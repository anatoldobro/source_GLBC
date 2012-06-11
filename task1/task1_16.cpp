/*
 * Task 1_16.
 * Using only bit and arithmetic operations, write a function that returns
 * unsigned long integer number that contains bits of length n,
 * starting from position p (bits numbered from 0 from right to left)
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

// Get bits of number
ULI GetBits(ULI number, ULI p, ULI n)
{
	return (number >> (p + 1 - n)) & ~(~0 << n);
}

int _tmain(int argc, _TCHAR* argv[])
{
	ULI number;
	ULI p;
	ULI n;
	ULI result;

	cout << "Enter number (dec): ";
	cin >> number;
	
	cout << "(bin): ";
	ShowDecAsBin(number);
	cout << endl;

	cout << "Enter position: ";
	cin >> p;

	cout << "Enter length: ";
	cin >> n;

	result = GetBits(number, p, n);

	cout << "Result (dec): " << result << endl;
	cout << "(bin): ";
	ShowDecAsBin(result);
	cout << endl;

	getch();

	return 0;
}

