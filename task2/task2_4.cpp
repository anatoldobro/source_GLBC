/**
 * @file task2_4.cpp
 * @brief With the keyboard to enter a set of structures in the form <Key> <Data>.
 *        Sort entered records in ascending key. In the sorted array of type 
 *        2 new records so that the total ordering of the array. Print the resulting array.
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
 * @brief This struct includes data: <Key>, <Data>
 *
 * Copyright 2012 by Anatoliy Dobrosynets
 */
struct Record
{
	char k[M];
	char d[M];
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
		cout << "\nEnter the key of the " << i + 1 << " record: ";
		gets(m[i].k);
		
		cout << "Enter the data of the " << i + 1 << " record: ";
		gets(m[i].d);
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
			if(strcmp(m[j].k, m[j + 1].k) > 0)
			{
				t = m[j];
				m[j] = m[j + 1];
				m[j + 1] = t;
			}
		}
	}
}

/**
 * @brief This function inserts struct Record to sorted array of struct Record
 * @param [in, out] m Array of struct Record pointer
 * @param [in] n Real count of records
 * @param [in] r struct Record pointer
 * @return int
 */
int Insert(Record* m, int n, Record* r)
{
	for (int i = 0; i < n; i++)
	{
		if(strcmp(m[i].k, r->k) > 0)
		{
			for(int j = n; j > i; j--)
			{
				m[j] = m[j - 1];
			}

			m[i] = *r;
			return n + 1;
		}
	}

	m[n] = *r;
	return n + 1;	
}

/**
 * @brief This function outputs array of struct Record
 * @param [in, out] m Array of struct Record pointer
 * @param [in] n Real count of records
 * @return void
 */
void Output(Record* m, int n)
{
	cout << "\nSorted list of records:\n";
	cout << "\n<Key>  |  <Data>\n";

	for(int i = 0; i < n; i++)
	{
		cout << m[i].k << "  |  " << m[i].d << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Record m[N];
	Record r;

	// Real count of records
	int n;
	
	int i;
	
	// Check for correct input
	while(true)
	{
		cout << "Enter count of records (count <= " << N - 2 << "): ";
		cin >> n;
		
		if(cin.good() && (n > 0) && (n <= (N - 2)))	// No error and no signed number
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

	for(i = 0; i < 2; i++)
	{
		cout << "\nEnter the key of " << i + 1 << " new record: ";
		gets(r.k);
		
		cout << "Enter the data of " << i + 1 << " new record: ";
		gets(r.d);
		
		n = Insert(m, n, &r);
	}
	
	Output(m, n);

	cin.get();

	return 0;
}

