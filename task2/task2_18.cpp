/**
 * @file task2_18.cpp
 * @brief With the keyboard to enter the sequence data with the results
 *        of the teams this week: <Day> <Plan> <Output>.
 *        Print your entries in a table, sorting them in order of growth plan.
 *        Identify the days of highest and lowest percentages of the plan.
 *
 * Copyright 2012 by Anatoliy Dobrosynets
 */

#include "stdafx.h"
#include <iostream>

using namespace std;

// Max count of records
const int N = 7;

// Max length of the string
const int M = 128;

/**
 * @struct Record
 * @brief This struct includes data: <Day>, <Plan>, <Output>
 *
 * Copyright 2012 by Anatoliy Dobrosynets
 */
struct Record
{
	char d[M];
	int p;
	int o;
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
		cout << "\nEnter the " << i + 1 << " day: ";
		gets(m[i].d);

		// Check for correct input
		while(true)
		{
			cout << "Enter the plan of the " << i + 1 << " day: ";
			cin >> m[i].p;

			if(cin.good() && (m[i].p > 0))	// No error and no signed number
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
			cout << "Enter the output of the " << i + 1 << " day: ";
			cin >> m[i].o;

			if(cin.good() && (m[i].o >= 0))	// No error and no signed number
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
			if(m[j].p > m[j + 1].p)
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
	cout << "\nSorted list of production:\n";
	cout << "\n<Day>  |  <Plan>  |  <Output>\n";

	for(int i = 0; i < n; i++)
	{
		cout << m[i].d << "  |  " << m[i].p << "  |  " << m[i].o << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Record m[N];
	
	// Real count of records
	int n;
	
	int i;
	int i1 = 0;
	int i2 = 0;

	// Check for correct input
	while(true)
	{
		cout << "Enter count of days (count <= " << N << "): ";
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

	if(n == 1)
	{
		cout << "\nThe day of highest and lowest percentages of the plan:\n";
		cout << "\n<Day>  |  <Plan>  |  <Output>\n";
		cout << m[0].d << "  |  " << m[0].p << "  |  " << m[0].o << endl;
	}
	else
	{
		for(i = 1; i < n; i++)
		{
			if((100 * m[i].o / m[i].p) > (100 * m[i1].o / m[i1].p))
			{
				i1 = i;
			}
			else if((100 * m[i].o / m[i].p) < (100 * m[i2].o / m[i2].p))
			{
				i2 = i;
			}
		}

		cout << "\nThe day of highest percentages of the plan:\n";
		cout << "\n<Day>  |  <Plan>  |  <Output>\n";
		cout << m[i1].d << "  |  " << m[i1].p << "  |  " << m[i1].o << endl;
		
		cout << "\nThe day of lowest percentages of the plan:\n";
		cout << "\n<Day>  |  <Plan>  |  <Output>\n";
		cout << m[i2].d << "  |  " << m[i2].p << "  |  " << m[i2].o << endl;
	}

	cin.get();

	return 0;
}

