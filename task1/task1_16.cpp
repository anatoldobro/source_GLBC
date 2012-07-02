/**
 * @file task1_16.cpp
 * @brief Using only bit and arithmetic operations, write a function that returns
 *        unsigned long integer number that contains bits of length n,
 *        starting from position p (bits numbered from 0 from right to left)
 *
 * Copyright 2012 by Anatoliy Dobrosynets
 */

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef unsigned long int ULI;

/**
 * @brief This function converts a decimal number to binary and shows on display
 * @param [in] n unsigned long int number
 * @return void
 */
void ShowDecAsBin(ULI n)
{
	for(int i = sizeof(ULI) * 8 - 1; i >= 0; i--)
		cout << (n >> i & 0x1);
}

/**
 * @brief This function gets bits of number
 * @param [in] num unsigned long int number
 * @param [in] p position of the block of bits
 * @param [in] n length of the block of bits
 * @return block of bits of number
 */
ULI GetBits(ULI num, int p, int n)
{
	return (num >> (p + 1 - n)) & ~(~0 << n);
}

int _tmain(int argc, _TCHAR* argv[])
{
	ULI num;
	int p;
	int n;
	ULI r;

	// Check for correct input
	while(true)
	{
		cout << "Enter unsigned integer number (dec): ";
		cin >> num;
		
		if(cin.good())	// No error
		{
			cin.ignore(100, '\n');	// Delete separator lines
			break;
		}
		cin.clear();	// Clear the bit error
		cout << "Invalid input!!!" << endl;
		cin.ignore(100, '\n');
	}

	cout << "(bin): ";
	ShowDecAsBin(num);
	cout << endl;

	// Check for correct input
	while(true)
	{
		cout << "Enter position: ";
		cin >> p;
		
		if(cin.good() && p >= 0)	// No error and no signed number
		{
			cin.ignore(100, '\n');	// Delete separator lines
			break;
		}
		cin.clear();	// Clear the bit error
		cout << "Invalid input!!!" << endl;
		cin.ignore(100, '\n');
	}

	// Check for correct input
	while(true)
	{
		cout << "Enter length: ";
		cin >> n;
		
		if(cin.good() && n >= 0)	// No error and no signed number
		{
			cin.ignore(100, '\n');	// Delete separator lines
			break;
		}
		cin.clear();	// Clear the bit error
		cout << "Invalid input!!!" << endl;
		cin.ignore(100, '\n');
	}
	
	r = GetBits(num, p, n);

	cout << "Result (dec): " << r << endl;
	cout << "(bin): ";
	ShowDecAsBin(r);
	cout << endl;

	cin.get();

	return 0;
}

