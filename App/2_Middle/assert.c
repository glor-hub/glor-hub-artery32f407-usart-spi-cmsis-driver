//********************************************************************************
//assert.c
//********************************************************************************

#include "at32f403a_407.h"
#include <stdio.h>
#include <stdbool.h>
#include "assert.h"


//********************************************************************************
//Macros
//********************************************************************************

//********************************************************************************
//Enums
//********************************************************************************


//********************************************************************************
//Typedefs
//********************************************************************************

//********************************************************************************
//Variables
//********************************************************************************


//********************************************************************************
//Prototypes
//********************************************************************************

//================================================================================
//Public
//================================================================================

void TEST_APP_AssertConfig(void)
{
    DEBUGMCU->ctrl_bit.trace_mode = 0x00;
    DEBUGMCU->ctrl_bit.trace_ioen = TRUE;
}

void TEST_APP_AssertFailed(char *func, char *file, uint32_t line)
{
    printf("Assertion failed: expression is false. Function %s in file %s on line %d.\n",
           func, file, line);
}


void TEST_APP_Logger(char *func, char *file, uint32_t line, char *report)
{
    printf("%s. Function %s in file %s on line %d\r\n", report, func, file, line);
}

//================================================================================
//Private
//================================================================================

