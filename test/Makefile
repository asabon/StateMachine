CC = gcc
CXX = g++

LIBS = ../src/statemachine.a
GTEST = googletest.a

GTEST_SRCS = googletest-release-1.10.0/googletest/src/gtest_main.cc \
             googletest-release-1.10.0/googletest/src/gtest-all.cc \
             googletest-release-1.10.0/googletest/src/gtest-death-test.cc \
             googletest-release-1.10.0/googletest/src/gtest-filepath.cc \
             googletest-release-1.10.0/googletest/src/gtest-matchers.cc \
             googletest-release-1.10.0/googletest/src/gtest-port.cc \
             googletest-release-1.10.0/googletest/src/gtest-printers.cc \
             googletest-release-1.10.0/googletest/src/gtest-test-part.cc \
             googletest-release-1.10.0/googletest/src/gtest-typed-test.cc \
             googletest-release-1.10.0/googletest/src/gtest.cc


TEST_SRCS = test.c
TEST_OBJS = $(TEST_SRCS:.c=.o)

INCDIR = -I../src -Igoogletest-release-1.10.0/googletest/include
CFLAGS = -Wall
TARGET = test

$(TARGET): $(TEST_OBJS) $(LIBS) $(GTEST)
	$(CC) $(CFLAGS) $(INCDIR) -o $(TARGET) $(TEST_OBJS) $(LIBS) $(GTEST)
	./test

$(GTEST):
	$(CXX) -o googletest.a $(GTEST_SRCS)

$(LIBS):
	make -C ../src

GTEST = googletest-release-1.10.0/googletest/


.cc.o:
	$(CXX) -c $<


.c.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $<
