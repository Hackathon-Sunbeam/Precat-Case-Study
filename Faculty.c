#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char name[50];
    char lecture_lab[50];
    char modulename[50];
} Faculty;
Faculty *readFaculties(const char *filename, int *numFaculties)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    // Skip the header line
    char line[256];
    fgets(line, sizeof(line), file);
    // Count the number of faculties in the file
    *numFaculties = 0;
    while (fgets(line, sizeof(line), file) != NULL)
    {
        (*numFaculties)++;
    }
    // Allocate memory for the faculties array
    Faculty *faculties = (Faculty *)malloc(*numFaculties * sizeof(Faculty));
    if (faculties == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    // Read faculties data from the file
    rewind(file);
    fgets(line, sizeof(line), file); // Skip the header line
    for (int i = 0; i < *numFaculties; i++)
    {
        fgets(line, sizeof(line), file);
        char *name = strtok(line, ",");
        char *lecture_lab = strtok(NULL, ",");
        char *modulename = strtok(NULL, ",");
        // other attributes can be read in a similar manner
        strcpy(faculties[i].name, name);
        strcpy(faculties[i].lecture_lab, lecture_lab);
        strtok(modulename, "\n");
        strcpy(faculties[i].modulename, modulename);
        // other attributes can be assigned in a similar manner
    }
    fclose(file);
    return faculties;
}
void display_emp(Faculty *f)
{
    printf("%s %s %s",f->modulename,f->name,f->name);
}


int main()
{
    int numFaculties;
    Faculty *faculties = readFaculties("faculties.csv", &numFaculties);
    // Print the faculties
    for (int i = 0; i < numFaculties; i++)
    {
        printf("Faculty Name: %s, Lecture/Lab: %s, ModuleName: %s\n", faculties[i].name, faculties[i].lecture_lab, faculties[i].modulename);
    }
    find_facutly( ); 
   
    return 0;
}