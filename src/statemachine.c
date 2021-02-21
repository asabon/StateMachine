#include "statemachine.h"

int statemachine_init(STATEMACHINE_T * pStatemachine, STATE_T * pState, int statelen, int initialState)
{
    pStatemachine->pState = pState;
    pStatemachine->currentState = initialState;
    pStatemachine->statelen;
    return 0;
}

int statemachine_do(STATEMACHINE_T * pStatemachine)
{
    return 0;
}
