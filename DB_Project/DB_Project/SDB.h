#ifndef SDB_H_INCLUDED
#define SDB_H_INCLUDED
#include "STD.h"
#include "UI.h"


//Student struct
typedef struct SimpleDb
{
    uint32 Student_ID;
    uint32 Student_Year;
    uint32 Course1_ID;
    uint32 Course1_Grade;
    uint32 Course2_ID;
    uint32 Course2_Grade;
    uint32 Course3_ID;
    uint32 Course3_Grade;


}Student;


//Database Functions:

/*
  SDB_IsFull

  This function checks if the size of the database has reached the maximum database size defined above or
 not. It returns True = 1 or False = 1
*/
extern bool SDB_IsFull();

/*
  SDB_GetUsedSize

  This function checks if the database size has reached the defined maximum size and returns True (1) or False (0).
*/
extern uint8 SDB_GetUsedSize(void);

/*
  SDB_AddEntry

This function returns the number of students in the database.
*/
extern bool SDB_AddEntry(uint32 , uint32, uint32 ,uint32, uint32, uint32, uint32, uint32 );

/*
  SDB_DeleteEntry

 This function takes input student data, performs validation, and adds them to the database. It returns either True (1) or False (0).
*/
extern void SDB_DeleteEntry(uint32);

/*
  SDB_ReadEntry

This function takes an ID and deletes the student from the database if the ID exists. It returns True (1) or False (0).*/
extern bool SDB_ReadEntry(uint32);

/*
 SDB_GetList

This function takes an ID and prints the student data with that ID if it exists. It returns True (1) or False (0).
 */
extern void SDB_GetList(uint8*, uint32*);

/*
    SDB_IsIDEXist

    This function takes an ID and searches for it in the database. It returns True = 1 or False = 0
*/
extern bool SDB_IsIdExist(uint32);

/*
  SDB_DeleteDatabase

This function is called when the program ends to delete all the data from memory as it is allocated in the heap.
*/
extern void SDB_DeleteDatabase(void);


#endif // SDB_H_INCLUDED
