[![CI](https://github.com/asabon/statemachine/actions/workflows/ci.yml/badge.svg?branch=main)](https://github.com/asabon/statemachine/actions/workflows/ci.yml)
![Coverage](https://github.com/asabon/StateMachine/blob/badges/badge_linecoverage.svg)

# StateMachine

## Overview

Simple statemachine written by C language.

## Requirement

- C language

## Usage

```
# include "statemachine.h"

int main(void)
{
    STATEMACHINE_T statemachine;
    STATE_T statelist[] = {
        {state00_entry, state00_do, state00_exit},
        {state01_entry, state01_do, state01_exit},
        {state02_entry, state02_do, state02_exit}
    };
    int result;
    result = statemachine_init(&statemachine, statelist, 3, 0);
    if (result != 0) {
        return result;
    }
    while(1) {
        result = statemachine_do(&statemachine);
        if (result != 0) {
            return result;
        }
    }
    return 0;
}
```

StateMachine has following data structure.

- STATEMACHINE_T
    - Statemachine data structure.
    - statemachine_init() initialize this instance.

- STATE_T
    - State data structure.
    - This structure has 3 function pointers.
        - Entry()
            - This function is called at entry this state.
            - int entry (void);
                - return value is error code (0 is successful)
        - Do()
            - int do (int * pNextstate);
                - return value is error code (0 is successful)
                - This function set next state id to pNextstate.
        - Exit()
            - int exit (void);
                - return value is error code (0 is successful)
