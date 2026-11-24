#include <stdio.h>
#include <stdlib.h>
struct Employee {
    int   id;
    char  name[31];
    float salary;
};
int main(void)
{
    int n, i, best = 0;
    double total = 0.0;
    struct Employee *emp = NULL;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Number of employees must be at least 1.\n");
        return 1;
    }
    emp = malloc(n * sizeof(struct Employee));
    if (emp == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("Enter ID, Name, Salary of employee %d: ", i + 1);
        scanf("%d %30s %f", &emp[i].id, emp[i].name, &emp[i].salary);
        total += emp[i].salary;
        if (emp[i].salary > emp[best].salary)
            best = i;
    }
    printf("--- Employee List ---\n");
    for (i = 0; i < n; i++)
        printf("%d %s Rs.%.2f\n", emp[i].id, emp[i].name, emp[i].salary);
    printf("\nTotal payroll: Rs.%.2f\n", total);
    printf("Highest salary: %s (Rs.%.2f)\n", emp[best].name, emp[best].salary);
    free(emp);
    emp = NULL;
    return 0;
}
