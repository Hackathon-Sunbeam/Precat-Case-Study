#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <faculty.h>
#define MAXCHAR 1000
int fc_count = 0;
typedef struct {
    char name[50];
    char lecture_lab[50];
    char modulename[50];
} Faculty;

void read_data(Faculty fc[])
{
    char row[MAXCHAR];
   
   // char *token;
    FILE *fp;
    // Open file for read
    fp = fopen("faculties.csv", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
      //  return 1;
    }
    // Read and process each line
    while (fgets(row, MAXCHAR, fp) != NULL)
    {
        // Tokenize the row
        char *token = strtok(row, ",");
        if (token != NULL)
            strcpy(fc[fc_count].name, token);
        token = strtok(NULL, ",");
        if (token != NULL)
                strcpy(fc[fc_count].lecture_lab, token);
           // strcpy(md->type, token);
        token = strtok(NULL, ",");
        if (token != NULL)
                strcpy(fc[fc_count].modulename, token);
           // fc[fc_count].theory_hrs = atoi(token);
           // strcpy(md->theory_hrs, token);
       fc_count++;
    }
    fclose(fp);
}
void display(Faculty fc[])
{
    for(int i=0;i<fc_count;i++)
    {
        printf("%s %s %s",fc[i].name,fc[i].lecture_lab,fc[i].modulename);
    }
}

int main()
{
    Faculty fc[100];
    read_data(fc);
    display(fc);
   
    return 0;
}