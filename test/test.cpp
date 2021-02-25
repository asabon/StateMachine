#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "statemachine.h"

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

TEST(statemachine_init, test_02)
{
    int result;
    STATEMACHINE_T statemachine;
    STATE_T statelist[] = {
        {NULL, NULL, NULL}
    };
    result = statemachine_init(&statemachine, statelist, 0, 0);
    EXPECT_EQ(ERROR_INIT_NULL, result);
}

TEST(statemachine_init, test_03)
{
    int result;
    STATEMACHINE_T statemachine;
    STATE_T statelist[] = {
        {NULL, NULL, NULL}
    };
    result = statemachine_init(&statemachine, statelist, 1, 0);
    EXPECT_EQ(0, result);
    EXPECT_EQ(statelist, statemachine.pState);
    EXPECT_EQ(1, statemachine.statelen);
    EXPECT_EQ(0, statemachine.currentState);
    EXPECT_EQ(1, statemachine.changed);
}

int state00_entry(void)
{
    return 0;
}

int state00_do(int * pNextState)
{
    *pNextState = 1;
    return 0;
}

int state00_exit(void)
{
    return 0;
}

int state01_entry(void)
{
    return 0;
}

int state01_do(int * pNextState)
{
    *pNextState = 0;
    return 0;
}

int state01_exit(void)
{
    return 0;
}

class Mocks {
    public:
        MOCK_METHOD0(state10_entry, int());
        MOCK_METHOD1(state10_do,    int(int * pNext));
        MOCK_METHOD0(state10_exit,  int());
        MOCK_METHOD0(state11_entry, int());
        MOCK_METHOD1(state11_do,    int(int * pNext));
        MOCK_METHOD0(state11_exit,  int());
};

Mocks * mocks;

extern "C" {
int state10_entry(void);
int state10_do(int * pNext);
int state10_exit(void);
int state11_entry(void);
int state11_do(int * pNext);
int state11_exit(void);
}

int state10_entry(void) {
    return mocks->state10_entry();
}

int state10_do(int * pNext) {
    return mocks->state10_do(pNext);
}

int state10_exit(void) {
    return mocks->state10_exit();
}

int state11_entry(void) {
    return mocks->state11_entry();
}

int state11_do(int * pNext) {
    return mocks->state11_do(pNext);
}

int state11_exit(void) {
    return mocks->state11_exit();
}

class Test_statemachine_do : public ::testing::Test {
protected:
    virtual void SetUp() {
        mocks = new Mocks();
    }
    virtual void TearDown() {
        delete mocks;
    }
};

TEST_F(Test_statemachine_do, test_01)
{
    int result;
    STATEMACHINE_T statemachine;
    STATE_T statelist[] = {
        {state10_entry, state10_do, state10_exit},
        {state11_entry, state11_do, state11_exit}
    };

    result = statemachine_init(&statemachine, statelist, sizeof(statelist)/sizeof(statelist[0]), 0);
    EXPECT_EQ(0, result);

    EXPECT_CALL(*mocks, state10_entry()).WillRepeatedly(testing::Return(0));
    EXPECT_CALL(*mocks, state10_do(testing::_)).WillRepeatedly(testing::Return(0)).WillRepeatedly(testing::SetArgPointee<0>(1));
    EXPECT_CALL(*mocks, state10_exit()).WillRepeatedly(testing::Return(0));
    EXPECT_CALL(*mocks, state11_entry()).WillRepeatedly(testing::Return(0));
    EXPECT_CALL(*mocks, state11_do(testing::_)).WillRepeatedly(testing::Return(0)).WillRepeatedly(testing::SetArgPointee<0>(0));
    EXPECT_CALL(*mocks, state11_exit()).WillRepeatedly(testing::Return(0));
    result = statemachine_do(&statemachine);
    EXPECT_EQ(0, result);
}
