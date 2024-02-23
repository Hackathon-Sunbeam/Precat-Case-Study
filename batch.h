#ifndef BATCH_H
#define BATCH_H

struct Date
{
    int DD;
    int MM;
    int YY;
};

struct Time
{
    int hr;
    int mm;
    int sec;
};

typedef struct
{
    char Name[100];
    int mode;
    int type;
    struct Date start_date;
    struct Date end_date;
    struct Time batch_start_time;
    struct Time batch_end_time;
} Batch;

struct batches
{
    char Name[100];
    int mode;
    int type;
    struct Date start_date;
    struct Date end_date;
    struct Time batch_start_time;
    struct Time batch_end_time;
};

void acceptData(struct batches *batch);
void printData(struct batches *batch);
void storeData(struct batches *batch, const char *filename);

#endif
