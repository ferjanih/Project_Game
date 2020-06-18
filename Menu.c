#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fonctions.h"


int main(int argc, char const *argv[])
{
  
  


  Acteurs acteurs;
  
  Ennmy ennmy;
  
  

   //initialisations
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 1;
    }

 SDL_ShowCursor(SDL_DISABLE);
  
/* appel des fonctions */

acteurs.screen= SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_WM_SetCaption( "THE End of Curse", NULL );

    initializeEnnmy(&ennmy);
    
    initialisation(&acteurs);
    

    drawEnnmy(ennmy, &acteurs);
   
    draw_life_bar(&ennmy  , &acteurs);



int carryon = 1;
while(carryon)
{		


	    

	    if (ennmy.vies == 0)
	    {

	    carryon=0 ;

	    }

		SDL_PollEvent(&acteurs.event);

		animationennmy(&ennmy, acteurs);
		updatePlayer(&ennmy , &acteurs) ;

		

		drawEnnmy(ennmy , &acteurs) ;

		
		
        draw_life_bar(&ennmy  , &acteurs);

		SDL_Flip(acteurs.screen);



	switch(acteurs.event.type)
	{
		case SDL_QUIT:
             carryon = 0;
    	case SDL_KEYDOWN:
			if(acteurs.event.key.keysym.sym == SDLK_ESCAPE)
				{
					carryon= 0;
				}
			break;

	}


}




    //LIB
	SDL_Quit();
	return 0 ;

}






