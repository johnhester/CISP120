/*
John Hester
CISP 1020-W01
Programming Assignment 3A
2/19/25
Description: Takes in employee information and returns a payroll summary of name, title, & weekly pay
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

//class definition
class Payroll {
    private:
        string name;
        string title;
        double payRate;
        double hours;
public:
    //defaults
    Payroll() {
        name = "Doug Funny";
        title = "Quail Man";
        payRate = 10;
        hours = 40;
    };
    //overload
    Payroll(string n, string t, double pR, double h)
    {
        name = n;
        title = t;
        payRate = pR;
        hours = h;
    }
    //getters 
    string getName() const
    {
        return name;
    }
    string getTitle() const
    {
        return title;
    }
    double getPayRate() const
    {
        return payRate;
    }
    double getHours() const
    {
        return hours;
    }
    //setters
    void setName(string n)
    {
        name = n;
    };
    void setTitle(string t)
    {
        title = t;
    }
    void setPayRate(double pR)
    {
        payRate = pR;
    }
    void setHours(double h)
    {
        hours = h;
    }
    //calculates weekly pay, factoring in overtime (1.5) for hours > 40
    double calcPay();
    //prints name, title, & weekly pay
    void Print();
    //destructor
    ~Payroll()
    {
        cout << "\nHave a great day!\n";
    }
};

//class functions
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

void Payroll::Print()
{
    //prime output
    cout << setprecision(2) << fixed;
    //name, title, weekly pay
    cout << endl << getName() << ", " << getTitle() << ", $" << calcPay() << endl;
}

//function tags
void gatherInput(Payroll[], int);
double validateDouble();
void clearBuffer();

int main()
{
    const int size = 5;
    Payroll employees[size];

    cout << "\nWelcome to the payroll calculator!\n";
    gatherInput(employees, size);

    //print employees
    cout << "\nHere are your employees: \n";
    //format output
    cout << setprecision(2) << fixed;

    for (int i = 0; i < size; i++)
    {
        employees[i].Print();
    }

}

//does what it says
void clearBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// checks type and number greater than 0
double validateDouble()
{
    double input = 0;
    //is correct input type or greater than zero
    while (!(cin >> input) || input < 0)
    {
        cout << "Invalid input. Please enter a number larger than zero: ";
        clearBuffer();
    }

    return input;
}

//load up to 5 employees
void gatherInput(Payroll employees[], int size)
{
    for (int i = 0; i < size; i++)
    {   
        string name, title;
        double hours, payRate;
        cout << "\nEnter the information for employee " << i + 1 << endl << endl;
        cout << "Name: ";
        getline(cin, name);
        cout << "Title: ";
        getline(cin, title);
        
        cout << "Hourly Pay Rate: ";
        payRate = validateDouble();

        cout << "Hours worked: ";
        hours = validateDouble();

        //clears for getline on rerun
        clearBuffer();

        //load class instance
        employees[i].setName(name);
        employees[i].setTitle(title);
        employees[i].setPayRate(payRate);
        employees[i].setHours(hours);

    }
}


