#include <stdio.h>
#include <string.h> 

struct Student {
    char name[50];
    int roll_number;
    char address[100];
};

int main() {
    struct Student student1;

    strcpy(student1.name, "Samarth");  
    student1.roll_number = 101;
    strcpy(student1.address, "123 Main St, Springfield, IL");

    printf("Student Name: %s\n", student1.name);
    printf("Roll Number: %d\n", student1.roll_number);
    printf("Address: %s\n", student1.address);

    return 0;
}
