#include "SDBAPP.h"
#include "UI.h"

extern void SDB_APP()
{
    // Indicating that the program has started
    PrintMessageOnScreen("\n--> Program has started");
    NewLine();

    uint32 Input;
    do
    {
        // Display the options table for the user
        PrintTable();

        // Take user input and store it in the 'Input' variable
        IntegerUserInput(&Input);

        // Perform the appropriate action based on the value in 'Input'
        SBD_Action(Input);

    } while (Input != EXIT); // Continue looping until the user presses 'EXIT'
}

extern void SBD_Action(uint8 Choice)
{
    // This function selects the appropriate action based on the 'Choice' value entered by the user, referring to the options table.

    switch (Choice)
    {
        // Actions:

        // Action 1: Add a new student to the database
        case ADD_ENTRY:
        {
            uint32 ID, Year, Course1ID, Course1Grade, Course2ID, Course2Grade, Course3ID, Course3Grade;

            // User inputs all the student data into these variables
            NewLine();
            PrintMessageOnScreen("--> Enter Student Id: ");
            IntegerUserInput(&ID);

            PrintMessageOnScreen("--> Enter Student Year: ");
            IntegerUserInput(&Year);

            PrintMessageOnScreen("--> Enter Course 1 ID: ");
            IntegerUserInput(&Course1ID);

            PrintMessageOnScreen("-->Enter Course 1 Grade (%): ");
            IntegerUserInput(&Course1Grade);

            PrintMessageOnScreen("--> Enter Course 2 ID: ");
            IntegerUserInput(&Course2ID);

            PrintMessageOnScreen("--> Enter Course 2 Grade (%): ");
            IntegerUserInput(&Course2Grade);

            PrintMessageOnScreen("--> Enter Course 3 ID: ");
            IntegerUserInput(&Course3ID);

            PrintMessageOnScreen("--> Enter Course 3 Grade (%): ");
            IntegerUserInput(&Course3Grade);

            NewLine();

            // Pass the variables to the SDB_AddEntry function for data validation and addition to the database
            if (SDB_AddEntry(ID, Year, Course1ID, Course1Grade, Course2ID, Course2Grade, Course3ID, Course3Grade))
            {
                // If the function returns True (1), the entry has been added successfully
                PrintMessageOnScreen("--> Entry added successfully.");
                NewLine();
                NewLine();
            }

            break;
        }

        // Action 2: Get the number of students in the database
        case GET_USED_SIZE:
            NewLine();
            PrintMessageOnScreen("--> Number of students: ");

            // The SDb_GetUeedSize function returns an integer value, which is passed to the PrintData function for display
            PrintData(SDB_GetUsedSize(), 'd');
            NewLine();
            NewLine();

            break;

        // Action 3: Print a specific student's data
        case READ_STUDENT_DATA:
        {
            uint32 ID;
            NewLine();
            PrintMessageOnScreen("Enter Student ID: ");

            // User enters the student's ID using the IntegerUserInput function from the UI
            IntegerUserInput(&ID);
            NewLine();

            // Pass the ID to the SDB_ReadEntry function, which prints the student's data if the ID exists and returns True or False
            // If the ID doesn't exist, an error type and message are printed
            if (!(SDB_ReadEntry(ID)))
            {
                ErrorMessage(NOT_FOUND);
            }
            break;
        }

        // Action 4: Get a list of student IDs
        case GET_STUDENTS_ID_LIST:
        {
            uint8 Count = 0;

            // Initialize an integer array with zeros
            uint32 IDArray[10] = {0};

            // Pass the variables and array to SDB_GetList, which populates Count with the number of students and fills the array with IDs
            SDB_GetList(&Count, IDArray);

            // Check if Count contains a non-zero value, indicating that the database is not empty
            if (Count)
            {
                // If Count is non-zero, print it along with the ID array
                NewLine();
                PrintMessageOnScreen("--> Count = ");
                PrintData(Count, 'd');
                NewLine();

                PrintMessageOnScreen("--> ID List: ");
                PrintArray(IDArray, Count);

                NewLine();
                NewLine();
            }
            else
            {
                // If Count is zero, the database is empty, and an error message is printed
                ErrorMessage(EMPTY_DATABASE);
            }
            break;
        }

        // Action 5: Check if an ID exists in the database
        case CHECK_ID:
            NewLine();
            PrintMessageOnScreen("Enter Student ID: ");
            uint32 ID;
            IntegerUserInput(&ID);

            // Pass the ID to SDB_IsIdExist, which searches for it and returns either EMPTY (0) or its index
            if (SDB_IsIdExist(ID))
            {
                // If the ID exists, notify the user
                PrintMessageOnScreen("--> ID exists");
                NewLine();
                NewLine();
            }
            else
            {
                // If it doesn't exist, print an error type and message
                ErrorMessage(NOT_FOUND);
            }
            break;

        // Action 6: Delete a specific student from the database
        case DELETE_STUDENT_DATA:
        {
            uint32 ID;

            // Check if the database is empty or not
            if (!SDB_GetUsedSize())
            {
                // If the database is empty, print an error message and type
                ErrorMessage(EMPTY_DATABASE);
                break;
            }

            // If the database is not empty, the user inputs the ID of the student to delete
            PrintMessageOnScreen("Enter Student ID: ");
            IntegerUserInput(&ID);

            // Check if the ID exists or not
            if (SDB_IsIdExist(ID))
            {
                // If it exists, a specific function deletes it from the database
                SDB_DeleteEntry(ID);

                // Notify the user that the process was successful
                NewLine();
                PrintMessageOnScreen("--> Student data deleted successfully.");
                NewLine();
                NewLine();
            }
            else
            {
                // If the ID doesn't exist, print an error message and type
                ErrorMessage(NOT_FOUND);
            }
            break;
        }

        // Action 7: Check if the database is full
        case CHECK_DATABASE_FULL:

            // Call a function that returns True or False
            if (SDB_IsFull())
            {
                // If it's True, print an error type and message
                ErrorMessage(FULL_DATABASE);
            }
            else
            {
                // If it's not full, notify the user
                NewLine();
                PrintMessageOnScreen("--> Database is not full.");
                NewLine();
                NewLine();
            }
            break;

        // Action 8: Delete the database and exit the program
        case EXIT:

            // Call a function to delete the database
            SDB_DeleteDatabase();

            // Notify the user that the program is ending
            NewLine();
            PrintMessageOnScreen("--> The database has been deleted");
            NewLine();
           break;


        default:
        //UI prints an eror messsage that the choice is incorrect entered by the user is incorrect
        ErrorMessage(WRONG_CHOICE);
    }

}
