#ifndef PERFECT_COLLISION_H_DEFINED
#define PERFECT_COLLISION_H_INCLUDED

/**
* @file Perfect_Collision.h
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

/**
* @struct coordinate
* @brief struct for corrdinate
*/
typedef struct 
{

int X;
int Y;

}Coordinate;


int Collision_Parfaite();
//SDL_Color GetPixel(SDL_Surface *background ,Coordinate C);
Uint32 getpixel(SDL_Surface *surface,Coordinate C);


#endif
