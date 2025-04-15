#include <stdio.h>

#define MAX_SUBJECTS 5
#define MAX_STUDENTS 3
float calculateAverage(float marks[], int num_subjects) {
    float total = 0;
    for (int i = 0; i < num_subjects; i++) {
        total += marks[i];
    }
    return total / num_subjects;
}
void determineStatus(float average, char *status) {
    if (average >= 60) {
        snprintf(status, 10, "Passed");
    } else {
        snprintf(status, 10, "Failed");
    }
}
void inputMarks(float marks[], int num_subjects) {
    printf("Enter marks for %d subjects:\n", num_subjects);
    for (int i = 0; i < num_subjects; i++) {
        while (1) {
            printf("Enter marks for subject %d (0-100): ", i + 1);
            scanf("%f", &marks[i]);

            if (marks[i] >= 0 && marks[i] <= 100) {
                break;  
            } else {
                printf("Invalid marks! Please enter a value between 0 and 100.\n");
            }
        }
    }
}
void printStudentReport(int student_id, float marks[], float average, char *status) {
    printf("\n--- Report for Student %d ---\n", student_id);
    printf("Marks for Subjects: ");
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("%.2f ", marks[i]);
    }
    printf("\nTotal Marks: %.2f\n", average * MAX_SUBJECTS);
    printf("Average Marks: %.2f\n", average);
    printf("Performance Status: %s\n", status);
}

int main() {
    int num_students = 0;
    float marks[MAX_SUBJECTS];
    float average;
    char status[10];
    printf("Enter the number of students (max %d): ", MAX_STUDENTS);
    scanf("%d", &num_students);
    if (num_students > MAX_STUDENTS) {
        printf("The number of students cannot exceed %d.\n", MAX_STUDENTS);
        return 1;  
    }
    for (int student_id = 1; student_id <= num_students; student_id++) {
        
        inputMarks(marks, MAX_SUBJECTS);
        average = calculateAverage(marks, MAX_SUBJECTS);
        determineStatus(average, status);
        printStudentReport(student_id, marks, average, status);
    }
    return 0;
}
