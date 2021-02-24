CC = g++
CXX = g++

TEST_SRCS = test.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

LIBS = -lgtest -lgtest_main -lpthread -lstatemachine

INCDIR = -I../src -Igoogletest-release-1.10.0/googletest/include
CFLAGS = -Wall -Lgoogletest-release-1.10.0/build/lib -L../src
TARGET = test

$(TARGET): $(TEST_OBJS)
	make -C ../src
	$(CC) $(CFLAGS) $(INCDIR) -o $(TARGET) $(TEST_OBJS) $(LIBS)
	./test

.cpp.o:
	$(CXX) $(CFLAGS) $(INCDIR) -c $<

.cc.o:
	$(CXX) $(CFLAGS) $(INCDIR) -c $<

.c.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $<
