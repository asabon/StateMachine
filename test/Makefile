CC = g++
CXX = g++

TEST_SRCS = test.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

LIBS = -lgtest -lgtest_main -lgmock -lpthread -lstatemachine

INCDIR = -I../src -Igoogletest-release-1.10.0/googletest/include -Igoogletest-release-1.10.0/googlemock/include
CFLAGS = -Wall -Lgoogletest-release-1.10.0/build/lib -L../src -coverage
TARGET = test

$(TARGET): $(TEST_OBJS)
	make -C ../src
	$(CC) $(CFLAGS) $(INCDIR) -o $(TARGET) $(TEST_OBJS) $(LIBS)
	./test -gtest_output "xml"
	gcov -bf ../src/statemachine.c

.cpp.o:
	$(CXX) $(CFLAGS) $(INCDIR) -c $<

.cc.o:
	$(CXX) $(CFLAGS) $(INCDIR) -c $<

.c.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $<
