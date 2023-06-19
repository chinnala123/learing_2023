#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[100];
    long number;
    char *endptr;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    number = strtol(str, &endptr, 10);

    if (str == endptr) {
        printf("Invalid input.\n");
    } else {
        printf("Converted integer: %ld\n", number);
    }

    return 0;
}
