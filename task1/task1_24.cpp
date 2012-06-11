/*
 * Task 1_24.
 * Using only bit operations, write a function that swaps the places
 * groups of 8 bits in unsigned long integer number
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

// Swap every eight bits of number
ULI SwapEightBits(ULI number)
{
	ULI n1;
	ULI n2;
	
	n1 = number & 0xFF00FF00;
	n2 = number & 0x00FF00FF;
	
	return (n1 >> 8) | (n2 << 8);
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

	result = SwapEightBits(number);

	cout << "Result (dec): " << result << endl;
	cout << "(bin): ";
	ShowDecAsBin(result);
	cout << endl;

	getch();

	return 0;
}

