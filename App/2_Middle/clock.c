//********************************************************************************
//clock.c
//********************************************************************************

#include "clock.h"
#include "arm_clock.h"

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

error_status ClockInit(void)
{
    uint32_t status, sys_clock;
    crm_sclk_type sclk_source;
    status = ARM_CRM_HEXT_PLL_ClockSourceConfig();
    ARM_CRM_BusClockConfig();
    sclk_source = ARM_CRM_GetClockSourceForSwitch();
    status |= ARM_CRM_SysClockSwitchCmd(sclk_source);
    sys_clock = system_core_clock;
    system_core_clock_update();
    sys_clock = system_core_clock;
    system_core_clock_update();
    return ARM_CRM_isReady(status) ? SUCCESS : ERROR;

}

//================================================================================
//Private
//================================================================================
