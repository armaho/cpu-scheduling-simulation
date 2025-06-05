#ifndef cpu_sim_cpu_h
#define cpu_sim_cpu_h

#include "task.h"
#include "scheduler.h"

typedef struct {
  Scheduler *scheduler;
} CPU;

typedef struct {
  float avgResponseTime;
  float avgWaitingTime;
  float avgTurnaroundTime;
} SimResult;

void initCPU(CPU *cpu, Scheduler *scheduler);
SimResult runCPU(CPU *cpu);

#endif
