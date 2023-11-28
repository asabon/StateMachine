#include "gtest/gtest.h"
#include "statemachine.h"

/* ===== Mock codes ===== */
static int state_00_entry_count = 0;
static int state_00_entry_result = 0;
static int state_00_do_count = 0;
static int state_00_do_next = 0;
static int state_00_do_result = 0;
static int state_00_exit_count = 0;
static int state_00_exit_result = 0;

void init_mock(void)
{
    state_00_entry_count = 0;
    state_00_entry_result = 0;
    state_00_do_count = 0;
    state_00_do_next = 0;
    state_00_do_result = 0;
    state_00_exit_count = 0;
    state_00_exit_result = 0;
}

int state_00_entry(void)
{
    state_00_entry_count++;
    return state_00_entry_result;
}

int state_00_do(int * pNextState)
{
    state_00_do_count++;
    *pNextState = state_00_do_next;
    return state_00_do_result;
}

int state_00_exit(void)
{
    state_00_exit_count++;
    return state_00_exit_result;
}

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
    };
    /* Initialize mock */
    init_mock();
    /* Initialize statemachine */
    result = statemachine_init(&statemachine, statelist, sizeof(statelist)/sizeof(statelist[0]), 0);
    EXPECT_EQ(0, result);
    EXPECT_EQ(0, state_00_entry_count);
    EXPECT_EQ(0, state_00_do_count);
    EXPECT_EQ(0, state_00_exit_count);
    /* Do statemachine */
    state_00_entry_result = 0;
    state_00_do_result = 0;
    state_00_exit_result = 0;
    result = statemachine_do(&statemachine);
    EXPECT_EQ(0, result);
    EXPECT_EQ(1, state_00_entry_count);
    EXPECT_EQ(1, state_00_do_count);
    EXPECT_EQ(1, state_00_exit_count);
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

static int state_00_entry_result = 0;
int state_00_entry(void)
{
    return state_00_entry_result;
}

static int state_00_do_next = 0;
static int state_00_do_result = 0;
int state_00_do(int * pNextState)
{
    *pNextState = state_00_do_next;
    return state_00_do_result;
}

static int state_00_exit_result = 0;
int state_00_exit(void)
{
    return state_00_exit_result;
}
