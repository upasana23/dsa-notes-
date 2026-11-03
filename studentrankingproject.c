
#include <stdio.h>
#include <string.h>

#define MAX 100
#define SUBJECTS 5

struct Student {
    int id;
    char name[50];
    float marks[SUBJECTS];
    float total;
    float average;
    int rank;
};

struct Student students[MAX];
int count = 0;

// Calculate total and average
void calculateAverage(struct Student *s) {
    s->total = 0;

    for (int i = 0; i < SUBJECTS; i++) {
        s->total += s->marks[i];
    }

    s->average = s->total / SUBJECTS;
}

// Add student
void addStudent() {
    if (count >= MAX) {
        printf("Student limit reached!\n");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &students[count].id);

    // Check duplicate ID
    for (int i = 0; i < count; i++) {
        if (students[i].id == students[count].id) {
            printf("Student ID already exists!\n");
            return;
        }
    }

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", students[count].name);

    printf("Enter marks in %d subjects:\n", SUBJECTS);

    for (int i = 0; i < SUBJECTS; i++) {
        do {
            printf("Subject %d: ", i + 1);
            scanf("%f", &students[count].marks[i]);

            if (students[count].marks[i] < 0 ||
                students[count].marks[i] > 100) {
                printf("Enter marks between 0 and 100.\n");
            }
        } while (students[count].marks[i] < 0 ||
                 students[count].marks[i] > 100);
    }

    calculateAverage(&students[count]);

    count++;

    printf("Student added successfully!\n");
}

// Sort students by average marks
void sortStudents() {
    struct Student temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {

            if (students[j].average < students[j + 1].average) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    // Assign competition ranks (1, 2, 2, 4)
    for (int i = 0; i < count; i++) {
        if (i == 0) {
            students[i].rank = 1;
        }
        else if (students[i].average ==
                 students[i - 1].average) {
            students[i].rank = students[i - 1].rank;
        }
        else {
            students[i].rank = i + 1;
        }
    }
}

// Display rankings
void displayRanking() {
    if (count == 0) {
        printf("No student records available!\n");
        return;
    }

    sortStudents();

    printf("\n========== STUDENT RANKING ==========\n");

    printf("%-8s %-20s %-10s %-10s %-8s\n",
           "Rank", "Name", "ID", "Average", "Total");

    for (int i = 0; i < count; i++) {
        printf("%-8d %-20s %-10d %-10.2f %-8.2f\n",
               students[i].rank,
               students[i].name,
               students[i].id,
               students[i].average,
               students[i].total);
    }
}

// Search student by ID
void searchStudent() {
    int id, found = 0;

    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("\nStudent Found!\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Total Marks: %.2f\n", students[i].total);
            printf("Average: %.2f\n", students[i].average);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }
}

// Performance summary
void performanceSummary() {
    int id, found = 0;

    printf("Enter Student ID: ");
    scanf("%d", &id);

    sortStudents();

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("\n====== PERFORMANCE SUMMARY ======\n");

            printf("Name: %s\n", students[i].name);
            printf("Student ID: %d\n", students[i].id);
            printf("Total Marks: %.2f\n", students[i].total);
            printf("Average Marks: %.2f\n", students[i].average);
            printf("Class Rank: %d\n", students[i].rank);

            if (students[i].average >= 90)
                printf("Grade: A+\n");
            else if (students[i].average >= 80)
                printf("Grade: A\n");
            else if (students[i].average >= 70)
                printf("Grade: B\n");
            else if (students[i].average >= 60)
                printf("Grade: C\n");
            else if (students[i].average >= 40)
                printf("Grade: D\n");
            else
                printf("Grade: F\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }
}

// Main function
int main() {
    int choice;

    do {
        printf("\n========== STUDENT RANKING ENGINE ==========\n");
        printf("1. Add Student\n");
        printf("2. Display Student Rankings\n");
        printf("3. Search Student by ID\n");
        printf("4. Performance Summary\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayRanking();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                performanceSummary();
                break;

            case 5:
                printf("Exiting Student Ranking Engine...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
