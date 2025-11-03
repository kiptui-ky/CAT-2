/*
Name: Kiptui Kipyator 
Reg No: PA106/G/28740/25
Date: 3rd November 2025
*/

#include <stdio.h>


#define STANDARD_HOURS 40.0
#define OVERTIME_RATE 1.5
#define TAX_THRESHOLD 600.0
#define TAX_RATE_LOW 0.15 
#define TAX_RATE_HIGH 0.20 


double calculate_tax(double gross_pay) {
    double tax = 0.0;
    
    if (gross_pay <= TAX_THRESHOLD) {
        
        tax = gross_pay * TAX_RATE_LOW;
    } else {
    
        tax = TAX_THRESHOLD * TAX_RATE_LOW;
        
        
        double taxable_rest = gross_pay - TAX_THRESHOLD;
        tax += taxable_rest * TAX_RATE_HIGH;
    }
    
    return tax;
}

int main() {
    double hours_worked;
    double hourly_wage;
    double gross_pay;
    double tax_amount;
    double net_pay;
    double normal_pay;
    double overtime_pay = 0.0;
    double overtime_hours = 0.0;

    
    printf("--- Payroll Calculator ---\n");
    printf("Enter the hours worked in a week: ");
    if (scanf("%lf", &hours_worked) != 1 || hours_worked < 0) {
        printf("Invalid input for hours worked. Please run again.\n");
        return 1;
    }
    
    printf("Enter the hourly wage ($): ");
    if (scanf("%lf", &hourly_wage) != 1 || hourly_wage < 0) {
        printf("Invalid input for hourly wage. Please run again.\n");
        return 1;
    }

    
    if (hours_worked > STANDARD_HOURS) {
        normal_pay = STANDARD_HOURS * hourly_wage;
        overtime_hours = hours_worked - STANDARD_HOURS;
        
        
        overtime_pay = overtime_hours * hourly_wage * OVERTIME_RATE;
        
        gross_pay = normal_pay + overtime_pay;
    } else {
        
        normal_pay = hours_worked * hourly_wage;
        gross_pay = normal_pay;
    }

    
    tax_amount = calculate_tax(gross_pay);
    
    
    net_pay = gross_pay - tax_amount;

    
    printf("\n--- Weekly Pay Details ---\n");
    printf("Hours Worked: %.2lf\n", hours_worked);
    printf("Hourly Wage: $%.2lf\n", hourly_wage);
    printf("Overtime Hours: %.2lf\n", overtime_hours);
    
    printf("--------------------------\n");
    printf("**1. Gross Pay:** $%.2lf\n", gross_pay);
    printf("**2. Taxes (%.0f%%/%.0f%%):** $%.2lf\n", TAX_RATE_LOW * 100, TAX_RATE_HIGH * 100, tax_amount);
    printf("**3. Net Pay:** $%.2lf\n", net_pay);
    printf("--------------------------\n");

    return 0;
}
