#include <stdio.h>
#include <stdlib.h>

#define PAYRATE 12.00
#define TAXRATE_300 .15
#define TAXRATE_150 .20
#define TAXRATE_REST .25
#define OVERTIME 40

int main()
{
    // declare variables
    int hours = 0;
    double weeklyPay = 0.0;
    double grossPay = 0.0;
    double taxes = 0.0;
    double netPay = 0.0;

    printf("Enter the number of hours worked this week: \n");
    scanf("%d", &hours);

    // calculate weekly pay
    if (hours <= 40)
        weeklyPay = hours * PAYRATE;
    else 
    {
        weeklyPay = 40 * PAYRATE;
        double overTimePay = (hours - 40) * (PAYRATE * 1.5);
        weeklyPay += overTimePay;
    }

    // calculate taxes
    if (weeklyPay <= 300)
        {
            taxes = weeklyPay * TAXRATE_300;
        }
    else if (weeklyPay >= 300 && weeklyPay <= 450)
        {
            taxes = 300 * TAXRATE_300;
            taxes += (weeklyPay - 300) * TAXRATE_150;
        }
    else
        {
            taxes = 300 * TAXRATE_300;
            taxes += 150 * TAXRATE_150;
            taxes += (weeklyPay - 450) * TAXRATE_REST;
        }

    // calculate gross pay

    grossPay = weeklyPay - taxes;

    //display output

    printf("Your total earned this week is: %.2f\n", weeklyPay);
    printf("Your gross taxes this week is: %.2f\n", taxes);
    printf("Your net pay this week is: %.2f\n", grossPay);

    return 0;
}