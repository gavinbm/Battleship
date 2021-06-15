
all: game.o util.o
	gcc game.o util.o -o battleship
	sudo cp battleship /bin

game.o: game.c game.h util.c
	gcc -g -c util.c game.c

util.o: util.c game.h
	gcc -g -c util.c

clean:
	rm *.o battleship
	sudo rm /bin/battleship