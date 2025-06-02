#ifndef cpu_sim_scheduler_fcfs_h
#define cpu_sim_scheduler_fcfs_h

#include "task.h"
#include "scheduler.h"

typedef struct {
  int currentTime;
  TaskList taskList;
  SchedulerResponse (*schedule)(Scheduler *scheduler);
  
  int lastTask;
} SchedulerFCFS;

int initSchedulerFCFS(SchedulerFCFS *scheduler, TaskList taskList);

#endif
