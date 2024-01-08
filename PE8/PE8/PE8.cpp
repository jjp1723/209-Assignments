// PE8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void changeVariable(int variable);
void changePointer(int* pointer);

int getLengthArray(int arr[]);
int getLengthPointer(int* pointer);

int* createStackArray();
int* createHeapArray(int size);

int main()
{
    // ----- Part 1 -----

    cout << " ----- Part 1 ----- \n" << endl;
    int var = 5;
    cout << "Inside main() - variable's value is: " << var << endl;
    changeVariable(var);
    changePointer(&var);

    //The two functions differ in terms of altering the value of the variable due to changeVariable() changing the value on the stack
    //   and changePointer() changing the value on the heap



    // ----- Part 2 -----

    cout << "\n\n\n ----- Part 2 ----- \n" << endl;
    int myIntArray[7] = { 1, 19, 43, 76, 343, 67, -1 };
    int* myPointer = myIntArray;
    cout << "Result of passing myPointer into getLengthArray(): " << getLengthArray(myPointer) << endl;
    cout << "Result of passing myIntArray into getLengthPointer(): " << getLengthPointer(myIntArray) << endl;



    // ----- Part 3 -----

    cout << "\n\n\n ----- Part 3 ----- \n" << endl;
    int* pointer1 = createStackArray();
    int* pointer2 = createHeapArray(5);

    cout << "Contents of stack array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << pointer1[i] << ", ";
    }

    cout << "\nContents of heap array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << pointer2[i] << ", ";
    }
    delete[] pointer2;

    //For the array on the stack, when the contents are printed they are random integers,
    //   and this is due to the original values on the stack being overwritten
}



// ----- Part 1 Functions -----

void changeVariable(int variable)
{
    variable = 7;
    cout << "Inside changeVariable() - variable's value is now: " << variable << endl;
}

void changePointer(int* pointer)
{
    *pointer = 9;
    cout << "Inside changePointer() - variable's value is now: " << *pointer << endl;
}



// ----- Part 2 Functions -----

int getLengthArray(int arr[])
{
    int length = 0;
    while (arr[length] != -1)
    {
        length++;
    }
    return length;
}

int getLengthPointer(int* pointer)
{
    int length = 0;
    while (pointer[length] != -1)
    {
        length++;
    }
    return length;
}



// ----- Part 3 Functions -----

int* createStackArray()
{
    int data[5] = { 0, 1, 2, 3, 4 };
    return data;
}

int* createHeapArray(int size)
{
    int *data = new int[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = i;
    }
    return data;
}