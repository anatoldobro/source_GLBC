/**
 * @file task3_8.cpp
 * @brief Develop a function that changes the places corresponding to the number
 *        elements of two vectors of integers the same length.
 *        Based on the developed function to rearrange rows in reverse order
 *        imposed by the integer matrix. Print the resulting matrix.
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
 * @brief This function swaps the places elements of two arrays of integer the same length
 * @param [in, out] m Array of integer
 * @param [in, out] n Array of integer
 * @param [in] r Real length of arrays
 * @return void
 */
void Swap(int m[], int n[], int l)
{
	for (int i = 0; i < l; i++)
		m[i] ^= n[i] ^= m[i] ^= n[i];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int mas[R][C];
	
	// Real size of the matrix
	int r,c;
	int i,j,k;
	
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
			
			// Check for correct input
			while(true)
			{
				cout << "Enter [" << i << " " << j <<"] element: ";
				cin >> mas[i][j];
		
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

	k = i - 1;
	j = 0;

	// Swap the places elements of two vectors
	while (j < k)
	{
		Swap(mas[j], mas[k], c);
		j++;
		k--;
	}

	cout << "\nResult:\n";
	for (i = 0; i < r; i++)
	{
		cout << endl << i + 1 << "row:\t";
		for (j = 0; j < c; j++)
			cout << mas[i][j] << " ";
	}
	
	cin.get();
	
	return 0;
}

