/**
* @file saut.c
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "saut.h"
/**
* @brief saut d'un perso
* @author salma abk
* @date  07/06/2020
* @param fond : backg
* @param perso : image 
*/
void saut()
{
    //Init de la SDL
    SDL_Init( SDL_INIT_VIDEO );

    // On crée une fenêtre
    SDL_Surface* ecran = SDL_SetVideoMode(640, 480, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);

    // On charge le fond
    SDL_Surface* fond = IMG_Load("fond.png");

    //On charge Perso
    SDL_Surface* perso = IMG_Load("perso.png");

    // La position du fond
    SDL_Rect posFond;
    posFond.x = 0;
    posFond.y = 0;

    // La position absolue de Perso
    SDL_Rect posPersoAbs;
    posPersoAbs.x = 200;
    posPersoAbs.y = 300-(perso->h);

    // La position relative de Perso
    SDL_Rect posPersoRel;
    posPersoRel.x = -50;
    posPersoRel.y = 0;

    // Boucle principale du programme
    int fin = 0;
    while (!fin)
    {
        // Gestion des evenements
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                // Quand on ferme la fenetre
            case SDL_QUIT:
                fin = 1;
                break;

                // Quand on appuie sur une touche
            case SDL_KEYDOWN:
                {
                    // ECHAP
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        fin = 1;
                    break;
                }
            }
        }

        // EVOLUTION
            //On avance de 1
            posPersoRel.x++;

            if(posPersoRel.x>=50)
            {
                posPersoRel.x=-50;
            }

            //On met à "0" les pos abs:
            posPersoAbs.x = 200;
            posPersoAbs.y = 300-(perso->h);

            //On calcule la valeur relative de y:
            posPersoRel.y=(-0.04*(posPersoRel.x*posPersoRel.x)+100);

            //On calcule maintenant les valeurs abs
            posPersoAbs.x = posPersoAbs.x + posPersoRel.x+50;
            posPersoAbs.y = posPersoAbs.y - posPersoRel.y;

        //Intervalle de 10ms
        SDL_Delay(10);

        // FIN EVOLUTION

        // DESSIN

        // On vide l'ecran
        SDL_FillRect(ecran, 0, SDL_MapRGB(ecran->format, 0, 0, 0));

        // On dessine les images aux positions respectives
        SDL_BlitSurface(fond, 0, ecran, &posFond);
        SDL_BlitSurface(perso, 0, ecran, &posPersoAbs);

        // FIN DESSIN

        // Et on oublie pas de rafraichir l'image !
        SDL_Flip(ecran);
    }

    // Soulageons la memoire !
    SDL_FreeSurface(fond);
    SDL_FreeSurface(perso);

    SDL_Quit();

}
