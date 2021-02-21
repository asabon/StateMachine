#include <stdio.h>
#include "statemachine.h"

enum {
    INIT = 0,
    SLEEP,
    ACTIVE
};

enum {
    INIT_ENTRY = 0,
    INIT_DO,
    INIT_EXIT,
    SLEEP_ENTRY,
    SLEEP_DO,
    SLEEP_EXIT,
    ACTIVE_ENTRY,
    ACTIVE_DO,
    ACTIVE_EXIT
};

int callcnt[9];

void callcnt_init(void)
{
    int i;
    for(i = 0; i < sizeof(callcnt)/sizeof(callcnt[0]); i++) {
        callcnt[i] = 0;
    }
}

int init_entry(void)
{
    callcnt[INIT_ENTRY]++;
    return 0;
}

int init_do(int * pNextState)
{
    callcnt[INIT_DO]++;
    *pNextState = SLEEP;
    return 0;
}

int init_exit(void)
{
    callcnt[INIT_EXIT]++;
    return 0;
}

int sleep_entry(void)
{
    callcnt[SLEEP_ENTRY]++;
    return 0;
}

int sleep_do(int * pNextState)
{
    callcnt[SLEEP_DO]++;
    *pNextState = ACTIVE;
    return 0;
}

int sleep_exit(void)
{
    callcnt[SLEEP_EXIT]++;
    return 0;
}

int active_entry(void)
{
    callcnt[ACTIVE_ENTRY]++;
    return 0;
}

int active_do(int * pNextState)
{
    callcnt[ACTIVE_DO]++;
    *pNextState = SLEEP;
    return 0;
}

int active_exit(void)
{
    callcnt[ACTIVE_EXIT]++;
    return 0;
}

int main(void)
{
    int result;
    STATEMACHINE_T statemachine;
    STATE_T statelist[] = {
        {0, init_entry,   init_do,   init_exit},
        {1, sleep_entry,  sleep_do,  sleep_exit},
        {2, active_entry, active_do, active_exit}
    };
    result = statemachine_init(&statemachine, statelist, sizeof(statelist)/sizeof(statelist[0]), 0);
    if (result != 0) {
        return -1;
    }
    result = statemachine_do(&statemachine);
    if (result != 0) {
        return -1;
    }
    result = statemachine_do(&statemachine);
    if (result != 0) {
        return -1;
    }
    result = statemachine_do(&statemachine);
    if (result != 0) {
        return -1;
    }
    result = statemachine_do(&statemachine);
    if (result != 0) {
        return -1;
    }
    return 0;
}
