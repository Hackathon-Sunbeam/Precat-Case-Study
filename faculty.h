#ifndef FACULTY_H
#define FACULTY_H

typedef struct
{
    char name[50];
    char lecture_lab[50];
    char modulename[50];
} Faculty;

void loadFaculties(Faculty fc[]);
void displayAllFaculties(Faculty fc[]);
void find_faculty(void);

#endif
