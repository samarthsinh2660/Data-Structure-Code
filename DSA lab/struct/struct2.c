#include <stdio.h>

struct Student {
    char name[50];
    int rollNumber;
    char address[100];
};

int main() {
    struct Student students[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter details for student %d\n", i + 1);

        printf("Enter student name: ");
        scanf("%s", students[i].name);

        printf("Enter roll number: ");
        scanf("%d", &students[i].rollNumber);

        printf("Enter address: ");
        scanf(" %[^\n]", students[i].address);
    }

    printf("\nStudent Information:\n");
    for (int i = 0; i < 5; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Address: %s\n", students[i].address);
        printf("\n");
    }

    return 0;
}
