#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int marks;
};

void sort_structures_by_marks(struct Student* structures, int size) {
    int i, j;
    struct Student temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (structures[j].marks < structures[j + 1].marks) {
                temp = structures[j];
                structures[j] = structures[j + 1];
                structures[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);

    struct Student* structures = malloc(size * sizeof(struct Student));
    if (structures == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", structures[i].name);
        printf("Enter the marks of student %d: ", i + 1);
        scanf("%d", &structures[i].marks);
    }

    sort_structures_by_marks(structures, size);

    printf("\nSorted by marks (descending order):\n");
    for (int i = 0; i < size; i++) {
        printf("Name: %s, Marks: %d\n", structures[i].name, structures[i].marks);
    }

    free(structures);

    return 0;
}
