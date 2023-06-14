#include<stdio.h>
int main()
{
    int input;
    scanf("%d",&input);
    if(input>=90 && input<=100){
        printf("grade A");
    }
    else if(input>=75 && input<=89)
    {
        printf("Grade B");
    }
    else if(input>=60 && input>=74)
    {
        printf("Grade C");
    }
    else if(input>=50 && input<=59)
    {
        printf("Grade D");
    }
    else
    {
        printf("Grade F");
    }
    
}