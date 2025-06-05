#include <stdio.h>
#include <stdlib.h>

#include "task.h"
#include "scheduler.h"
#include "cpu.h"

void initCPU(CPU *cpu, Scheduler *scheduler) {
  cpu->scheduler = scheduler;
}

SimResult runCPU(CPU *cpu) {
  int sumTurnaround = 0;
  int sumWaiting = 0;
  int sumResponse = 0;

  for (SchedulerResponse sr = callScheduler(cpu->scheduler); 
      sr.duration != 0 || sr.taskToRun != NULL;
      sr = callScheduler(cpu->scheduler)) {
    printf("current time: %d\n", cpu->scheduler->currentTime);

    int executionTime = cpu->scheduler->currentTime;
    cpu->scheduler->currentTime += sr.duration;

    if (sr.taskToRun == NULL) {  
      printf("no task to run\n");
      continue;
    }

    Task *t = sr.taskToRun;

    printf("task: %s, duration: %d\n", 
        t->name, sr.duration);
    t->remaining -= sr.duration;
    
    if (!t->hasExecuted) {
      sumResponse += executionTime - t->arrivalTime;
      t->hasExecuted = true;
    }

    if (t->remaining == 0) {
      int turnaround = cpu->scheduler->currentTime - t->arrivalTime;

      sumTurnaround += turnaround;
      sumWaiting += turnaround - t->duration;
    }
  }

  int taskCnt = cpu->scheduler->taskList.size;

  return (SimResult){
      .avgWaitingTime = (float) sumWaiting / taskCnt,
      .avgTurnaroundTime = (float) sumTurnaround / taskCnt,
      .avgResponseTime = (float) sumResponse / taskCnt,
      };
}

