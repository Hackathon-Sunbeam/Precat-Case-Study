// schedule.c
#include <stdio.h>
#include <string.h>
#include "schedule.h"
#include "faculty.h"
#include "batch.h"

void assignSchedule(Batch *batch, Faculty faculty, const char *moduleName)
{
    // Check for clashes and produce warnings
    if (checkClashes(batch, faculty, moduleName))
    {
        printf("Warning: Clash detected for Faculty %s in Module %s\n", faculty.name, moduleName);
        // You can choose to handle clashes in some way
    }

    // Assign the schedule
    for (int i = 0; i < batch->numModules; i++)
    {
        if (strcmp(batch->modules[i].name, moduleName) == 0)
        {
            batch->modules[i].faculty = faculty;
            break;
        }
    }
}

void displaySchedule(const Batch *batch)
{
    printf("Schedule for Batch: %s\n", batch->name);
    printf("Start Date: %02d/%02d/%02d\n", batch->start_date.DD, batch->start_date.MM, batch->start_date.YY);
    printf("End Date: %02d/%02d/%02d\n", batch->end_date.DD, batch->end_date.MM, batch->end_date.YY);
    printf("Batch Mode: %s\n", batch->mode == 1 ? "Offline" : "Online");
    printf("Batch Type: %s\n", batch->type == 1 ? "Regular" : (batch->type == 2 ? "Fast track" : "Crash"));
    printf("Batch Start Time: %02d:%02d:%02d\n", batch->batch_start_time.hr, batch->batch_start_time.mm, batch->batch_start_time.sec);
    printf("Batch End Time: %02d:%02d:%02d\n", batch->batch_end_time.hr, batch->batch_end_time.mm, batch->batch_end_time.sec);
    printf("Batch Location: %s\n", batch->location);

    printf("Module-wise Schedule:\n");
    for (int i = 0; i < batch->numModules; i++)
    {
        printf("Module: %s\n", batch->modules[i].name);
        printf("Lab Hours: %d\n", batch->modules[i].hours);
        printf("Assigned Faculty: %s\n", batch->modules[i].faculty.name);
        // Add any other relevant information
        printf("\n");
    }
}

int checkClashes(const Batch *batch, const Faculty faculty, const char *moduleName)
{
    for (int i = 0; i < batch->numModules; i++)
    {
        if (strcmp(batch->modules[i].name, moduleName) == 0 &&
            strcmp(batch->modules[i].faculty.name, faculty.name) != 0)
        {
            return 1; // Clash detected
        }
    }
    return 0; // No clash
}