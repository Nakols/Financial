//
//  global.h
//  Financial
//
//  Created by Nikita Lisitsyn on 2016-06-19.
//  Copyright © 2016 Nikita Lisitsyn. All rights reserved.
//

#ifndef global_h
#define global_h

const int gmonthInYear = 12;
const int gpercentDenominator = 100;

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


#endif /* global_h */
