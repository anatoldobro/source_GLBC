/**
 * @file task2_8.cpp
 * @brief With the keyboard to enter the sequence data is the coordinates (x, y, z)
 *        points. Print your entries in a table, sorting them in increasing coordinate z.
 *        Identify two points, the distance between which is the smallest.
 *
 * Copyright 2012 by Anatoliy Dobrosynets
 */

#include "stdafx.h"
#include <iostream>

using namespace std;

// Max count of points
const int N = 10;

/**
 * @struct Point
 * @brief This struct includes data: <X>, <Y>, <Z>
 *
 * Copyright 2012 by Anatoliy Dobrosynets
 */
struct Point
{
	float x;
	float y;
	float z;
};

/**
 * @brief This function inputs array of struct Point
 * @param [in, out] m Array of struct Point pointer
 * @param [in] n Real count of points
 * @return void
 */
void Input(Point* m, int n)
{
	for(int i = 0; i < n; i++)
	{
		
		// Check for correct input
		while(true)
		{
			cout << "\nEnter the X coordinate " << i + 1 << " point: ";
			cin >> m[i].x;

			cout << "Enter the Y coordinate " << i + 1 << " point: ";
			cin >> m[i].y;

			cout << "Enter the Z coordinate " << i + 1 << " point: ";
			cin >> m[i].z;

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

/**
 * @brief This function sorts array of struct Point
 * @param [in, out] m Array of struct Point pointer
 * @param [in] n Real count of points
 * @return void
 */
void Sort(Point* m, int n)
{
	Point t;

	for(int i = n - 1; i > 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			if(m[j].z > m[j + 1].z)
			{
				t = m[j];
				m[j] = m[j + 1];
				m[j + 1] = t;
			}
		}
	}
}

/**
 * @brief This function outputs array of struct Point
 * @param [in, out] m Array of struct Point pointer
 * @param [in] n Real count of points
 * @return void
 */
void Output(Point* m, int n)
{
	cout << "\nSorted list of Points:\n";
	cout << "\n<X>  |  <Y>  |  <Z>\n";

	for(int i = 0; i < n; i++)
	{
		cout << m[i].x << "  |  " << m[i].y << "  |  " << m[i].z << endl;
	}
}

/**
 * @brief This function calculates distance between points
 * @param [in, out] p1 struct Point pointer
 * @param [in, out] p2 struct Point pointer
 * @return double
 */
double Distance(Point* p1, Point* p2)
{
	return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2) + pow(p1->z - p2->z, 2)); 
}

int _tmain(int argc, _TCHAR* argv[])
{
	Point m[N];
	
	// Real count of points
	int n;
	
	int i, j;
	
	int i1 = 0;
	int i2 = 1;
	
	double d;
	double t;

	// Check for correct input
	while(true)
	{
		cout << "Enter count of points (count <= " << N << "): ";
		cin >> n;
		
		if(cin.good() && (n > 1) && (n <= N))	// No error and no signed number
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

	d = Distance(m, m + 1);

	for(i = 0; i < n - 1; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			t = Distance(m + i, m + j);

			if(t < d)
			{
				d = t;
				i1 = i;
				i2 = j;
			}
		}
	}

	cout << "\nThe smallest distance is between the following points:\n";
	cout << "\n<X>  |  <Y>  |  <Z>\n";
	cout << m[i1].x << "  |  " << m[i1].y << "  |  " << m[i1].z << endl;
	cout << m[i2].x << "  |  " << m[i2].y << "  |  " << m[i2].z << endl;

	cin.get();

	return 0;
}

