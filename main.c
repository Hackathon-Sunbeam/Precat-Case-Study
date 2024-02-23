#include <stdio.h>
#include "batch.h"
#include "faculty.h"
#include "module.h"
#include "venue.h"
#include "schedule.h"

int main()
{
    // Load data from CSV files
    loadModules();
    loadVenues();

    // Accept batch data
    struct batches batch;
    acceptData(&batch);

    // Display batch data
    printData(&batch);

    // Assign modules to the batch
    assignModules(&batch);

    // Display all modules
    displayAllModules(modules);

    // Display all faculties
    displayAllFaculties(faculties);

    // Assign venues
    venue_t selectedVenue = assignVenue();

    // Assign faculty
    Faculty selectedFaculty;

    // Assign schedule
    for (int i = 0; i < batch.numModules; i++)
    {
        assignSchedule(&batch, selectedFaculty, batch.modules[i].name);
    }

    // Display the schedule
    displaySchedule(&batch);

    // Display venue details
    printf("Venue: %s, Lecture Venue: %s, Lab Venue: %s, Capacity: %d\n", selectedVenue.location, selectedVenue.lecture_venue, selectedVenue.Lab_venue, selectedVenue.capacity);

    storeData(&batch, "batch_data.csv");

    return 0;
}
