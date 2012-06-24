/*
 * Task 3_8.
 * Develop a function that changes the places corresponding to the number
 * elements of two vectors of integers the same length.
 * Based on the developed function to rearrange rows in reverse order
 * imposed by the integer matrix. Print the resulting matrix.
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
	
	do
	{
		cout << "Enter size of the matrix (rows <= " << R;
		cout << " and columns <= " << C << "):\n";
	
		cin >> r;
		cin >> c;
	}
	while ((r <= 0) || (r > R) || (c <= 0) || (c > C));

	for (i = 0; i < r; i++)
	{
		cin.clear();
		cin.sync();

		cout << "Enter " << i + 1 << " row:\t";
		for (j = 0; j < c; j++)
			cin >> mas[i][j];
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
	
	cin.clear();
	cin.sync();
	cin.get();
	
	return 0;
}
