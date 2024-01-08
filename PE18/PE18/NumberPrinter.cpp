#include "NumberPrinter.h"
#include <iostream>
#include <mutex>
using namespace std;

NumberPrinter::NumberPrinter(int num)
{
	number = num;
}

void NumberPrinter::Print(mutex* mtx)
{
	//Using mutex to lock the threads to keep them from jumbling together
	mtx->lock();
	for (int count = 0; count < 50; count++)
	{
		cout << number << " ";
	}
	cout << endl;
	mtx->unlock();
}
