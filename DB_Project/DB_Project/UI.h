#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED


/*
  This document manages the interaction between the user and the input/output operations.
   Its role is limited to utilizing the printf() and scanf() functions.
    Additionally,it handles the task of displaying error messages.

*/
#include <stdio.h>
#include "SDB.h"

/*
  IntegerUserInput

This function obtains an integer input from the user and stores it in a variable passed by reference.
*/
extern void IntegerUserInput(uint32*);
/*
  NewLine

This function prints a new line on the screen.
*/
extern void NewLine(void);

/*
  PrintData

this function takes a variable and prints it to the output. You must specify the type format of the variable as 'd' for decimal or 'c' for character.*/

extern void PrintData(uint32, int8);

/*
  PrintMessageOnScreen

This function accepts an array of characters and displays it to the user.
*/
extern void PrintMessageOnScreen(int8*);


/*
  ErrorMessage

This function takes an integer representing an error type and prints the corresponding error message.
*/
extern void ErrorMessage(uint32);


/*
  Print Table

This function prints the options table for the user.
*/
extern void PrintTable(void);
/*
  PrintArray

This function takes an integer array and its size and prints the array on the screen.
*/
extern void PrintArray(uint32* IntegerArray, uint32 Size);

#endif // UI_H_INCLUDED
