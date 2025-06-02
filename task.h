#ifndef cpu_sim_task_h
#define cpu_sim_task_h

#include <stdbool.h>

typedef struct {
  int duration;
  int arrivalTime;
  char *name;
} Task;

typedef struct {
  int size;
  int cap;
  Task *buff;
} TaskList;

int initTaskList(TaskList *taskList);
void freeTaskList(TaskList *taskList);
int addTaskList(TaskList *taskList, Task task);
bool containsUnfinishedTask(TaskList *taskList);
void printTaskList(TaskList *taskList);

#endif
