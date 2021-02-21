#include "statemachine.h"

int statemachine_init(STATEMACHINE_T * pStatemachine, STATE_T * pState, int statelen, int initialState)
{
    int result;
    pStatemachine->pState = pState;
    pStatemachine->currentState = initialState;
    pStatemachine->statelen = statelen;
    if (pStatemachine->pState[pStatemachine->nextState].pf_Entry != NULL) {
        result = pStatemachine->pState[initialState].pf_Entry();
        if (result != 0) {
            return result;
        }
    }
    return 0;
}

int statemachine_do(STATEMACHINE_T * pStatemachine)
{
    int result;
    result = pStatemachine->pState[pStatemachine->currentState].pf_Do(&(pStatemachine->nextState));
    if (result != 0) {
        return result;
    }
    if (pStatemachine->currentState != pStatemachine->nextState) {
        if (pStatemachine->pState[pStatemachine->currentState].pf_Exit != NULL) {
            result = pStatemachine->pState[pStatemachine->currentState].pf_Exit();
            if (result != 0) {
                return result;
            }
        }
        if (pStatemachine->pState[pStatemachine->nextState].pf_Entry != NULL) {
            result = pStatemachine->pState[pStatemachine->nextState].pf_Entry();
            if (result != 0) {
                return result;
            }
        }
        pStatemachine->currentState = pStatemachine->nextState;
    }
    return 0;
}
