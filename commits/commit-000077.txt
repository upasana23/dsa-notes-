/*
 * Program 77: Student Record Using struct
 * Topic: User-Defined Data Types
 */
#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

int main(void) {
    Student s1 = {101, "Alice Smith", 3.85f};
    printf("ID: %d\nName: %s\nGPA: %.2f\n", s1.id, s1.name, s1.gpa);
    return 0;
}
