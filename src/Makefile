CC = gcc
AR = ar
RANLIB = ranlib
SRCS = statemachine.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall
LIB = statemachine.a

$(LIB): $(OBJS)
	$(AR) r $(LIB) $(OBJS)
	$(RANLIB) $(LIB)

.c.o:
	$(CC) $(CFLAGS) -c $<
