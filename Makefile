prog: rotozoom.o main.o
	gcc rotozoom.c main.c -o prog -lSDL -lSDL_image -lSDL_gfx  -g
main.o: main.c
	gcc -c main.c  -g
rotozoom.o: rotozoom.c
	gcc -c rotozoom.c -g

	 
