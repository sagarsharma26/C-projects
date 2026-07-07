#include <stdio.h>
#include <string.h>
#include <math.h>

float rate = 7.0;

void emi(float price);

int main() {

    char car[20];

    printf("Available Cars:\n");
    printf("Thar\nBaleno\nSwift\nWagonR\n");

    printf("\nEnter car name: ");
    scanf("%s", car);

    if (strcmp(car, "Thar") == 0)
        emi(500000);

    else if (strcmp(car, "Baleno") == 0)
        emi(800000);

    else if (strcmp(car, "Swift") == 0)
        emi(900000);

    else if (strcmp(car, "WagonR") == 0)
        emi(300000);

    else
        printf("Car not available.\n");

    return 0;
}

void emi(float price)
{
    float dp, loan, emi, monthly_int;
    int years, months;

    printf("\nCar Price : Rs. %.2f\n", price);

    printf("Enter Down Payment: ");
    scanf("%f", &dp);

    if (dp > price) {
        printf("Invalid Down Payment!\n");
        return;
    }

    printf("Enter Loan Tenure (Years): ");
    scanf("%d", &years);

    loan = price - dp;
    months = years * 12;
    monthly_int = rate / (12 * 100);

    emi = (loan * monthly_int * pow(1 + monthly_int, months))
        / (pow(1 + monthly_int, months) - 1);

    printf("\nLoan Amount     : %.2f\n", loan);
    printf("Interest Rate   : %.2f%%\n", rate);
    printf("Monthly EMI     : %.2f\n", emi);
    printf("Total Payment   : %.2f\n", emi * months);
    printf("Total Interest  : %.2f\n", (emi * months) - loan);
}