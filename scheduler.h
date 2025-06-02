#ifndef cpu_sim_scheduler_h
#define cpu_sim_scheduler_h

#include "task.h"

typedef struct {
  Task *taskToRun;
  int duration;
} SchedulerResponse;

typedef struct _scheduler {
  int currentTime;
  TaskList taskList;
  SchedulerResponse (*schedule)(struct _scheduler *scheduler);
} Scheduler;

int initScheduler(Scheduler *scheduler, 
    TaskList taskList, 
    SchedulerResponse (schedule)(Scheduler *schedule));
SchedulerResponse callScheduler(Scheduler *scheduler);

#endif
