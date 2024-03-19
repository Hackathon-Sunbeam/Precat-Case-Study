// venue.h
#ifndef VENUE_H
#define VENUE_H

#define NUM_VENUES 6

#define MAX_NAME_LENGTH 30
#define MAX_LOCATION_LENGTH 20

typedef struct
{
    char location[MAX_NAME_LENGTH];
    char lecture_venue[MAX_LOCATION_LENGTH];
    char Lab_venue[MAX_LOCATION_LENGTH];
    int capacity;
} venue_t;

venue_t *getVenuesArray();
extern venue_t venues[]; // Declare the array

void loadVenues();
void display_venue(venue_t v[], int size, int num_venues);
venue_t assignVenue();

#endif