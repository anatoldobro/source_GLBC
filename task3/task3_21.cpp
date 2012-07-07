/**
 * @file task3_21.cpp
 * @brief Develop a function that generates a character string corresponding
 *        to the binary code of a given integer. In vector preset sequence entered
 *        from the keyboard as much as natural numbers (a sign of completion - enter "0").
 *        Based on the developed function to print the table numbers and put their binary values.
 *
 * Copyright 2012 by Anatoliy Dobrosynets
 */

#include "stdafx.h"
#include <iostream>

using namespace std;

// Max length of the array
const int L = 128;

/**
 * @brief This function converts a decimal number to binary code in a character string
 * @param [in] n unsigned long int number
 * @param [in, out] s character string pointer 
 * @return char*
 */
char* DecToBin(int n, char* s)
{
	int i;
	int j = 0;
	for(i = sizeof(int) * 8 - 1; i >= 0; i--)
	{
		if(n >> i & 0x1)
		{
			s[j++] = '1';
		}
		else
		{
			s[j++] = '0';
		}
	}
	
	s[j] = '\0';
	
	return s;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int m[L];
	char s[sizeof(int) * 8 + 1];
	int i;

	// Check for correct input
	for(i = 0; i < L; i++)
	{
		cout << "Enter " << i + 1 << " number (count <= " << L << ") or enter \'0\' for finish:\n";
		cin >> m[i];
		
		if(cin.good() && (m[i] > 0))	// No error and no signed number and no zero
		{
			cin.ignore(100, '\n');	// Delete separator lines
			continue;
		}
		else if (m[i] == 0)
		{
			cin.ignore(100, '\n');
			break;
		}
				
		cin.clear();	// Clear the bit error
		cout << "Invalid input!!!" << endl;
		cin.ignore(100, '\n');
		i--;
	}
		
	cout << "Result:\n";

	for(int j = 0; j < i; j++)
	{
		cout << m[j] << ":\t" << DecToBin(m[j], s) << endl;
	}

	cin.get();

	return 0;
}

