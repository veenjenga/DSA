#include <iostream>
#include <string>

class Course {
public:
    std::string course_code;
    std::string course_name;
};

class Grade {
public:
    int mark;
    char the_grade;

    // Calculate grade based on the grading system
    void calculateGrade() {
        if (mark > 69) {
            the_grade = 'A';
        } else if (mark > 59) {
            the_grade = 'B';
        } else if (mark > 49) {
            the_grade = 'C';
        } else if (mark > 39) {
            the_grade = 'D';
        } else {
            the_grade = 'E';
        }
    }
};

class Student {
public:
    std::string reg_number;
    std::string name;
    int age;
    Course courses[2]; // Assuming each student can have up to 2 courses
    Grade grades[2];   // Corresponding grades for each course

    // Member function to add a student
    void addStudent() {
        std::cout << "Enter registration number: ";
        std::cin >> reg_number;

        std::cout << "Enter name: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        std::cout << "Enter age: ";
        std::cin >> age;

        for (int i = 0; i < 2; ++i) {
            std::cout << "Enter course " << i + 1 << " details:" << std::endl;
            std::cout << "  Enter course code: ";
            std::cin >> courses[i].course_code;

            std::cout << "  Enter course name: ";
            std::cin.ignore();
            std::getline(std::cin, courses[i].course_name);

            // Initialize grades to -1 (indicating not calculated yet)
            grades[i].mark = -1;
        }

        std::cout << "Student added successfully!" << std::endl;
    }

    // Member function to edit a student's details
    void editStudentDetails() {
        std::cout << "Enter new details for student with registration number " << reg_number << ":" << std::endl;
        std::cout << "Enter new name: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        std::cout << "Enter new age: ";
        std::cin >> age;

        std::cout << "Details updated successfully!" << std::endl;
    }

    // Member function to add marks and calculate grades
    void addMarksAndCalculateGrades() {
        for (int i = 0; i < 2; ++i) {
            std::cout << "Enter mark for " << courses[i].course_code << ": ";
            std::cin >> grades[i].mark;

            // Calculate grade based on the grading system
            grades[i].calculateGrade();
        }

        std::cout << "Marks and grades added successfully!" << std::endl;
    }

    // Member function to display student details
    void displayStudentDetails() const {
        std::cout << "Registration Number: " << reg_number << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;

        for (int i = 0; i < 2; ++i) {
            std::cout << "Course " << i + 1 << " details:" << std::endl;
            std::cout << "  Course Code: " << courses[i].course_code << std::endl;
            std::cout << "  Course Name: " << courses[i].course_name << std::endl;

            if (grades[i].mark != -1) {
                std::cout << "  Mark: " << grades[i].mark << std::endl;
                std::cout << "  Grade: " << grades[i].the_grade << std::endl;
            } else {
                std::cout << "  Marks and grade not available." << std::endl;
            }
        }
    }
};

int main() {
    const int MAX_STUDENTS = 40;
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add a student" << std::endl;
        std::cout << "2. Edit a student's details" << std::endl;
        std::cout << "3. Add marks and calculate grades" << std::endl;
        std::cout << "4. Display all students' details" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                if (studentCount < MAX_STUDENTS) {
                    students[studentCount].addStudent();
                    ++studentCount;
                } else {
                    std::cout << "Cannot add more students. Maximum limit reached." << std::endl;
                }
                break;
            case 2:
                if (studentCount > 0) {
                    students[studentCount - 1].editStudentDetails();
                } else {
                    std::cout << "No students available to edit." << std::endl;
                }
                break;
            case 3:
                if (studentCount > 0) {
                    students[studentCount - 1].addMarksAndCalculateGrades();
                } else {
                    std::cout << "No students available to add marks." << std::endl;
                }
                break;
            case 4:
                if (studentCount > 0) {
                    for (int i = 0; i < studentCount; ++i) {
                        std::cout << "Student " << i + 1 << " details:" << std::endl;
                        students[i].displayStudentDetails();
                        std::cout << std::endl;
                    }
                } else {
                    std::cout << "No students available to display." << std::endl;
                }
                break;
            case 5:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }

    } while (choice != 5);

    return 0;
}