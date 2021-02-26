/**
 * @file
 */
#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <stdio.h>

#define ERROR_INIT_NULL (-1)

/**
 * State data structure
 */
typedef struct {
    /**
     * Entry function
     *
     * If no need entry function, set NULL.
     *
     * @retval 0  : Success
     * @retval !0 : Error
     */
    int (*pf_Entry)(void);
    /**
     * Do function
     *
     * @param pNextState Next state id
     * @retval 0  : Success
     * @retval !0 : Error
     */
    int (*pf_Do)(int * pNextState);
    /**
     * Exit function
     *
     * If no need entry function, set NULL.
     *
     * @retval 0  : Success
     * @retval !0 : Error
     */
    int (*pf_Exit)(void);
} STATE_T;

/**
 * Statemachine management data structure
 */
typedef struct {
    int currentState; /**< current state */
    int nextState;    /**< next state */
    int statelen;     /**< state table length */
    int changed;      /**< state changed flag */
    STATE_T * pState; /**< state table pointer */
} STATEMACHINE_T;

#ifdef __cplusplus
extern "C" {
#endif
/**
 * Initialize statemachine structure.
 *
 * @param pStatemachine Pointer of statemachine instance.
 * @param pState        Pointer of state table.
 * @param statelen      Data num of state table.
 * @param initialistate Initial state id. (min: 0, max: statelen - 1)
 */
extern int statemachine_init(STATEMACHINE_T * pStatemachine, STATE_T * pState, int statelen, int initialState);

/**
 * Execute statemachine.
 *
 * @param pStatemachine
 */
extern int statemachine_do(STATEMACHINE_T * pStatemachine);
#ifdef __cplusplus
}
#endif

#endif /* STATEMACHINE_H */
