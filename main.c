/**
* @file main.c
* @brief Tester programme
* @author Dabbech Mondher
* @version 1.0
* @date Juin 01, 2020
*
* Tester programme pour enigme
*
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enigme.h"
#include <SDL/SDL_ttf.h>
int main()
{ 

	SDL_Surface *screen ;
	SDL_Init ( SDL_INIT_VIDEO ) ;

	screen=SDL_SetVideoMode(858,858,32,SDL_HWSURFACE  |  SDL_DOUBLEBUF  );
	
	char str[128];
	char str1[128];
	SDL_Surface *sur,*sur1;
	SDL_Rect positiontxt;  
	TTF_Font *police=NULL;
	SDL_Color coulerRouge={255,0,0};


	TTF_Init();
	police=TTF_OpenFont("police.ttf",35);




	enigme e;
	int a=0,b=0,i,j,k,solution;
	int running=0;
	int done =1;
	 SDL_Event event;
   

FILE *f ;
 f=fopen("test.txt","a") ;



	 

	 inite(&e,screen);
	afficherenigme(e,screen);
	 while (done)
	 {
	   SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                done = 0;
	        break ;
			
			case SDL_KEYDOWN : 
            switch( event.key.keysym.sym )
                {
			  case  SDLK_r: 
			  {
				  for(i=0;i<2;i++)
				  {
				SDL_BlitSurface(e.bk,NULL,screen,&e.positionecran);
			        j=blitutl(e,screen);
					k=blitpc(e,screen);
					a=a+j;
					b=b+k;
				  }
				  SDL_BlitSurface(e.background2,NULL,screen,&e.positionecran);
sprintf(str,"%8d", a);
sprintf(str1,"%8d", b);
sur=TTF_RenderText_Blended(police,str,coulerRouge);
sur1=TTF_RenderText_Blended(police,str1,coulerRouge);
positiontxt.x=400;
                    positiontxt.y=500;
                    SDL_BlitSurface (sur,NULL,screen,&positiontxt);
positiontxt.x=450;
SDL_BlitSurface (sur1,NULL,screen,&positiontxt);
			  SDL_Flip(screen) ;
			   break ;
			   }
			   case  SDLK_y :
			   {
			   SDL_BlitSurface(e.bk,NULL,screen,&e.positionecran);
			   j=blitutl(e,screen);
			   a=a+j;
			   b=ia(a,b,screen,e);
                           solution=solution_e(a,b);
fprintf(f,"a=%d,b=%d,s=%d\n",a,b,solution) ;
			   resolution (solution,done,screen,e );
			   break;
			   }
			   case  SDLK_n :
			   {
			    b=ia(a,b,screen,e);
			   solution=solution_e(a,b);
fprintf(f,"a=%d,b=%d,s=%d\n",a,b,solution) ;
			   resolution (solution,done,screen,e );
			   break;
			   }
		          
			    
            break ;
		        }
			
	  
			

        }
	}	
 
      SDL_FreeSurface(screen);
      SDL_Quit();
	return 0;
}
