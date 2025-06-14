#include <stdio.h>
#include <string.h>

#define SIZE 100

// Declare global arrays to store student data
int rollNo[SIZE];
char name[SIZE][50];
float marks[SIZE];
char grade[SIZE];
int count = 0;

// Function to Add a New Student
void addStudent() {
    printf("\nEnter Roll Number: ");
    scanf("%d", &rollNo[count]);
    printf("Enter Name: ");
    scanf(" %[^\n]s", name[count]);
    printf("Enter Marks: ");
    scanf("%f", &marks[count]);
    printf("Enter Grade: ");
    scanf(" %c", &grade[count]);

    count++;
    printf("Student added successfully!\n");
}

// Function to Display All Students
void displayStudents() {
    printf("\n--- Student List ---\n");
    int i;
    for (i = 0; i < count; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f, Grade: %c\n",
               rollNo[i], name[i], marks[i], grade[i]);
    }
}

// Function to Update a Student
void updateStudent() {
    int r, found = 0;
    printf("\nEnter Roll Number to Update: ");
    scanf("%d", &r);
    int i;
    for (i = 0; i < count; i++) {
        if (rollNo[i] == r) {
            printf("Enter new Name: ");
            scanf(" %[^\n]s", name[i]);
            printf("Enter new Marks: ");
            scanf("%f", &marks[i]);
            printf("Enter new Grade: ");
            scanf(" %c", &grade[i]);
            printf("Student Updated Successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");
}

// Function to Delete a Student
void deleteStudent() {
    int r, found = 0;
    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &r);
     int i;
    for (i = 0; i < count; i++) {
        if (rollNo[i] == r) {
        	int j;
            for (j = i; j < count - 1; j++) {
                rollNo[j] = rollNo[j + 1];
                strcpy(name[j], name[j + 1]);
                marks[j] = marks[j + 1];
                grade[j] = grade[j + 1];
            }
            count--;
            printf("Student Deleted Successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");
}

// Function to Search a Student
void searchStudent() {
    int r, found = 0;
    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &r);
   int i;
    for (i = 0; i < count; i++) {
        if (rollNo[i] == r) {
            printf("Student Found!\n");
            printf("Name: %s\n", name[i]);
            printf("Marks: %.2f\n", marks[i]);
            printf("Grade: %c\n", grade[i]);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");
}

// Function to Show Academic Progress (all marks and grades)
void showProgress() {
    printf("\n--- Academic Progress ---\n");
    int i;
    for (i = 0; i < count; i++) {
        printf("Name: %s, Marks: %.2f, Grade: %c\n", name[i], marks[i], grade[i]);
    }
}

// Main Program with Menu
int main() {
    int choice;

    do {
        printf("\n=== Student Management System ===\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Search Student\n");
        printf("6. Show Academic Progress\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: searchStudent(); break;
            case 6: showProgress(); break;
            case 7: printf("Exiting program...\n"); break;
            default: printf("Invalid Choice!\n");
        }
    } while (choice != 7);

    return 0;
}

