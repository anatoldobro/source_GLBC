/**
 * @file task2_7.cpp
 * @brief With the keyboard to enter data set of books in the form
 *        <Author>, <Name>, <Edition>, <Year>. Print a list of books
 *        entered in a table sorting them by years of publications in
 *        descending order. Print information about books on programming in C/C++.
 *
 * Copyright 2012 by Anatoliy Dobrosynets
 */

#include "stdafx.h"
#include <iostream>

using namespace std;

// Max count of books
const int N = 10;

// Max length of the string
const int M = 128;

/**
 * @struct Book
 * @brief This struct includes data: <Author>, <Name>, <Edition>, <Year>
 *
 * Copyright 2012 by Anatoliy Dobrosynets
 */
struct Book
{
	char a[M];
	char n[M];
	char e[M];
	int y;
};

/**
 * @brief This function inputs array of struct Book
 * @param [in, out] m Array of struct Book pointer
 * @param [in] n Real count of books
 * @return void
 */
void Input(Book* m, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << "\nEnter the author of the " << i + 1 << " book: ";
		gets(m[i].a);

		cout << "Enter the name of the " << i + 1 << " book: ";
		gets(m[i].n);

		cout << "Enter the edition of the " << i + 1 << " book: ";
		gets(m[i].e);

		// Check for correct input
		while(true)
		{
			cout << "Enter the year of the " << i + 1 << " book: ";
			cin >> m[i].y;

			if(cin.good() && (m[i].y >= 0))	// No error and no signed number
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
 * @brief This function sorts array of struct Book
 * @param [in, out] m Array of struct Book pointer
 * @param [in] n Real count of books
 * @return void
 */
void Sort(Book* m, int n)
{
	Book t;

	for(int i = n - 1; i > 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			if(m[j].y < m[j + 1].y)
			{
				t = m[j];
				m[j] = m[j + 1];
				m[j + 1] = t;
			}
		}
	}
}

/**
 * @brief This function outputs array of struct Book
 * @param [in, out] m Array of struct Book pointer
 * @param [in] n Real count of books
 * @return void
 */
void Output(Book* m, int n)
{
	cout << "\nSorted list of books:\n";
	cout << "\n<Author>  |  <Name>  |  <Edition>  |  <Year>\n";

	for(int i = 0; i < n; i++)
	{
		cout << m[i].a << "  |  " << m[i].n << "  |  " << m[i].e << "  |  " << m[i].y << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Book m[N];
	
	// Real count of books
	int n;
	
	int i;

	// Check for correct input
	while(true)
	{
		cout << "Enter count of books (count <= " << N << "): ";
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

	cout << "\nList of books  on programming in C/C++:\n";
	cout << "\n<Author>  |  <Name>  |  <Edition>  |  <Year>\n";

	for(i = 0; i < n; i++)
	{
		if(strstr(m[i].n, "C/C++"))
		{
			cout << m[i].a << "  |  " << m[i].n << "  |  " << m[i].e << "  |  " << m[i].y << endl;
		}
	}
	
	cin.get();

	return 0;
}

