// function to find venue 
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
