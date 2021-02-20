CC = gcc
SRCS = test.c \
       ../src/statemachine.c
OBJS = $(SRCS:.c=.o)
TARGET = test

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

.c.o:
	$(CC) -c $<
