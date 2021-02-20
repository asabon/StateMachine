#include <stdio.h>
#include "statemachine.h"

int main(void)
{
    int result;
    STATEMACHINE_T statemachine;
    STATE_T state;
    result = statemachine_init(&statemachine);
    result = statemachine_add_state(&statemachine, &state);
    result = statemachine_do(&statemachine);
    return 0;
}
