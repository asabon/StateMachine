#include <stdio.h>
#include "statemachine.h"

int init_entry(void)
{
    return 0;
}

int init_do(void)
{
    return 0;
}

int init_exit(void)
{
    return 0;
}

int main(void)
{
    int result;
    STATEMACHINE_T statemachine;
    STATE_T statelist[] = {
        {0, init_entry, init_do, init_exit},
        {1, init_entry, init_do, init_exit}
    };
    result = statemachine_init(&statemachine, statelist);
    if (result != 0) {
        return -1;
    }
    result = statemachine_do(&statemachine);
    if (result != 0) {
        return -1;
    }
    return 0;
}
