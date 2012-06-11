/*
 * Task 1_1.
 * Using only bit and arithmetic operations, write a function
 * that returns the next even number for unsigned long integer number
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

// Get next even number
ULI GetNextEvenNumber(ULI number)
{
	return (number & ~0x1) + 0x2;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ULI number;
	ULI result;

	cout << "Enter number (dec): ";
	cin >> number;
	
	cout << "(bin): ";
	ShowDecAsBin(number);
	cout << endl;

	result = GetNextEvenNumber(number);

	cout << "Result (dec): " << result << endl;
	cout << "(bin): ";
	ShowDecAsBin(result);
	cout << endl;

	getch();

	return 0;
}

