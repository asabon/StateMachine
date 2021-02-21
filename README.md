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
    result = statemachine_init(&statemachine, statelist);
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
