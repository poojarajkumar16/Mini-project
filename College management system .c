#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 5
#define MAX_NAME_LENGTH 50
#define MAX_ROLL_LENGTH 10

typedef struct {
    char course_name[MAX_NAME_LENGTH];
    float grade;
} Course;

typedef struct {
    char name[MAX_NAME_LENGTH];
    char roll_number[MAX_ROLL_LENGTH];
    Course courses[MAX_COURSES];
    int num_courses;
} Student;

Student students[MAX_STUDENTS];
int num_students = 0;

void addStudent() {
    if (num_students >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    Student new_student;
    printf("Enter student name: ");
    scanf("%s", new_student.name);
    printf("Enter student roll number: ");
    scanf("%s", new_student.roll_number);

    printf("Enter number of courses: ");
    scanf("%d", &new_student.num_courses);

    printf("Enter details for each course:\n");
    for (int i = 0; i < new_student.num_courses; i++) {
        printf("Course %d name: ", i + 1);
        scanf("%s", new_student.courses[i].course_name);
        printf("Grade for course %d: ", i + 1);
        scanf("%f", &new_student.courses[i].grade);
    }

    students[num_students++] = new_student;
    printf("Student added successfully.\n");
}

void displayStudents() {
    printf("List of students:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s, Roll Number: %s\n", students[i].name, students[i].roll_number);
        printf("Courses:\n");
        for (int j = 0; j < students[i].num_courses; j++) {
            printf("%s: %.2f\n", students[i].courses[j].course_name, students[i].courses[j].grade);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nCollege Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}
