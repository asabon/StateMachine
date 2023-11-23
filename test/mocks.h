#ifndef MOCKS_H
#define MOCKS_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C" {
int state10_entry(void);
int state10_do(int * pNext);
int state10_exit(void);
int state11_entry(void);
int state11_do(int * pNext);
int state11_exit(void);
}

class Mocks {
    public:
        MOCK_METHOD0(state10_entry, int());
        MOCK_METHOD1(state10_do,    int(int *));
        MOCK_METHOD0(state10_exit,  int());
        MOCK_METHOD0(state11_entry, int());
        MOCK_METHOD1(state11_do,    int(int *));
        MOCK_METHOD0(state11_exit,  int());
};

#endif /* MOCKS_H */
