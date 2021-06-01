CC = gcc
OBJS = multixor.o xorlib.o strXor.o
EXEC = multixor
DEBUG = -g
CFLAGS = -std=c99 -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@ -lpthread

multixor.o: multixor.c xorlib.h strXor.h
xorlib.o: xorlib.c xorlib.h strXor.h
strXor.o: strXor.c strXor.h

clean:
	rm -f $(EXEC) $(OBJS)
