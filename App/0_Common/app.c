//********************************************************************************
//app.c
//********************************************************************************

#include "app.h"
#include "clock.h"
#include "assert.h"
#include "timer.h"
#include "LCD_2004.h"
#include "usart.h"

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

void TEST_APP_AppIdleTask(void)
{
    TEST_APP_USART_cb();
}

error_status TEST_APP_AppInit(void)
{
    error_status init_result = SUCCESS;

#ifdef _TEST_APP_DEBUG_
    TEST_APP_AssertConfig();
#endif//_TEST_APP_DEBUG_
    init_result &= TEST_APP_ClockInit();
    TimerInit();
    TEST_APP_LCD2004_Init();
    init_result &= TEST_APP_USART_Init();
    return init_result;
}

//================================================================================
//Private
//================================================================================
