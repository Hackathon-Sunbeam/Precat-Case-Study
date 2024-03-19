// venue.c
#include <stdio.h>
#include <stdlib.h>
#include "venue.h"

#define MAXCHAR 1000
#define MAX_VENUES 100
venue_t venues[MAX_VENUES];

// static venue_t venues[MAX_VENUES]; // Array of venue_t structures
// venue_t venues[MAX_VENUES];        // Define the array
void loadVenues()
{

    char row[MAXCHAR];
    FILE *fp;
    // Open file for read
    fp = fopen("venue.csv", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(EXIT_FAILURE);
    }
    // Read and process each line
    for (int i = 0; i < NUM_VENUES; i++)
    {
        if (fgets(row, MAXCHAR, fp) != NULL)
        {
            // Tokenize the row
            char *token = strtok(row, ",");
            if (token != NULL)
                strcpy(venues[i].location, token);
            token = strtok(NULL, ",");
            if (token != NULL)
                strcpy(venues[i].lecture_venue, token);
            token = strtok(NULL, ",");
            if (token != NULL)
                strcpy(venues[i].Lab_venue, token);
            token = strtok(NULL, ",");
            if (token != NULL)
                venues[i].capacity = atoi(token);
        }
        else
        {
            printf("Error reading data from file!\n");
            exit(EXIT_FAILURE);
        }
    }
    // Close the file
    fclose(fp);
}

void display_venue(venue_t v[], int size, int num_venues)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s, %s, %s, %d\n", v[i].location, v[i].lecture_venue, v[i].Lab_venue, v[i].capacity);
    }
}

venue_t *getVenuesArray()
{
    return venues;
}

venue_t assignVenue()
{
    int venueChoice;
    venue_t selectedVenue;

    printf("Select Venue: ");
    scanf("%d", &venueChoice);

    if (venueChoice >= 1 && venueChoice <= NUM_VENUES)
    {
        selectedVenue = venues[venueChoice - 1];
        printf("Venue %s selected at %s with a capacity of %d\n", selectedVenue.location, selectedVenue.lecture_venue, selectedVenue.capacity);
    }
    else
    {
        printf("Invalid Venue choice.\n");
        exit(EXIT_FAILURE);
    }

    return selectedVenue;
}
