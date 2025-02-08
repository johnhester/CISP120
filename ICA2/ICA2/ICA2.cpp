/*
John Hester
CISP-1020-W01
Module 2 In-Class Activity
2/8/25
*/

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

void printDiv(int);
int validateInput();

int main()
{

    //each of the company divisions
    enum Divisions {East, West, North, South};
    
    //describes division name and sales activity for the year
    struct Division {
        Divisions name;
        int firstQ;
        int secondQ;
        int thirdQ;
        int fourthQ;
        int totalAnnSales;
        double averageQSales;

    };

    //array of structs for each division, initialized with division names already included
    const int size = 4, quarters = 4;
    Division companyDivisions[size] = { {East}, {West}, {North}, {South} };

    cout << "\n\nPlease enter the sale data for each divison.\n";

    //step through loop using enum to gather sales
    for (Divisions d = East; d <= South; d = static_cast<Divisions>(d + 1))
    {
        cout << "\nEnter quarterly data for the ";
        printDiv(companyDivisions[d].name);
        cout << " division." << endl;

        int sum = 0;

        cout << "First Quarter: ";
        companyDivisions[d].firstQ = validateInput();
        //start gatherint total
        sum += companyDivisions[d].firstQ;

        cout << "Second Quarter: ";
        companyDivisions[d].secondQ = validateInput();
        sum += companyDivisions[d].secondQ;

        cout << "Third Quarter: ";
        companyDivisions[d].thirdQ = validateInput();
        sum += companyDivisions[d].thirdQ;

        cout << "Fourth Quarter: ";
        companyDivisions[d].fourthQ = validateInput();
        sum += companyDivisions[d].thirdQ;

        //get total annual
        companyDivisions[d].totalAnnSales = sum;
        //get average
        companyDivisions[d].averageQSales = static_cast<double>(companyDivisions[d].totalAnnSales) / quarters;

    }

    cout << endl;

    //print output
    for (Divisions d = East; d <= South; d = static_cast<Divisions>(d + 1))
    {
        cout << fixed << setprecision(2);

        cout << "\nThe ";
        printDiv(d);
        cout << " division had " << companyDivisions[d].averageQSales << " average quarterly sales.";
    }
    
    cout << endl;
}

// prints division name based on input
void printDiv(int d)
{
    switch (d)
    {
    case 0:
        cout << "East";
        break;
    case 1:
        cout << "West";
        break;
    case 2:
        cout << "North";
        break;
    case 3:
        cout << "South";
        break;
    default:
        cout << "Uh oh. Somehting Broke";
    }
}

//validates int input
int validateInput()
{
    int i = 0;

    while (!(cin >> i) || i < 0)
    {
        cout << "\nError. Invalid input. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');    
    }

    return i;
}
