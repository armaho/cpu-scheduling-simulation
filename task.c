#include <stdlib.h>
#include <stdio.h>

#include "task.h"

#define INIT_CAP 8

static int increaseCap(TaskList *taskList) {
  int newCap = taskList->cap * 2;
  Task *newBuff = (Task *)realloc(taskList->buff, newCap * sizeof(Task));
  if (newBuff == NULL) {
    return -1;
  }

  taskList->buff = newBuff;
  taskList->cap = newCap;

  return 0;
}

int initTaskList(TaskList *taskList) {
  taskList->size = 0;
  taskList->cap = INIT_CAP;
  taskList->buff = (Task *)malloc(INIT_CAP * sizeof(Task));
  if (taskList->buff == NULL) {
    return -1;
  }

  return 0;
}

void freeTaskList(TaskList *taskList) {
  free(taskList->buff);
}

int addTaskList(TaskList *taskList, Task task) {
  if (taskList->size == taskList->cap && increaseCap(taskList)) {
    return -1;
  }

  taskList->buff[taskList->size++] = task;
  return 0;
}

bool containsUnfinishedTask(TaskList *taskList) {
  for (int i = 0; i < taskList->size; i++) {
    if (taskList->buff[i].duration > 0) {
      return true;
    }
  }

  return false;
}

void printTaskList(TaskList *taskList) {
  printf("TaskList(%p): \n", taskList);
  printf("\tCap: %d \n", taskList->cap);
  printf("\tSize: %d \n", taskList->size);
  printf("\tBuff(%p): \n", taskList->buff);
  for (int i = 0; i < taskList->size; i++) {
    printf("\t\tPtr: %p, Name: %10s, Duration: %4d, Arrival: %d\n", 
        taskList->buff + i,
        taskList->buff[i].name,
        taskList->buff[i].duration,
        taskList->buff[i].arrivalTime);
  }
}
