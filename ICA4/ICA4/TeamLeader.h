#pragma once
#ifndef TEAMLEADER_H
#define TEAMLEADER_H

#include "ProductionWorker.h"
#include <string>
using namespace std;

class TeamLeader :
    public ProductionWorker
{
private:
    double monthlyBonus;
    double requiredTrainingHours;
    double completedTrainingHours;
public:
    //constructors
    TeamLeader() : ProductionWorker()
    {
        monthlyBonus = 0;
        requiredTrainingHours = 0;
        completedTrainingHours = 0;
    }
    TeamLeader(string n, string num, string hire, int s, double rate, double bonus, double req, double com) : ProductionWorker(n, num, hire, s, rate)
    {
        monthlyBonus = bonus;
        requiredTrainingHours = req;
        completedTrainingHours = com;
    }
    //getters and setters
    double getMonthlyBonus()
    {
        return monthlyBonus;
    }
    void setMonthlyBonus(double bonus)
    {
        monthlyBonus = bonus;
    }
    double getRequiredTrainingHours()
    {
        return requiredTrainingHours;
    }
    void setRequiredTrainingHours(double req)
    {
        requiredTrainingHours = req;
    }
    double getCompletedTrainingHours()
    {
        return completedTrainingHours;
    }
    void setCompletedTrainingHours(double com)
    {
        completedTrainingHours = com;
    }
};

#endif

