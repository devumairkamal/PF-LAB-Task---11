#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n, extra, i, total = 0;
    int *donations = NULL, *temp = NULL;
    printf("Enter number of donations: ");
    scanf("%d", &n);
    donations = malloc(n * sizeof(int));
    if (donations == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter %d donation amounts: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &donations[i]);
    printf("Enter number of additional donations: ");
    scanf("%d", &extra);
    temp = realloc(donations, (n + extra) * sizeof(int));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        free(donations);
        donations = NULL;
        return 1;
    }
    donations = temp;
    printf("Enter %d more amounts: ", extra);
    for (i = n; i < n + extra; i++)
        scanf("%d", &donations[i]);
    printf("\nAll donations:");
    for (i = 0; i < n + extra; i++) {
        printf(" %d", donations[i]);
        total += donations[i];
    }
    printf("\nTotal collected: %d\n", total);
    free(donations);
    donations = NULL;
    return 0;
}
