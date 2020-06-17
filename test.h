#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>

#ifndef JEUX_H_INCLUDED
#define JEUX_H_INCLUDED

typedef struct{

SDL_Surface * img;
SDL_Rect pos;

int pos_alea_max_x;
int pos_alea_min_x;
int pos_alea_max_y;
int pos_alea_min_y;

}entite_sc;

void initialiser_entite_secondaire ( entite_sc *E );
void afficher_entite_secondaire ( SDL_Surface * screen , entite_sc *e );
int Collision_Bounding_Box( entite_sc E , SDL_Rect pos_perso );
int collision( entite_sc E, SDL_Rect b);
int deplacement_aleatoire ( int positionmax , int positionmin );

#endif // JEUX_H_INCLUDED
