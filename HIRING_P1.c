#include<stdio.h>
#include<string.h>

int main()
{
    char first[50],country[50],last[50];
    int age,exp;

    printf("Enter your first name :");
    scanf("%s",first);

    printf("Enter your last name:");
    scanf("%s",last);

    printf("Enter your country:");
    scanf("%s",country);

    printf("enter your age:");
    scanf("%d",&age);

    printf("Enter your experience:");
    scanf("%d",&exp);

    if(exp>(age-18)){
        printf("Invalid data! A person of age %d cannot have %d years experience.\n",age,exp);  // age validation
    }

    else if(strcmpi(country,"india")==0 && age>=18 && exp>=5)  //strcmpi use to check each letter of variable 
    {
        
        printf("\nName:%s %s",first,last);
        printf(" is selected");

    }
    
    else{
        printf("\nName:%s %s",first,last);
        printf(" is Rejected");
    }
    
}