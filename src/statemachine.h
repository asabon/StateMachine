/**
 * @file
 */
#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <stdio.h>

typedef struct {
    int stateId;
    int (*pf_Entry)(void);
    int (*pf_Do)(int * pNextState);
    int (*pf_Exit)(void);
} STATE_T;

typedef struct {
    int currentState;
    int nextState;
    int statelen;
    STATE_T * pState;
} STATEMACHINE_T;

extern int statemachine_init(STATEMACHINE_T * pStatemachine, STATE_T * pState, int statelen, int initialState);
extern int statemachine_do(STATEMACHINE_T * pStatemachine);

#endif /* STATEMACHINE_H */
