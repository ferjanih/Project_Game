#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "time.h"
#include "test.h"

void initialiser_entite_secondaire ( entite_sc *E )
{

 E->img=NULL;

 E->pos.x=100;
 E->pos.y=100;


 // Sur l'axe X
 E->pos_alea_max_x=300;
 E->pos_alea_min_x=500;

 // Sur l'axe Y
 E->pos_alea_max_y=250;
 E->pos_alea_min_y=430;


}



void afficher_entite_secondaire ( SDL_Surface * screen , entite_sc *e )
{

 e->img=IMG_Load("img.png");

 SDL_BlitSurface(e->img,NULL,screen,&(e->pos)) ;
 SDL_Flip(screen);

}


int collision( entite_sc E, SDL_Rect b)
{
	if(!(E.pos.x > b.x+b.w || E.pos.y > b.y+b.h || E.pos.x+E.pos.w < b.x || E.pos.y+E.pos.h < b.y)){
	return 1;}

	return 0;
}


int Collision_Bounding_Box( entite_sc E , SDL_Rect pos_perso )
{
 
 E.pos.w=E.img->w;
 E.pos.h=E.img->h;

 int collision;

            if((pos_perso.x + pos_perso.w <= E.pos.x)||(pos_perso.x >= E.pos.x + E.pos.w)||(pos_perso.y + pos_perso.h <= E.pos.y)||(pos_perso.y >= E.pos.y + E.pos.h))

                collision=0;

            else

                collision=1; // pas de collision


 return (collision);

}



int deplacement_aleatoire (int positionmax,int positionmin)
{

int pos;

srand(time(NULL));

pos=rand()%(positionmax-positionmin+1)+positionmin;


 return pos;

}

	
   
