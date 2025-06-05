#include <stdio.h>

#include "task.h"
#include "scheduler.h"
#include "schedulerFCFS.h"
#include "schedulerSJF.h"
#include "schedulerRR.h"
#include "cpu.h"

int main(void) {
  Task t1;
  Task t2;
  Task t3;
  Task t4;
  TaskList tl;

  initTask(&t1, 10, 2, "T1");
  initTask(&t2, 12, 3, "T2");
  initTask(&t3, 4, 10, "T3");
  initTask(&t4, 6, 4, "T4");
  initTaskList(&tl);

  addTaskList(&tl, t1);
  addTaskList(&tl, t2);
  addTaskList(&tl, t3);
  addTaskList(&tl, t4); 

  SchedulerFCFS sFCFS;
  SchedulerSJF sSJF;
  SchedulerRR sRR;

  initSchedulerFCFS(&sFCFS, tl);
  initSchedulerSJF(&sSJF, tl);
  initSchedulerRR(&sRR, tl, 3);

  CPU cpu;

  initCPU(&cpu, (Scheduler *)&sFCFS);
  SimResult result = runCPU(&cpu);

  printf("Average Waiting Time: %.2f\n", result.avgWaitingTime);
  printf("Average Turnaround Time: %.2f\n", result.avgTurnaroundTime);
  printf("Average Response Time: %.2f\n", result.avgResponseTime);

  return 0;
}
