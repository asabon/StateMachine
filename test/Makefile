CC = gcc

LIBS = ../src/statemachine.a

TEST_SRCS = test.c
TEST_OBJS = $(TEST_SRCS:.c=.o)

INCDIR = -I../src
CFLAGS = -Wall
TARGET = test

$(TARGET): $(TEST_OBJS) $(LIBS)
	make -c ../src
	$(CC) $(CFLAGS) $(INCDIR) -o $(TARGET) $(TEST_OBJS) $(LIBS)
	./test

.c.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $<
