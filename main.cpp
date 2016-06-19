//
//  main.cpp
//  Financial
//
//  Created by Nikita Lisitsyn on 2016-06-15.
//  Copyright © 2016 Nikita Lisitsyn. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <iomanip>
#include "multiplier.h"
#include "divisor.h"
#include "global.h" 
using namespace std;

enum AmortizeProgram
{
    LOAN_PRINCIPAL = 1,
    INTEREST_RATE = 2,
    YEARS_OF_LOAN = 3
};

enum AmortEnum
{
    YR_OUT = 2,
    MN_OUT = 2,
    CU_MN_OUT = 5,
    PAYMENT_OUT = 12,
    INTEREST_OUT = 12,
    PRINCIPAL_OUT = 12,
    BALANCE_OUT = 16
};

int main(int argc, char*argv[])
{
    
    double principal = 0.0;
    double humanInterest = 0.0;
    int yearsOfLoan = 0;

    if ( argc == 1)
    {
        cout << "Enter the principal amount: ";
        cin >> principal;
        
        cout << "Enter the interest rate: ";
        cin >> humanInterest;
        
        cout << "Enter years of loan: ";
        cin >> yearsOfLoan;
        
    } else {
        principal = atof(argv[LOAN_PRINCIPAL]);
        humanInterest = atof(argv[INTEREST_RATE]);
        yearsOfLoan = atoi(argv[YEARS_OF_LOAN]);
    }
    
    cout << "Loan Principal: " << principal << endl;
    cout << "Interest Rate: " << humanInterest << "%" << endl;
    cout << "Time Period: " << yearsOfLoan  << " year(s)" << endl;
    
    double interest = divisor(humanInterest, gpercentDenominator);
    double monthInterest = divisor(interest, gmonthInYear);
    long monthsOfLoan = multiplier(yearsOfLoan, gmonthInYear);
    
    double payment = 0.0;
    
    payment = principal*(monthInterest/(1 - pow( (double) 1 + monthInterest, (double) -monthsOfLoan)));
    
    cout << "Payment: " << setiosflags(ios::fixed) << setprecision(2) << payment << endl;
    
    double currInterestPayment = 0.0;
    double currPrincipalPayment = 0.0;
    double currBalance = 0.0;
    
    currBalance = principal;
    
    int year = 1 ;
    int switchYear = 0 ;
    
    int yearMonth = 1;
    
    long currLoanmonth = 1;
    
    while(currLoanmonth <= monthsOfLoan){
        gAmortizeMonth amortMonth;
        
        currInterestPayment = currBalance*monthInterest;
        currPrincipalPayment = payment - currInterestPayment;
        currBalance = currBalance - currPrincipalPayment;
        
        amortMonth.year = year;
        amortMonth.yearMonth = yearMonth;
        amortMonth.loanMonth = currLoanmonth;
        amortMonth.payment = payment;
        amortMonth.pureInterest = currInterestPayment;
        amortMonth.paidDownPrincipal = currPrincipalPayment;
        amortMonth.principalBalance = currBalance;
    
        
        struct gAmortizeMonth
        {
            int year;
            int yearMonth;
            long loanMonth;
            double payment;
            double pureInterest;
            double paidDownPrincipal;
            double principalBalance;
        };
        
        cout <<
        setw(YR_OUT) << amortMonth.year << " " <<
        setw(MN_OUT) << amortMonth.yearMonth << " " <<
        setw(CU_MN_OUT) << amortMonth.loanMonth << " " <<
        setw(PAYMENT_OUT) << amortMonth.payment << " " <<
        setw(INTEREST_RATE) << amortMonth.pureInterest << " " <<
        setw(PRINCIPAL_OUT) << amortMonth.paidDownPrincipal << " " <<
        setw(BALANCE_OUT) << amortMonth.principalBalance << " " << endl;

        yearMonth++;
        
        if (yearMonth > gmonthInYear)
        {
            yearMonth = 1;
            year++;
        }
       
        currLoanmonth++;
    }
    
    cout << "Loan payments complete" << endl;
    return 0;
}

    

