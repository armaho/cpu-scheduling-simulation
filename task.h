#ifndef cpu_sim_task_h
#define cpu_sim_task_h

#include <stdbool.h>

typedef struct {
  int duration;
  int arrivalTime;
  char *name;
  int remaining;
  bool hasExecuted;
} Task;

typedef struct {
  int size;
  int cap;
  Task *buff;
} TaskList;

void initTask(Task *task, int duration, int arrivalTime, char *name);
int initTaskList(TaskList *taskList);
void freeTaskList(TaskList *taskList);
int addTaskList(TaskList *taskList, Task task);
bool containsUnfinishedTask(TaskList *taskList);
void printTaskList(TaskList *taskList);

#endif
