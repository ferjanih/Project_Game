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
  
  Hero hero ;
  
  

   //initialisations
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 1;
    }

 SDL_ShowCursor(SDL_DISABLE);
  
/* appel des fonctions */

acteurs.screen= SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_WM_SetCaption( "The End Of Curse", NULL );

    initializeHero(&hero);
    
    initialisation(&acteurs);
    

    drawHero(hero, &acteurs);
   
    draw_life_bar(&hero  , &acteurs);

    draw_score_bar(&hero  , &acteurs);

int carryon = 1;
while(carryon)
{		


	    

	    if (hero.vies == 0)
	    {

	    carryon=0 ;

	    }

		SDL_PollEvent(&acteurs.event);

		animationhero(&hero, acteurs);
		updatePlayer(&hero , &acteurs) ;

		

		drawHero(hero , &acteurs) ;

		
		
       draw_life_bar(&hero  , &acteurs);
      draw_score_bar(&hero  , &acteurs);
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






