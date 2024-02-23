#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define SIZE 10
#define MAXCHAR 1000
typedef struct module
{
    char name[50];
    char type[50];
    int theory_hrs;
    int lab_hrs;
}module;
int mod_count = 0;
void read_data(module *md);
void display(module *md);

int main()
{
    module md[100];
    read_data(md);
    printf("ModuleName\tModuleType\tTheoryHours\tLabHours\n");
    display(md);


    return 0;
}

void read_data(module md[])
{
    char row[MAXCHAR];
   
   // char *token;
    FILE *fp;
    // Open file for read
    fp = fopen("modules.csv", "r");
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
            strcpy(md[mod_count].name, token);
        token = strtok(NULL, ",");
        if (token != NULL)
                strcpy(md[mod_count].type, token);
           // strcpy(md->type, token);
        token = strtok(NULL, ",");
        if (token != NULL)
            md[mod_count].theory_hrs = atoi(token);
           // strcpy(md->theory_hrs, token);
        token = strtok(NULL, ",");
        if (token != NULL)
        md[mod_count].lab_hrs = atoi(token);
           // strcpy(md->lab_hrs, token);
        // Display data to the user
       // display(md);
       mod_count++;
    }
    fclose(fp);
}

void display(module md[])
{   
    for(int i=0;i<mod_count;i++)
    {
        printf("%s, %s, %d, %d\n",md[i].name,md[i].type,md[i].theory_hrs,md[i].lab_hrs);
    }
}