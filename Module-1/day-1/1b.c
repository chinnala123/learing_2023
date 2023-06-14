#include <stdio.h>

int greatest_number(int a, int b) {
    int biggest = (a > b) ? a : b;
    return biggest;
}

int main() {
    int num1, num2;
    
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    int result = greatest_number(num1, num2);
    printf("The biggest number is: %d\n", result);
    
    return 0;
}
