CC = gcc

LIBS = ../src/statemachine.a

TEST_SRCS = test.c
TEST_OBJS = $(TEST_SRCS:.c=.o)

INCDIR = -I../src
CFLAGS = -Wall
TARGET = test

$(TARGET): $(TEST_OBJS) $(LIBS)
	mkdir googletest-release-1.10.0/build; cd build; cmake ..
	$(CC) $(CFLAGS) $(INCDIR) -o $(TARGET) $(TEST_OBJS) $(LIBS)
	./test

$(LIBS):
	make -C ../src

.c.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $<
