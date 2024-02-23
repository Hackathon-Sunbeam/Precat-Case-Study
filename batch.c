#include <stdio.h>
#include <string.h>

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

// Function to print data for a batch
void printData(struct batches *batch) {
    printf("\nBatch Name: %s\n", batch->Name);
    printf("Batch Mode: %s\n", batch->mode == 1 ? "Offline" : "Online");
    printf("Batch Type: %s\n", batch->type == 1 ? "Regular" : (batch->type == 2 ? "Fast track" : "Crash"));
    printf("Batch Start Date: %02d/%02d/%02d\n", batch->start_date.DD, batch->start_date.MM, batch->start_date.YY);
    printf("Batch End Date: %02d/%02d/%02d\n", batch->end_date.DD, batch->end_date.MM, batch->end_date.YY);
    printf("Batch Start Time: %02d:%02d:%02d\n", batch->batch_start_time.hr, batch->batch_start_time.mm, batch->batch_start_time.sec);
    printf("Batch End Time: %02d:%02d:%02d\n", batch->batch_end_time.hr, batch->batch_end_time.mm, batch->batch_end_time.sec);
}

// Function to store data for a batch in a CSV file
void storeData(struct batches *batch, const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    fprintf(file, "batch_name=%s,batch_mode%d,batch_type%d,%d %d %d,%d %d %d,%d %d %d,%d %d %d\n", batch->Name, batch->mode, batch->type,
            batch->start_date.DD, batch->start_date.MM, batch->start_date.YY,
            batch->end_date.DD, batch->end_date.MM, batch->end_date.YY,
            batch->batch_start_time.hr, batch->batch_start_time.mm, batch->batch_start_time.sec,
            batch->batch_end_time.hr, batch->batch_end_time.mm, batch->batch_end_time.sec);

    fclose(file);
}

int main() {
    struct batches batch;
    acceptData(&batch);
    printData(&batch);
    storeData(&batch, "batch.csv");
    return 0;
}
