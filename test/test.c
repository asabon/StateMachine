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

int sleep_entry(void)
{
    return 0;
}

int sleep_do(void)
{
    return 0;
}

int sleep_exit(void)
{
    return 0;
}

int active_entry(void)
{
    return 0;
}

int active_do(void)
{
    return 0;
}

int active_exit(void)
{
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
    result = statemachine_init(&statemachine, &&statelist);
    if (result != 0) {
        return -1;
    }
    result = statemachine_do(&statemachine);
    if (result != 0) {
        return -1;
    }
    return 0;
}
