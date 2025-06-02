#ifndef cpu_sim_scheduler_rr_h
#define cpu_sim_scheduler_rr_h

#include "task.h"
#include "scheduler.h"

typedef struct {
  int currentTime;
  TaskList taskList;
  SchedulerResponse (*schedule)(struct _scheduler *scheduler);

  int lastTask;
  int quantum;
} SchedulerRR;

int initSchedulerRR(SchedulerRR *scheduler, TaskList taskList, int quantum);

#endif
