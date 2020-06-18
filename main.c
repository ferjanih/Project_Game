/**
* @file main.c
* @brief Testing Program
* @author Gamra ben marzouka
* @version 0.1
* @date jun 12, 2020
*
* Testing program for clavier 
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scrolling.h"
#include "Perfect_Collision.h"


int main()
{
SDL_Surface *screen = NULL ;
Objet map,wood,boat,map2,failed,perso;
SDL_Rect pos ;
Coordinate C ;
int running=1,collision3=0,running8=1 ;
SDL_Event event ;
FILE *f ;

 f=fopen("test.txt","a") ;

 screen= SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE|SDL_DOUBLEBUF  );
 
  
  initialiser (&perso,&map ,&wood ,&boat,&map2,&failed) ;
  setup (screen,&map ,&wood,&boat,&map2,&perso) ;

  SDL_EnableKeyRepeat(10, 10);
  while(running){
 evenement (screen ,&boat ,&wood,&map,&running ,&pos,&map2,&perso) ;

      
     }
    free_memory (&boat ,&wood,&map,&map2) ;

    
    fclose(f) ;
    return EXIT_SUCCESS;
}
