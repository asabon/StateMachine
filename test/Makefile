CC = gcc
CXX = g++

LIBS = ../src/statemachine.a
GTEST = googletest.a

GTEST_SRCS = googletest/gtest_main.cc \
             googletest/gtest-all.cc \
	         googletest/gtest-death-test.cc \
	         googletest/gtest-filepath.cc \
	         googletest/gtest-matchers.cc \
	         googletest/gtest-port.cc \
	         googletest/gtest-printers.cc \
	         googletest/gtest-test-part.cc \
	         googletest/gtest-typed-test.cc \
	         googletest/gtest.cc


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
