/**
 * @file statemachine.c
 */
#include "statemachine.h"

int statemachine_init(STATEMACHINE_T * pStatemachine, STATE_T * pState, int statelen, int initialState)
{
    if (pStatemachine == NULL) {
        return ERROR_INIT_NULL;
    }
    if (pState == NULL) {
        return ERROR_INIT_NULL;
    }
    if (statelen == 0) {
        return ERROR_INIT_NULL;
    }
    pStatemachine->pState = pState;
    pStatemachine->currentState = initialState;
    pStatemachine->statelen = statelen;
    pStatemachine->changed = 1;
    return 0;
}

int statemachine_do(STATEMACHINE_T * pStatemachine)
{
    int result;
    if (pStatemachine->changed != 0) {
        if (pStatemachine->pState[pStatemachine->currentState].pf_Entry != NULL) {
            result = pStatemachine->pState[pStatemachine->currentState].pf_Entry();
            if (result != 0) {
                return result;
            }
        }
        pStatemachine->changed = 0;
    }
    result = pStatemachine->pState[pStatemachine->currentState].pf_Do(&(pStatemachine->nextState));
    if (result != 0) {
        return result;
    }
    if (pStatemachine->currentState != pStatemachine->nextState) {
        pStatemachine->changed = 1;
        if (pStatemachine->pState[pStatemachine->currentState].pf_Exit != NULL) {
            result = pStatemachine->pState[pStatemachine->currentState].pf_Exit();
            if (result != 0) {
                return result;
            }
        }
        pStatemachine->currentState = pStatemachine->nextState;
    }
    return 0;
}
