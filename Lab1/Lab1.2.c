#include <stdio.h>
#include <string.h>

// Define the course structure
struct Course {
    char course_code[10];
    char course_name[30];
};

// Define the grade structure
struct Grade {
    int mark;
    char the_grade;
};

// Define the student structure
struct Student {
    char reg_number[20];
    char name[50];
    int age;
    struct Course course;
    struct Grade grades;
};

// Function to calculate the grade based on the mark
char calculateGrade(int mark) {
    if (mark > 69) {
        return 'A';
    } else if (mark > 59) {
        return 'B';
    } else if (mark > 49) {
        return 'C';
    } else if (mark > 39) {
        return 'D';
    } else {
        return 'E';
    }
}

// Function to add a student
void addStudent(struct Student students[], int *count) {
    if (*count < 40) {
        struct Student newStudent;
        
        printf("Enter registration number: ");
        scanf("%s", newStudent.reg_number);
        
        printf("Enter name: ");
        scanf("%s", newStudent.name);
        
        printf("Enter age: ");
        scanf("%d", &newStudent.age);

        printf("Enter course code: ");
        scanf("%s", newStudent.course.course_code);

        printf("Enter course name: ");
        scanf("%s", newStudent.course.course_name);

        // Initialize grade with default values
        newStudent.grades.mark = -1;
        newStudent.grades.the_grade = 'N'; // 'N' denotes grade not calculated yet

        students[*count] = newStudent;
        (*count)++;
        
        printf("Student added successfully!\n");
    } else {
        printf("Maximum number of students reached!\n");
    }
}

// Function to edit a student's details
void editStudent(struct Student students[], int count) {
    char regNumber[20];
    int found = 0;

    printf("Enter registration number of the student to edit: ");
    scanf("%s", regNumber);

    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].reg_number, regNumber) == 0) {
            printf("Enter new name: ");
            scanf("%s", students[i].name);
            
            printf("Enter new age: ");
            scanf("%d", &students[i].age);

            printf("Student details updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }
}

// Function to add marks and calculate grades
void addMarks(struct Student students[], int count) {
    char regNumber[20];
    int found = 0;

    printf("Enter registration number of the student to add marks: ");
    scanf("%s", regNumber);

    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].reg_number, regNumber) == 0) {
            printf("Enter marks: ");
            scanf("%d", &students[i].grades.mark);

            students[i].grades.the_grade = calculateGrade(students[i].grades.mark);

            printf("Marks added and grades calculated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }
}

// Function to display student details
void displayStudents(struct Student students[], int count) {
    printf("\nStudent Details:\n");
    for (int i = 0; i < count; i++) {
        printf("Registration Number: %s\n", students[i].reg_number);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Course Code: %s\n", students[i].course.course_code);
        printf("Course Name: %s\n", students[i].course.course_name);
        
        if (students[i].grades.mark != -1) {
            printf("Marks: %d\n", students[i].grades.mark);
            printf("Grade: %c\n", students[i].grades.the_grade);
        } else {
            printf("Marks: Not available\n");
            printf("Grade: Not calculated\n");
        }

        printf("------------------------\n");
    }
}

int main() {
    struct Student students[40];
    int studentCount = 0;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Edit Student Details\n");
        printf("3. Add Marks and Calculate Grades\n");
        printf("4. Display Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                editStudent(students, studentCount);
                break;
            case 3:
                addMarks(students, studentCount);
                break;
            case 4:
                displayStudents(students, studentCount);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}