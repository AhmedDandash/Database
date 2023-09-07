#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED


/*
  This file contains the linked list implementation. I chose the single linked list data structure as it provides an easy
 approach when deleting data and also as it uses the heap and can have undeetermined size precompiling
*/
#include <stdlib.h>
#include "SDB.h"
#define EMPTY 0

typedef struct Node
{
    Student Data ;
    struct Node* NextPtr;
}Node_t;

/*
Initializes the head pointer to make sure it points yo NULL
*/
extern void LinkedListInit(Node_t**);

/*
  Takes the student object and list head and inserts the Node in the end
*/
extern void AddData(Node_t**, Student*);

/*
  Returns the number of nodes in the linked list
*/
extern uint32 GetListSize(Node_t*);

/*
Searches the List for a specific ID passed
*/
extern uint32 SearchList(Node_t*, uint32);

/*
 Delete all Nodes
*/
extern void DeleteList(Node_t**);

/*
 Prints Node data
*/
extern void PrintNodeData(Node_t*, uint32);

/*
 Returns student ID
*/
extern uint32 GetStudentData(Node_t*, uint32);

extern void DeleteByIndex(Node_t**Head,uint32 ID);


#endif // LINKEDLIST_H_INCLUDED
