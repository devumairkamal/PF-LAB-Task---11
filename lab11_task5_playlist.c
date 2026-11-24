#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n, del, i, total = 0, left_total = 0;
    int *playlist = NULL;
    printf("Enter number of songs: ");
    scanf("%d", &n);
    playlist = malloc(n * sizeof(int));
    if (playlist == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter duration (minutes) of %d songs: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &playlist[i]);
        total += playlist[i];
    }
    printf("Playlist:");
    for (i = 0; i < n; i++)
        printf(" %d", playlist[i]);
    printf(" (total %d minutes)\n", total);
    printf("Enter number of songs to remove from the end: ");
    scanf("%d", &del);
    if (del >= n) {
        printf("Cannot remove that many songs.\n");
    } else {
        n -= del;
        printf("Playlist after removing:");
        for (i = 0; i < n; i++) {
            printf(" %d", playlist[i]);
            left_total += playlist[i];
        }
        printf(" (total %d minutes)\n", left_total);
    }
    free(playlist);
    playlist = NULL;
    if (playlist == NULL)
        printf("Playlist deleted. Nothing left to play.\n");
    return 0;
}
