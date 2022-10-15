/* ------------------------------------------------------------------- */
/* PROGRAM  main.c:                                                    */
/*    This program uses a monitor (monitor_header.h and monitor.c) to  */
/* synchronize the increasing, decreasing, reseting, and retrieval     */
/* of the value of a shared counter. Note that the counter is within   */
/* the monitor.                                                        */
/* To establish mutual exclusion, a mutex lock is used.                */
/* The communication between processes is maintained via a shared      */
/* file which contains a shared variable. Each thread derived from     */
/* either process can access and modify the value of the counter at    */
/* one point in time due to sharing the mutex across all processes.    */
/* If one thread attempts to decrease the counter's value below 0, the */
/* procedure is paused until the value is again increased so the       */
/* subtraction doesn't yield negative numbers. This is achieved        */
/* by creating a shared condition variable between processes.          */
/* The value of the counter is generated randomly and at the end       */
/* of the program's execution the new value should be the same as the  */
/* initial one.                                                        */
/* ------------------------------------------------------------------- */


#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include "monitor_header.h"

#define MUTEX_FILE "mutex_file"
#define COND_FILE "cond_file"
#define SHM_SIZE 1024
#define MAX_ITEMS 20
#define MAX_RAND 5
#define MAX_PROCESSES 3
#define MAX_THREADS 3

pthread_mutex_t* mutex;
pthread_cond_t* condition;


void* Increase(void* arg)
{
     int* intArg = (int*)arg;
     int processNumber = *intArg;
     int counterValue;

     for (int i = 0; i < MAX_ITEMS; ++i)
     {
          pthread_mutex_lock(mutex);

          sched_yield();

          counterValue = INC();
          printf("       (INSIDE PROCESS NO. %d | INCREASE) Counter has been increased by 1 (value = %d)\n", processNumber, counterValue);

          pthread_mutex_unlock(mutex);
          pthread_cond_signal(condition);
     }

     return NULL;
}


void* Decrease(void* arg)
{
     int* intArg = (int*)arg;
     int processNumber = *intArg;
     int counterValue;

     for (int i = 0; i < MAX_ITEMS; ++i)
     {
          pthread_mutex_lock(mutex);

          sched_yield();

          while (!GET())
          {
               printf("       (INSIDE PROCESS NO. %d | WAITING) Counter is equal to 0 (value = %d)\n", processNumber, GET());
               pthread_cond_wait(condition, mutex);
          }

          counterValue = DEC();
          printf("       (INSIDE PROCESS NO. %d | DECREASE) Counter has been decreased by 1 (value = %d)\n", processNumber, counterValue);

          pthread_mutex_unlock(mutex);
     }

     return NULL;
}


int main()
{

srand((unsigned)time(NULL));

int shm_fd_mutex;

shm_fd_mutex = shm_open(MUTEX_FILE, O_CREAT | O_RDWR | O_TRUNC, S_IRWXU | S_IRWXG);
if (shm_fd_mutex == -1)
{ perror("Failed to execute shm_open() inside main"); return errno; }

if (ftruncate(shm_fd_mutex, sizeof(pthread_mutex_t)) == -1)
{
     perror("Failed to execute ftruncate() inside main");
     shm_unlink(MUTEX_FILE);
     return errno;
}

mutex = (pthread_mutex_t*) mmap(NULL, sizeof(pthread_mutex_t),
                                PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd_mutex, 0);
if (mutex == MAP_FAILED)
{
     perror("Failed to execute mmap() inside main");
     shm_unlink(MUTEX_FILE);
     return errno;
}

int shm_fd_cond;

shm_fd_cond = shm_open(COND_FILE, O_CREAT | O_RDWR | O_TRUNC, S_IRWXU | S_IRWXG);
if (shm_fd_cond == -1)
{
     perror("Failed to execute shm_open() inside main");
     munmap(mutex, sizeof(pthread_mutex_t)); shm_unlink(MUTEX_FILE);
     return errno;
}

if (ftruncate(shm_fd_cond, sizeof(pthread_cond_t)) == -1)
{
     perror("Failed to execute ftruncate() inside main");
     munmap(mutex, sizeof(pthread_mutex_t)); shm_unlink(MUTEX_FILE);
     shm_unlink(COND_FILE);
     return errno;
}

condition = (pthread_cond_t*) mmap(NULL, sizeof(pthread_cond_t),
                                   PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd_cond, 0);
if (condition == MAP_FAILED)
{
     perror("Failed to execute mmap() inside main");
     munmap(mutex, sizeof(pthread_mutex_t)); shm_unlink(MUTEX_FILE);
     shm_unlink(COND_FILE);
     return errno;
}

/* set mutex shared between processes */
pthread_mutexattr_t mutexAttr;
pthread_mutexattr_setpshared(&mutexAttr, PTHREAD_PROCESS_SHARED);
pthread_mutex_init(mutex, &mutexAttr);
pthread_mutexattr_destroy(&mutexAttr);

/* set condition shared between processes */
pthread_condattr_t condAttr;
pthread_condattr_setpshared(&condAttr, PTHREAD_PROCESS_SHARED);
pthread_cond_init(condition, &condAttr);
pthread_condattr_destroy(&condAttr);

pid_t pid;
pthread_t incThread[MAX_THREADS], decThread[MAX_THREADS];

MonitorInit();
printf("The monitor has been initialized.\n");

for (int i = 0; i < MAX_PROCESSES; ++i)
{
     pthread_mutex_lock(mutex);
     int counterValue = rand() % MAX_RAND;
     SET(counterValue);
     printf("  (PROCESS NO. %d | SET) The counter has been set to %d.\n", i, counterValue);
     pthread_mutex_unlock(mutex);

     pid = fork();

     if (!pid)
     {
          pthread_mutex_lock(mutex);
          counterValue = GET();
          printf("  (PROCESS NO. %d | DISPLAY) The initial counter value is %d.\n", i, counterValue);
          pthread_mutex_unlock(mutex);

          printf("  (PROCESS NO. %d | START) Child process %d of parent %d has started.\n", i, getpid(), getppid());

          for (int j = 0; j < MAX_THREADS; ++j)
          {
               if (pthread_create(&incThread[j], NULL, Increase, &i))
               {
                    perror("Failed to execute pthread_create()");
                    munmap(mutex, sizeof(pthread_mutex_t)); shm_unlink(MUTEX_FILE);
                    munmap(condition, sizeof(pthread_cond_t)); shm_unlink(COND_FILE);
                    return errno;
               }
               if (pthread_create(&decThread[j], NULL, Decrease, &i))
               {
                    perror("Failed to execute pthread_create()");
                    munmap(mutex, sizeof(pthread_mutex_t)); shm_unlink(MUTEX_FILE);
                    munmap(condition, sizeof(pthread_cond_t)); shm_unlink(COND_FILE);
                    return errno;
               }
          }

          for (int k = 0; k < MAX_THREADS; ++k)
          {
               if (pthread_join(incThread[k], NULL))
               {
                    perror("Failed to execute pthread_join()");
                    munmap(mutex, sizeof(pthread_mutex_t)); shm_unlink(MUTEX_FILE);
                    munmap(condition, sizeof(pthread_cond_t)); shm_unlink(COND_FILE);
                    return errno;
               }
               if (pthread_join(decThread[k], NULL))
               {
                    perror("Failed to execute pthread_join()");
                    munmap(mutex, sizeof(pthread_mutex_t)); shm_unlink(MUTEX_FILE);
                    munmap(condition, sizeof(pthread_cond_t)); shm_unlink(COND_FILE);
                    return errno;
               }
          }

          pthread_mutex_lock(mutex);
          counterValue = GET();
          printf("  (PROCESS NO. %d | DISPLAY) The final counter value is %d.\n", i, counterValue);
          printf("  (PROCESS NO. %d | FINISH) Child process %d of parent %d has finished.\n", i, getpid(), getppid());
          pthread_mutex_unlock(mutex);

          break;
     }
     else
          if (pid < 0)
          { perror("An error has occured in the creation of a process"); return errno; }
}

if (pid > 0)
{
     while (wait(NULL) > 0);

     printf("Parent %d exits ...\n", getpid());

     TurnOffMonitor();

     pthread_mutex_destroy(mutex);
     pthread_cond_destroy(condition);

     munmap(mutex, sizeof(pthread_mutex_t));
     shm_unlink(MUTEX_FILE);
     munmap(condition, sizeof(pthread_cond_t));
     shm_unlink(COND_FILE);
}

return 0;}