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

struct date {
    int DD;
    int MM;
    int YY;
};

struct time {
    int hr;
    int mm;
    int sec;
};
struct batches {
    char Name[20];
    int mode;
    int type;
    struct date start_date;
    struct date end_date;
    struct time batch_start_time;
    struct time batch_end_time;
};

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

// Function to accept data for a batch
void acceptData(struct batches *batch) {
    printf("Enter batch name: ");
    scanf("%s", batch->Name);

    printf("Enter batch mode (1 for offline and 2 for online): ");
    scanf("%d", &batch->mode);

    printf("Enter batch type (1.Regular, 2.Fast track, 3.Crash): ");
    scanf("%d", &batch->type);

    printf("Enter batch start date (DD MM YY): ");
    scanf("%d %d %d", &batch->start_date.DD, &batch->start_date.MM, &batch->start_date.YY);

    printf("Enter batch end date (DD MM YY): ");
    scanf("%d %d %d", &batch->end_date.DD, &batch->end_date.MM, &batch->end_date.YY);

    printf("Enter batch start time (HH MM SS): ");
    scanf("%d %d %d", &batch->batch_start_time.hr, &batch->batch_start_time.mm, &batch->batch_start_time.sec);

    printf("Enter batch end time (HH MM SS): ");
    scanf("%d %d %d", &batch->batch_end_time.hr, &batch->batch_end_time.mm, &batch->batch_end_time.sec);
}

void printData(struct batches *batch) {
    printf("\nBatch Name: %s\n", batch->Name);
    printf("Batch Mode: %s\n", batch->mode == 1 ? "Offline" : "Online");
    printf("Batch Type: %s\n", batch->type == 1 ? "Regular" : (batch->type == 2 ? "Fast track" : "Crash"));
    printf("Batch Start Date: %02d/%02d/%02d\n", batch->start_date.DD, batch->start_date.MM, batch->start_date.YY);
    printf("Batch End Date: %02d/%02d/%02d\n", batch->end_date.DD, batch->end_date.MM, batch->end_date.YY);
    printf("Batch Start Time: %02d:%02d:%02d\n", batch->batch_start_time.hr, batch->batch_start_time.mm, batch->batch_start_time.sec);
    printf("Batch End Time: %02d:%02d:%02d\n", batch->batch_end_time.hr, batch->batch_end_time.mm, batch->batch_end_time.sec);
}


void schedule(Faculty fc[],struct batches b1)
{
    FILE *fptr = fopen("schedule.txt","w");

    if(fptr == NULL)
        printf("File not opened !");
    else
    {
       // for(int i=0;i<fc_count;i++)
            fwrite(fc,sizeof(Faculty),fc_count,fptr);
            fwrite(fc,sizeof(b1),fc_count,fptr);
    }
    fclose(fptr);
}

int main()
{
    Faculty fc[100];
    struct batches b1;
    read_data(fc);
    acceptData(&b1);
    printData(&b1);
    schedule(fc,b1);
    //display(fc);
    
    return 0;
}