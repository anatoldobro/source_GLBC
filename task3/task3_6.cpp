/**
 * @file task3_6.cpp
 * @brief Develop a function that sorts array of real numbers in
 *        order of increasing values of elements. Based on the develop function
 *        to sort in order of increasing values of the elements of each
 *        row of the matrix of real numbers.
 *
 * Copyright 2012 by Anatoliy Dobrosynets
 */

#include "stdafx.h"
#include <iostream>

using namespace std;

// Max count rows in the matrix
const int R = 10;

// Max count columns in the matrix
const int C = 10;

/**
 * @brief This function sorts array of real numbers
 * @param [in, out] m Array of float pointer
 * @param [in] l Real length of arrays
 * @return void
 */
void Sort(float* m, int l)
{
	float t;

	for(int i = l - 1; i > 0; i--)
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
	float m[R][C];
	
	// Real size of the matrix
	int r,c;
	int i,j;
	
	// Check for correct input
	while(true)
	{
		cout << "Enter size of the matrix (rows <= " << R;
		cout << " and columns <= " << C << "):\n";
	
		cin >> r;
		cin >> c;
		
		if(cin.good() && (r > 0) && (r <= R) && (c > 0) && (c <= C))	// No error
		{
			cin.ignore(100, '\n');	// Delete separator lines
			break;
		}
		
		cin.clear();	// Clear the bit error
		cout << "Invalid input!!!" << endl;
		cin.ignore(100, '\n');
	}

	for (i = 0; i < r; i++)
	{
		cout << "Enter " << i + 1 << " row:\n";
		for (j = 0; j < c; j++)
		{
			
			// Check for correct input
			while(true)
			{
				cout << "Enter [" << i << " " << j <<"] element: ";
				cin >> m[i][j];
		
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
	}

	cout << "\nResult:\n";
	
	for (i = 0; i < r; i++)
	{
		cout << endl << i + 1 << "row:\t";

		Sort(m[i], c);

		for (j = 0; j < c; j++)
		{
			cout << m[i][j] << "; ";
		}
	}
	
	cout << endl;

	cin.get();
	
	return 0;
}

