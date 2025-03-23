#pragma once
#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include "Employee.h"
#include <string>
using namespace std;

class ProductionWorker :
    public Employee
{
private:
    int shift;
    double payRate;
public:
    //default extending employee
    ProductionWorker() : Employee()
    {
        shift = 0;
        payRate = 0.0;
    }
    //overload extending to employee
    ProductionWorker(string n, string num, string hire, int s, double rate) : Employee(n, num, hire)
    {
        shift = s;
        payRate = rate;
    }
    //getters and setters
    int getShift()
    {
        return shift;
    }
    string getShiftName()
    {
        if (shift == 1)
            return "day";
        else
            return "night";
    }

    void setShift(int s)
    {
        shift = s;
    }
    double getPayRate()
    {
        return payRate;
    }
    void setPayRate(double rate)
    {
        payRate = rate;
    }
};


#endif //PRODUCTIONWORKER_H
