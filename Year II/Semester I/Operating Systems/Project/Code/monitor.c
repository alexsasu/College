/* ----------------------------------------------------------------- */
/* MONITOR  monitor.c:                                               */
/*    This monitor provides the following procedures :               */
/*    (1)  MonitorInit()      - initialize the monitor               */
/*    (2)  SET()              - set the counter value                */
/*    (3)  INC()              - increase the counter value by one    */
/*    (4)  DEC()              - decrease the counter value by one    */
/*    (5)  GET()              - retrieve the counter value           */
/*    (6)  TurnOffMonitor()   - turn off the monitor                 */
/* Although several functions return the value of the counter, the   */
/* retrieved value may not be accurate since before the value can    */
/* be returned, the counter may have already been modified by one    */
/* of the defined functions such as INC, DEC.                        */
/* ----------------------------------------------------------------- */


#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "monitor_header.h"

#define COUNTER_FILE "counter_file"
#define SHM_SIZE 1024

int shm_fd_counter;
char* shm_ptr_child;


/* ---------------------------------------------------------------- */
/* FUNCTION  MonitorInit() :                                        */
/*      Initialize the simulated monitor.                           */
/* ---------------------------------------------------------------- */

void MonitorInit()
{
     shm_fd_counter = shm_open(COUNTER_FILE, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR );
     if (shm_fd_counter == -1)
     { perror("Failed to execute shm_open() inside MonitorInit"); exit(1); }
     if (ftruncate(shm_fd_counter, SHM_SIZE))
     { perror("Failed to execute ftruncate() inside MonitorInit"); shm_unlink(COUNTER_FILE); exit(1); }
     shm_ptr_child = mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd_counter, 0);
     if (shm_ptr_child == MAP_FAILED)
     { perror("Failed to execute mmap() inside MonitorInit"); shm_unlink(COUNTER_FILE); exit(1); }
}

/* ---------------------------------------------------------------- */
/* FUNCTION  SET() :                                                */
/*      Set the counter to a new value.                             */
/* ---------------------------------------------------------------- */

void SET(int n)
{
     sprintf(shm_ptr_child, "%d", n);
}

/* ---------------------------------------------------------------- */
/* FUNCTION  INC() :                                                */
/*      Increase the counter value by one.                          */
/* ---------------------------------------------------------------- */

int INC()
{
     int counterValue;

     char* snum = (char*)malloc(10 * sizeof(char) + 1);
     if (snum == NULL)
     { perror("Failed to execute malloc() inside INC"); munmap(shm_ptr_child, SHM_SIZE); shm_unlink(COUNTER_FILE); exit(2); }
     sprintf(snum, "%s", shm_ptr_child);
     counterValue = atoi(snum) + 1;
     sprintf(shm_ptr_child, "%d", counterValue);

     free(snum);

     return counterValue;
}

/* ---------------------------------------------------------------- */
/* FUNCTION  DEC() :                                                */
/*      Decrease the counter value by one.                          */
/* ---------------------------------------------------------------- */

int DEC()
{
     int counterValue;

     char* snum = (char*)malloc(10 * sizeof(char) + 1);
     if (snum == NULL)
     { perror("Failed to execute malloc() inside DEC"); munmap(shm_ptr_child, SHM_SIZE); shm_unlink(COUNTER_FILE); exit(3); }
     sprintf(snum, "%s", shm_ptr_child);
     counterValue = atoi(snum) - 1;
     sprintf(shm_ptr_child, "%d", counterValue);

     free(snum);

     return counterValue;
}

/* ---------------------------------------------------------------- */
/* FUNCTION  GET() :                                                */
/*      Retrieve the counter's value.                               */
/* ---------------------------------------------------------------- */

int GET()
{
     int counterValue;

     char* snum = (char*)malloc(10 * sizeof(char) + 1);
     if (snum == NULL)
     { perror("Failed to execute malloc() inside GET"); munmap(shm_ptr_child, SHM_SIZE); shm_unlink(COUNTER_FILE); exit(4); }
     sprintf(snum, "%s", shm_ptr_child);
     counterValue = atoi(snum);

     free(snum);

     return counterValue;
}

/* ------------------------------------------------------------------------ */
/* FUNCTION  TurnOffMonitor() :                                             */
/*      Delete all mapping and in memory references of the shared counter.  */
/*      Turn off the simulated monitor.                                     */
/* ------------------------------------------------------------------------ */

void TurnOffMonitor()
{
     munmap(shm_ptr_child, SHM_SIZE);
     shm_unlink(COUNTER_FILE);
}