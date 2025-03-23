#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee
{
private:
	string name;
	string number;
	string hireDate;
public:
	//default constructor
	Employee()
	{
		name = "";
		number = "";
		hireDate = "";
	};
	//overload
	Employee(string n, string num, string hire)
	{
		name = n;
		number = num;
		hireDate = hire;
	};

	//getters and setters
	string getName()
	{
		return name;
	}
	string getNumber()
	{
		return number;
	}
	string getHireDate()
	{
		return hireDate;
	}
	void setName(string n)
	{
		name = n;
	}
	void setNumber(string num)
	{
		number = num;
	}
	void setHireDate(string h)
	{
		hireDate = h;
	}
};

#endif //!EMPLOYEE_H