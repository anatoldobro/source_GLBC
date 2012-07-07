/**
 * @file task1_30.cpp
 * @brief Using only bit operations, write a function that returns 1,
 *        if the bits in two positions unsigned long integer number is the same
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
 * @brief This function compares bit positions in number
 * @param [in] n unsigned long int number
 * @param [in] p1 position of the bit
 * @param [in] p2 position of the bit
 * @return 1 if bits are same else 0
 */
ULI CompareBits(ULI n, int p1, int p2)
{
	ULI n1;
	ULI n2;
	
	n1 = n >> p1 & 0x1;
	n2 = n >> p2 & 0x1;
	
	return ~(n1 ^ n2) & 0x1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ULI n;
	ULI r;
	int p1;
	int p2;

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
		cout << "Enter position 1: ";
		cin >> p1;
		
		if(cin.good() && p1 >= 0)	// No error and no signed number
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
		cout << "Enter position 2: ";
		cin >> p2;
		
		if(cin.good() && p2 >= 0)	// No error and no signed number
		{
			cin.ignore(100, '\n');	// Delete separator lines
			break;
		}
		
		cin.clear();	// Clear the bit error
		cout << "Invalid input!!!" << endl;
		cin.ignore(100, '\n');
	}
	
	r = CompareBits(n, p1, p2);

	cout << "Result of compare is: " << r << endl;
	
	cin.get();

	return 0;
}

