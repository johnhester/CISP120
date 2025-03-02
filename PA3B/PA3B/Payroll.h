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
    static double totalEmployeeSalaries;
    void createStrArray(string n, string t);
public:
    //defaults
    Payroll();
    //constructor overload
    Payroll(string n, string t, double pR, double h);
    //copy constructor 
    Payroll(Payroll& obj);
    //getters 
    string getName() const;
    string getTitle() const;
    double getPayRate() const;
    double getHours() const;
    //static getter
    static int getObjCount();
    static double getSalaries();
    //setters
    void setName(string n);
    void setTitle(string t);
    void setPayRate(double pR);
    void setHours(double h);
    //calculates weekly pay, factoring in overtime (1.5) for hours > 40
    double calcPay();
    //prints name, title, & weekly pay
    void Print();
    //overloads
    //assignment
    const Payroll operator=(Payroll &right);
    //equality
    bool operator ==(const Payroll& right);
    //subraction
    double operator -(Payroll& right);
    //iostream
    friend ostream& operator << (ostream&, Payroll&);
    friend istream& operator >> (istream&, Payroll&);
    //destructor
    ~Payroll();
};


#endif // !PAYROLL_H
