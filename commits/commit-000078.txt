/*
 * Program 78: Array of Structures
 * Topic: Multi-entity Data Management
 */
#include <stdio.h>

typedef struct {
    int id;
    char name[30];
    double salary;
} Employee;

int main(void) {
    Employee team[2] = {
        {1, "Bob", 65000.0},
        {2, "Charlie", 72000.0}
    };

    for (int i = 0; i < 2; i++) {
        printf("Emp #%d: %s, Salary: $%.2f\n", team[i].id, team[i].name, team[i].salary);
    }
    return 0;
}
