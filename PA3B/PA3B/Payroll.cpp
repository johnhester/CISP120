//.cpp file for Payroll.h

#include "Payroll.h";
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cmath>
using namespace std;

//initialize payroll static var
int Payroll::objectCount = 0;
//initialize salary static var
double Payroll::totalEmployeeSalaries = 0;


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
    //add salary
    totalEmployeeSalaries += calcPay();
};
//overload
Payroll::Payroll(string n, string t, double pR, double h)
{
    createStrArray(n, t);
    payRate = pR;
    hours = h;
    //iterate static counter
    objectCount++;
    //add salary
    totalEmployeeSalaries += calcPay();
}
//copy constructor
Payroll::Payroll(Payroll& obj)
{
    
    payRate = obj.payRate;
    hours = obj.hours;
    //new ptr arr
    int size = 2;
    nameTitle = new string[size];
    for (int i = 0; i < size; i++)
    {
        //assign items 
        nameTitle[i] = obj.nameTitle[i];
    }
    //iterate object counter & salary variable
    objectCount++;
    totalEmployeeSalaries += calcPay();
}

//destructor
Payroll::~Payroll()
{
    //remove salary 
    totalEmployeeSalaries -= calcPay();
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
//static member function for returning total salaries
double Payroll::getSalaries()
{
    return totalEmployeeSalaries;
}

//operator overloads

//assignment operator
const Payroll Payroll::operator=(Payroll& right)
{
    if (this != &right)
    {
        //remove salary
        totalEmployeeSalaries -= calcPay();

        //clear out ptr arr
        delete[] nameTitle;
        //assign vals
        payRate = right.payRate;
        hours = right.hours;
        int size = 2;
        nameTitle = new string[size];
        //re-assign ptr arr
        for (int i = 0; i < size; i++)
        {
            nameTitle[i] = right.nameTitle[i];
        }

        //add new salary
        totalEmployeeSalaries += right.calcPay();

    }

    return *this;
}

//equality operator
bool Payroll::operator==(const Payroll& right)
{
    //check if name, title, hours, and rate are equal
    if (getName() == right.getName() && getTitle() == right.getTitle() && payRate == right.payRate && hours == right.hours)
    {
        return true;
    }

    return false;
}

//subtraction operator, returns difference in pay
double Payroll::operator-(Payroll& right)
{
    return abs(calcPay() - right.calcPay());
}

//ostream operator
ostream& operator << (ostream& strm, Payroll& obj)
{
    //does the same thing as the print function
    //prime output
    strm << setprecision(2) << fixed;
    //name, title, weekly pay
    strm << endl << obj.getName() << ", " << obj.getTitle() << ", $" << obj.calcPay() << endl;

    return strm;
}

//istream operator
istream& operator >> (istream& strm, Payroll& obj)
{
    string name, title;
    int size = 2;
    double payRate = 0, hours = 0;

    //remove existing pay from variable before updating with correct info
    Payroll::totalEmployeeSalaries -= obj.calcPay();

    

    //gather input
    cout << "\nName: ";
    getline(strm, name);
    cout << "Title: ";
    getline(strm, title);
    //get and validate pay rate
    cout << "Hourly Pay Rate: ";
    while (!(strm >> payRate) || payRate <= 0)
    {
        cout << "Invalid input. Please enter a number larger than zero: ";
        strm.clear();
        strm.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    //get and validate hours
    cout << "Hours worked: ";
    while (!(strm >> hours) || hours <= 0)
    {
        cout << "Invalid input. Please enter a number larger than zero: ";
        strm.clear();
        strm.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    //load obj;
    obj.createStrArray(name, title);
    obj.payRate = payRate;
    obj.hours = hours;
    obj.objectCount++;
    obj.totalEmployeeSalaries += obj.calcPay();

    //clear buffer for next run
    strm.clear();
    strm.ignore(numeric_limits<streamsize>::max(), '\n');


    return strm;
}

//validates numeric double inputs

