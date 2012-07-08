/**
 * @file task2_2.cpp
 * @brief With the keyboard to enter the sequence data is the coordinates of 
 *        opposite vertices of rectangles. Print your entries in a table,
 *        sorting them in ascending left the x rectangle. Identify two rectangles
 *        with the largest and the smallest square.
 *
 * Copyright 2012 by Anatoliy Dobrosynets
 */

#include "stdafx.h"
#include <iostream>

using namespace std;

// Max count of rectangles
const int N = 10;

/**
 * @struct Rectangle
 * @brief This struct includes data: <X left top>, <Y left top>, <X right bottom>, <Y right bottom>
 *
 * Copyright 2012 by Anatoliy Dobrosynets
 */
struct Rectangle
{
	float xl;
	float yl;
	float xr;
	float yr;
};

/**
 * @brief This function inputs array of struct Rectangle
 * @param [in, out] m Array of struct Rectangle pointer
 * @param [in] n Real count of rectangles
 * @return void
 */
void Input(Rectangle* m, int n)
{
	for(int i = 0; i < n; i++)
	{
		
		// Check for correct input
		while(true)
		{
			cout << "\nEnter the X left top " << i + 1 << " rectangle: ";
			cin >> m[i].xl;

			cout << "Enter the Y left top " << i + 1 << " rectangle: ";
			cin >> m[i].yl;

			cout << "Enter the X right bottom " << i + 1 << " rectangle: ";
			cin >> m[i].xr;

			cout << "Enter the Y right bottom " << i + 1 << " rectangle: ";
			cin >> m[i].yr;

			if(cin.good() && (m[i].xl != m[i].xr) && (m[i].yl != m[i].yr))	// No error
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
 * @brief This function sorts array of struct Rectangle
 * @param [in, out] m Array of struct Rectangle pointer
 * @param [in] n Real count of rectangles
 * @return void
 */
void Sort(Rectangle* m, int n)
{
	Rectangle t;

	for(int i = n - 1; i > 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			if(m[j].xl > m[j + 1].xl)
			{
				t = m[j];
				m[j] = m[j + 1];
				m[j + 1] = t;
			}
		}
	}
}

/**
 * @brief This function outputs array of struct Rectangle
 * @param [in, out] m Array of struct Rectangle pointer
 * @param [in] n Real count of rectangles
 * @return void
 */
void Output(Rectangle* m, int n)
{
	cout << "\nSorted list of Rectangles:\n";
	cout << "\n<X left top>  |  <Y left top>  |  <X right bottom>  |  <Y right bottom>\n";

	for(int i = 0; i < n; i++)
	{
		cout << m[i].xl << "  |  " << m[i].yl << "  |  " << m[i].xr << "  |  " << m[i].yr << endl;
	}
}

/**
 * @brief This function calculates square of struct Rectangle
 * @param [in, out] r struct Rectangle pointer
 * @return double
 */
double Square(Rectangle* r)
{
	return fabs(r->xr - r->xl) * fabs(r->yl - r->yr);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Rectangle m[N];
	
	// Real count of rectangles
	int n;
	
	int i;
	
	int i1 = 0;
	int i2 = 0;

	double s1;
	double s2;
	double t;

	// Check for correct input
	while(true)
	{
		cout << "Enter count of rectangles (count <= " << N << "): ";
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
		cout << "\nThe rectangle with the largest and the smallest square:\n";
		cout << "\n<X left top>  |  <Y left top>  |  <X right bottom>  |  <Y right bottom>\n";
		cout << m[0].xl << "  |  " << m[0].yl << "  |  " << m[0].xr << "  |  " << m[0].yr << endl;
	}
	else
	{
		s1 = s2 = Square(m);
		
		for(i = 1; i < n; i++)
		{
			t = Square(m + i);

			if(t > s1)
			{
				s1 = t;
				i1 = i;
			}
			else if(t < s2)
			{
				s2 = t;				
				i2 = i;
			}
		}

		cout << "\nThe rectangle with the largest square:\n";
		cout << "\n<X left top>  |  <Y left top>  |  <X right bottom>  |  <Y right bottom>\n";
		cout << m[i1].xl << "  |  " << m[i1].yl << "  |  " << m[i1].xr << "  |  " << m[i1].yr << endl;
		
		cout << "\nThe rectangle with the smallest square:\n";
		cout << "\n<X left top>  |  <Y left top>  |  <X right bottom>  |  <Y right bottom>\n";
		cout << m[i2].xl << "  |  " << m[i2].yl << "  |  " << m[i2].xr << "  |  " << m[i2].yr << endl;
	}

	cin.get();

	return 0;
}

