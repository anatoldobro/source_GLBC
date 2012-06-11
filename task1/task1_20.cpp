/*
 * Task 1_20.
 * Using only bit and arithmetic operations, write a function
 * that performs cyclic shift unsigned long integer number to r bits left
 */

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

typedef unsigned long int ULI;

// Convert a decimal number to binary and show on display
void ShowDecAsBin(ULI number)
{
	int mas[32];
	int count = 0;

	while(number > 1)
	{
		mas[count] = number % 2;
		number = number / 2;
		++count;
	}

	mas[count] = number;

	for (int i = count; i >= 0 ; i--)
		cout << mas[i];
}

// Left cyclic shift bits of number
ULI LeftCyclicShift(ULI number, ULI r)
{
	ULI n1;
	ULI n2;
	
	n1 = number << r;
	n2 = number >> 32 - r;
	
	return n1 | n2;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ULI number;
	ULI r;
	ULI result;

	cout << "Enter number (dec): ";
	cin >> number;
	
	cout << "(bin): ";
	ShowDecAsBin(number);
	cout << endl;

	cout << "Enter left shift: ";
	cin >> r;

	result = LeftCyclicShift(number, r);

	cout << "Result (dec): " << result << endl;
	cout << "(bin): ";
	ShowDecAsBin(result);
	cout << endl;

	getch();

	return 0;
}

