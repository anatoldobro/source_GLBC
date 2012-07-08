/**
 * @file Stack.cpp
 * @brief This file contains source code of task5_3.
 *        It contains  realizations of library functions for a stack.
 *
 * Copyright 2012 by Anatoliy Dobrosynets
 */

#include "stdafx.h"
#include <iostream>
#include "Stack.h"

using namespace std;

void Clear(Stack* t)
{
	Stack* p;
	
	while(t)
	{
		p = t;
		t = t->n;
		
		delete p;
	}
}

bool IsEmpty(Stack* t)
{
	if(t)
	{
		return false;
	}
	
	return true;
}

Stack* Push(Stack* t, char ch)
{
	Stack* p;
	
	try
	{
		p = new Stack;
	}
	catch(bad_alloc)
	{
		return t;
	}
		
	p->c = ch;

	if(t == NULL)
	{
		p->n = NULL;
		t = p;
	}
	else
	{
		p->n = t;
		t = p;
	}
	
	return t;
}

char TopCh(Stack* t)
{
	if(IsEmpty(t))
	{
		return 27;	// ASCII code Esc = 27
	}
	
	return t->c;
}

Stack* Pop (Stack* t)
{
	Stack* p = NULL;

	if(t)
	{
		p = t->n;
		delete t;
	}

	return p;
}