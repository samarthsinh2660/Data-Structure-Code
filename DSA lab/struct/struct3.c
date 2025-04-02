#include <stdio.h>

struct Org {
    char name[50];
    int orgID;

    struct Employee {
        int empID;
        float salary;
        char empName[50];
    } employees[2];
};

int main() {
    struct Org orgs[2];

    for (int i = 0; i < 2; i++) {
        printf("Enter details for organization %d\n", i + 1);

        printf("Enter organization name: ");
        scanf("%s", orgs[i].name);

        printf("Enter organization ID: ");
        scanf("%d", &orgs[i].orgID);

        for (int j = 0; j < 2; j++) {
            printf("Enter details for employee %d of organization %d\n", j + 1, i + 1);

            printf("Enter employee name: ");
            scanf("%s", orgs[i].employees[j].empName);

            printf("Enter employee ID: ");
            scanf("%d", &orgs[i].employees[j].empID);

            printf("Enter employee salary: ");
            scanf("%f", &orgs[i].employees[j].salary);
        }
    }

    printf("\nOrganization and Employee Details:\n");
    for (int i = 0; i < 2; i++) {
        printf("Organization %d: %s (ID: %d)\n", i + 1, orgs[i].name, orgs[i].orgID);

        for (int j = 0; j < 2; j++) {
            printf("Employee %d: %s (ID: %d, Salary: %.2f)\n", j + 1, orgs[i].employees[j].empName, orgs[i].employees[j].empID, orgs[i].employees[j].salary);
        }
        printf("\n");
    }

    return 0;
}
