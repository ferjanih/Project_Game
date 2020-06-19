prog:main.o menu.o 
	gcc main.o menu.o -o prog -lSDL -lSDL_ttf -lSDL_mixer -lSDL_image -g
main.o:main.c
	gcc -c main.c -g
enig.o:enig.c
	gcc -c menu.c -g

