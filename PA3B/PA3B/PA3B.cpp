/*
John Hester
CISP 1020-W01
Programming Assignment 4 (3B)
Last date modified: 3/1/25
Description: Gathers an array of 5 employee objects utilizing various class features and compares them using overloaded operators
*/

using namespace std;
#include "Payroll.h"
#include <iostream>;
#include <iomanip>


int main()
{
	//initialize array
	const int size = 5;
	Payroll employees[size];

	/*
	Objects:
		1.	The user should enter all of the information, use the overloaded >> operator.  
		2.	Initialized to the values of the first object.  Verify that these two are equal, using the == operators.  The verification should print “Same”.
		3.	The user should enter all of the information, use the overloaded >> operator.  
		4.	Created and then contents of object 3 copied to it (operloaded =)
		5.	The user should enter all of the information, use the overloaded >> operator.  Then print the difference between object 1 and 5.  

	*/

	cout << "\nHello! Welcome to the payroll simulator.\n";

	//1.
	
	cout << "Please enter the information of your first employee: ";
	cin >> employees[0];

	//2
	employees[1] = employees[0];
	cout << "\nFirst employee == second employee: ";

	//check if they're equal
	if (employees[1] == employees[0])
	{
		cout << "Same\n";
	}
	else
	{
		cout << "Different\n";
	}

	//3
	cout << "Please enter the information of your third employee: ";
	cin >> employees[2];

	//4
	employees[3] = employees[2];
	
	//5
	cout << "Please enter the information of your fifth employee: ";
	cin >> employees[4];

	cout << fixed << setprecision(2);
	cout << "\nThe difference in pay between " << employees[0].getName() << "'s pay and " << employees[4].getName() << "'s pay is: " << employees[0] - employees[4] << endl;

	
	//After all five objects are created and stored in the array.  Print the name, title, and salary for each object, using the overloaded << operator. 
	for (int i = 0; i < size; i++)
	{
		cout << employees[i];
	}
	
	//Lastly, using the static variables, print the average pay (total pay/number of objects). 
	cout << "\nAverage pay across all employees: $";
	cout << employees[0].getSalaries() / static_cast<double>(size) << endl;
	

}