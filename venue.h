// venue.h
#ifndef VENUE_H
#define VENUE_H

#define MAX_NAME_LENGTH 30
#define MAX_LOCATION_LENGTH 20

typedef struct
{
    char location[MAX_NAME_LENGTH];
    char lecture_venue[MAX_LOCATION_LENGTH];
    char Lab_venue[MAX_LOCATION_LENGTH];
    int capacity;
} venue_t;

void loadVenues();
void display_venue(venue_t v[], int size);
Venue assignVenue();

#endif
