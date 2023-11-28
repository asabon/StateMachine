#include "gtest/gtest.h"
#include "statemachine.h"

/* ===== Mock codes ===== */
#define STATE_NUM 3
static int state_entry_count[STATE_NUM] = {0};
static int state_entry_result[STATE_NUM] = {0};
static int state_do_count[STATE_NUM] = {0};
static int state_do_next[STATE_NUM] = {0};
static int state_do_result[STATE_NUM] = {0};
static int state_exit_count[STATE_NUM] = {0};
static int state_exit_result[STATE_NUM] = {0};

void init_mock(void)
{
    for (int i = 0; i < STATE_NUM; i++) {
        state_entry_count[i] = 0;
        state_entry_result[i] = 0;
        state_do_count[i] = 0;
        state_do_next[i] = 0;
        state_do_result[i] = 0;
        state_exit_count[i] = 0;
        state_exit_result[i] = 0;
    }
}

int state_entry(int index)
{
    state_entry_count[index]++;
    return state_entry_result[index];
}

int state_do(int index, int * pNextState)
{
    state_do_count[index]++;
    *pNextState = state_do_next[index];
    return state_do_result[index];
}

int state_exit(int index)
{
    state_exit_count[index]++;
    return state_exit_result[index];
}

int state_00_entry(void)             { return state_entry(0); }
int state_00_do   (int * pNextState) { return state_do   (0, pNextState); }
int state_00_exit (void)             { return state_exit (0); }

int state_01_entry(void)             { return state_entry(1); }
int state_01_do   (int * pNextState) { return state_do   (1, pNextState); }
int state_01_exit (void)             { return state_exit (1); }

int state_02_entry(void)             { return state_entry(2); }
int state_02_do   (int * pNextState) { return state_do   (2, pNextState); }
int state_02_exit (void)             { return state_exit (2); }

/* ===== Test codes ===== */

/*
 * Test target    : statemachine_init()
 * Test condition : statelist pointer is NULL.
 */
TEST(statemachine_init, test_statelist_is_null)
{
    int result;
    STATEMACHINE_T statemachine;
    result = statemachine_init(&statemachine, NULL, 0, 0);
    EXPECT_EQ(ERROR_INIT_NULL, result);
}

/*
 * Test target    : statemachine_init()
 * Test condition : statelist has one item but all null functions.
 */
TEST(statemachine_init, test_statelist_has_one_item)
{
    int result;
    STATE_T statelist[] = {
        {NULL, NULL, NULL}
    };
    result = statemachine_init(NULL, statelist, sizeof(statelist)/sizeof(statelist[0]), 0);
    EXPECT_EQ(ERROR_INIT_NULL, result);
}

/*
 * Test target    : statemachine_init()
 * Test condition : statelist has one item but all null functions and length is 0.
 */
TEST(statemachine_init, test_statelist_has_one_item_but_length_is_0)
{
    int result;
    STATEMACHINE_T statemachine;
    STATE_T statelist[] = {
        {NULL, NULL, NULL}
    };
    result = statemachine_init(&statemachine, statelist, 0, 0);
    EXPECT_EQ(ERROR_INIT_NULL, result);
}

/*
 * Test target    : statemachine_init()
 * Test condition : statelist has one item but all null functions and length is 1.
 */
TEST(statemachine_init, test_statelist_has_one_item_and_length_is_1)
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

TEST(statemachine_do, test_do_01)
{
    int result;
    STATEMACHINE_T statemachine;
    STATE_T statelist[] = {
        {state_00_entry, state_00_do, state_00_exit},
        {state_01_entry, state_01_do, state_01_exit},
        {state_02_entry, state_02_do, state_02_exit},
    };
    /* Initialize mock */
    init_mock();
    state_do_next[0] = 1;
    state_do_next[1] = 2;
    state_do_next[2] = 0;
 
    /* Initialize statemachine */
    result = statemachine_init(&statemachine, statelist, sizeof(statelist)/sizeof(statelist[0]), 0);
    EXPECT_EQ(0, result);
    EXPECT_EQ(0, state_entry_count[0]);
    EXPECT_EQ(0, state_do_count[0]);
    EXPECT_EQ(0, state_exit_count[0]);
    EXPECT_EQ(0, state_entry_count[1]);
    EXPECT_EQ(0, state_do_count[1]);
    EXPECT_EQ(0, state_exit_count[1]);
    EXPECT_EQ(0, state_entry_count[2]);
    EXPECT_EQ(0, state_do_count[2]);
    EXPECT_EQ(0, state_exit_count[2]);
    /* Do statemachine */
    state_entry_result[0] = 0;
    state_do_result[0] = 0;
    state_exit_result[0] = 0;
    result = statemachine_do(&statemachine);
    EXPECT_EQ(0, result);
    EXPECT_EQ(1, state_entry_count[0]);
    EXPECT_EQ(1, state_do_count[0]);
    EXPECT_EQ(1, state_exit_count[0]);
    EXPECT_EQ(0, state_entry_count[1]);
    EXPECT_EQ(0, state_do_count[1]);
    EXPECT_EQ(0, state_exit_count[1]);
    EXPECT_EQ(0, state_entry_count[2]);
    EXPECT_EQ(0, state_do_count[2]);
    EXPECT_EQ(0, state_exit_count[2]);
    result = statemachine_do(&statemachine);
    EXPECT_EQ(0, result);
    EXPECT_EQ(0, state_entry_count[0]);
    EXPECT_EQ(0, state_do_count[0]);
    EXPECT_EQ(0, state_exit_count[0]);
    EXPECT_EQ(1, state_entry_count[1]);
    EXPECT_EQ(1, state_do_count[1]);
    EXPECT_EQ(1, state_exit_count[1]);
    EXPECT_EQ(0, state_entry_count[2]);
    EXPECT_EQ(0, state_do_count[2]);
    EXPECT_EQ(0, state_exit_count[2]);
    result = statemachine_do(&statemachine);
    EXPECT_EQ(0, result);
    EXPECT_EQ(0, state_entry_count[0]);
    EXPECT_EQ(0, state_do_count[0]);
    EXPECT_EQ(0, state_exit_count[0]);
    EXPECT_EQ(0, state_entry_count[1]);
    EXPECT_EQ(0, state_do_count[1]);
    EXPECT_EQ(0, state_exit_count[1]);
    EXPECT_EQ(1, state_entry_count[2]);
    EXPECT_EQ(1, state_do_count[2]);
    EXPECT_EQ(1, state_exit_count[2]);
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
