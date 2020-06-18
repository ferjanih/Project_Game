prog: saut.o main.o
	gcc saut.c main.c -o prog -lSDL -lSDL_image 
main.o: main.c
	gcc -c main.c 
rotozoom.o: saut.c
	gcc -c saut.c
	 
