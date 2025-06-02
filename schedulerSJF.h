#ifndef cpu_sim_scheduler_sjf_h
#define cpu_sim_scheduler_sjf_h

#include "task.h"
#include "scheduler.h"

typedef struct {
  int currentTime;
  TaskList taskList;
  SchedulerResponse (*schedule)(struct _scheduler *scheduler);
} SchedulerSJF;

int initSchedulerSJF(SchedulerSJF *scheduler, TaskList taskList);

#endif
