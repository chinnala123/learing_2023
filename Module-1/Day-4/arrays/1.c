#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array; 
    int size;
    int sum = 0;
    float average;
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
        sum += array[i];
    }
    average = 0.0;
    for (int i = 0; i < size; i++) {
        average += array[i];
    }
    average /= size;

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    free(array);
    return 0;
}
