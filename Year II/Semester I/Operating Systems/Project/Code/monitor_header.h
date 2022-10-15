/* ----------------------------------------------------------------- */
/* MONITOR  monitor_header.c:                                        */
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


void MonitorInit();         /* initialize the simulated monitor   */
void SET(int n);            /* set the counter value              */
int INC();                  /* increase the counter               */
int DEC();                  /* decrease the counter               */
int GET();                  /* retrieve counter's value           */
void TurnOffMonitor();      /* turn off the simulated monitor     */