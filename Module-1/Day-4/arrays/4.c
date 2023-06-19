#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array; 
    int size;
    int evenSum = 0;
    int oddSum = 0;
    int diff;

    printf("Enter the size of the array: ");
    scanf("%d", &size);
    array = (int *)malloc(size * sizeof(int));

    if (array == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            evenSum += array[i];
        } else {
            oddSum += array[i];
        }
    }
    diff = evenSum - oddSum;

    printf("Sum of even numbers: %d\n", evenSum);
    printf("Sum of odd numbers: %d\n", oddSum);
    printf("Difference: %d\n", diff);
    free(array);

    return 0;
}
