#include <stdio.h>

#define MAX 100

int main() {
    int n, scores[MAX];
    int freq[101] = {0}; // assuming scores 0–100
    int i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input scores
    for (i = 0; i < n; i++) {
        printf("Enter score of student %d: ", i + 1);
        scanf("%d", &scores[i]);

        if (scores[i] >= 0 && scores[i] <= 100)
            freq[scores[i]]++;
        else
            printf("Invalid score (ignored in frequency)\n");
    }

    // Initialize
    int sum = 0, max = scores[0], min = scores[0];

    // Calculate sum, max, min
    for (i = 0; i < n; i++) {
        sum += scores[i];

        if (scores[i] > max)
            max = scores[i];

        if (scores[i] < min)
            min = scores[i];
    }

    float avg = (float)sum / n;

    // Find mode
    int mode = -1, maxFreq = 0;
    for (i = 0; i <= 100; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            mode = i;
        }
    }

    // Output
    printf("\nAverage Score = %.2f\n", avg);
    printf("Highest Score = %d\n", max);
    printf("Lowest Score = %d\n", min);

    printf("\nFrequency of Scores:\n");
    for (i = 0; i <= 100; i++) {
        if (freq[i] > 0)
            printf("%d -> %d times\n", i, freq[i]);
    }

    if (mode != -1)
        printf("\nMost Frequent Score (Mode) = %d (%d times)\n", mode, maxFreq);
    else
        printf("\nNo valid mode\n");

    return 0;
}
