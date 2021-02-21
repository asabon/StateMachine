#include "statemachine.h"

int statemachine_init(STATEMACHINE_T * pStatemachine, STATE_T * pState, int statelen, int initialState)
{
    int result;
    pStatemachine->pState = pState;
    pStatemachine->currentState = initialState;
    pStatemachine->statelen = statelen;
    result = pStatemachine->pState[initialState].pf_Entry();
    if (result != 0) {
        return result;
    }
    return 0;
}

int statemachine_do(STATEMACHINE_T * pStatemachine)
{
    int i;
    int j;
    int result;
    result = pStatemachine->pState[pStatemachine->currentState].pf_Do(&(pStatemachine->nextState));
    if (result != 0) {
        return result;
    }
    if (pStatemachine->currentState != pStatemachine->nextState) {
        result = pStatemachine->pState[currentState].pf_Exit();
        if (result != 0) {
            return result;
        }
        result = pStatemachine->pState[nextState].pf_Entry();
        if (result != 0) {
            return result;
        }
    }
    return 0;
}
