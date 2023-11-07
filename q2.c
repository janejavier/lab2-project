#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_SUBJECTS 5
#define MAX_STUDENTS 100


struct StudentRecord {
    char FirstName[MAX_NAME_LENGTH];
    char LastName[MAX_NAME_LENGTH];
    int StudentID;
    float SubjectMarks[MAX_SUBJECTS];
    int AggregateMarks;
    char Grade[MAX_NAME_LENGTH];
};


void enrol(struct StudentRecord students[], int studentIndex);
void searchUpdate(struct StudentRecord students[], int numOfStudents);
void topStudents(struct StudentRecord students[], int numOfStudents);

int main() {
    int numOfSubjects = MAX_SUBJECTS;
    int numOfStudents = 0; 
    struct StudentRecord students[MAX_STUDENTS];


    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Enroll a student\n");
        printf("2. Search and update student record\n");
        printf("3. Display top students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enrol(students, numOfStudents);
                numOfStudents++; 
                break;
            case 2:
                searchUpdate(students, numOfStudents);
                break;
            case 3:
                topStudents(students, numOfStudents);
                break;
            case 4:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void enrol(struct StudentRecord students[], int studentIndex) {
    if (studentIndex >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    struct StudentRecord *student = &students[studentIndex];

    printf("\nEnrolling a student:\n");
    printf("Enter First Name: ");
    scanf("%s", student->FirstName);
    printf("Enter Last Name: ");
    scanf("%s", student->LastName);
    printf("Enter Student ID: ");
    scanf("%d", &(student->StudentID));

    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("Enter mark for Subject %d (-1 if not available): ", i);
        scanf("%f", &(student->SubjectMarks[i]));
    }

    float sum = 0;
    int numAvailableSubjects = 0;
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        if (student->SubjectMarks[i] != -1) {
            sum += student->SubjectMarks[i];
            numAvailableSubjects++;
        }
    }

    if (numAvailableSubjects == MAX_SUBJECTS) {
        student->AggregateMarks = (int)(sum / MAX_SUBJECTS);
    } else {
        student->AggregateMarks = -1;
    }


    if (student->AggregateMarks >= 85 && student->AggregateMarks <= 100) {
        strcpy(student->Grade, "HD");
    } else if (student->AggregateMarks >= 75 && student->AggregateMarks < 85) {
        strcpy(student->Grade, "D");
    } else if (student->AggregateMarks >= 65 && student->AggregateMarks < 75) {
        strcpy(student->Grade, "C");
    } else if (student->AggregateMarks >= 50 && student->AggregateMarks < 65) {
        strcpy(student->Grade, "P");
    } else if (student->AggregateMarks < 50) {
        strcpy(student->Grade, "F");
    } else {
        strcpy(student->Grade, "undefined");
    }

    printf("Student enrolled successfully.\n");
}

void searchUpdate(struct StudentRecord students[], int numOfStudents) {
    int choice;
    printf("\nSearch and update student record:\n");
    printf("1. Search by Student ID\n");
    printf("2. Search by Last Name\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int studentID;
        printf("Enter Student ID: ");
        scanf("%d", &studentID);

        for (int i = 0; i < numOfStudents; i++) {
            if (students[i].StudentID == studentID) {

                printf("Record Found:\n");
                printf("First Name: %s\n", students[i].FirstName);
                printf("Last Name: %s\n", students[i].LastName);
                printf("Student ID: %d\n", students[i].StudentID);
                printf("Aggregate Marks: %d\n", students[i].AggregateMarks);
                printf("Grade: %s\n", students[i].Grade);


                printf("\nUpdate student's record:\n");
                printf("Enter First Name: ");
                scanf("%s", students[i].FirstName);
                printf("Enter Last Name: ");
                scanf("%s", students[i].LastName);

                for (int j = 0; j < MAX_SUBJECTS; j++) {
                    printf("Enter mark for Subject %d (-1 if not available): ", j);
                    scanf("%f", &(students[i].SubjectMarks[j]));
                }


                float sum = 0;
                int numAvailableSubjects = 0;
                for (int j = 0; j < MAX_SUBJECTS; j++) {
                    if (students[i].SubjectMarks[j] != -1) {
                        sum += students[i].SubjectMarks[j];
                        numAvailableSubjects++;
                    }
                }

                if (numAvailableSubjects == MAX_SUBJECTS) {
                    students[i].AggregateMarks = (int)(sum / MAX_SUBJECTS);
                } else {
                    students[i].AggregateMarks = -1;
                }


                if (students[i].AggregateMarks >= 85 && students[i].AggregateMarks <= 100) {
                    strcpy(students[i].Grade, "HD");
                } else if (students[i].AggregateMarks >= 75 && students[i].AggregateMarks < 85) {
                    strcpy(students[i].Grade, "D");
                } else if (students[i].AggregateMarks >= 65 && students[i].AggregateMarks < 75) {
                    strcpy(students[i].Grade, "C");
                } else if (students[i].AggregateMarks >= 50 && students[i].AggregateMarks < 65) {
                    strcpy(students[i].Grade, "P");
                } else if (students[i].AggregateMarks < 50) {
                    strcpy(students[i].Grade, "F");
                } else {
                    strcpy(students[i].Grade, "undefined");
                }

                printf("Record updated successfully.\n");
                return;
            }
        }

        printf("No record found with the given Student ID.\n");
    } else if (choice == 2) {
        char lastName[MAX_NAME_LENGTH];
        printf("Enter Last Name: ");
        scanf("%s", lastName);

        for (int i = 0; i < numOfStudents; i++) {
            if (strcmp(students[i].LastName, lastName) == 0) {
 
                printf("Record Found:\n");
                printf("First Name: %s\n", students[i].FirstName);
                printf("Last Name: %s\n", students[i].LastName);
                printf("Student ID: %d\n", students[i].StudentID);
                printf("Aggregate Marks: %d\n", students[i].AggregateMarks);
                printf("Grade: %s\n", students[i].Grade);

                printf("\nUpdate student's record:\n");
                printf("Enter First Name: ");
                scanf("%s", students[i].FirstName);
                printf("Enter Last Name: ");
                scanf("%s", students[i].LastName);

                for (int j = 0; j < MAX_SUBJECTS; j++) {
                    printf("Enter mark for Subject %d (-1 if not available): ", j);
                    scanf("%f", &(students[i].SubjectMarks[j]));
                }

   
                float sum = 0;
                int numAvailableSubjects = 0;
                for (int j = 0; j < MAX_SUBJECTS; j++) {
                    if (students[i].SubjectMarks[j] != -1) {
                        sum += students[i].SubjectMarks[j];
                        numAvailableSubjects++;
                    }
                }

                if (numAvailableSubjects == MAX_SUBJECTS) {
                    students[i].AggregateMarks = (int)(sum / MAX_SUBJECTS);
                } else {
                    students[i].AggregateMarks = -1;
                }

                
                if (students[i].AggregateMarks >= 85 && students[i].AggregateMarks <= 100) {
                    strcpy(students[i].Grade, "HD");
                } else if (students[i].AggregateMarks >= 75 && students[i].AggregateMarks < 85) {
                    strcpy(students[i].Grade, "D");
                } else if (students[i].AggregateMarks >= 65 && students[i].AggregateMarks < 75) {
                    strcpy(students[i].Grade, "C");
                } else if (students[i].AggregateMarks >= 50 && students[i].AggregateMarks < 65) {
                    strcpy(students[i].Grade, "P");
                } else if (students[i].AggregateMarks < 50) {
                    strcpy(students[i].Grade, "F");
                    } else {
                    strcpy(students[i].Grade, "undefined");
                }

                printf("Record updated successfully.\n");
                return;
            }
        }

        printf("No record found with the given Last Name.\n");
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}

void topStudents(struct StudentRecord students[], int numOfStudents) {
    printf("\nDisplay top student:\n");

    if (numOfStudents <= 0) {
        printf("no students found.\n");
        return;
    }

    struct StudentRecord topStudent = students[0];

    for (int i = 1; i < numOfStudents; i++) {
        if (students[i].AggregateMarks > topStudent.AggregateMarks) {
            topStudent = students[i];
        }
    }

 
    printf("Top Student:\n");
    printf("First Name: %s\n", topStudent.FirstName);
    printf("Last Name: %s\n", topStudent.LastName);
    printf("Student ID: %d\n", topStudent.StudentID);
    printf("Aggregate Marks: %.2d\n", topStudent.AggregateMarks);
}
