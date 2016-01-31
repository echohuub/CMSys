CC=g++
CFLAGS= -Wall -std=c++11 -framework OpenGL -framework GLUT
PROG = tetris
OBJS = main.o Game.o Figure.o Block.o

LIBS= -lglut -lGLU -lGL

all:$(PROG) 

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROG)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Game.o: Game.cpp
	$(CC) $(CFLAGS) -c Game.cpp

Figure.o: Figure.cpp
	$(CC) $(CFLAGS) -c Figure.cpp

Block.o: Block.cpp
	$(CC) $(CFLAGS) -c Block.cpp

clean:
	rm -f $(PROG) $(OBJS)
