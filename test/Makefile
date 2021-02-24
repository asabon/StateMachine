CC = gcc
CXX = g++

LIBS = ../src/statemachine.a

TEST_SRCS = test.c
TEST_OBJS = $(TEST_SRCS:.c=.o)

GTEST_OBJS = -ltest -lgmock -lgmock_main -lgtest_main

INCDIR = -I../src -Igoogletest-release-1.10.0/googletest/include
CFLAGS = -Wall -Lgoogletest-release-1.10.0/googletest/build/lib
TARGET = test

$(TARGET): $(TEST_OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(INCDIR) -o $(TARGET) $(TEST_OBJS) $(LIBS) $(GTEST_OBJS)
	./test

$(LIBS):
	make -C ../src

.cc.o:
	$(CXX) -c $<


.c.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $<
