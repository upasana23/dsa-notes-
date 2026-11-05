
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Appointment {
    int id;
    char name[50];
    char date[15];
    int startTime;
    int endTime;
};

struct Appointment appointments[MAX];
int count = 0;

// Convert HH:MM into minutes
int convertToMinutes(int hour, int minute) {
    return hour * 60 + minute;
}

// Input time
int inputTime() {
    int hour, minute;

    printf("Enter hour (0-23): ");
    scanf("%d", &hour);

    printf("Enter minute (0-59): ");
    scanf("%d", &minute);

    if (hour < 0 || hour > 23 ||
        minute < 0 || minute > 59) {
        return -1;
    }

    return convertToMinutes(hour, minute);
}

// Display time
void displayTime(int time) {
    printf("%02d:%02d", time / 60, time % 60);
}

// Add appointment
void addAppointment() {
    if (count >= MAX) {
        printf("Appointment list is full!\n");
        return;
    }

    int id;

    printf("Enter Appointment ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (appointments[i].id == id) {
            printf("Appointment ID already exists!\n");
            return;
        }
    }

    appointments[count].id = id;

    printf("Enter Person Name: ");
    scanf(" %49[^\n]", appointments[count].name);

    printf("Enter Date (DD-MM-YYYY): ");
    scanf("%14s", appointments[count].date);

    printf("\nEnter Start Time:\n");
    appointments[count].startTime = inputTime();

    if (appointments[count].startTime == -1) {
        printf("Invalid start time!\n");
        return;
    }

    printf("\nEnter End Time:\n");
    appointments[count].endTime = inputTime();

    if (appointments[count].endTime == -1 ||
        appointments[count].endTime <=
        appointments[count].startTime) {
        printf("Invalid end time!\n");
        return;
    }

    count++;

    printf("Appointment added successfully!\n");
}

// Sort appointments by date and start time
void sortAppointments() {
    struct Appointment temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {

            int comparison =
                strcmp(appointments[j].date,
                       appointments[j + 1].date);

            if (comparison > 0 ||
                (comparison == 0 &&
                 appointments[j].startTime >
                 appointments[j + 1].startTime)) {

                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
        }
    }
}

// Display appointments
void displayAppointments() {
    if (count == 0) {
        printf("No appointments available!\n");
        return;
    }

    sortAppointments();

    printf("\n========== APPOINTMENT LIST ==========\n");

    for (int i = 0; i < count; i++) {
        printf("\nAppointment ID: %d\n",
               appointments[i].id);

        printf("Name: %s\n", appointments[i].name);

        printf("Date: %s\n", appointments[i].date);

        printf("Start Time: ");
        displayTime(appointments[i].startTime);

        printf("\nEnd Time: ");
        displayTime(appointments[i].endTime);

        printf("\n");
    }
}

// Detect overlapping appointments
void detectConflicts() {
    int found = 0;

    sortAppointments();

    printf("\n========== SCHEDULING CONFLICTS ==========\n");

    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {

            if (strcmp(appointments[i].date,
                       appointments[j].date) == 0) {

                if (appointments[i].startTime <
                    appointments[j].endTime &&
                    appointments[j].startTime <
                    appointments[i].endTime) {

                    printf("\nConflict Detected!\n");

                    printf("%s (ID: %d) overlaps with %s (ID: %d)\n",
                           appointments[i].name,
                           appointments[i].id,
                           appointments[j].name,
                           appointments[j].id);

                    found = 1;
                }
            }
        }
    }

    if (!found) {
        printf("No scheduling conflicts found!\n");
    }
}

// Search appointment by ID
void searchAppointment() {
    int id, found = 0;

    printf("Enter Appointment ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (appointments[i].id == id) {

            printf("\nAppointment Found!\n");

            printf("ID: %d\n", appointments[i].id);
            printf("Name: %s\n", appointments[i].name);
            printf("Date: %s\n", appointments[i].date);

            printf("Start Time: ");
            displayTime(appointments[i].startTime);

            printf("\nEnd Time: ");
            displayTime(appointments[i].endTime);

            printf("\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Appointment not found!\n");
    }
}

// Main function
int main() {
    int choice;

    do {
        printf("\n========== APPOINTMENT SLOT MANAGER ==========\n");

        printf("1. Add Appointment\n");
        printf("2. Display Appointments\n");
        printf("3. Detect Scheduling Conflicts\n");
        printf("4. Search Appointment by ID\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment();
                break;

            case 2:
                displayAppointments();
                break;

            case 3:
                detectConflicts();
                break;

            case 4:
                searchAppointment();
                break;

            case 5:
                printf("Exiting Appointment Manager...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
