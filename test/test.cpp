#include <gtest/gtest.h>
#include "statemachine.h"

#if 0
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

int callcnt_check(int ientry, int ido, int iexit, int sentry, int sdo, int sexit, int aentry, int ado, int aexit)
{
    int error_cnt = 0;
    if (callcnt[INIT_ENTRY] != ientry){
        error_cnt++;
    }
    if (callcnt[INIT_DO] != ido){
        error_cnt++;
    }
    if (callcnt[INIT_EXIT] != iexit){
        error_cnt++;
    }
    if (callcnt[SLEEP_ENTRY] != sentry){
        error_cnt++;
    }
    if (callcnt[SLEEP_DO] != sdo){
        error_cnt++;
    }
    if (callcnt[SLEEP_EXIT] != sexit){
        error_cnt++;
    }
    if (callcnt[ACTIVE_ENTRY] != aentry){
        error_cnt++;
    }
    if (callcnt[ACTIVE_DO] != ado){
        error_cnt++;
    }
    if (callcnt[ACTIVE_EXIT] != aexit){
        error_cnt++;
    }
    if (error_cnt != 0) {
        printf ("%d %d %d %d %d %d %d %d %d\n", ientry, ido, iexit, sentry, sdo, sexit, aentry, ado, aexit);
        printf ("%d %d %d %d %d %d %d %d %d\n", callcnt[INIT_ENTRY], callcnt[INIT_DO], callcnt[INIT_EXIT], callcnt[SLEEP_ENTRY], callcnt[SLEEP_DO], callcnt[SLEEP_EXIT], callcnt[ACTIVE_ENTRY], callcnt[ACTIVE_DO], callcnt[ACTIVE_EXIT]);
    }
    return error_cnt;
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
#endif

TEST(statemachine_init, test_00)
{
    int result;
    STATE_T statelist[] = {
        {NULL, NULL, NULL}
    };
    result = statemachine_init(NULL, statelist, sizeof(statelist)/sizeof(statelist[0]), 0);
    EXPECT_EQ(ERROR_INIT_NULL, result);
}

TEST(statemachine_init, test_01)
{
    int result;
    STATEMACHINE_T statemachine;
    result = statemachine_init(&statemachine, NULL, 0, 0);
    EXPECT_EQ(ERROR_INIT_NULL, result);
}

#if 0
int main(void)
{
    int result;
    int errorcnt = 0;
    STATEMACHINE_T statemachine;
    STATE_T statelist[] = {
        {init_entry,   init_do,   init_exit},
        {sleep_entry,  sleep_do,  sleep_exit},
        {active_entry, active_do, active_exit}
    };

    result = statemachine_init(&statemachine, statelist, sizeof(statelist)/sizeof(statelist[0]), 0);
    if (result != 0) {
        printf ("%d\n", __LINE__);
        errorcnt++;
    }
    if (callcnt_check(0, 0, 0, 0, 0, 0, 0, 0, 0) != 0) {
        printf ("%d\n", __LINE__);
        errorcnt++;
    }

    result = statemachine_do(&statemachine);
    if (result != 0) {
        printf ("%d\n", __LINE__);
        errorcnt++;
    }
    if (callcnt_check(1, 1, 1, 0, 0, 0, 0, 0, 0) != 0) {
        printf ("%d\n", __LINE__);
        errorcnt++;
    }

    result = statemachine_do(&statemachine);
    if (result != 0) {
        printf ("%d\n", __LINE__);
        errorcnt++;
    }
    if (callcnt_check(1, 1, 1, 1, 1, 1, 0, 0, 0) != 0) {
        printf ("%d\n", __LINE__);
        errorcnt++;
    }

    result = statemachine_do(&statemachine);
    if (result != 0) {
        printf ("%d\n", __LINE__);
        errorcnt++;
    }
    if (callcnt_check(1, 1, 1, 1, 1, 1, 1, 1, 1) != 0) {
        printf ("%d\n", __LINE__);
        errorcnt++;
    }
    return errorcnt;
}
#endif
