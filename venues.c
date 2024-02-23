// load the venues from csv file 
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
