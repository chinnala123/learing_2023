#include <stdio.h>

void findSmallestLargestDigits(int n, int numbers[]) {
    int smallestDigit = 9;
    int largestDigit = 0;
    int isValid = 1;

    for (int i = 0; i < n; i++) {
        int num = numbers[i];

        if (num < 0) {
            isValid = 0;
            break;
        }

        while (num != 0) {
            int digit = num % 10;
            num /= 10;

            smallestDigit = (digit < smallestDigit) ? digit : smallestDigit;
            largestDigit = (digit > largestDigit) ? digit : largestDigit;
        }
    }

    if (!isValid) {
        printf("Not Valid\n");
    } else {
        printf("Smallest Digit: %d\n", smallestDigit);
        printf("Largest Digit: %d\n", largestDigit);
    }
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    int numbers[n];

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    findSmallestLargestDigits(n, numbers);

    return 0;
}
