#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){

    char choice[10];
    float loan,rate,monthly_rate,salary,new_emi;
    int year,month;

    printf("Enter loan amount:");
    scanf("%f",&loan);
    printf("Enter interest rate:");
    scanf("%f",&rate);
    printf("Enter loan tenure(yrs):");
    scanf("%d",&year);

    month = year*12;
    monthly_rate = rate/(12*100);

    float emi = (loan * monthly_rate * pow(1 + monthly_rate, month))/ (pow(1 + monthly_rate, month) - 1);

    printf("Enter your salary:");
    scanf("%f",&salary);

    printf("Any existing EMI(yes or no):");
    scanf("%s",choice);

    if(strcmpi(choice,"yes")==0){
        printf("Enter EMI amount per month:\n\n\n");
        scanf("%f",&new_emi);
    }
    else{
        new_emi=0;
        printf("no existing emi!!!\n\n\n");
    }

    float h_salary = salary-(salary/2);
    float net_salary = h_salary-new_emi;

    printf("-----EMI details------");
    printf("\nloan amount: %.2f",loan);
    printf("\nannual rate: %.2f",rate);
    printf("\nloan time(yrs): %d",year);
    printf("\nyou monthly EMI : %.2f",emi);

    if(net_salary>emi){
        printf("\n\nyour loan has been approved.");
    }
    else{
        printf("\n\nyour loan has been rejected due to our terms and policies. ");
    }


 return 0;
}