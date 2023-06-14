#include<stdio.h>
int main()
{
    float num1,num2;
    scanf("%f %f",&num1,&num2);
    if(num1>num2)
    {
        printf("num1 is greater %f",num1);
    }
    else
    {
        printf("num2 is greater %f",num2);
    }
return 0;
}