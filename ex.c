#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numbers = NULL;  // Pointer to store dynamically allocated memory
    int input, count = 0;
    printf("Enter integers (enter any non-integer to stop): ");

    while (scanf("%d", &input) == 1) {
        count++;  // Increment count for each valid integer input

        // Reallocate memory for 'numbers' array to store the new input
        int *temp = realloc(numbers, count * sizeof(int));
        if (temp == NULL) {
            // Handle memory allocation failure
            printf("Memory allocation failed!\n");
            free(numbers);  // Free previously allocated memory
            return 1;
        }
        numbers = temp;
        numbers[count - 1] = input;  // Store input in the array
    }

    printf("Entered integers: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    free(numbers);  // Free allocated memory

    return 0;
}
