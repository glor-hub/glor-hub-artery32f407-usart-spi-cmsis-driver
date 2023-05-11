#include "app.h"
#include "clock.h"
#include "assert.h"

void AppIdleTask(void)
{
}

error_status AppInit(void)
{
    error_status init_result = ERROR;

#ifdef _APP_DEBUG_
    AssertConfig();
#endif//_APP_DEBUG_

    init_result |= ClockInit();
    return init_result;
}
