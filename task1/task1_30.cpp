/*
 * Task 1_30.
 * Using only bit operations, write a function that returns 1,
 * if the bits in two positions unsigned long integer number is the same
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

// Compare bit positions in number
ULI CompareBits(ULI number, ULI pos1, ULI pos2)
{
	ULI n1;
	ULI n2;
	
	n1 = number >> pos1 & 0x1;
	n2 = number >> pos2 & 0x1;
	
	return ~(n1 ^ n2) & 0x1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ULI number;
	ULI result;
	ULI pos1;
	ULI pos2;

	cout << "Enter number (dec): ";
	cin >> number;
	
	cout << "(bin): ";
	ShowDecAsBin(number);
	cout << endl;

	cout << "Enter position 1: ";
	cin >> pos1;

	cout << "Enter position 2: ";
	cin >> pos2;

	result = CompareBits(number, pos1, pos2);

	cout << "Result of compare is: " << result << endl;
	
	getch();

	return 0;
}

