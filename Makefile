CC = gcc
OBJS = multixor.o xorlib.o allStrings.o
EXEC = multixor
DEBUG = -g
CFLAGS = -std=c99 -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@ -lpthread

multixor.o: multixor.c xorlib.h allStrings.h
xorlib.o: xorlib.c xorlib.h allStrings.h
allStrings.o: allStrings.c allStrings.h

clean:
	rm -f $(EXEC) $(OBJS)
