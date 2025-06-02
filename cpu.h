#ifndef cpu_sim_cpu_h
#define cpu_sim_cpu_h

#include "task.h"
#include "scheduler.h"

typedef struct {
  Scheduler *scheduler;
} CPU;

void initCPU(CPU *cpu, Scheduler *scheduler);
void runCPU(CPU *cpu);

#endif
