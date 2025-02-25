/*
John Hester
CISP 1020-W01
Programming Assignment 4 (3B)
Last date modified: 2/25/25
Description:
*/

using namespace std;
#include "Payroll.h"
#include <iostream>;


int main()
{
	Payroll person;

	person.Print();

	Payroll newGuy("David Rose", "Unemployed", 45, 2);

	newGuy.Print();

	cout << "Num created: " << person.getObjCount();
}