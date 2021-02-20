#include <stdio.h>
#include "statemachine.h"

int main(void)
{
    int result;
    STATEMACHINE_T statemachine;
    STATE_T state;
    result = statemachine_init(&statemachine);
    if (result != 0) {
        return -1;
    }
    result = statemachine_add_state(&statemachine, &state);
    if (result != 0) {
        return -1;
    }
    result = statemachine_do(&statemachine);
    if (result != 0) {
        return -1;
    }
    return 0;
}
