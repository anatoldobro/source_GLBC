/**
 * @file task1_1.cpp
 * @brief Using only bit and arithmetic operations, write a function
 *        that returns the next even number for unsigned long integer number.
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
	int m[sizeof(ULI) * 8];
	int i = 0;

	while(n > 1)
	{
		m[i] = n % 2;
		n = n / 2;
		i++;
	}

	m[i] = n;

	for (int j = i; j >= 0 ; j--)
	{
		cout << m[j];
	}
}

/**
 * @brief This function calculates next even number
 * @param [in] n unsigned long int number
 * @return next even number
 */
ULI GetNextEvenNumber(ULI n)
{
	return (n & ~0x1) + 0x2;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ULI n;
	ULI r;

	// Check for correct input
	while(true)
	{
		cout << "Enter unsigned integer number (dec): ";
		cin >> n;
		
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
	
	ShowDecAsBin(n);
	
	cout << endl;

	r = GetNextEvenNumber(n);

	cout << "The next even number is (dec): " << r << endl;
	cout << "(bin): ";
	
	ShowDecAsBin(r);
	
	cout << endl;

	cin.get();

	return 0;
}

