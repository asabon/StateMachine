#include "statemachine.h"

int statemachine_init(STATEMACHINE_T * pStatemachine, STATE_T * pState[]);
{
    int i;
    for (i = 0; i < sizeof(pState)/sizeof(pState[0]); i++) {
    }
    return 0;
}

int statemachine_do(STATEMACHINE_T * pStatemachine)
{
    return 0;
}
