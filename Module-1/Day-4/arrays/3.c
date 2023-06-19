#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array; 
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);
    array = (int *)malloc(size * sizeof(int));

    if (array == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    for (int i = 0; i < size / 2; i++) {
        int temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }

    printf("\nReversed Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    free(array);

    return 0;
}
