#include <stdio.h>
#include <stdlib.h>

#include "task.h"
#include "scheduler.h"
#include "cpu.h"

void initCPU(CPU *cpu, Scheduler *scheduler) {
  cpu->scheduler = scheduler;
}

void runCPU(CPU *cpu) {
  for (SchedulerResponse sr = callScheduler(cpu->scheduler); 
      cpu->scheduler->currentTime < 100 && (sr.duration != 0 || sr.taskToRun != NULL);
      sr = callScheduler(cpu->scheduler)) {
    printf("current time: %d\n", cpu->scheduler->currentTime);
    if (sr.taskToRun != NULL) {  
      printf("task: %s, duration: %d, ptr: %p\n", sr.taskToRun->name, sr.duration, sr.taskToRun);
      sr.taskToRun->duration -= sr.duration;
    } else {
      printf("no task to run\n");
    }

    cpu->scheduler->currentTime += sr.duration;
  }
}

