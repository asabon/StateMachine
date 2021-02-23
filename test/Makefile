CC = gcc
CXX = g++

LIBS = ../src/statemachine.a
GTEST = googletest.a

GTEST_SRCS = googletest-release-1.10.0/googletest/gtest_main.cc \
             googletest-release-1.10.0/googletest/gtest-all.cc \
             googletest-release-1.10.0/googletest/gtest-death-test.cc \
             googletest-release-1.10.0/googletest/gtest-filepath.cc \
             googletest-release-1.10.0/googletest/gtest-matchers.cc \
             googletest-release-1.10.0/googletest/gtest-port.cc \
             googletest-release-1.10.0/googletest/gtest-printers.cc \
             googletest-release-1.10.0/googletest/gtest-test-part.cc \
             googletest-release-1.10.0/googletest/gtest-typed-test.cc \
             googletest-release-1.10.0/googletest/gtest.cc


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
