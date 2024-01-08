#pragma once

#include <iostream>
using namespace std;

template<class dataType>
class TemplatedStack
{
	// ----- Public Data -----
	public:
		//Default Constructor
		TemplatedStack()
		{
			stack = new dataType[1]{};
			currentStack = 0;
			size = 1;
		}

		//Destructor
		~TemplatedStack()
		{
			delete[] stack;
			stack = nullptr;
		}

		//Copy Constructor
		TemplatedStack(const TemplatedStack& otherStack)
		{
			currentStack = otherStack.currentStack;
			size = otherStack.size;
			stack = new dataType[size];

			for (int i = 0; i < currentStack + 1; i++)
			{
				stack[i] = otherStack.stack[i];
			}

			//copy(otherStack.stack, otherStack.stack + currentStack, stack);
		}

		//Copy Assignment Operator
		TemplatedStack& operator=(const TemplatedStack& otherStack)
		{
			if (this == &otherStack)
			{
				return *this;
			}

			if (stack != nullptr)
			{
				delete[] stack;
				stack = nullptr;
				currentStack = 0;
			}

			currentStack = otherStack.currentStack;
			size = otherStack.size;
			stack = new dataType[size];

			for (int i = 0; i < currentStack; i++)
			{
				stack[i] = otherStack.stack[i];
			}

			//copy(otherStack.stack, otherStack.stack + currentStack, stack);

			return *this;
		}

		//Push Method
		void Push(dataType data)
		{
			//If the current 'stack' array is full, a new one is created that is twice as large
			if (currentStack == size)
			{
				//Creating a new array that's twice as large
				dataType* newStack = new dataType[size * 2];
				newStack[currentStack] = data;
				currentStack++;
				size *= 2;

				//Adding all data from the current 'stack' array to the new one
				for (int index = 0; index < currentStack - 1; index++)
				{
					newStack[index] = stack[index];
				}

				//Deleting the old 'stack' array and making the pointer point at the new one instead
				delete[] stack;
				stack = newStack;

				newStack = nullptr;
			}

			//If the 'stack' array isn't full, then the new data is simply added where there is room
			else
			{
				stack[currentStack] = data;
				currentStack++;
			}
		}

		//Pop Method
		dataType Pop()
		{
			//If the stack is empty, this method returns null
			if (currentStack == 0)
			{
				return NULL;
			}

			//Returning the data at the top of the stack
			currentStack--;
			return stack[currentStack];
		}

		//Print Method
		void Print()
		{
			cout << "Current stack contents: ";

			//Printing from the "top" of the stack; printing from the last item in the array
			for (int index = currentStack - 1; index > -1; index--)
			{
				cout << stack[index];

				if (index > 0)
				{
					cout << ", ";
				}
			}

			cout << endl;
		}

		//GetSize Method
		int GetSize()
		{
			//Returns the value of 'currentStack'
			return currentStack;
		}

		//IsEmptyMethod
		bool IsEmpty()
		{
			//Returns false if the size is greater than zero, since that means there is data in the stack
			if (currentStack > 0)
			{
				return false;
			}

			//Returns true if it hasn't returned false already
			return true;
		}



	// ----- Protected Data -----
	protected:
		//'stack' pointer which points at an array
		dataType *stack;

		//'currentStack' variable which keeps track of where the "top" of the stack is
		int currentStack;

		//'size' variable which keeps track of how large the array, which the 'stack' pointer is pointing to, actually is
		int size;
};
