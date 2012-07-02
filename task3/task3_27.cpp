/**
 * @file task3_27.cpp
 * @brief Develop a function that removes from the specified character string
 *        all digit characters and returns the number of deleted digits.
 *        Enter a sequence of character strings. Using the developed function
 *        to print all lines entered without numbers.
 *        Indicate with that line removed most characters.
 *
 * Copyright 2012 by Anatoliy Dobrosynets
 */

#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

// Max count strings
const int C = 10;

// Max length of the string
const int L = 128;

/**
 * @brief This function removes from the specified character string all numeric characters
 * @param [in, out] s Array of char
 * @return int The number of deleted digits
 */
int DelDig(char* s)
{
	char s1[L];
	char *p,*q;
	int k = 0;
	int n = 0;

	p = s;
	q = s1;
	while (*p != '\0')
	{
		if ((*p >= '0') && (*p <= '9'))
		{
			k++;
			p++;
		}
		else
		{
			*q++ = *p++;
			n++;
		}
	}
	*q = '\0';
	n++;
	memcpy(s, s1, n);
	
	return k;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char str[C][L];

	
	// Real coun of the strings
	int c;
	int i,j;
	int k = 0;
	int max = 0;
	int imax = 0;
	
	// Check for correct input
	while(true)
	{
		cout << "Enter count of the strings (count <= " << C << "):\n";
		cin >> c;
		
		if(cin.good() && (c > 0) && (c <= C))	// No error
		{
			cin.ignore(100, '\n');	// Delete separator lines
			break;
		}
		cin.clear();	// Clear the bit error
		cout << "Invalid input!!!" << endl;
		cin.ignore(100, '\n');
	}
	
	for (i = 0; i < c; i++)
	{
		cout << "\nEnter " << i + 1 << " string:\n";
		gets(str[i]);
	}
	
	cout << "Result:\n";

	for (i = 0; i < c; i++)
	{
		k = DelDig(str[i]);
		cout<< "\n" << i+1 << ". "<< str[i];
		if (k > max)
		{
			max = k;
			imax = i;
		}
	}

	cout << "\nMax count digits (" << max;
	cout << ") deleted in " << imax + 1 << " string\n";

	cin.get();

	return 0;
}

