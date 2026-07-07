#include<stdio.h>

void add();
void sub();
void mul();
void divi();

int main(){

    int choice;

    printf("------CALCULATOR------\n\n");
    printf("1.ADDITION\n2.SUBTRACTION\n3.MULTIPLICATION\n4.DIVISION\n");
    printf("Enter your operator(+,-,*,/):");
    scanf("%d",&choice);


    switch(choice)
    {
        case 1:
            add();
            break;
        case 2:
            sub();
            break;
        case 3:
            mul();
            break;
        case 4:
            divi();
            break;
        default:
            printf("Invalid operator!!!");
    }

        
    return 0;

    
}

void add()
{
    int a,b,sum;

    printf("Enter your first number:");
    scanf("%d",&a);
    printf("Enter your second number:");
    scanf("%d",&b);

    sum = a + b;
    printf("Sum of two number is %d",sum);
}
void sub()
{
    int a,b,diff;

    printf("Enter your first number:");
    scanf("%d",&a);
    printf("Enter your second number:");
    scanf("%d",&b);

    diff = a - b;
    printf("Difference of two number is %d",diff);
}
void mul()
{
    int a,b,pro;

    printf("Enter your first number:");
    scanf("%d",&a);
    printf("Enter your second number:");
    scanf("%d",&b);

    pro = a * b;
    printf("Product of two number is %d",pro);

}
void divi()
{
    int a,b,div;

    printf("Enter your first number:");
    scanf("%d",&a);
    printf("Enter your second number:");
    scanf("%d",&b);

    div = a / b;
    printf("Divide of two number is %d",div);
}