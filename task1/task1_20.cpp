/**
 * @file task1_20.cpp
 * @brief Using only bit and arithmetic operations, write a function
 *        that performs cyclic shift unsigned long integer number to r bits left.
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
	{
		cout << (n >> i & 0x1);
	}
}

/**
 * @brief This function makes left cyclic shift bits of number
 * @param [in] n unsigned long int number
 * @param [in] r left shift
 * @return left cyclic shift bits of number
 */
ULI LeftCyclicShift(ULI n, int r)
{
	ULI n1;
	ULI n2;
	
	n1 = n << r;
	n2 = n >> 32 - r;
	
	return n1 | n2;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ULI n;
	int r;
	ULI res;

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

	// Check for correct input
	while(true)
	{
		cout << "Enter left shift: ";
		cin >> r;
		
		if(cin.good() && r >= 0)	// No error and no signed number
		{
			cin.ignore(100, '\n');	// Delete separator lines
			break;
		}
		
		cin.clear();	// Clear the bit error
		cout << "Invalid input!!!" << endl;
		cin.ignore(100, '\n');
	}
	
	res = LeftCyclicShift(n, r);

	cout << "Result (dec): " << res << endl;
	cout << "(bin): ";
	
	ShowDecAsBin(res);
	
	cout << endl;

	cin.get();

	return 0;
}

