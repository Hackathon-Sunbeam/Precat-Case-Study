#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define SIZE 10
#define MAXCHAR 1000
#define MAXCHAR 1000
#define MAX_VENUES 100 // Maximum number of venues
typedef struct venue {
    char location[30];
    char lecture_venue[20];
    char Lab_venue[20];
    int capacity;
} venue_t;
typedef struct module
{
    char name[50];
    char type[50];
    int theory_hrs;
    int lab_hrs;
}module;
int fc_count = 0;
typedef struct {
    char name[50];
    char lecture_lab[50];
    char modulename[50];
} Faculty;
// Define the structures
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


int mod_count = 0;
void read_data(module *md);
void display(module *md);
void read_faculty(Faculty fc[]); 
void read_module(module md[]); 
void display_faculty(Faculty fc[]); 
void display_module(module md[]); 
void display_venue(venue_t v[], int size); 
void find_venue(void);

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
int load_venues() {
    venue_t venues[MAX_VENUES]; // Array of venue_t structures
    int num_venues = 0; // Number of venues read from file
    char row[MAXCHAR];
    FILE *fp;

    // Open file for read
    fp = fopen("venue.csv", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read and process each line
    while (fgets(row, MAXCHAR, fp) != NULL) {
        // Tokenize the row
        char *token = strtok(row, ",");
        if (token != NULL)
            strcpy(venues[num_venues].location, token);
        token = strtok(NULL, ",");
        if (token != NULL)
            strcpy(venues[num_venues].lecture_venue, token);
        token = strtok(NULL, ",");
        if (token != NULL)
            strcpy(venues[num_venues].Lab_venue, token);
        token = strtok(NULL, ",");
        if (token != NULL)
            venues[num_venues].capacity = atoi(token);

        num_venues++; // Increment number of venues
    }

    // Close the file
    fclose(fp);

    // Display data to the user
    display_venue(venues, num_venues);

    return 0;
}
void display_venue(venue_t v[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s, %s, %s, %d\n", v[i].location, v[i].lecture_venue, v[i].Lab_venue, v[i].capacity);
    }
}
// void find_venue(void)
//  {
//     char venue_name[50]; 
//     int found = 0;
//     venue_t v;
//     FILE *fp;
//     // input faculty name to be found
//     printf("Enter Venue name : ");
//     scanf("%s", venue_name);
//     // open file for read
//     fp = fopen("venue.csv", "r");
//     if(fp == NULL) {
//         perror("fopen() failed");
//         exit(1);
//     }
//     // read data from file
//     char line[256];
//     fgets(line, sizeof(line), fp); // Skip the header line
//     while (fgets(line, sizeof(line), fp) != NULL) {
//         char *Location= strtok(line, ",");
//         char *Lecture_Venue = strtok(line, ",");
//         char *Lab_venue = strtok(NULL, ",");
//         char *Capacity = strtok(NULL, ",");
        
//         // remove newline character from modulename
//         Capacity[strcspn(Capacity, "\n")] = 0;
//         // compare faculty name
//         if(strcmp(Location, venue_name) == 0) {
//             // display data to user
//             printf("Location: %s, Lecture_Venue: %s, Lab_venue: %s,Capacity : %d\n", Location, Lecture_Venue, Lab_venue,Lab_venue);
//             found = 1;
//         }
//     } // repeat until end of file
//     // close file
//     fclose(fp);
//     if(found == 0)
//         printf("Faculty not found.\n");
// }
void find_venue(void) {
    char venue_name[50]; 
    int found = 0;
    venue_t v;
    FILE *fp;
    // input venue name to be found
    printf("Enter Venue name : ");
    scanf("%s", venue_name);
    // open file for read
    fp = fopen("venue.csv", "r");
    if(fp == NULL) {
        perror("fopen() failed");
        exit(1);
    }
    // read data from file
    char line[256];
    fgets(line, sizeof(line), fp); // Skip the header line
    while (fgets(line, sizeof(line), fp) != NULL) {
        // tokenize the line
        char *Location = strtok(line, ",");
        char *Lecture_Venue = strtok(NULL, ",");
        char *Lab_venue = strtok(NULL, ",");
        char *Capacity_str = strtok(NULL, ",");
        
        // convert capacity string to integer
        int Capacity = atoi(Capacity_str);
        
        // remove newline character from venue name
        Location[strcspn(Location, "\n")] = 0;
        // compare venue name
        if(strcmp(Location, venue_name) == 0) {
            // display data to user
            printf("Location: %s, Lecture Venue: %s, Lab Venue: %s, Capacity: %d\n", Location, Lecture_Venue, Lab_venue, Capacity);
            found = 1;
        }
    } // repeat until end of file
    // close file
    fclose(fp);
    if(found == 0)
        printf("Venue not found.\n");
}

int main() {
    struct batches batch;
    acceptData(&batch);
    printData(&batch);
    storeData(&batch, "batch.csv");
    load_venues( ); 
    find_venue( ); 
    return 0;
}

void read_module(module md[])
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

void display_module(module md[])
{   
    for(int i=0;i<mod_count;i++)
    {
        printf("%s, %s, %d, %d\n",md[i].name,md[i].type,md[i].theory_hrs,md[i].lab_hrs);
    }
}


void read_faculty(Faculty fc[])
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
void display_faculty(Faculty fc[])
{
    for(int i=0;i<fc_count;i++)
    {
        printf("%s %s %s",fc[i].name,fc[i].lecture_lab,fc[i].modulename);
    }
}
void find_facutly(void) 
{
    char faculty_name[50]; 
    int found = 0;
    Faculty f;
    FILE *fp;
    // input faculty name to be found
    printf("Enter faculty name to find: ");
    scanf("%s", faculty_name);
    // open file for read
    fp = fopen("faculties.csv", "r");
    if(fp == NULL) {
        perror("fopen() failed");
        exit(1);
    }
    // read data from file
    char line[256];
    fgets(line, sizeof(line), fp); // Skip the header line
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *name = strtok(line, ",");
        char *lecture_lab = strtok(NULL, ",");
        char *modulename = strtok(NULL, ",");
        
        // remove newline character from modulename
        modulename[strcspn(modulename, "\n")] = 0;
        // compare faculty name
        if(strcmp(name, faculty_name) == 0) {
            // display data to user
            printf("Faculty Name: %s, Lecture/Lab: %s, ModuleName: %s\n", name, lecture_lab, modulename);
            found = 1;
        }
    } // repeat until end of file
    // close file
    fclose(fp);
    if(found == 0)
        printf("Faculty not found.\n");
}

// int main2()
// {
//     Faculty fc[100];
//     read_data(fc);
//     display(fc);
   
//     return 0;
// }