CC = gcc
SRCS = test.c
OBJS = $(SRCS:.c=.o)
INC = -I../src
TARGET = test

$(TARGET): $(OBJS)
	$(CC) $(INC) -o $(TARGET) $(OBJS)
	./test

.c.o:
	$(CC) $(INC) -c $<
