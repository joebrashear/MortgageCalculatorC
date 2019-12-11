//
//  main.c
//  alltogether
//
//  Created by Mr Joseph on 11/30/19.
//  Copyright © 2019 Mr Joseph. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define N 100
void output_short_format(double loan_amount, double interest_rate, double term_years)
{
    double P,m_rate,months, totalamt,interestpaid;
    m_rate=(interest_rate/100)/12;
    months=term_years*12;
    // Output
    printf("---------------------------------\n");
    printf("\t\t   LOAN TERMS\n");
    printf("---------------------------------\n");
    printf("Loan Amount:%17.0lf\n", loan_amount);
    printf("Interest Rate:%14.02lf%%\n", interest_rate);
    printf("Term:%18.0lf years\n",term_years);
    printf("---------------------------------\n\n");
    P = (loan_amount * m_rate * pow((1+m_rate),months)) / ((pow((1+m_rate),months)) - 1 );
    totalamt = P*months;
    interestpaid = totalamt-loan_amount;
    
    printf("Monthly payment is: %13.02lf\n",P);
    printf("Total interest is: %14.02lf\n", interestpaid);
    printf("Total amount paid is: %11.02lf\n", totalamt);
    return;
}

void output_amortized(double loan_amount, double interest_rate, double term_years)
{
    // initialized vars
    double P,m_rate,months, monthinterest, monthprincipal,totalinterest=0, totalprincipal=0;
    m_rate=(interest_rate/100)/12;
    months=term_years*12;
    P = (loan_amount * m_rate * pow((1+m_rate),months)) / ((pow((1+m_rate),months)) - 1 );
    // The start of the tab
    printf("-----------------------------------------------------------------\n");
    printf("Year  Month  Interest  Principal  Balance  |  INTEREST  PRINCIPAL\n");
    printf("-----------------------------------------------------------------\n");
    printf("   1");
    // Main loop, prints the Year, months, interest, principal, balance, total interest paid, and total principal paid
    for (int i=1; i<=months;i++)
    {
        monthinterest = loan_amount * m_rate;
        totalinterest += monthinterest;
        monthprincipal = P - monthinterest;
        totalprincipal += monthprincipal;
        loan_amount -= monthprincipal;
        // Ensures that the tab doesn't missalign when the years become 2 digits
        if (i%12 == 0 && i != months && i<108){
            printf("\t %6d %9.0lf %10.0lf %8.0lf  | %9.0lf %10.0lf\n", i, monthinterest,monthprincipal,loan_amount,totalinterest,totalprincipal);
            printf("-----------------------------------------------------------------\n");
            printf("Year  Month  Interest  Principal  Balance  |  INTEREST  PRINCIPAL\n");
            printf("-----------------------------------------------------------------\n");
            monthinterest = loan_amount * m_rate;
            totalinterest += monthinterest;
            monthprincipal = P - monthinterest;
            totalprincipal += monthprincipal;
            loan_amount -= monthprincipal;
            // Extra iterations, due to the code shifting in spaces if not done
            i+=1;
            printf("   %d", (i/12)+1);
            printf("%7d %9.0lf %10.0lf %8.0lf  | %9.0lf %10.0lf\n", i, monthinterest,monthprincipal,loan_amount,totalinterest,totalprincipal);
            monthinterest = loan_amount * m_rate;
            totalinterest += monthinterest;
            monthprincipal = P - monthinterest;
            totalprincipal += monthprincipal;
            loan_amount -= monthprincipal;
            i+=1;
            
        }
        // Accounts for 2 digit years so it looks nice. Uneccessary for functionality, but necessary for aesthetics.
        if(i%12 == 0 && i != months && i>=108){
            printf("\t %6d %9.0lf %10.0lf %8.0lf  | %9.0lf %10.0lf\n", i, monthinterest,monthprincipal,loan_amount,totalinterest,totalprincipal);
            printf("-----------------------------------------------------------------\n");
            printf("Year  Month  Interest  Principal  Balance  |  INTEREST  PRINCIPAL\n");
            printf("-----------------------------------------------------------------\n");
            monthinterest = loan_amount * m_rate;
            totalinterest += monthinterest;
            monthprincipal = P - monthinterest;
            totalprincipal += monthprincipal;
            loan_amount -= monthprincipal;
            i+=1;
            printf("  %d", (i/12)+1);
            printf("%7d %9.0lf %10.0lf %8.0lf  | %9.0lf %10.0lf\n", i, monthinterest,monthprincipal,loan_amount,totalinterest,totalprincipal);
        }
        else if(i>1){
            printf("\t %6d %9.0lf %10.0lf %8.0lf  | %9.0lf %10.0lf\n", i, monthinterest,monthprincipal,loan_amount,totalinterest,totalprincipal);
        }
        else{
            printf(" %6d %9.0lf %10.0lf %8.0lf  | %9.0lf %10.0lf\n", i, monthinterest,monthprincipal,loan_amount,totalinterest,totalprincipal);
        }
    }
    return;
}

void output_extra_monthy(double loan_amount, double interest_rate, double term_years, double extra){
    double P,m_rate,months, monthinterest, monthprincipal, monthprincextra, totalprincipal=0, totalinterest=0;
    double monthinterest2, totalinterest2=0, monthprincipal2, totalprincipal2=0, L;
    L=loan_amount;
    m_rate=(interest_rate/100)/12;
    months=term_years*12;
    P = (loan_amount * m_rate * pow((1+m_rate),months)) / ((pow((1+m_rate),months)) - 1 );
    printf("------------------------------------------------------------------------\n");
    printf("Year  Month  Interest  Principal  Balance  |  INTEREST  PRINCIPAL  EXTRA\n");
    printf("------------------------------------------------------------------------\n");
    printf("   1");
    for (int j=1; j<=months;j++)
    {
        monthinterest2 = L * m_rate;
        totalinterest2 += monthinterest2;
        monthprincipal2 = P - monthinterest2;
        totalprincipal2 += monthprincipal2;
        L -= monthprincipal2;
    }
    for (int i=1; i<=months;i++)
    {
        monthinterest = loan_amount * m_rate;
        monthprincipal = P - monthinterest;
        monthprincextra = monthprincipal + extra;
        totalinterest += monthinterest;
        totalprincipal += monthprincextra;
        loan_amount -= monthprincextra;
        
        if (i%12 == 0 && i != months && i<108){
            printf("\t %6d %9.0lf %10.0lf %8.0lf  | %9.0lf %10.0lf %6.0lf\n", i, monthinterest,monthprincipal,loan_amount,totalinterest,totalprincipal,extra);
            printf("------------------------------------------------------------------------\n");
            printf("Year  Month  Interest  Principal  Balance  |  INTEREST  PRINCIPAL  EXTRA\n");
            printf("------------------------------------------------------------------------\n");
            monthinterest = loan_amount * m_rate;
            monthprincipal = P - monthinterest;
            monthprincextra = monthprincipal + extra;
            totalinterest += monthinterest;
            totalprincipal += monthprincextra;
            loan_amount -= monthprincextra;
            // Extra iterations, due to the code shifting in spaces if not done
            i+=1;
            printf("   %d", (i/12)+1);
            printf("%7d %9.0lf %10.0lf %8.0lf  | %9.0lf %10.0lf %6.0lf\n", i, monthinterest,monthprincipal,loan_amount,totalinterest,totalprincipal,extra);
            i+=1;
            monthinterest = loan_amount * m_rate;
            monthprincipal = P - monthinterest;
            monthprincextra = monthprincipal + extra;
            totalinterest += monthinterest;
            totalprincipal += monthprincextra;
            loan_amount -= monthprincextra;
            
        }
        // Accounts for 2 digit years so it looks nice. Uneccessary for functionality, but necessary for aesthetics.
        if(i%12 == 0 && i != months && i>=108){
            printf("\t %6d %9.0lf %10.0lf %8.0lf  | %9.0lf %10.0lf %6.0lf\n", i, monthinterest,monthprincipal,loan_amount,totalinterest,totalprincipal,extra);
            printf("------------------------------------------------------------------------\n");
            printf("Year  Month  Interest  Principal  Balance  |  INTEREST  PRINCIPAL  EXTRA\n");
            printf("------------------------------------------------------------------------\n");
            monthinterest = loan_amount * m_rate;
            monthprincipal = P - monthinterest;
            monthprincextra = monthprincipal + extra;
            totalinterest += monthinterest;
            totalprincipal += monthprincextra;
            loan_amount -= monthprincextra;
            i+=1;
            printf("  %d", (i/12)+1);
            printf("%7d %9.0lf %10.0lf %8.0lf  | %9.0lf %10.0lf %6.0lf\n", i, monthinterest,monthprincipal,loan_amount,totalinterest,totalprincipal, extra);
        }
        else if(i>1){
            printf("\t %6d %9.0lf %10.0lf %8.0lf  | %9.0lf %10.0lf %6.0lf\n", i, monthinterest,monthprincextra,loan_amount,totalinterest,totalprincipal, extra);
        }
        else if (i==1){
            printf(" %6d %9.0lf %10.0lf %8.0lf  | %9.0lf %10.0lf %6.0lf\n", i, monthinterest,monthprincextra,loan_amount,totalinterest,totalprincipal, extra);
        }
        if(loan_amount<0){
            printf("\nThe payments are finished %.0lf months (%.01lf years) earlier!\n", (months-i), (months-i)/12);
            printf("The interest saving is %.0lf\n", totalinterest2-totalinterest);
            break;
        }
    }
    return;
}

void output_extra_yearly(double loan_amount, double interest_rate, double term_years, double extra)
{
        double P,m_rate,months, monthinterest, monthprincipal, totalprincipal=0, totalinterest=0;
        double monthinterest2, totalinterest2=0, monthprincipal2, totalprincipal2=0, L;
        L=loan_amount;
        m_rate=(interest_rate/100)/12;
        months=term_years*12;
        P = (loan_amount * m_rate * pow((1+m_rate),months)) / ((pow((1+m_rate),months)) - 1 );
        printf("------------------------------------------------------------------------\n");
        printf("Year  Month  Interest  Principal  Balance  |  INTEREST  PRINCIPAL  EXTRA\n");
        printf("------------------------------------------------------------------------\n");
        printf("   1");
        for (int j=1; j<=months;j++)
        {
            monthinterest2 = L * m_rate;
            totalinterest2 += monthinterest2;
            monthprincipal2 = P - monthinterest2;
            totalprincipal2 += monthprincipal2;
            L -= monthprincipal2;
        }
        for (int i=1; i<=months;i++)
        {
            monthinterest = loan_amount * m_rate;
            monthprincipal = P - monthinterest;
            totalinterest += monthinterest;
            totalprincipal += monthprincipal;
            loan_amount -= monthprincipal;
            
            if (i%12 == 0 && i != months && i<108){
                loan_amount -= extra;
                totalprincipal += extra;
                printf("\t %6d %9.0lf %10.0lf %8.0lf  | %9.0lf %10.0lf %6.0lf\n", i, monthinterest,monthprincipal,loan_amount,totalinterest,totalprincipal,extra);
                printf("------------------------------------------------------------------------\n");
                printf("Year  Month  Interest  Principal  Balance  |  INTEREST  PRINCIPAL  EXTRA\n");
                printf("------------------------------------------------------------------------\n");
                monthinterest = loan_amount * m_rate;
                monthprincipal = P - monthinterest;
                totalinterest += monthinterest;
                totalprincipal += monthprincipal;
                loan_amount -= monthprincipal;
                
                // Extra iterations, due to the code shifting in spaces if not done
                i+=1;
                printf("   %d", (i/12)+1);
                printf("%7d %9.0lf %10.0lf %8.0lf  | %9.0lf %10.0lf\n", i, monthinterest,monthprincipal,loan_amount,totalinterest,totalprincipal);
                i+=1;
                monthinterest = loan_amount * m_rate;
                monthprincipal = P - monthinterest;
                totalinterest += monthinterest;
                totalprincipal += monthprincipal;
                loan_amount -= monthprincipal;
            }
            // Accounts for 2 digit years so it looks nice. Uneccessary for functionality, but necessary for aesthetics.
                
            if(i%12 == 0 && i != months && i>=108){
                loan_amount -= extra;
                totalprincipal += extra;
                printf("\t %6d %9.0lf %10.0lf %8.0lf  | %9.0lf %10.0lf %6.0lf\n", i, monthinterest,monthprincipal,loan_amount,totalinterest,totalprincipal,extra);
                printf("------------------------------------------------------------------------\n");
                printf("Year  Month  Interest  Principal  Balance  |  INTEREST  PRINCIPAL  EXTRA\n");
                printf("------------------------------------------------------------------------\n");
                monthinterest = loan_amount * m_rate;
                monthprincipal = P - monthinterest;
                totalinterest += monthinterest;
                totalprincipal += monthprincipal;
                loan_amount -= monthprincipal;
                i+=1;
                printf("  %d", (i/12)+1);
                printf("%7d %9.0lf %10.0lf %8.0lf  | %9.0lf %10.0lf\n", i, monthinterest,monthprincipal,loan_amount,totalinterest,totalprincipal);
            }
            else if(i>1){
                printf("\t %6d %9.0lf %10.0lf %8.0lf  | %9.0lf %10.0lf\n", i, monthinterest,monthprincipal,loan_amount,totalinterest,totalprincipal);
            }
            else if (i==1){
                printf(" %6d %9.0lf %10.0lf %8.0lf  | %9.0lf %10.0lf\n", i, monthinterest,monthprincipal,loan_amount,totalinterest,totalprincipal);
            }
            if(loan_amount<0){
                printf("\nThe payments are finished %.0lf months (%.01lf years) earlier!\n", (months-i), (months-i)/12);
                printf("The interest saving is %.0lf\n", totalinterest2-totalinterest);
                break;
        }
    }
}

void start(){
    int option;
    double loanamt, interest, term, extra;
    printf("------------------------------------------------------------------------\n");
    printf("\t    Welcome to Mortgage Calculator! Enter an Option below: \n");
    printf("------------------------------------------------------------------------\n");
    printf("1. Print the monthly payment, total interest paid, and total price paid\n");
    printf("2. Print The amortized schedule with interest and principal paid each month\n");
    printf("3. Print The amortized schedule with interest and principal paid each month with an extra monthly payment\n");
    printf("4. Print The amortized schedule with interest and principal paid each month with an extra yearly payment\n");
    scanf("%d", &option);
    // Options, calls function needed and takes other inputs
            
    if (option == 1){
        printf("Enter Loan Amount: ");
        scanf("%lf", &loanamt);
        printf("Enter Interest Rate (whole number): ");
        scanf("%lf", &interest);
        printf("Enter the loan term in years: ");
        scanf("%lf", &term);
        output_short_format(loanamt,interest,term);
    }
    if (option == 2){
        printf("Enter Loan Amount: ");
        scanf("%lf", &loanamt);
        printf("Enter Interest Rate (whole number): ");
        scanf("%lf", &interest);
        printf("Enter the loan term in years: ");
        scanf("%lf", &term);
        output_amortized(loanamt,interest,term);
    }
    if (option == 3){
        printf("Enter Loan Amount: ");
        scanf("%lf", &loanamt);
        printf("Enter Interest Rate (whole number): ");
        scanf("%lf", &interest);
        printf("Enter the loan term in years: ");
        scanf("%lf", &term);
        printf("Enter the extra monthly payment: ");
        scanf("%lf", &extra);
        output_extra_monthy(loanamt,interest,term, extra);
    }
    if (option == 4){
        printf("Enter Loan Amount: ");
        scanf("%lf", &loanamt);
        printf("Enter Interest Rate (whole number): ");
        scanf("%lf", &interest);
        printf("Enter the loan term in years: ");
        scanf("%lf", &term);
        printf("Enter the extra yearly payment: ");
        scanf("%lf", &extra);
        output_extra_yearly(loanamt,interest,term, extra);
        }
}

    
int main(int argc, const char * argv[]) {
    start();
    return 0;
}
