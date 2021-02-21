#include "statemachine.h"

int statemachine_init(STATEMACHINE_T * pStatemachine, STATE_T * pState, int initialState)
{
    pStatemachine->pState = pState;
    pStatemachine->currentState = initialState;
    printf ("len = %ld\n", sizeof(pState)/sizeof(STATE_T));
    return 0;
}

int statemachine_do(STATEMACHINE_T * pStatemachine)
{
    return 0;
}
