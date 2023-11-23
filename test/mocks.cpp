#include "mocks.h"

Mocks * mocks;

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
