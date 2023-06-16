#include <stdio.h>

int findLargestNumber(int num) {
    int largest = 0;
    int temp = num;
    int divisor = 1;

    for (int i = 0; i < 4; i++) {
        int digit = temp % 10;
        temp /= 10;

        int newNumber = (num / (divisor * 10)) * divisor + temp;
        if (newNumber > largest) {
            largest = newNumber;
        }

        divisor *= 10;
        temp = num;
    }

    return largest;
}

int main() {
    int num;

    printf("Enter a 4-digit number: ");
    scanf("%d", &num);

    int largestNumber = findLargestNumber(num);
    printf("Largest number by deleting a single digit: %d\n", largestNumber);

    return 0;
}
