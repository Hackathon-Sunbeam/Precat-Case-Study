// schedule.h
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "batch.h"
#include "faculty.h"

// Function to assign a schedule
void assignSchedule(Batch *batch, Faculty faculty, const char *moduleName);

// Function to display the schedule
void displaySchedule(const Batch *batch);

// Function to check for clashes in the schedule
int checkClashes(const Batch *batch, const Faculty faculty, const char *moduleName);

#endif
