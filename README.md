# statemachine

This is a simple statemachine.

## Example

```
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

- statemachine
    - Statemachine object
    - This object is initialized by statemachine_init() function.
- statelist
    - State list
    - This list have function pointers for each state.
    - Each state has 3 functions.
        - Entry() : This function is called at entry this state.
        - Do()    : This function is called one time.
        - Exit()  : This function is called at exit this state.
