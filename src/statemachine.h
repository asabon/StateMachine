#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <stdio.h>

typedef struct {
    (void *)pf_Entry(void *);
    (void *)pf_Do(void *);
    (void *)pf_Exit(void *);
} STATE_T;

typedef struct {
    int i;
} STATEMACHINE_T;

extern int statemachine_init(STATEMACHINE_T * pStatemachine);
extern int statemachine_do(STATEMACHINE_T * pStatemachine);

#endif /* STATEMACHINE_H */
