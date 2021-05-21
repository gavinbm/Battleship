
all: game.o util.o
	gcc game.o util.o -o bs

game.o: game.c game.h util.c
	gcc -g -c util.c game.c

util.o: util.c game.h
	gcc -g -c util.c

clean:
	rm *.o bs