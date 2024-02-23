// module.h
#ifndef MODULE_H
#define MODULE_H

#include "batch.h"

#define MAX_MODULES 100
#define MAX_NAME_LENGTH 50

typedef struct
{
    char name[MAX_NAME_LENGTH];
    char type[MAX_NAME_LENGTH];
    int theory_hrs;
    int lab_hrs;
} Module;

void loadModules();
void displayAllModules(Module md[]);
Module assignModule();
void assignModules(Batch *batch);

#endif
