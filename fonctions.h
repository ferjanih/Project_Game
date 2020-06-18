#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#define TIME_BETWEEN_2_FRAMES 20

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define PLAYER_WIDTH 100
#define PLAYER_HEIGHT 200



#define GRAVITY 2

enum{WALK_RIGHT, WALK_LEFT, IMMOBILE, JUMP};

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#define RIGHT 1
#define LEFT 2

#define MAX_FRAMES 6 
#define SPRITE_W 76
#define SPRITE_H 80
#define SPEED 5
#define PLAYER_ACCELERATION 10




#define ENEMY_Height 80
#define ENEMY_Width 76

#define Backg_W 8000
#define Backg_H 600

#define MAXF 3
#define MAXF_ENEMY 6

#define NON 0
#define OUI 1

#define LIFE_BAR_WIDTH 272
#define LIFE_BAR_HEIGHT 86
#define SCORE_BAR_WIDTH 272
#define SCORE_BAR_HEIGHT 86



/*_________   structure numero 1  ____________ */



typedef struct Acteurs Acteurs;
struct Acteurs
{
	  SDL_Surface *screen;
    SDL_Event event ;

	//fond
	SDL_Surface *fond ;
	SDL_Rect posFond;

  //fond noir
  
  SDL_Surface* backg;
  SDL_Rect camera;

};


/*_________   structure de l hero  ____________ */

typedef struct Hero Hero ;
struct Hero 
{

SDL_Surface *sprite;

/* Coordonnées du héros */
Sint16 x , y ;


/* Variables utiles pour l'animation */
int frame_timer, frame_number;
int etat  , direction ; 


int PLAYER_SPEED ;
int vies ; 
int scores;

SDL_Surface *life_bar ;
int x_life_bar , y_life_bar , w_life_bar , h_life_bar ;
SDL_Surface *score_bar;
int x_score_bar , y_score_bar , w_score_bar , h_score_bar ;

};




/* prototypes */
void initialisation(Acteurs* acteurs);

void initializeHero(Hero* hero) ;

void drawHero(Hero hero , Acteurs *acteurs) ;


void updatePlayer(Hero* hero , Acteurs* acteurs) ;

void animationhero(Hero* hero, Acteurs acteurs);


void draw_life_bar(Hero *hero  , Acteurs *acteurs);
void draw_score_bar(Hero *hero, Acteurs *acteurs);

#endif /* FONCTIONS_H_ */
