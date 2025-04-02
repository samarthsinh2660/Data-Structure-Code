#include <stdio.h>

struct Student {
    char name[50];
    int rollNumber;
    char address[100];
};

int main() {
    struct Student s1;

    // Assign values
    printf("Enter student name: ");
    scanf("%s", s1.name);

    printf("Enter roll number: ");
    scanf("%d", &s1.rollNumber);

    printf("Enter address: ");
    scanf(" %[^\n]", s1.address);  // For reading strings with spaces

    // Print values
    printf("\nStudent Information:\n");
    printf("Name: %s\n", s1.name);
    printf("Roll Number: %d\n", s1.rollNumber);
    printf("Address: %s\n", s1.address);

    return 0;
}
