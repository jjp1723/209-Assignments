// HW4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "TemplatedStack.h"
#include "Test.h"
#define _CRTDBG_MAP_ALLOC
#include <iostream>
using namespace std;

int main()
{
    //Creating three stacks of different data types
    TemplatedStack<int> stack1 = TemplatedStack<int>();
    TemplatedStack<char> stack2 = TemplatedStack<char>();
    TemplatedStack<double> stack3 = TemplatedStack<double>();

    //Checking the sizes of each stack
    cout << stack1.GetSize() << endl;
    cout << stack2.GetSize() << endl;
    cout << stack3.GetSize() << endl;

    //Making sure 'Pop()' method returns null when the stack is empty
    if (stack1.Pop() == NULL)
    {
        cout << "Cannot pop from stack 1; stack 1 is empty" << endl;
    }

    //Checking if the stacks ar empty
    if (stack1.IsEmpty())
    {
        cout << "Stack 1 is empty" << endl;
    }
    else
    {
        cout << "Stack 1 is NOT empty" << endl;
    }
    if (stack2.IsEmpty())
    {
        cout << "Stack 2 is empty" << endl;
    }
    else
    {
        cout << "Stack 2 is NOT empty" << endl;
    }
    if (stack3.IsEmpty())
    {
        cout << "Stack 3 is empty" << endl;
    }
    else
    {
        cout << "Stack 3 is NOT empty" << endl;
    }

    //Pushing data to each stack
    stack1.Push(2);
    stack1.Push(10);
    stack1.Push(99);
    stack2.Push('a');
    stack2.Push('b');
    stack2.Push('c');
    stack2.Push('z');
    stack3.Push(1.1);
    stack3.Push(3.14);

    //Printing data from each stack
    stack1.Print();
    stack2.Print();
    stack3.Print();

    //Checking the sizes of each stack again
    cout << stack1.GetSize() << endl;
    cout << stack2.GetSize() << endl;
    cout << stack3.GetSize() << endl;

    //Popping data from each stack
    stack1.Pop();
    stack2.Pop();
    stack3.Pop();

    //Printing data from each stack again
    stack1.Print();
    stack2.Print();
    stack3.Print();

    //Checking the sizes of each stack yet again
    cout << stack1.GetSize() << endl;
    cout << stack2.GetSize() << endl;
    cout << stack3.GetSize() << endl;

    //Checking if the stacks ar empty again
    if (stack1.IsEmpty())
    {
        cout << "Stack 1 is empty" << endl;
    }
    else
    {
        cout << "Stack 1 is NOT empty" << endl;
    }
    if (stack2.IsEmpty())
    {
        cout << "Stack 2 is empty" << endl;
    }
    else
    {
        cout << "Stack 2 is NOT empty" << endl;
    }
    if (stack3.IsEmpty())
    {
        cout << "Stack 3 is empty" << endl;
    }
    else
    {
        cout << "Stack 3 is NOT empty" << endl;
    }

    //Using the copy constructor to copy stack1
    TemplatedStack<int> stack1Copy = TemplatedStack<int>(stack1);
    stack1Copy.Print();
    stack1Copy.Push(54);
    stack1Copy.Print();

    //Using the copy assignment operator to copy stack2
    TemplatedStack<char> stack2Copy = stack2;
    stack2Copy.Print();
    stack2Copy.Pop();
    stack2Copy.Print();

    //Deleting the stacks
    stack1.~TemplatedStack();
    stack2.~TemplatedStack();
    stack3.~TemplatedStack();
    stack1Copy.~TemplatedStack();
    stack2Copy.~TemplatedStack();



    // ----- Extra Credit -----
    TemplatedStack<Test> testStack = TemplatedStack<Test>();
    testStack.Print();

    Test myTest1 = Test();
    testStack.Push(myTest1);
    testStack.Print();

    Test myTest2 = Test(19);
    testStack.Push(myTest2);
    testStack.Print();


    //Checking for Memory Leaks
    _CrtDumpMemoryLeaks();
}
