#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fonctions.h"



/*________________________________________________________________________________________*/



void initialisation(Acteurs* acteurs)
{
	SDL_Surface *tmp2;
	

	tmp2 = SDL_LoadBMP("stage1.bmp");
	acteurs->backg = SDL_DisplayFormat(tmp2);
	SDL_FreeSurface(tmp2);
	acteurs->camera.x = 0;
	acteurs->camera.y = 0;
	acteurs->camera.w = SCREEN_WIDTH;
	acteurs->camera.h = SCREEN_HEIGHT;
}



/*________________________________________________________________________________________*/



/*---fonction d initialisation de l ennmy---*/

void initializeEnnmy(Ennmy* ennmy)
{
	SDL_Surface* tmp  , *tmp1  ;

	tmp = IMG_Load("sprite_ennmy_right.png");
	ennmy->sprite = SDL_DisplayFormat(tmp);
	SDL_FreeSurface(tmp);
	SDL_SetColorKey(ennmy->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(ennmy->sprite->format, 255, 255, 255));



	tmp1 =IMG_Load("v.png");
	ennmy->life_bar = SDL_DisplayFormat(tmp1);
	SDL_FreeSurface(tmp1);
	SDL_SetColorKey(ennmy->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(ennmy->life_bar->format, 255, 255, 255));


	//Indique l'état et la direction de notre ennmy
	ennmy->direction = RIGHT;
	ennmy->etat = IMMOBILE;

	//Réinitialise le timer de l'animation et la frame
	ennmy->frame_timer = TIME_BETWEEN_2_FRAMES;
	ennmy->frame_number = 0;

	/* Coordonnées de démarrage de notre héros */
	ennmy->x = 0 ;
	ennmy->y =300 ;

	ennmy->x_life_bar = 0 ;
	ennmy->y_life_bar = 0 ;
	ennmy->w_life_bar = LIFE_BAR_WIDTH ;
	ennmy->h_life_bar = LIFE_BAR_HEIGHT ;

	
	ennmy->vies = 5 ;

}



/*________________________________________________________________________________________*/



/*---fontion pour afficher l'hero ---*//////////////////////////

void drawEnnmy(Ennmy ennmy , Acteurs *acteurs)
{

/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = ennmy.x - acteurs->camera.x;
dest.y = ennmy.y ;





SDL_Rect frame;
frame.x = ennmy.frame_number*PLAYER_WIDTH;
frame.y = 0;
frame.w = PLAYER_WIDTH;
frame.h = PLAYER_HEIGHT;


/* Blitte notre héros sur l'écran aux coordonnées x et y */
SDL_BlitSurface(acteurs->backg, &acteurs->camera, acteurs->screen, NULL);
SDL_BlitSurface(ennmy.sprite , &frame , acteurs->screen , &dest) ;
SDL_SetColorKey(ennmy.sprite, SDL_SRCCOLORKEY, SDL_MapRGB(ennmy.sprite->format, 255, 255, 255));





}


/*________________________________________________________________________________________*/



/*---fonction de deplacement de l ennmy---*/

void updatePlayer(Ennmy* ennmy , Acteurs* acteurs)
{	
	
	ennmy->PLAYER_SPEED=12 ;




	if(acteurs->event.type == SDL_KEYDOWN)
	{
		if(acteurs->event.key.keysym.sym == SDLK_RIGHT || acteurs->event.key.keysym.sym == SDLK_SPACE)
		{



			if (acteurs->event.key.keysym.sym == SDLK_SPACE )
			{

			ennmy->PLAYER_SPEED += PLAYER_ACCELERATION ;

			}	


			if(ennmy->etat == IMMOBILE || ennmy->etat == WALK_LEFT)
			{
				ennmy->etat = WALK_RIGHT;
			}
			if(ennmy->direction == LEFT)
				{
					ennmy->direction = RIGHT ;
				}
			ennmy->sprite = IMG_Load("sprite_ennmy_right.png") ;
			SDL_SetColorKey(ennmy->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(ennmy->sprite->format, 255, 255, 255));
			

			ennmy->x += ennmy->PLAYER_SPEED;
			//hero->x_life_bar += ennmy->PLAYER_SPEED; 



		}


		else if(acteurs->event.key.keysym.sym == SDLK_LEFT )
		{   
			
			if(ennmy->etat == IMMOBILE || ennmy->etat == WALK_RIGHT)
			{
				ennmy->etat = WALK_LEFT;
			}
			if(ennmy->direction == RIGHT)
				{
					ennmy->direction = LEFT ;
				}
			ennmy->sprite = IMG_Load("sprite_ennmy_left.png") ;
			SDL_SetColorKey(ennmy->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(ennmy->sprite->format, 255, 255, 255));
			ennmy->x -= ennmy->PLAYER_SPEED ;

			

		}
	} 

/*
    if(acteurs->event.key.keysym.sym == SDLK_UP)
	
		{
ennmy->sprite =IMG_Load("sprite_ennmy_right.png") ;
			SDL_SetColorKey(ennmy->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(ennmy->sprite->format, 255, 255, 255));
			ennmy->y -= ennmy->PLAYER_SPEED;

	} 
 
if(acteurs->event.key.keysym.sym == SDLK_DOWN)
	
		{ 

ennmy->sprite = IMG_Load("sprite_ennmy_right.png") ;
			SDL_SetColorKey(ennmy->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(ennmy->sprite->format, 255, 255, 255));
			ennmy->y += ennmy->PLAYER_SPEED;	}*/}

/*________________________________________________________________________________________*/


//fonction pour annimer l'ennmy

void animationennmy(Ennmy* ennmy, Acteurs acteurs)
{
	if(acteurs.event.type == SDL_KEYDOWN)
	{
		if(acteurs.event.key.keysym.sym == SDLK_LEFT || acteurs.event.key.keysym.sym == SDLK_RIGHT || acteurs.event.key.keysym.sym == SDLK_SPACE)
		{
			if(ennmy->frame_timer <= 0)
			{
				ennmy->frame_number++;
				SDL_Delay(15);
			if(ennmy->frame_number > MAXF-1)
				ennmy->frame_number = 0;
			}
		else
		ennmy->frame_timer--;
		SDL_Delay(15);

		}
	}
	
	if(acteurs.event.type == SDL_KEYUP)
	{
		if(ennmy->direction == RIGHT)
		{
			ennmy->frame_number = 0;
		}
		else if(ennmy->direction == LEFT)
		{
			ennmy->frame_number = MAXF-1;
		}
	}
}





/*________________________________________________________________________________________*/



void draw_life_bar(Ennmy *ennmy  , Acteurs *acteurs)
{

/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = ennmy->x_life_bar - acteurs->camera.x;
dest.y = ennmy->y_life_bar ;



/* Blitte notre enemy sur l'écran aux coordonnées x et y */

SDL_BlitSurface(ennmy->life_bar , NULL , acteurs->screen , &dest) ;
SDL_SetColorKey(ennmy->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(ennmy->life_bar->format, 255, 255, 255));
SDL_Delay(15);
	
}



/*________________________________________________________________________________________*/


