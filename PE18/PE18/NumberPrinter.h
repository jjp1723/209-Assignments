#pragma once
#include <mutex>
using namespace std;

class NumberPrinter
{
protected:
	int number;

public:
	NumberPrinter(int num);
	void Print(mutex* mtx);
};