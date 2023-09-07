#ifndef STD_H_INCLUDED
#define STD_H_INCLUDED


//Data types declaration
typedef unsigned char uint8;
typedef char int8;
typedef unsigned short uint16;
typedef short int16;
typedef unsigned int uint32;

//Boolean enum definition:
typedef enum {False, True} bool;

//Error List:
typedef enum {
    WRONG_CHOICE,
    WRONG_INPUTDATA,
    FULL_DATABASE,
    NOT_FOUND,
    REPEATED_ID,
    REPEATED_COURSE_ID,
    EMPTY_DATABASE,
    STUDENT_YEAR_OUT_OF_RANGE,
    STUDENT_ID_OUT_OF_RANGE,
    COURSE_GRADE_OUT_OF_RANGE,
    COURSE_ID_OUT_OF_RANGE}Error;
/*
 WRONG_CHOICE: When the user selects an incorrect option
FULL_DATABASE: When the database has reached its maximum capacity
NOT_FOUND: When a specific data cannot be located after a database search
REPEATED_ID: When two students share the same ID
REPEATED_COURSE_ID: When two courses have identical IDs for the same student
EMPTY_DATABASE: When an action is performed on an empty database
STUDENT_YEAR_OUT_OF_RANGE: When the student's year falls outside the allowed range
STUDENT_ID_OUT_OF_RANGE: When the student's ID is outside the specified range
COURSE_GRADE_OUT_OF_RANGE: When the course grade is beyond the acceptable range
COURSE_ID_OUT_OF_RANGE: When the course ID is outside the defined range
*/

//Database Options:
typedef enum {
    EXIT ,
    ADD_ENTRY,
    GET_USED_SIZE,
    READ_STUDENT_DATA ,
    GET_STUDENTS_ID_LIST,
    CHECK_ID ,
    DELETE_STUDENT_DATA ,
    CHECK_DATABASE_FULL} Option;

#endif // STD_H_INCLUDED
