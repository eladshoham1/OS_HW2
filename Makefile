CC = gcc
OBJS = ex2.o xorlib.o strXor.o
EXEC = ex2
DEBUG = -g
CFLAGS = -std=c99 -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@ -lpthread

ex2.o: ex2.c xorlib.h strXor.h
xorlib.o: xorlib.c xorlib.h strXor.h
strXor.o: strXor.c strXor.h

clean:
	rm -f $(EXEC) $(OBJS)
