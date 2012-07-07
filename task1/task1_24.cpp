/**
 * @file task1_24.cpp
 * @brief Using only bit operations, write a function that swaps the places
 *        groups of 8 bits in unsigned long integer number
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
 * @brief This function swaps every eight bits of number
 * @param [in] n unsigned long int number
 * @return swap the places groups of 8 bits in number
 */
ULI SwapEightBits(ULI n)
{
	ULI n1;
	ULI n2;
	
	n1 = n & 0xFF00FF00;
	n2 = n & 0x00FF00FF;
	
	return (n1 >> 8) | (n2 << 8);
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

	r = SwapEightBits(n);

	cout << "Result (dec): " << r << endl;
	cout << "(bin): ";
	
	ShowDecAsBin(r);
	
	cout << endl;

	cin.get();

	return 0;
}

