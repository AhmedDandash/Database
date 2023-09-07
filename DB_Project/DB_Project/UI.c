#include "UI.h"

extern void IntegerUserInput(uint32* input)
{
    scanf(" %d", input);
}

extern void PrintData(uint32 data, int8 type)
{
    // Check if the variable is a decimal or character

    if (type == 'd')
        printf("%d", data);

    if (type == 'c')
        printf("%c", data);
}

extern void PrintMessageOnScreen(int8* MSG)
{
    // Check if the pointer points to the null terminator or not
    while (*MSG)
    {
        // Print the element pointed to by the pointer
        printf("%c", *MSG);

        // Increment the pointer
        MSG++;
    }
}

extern void NewLine(void)
{
    printf("\n");
}

extern void ErrorMessage(uint32 ErrorType)
{
    // Check what type of error the variable holds
    // All error types are described in the STD.h file
    switch (ErrorType)
    {
        case WRONG_CHOICE:
            printf("--> Error type: Invalid choice entered, please try again.\n\n");
            break;

        case WRONG_INPUTDATA:
            printf("--> Error type: Wrong input data, please try again.\n\n");
            break;

        case NOT_FOUND:
            printf("--> Error type: Data not found, please try again.\n\n");
            break;

        case FULL_DATABASE:
            printf("--> Error Type: Database is full; maximum size of %d has been reached. Free some space and try again.\n\n", 10);
            break;

        case EMPTY_DATABASE:
            printf("--> Error type: Database is empty, please add some entries.\n\n");
            break;

        case REPEATED_ID:
            printf("--> Error type: Student ID already exists, please try again.\n\n");
            break;

        case STUDENT_ID_OUT_OF_RANGE:
            printf("--> Error type: Student ID is out of range (%d - %d).\n\n", 1, 1000);
            break;

        case STUDENT_YEAR_OUT_OF_RANGE:
            printf("--> Error type: Student year is out of range (%d - %d).\n\n", 1, 12);
            break;

        case COURSE_ID_OUT_OF_RANGE:
            printf("--> Error type: Course ID is out of range (%d - %d).\n\n", 1, 100);
            break;

        case COURSE_GRADE_OUT_OF_RANGE:
            printf("--> Error type: Course grade is out of range (%d - %d).\n\n", 0, 100);
            break;

        case REPEATED_COURSE_ID:
            printf("--> Error type: Course ID already exists, please try again.\n\n");
            break;

        default:
            printf("--> Error type: No such error type exists, please revise the error passed and try again.\n\n");
            break;
    }
}

extern void PrintArray(uint32* IntegerArray, uint32 Size)
{
    for (uint32 i = 0; i < Size; i++)
    {
        printf("%d", IntegerArray[i]);

        if (i != Size - 1)
        {
            printf(", ");
        }
    }
}

extern void PrintTable(void)
{
    printf("%s\n", "******************************************");
    printf("                Options Table\n");
    printf("%s\n", "******************************************");
    printf("--> To add data to the database                  %d\n", ADD_ENTRY);
    printf("--> To get the used size of the database         %d\n", GET_USED_SIZE);
    printf("--> To read a student's data                     %d\n", READ_STUDENT_DATA);
    printf("--> To get a list of all student IDs             %d\n", GET_STUDENTS_ID_LIST);
    printf("--> To check if an ID exists in the database     %d\n", CHECK_ID);
    printf("--> To delete a student's data from the database %d\n", DELETE_STUDENT_DATA);
    printf("--> To check if the database is full             %d\n", CHECK_DATABASE_FULL);
    printf("--> To exit and delete the database              %d\n", EXIT);
    printf("%s\n", "******************************************\n");
    printf("%s\n", "******************************************");
    printf("--> Your Input: ");
}
