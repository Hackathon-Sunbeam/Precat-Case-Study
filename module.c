// module.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "module.h"
#include "batch.h"
#define MAXCHAR 1000

Module modules[MAX_MODULES];
// module.c
// static Module modules[MAX_MODULES]; // Array of module structures
int mod_count = 0; // Define mod_count here

void loadModules()
{
    char row[MAXCHAR];
    FILE *fp;

    fp = fopen("modules.csv", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(row, MAXCHAR, fp) != NULL)
    {
        char *token = strtok(row, ",");
        if (token != NULL)
            strcpy(modules[mod_count].name, token);
        token = strtok(NULL, ",");
        if (token != NULL)
            strcpy(modules[mod_count].type, token);
        token = strtok(NULL, ",");
        if (token != NULL)
            modules[mod_count].theory_hrs = atoi(token);
        token = strtok(NULL, ",");
        if (token != NULL)
            modules[mod_count].lab_hrs = atoi(token);

        mod_count++;
    }

    fclose(fp);
}

void displayAllModules(Module md[])
{
    for (int i = 0; i < mod_count; i++)
    {
        printf("%s, %s, %d, %d\n", modules[i].name, modules[i].type, modules[i].theory_hrs, modules[i].lab_hrs);
    }
}

Module assignModule()
{
    int moduleChoice;
    Module selectedModule;

    printf("Select Module: ");
    scanf("%d", &moduleChoice);

    if (moduleChoice >= 1 && moduleChoice <= mod_count)
    {
        selectedModule = modules[moduleChoice - 1];
        printf("Module %s selected with %d theory hours and %d lab hours\n", selectedModule.name, selectedModule.theory_hrs, selectedModule.lab_hrs);
    }
    else
    {
        printf("Invalid Module choice.\n");
        exit(EXIT_FAILURE);
    }

    return selectedModule;
}

void assignModules(Batch *batch)
{
    printf("Enter module hours for the batch:\n");
    void displayAllModules(Module md[]);

    for (int i = 0; i < mod_count; i++)
    {
        int moduleChoice;
        scanf("%d", &moduleChoice);
        // Assuming you have a function to assign a module to a batch
        // assignModuleToBatch(batch, modules[moduleChoice - 1]);
    }
}