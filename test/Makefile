CC = gcc
SRCS = test.c \
       ../src/statemachine.c
OBJS = $(SRCS:.c=.o)
INC = -I../src
TARGET = test

$(TARGET): $(OBJS)
	$(CC) $(INC) -o $(TARGET) $(OBJS)

.c.o:
	$(CC) $(INC) -c $<
