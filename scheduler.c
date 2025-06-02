#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "scheduler.h"

SchedulerResponse callScheduler(Scheduler *scheduler) {
  return scheduler->schedule(scheduler);
}

int initScheduler(Scheduler *scheduler, 
    TaskList taskList, 
    SchedulerResponse (schedule)(Scheduler *schedule)) {
  scheduler->currentTime = 0;
  scheduler->schedule = schedule;
  scheduler->taskList = taskList;

  scheduler->taskList.buff = (Task *)malloc(taskList.size * sizeof(Task));
  if (scheduler->taskList.buff == NULL) {
    return -1;
  }
  memcpy(scheduler->taskList.buff, taskList.buff, taskList.size * sizeof(Task));
 
  return 0;
}
