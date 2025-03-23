/*
John Hester
CISP 1020-W01
Module 4 In-Class Activity
3/22/25
*/

#include "TeamLeader.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	TeamLeader leader("Sammy Davis Jr", "987123", "3/22/2005", 2, 25.00, 2200, 75, 40);

	//formatting:
	cout << fixed << setprecision(2);
	//output
	cout << "\nThis is your team lead: \n\n";
	cout << "Name: " << leader.getName() << endl;
	cout << "Number: " << leader.getNumber() << endl;
	cout << "Hire Date: " << leader.getHireDate() << endl;
	cout << "Shift: " << leader.getShiftName() << endl;
	cout << "Pay Rate: $" << leader.getPayRate() << "/hr" << endl;
	cout << "Monthly Bonus: $" << leader.getMonthlyBonus() << endl;
	cout << "Required Training Hours: " << leader.getRequiredTrainingHours() << endl;
	cout << "Completed Training Hours: " << leader.getCompletedTrainingHours() << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

