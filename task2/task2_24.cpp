/**
 * @file task2_24.cpp
 * @brief With the keyboard to enter a sequence of records containing data
 *        on the status of subscription publications:
 *        <Name>, <Index>, <Count of subscribers>. Generate an array of
 *        input and print the data as a table, sorting them by index.
 *        Identify the two most popular publications.
 *
 * Copyright 2012 by Anatoliy Dobrosynets
 */

#include "stdafx.h"
#include <iostream>

using namespace std;

// Max count of records
const int N = 10;

// Max length of the string
const int M = 128;

/**
 * @struct Record
 * @brief This struct includes data: <Name>, <Index>, <Count>
 *
 * Copyright 2012 by Anatoliy Dobrosynets
 */
struct Record
{
	char n[M];
	int i;
	int c;
};

/**
 * @brief This function inputs array of struct Record
 * @param [in, out] m Array of struct Record pointer
 * @param [in] n Real count of records
 * @return void
 */
void Input(Record* m, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << "\nEnter the name of the " << i + 1 << " publication: ";
		gets(m[i].n);

		// Check for correct input
		while(true)
		{
			cout << "Enter the index of the " << i + 1 << " publication: ";
			cin >> m[i].i;

			if(cin.good() && (m[i].i >= 0))	// No error and no signed number
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
			cout << "Enter the count of subscribers of the " << i + 1 << " publication: ";
			cin >> m[i].c;

			if(cin.good() && (m[i].c >= 0))	// No error and no signed number
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

/**
 * @brief This function sorts array of struct Record
 * @param [in, out] m Array of struct Record pointer
 * @param [in] n Real count of records
 * @return void
 */
void Sort(Record* m, int n)
{
	Record t;

	for(int i = n - 1; i > 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			if(m[j].i > m[j + 1].i)
			{
				t = m[j];
				m[j] = m[j + 1];
				m[j + 1] = t;
			}
		}
	}
}

/**
 * @brief This function outputs array of struct Record
 * @param [in, out] m Array of struct Record pointer
 * @param [in] n Real count of records
 * @return void
 */
void Output(Record* m, int n)
{
	cout << "\nSorted list of publications:\n";
	cout << "\n<Name>  |  <Index>  |  <Count>\n";

	for(int i = 0; i < n; i++)
	{
		cout << m[i].n << "  |  " << m[i].i << "  |  " << m[i].c << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Record m[N];
	
	// Real count of records
	int n;
	
	int i;
	int i1 = 0;
	int i2 = 1;

	// Check for correct input
	while(true)
	{
		cout << "Enter count of publications (count <= " << N << "): ";
		cin >> n;
		
		if(cin.good() && (n > 0) && (n <= N))	// No error and no signed number
		{
			cin.ignore(100, '\n');	// Delete separator lines
			break;
		}
		
		cin.clear();	// Clear the bit error
		cout << "Invalid input!!!" << endl;
		cin.ignore(100, '\n');
	}

	Input(m, n);

	Sort(m, n);

	Output(m, n);

	cout << "\nList of the two most popular publications:\n";
	cout << "\n<Name>  |  <Index>  |  <Count>\n";

	if(n == 1)
	{
		cout << m[0].n << "  |  " << m[0].i << "  |  " << m[0].c << endl;
	}
	else
	{
		for(i = 1; i < n; i++)
		{
			if(m[i].c > m[i1].c)
			{
				i2 = i1;
				i1 = i;
			}
			else if(m[i].c > m[i2].c)
			{
				i2 = i;
			}
		}

		cout << m[i1].n << "  |  " << m[i1].i << "  |  " << m[i1].c << endl;
		cout << m[i2].n << "  |  " << m[i2].i << "  |  " << m[i2].c << endl;
	}

	cin.get();

	return 0;
}

