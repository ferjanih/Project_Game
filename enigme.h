/**
* @struct enigme
* @brief struct for enigme
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct
{
SDL_Surface *im1;/*!< Surface. */
SDL_Surface *im2;/*!< Surface. */
SDL_Surface *im3;/*!< Surface. */
SDL_Surface *im4;/*!< Surface. */
SDL_Surface *im5;/*!< Surface. */
SDL_Surface *im6;/*!< Surface. */
SDL_Surface *bk;/*!< Surface. */
SDL_Surface *background1;/*!< Surface. */
SDL_Surface *background2;/*!< Surface. */
SDL_Surface *passed;/*!< Surface. */
SDL_Surface *failed;/*!< Surface. */
SDL_Surface *draw;/*!< Surface. */
SDL_Rect posplayer;/*!< Rectangle*/
SDL_Rect pospc;/*!< Rectangle*/
SDL_Rect positionecran;/*!< Rectangle*/
}enigme;



void inite(enigme *e,SDL_Surface *screen);
void afficherenigme(enigme e,SDL_Surface *screen);
int blitutl(enigme e,SDL_Surface *screen);
int blitpc(enigme e,SDL_Surface *screen);
int ia(int a,int b,SDL_Surface *screen,enigme e);
int solution_e (int a,int b);
void resolution (int solution,int x,SDL_Surface *screen,enigme e );
