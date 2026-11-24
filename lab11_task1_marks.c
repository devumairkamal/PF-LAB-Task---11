#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n, i, sum = 0, high, low;
    int *marks = NULL;
    printf("Enter number of students: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Number of students must be at least 1.\n");
        return 1;
    }
    marks = malloc(n * sizeof(int));
    if (marks == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter %d marks: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &marks[i]);
        sum += marks[i];
    }
    high = low = marks[0];
    for (i = 1; i < n; i++) {
        if (marks[i] > high) high = marks[i];
        if (marks[i] < low)  low = marks[i];
    }
    printf("\n-- --  -- Result Summary-- -- - - \n");
    printf("Average marks: %.2f\n", (double)sum / n);
    printf("Highest marks: %d\n", high);
    printf("Lowest marks: %d\n", low);
    free(marks);
    marks = NULL;
    return 0;
}
