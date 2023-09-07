#ifndef SDBAPP_H
#define SDBAPP_H

#include "SDB.h"

/*
  SDB_APP:

  This function contains a main loop that continuously takes user input and passes it to SDB_Action to execute user tasks.
  It features a main loop executed by a do-while() loop, ensuring it runs at least once. This function consistently displays the
  options table for the user during each iteration.
*/
extern void SDB_APP();

/*
  SDB_Action:

  This function receives user input when they select an option from the options table displayed on the screen. It then calls the appropriate action
  function from SDB.h to perform the task. Additionally, it prints indications and invokes the UI to display error messages based on the output of the action functions.
*/
extern void SBD_Action(uint8);

#endif // SDBAPP_H
