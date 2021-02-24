CC = gcc
CXX = g++

LIBS = ../src/statemachine.a

TEST_SRCS = test.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

GTEST_OBJS = -lgtest -lgmock -lgmock_main -lgtest_main

INCDIR = -I../src -Igoogletest-release-1.10.0/googletest/include
CFLAGS = -Wall -Lgoogletest-release-1.10.0/build/lib
TARGET = test

$(TARGET): $(TEST_OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(INCDIR) -o $(TARGET) $(TEST_OBJS) $(LIBS) $(GTEST_OBJS)
	./test

$(LIBS):
	make -C ../src

.cpp.o:
	$(CXX) $(CFLAGS) $(INCDIR) -c $<

.cc.o:
	$(CXX) $(CFLAGS) $(INCDIR) -c $<

.c.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $<
