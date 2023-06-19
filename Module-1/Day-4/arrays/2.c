#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int size;
    int min, max;

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
    min = array[0];
    max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
        if (array[i] > max) {
            max = array[i];
        }
    }

    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    free(array);

    return 0;
}
