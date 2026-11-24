#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int candidates, voters, v, i, winner = 0;
    int *votes = NULL;
    printf("Enter number of candidates: ");
    scanf("%d", &candidates);
    printf("Enter number of voters: ");
    scanf("%d", &voters);
    votes = calloc(candidates, sizeof(int));
    if (votes == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Initial vote counts:");
    for (i = 0; i < candidates; i++)
        printf(" %d", votes[i]);
    printf("\n");
    printf("Enter %d votes (1-%d): ", voters, candidates);
    for (i = 0; i < voters; i++) {
        scanf("%d", &v);
        if (v >= 1 && v <= candidates)
            votes[v - 1]++;
    }
    printf("\n-- - - - --Election Result--  -- - - \n");
    for (i = 0; i < candidates; i++) {
        printf("Candidate %d: %d vote(s)\n", i + 1, votes[i]);
        if (votes[i] > votes[winner])
            winner = i;
    }
    printf("Winner: Candidate %d\n", winner + 1);
    free(votes);
    votes = NULL;
    return 0;
}
