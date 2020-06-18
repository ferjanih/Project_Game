/**
* @file enigme.c
* @brief Tester programme
* @author Dabbech Mondher
* @version 1.0
* @date Juin 01, 2020
*
* Development des fonctions
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enigme.h"
/**
* @brief Initialisation enigme
* @param e enigme ,screen fenetre  
* @return Rien
*/
void inite(enigme *e,SDL_Surface *screen)
{
	
e->bk=SDL_LoadBMP("background.bmp");
e->background1=SDL_LoadBMP("background1.bmp");
e->background2=SDL_LoadBMP("background2.bmp");

e->im1=SDL_LoadBMP("1.bmp");

e->im2=SDL_LoadBMP("2.bmp");

e->im3=SDL_LoadBMP("3.bmp");

e->im4=SDL_LoadBMP("4.bmp");

e->im5=SDL_LoadBMP("5.bmp");

e->im6=SDL_LoadBMP("6.bmp");
e->passed=IMG_Load("passed.png");
e->failed=IMG_Load("failed.png");
e->draw=IMG_Load("draw.png");
e->positionecran.x=0;
e->positionecran.y=0;
e->positionecran.w=e->bk->w;

e->posplayer.x=200;
e->posplayer.y=500;
e->pospc.x=200;
e->pospc.y=20;

    /*SDL_Surface *texte=NULL;
    SDL_Rect positiontxt;  
    TTF_Font *police=NULL;
    SDL_Color coulerRouge={255,0,0};
	positiontxt.x=20;
    positiontxt.y=500;


    TTF_Init();
    police=TTF_OpenFont("police.ttf",35);*/


}
/**
* @brief affichage enigme
* @param e enigme , screen fenetre
* @return Rien
*/

void afficherenigme(enigme e,SDL_Surface *screen)
{
SDL_BlitSurface(e.background1,NULL,screen,&e.positionecran);
SDL_BlitSurface(e.im6,NULL,screen,&e.posplayer);
SDL_BlitSurface(e.im6,NULL,screen,&e.pospc);
//texte=TTF_RenderText_Blended(police,"press R to roll the dice...",coulerRouge);
SDL_Flip(screen) ;
}
/**
* @brief afficher le nembre de l utilisateur
* @param e enigme , screen fenetre
* @return nembre de l utilisateur
*/
int blitutl(enigme e,SDL_Surface *screen)
{
//	texte=TTF_RenderText_Blended(police," ",coulerRouge);
int alea ;
srand(time(NULL));
alea = 1+ rand()%6;
if(alea==1)
{
	SDL_BlitSurface(e.im1,NULL,screen,&e.posplayer);
}
else if(alea==1)
{
	SDL_BlitSurface(e.im1,NULL,screen,&e.posplayer);
}		
else if(alea==2)
{
	SDL_BlitSurface(e.im2,NULL,screen,&e.posplayer);
}		

else if(alea==3)
{
	SDL_BlitSurface(e.im3,NULL,screen,&e.posplayer);
}		
else if(alea==4)
{
	SDL_BlitSurface(e.im4,NULL,screen,&e.posplayer);
}		
else if(alea==5)
{
	SDL_BlitSurface(e.im5,NULL,screen,&e.posplayer);
}		
else if(alea==6)
{
	SDL_BlitSurface(e.im6,NULL,screen,&e.posplayer);
}		
SDL_Flip(screen) ;
	SDL_Delay(1000);
	return alea;
}
/**
* @brief afficher le nembre de pc
* @param e enigme , screen fenetre
* @return nembre de pc
*/

int blitpc(enigme e,SDL_Surface *screen)
{
int alea ;
srand(time(NULL));
alea = 1+ rand()%6;
if(alea==1)
{
	SDL_BlitSurface(e.im1,NULL,screen,&e.pospc);
}		
else if(alea==2)
{
	SDL_BlitSurface(e.im2,NULL,screen,&e.pospc);
}		

else if(alea==3)
{
	SDL_BlitSurface(e.im3,NULL,screen,&e.pospc);
}		
else if(alea==4)
{
	SDL_BlitSurface(e.im4,NULL,screen,&e.pospc);
}		
else if(alea==5)
{
	SDL_BlitSurface(e.im5,NULL,screen,&e.pospc);
}		
else if(alea==6)
{
	SDL_BlitSurface(e.im6,NULL,screen,&e.pospc);
}		
SDL_Flip(screen) ;
	SDL_Delay(1000);
	return alea;
}
/**
* @brief intelligence artificielle simple
* @param e enigme , screen fenetre, a nembre d'utilisateur,b nembre de pc
* @return nembre de pc apres calcul
*/
int ia(int a,int b,SDL_Surface *screen,enigme e)
{
	int i,j;
	for (i=0;i<2;i++)
	{
		if(a<7 && b<=a)
		{
			j=blitpc(e,screen);
			b=b+j;
		}
		else if(b<a && a<=12)
		{
			j=blitpc(e,screen);
			b=b+j;
		}
		
	}
return b;
}
/**
* @brief calcul du solution de l'enigme 
* @param a nembre d'utilisateur,b nembre de pc
* @return la solution
*/
 int solution_e (int a,int b)
 {
	 int solution;
	 if (a<12 && b<12)
	{
		if (a>b)
		{
			solution=1;
		}
		else if (a<b)
		{
			solution=2;
		}
		else if (a==b)
		{
			solution=0;
		}
		return solution;
	}
	 
	 
 	else if (a==12 && b!=12)
	{
		solution=1;
	}
	else if (a>12 && b>12)
	{
		solution=0;
	}
	else if (a>12 && b<12)
	{
		solution=2;

	}
	else if (a!=12 && b==12)
	{
		solution=2;
	}
	else if(a<12 && b>12)
	{
		solution=1;
	}
 	return solution;
 }
/**
* @brief resolution de l'enigme et affichage de resultat
* @param s solution,x variable pour fermer la boucle,screen fenetre,e enigme
* @return rien
*/
void resolution (int solution,int x,SDL_Surface *screen ,enigme e)
{
	if (solution==1)
	{
		SDL_BlitSurface(e.passed,NULL,screen,&e.positionecran);
	}
	else if (solution==2)
	{
		SDL_BlitSurface(e.failed,NULL,screen,&e.positionecran);
	}
	else if (solution==0)
	{
		SDL_BlitSurface(e.draw,NULL,screen,&e.positionecran);
	}
	x=1;
	SDL_Flip(screen) ;
}
