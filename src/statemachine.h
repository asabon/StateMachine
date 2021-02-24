/**
 * @file
 */
#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <stdio.h>

#define ERROR_INIT_NULL (-1)

typedef struct {
    int (*pf_Entry)(void);
    int (*pf_Do)(int * pNextState);
    int (*pf_Exit)(void);
} STATE_T;

/**
 * @brief statemachine structure
 */
typedef struct {
    int currentState; /**< current state */
    int nextState;    /**< next state */
    int statelen;
    int changed;
    STATE_T * pState;
} STATEMACHINE_T;

#ifdef __cplusplus
extern "C" {
#endif
extern int statemachine_init(STATEMACHINE_T * pStatemachine, STATE_T * pState, int statelen, int initialState);
extern int statemachine_do(STATEMACHINE_T * pStatemachine);
#ifdef __cplusplus
}
#endif

#endif /* STATEMACHINE_H */
