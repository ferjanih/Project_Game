#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "time.h"
#include "test.h"


int main(void)
{


// Declaration

SDL_Surface *screen;
SDL_Surface *background;
SDL_Surface *Obstacle;


SDL_Rect pos_obs; 
SDL_Rect positionecran;

Mix_Music *music;
Mix_Chunk *son;


entite_sc e;

char pause;
int done=1;
int direction=0;

if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("Unable to inizialize SDL: %s \n",SDL_GetError());
        return 1;
    }


// Creation screen

screen=SDL_SetVideoMode(1280,640,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("Unable to set video mode : %s",SDL_GetError());
        return 1;
    }

//music

if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{printf("%s",Mix_GetError());}


music=Mix_LoadMUS("music.mp3");
Mix_PlayMusic(music,-1);



//son bref
son = Mix_LoadWAV("scream.wav");


if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
  printf("Unable to inizialize SDL: %s \n",SDL_GetError());
  return 1;
}



// Ajouter background

  background=IMG_Load("background.bmp");
    if(background==NULL)
    {
        printf("Unable to load background: %s\n",SDL_GetError());
        return 1;
    }
    positionecran.x=0;
    positionecran.y=0;
    positionecran.w=background->w;
    positionecran.h=background->h;

// Ajouter Obstacle

  Obstacle=IMG_Load("test.png");
    if(background==NULL)
    {
        printf("Unable to load Obstacle: %s\n",SDL_GetError());
        return 1;
    }
    
    pos_obs.x=500;
    pos_obs.y=250;
    pos_obs.w=Obstacle->w;
    pos_obs.h=Obstacle->h;


    initialiser_entite_secondaire ( &e );

    if(e.img==NULL)
    {
        printf("Unable to load bitmap: %s\n",SDL_GetError());
       
    }
SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);

while(done)

{

// blit

SDL_BlitSurface(background,NULL,screen,&positionecran);
SDL_BlitSurface(Obstacle,&positionecran,screen,&pos_obs);

afficher_entite_secondaire ( screen ,&e );

SDL_Event event;



while(SDL_PollEvent(&event))
{switch(event.type)
  {


case SDL_QUIT:
  {done=0;
   break;}


case SDL_KEYDOWN:
{
  

if(event.key.keysym.sym==SDLK_ESCAPE)
{ done=0;
      break;}


else if(event.key.keysym.sym==SDLK_RIGHT)
 {   e.pos.x+=20; direction=2; }


else if(event.key.keysym.sym==SDLK_LEFT)
 {   e.pos.x-=20;  direction=0; }

else if(event.key.keysym.sym==SDLK_DOWN)
 {   e.pos.y+=20; direction=3; }


else if(event.key.keysym.sym==SDLK_UP)
 {   e.pos.y-=20; direction=1;  }



}


 if (collision( e, pos_obs)) 
{
		
if(direction == 0)
  e.pos.x += 130;

if(direction == 1)
  e.pos.y += 130;

if(direction == 2)
  e.pos.x -= 130;

if(direction == 3)
  e.pos.y -= 130;

Mix_PlayChannel(-1, son, 0);

}


}

SDL_Flip(screen);

}
}


// Liberation memoire


SDL_FreeSurface(background);
Mix_FreeMusic(music);
SDL_Quit();
SDL_Delay(10);
pause=getchar();

return 0;

}
