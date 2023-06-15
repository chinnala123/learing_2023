#include <stdio.h>

int main() {
    double x;
    printf("Enter a double number: ");
    scanf("%lf", &x);

    unsigned long long *ptr = (unsigned long long*)&x;
    unsigned long long exponent = (*ptr >> 52) & 0x7FF;
    printf("Hexadecimal: 0x%llX\n", exponent);
    printf("Binary: 0b");
    for (int i = 11; i >= 0; i--) {
        printf("%d", (exponent >> i) & 1);
    }
    printf("\n");
    return 0;
}
