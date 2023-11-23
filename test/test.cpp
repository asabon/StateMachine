//#include "gmock/gmock.h"
#include "gtest/gtest.h"
//#include "mocks.h"
#include "../src/statemachine.h"

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

#if 0
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

    EXPECT_CALL(*mocks, state10_entry()).Times(1).WillRepeatedly(testing::Return(0));
    EXPECT_CALL(*mocks, state10_do(testing::_)).Times(1).WillRepeatedly(testing::DoAll(testing::SetArgPointee<0>(1), testing::Return(0)));
    EXPECT_CALL(*mocks, state10_exit()).Times(1).WillRepeatedly(testing::Return(0));
    EXPECT_CALL(*mocks, state11_entry()).Times(0);
    EXPECT_CALL(*mocks, state11_do(testing::_)).Times(0);
    EXPECT_CALL(*mocks, state11_exit()).Times(0);
    result = statemachine_do(&statemachine);
    EXPECT_EQ(0, result);
}

TEST_F(Test_statemachine_do, test_02)
{
    int result;
    STATEMACHINE_T statemachine;
    STATE_T statelist[] = {
        {NULL, state10_do, state10_exit},
        {NULL, state11_do, state11_exit}
    };

    result = statemachine_init(&statemachine, statelist, sizeof(statelist)/sizeof(statelist[0]), 0);
    EXPECT_EQ(0, result);

    EXPECT_CALL(*mocks, state10_entry()).Times(0);
    EXPECT_CALL(*mocks, state10_do(testing::_)).Times(1).WillRepeatedly(testing::DoAll(testing::SetArgPointee<0>(1), testing::Return(0)));
    EXPECT_CALL(*mocks, state10_exit()).Times(1).WillRepeatedly(testing::Return(0));
    EXPECT_CALL(*mocks, state11_entry()).Times(0);
    EXPECT_CALL(*mocks, state11_do(testing::_)).Times(0);
    EXPECT_CALL(*mocks, state11_exit()).Times(0);
    result = statemachine_do(&statemachine);
    EXPECT_EQ(0, result);
}

TEST_F(Test_statemachine_do, test_03)
{
    int result;
    STATEMACHINE_T statemachine;
    STATE_T statelist[] = {
        {state10_entry, state10_do, NULL},
        {state11_entry, state11_do, NULL}
    };

    result = statemachine_init(&statemachine, statelist, sizeof(statelist)/sizeof(statelist[0]), 0);
    EXPECT_EQ(0, result);

    EXPECT_CALL(*mocks, state10_entry()).Times(1).WillRepeatedly(testing::Return(0));
    EXPECT_CALL(*mocks, state10_do(testing::_)).Times(1).WillRepeatedly(testing::DoAll(testing::SetArgPointee<0>(1), testing::Return(0)));
    EXPECT_CALL(*mocks, state10_exit()).Times(0);
    EXPECT_CALL(*mocks, state11_entry()).Times(0);
    EXPECT_CALL(*mocks, state11_do(testing::_)).Times(0);
    EXPECT_CALL(*mocks, state11_exit()).Times(0);
    result = statemachine_do(&statemachine);
    EXPECT_EQ(0, result);
}

TEST_F(Test_statemachine_do, test_04)
{
    int result;
    STATEMACHINE_T statemachine;
    STATE_T statelist[] = {
        {state10_entry, state10_do, state10_exit},
        {state11_entry, state11_do, state11_exit}
    };

    result = statemachine_init(&statemachine, statelist, sizeof(statelist)/sizeof(statelist[0]), 0);
    EXPECT_EQ(0, result);

    EXPECT_CALL(*mocks, state10_entry()).Times(1).WillRepeatedly(testing::Return(-1));
    EXPECT_CALL(*mocks, state10_do(testing::_)).Times(0);
    EXPECT_CALL(*mocks, state10_exit()).Times(0);
    EXPECT_CALL(*mocks, state11_entry()).Times(0);
    EXPECT_CALL(*mocks, state11_do(testing::_)).Times(0);
    EXPECT_CALL(*mocks, state11_exit()).Times(0);
    result = statemachine_do(&statemachine);
    EXPECT_EQ(-1, result);
}

TEST_F(Test_statemachine_do, test_05)
{
    int result;
    STATEMACHINE_T statemachine;
    STATE_T statelist[] = {
        {state10_entry, state10_do, state10_exit},
        {state11_entry, state11_do, state11_exit}
    };

    result = statemachine_init(&statemachine, statelist, sizeof(statelist)/sizeof(statelist[0]), 0);
    EXPECT_EQ(0, result);

    EXPECT_CALL(*mocks, state10_entry()).Times(1).WillRepeatedly(testing::Return(0));
    EXPECT_CALL(*mocks, state10_do(testing::_)).Times(1).WillRepeatedly(testing::DoAll(testing::SetArgPointee<0>(1), testing::Return(-2)));
    EXPECT_CALL(*mocks, state10_exit()).Times(0);
    EXPECT_CALL(*mocks, state11_entry()).Times(0);
    EXPECT_CALL(*mocks, state11_do(testing::_)).Times(0);
    EXPECT_CALL(*mocks, state11_exit()).Times(0);
    result = statemachine_do(&statemachine);
    EXPECT_EQ(-2, result);
}

TEST_F(Test_statemachine_do, test_06)
{
    int result;
    STATEMACHINE_T statemachine;
    STATE_T statelist[] = {
        {state10_entry, state10_do, state10_exit},
        {state11_entry, state11_do, state11_exit}
    };

    result = statemachine_init(&statemachine, statelist, sizeof(statelist)/sizeof(statelist[0]), 0);
    EXPECT_EQ(0, result);

    EXPECT_CALL(*mocks, state10_entry()).Times(1).WillRepeatedly(testing::Return(0));
    EXPECT_CALL(*mocks, state10_do(testing::_)).Times(1).WillRepeatedly(testing::DoAll(testing::SetArgPointee<0>(1), testing::Return(0)));
    EXPECT_CALL(*mocks, state10_exit()).Times(1).WillRepeatedly(testing::Return(-3));
    EXPECT_CALL(*mocks, state11_entry()).Times(0);
    EXPECT_CALL(*mocks, state11_do(testing::_)).Times(0);
    EXPECT_CALL(*mocks, state11_exit()).Times(0);
    result = statemachine_do(&statemachine);
    EXPECT_EQ(-3, result);
}
#endif
