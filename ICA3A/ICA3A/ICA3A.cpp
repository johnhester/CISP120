/*
John Hester
CISP 1020-W01
Module 3A In-Class Activity
2/15/25
*/

#include <iostream>
#include <iomanip>
using namespace std;

//Define Circle Class
class Circle {
    private:
        double radius;
        double pi;
    public:
        //default, defines pi
        Circle() {
            radius = 1.0;
            pi = 3.1415;
        };
        //take radius
        Circle(double rad)
        {
            radius = rad;
            pi = 3.1415;
        };
        //accessors & mutators
        double getArea()
        {
            return pi * (radius*radius);
        };
        double getDiameter()
        {
            return 2 * radius;
        };
        double getCircumference()
        {
            return 2 * pi * radius;
        };
        ~Circle()
        {
            cout << "\nHave a great day!\n";
        };
        
};

int main()
{
    cout << "\nHello! Please input the radius of your circle: ";
    double input = 0.0;
    cin >> input;
    //check input greater than zero
    while (input <= 0)
    {
        cout << "Invalid input. Please input a radius greater than zero: ";
        cin >> input;
    }

    Circle circ(input);

    cout << "\nYour circle information:\n";
    cout << "Area: " << circ.getArea() << endl;
    cout << "Diameter: " << circ.getDiameter() << endl;
    cout << "Circumference: " << setprecision(2) << fixed << circ.getCircumference() << endl;
}

