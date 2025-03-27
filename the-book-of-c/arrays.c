
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void array_setting_and_printing(void) {
    int scores[100];
    memset(scores, 0, sizeof(scores));

    for (int i = 0; i < 100; i++) {
        printf("%d\n", i);
    }
}

int *set_scores(int *num_scores) {
    printf("How many scores to input? ");

    //Is buffer a pointer?
    //Yes, an array like char buffer[10]; decays into a pointer to the first element of the array when used in expressions.
    //buffer itself refers to the memory address of the first element (&buffer[0]).
    //When you pass buffer to a function (e.g., fgets(buffer, 10, stdin);), it passes the address of the first element, which is a pointer.
    char buffer[10];
    fgets(buffer, sizeof(buffer), stdin);

    // If chars are passed to atoi it returns 0 and terminates.
    *num_scores = atoi(buffer);

    if (*num_scores <= 0) {
        printf("Invalid number scores.\n");
        exit(EXIT_FAILURE);
    }

    // Malloc returns a generic pointer (void *) while allocating memory.
    // So scores now is a pointer to a memory address.
    int *scores = malloc(*num_scores * sizeof(int));

    for (int i = 0; i < *num_scores; i++) {
        printf("Enter score %d: ", i + 1);
        fgets(buffer, 10, stdin);
        scores[i] = atoi(buffer);
    }

    return scores;
}

void score_printing(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d: %d\n", i + 1, arr[i]);
    }
}

int main(void) {
    // This is them amount of scores the score array will hold.
    int num_scores;
    // Here dereferencing is giving the function access to num_scores locations in memory.
    int *scores = set_scores(&num_scores);

    // Perform an operation with the data associated to the pointer.
    score_printing(scores, num_scores);
    // Freeing the location in memory.
    free(scores);

    return EXIT_SUCCESS;
}
