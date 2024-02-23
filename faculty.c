// faculty.c
#include <stdio.h>
#include <stdlib.h>
#include "faculty.h"
#include "batch.h" // Add this line to include the batch header file

#define MAX_FACULTIES 10 // Maximum number of faculties

#define MAXCHAR 1000
int fc_count = 0;
static Faculty faculties[MAX_FACULTIES];
void loadFaculties(Faculty fc[])
{
    char row[MAXCHAR];
    FILE *fp;

    fp = fopen("faculties.csv", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
    }

    while (fgets(row, MAXCHAR, fp) != NULL)
    {
        char *token = strtok(row, ",");
        if (token != NULL)
            strcpy(fc[fc_count].name, token);
        token = strtok(NULL, ",");
        if (token != NULL)
            strcpy(fc[fc_count].lecture_lab, token);
        token = strtok(NULL, ",");
        if (token != NULL)
            strcpy(fc[fc_count].modulename, token);

        fc_count++;
    }
    fclose(fp);
}

void displayAllFaculties(Faculty fc[])
{
    for (int i = 0; i < fc_count; i++)
    {
        printf("%s %s %s\n", fc[i].name, fc[i].lecture_lab, fc[i].modulename);
    }
}

void find_faculty(void)
{
    char faculty_name[50];
    int found = 0;
    Faculty f;
    FILE *fp;

    printf("Enter faculty name to find: ");
    scanf("%s", faculty_name);

    fp = fopen("faculties.csv", "r");
    if (fp == NULL)
    {
        perror("fopen() failed");
        exit(1);
    }

    char line[256];
    fgets(line, sizeof(line), fp); // Skip the header line

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char *name = strtok(line, ",");
        char *lecture_lab = strtok(NULL, ",");
        char *modulename = strtok(NULL, ",");

        modulename[strcspn(modulename, "\n")] = 0;

        if (strcmp(name, faculty_name) == 0)
        {
            printf("Faculty Name: %s, Lecture/Lab: %s, ModuleName: %s\n", name, lecture_lab, modulename);
            found = 1;
        }
    }

    fclose(fp);

    if (found == 0)
        printf("Faculty not found.\n");
}
