/**
 * @file task3_18.cpp
 * @brief Develop a function that inserts into an array of real numbers,
 *        sorted in order of increasing values of elements, extra number,
 *        keeping the total ordering. Based on the developed function in turn
 *        enter into the specified sorted array of three real numbers. Print the resulting array.
 *
 * Copyright 2012 by Anatoliy Dobrosynets
 */

#include "stdafx.h"
#include <iostream>

using namespace std;

// Max length of the array
const int L = 10;

/**
 * @brief This function insert real number to sorted array of real numbers
 * @param [in, out] m Array of float pointer
 * @param [in] n Real number
 * @param [in] l Real length of arrays
 * @return int
 */
int Insert(float* m, int l, float n)
{
	for (int i = 0; i < l; i++)
	{
		if(m[i] > n)
		{
			for(int j = l; j > i; j--)
			{
				m[j] = m[j-1];
			}

			m[i] = n;
			return l + 1;
		}
	}

	m[l] = n;
	return l + 1;
}

/**
 * @brief This function sorts array of real numbers
 * @param [in, out] m Array of float pointer
 * @param [in] l Real length of arrays
 * @return void
 */

void Sort(float* m, int l)
{
	float t;

	for(int i = l-1; i > 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			if(m[j] > m[j + 1])
			{
				t = m[j];
				m[j] = m[j + 1];
				m[j + 1] = t;
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	float m[L];
	float n;

	// Real length of the array
	int l;
	int i;
	
	// Check for correct input
	while(true)
	{
		cout << "Enter length of the array ( <= " << L - 3 << "): ";
	
		cin >> l;
		
		if(cin.good() && (l > 0) && (l <= (L - 3)))	// No error
		{
			cin.ignore(100, '\n');	// Delete separator lines
			break;
		}
		
		cin.clear();	// Clear the bit error
		cout << "Invalid input!!!" << endl;
		cin.ignore(100, '\n');
	}

	for (i = 0; i < l; i++)
	{
				
		// Check for correct input
		while(true)
		{
			cout << "Enter " << i + 1 << " element: ";
			cin >> m[i];
		
			if(cin.good())	// No error
			{
				cin.ignore(100, '\n');	// Delete separator lines
				break;
			}
				
			cin.clear();	// Clear the bit error
			cout << "Invalid input!!!" << endl;
			cin.ignore(100, '\n');
		}
	}

	Sort(m, l);

	for (i = 0; i < 3; i++)
	{
				
		// Check for correct input
		while(true)
		{
			cout << "Enter " << i + 1 << " real number: ";
			cin >> n;
		
			if(cin.good())	// No error
			{
				cin.ignore(100, '\n');	// Delete separator lines
				
				l = Insert(m, l, n);

				break;
			}
				
			cin.clear();	// Clear the bit error
			cout << "Invalid input!!!" << endl;
			cin.ignore(100, '\n');
		}
	}

	cout << "\nResult:\n";
	
	for (i = 0; i < l; i++)
	{
		cout << m[i] << "; ";
	}
	
	cout << endl;

	cin.get();
	
	return 0;
}

