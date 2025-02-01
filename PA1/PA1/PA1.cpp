/*
John Hester
CISP 1020-W01
Programming Assignment 1
2/1/25
Description: This program takes in a user defined number of test scores, store and sort those using pointers, 
print them line by line, and average them.
*/

#include <iostream>
#include <limits>
using namespace std; 

void clearInput();
double* allocateMem(int);
void selectionSort(double*, int);
void swap(double*, double*);
double getAverage(double*, int);
void displayOutput(double*, int, double);

int main()
{
    
    int size = 0;

    //gather user input for double array size
    cout << endl << "Welcome!" << endl;
    cout << "\nPlease enter the number of grades you wish to average: ";

    //input validation
    while (!(cin >> size) || size <= 0)
    {
        cout << "\nInvalid input. Please enter an integer greater than zero: ";
        clearInput();
    }
    //at least three required functions
    //1. Function dynamically allocates array of doubles to a userdefined size and returns the pointer
    double* arrPtr = allocateMem(size);    
    //main function will have user enter all of the test scores
    cout << "\nThank you. Now please enter your test scores.\n";

    for (int i = 0; i < size; i++)
    {
        double grade = 0;

        //numbering the inputs for the user
        cout << "[" << i + 1 << "]:";
        //input validation
        while (!(cin >> grade) || grade < 0)
        {
            cout << "Invalid input. Please enter non-negative, numeric grade: ";
            clearInput();
        }
        arrPtr[i] = grade;
    }

    //2. Function to sort test scores in ascending order (pointers)
    selectionSort(arrPtr, size);
    //3. Function to return average of array
    double average = getAverage(arrPtr, size);
    //print sorted one element per line and display the average
    displayOutput(arrPtr, size, average);




    //de-allocate memory and convert arr pointer to null pointer
    delete[] arrPtr;
    arrPtr = nullptr;
}

//clears the input buffer
void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//create an array of doubles based on user input size
double* allocateMem(int size)
{
    //allocate memory based on parameter size
    double* doubleArr = new double[size];

    return doubleArr;
}

//seleciton sort for the ptr array
void selectionSort(double* arrPtr, int size)
{
    int minIndex;
    double minValue = 0;

    for (int start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = arrPtr[start];

        for (int index = start + 1; index < size; index++)
        {
            if (arrPtr[index] < minValue)
            {
                minValue = arrPtr[index];
                minIndex = index;
            }
        }

        swap(arrPtr[minIndex], arrPtr[start]);
    }
}

//swaps values
void swap(double* a, double* b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

//gets the average of the provided grades
double getAverage(double* arrPtr, int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
        sum += arrPtr[i];

    return sum / size;
}

//prints output, extracted to function
void displayOutput(double* ptrArr, int size, double avg)
{

    cout << endl << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "[" << i + 1 << "]: " << ptrArr[i] << endl;
    }

    cout << "The average of the test scores is " << avg << endl << endl;
}