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
	

	tmp2 = IMG_Load("map.png");
	acteurs->backg = SDL_DisplayFormat(tmp2);
	SDL_FreeSurface(tmp2);
	acteurs->camera.x = 0;
	acteurs->camera.y = 0;
	acteurs->camera.w = SCREEN_WIDTH;
	acteurs->camera.h = SCREEN_HEIGHT;
}



/*________________________________________________________________________________________*/



/*---fonction d initialisation de l hero---*/

void initializeHero(Hero* hero)
{
	SDL_Surface* tmp  , *tmp1 , *tmp3;

	tmp = SDL_LoadBMP("sprite_hero_right.bmp");
	hero->sprite = SDL_DisplayFormat(tmp);
	SDL_FreeSurface(tmp);
	SDL_SetColorKey(hero->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero->sprite->format, 255, 255, 255));



	tmp1 =SDL_LoadBMP("v.bmp");
	hero->life_bar = SDL_DisplayFormat(tmp1);
	SDL_FreeSurface(tmp1);
	SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));


	tmp3 =IMG_Load("s.png");
	hero->score_bar= SDL_DisplayFormat(tmp3);
	SDL_FreeSurface(tmp1);
	SDL_SetColorKey(hero->score_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->score_bar->format,255,255,255));


	//Indique l'état et la direction de notre héros
	hero->direction = RIGHT;
	hero->etat = IMMOBILE;

	//Réinitialise le timer de l'animation et la frame
	hero->frame_timer = TIME_BETWEEN_2_FRAMES;
	hero->frame_number = 0;

	/* Coordonnées de démarrage de notre héros */
	hero->x = 0 ;
	hero->y = 300 ;

	hero->x_life_bar = 14 ;
	hero->y_life_bar = 9 ;
	hero->w_life_bar = LIFE_BAR_WIDTH ;
	hero->h_life_bar = LIFE_BAR_HEIGHT ;

	
	hero->vies = 3 ;

	hero->x_score_bar = 500 ;
	hero->y_score_bar = 9 ;
	hero->w_score_bar = SCORE_BAR_WIDTH ;
	hero->h_score_bar = SCORE_BAR_HEIGHT ;
 	

	hero->scores=3;

}



/*________________________________________________________________________________________*/



/*---fontion pour afficher l'hero ---*//////////////////////////

void drawHero(Hero hero , Acteurs *acteurs)
{

/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = hero.x - acteurs->camera.x;
dest.y = hero.y ;




SDL_Rect frame;
frame.x = hero.frame_number*PLAYER_WIDTH;
frame.y = 0;
frame.w = PLAYER_WIDTH;
frame.h = PLAYER_HEIGHT;


/* Blitte notre héros sur l'écran aux coordonnées x et y */
SDL_BlitSurface(acteurs->backg, &acteurs->camera, acteurs->screen, NULL);
SDL_BlitSurface(hero.sprite , &frame , acteurs->screen , &dest) ;
SDL_SetColorKey(hero.sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero.sprite->format, 255, 255, 255));





}


/*________________________________________________________________________________________*/



/*---fonction de deplacement de l hero---*/

void updatePlayer(Hero* hero , Acteurs* acteurs)
{	
	
	hero->PLAYER_SPEED=12 ;




	if(acteurs->event.type == SDL_KEYDOWN)
	{
		if(acteurs->event.key.keysym.sym == SDLK_RIGHT || acteurs->event.key.keysym.sym == SDLK_SPACE)
		{



			if (acteurs->event.key.keysym.sym == SDLK_SPACE )
			{

			hero->PLAYER_SPEED += PLAYER_ACCELERATION ;

			}	


			if(hero->etat == IMMOBILE || hero->etat == WALK_LEFT)
			{
				hero->etat = WALK_RIGHT;
			}
			if(hero->direction == LEFT)
				{
					hero->direction = RIGHT ;
				}
			hero->sprite = SDL_LoadBMP("sprite_hero_right.bmp") ;
			SDL_SetColorKey(hero->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero->sprite->format, 255, 255, 255));
			

			hero->x += hero->PLAYER_SPEED;
			


		}


		else if(acteurs->event.key.keysym.sym == SDLK_LEFT )
		{   
			
			if(hero->etat == IMMOBILE || hero->etat == WALK_RIGHT)
			{
				hero->etat = WALK_LEFT;
			}
			if(hero->direction == RIGHT)
				{
					hero->direction = LEFT ;
				}
			hero->sprite = SDL_LoadBMP("sprite_hero_left.bmp") ;
			SDL_SetColorKey(hero->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero->sprite->format, 255, 255, 255));
			hero->x -= hero->PLAYER_SPEED ;

			

		}
	} 


  /*  if(acteurs->event.key.keysym.sym == SDLK_UP)
	
		{
hero->sprite = SDL_LoadBMP("sprite_hero_right.bmp") ;
			SDL_SetColorKey(hero->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero->sprite->format, 255, 255, 255));
			hero->y -= hero->PLAYER_SPEED;

	} 
 
if(acteurs->event.key.keysym.sym == SDLK_DOWN)
	
		{ 

hero->sprite = SDL_LoadBMP("sprite_hero_right.bmp") ;
			SDL_SetColorKey(hero->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero->sprite->format, 255, 255, 255));
			hero->y += hero->PLAYER_SPEED;	}*/}



/*________________________________________________________________________________________*/


//fonction pour annimer l'hero

void animationhero(Hero* hero, Acteurs acteurs)
{
	if(acteurs.event.type == SDL_KEYDOWN)
	{
		if(acteurs.event.key.keysym.sym == SDLK_LEFT || acteurs.event.key.keysym.sym == SDLK_RIGHT || acteurs.event.key.keysym.sym == SDLK_SPACE)
		{
			if(hero->frame_timer <= 0)
			{
				hero->frame_number++;
				SDL_Delay(15);
			if(hero->frame_number > MAXF-1)
				hero->frame_number = 0;
			}
		else
		hero->frame_timer--;
		SDL_Delay(15);

		}
	}
	
	if(acteurs.event.type == SDL_KEYUP)
	{
		if(hero->direction == RIGHT)
		{
			hero->frame_number = 0;
		}
		else if(hero->direction == LEFT)
		{
			hero->frame_number = MAXF-1;
		}
	}
}





/*________________________________________________________________________________________*/



void draw_life_bar(Hero *hero  , Acteurs *acteurs)
{

/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = hero->x_life_bar - acteurs->camera.x;
dest.y = hero->y_life_bar ;




 /*Blitte notre hero sur l'écran aux coordonnées x et y */ 

SDL_BlitSurface(hero->life_bar , NULL , acteurs->screen , &dest) ;
SDL_SetColorKey(hero->life_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->life_bar->format, 255, 255, 255));
SDL_Delay(15);
	
}
void draw_score_bar(Hero *hero, Acteurs *acteurs)
{

/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = hero->x_score_bar - acteurs->camera.x;
dest.y = hero->y_score_bar ;




 /*Blitte notre hero sur l'écran aux coordonnées x et y */ 

SDL_BlitSurface(hero->score_bar , NULL , acteurs->screen , &dest) ;
SDL_SetColorKey(hero->score_bar, SDL_SRCCOLORKEY, SDL_MapRGB(hero->score_bar->format, 255, 255, 255));
SDL_Delay(15);

}

