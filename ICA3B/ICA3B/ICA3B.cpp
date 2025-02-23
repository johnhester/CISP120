/*
John Hester
CISP 1020-W01
Module 3B In-Class Activity
2/22/25
*/

#include <iostream>
#include <iomanip>
using namespace std;

//Define Circle Class
class Circle {
private:
    double radius;
    double pi;
    static int circleCount;
public:
    //constructors
    //default, defines pi
    Circle() {
        radius = 1.0;
        pi = 3.1415;
        //sum circles
        circleCount++;
    };
    //take radius
    Circle(double rad)
    {
        radius = rad;
        pi = 3.1415;
        //sum circles
        circleCount++;
    };
    //copy constructor
    Circle(const Circle &circ)
    {
        radius = circ.radius;
        pi = circ.pi;
        //sum circles
        circleCount++;
    }
    //destructor
    ~Circle()
    {
        cout << "\nHave a great day!\n";
    };
    //accessors & mutators
    double getArea()
    {
        return pi * (radius * radius);
    };
    double getDiameter()
    {
        return 2 * radius;
    };
    double getCircumference()
    {
        return 2 * pi * radius;
    };
    //static member function that returns count
    static int returnCount();
    
    //overloads
    
    // assignment operator
    const Circle operator=(const Circle &right)
    {
        //check to make sure they aren't the same
        if (this != &right)
        {
            //assign vals
            radius = right.radius;
            pi = right.pi;
        }
        //return de-referenced this pointer
        return *this;
    }

    // equality ==
    const bool operator==(const Circle &right)
    {
        //return true if equal, otherwise return false
        if (radius == right.radius)
            return true;        
        return false;
    }
    // less than <
    const bool operator< (const Circle& right)
    {
        //check for less than
        if (radius < right.radius)
            return true;
        return false;
    }
    // greater than >
    const bool operator> (const Circle& right)
    {
        //check for greater than
        if (radius > right.radius)
            return true;
        return false;
    }
    // addition +
    const Circle operator+ (const Circle& right)
    {
        //sum the radiuses (radii?)
        double sum = radius + right.radius;
        //new circle with summed radii
        const Circle circ(sum);
        //return
        return circ;
    }

};

//define static var
int Circle::circleCount = 0;
//define static func
int Circle::returnCount()
{
    return circleCount;
}


//functions
double getRadius();
void printCircleData(Circle&);
void compareCircles(Circle&, Circle&);

int main()
{
    double rad1 = 0, rad2 = 0;

    //get & verify first radius
    cout << "\nHello! Please input the radius of your circle: ";
    rad1 = getRadius();
    
    //create first circle
    Circle circle1(rad1);
    printCircleData(circle1);

    //get & verify second radius
    cout << "\nPlease input the radius of your second circle: ";
    rad2 = getRadius();

    //create second circle
    Circle circle2(rad2);
    //compare circles
    compareCircles(circle1, circle2);

    //initialize circle 3 to circle one
    Circle circle3 = circle1;

    //create circle 4, then equate it to 2
    Circle circle4;
    circle4 = circle2;

    //create circle 5 by summing circles 1 & 2
    Circle circle5 = circle1 + circle2;

    //print number of circles that were created 
    cout << "\n" << circle1.returnCount() << " circles were created in this program.\n";
}

//get radius and check for greater than zero;
double getRadius()
{
    double input = 0;
    cin >> input;
    while (input <= 0)
    {
        cout << "Invalid input. Please enter a number greater than 0: ";
        cin >> input;
    }

    return input;
}

//takes in circle and prints area, diameter, and circumference
void printCircleData(Circle &circle)
{
    //prime output
    cout << setprecision(2) << fixed;
    //print info
    cout << "\nCircle information: \n";
    cout << "Area: " << circle.getArea() << endl;
    cout << "Diameter: " << circle.getDiameter() << endl;
    cout << "Circumference: " << circle.getCircumference() << endl;
}

//takes in 2 circles and compares with overloaded relational operators
void compareCircles(Circle& circle1, Circle& circle2)
{
    cout << "\nThe radius of the second circle is ";

    //compare circles

    if (circle2 > circle1)
        cout << "greater than ";
    else if (circle2 < circle1)
        cout << "less than ";
    else if (circle2 == circle1)
        cout << "equal to ";

    cout << "the first circle.\n";

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


