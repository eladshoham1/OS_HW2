CC = gcc
OBJS = multixor.o xorlib.o AllStrings.o
EXEC = multixor
DEBUG = -g
CFLAGS = -std=c99 -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@ -lpthread

multixor.o: multixor.c xorlib.h AllStrings.h
xorlib.o: xorlib.c xorlib.h AllStrings.h
AllStrings.o: AllStrings.c AllStrings.h

clean:
	rm -f $(EXEC) $(OBJS)

