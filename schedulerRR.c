#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "scheduler.h"
#include "schedulerRR.h"

SchedulerResponse schedule(Scheduler *scheduler) {
  SchedulerRR *schedulerRR = (SchedulerRR *)scheduler;
  
  if (!containsUnfinishedTask(&(scheduler->taskList))) {
    return (SchedulerResponse){.taskToRun = NULL, .duration = 0};
  }

  int cnt = 0;
  int newTask = (schedulerRR->lastTask + 1) % schedulerRR->taskList.size;
  while ((schedulerRR->taskList.buff[newTask].remaining <= 0 ||
      schedulerRR->taskList.buff[newTask].arrivalTime > schedulerRR->currentTime) &&
      cnt < schedulerRR->taskList.size) {
    newTask = (newTask + 1) % schedulerRR->taskList.size;
    cnt++;
  }

  if (cnt == schedulerRR->taskList.size) {
    return (SchedulerResponse){.taskToRun = NULL, .duration = 1};
  }

  Task *t = schedulerRR->taskList.buff + newTask;
  int duration = t->remaining < schedulerRR->quantum ? t->remaining : schedulerRR->quantum;

  return (SchedulerResponse){.taskToRun = t, duration};
}

int initSchedulerRR(SchedulerRR *scheduler, TaskList taskList, int quantum) {
  if (initScheduler((Scheduler *)scheduler, taskList, schedule)) {
    return -1;
  }
  
  scheduler->lastTask = -1;
  scheduler->quantum = quantum;

  return 0;
}

