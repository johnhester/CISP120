/*
John Hester
CISP 1020 W01
Module 1 In-Class Activity
01/31/2025
*/

#include <iostream>
#include <limits>
using namespace std;

int getArrSize();
float* allocateMem(int);

int main()
{
    //accept integer argument for size of array needed
    int size = getArrSize();
    //create function that dynamically allocates the memory for the array and returns a pointer to the array
    float* arrPtr = allocateMem(size);
    //take input for the array
    cout << "\nEnter your values.\n";
    for (int i = 0; i < size; i++)
    {
        cout << "[" << i + 1 << "]: ";
        while (!(cin >> arrPtr[i]))
        {
            cout << "Invalid entry. Please input a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    //find the total and average, then print
    float sum = 0, avg = 0;
    for (int i = 0; i < size; i++)
        sum += *(arrPtr + i);
    avg = sum / size;

    cout << "\nThe total sum of your entries is: " << sum;
    cout << "\nThe average of your entries is: " << avg << endl << endl;

    delete[] arrPtr;
}

//obtain initial value, validate input
int getArrSize()
{
    int input = 0;
    cout << endl << "Input the size of the array: ";
    while (!(cin >> input) || input <= 0)
    {
        cout << "\nInvalid entry. Input an integer greater than 0: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return input;
}

//create array for memory allocation and return pointer
float* allocateMem(int size)
{
    float* arrPtr = new float[size];

    return arrPtr;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

