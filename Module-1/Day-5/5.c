#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int age;
    float marks;
};

void swapFields(struct Student* student1, struct Student* student2) {
    struct Student temp;
    strcpy(temp.name, student1->name);
    strcpy(student1->name, student2->name);
    strcpy(student2->name, temp.name);
    temp.age = student1->age;
    student1->age = student2->age;
    student2->age = temp.age;
    temp.marks = student1->marks;
    student1->marks = student2->marks;
    student2->marks = temp.marks;
}

int main() {
    struct Student* student1 = (struct Student*)malloc(sizeof(struct Student));
    struct Student* student2 = (struct Student*)malloc(sizeof(struct Student));
    printf("Enter details for student 1:\n");
    printf("Name: ");
    scanf("%s", student1->name);
    printf("Age: ");
    scanf("%d", &(student1->age));
    printf("Marks: ");
    scanf("%f", &(student1->marks));
    printf("\n");
    printf("Enter details for student 2:\n");
    printf("Name: ");
    scanf("%s", student2->name);
    printf("Age: ");
    scanf("%d", &(student2->age));
    printf("Marks: ");
    scanf("%f", &(student2->marks));
    printf("\n");

    printf("Before swapping:\n");
    printf("Student 1:\n");
    printf("Name: %s\n", student1->name);
    printf("Age: %d\n", student1->age);
    printf("Marks: %.2f\n\n", student1->marks);
    printf("Student 2:\n");
    printf("Name: %s\n", student2->name);
    printf("Age: %d\n", student2->age);
    printf("Marks: %.2f\n\n", student2->marks);

    swapFields(student1, student2);

    printf("After swapping:\n");
    printf("Student 1:\n");
    printf("Name: %s\n", student1->name);
    printf("Age: %d\n", student1->age);
    printf("Marks: %.2f\n\n", student1->marks);
    printf("Student 2:\n");
    printf("Name: %s\n", student2->name);
    printf("Age: %d\n", student2->age);
    printf("Marks: %.2f\n\n", student2->marks);

    free(student1);
    free(student2);

    return 0;
}
