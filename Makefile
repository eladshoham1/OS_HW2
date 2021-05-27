CC = gcc
OBJS = multixor.o xorlib.o
EXEC = multixor
DEBUG = -g
CFLAGS = -std=c99 -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@ -lpthread

multixor.o: multixor.c xorlib.h
xorlib.o: xorlib.c xorlib.h

clean:
	rm -f $(EXEC) $(OBJS)

