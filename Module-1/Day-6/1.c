#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(char* input, struct Student* students, int n) {
    char* token = strtok(input, " "); 

    for (int i = 0; i < n; i++) {
        students[i].rollno = atoi(token); 

        token = strtok(NULL, " "); 
        strcpy(students[i].name, token); 

        token = strtok(NULL, " "); 
        students[i].marks = atof(token); 

        token = strtok(NULL, " "); 
    }
}

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);
    getchar();

    struct Student* students = (struct Student*)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the input string: ");
    char input[100];
    scanf("%[^\n]", input); 
    getchar(); 

    parseString(input, students, n);

    printf("\nStudent details:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    free(students);

    return 0;
}
