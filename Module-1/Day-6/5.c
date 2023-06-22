#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char grade;
} Student;

void searchStudentsByName(Student students[], int numStudents, const char* name) {
    int i;
    for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Name: %s, Age: %d, Grade: %c\n", students[i].name, students[i].age, students[i].grade);
        }
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    Student* students = (Student*)malloc(numStudents * sizeof(Student));

    int i;
    for (i = 0; i < numStudents; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter the age of student %d: ", i + 1);
        scanf("%d", &students[i].age);

        printf("Enter the grade of student %d: ", i + 1);
        scanf(" %c", &students[i].grade);
    }

    char searchName[MAX_NAME_LENGTH];
    printf("Enter the name to search for: ");
    scanf("%s", searchName);

    searchStudentsByName(students, numStudents, searchName);

    free(students);

    return 0;
}

