//.cpp file for Payroll.h

#include "Payroll.h";
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//initialize payroll static var
int Payroll::objectCount = 0;

//constructors
//default
Payroll::Payroll() {
    payRate = 10;
    hours = 40;
    string name = "Doug Funny";
    string title = "Quail Man";
    //initialize dynamic string array
    createStrArray(name, title);
    //iterate static counter
    objectCount++;
};
//overload
Payroll::Payroll(string n, string t, double pR, double h)
{
    createStrArray(n, t);
    payRate = pR;
    hours = h;
    //iterate static counter
    objectCount++;
}

//destructor
Payroll::~Payroll()
{
    //de-allocate ptr
    delete[] nameTitle;
    nameTitle = nullptr;
    //closing message;
    cout << "\nHave a great day!\n";
}

//dynamically allocate array space for name and title
void Payroll::createStrArray(string name, string title)
{
    int size = 2;
    nameTitle = new string[size];
    nameTitle[0] = name;
    nameTitle[1] = title;

}

//getters 
string Payroll::getName() const
{
    return nameTitle[0];
}
string Payroll::getTitle() const
{
    return nameTitle[1];
}
double Payroll::getPayRate() const
{
    return payRate;
}
double Payroll::getHours() const
{
    return hours;
}
//setters
void Payroll::setName(string n)
{
    nameTitle[0] = n;
};
void Payroll::setTitle(string t)
{
    nameTitle[1] = t;
}
void Payroll::setPayRate(double pR)
{
    payRate = pR;
}
void Payroll::setHours(double h)
{
    hours = h;
}
//calculates weekly pay, factoring in overtime (1.5) for hours > 40
double Payroll::calcPay()
{
    //check hours to factor in overtime
    //OT rate is 1.5
    if (hours > 40)
    {
        double basePay = 40 * payRate;
        double overTime = 1.5 * payRate * (hours - 40);

        return basePay + overTime;
    }
    //standard week
    return hours * payRate;
}
//prints name, title, & weekly pay
void Payroll::Print()
{
    //prime output
    cout << setprecision(2) << fixed;
    //name, title, weekly pay
    cout << endl << getName() << ", " << getTitle() << ", $" << calcPay() << endl;
}

//static member function for returning ojbect count
int Payroll::getObjCount()
{
    return objectCount;
}