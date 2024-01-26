// Name: Nayan
// Question: 5.9 Parking Charges

#include <stdio.h>

double inputHours(int carNumber);
double calculateCharges(double hours);

int main(void)
{
    double hours[3], charges[3], totalHours = 0.0, totalCharges = 0.0;

    for (int i = 0; i < 3; i++) {
        hours[i] = inputHours(i + 1);
        charges[i] = calculateCharges(hours[i]);
        totalHours += hours[i];
        totalCharges += charges[i];
    }

    printf("%-10s%-10s%-10s\n", "Car", "Hours", "Charge");
    for (int i = 0; i < 3; i++) {
        printf("%-10d%-10.1f%-10.2f\n", i + 1, hours[i], charges[i]);
    }
    printf("%-10s%-10.1f%-10.2f\n", "TOTAL", totalHours, totalCharges);

    return 0;
}

double inputHours(int carNumber)
{
    double hours;
    
    printf("Enter hours parked for car %d: ", carNumber);
    scanf("%lf", &hours);
    
    return hours;
}

double calculateCharges(double hours)
{
    double charges = 0.0;

    if (hours <= 3)
    {
        charges = 2.0;
    }
    else if (hours > 3 && hours < 24)
    {
        charges = 2.0 + (hours - 3) * 0.5;
    }
    else
    {
        charges = 10.0;
    }

    return charges;
}