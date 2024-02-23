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
