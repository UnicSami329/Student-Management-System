```c
#include <stdio.h>

struct Student {
    int id;
    char name[50];
    int marks;
};

char getGrade(int marks) {
    if (marks >= 90)
        return 'A';
    else if (marks >= 75)
        return 'B';
    else if (marks >= 60)
        return 'C';
    else if (marks >= 40)
        return 'D';
    else
        return 'F';
}

int main() {

    struct Student students[100];

    int choice;
    int count = 0;
    int searchId;
    int found;

    do {

        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:

                if (count >= 100) {
                    printf("\nStudent limit reached!\n");
                    break;
                }

                printf("\nEnter Student ID: ");
                scanf("%d", &students[count].id);

                printf("Enter Student Name: ");
                scanf("%49s", students[count].name);

                printf("Enter Marks: ");
                scanf("%d", &students[count].marks);

                if (students[count].marks < 0 ||
                    students[count].marks > 100) {

                    printf("\nInvalid marks! Enter marks between 0 and 100.\n");
                    break;
                }

                count++;

                printf("\nStudent added successfully!\n");

                break;


            case 2:

                printf("\n===== ALL STUDENTS =====\n");

                if (count == 0) {

                    printf("No students added yet.\n");

                } else {

                    for (int i = 0; i < count; i++) {

                        printf("\nStudent %d\n", i + 1);
                        printf("ID: %d\n", students[i].id);
                        printf("Name: %s\n", students[i].name);
                        printf("Marks: %d\n", students[i].marks);
                        printf("Grade: %c\n",
                               getGrade(students[i].marks));
                    }
                }

                break;


            case 3:

                printf("\nEnter Student ID to search: ");
                scanf("%d", &searchId);

                found = 0;

                for (int i = 0; i < count; i++) {

                    if (students[i].id == searchId) {

                        printf("\n===== STUDENT FOUND =====\n");
                        printf("ID: %d\n", students[i].id);
                        printf("Name: %s\n", students[i].name);
                        printf("Marks: %d\n", students[i].marks);
                        printf("Grade: %c\n",
                               getGrade(students[i].marks));

                        found = 1;
                        break;
                    }
                }

                if (found == 0) {
                    printf("\nStudent not found!\n");
                }

                break;


            case 4:

                printf("\nThank you for using Student Management System!\n");

                break;


            default:

                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
```
