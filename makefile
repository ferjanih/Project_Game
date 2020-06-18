enigme:main.o enigme.o 
	gcc   main.o enigme.o -o enigme -lSDL -lSDL_image -lSDL_ttf
main.o:main.c
	gcc -c main.c -g

enigf.o:enigme.c
	gcc -c enigme.c -g 


