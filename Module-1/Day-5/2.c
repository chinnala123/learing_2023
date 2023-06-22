#include <stdio.h>
#include <stdlib.h>

struct Complex {
    double real;
    double imag;
};

struct Complex* readComplex() {
    struct Complex* complexNum = (struct Complex*)malloc(sizeof(struct Complex));
    
    printf("Enter real part: ");
    scanf("%lf", &(complexNum->real));
    
    printf("Enter imaginary part: ");
    scanf("%lf", &(complexNum->imag));
    
    return complexNum;
}

void writeComplex(struct Complex* complexNum) {
    printf("Complex number: %.2f + %.2fi\n", complexNum->real, complexNum->imag);
}

struct Complex* addComplex(struct Complex* num1, struct Complex* num2) {
    struct Complex* result = (struct Complex*)malloc(sizeof(struct Complex));
    
    result->real = num1->real + num2->real;
    result->imag = num1->imag + num2->imag;
    
    return result;
}

struct Complex* multiplyComplex(struct Complex* num1, struct Complex* num2) {
    struct Complex* result = (struct Complex*)malloc(sizeof(struct Complex));
    
    result->real = num1->real * num2->real - num1->imag * num2->imag;
    result->imag = num1->real * num2->imag + num1->imag * num2->real;
    
    return result;
}

int main() {
    struct Complex* complex1 = readComplex();
    struct Complex* complex2 = readComplex();
    
    printf("Complex numbers entered:\n");
    writeComplex(complex1);
    writeComplex(complex2);
    
    struct Complex* sum = addComplex(complex1, complex2);
    struct Complex* product = multiplyComplex(complex1, complex2);
    
    printf("Sum of the complex numbers:\n");
    writeComplex(sum);
    
    printf("Product of the complex numbers:\n");
    writeComplex(product);
    free(complex1);
    free(complex2);
    free(sum);
    free(product);
    
    return 0;
}
