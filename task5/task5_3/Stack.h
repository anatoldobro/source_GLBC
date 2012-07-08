/**
 * @file Stack.h
 * @brief This file contains source code of task5_3.
 *        It contains  declarations of library functions for a stack.
 *
 * Copyright 2012 by Anatoliy Dobrosynets
 */

#if !defined(STACK_H)
#define STACK_H

/**
 * @struct Stack
 * @brief This struct realizes a stack
 *
 * Copyright 2012 by Anatoliy Dobrosynets
 */
struct Stack
{
	char c;
	struct Stack* n;
};

/**
 * @brief This function makes an empty stack
 * @param [in, out] t struct Stack pointer
 * @return void
 */
void Clear(Stack* t);

/**
 * @brief This function checks is a stack empty
 * @param [in] t struct Stack pointer
 * @return bool
 */
bool IsEmpty(Stack* t);

/**
 * @brief This function pushes element in a stack
 * @param [in, out] t struct Stack pointer
 * @param [in] ch char
 * @return struct Stack pointer
 */
Stack* Push(Stack* t, char ch);

/**
 * @brief This function gets top element of a stack
 * @param [in] t struct Stack pointer
 * @return char
 */
char TopCh(Stack* t);

/**
 * @brief This function deletes top element of a stack
 * @param [in, out] t struct Stack pointer
 * @return struct Stack pointer
 */
Stack* Pop (Stack* t);

#endif /* STACK_H */