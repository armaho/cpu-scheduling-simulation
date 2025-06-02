#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

#include "task.h"
#include "scheduler.h"
#include "schedulerSJF.h"

SchedulerResponse scheduleSJF(Scheduler *scheduler) {
  SchedulerSJF *s = (SchedulerSJF *)scheduler;

  if (!containsUnfinishedTask(&(scheduler->taskList))) {
    return (SchedulerResponse){.taskToRun = NULL, .duration = 0};
  }

  int shortestDuration = INT_MAX;
  Task *shortestTask = NULL;

  for (int i = 0; i < scheduler->taskList.size; i++) {
    Task *t = &(scheduler->taskList.buff[i]);

    if (t->arrivalTime < scheduler->currentTime &&
        t->duration > 0 && 
        t->duration < shortestDuration) {
      shortestTask = t;
      shortestDuration = t->duration;
    }
  }

  if (shortestTask == NULL) {
    return (SchedulerResponse){.taskToRun = NULL, .duration = 1};
  }
  return (SchedulerResponse){.taskToRun = shortestTask, .duration = shortestDuration};
}

int initSchedulerSJF(SchedulerSJF *scheduler, TaskList taskList) {
  if (initScheduler((Scheduler *)scheduler, taskList, scheduleSJF)) {
    return -1;
  }
  return 0;
}
