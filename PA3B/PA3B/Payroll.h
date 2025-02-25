/*
Payroll class holds an employee name, title, pay rate, and hours worked.
Functions: Has getters and setters, constructor overloads, calculates pay, and prints worker details 
*/

#pragma once
#ifndef PAYROLL_H
#define PAYROLL_H



#include <iostream>
#include <string>
using namespace std;


//class definition
class Payroll {
private:
    string *nameTitle;
    double payRate;
    double hours;
    static int objectCount;
    static double employeeSalaries;
    void createStrArray(string n, string t);
public:
    //defaults
    Payroll();
    //constructor overload
    Payroll(string n, string t, double pR, double h);
    //getters 
    string getName() const;
    string getTitle() const;
    double getPayRate() const;
    double getHours() const;
    //static getter
    static int getObjCount();
    //setters
    void setName(string n);
    void setTitle(string t);
    void setPayRate(double pR);
    void setHours(double h);
    //calculates weekly pay, factoring in overtime (1.5) for hours > 40
    double calcPay();
    //prints name, title, & weekly pay
    void Print();
    //calculates and adds salaries to each new employee
    //overloads

    //destructor
    ~Payroll();
};


#endif // !PAYROLL_H
