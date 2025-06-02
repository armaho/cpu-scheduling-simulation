#include <stdio.h>

#include "task.h"
#include "scheduler.h"
#include "schedulerFCFS.h"
#include "schedulerSJF.h"
#include "schedulerRR.h"
#include "cpu.h"

int main(void) {
  TaskList tl;

  initTaskList(&tl);
  addTaskList(&tl, (Task){.name = "T1", .duration = 10, .arrivalTime = 2});
  addTaskList(&tl, (Task){.name = "T2", .duration = 12, .arrivalTime = 3});
  addTaskList(&tl, (Task){.name = "T3", .duration = 4, .arrivalTime = 10});
  addTaskList(&tl, (Task){.name = "T4", .duration = 6, .arrivalTime = 4});

  SchedulerFCFS s;
  SchedulerSJF sSJF;
  SchedulerRR sRR;

  initSchedulerFCFS(&s, tl);
  initSchedulerSJF(&sSJF, tl);
  initSchedulerRR(&sRR, tl, 3);

  CPU cpu;

  initCPU(&cpu, (Scheduler *)&sRR);
  runCPU(&cpu);

  return 0;
}
