/**
 * @file task5_3.cpp
 * @brief Create the library for realization a stack.
 *        Do inverting input sequence of characters.
 *
 * Copyright 2012 by Anatoliy Dobrosynets
 */

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "Stack.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Stack* top = NULL;
	Stack* temp;
	char ch;

	cout << "Enter chars to stack (press Esc or Enter for finish):\n";
		
	while(((ch = getch()) != 27) && (ch != 13))	// ASCII code Esc = 27, ASCII code Enter = 13
	{
		temp = Push(top, ch);
		
		if(temp != top)
		{
			top = temp;
			cout << ch;
		}
		else
		{
			cin.putback(ch);	// Put char back to stream
		}
	}
	
	if (IsEmpty(top))
	{
		cout << "\nThe stack is empty!!!\n";
	}
	else
	{
		cout << "\nInvert chars:\n";
		
		while((ch = TopCh(top)) != 27)	// ASCII code Esc = 27
		{
			cout << ch;
			top = Pop(top);
		}
	}
	
	cin.get();

	return 0;
}

