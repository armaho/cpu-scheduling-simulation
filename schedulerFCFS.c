#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "scheduler.h"
#include "schedulerFCFS.h"

SchedulerResponse scheduleFCFS(Scheduler *scheduler) {
  SchedulerFCFS *s = (SchedulerFCFS *)scheduler;
  
  int newTask = s->lastTask + 1;

  if (s->taskList.size == newTask) {
    return (SchedulerResponse){.taskToRun = NULL, .duration = 0};
  }
  
  if (s->taskList.buff[newTask].arrivalTime > s->currentTime) {
    return (SchedulerResponse){.taskToRun = NULL, .duration = 1};
  }

  s->lastTask = newTask;

  Task *taskToRun = &(s->taskList.buff[newTask]);
  return (SchedulerResponse){.taskToRun = taskToRun, .duration = taskToRun->duration};
}

int compareTaskFCFS(const void *t1, const void *t2) {
  return ((Task *)t1)->arrivalTime - ((Task *)t2)->arrivalTime;
}

int initSchedulerFCFS(SchedulerFCFS *scheduler, TaskList taskList) {
  if (initScheduler((Scheduler *)scheduler, taskList, scheduleFCFS)) {
    return -1;
  }

  scheduler->lastTask = -1;
  qsort(scheduler->taskList.buff, scheduler->taskList.size, sizeof(Task), compareTaskFCFS);

  return 0;
}
