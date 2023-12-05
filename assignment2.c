#include <stdio.h>
#include <stdlib.h>

#define SWAP(A, B) \
    A ^= B ^= A ^= B;

float averageOfArray(int* array, int length);
void countLessAndGreater(int* array, int length, float average);
void printArray(int* array, int length);
void moveEvenLeft(int* array, int length);
void moveOddLeft(int* array, int length);

int main() {
    unsigned int N;
    do {
        printf("Enter length of array (Nmax = 50): ");
        scanf("%u", &N);
    } while (N > 50);

    int* array = (int*)malloc(N * sizeof(int));

    int i;
    /**
     * @brief Enter element one by one
     *
     */
    for (i = 0; i < N; i++) {
        printf("arr[%d]=", i);
        scanf("%d", array + i);
    }

    /**
     * @brief Enter the whole array (with space delim)
     *
     */
    // for (i = 0; i < N; i++) {
    //     if (!scanf("%d", array + i)) {
    //         printf("Element in %d of array fail !!!\n", i);
    //     }
    // }

    printf("Input array:\n");
    printArray(array, N);
    printf("\n");

    float average = averageOfArray(array, N);
    printf("Average of array: %f\n", average);
    countLessAndGreater(array, N, average);

    printf("\n");
    printf("Before call:\n");
    printArray(array, N);
    printf("After call:\n");
    // moveEvenLeft(array, N);
    moveOddLeft(array, N);
    printArray(array, N);

    return 0;
}

// using for to calcute average, return average value
float averageOfArray(int* array, int length) {
    int i;
    float sum = 0;
    for (i = 0; i < length; i++) {
        sum += array[i];
    }
    sum = sum / length;
    return sum;
}

// using for loop to count less and greater value than average
void countLessAndGreater(int* array, int length, float average) {
    int i;
    int countLess = 0;
    int countGreater = 0;
    for (i = 0; i < length; i++) {
        if (array[i] > average) {
            countGreater += 1;
        }
        if (array[i] < average) {
            countLess += 1;
        }
    }
    printf("Less than average count: %d\n", countLess);
    printf("Greater than average count: %d\n", countGreater);
}

// using for to print whole array
void printArray(int* array, int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// move all even value to left
void moveEvenLeft(int* array, int length) {
    int i;
    int trace = 0;
    for (i = 0; i < length; i++) {
        if (array[i] % 2 == 0) {
            SWAP(array[trace], array[i]);
            trace += 1;
        }
    }
}

// move all odd value to left
void moveOddLeft(int* array, int length) {
    int i;
    int trace = 0;
    for (i = 0; i < length; i++) {
        if (array[i] % 2 != 0) {
            SWAP(array[trace], array[i]);
            trace += 1;
        }
    }
}
