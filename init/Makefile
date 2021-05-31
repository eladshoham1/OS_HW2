CC = gcc
OBJS = multixor.o
EXEC = multixor
DEBUG = -g
CFLAGS = -std=c99 -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@

multixor.o: multixor.c

clean:
	rm -f $(EXEC) $(OBJS)
