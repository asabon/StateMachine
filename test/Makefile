CC = gcc
CXX = g++

LIBS = ../src/statemachine.a

TEST_SRCS = test.c
TEST_OBJS = $(TEST_SRCS:.c=.o)

INCDIR = -I../src -Igoogletest-release-1.10.0/googletest/include
CFLAGS = -Wall
TARGET = test

$(TARGET): $(TEST_OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(INCDIR) -o $(TARGET) $(TEST_OBJS) $(LIBS)
	./test

$(LIBS):
	make -C ../src

GTEST = googletest-release-1.10.0/googletest/


.cc.o:
	$(CXX) -c $<


.c.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $<
