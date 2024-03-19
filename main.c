// Include necessary header files
#include <stdio.h>
#include <string.h> // Include string.h for string manipulation functions
#include "batch.h"
#include "faculty.h"
#include "module.h"
#include "venue.h"
#include "schedule.h"

int main()
{
    int mod_count = 0;
    // Load data from CSV files
    loadModules(); // Load module data from "modules.csv"
                   // Display loaded modules
    printf("Loaded Modules:\n");
    for (int i = 0; i < mod_count; i++)
    {
        printf("Module Name: %s, Type: %s, Theory Hours: %d, Lab Hours: %d\n", modules[i].name, modules[i].type, modules[i].theory_hrs, modules[i].lab_hrs);
    }
    loadVenues(); // Load venue data from "venue.csv"

    // Accept batch data
    struct batches batch;
    acceptData(&batch); // Prompt user to enter batch details

    // Display batch data
    printf("\nBatch Details:\n");
    printData(&batch); // Print the entered batch details

    // Assign modules to the batch
    assignModules(&batch); // Assign modules to the batch
    storeData(&batch, "batch_data.txt");

    // Load and display faculties
    Faculty fc[MAX_FACULTIES];
    loadFaculties(fc);

    // Display all loaded faculties
    printf("All Faculties:\n");
    displayAllFaculties(fc);

    // Find a faculty by name
    find_faculty();

    // Display all loaded modules
    printf("All Modules:\n");
    displayAllModules(modules); // Display all loaded modules

    // Display loaded venues
    printf("Venues loaded:\n");
    venue_t *venues = getVenuesArray();
    display_venue(venues, NUM_VENUES, NUM_VENUES);

    // Assign a venue
    venue_t selectedVenue = assignVenue();

    /*
                                    // Assign schedule
                                    for (int i = 0; i < batch.numModules; i++)
                                    {
                                    assignSchedule(&batch, selectedFaculty, batch.modules[i].name); // Assign schedule for each module
                                    }

                                    // Display the schedule
                                    displaySchedule(&batch); // Display the generated schedule

                                    // Display venue details
                                    printf("Venue: %s, Lecture Venue: %s, Lab Venue: %s, Capacity: %d\n", selectedVenue.location, selectedVenue.lecture_venue, selectedVenue.Lab_venue, selectedVenue.capacity); // Display selected venue details

                                    storeData(&batch, "batch_data.csv"); // Store batch data in "batch_data.csv"
                                    */

    return 0;
}