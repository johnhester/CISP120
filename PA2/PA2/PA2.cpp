/*
John Hester
CISP 1020-W01
Programming Assignment 2
2/12/2025
Description: This user gathers user budget data, stores it in an array by month, and prints out the toaverage spent per month
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

//self explanitory
enum Month { January, February, March, April, May, June, July, August, September, October, November, December };

//monthly budget struct
struct MonthlyBudget {
    Month month;
    double housing;
    double utilities;
    double food;
    double savings;
    double transportation;
    double miscellaneous;
    double total;
    };

//function declarations
void averageTotal(MonthlyBudget[]);
void gatherInput(MonthlyBudget[]);
void clearInputBuffer();
void printMonth(Month);
double validateDouble();

int main()
{
    //declare array, no need for dynamic array in this scenario
    const int size = 12;
    MonthlyBudget monthArr[size];
    //gather user input 
    gatherInput(monthArr);
    //function that prints totals and average spent per month
    averageTotal(monthArr);
}

//take array print totals, and average the yearly expenditures
void averageTotal(MonthlyBudget monthArr[])
{
    double average, sum = 0;
    int numMonths = 0;
    //prepare output
    cout << fixed << setprecision(2);

    cout << "\n\nHere are your total monthly expenses: ";

   //iterate over array and print totals while building average
    for (Month m = January; m <= December; m = static_cast<Month>(m + 1))
    {   
        cout << endl;
        printMonth(m);
        cout << ": $" << monthArr[m].total;
        sum += monthArr[m].total;
        numMonths++;
    }


    average = sum / static_cast<double>(numMonths);

    cout << "\n\nYou spent an average of $" << average << " per month over " << numMonths << " months.\n\n";

}

//gather input
void gatherInput(MonthlyBudget monthArr[])
{
    cout << "\n\nWelcome to the budget summarizer! Prepare to enter your monthly expenditures." << endl;

    //iterate using enum
    for (Month m = January; m <= December; m = static_cast<Month>(m + 1))
    {

        double total = 0;
        //load month
        monthArr[m].month = m;

        //start for the month
        cout << "\n\nPlease enter your expenses for the month of ";
        printMonth(m);


        //gather various expenses and sum total
        cout << "\nEnter your housing expenses: ";
        monthArr[m].housing = validateDouble();
        total += monthArr[m].housing;

        cout << "Enter your utility expense: ";
        monthArr[m].utilities = validateDouble();
        total += monthArr[m].utilities;
        
        cout << "Enter your food expenses: ";
        monthArr[m].food = validateDouble();
        total += monthArr[m].food;
        
        cout << "Enter the amount you put into savings: ";
        monthArr[m].savings = validateDouble();
        total += monthArr[m].savings;
        
        cout << "Enter the amount you spent on transportation: ";
        monthArr[m].transportation = validateDouble();
        total += monthArr[m].transportation;
        
        cout << "Enter your mischellaneous expenses: ";
        monthArr[m].miscellaneous = validateDouble();
        total += monthArr[m].miscellaneous;

        //store total
        monthArr[m].total = total;
    }

}

//clears the buffer
void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void printMonth(Month month)
{
    switch (month)
    {
    case 0:
        cout << "January";
        break;
    case 1:
        cout << "February";
        break;
    case 2:
        cout << "March";
        break;
    case 3:
        cout << "April";
        break;
    case 4:
        cout << "May";
        break;
    case 5:
        cout << "June";
        break;
    case 6: 
        cout << "July";
        break;
    case 7:
        cout << "August";
        break;
    case 8:
        cout << "September";
        break;
    case 9:
        cout << "October";
        break;
    case 10:
        cout << "November";
        break;
    case 11:
        cout << "December";
        break;
    default:
        cout << "Error. The month printer broke.";
    }
}

//validates double
double validateDouble()
{
    double input = 0;
    while (!(cin >> input) || input < 0)
    {
        cout << "\nInvalid input. Please enter a positive number: ";
        clearInputBuffer();
    }

    return input;
}