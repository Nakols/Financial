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
        principal = atof(argv[1]);
        humanInterest = atof(argv[2]);
        yearsOfLoan = atoi(argv[3]);
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
    
    long currLoanmonth = 1;
    
    while(currLoanmonth <= monthsOfLoan){
        gAmortizeMonth amortMonth;
        
        currInterestPayment = currBalance*monthInterest;
        currPrincipalPayment = payment - currInterestPayment;
        currBalance = currBalance - currPrincipalPayment;
        
        amortMonth.year = 1;
        amortMonth.yearMonth = 1;
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
        
        cout << "CM: " << amortMonth.loanMonth << " " <<
        "CIP: " << amortMonth.pureInterest << " " <<
        "CP: " << amortMonth.paidDownPrincipal << " " <<
        "Bal: " << amortMonth.principalBalance << endl;
        currLoanmonth++;
    }
    
    cout << "Loan payments complete" << endl;
    return 0;
}

    

