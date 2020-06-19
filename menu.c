#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "menu.h"


int menu ()
{//declaration
SDL_Surface *fenetre=NULL;
SDL_Surface *background=NULL;
SDL_Surface *playim=NULL;
SDL_Surface *bk=NULL;
SDL_Surface *moption=NULL;
SDL_Surface *retour=NULL;
SDL_Surface *mon=NULL;
SDL_Surface *moff=NULL;
SDL_Surface *plus=NULL;
SDL_Surface *moin=NULL;
SDL_Surface *barres=NULL;
 SDL_Surface *t[22]; //tableau


SDL_Surface *singel=NULL;
SDL_Surface *multiplayer=NULL;

SDL_Surface *newgame=NULL;
SDL_Surface *newgame1=NULL;
SDL_Surface *newgame2=NULL;

SDL_Surface *continuer=NULL;
SDL_Surface *continuer1=NULL;
SDL_Surface *continuer2=NULL;

SDL_Surface *option=NULL;
SDL_Surface *option1=NULL;
SDL_Surface *option2=NULL;

SDL_Surface *exit=NULL;
SDL_Surface *exit1=NULL;
SDL_Surface *exit2=NULL;
 

SDL_Rect possing;
SDL_Rect posmul;

SDL_Rect playimposition;
SDL_Rect positionecran;
SDL_Rect newgamePosition;
SDL_Rect newgame1Position;
SDL_Rect newgame2Position;

SDL_Rect continuerPosition;
SDL_Rect continuer1Position;
SDL_Rect continuer2Position;

SDL_Rect optionPosition;
SDL_Rect option1Position;
SDL_Rect option2Position;

SDL_Rect exitPosition;
SDL_Rect exit1Position;
SDL_Rect exit2Position;

SDL_Rect moptionPosition;
SDL_Rect retourPosition;
SDL_Rect bkPosition;
SDL_Rect monPosition;
SDL_Rect moffPosition;
SDL_Rect plusPosition;
SDL_Rect moinPosition;
SDL_Rect positiontexte;
SDL_Rect barresPosition;
Mix_Chunk *bip;
Mix_Music *music;
SDL_Event event; 
char pause;
int done=1;
int x,y;
int a=0;
int compteur;
int pos=3 ;
int s=1;
int fs=1;
int v=3;
 
 SDL_Color couleurRouge= {255,0, 0};
/*le tableau des images */
t[0]=IMG_Load("back.png");
t[1]=IMG_Load("1.png");
t[2]=IMG_Load("2.png");
t[3]=IMG_Load("3.png");
t[4]=IMG_Load("4.png");
t[5]=IMG_Load("5.png");
t[6]=IMG_Load("6.png");
t[7]=IMG_Load("7.png");
t[8]=IMG_Load("8.png");
t[9]=IMG_Load("9.png");
t[10]=IMG_Load("10.png");
t[11]=IMG_Load("11.png");
t[12]=IMG_Load("12.png");
t[13]=IMG_Load("13.png");
t[14]=IMG_Load("14.png");
t[15]=IMG_Load("15.png");
t[16]=IMG_Load("16.png");
t[17]=IMG_Load("17.png");
t[18]=IMG_Load("18.png");
t[19]=IMG_Load("19.png");
t[20]=IMG_Load("20.png");
t[21]=IMG_Load("21.png");
int i=0;

//Music

if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
	printf("%s",Mix_GetError());
}
music=Mix_LoadMUS("music.mp3");
bip = Mix_LoadWAV("mus.wav");
Mix_PlayMusic(music,-1);
if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
	printf("Unable to inizialize SDL: %s \n",SDL_GetError());
return 1;
}
Mix_AllocateChannels(2);
//créer la surface principale (fenetre!!!)
fenetre=SDL_SetVideoMode(1300,768,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_FillRect (fenetre,NULL,SDL_MapRGB(fenetre->format,128,0,0));

//ajout background
background=IMG_Load("back.png");
if(background==NULL)
{printf("Unable to load background: %s\n",SDL_GetError());
return 1;
}
positionecran.x=0;
positionecran.y=0;
positionecran.w=background->w;
positionecran.h=background->h;

//newgame
playim=IMG_Load("moption.png");
playimposition.x=0;
playimposition.y=0;
//newgame1
bk=SDL_LoadBMP("background.bmp");
bkPosition.x=0;
bkPosition.y=0;
//ajout newgame
newgame=IMG_Load("n.png");
if(newgame==NULL)
{
	printf("Unable to load newgame : %s\n",SDL_GetError());
return 1;
}
newgamePosition.x=150;
newgamePosition.y=320;
// ajout newgame1
newgame1=IMG_Load("n1.png");
if(newgame1==NULL)
{
	printf("Unable to load newgame1 : %s\n",SDL_GetError());
return 1;
}
newgame1Position.x=150;
newgame1Position.y=320;

// ajout newgame2
newgame2=IMG_Load("n2.png");
if(newgame2==NULL)
{
	printf("Unable to load newgame2 : %s\n",SDL_GetError());
return 1;
}
newgame2Position.x=150;
newgame2Position.y=320;
//ajout singel
singel=IMG_Load("singel.jpg");
if(singel==NULL)
{
	printf("Unable to load singel : %s\n",SDL_GetError());
return 1;
}
possing.x=150;
possing.y=320;
//ajout multiplayer
multiplayer=IMG_Load("multiplayer.jpg");
if(multiplayer==NULL)
{
	printf("Unable to load multiplayer : %s\n",SDL_GetError());
return 1;
}
posmul.x=150;
posmul.y=390;



//continuer
//ajout continuer
continuer=IMG_Load("c.png");
if(continuer==NULL)
{
	printf("Unable to load continuer : %s\n",SDL_GetError());
return 1;
}
continuerPosition.x=150;
continuerPosition.y=390;
// ajout continuer1
continuer1=IMG_Load("c1.png");
if(continuer1==NULL)
{
	printf("Unable to load continuer1 : %s\n",SDL_GetError());
return 1;
}
continuer1Position.x=150;
continuer1Position.y=390;

// ajout continuer2
continuer2=IMG_Load("c2.png");
if(continuer2==NULL)
{
	printf("Unable to load continuer2 : %s\n",SDL_GetError());
return 1;
}
continuer2Position.x=150;
continuer2Position.y=390;


//option
moption=IMG_Load("moption.png");
playimposition.x=50;
playimposition.y=0;

//ajout option
option=IMG_Load("o.png");
if(option==NULL)
{
	printf("Unable to load option : %s\n",SDL_GetError());
return 1;
}
optionPosition.x=150;
optionPosition.y=460;
// ajout option1
option1=IMG_Load("o1.png");
if(option1==NULL)
{
	printf("Unable to load option1 : %s\n",SDL_GetError());
return 1;
}
option1Position.x=150;
option1Position.y=460;

// ajout option2
option2=IMG_Load("o2.png");
if(option2==NULL)
{
	printf("Unable to load option2 : %s\n",SDL_GetError());
return 1;
}
option2Position.x=150;
option2Position.y=460;


//exit
//ajout exit
exit=IMG_Load("e.png");
if(exit==NULL)
{
	printf("Unable to load exit : %s\n",SDL_GetError());
return 1;
}
exitPosition.x=150;
exitPosition.y=530;
// ajout exit1
exit1=IMG_Load("e1.png");
if(exit1==NULL)
{
	printf("Unable to load exit1 : %s\n",SDL_GetError());
return 1;
}
exit1Position.x=150;
exit1Position.y=530;

// ajout exit2
exit2=IMG_Load("e2.png");
if(exit2==NULL)
{
	printf("Unable to load exit2 : %s\n",SDL_GetError());
return 1;
}
exit2Position.x=150;
exit2Position.y=530;

// ajout retour
retour=IMG_Load("retour.png");
if(retour==NULL)
{
	printf("Unable to load exit2 : %s\n",SDL_GetError());
return 1;
}
retourPosition.x=0;
retourPosition.y=0;
// ajout bouton on on
mon=IMG_Load("mon.png");
if(mon==NULL)
{
	printf("Unable to load mon : %s\n",SDL_GetError());
return 1;
}
monPosition.x=400;
monPosition.y=20;
//bouton off
moff=IMG_Load("moff.png");
if(moff==NULL)
{
	printf("Unable to load moff : %s\n",SDL_GetError());
return 1;
}
moffPosition.x=400;
moffPosition.y=20;
//bouton plus
plus=IMG_Load("plus.png");
if(plus==NULL)
{
	printf("Unable to load plus : %s\n",SDL_GetError());
return 1;
}
plusPosition.x=20;
plusPosition.y=200;
//bouton moin
moin=IMG_Load("moin.png");
if(moin==NULL)
{
	printf("Unable to load moin : %s\n",SDL_GetError());
return 1;
}
moinPosition.x=320;
moinPosition.y=200;
//bouton barres
barres=IMG_Load("00.png");
if(barres==NULL)
{
	printf("Unable to load barres : %s\n",SDL_GetError());
return 1;
}
barresPosition.x=50;
barresPosition.y=200;
//créee un texte
SDL_Surface *texte=NULL;
SDL_Rect positiontxt;  
TTF_Font *police=NULL;
SDL_Color coulerRouge={255,0,0};


TTF_Init();
police=TTF_OpenFont("police.ttf",35);

while(done)

{

//blit
if(a==0)
{        
	SDL_BlitSurface(t[i],NULL,fenetre,&positionecran);
        i++;
        SDL_Delay(20);
        if (i==22) 
         i=0;
	SDL_BlitSurface(newgame,&positionecran,fenetre,&newgamePosition);
	SDL_BlitSurface(continuer,&positionecran,fenetre,&continuerPosition);
	SDL_BlitSurface(option,&positionecran,fenetre,&optionPosition);
	SDL_BlitSurface(exit,&positionecran,fenetre,&exitPosition);

}
SDL_Event event;
 

while(SDL_PollEvent(&event))
{switch(event.type)
  {
   

case SDL_QUIT:
  {done=0;
   break;}
case SDL_KEYUP:
            { //deplacement du clavier down  
             if(event.key.keysym.sym==SDLK_DOWN)
             {switch (pos) 
               { 
                 case 3 : 
                  { texte=TTF_RenderText_Blended(police,"Commencer une nouvelle partie...",coulerRouge);
                    positiontxt.x=400;
                    positiontxt.y=500;
                    SDL_BlitSurface (texte,NULL,fenetre,&positiontxt);
 
                   SDL_BlitSurface(newgame1,&positionecran,fenetre,&newgamePosition);
                   Mix_PlayChannel(1, bip,0);
                   pos=0; 
                  break;}
                 case 0 : 
                 { texte=TTF_RenderText_Blended(police,"Continue la partie...",coulerRouge);
                   positiontxt.x=400;
                  positiontxt.y=500;
                  SDL_BlitSurface (texte,NULL,fenetre,&positiontxt);
                  SDL_BlitSurface(continuer1,&positionecran,fenetre,&continuerPosition);
                 Mix_PlayChannel(1, bip,0);
                  pos=1; 
                 break;}
                 case 1 : 
                 { texte=TTF_RenderText_Blended(police,"Settings...",coulerRouge);
                   positiontxt.x=400;
                   positiontxt.y=500;
                   SDL_BlitSurface (texte,NULL,fenetre,&positiontxt);
                  SDL_BlitSurface(option1,&positionecran,fenetre,&optionPosition);
                 Mix_PlayChannel(1, bip,0);
                  pos=2; 
                 break;
                  }
                case 2:
               { texte=TTF_RenderText_Blended(police,"Quitter le jeu...",coulerRouge);
                 positiontxt.x=400;
                 positiontxt.y=500;
                 SDL_BlitSurface (texte,NULL,fenetre,&positiontxt);
                 SDL_BlitSurface(exit1,&positionecran,fenetre,&exitPosition);
                Mix_PlayChannel(1, bip,0);
                 pos =3;
               break;
               }
               } 
              }
else if ( event.key.keysym.sym == SDLK_UP ) 
              {           
             switch (pos) 
               { 
             case 1 : 
             { texte=TTF_RenderText_Blended(police,"Commencer une nouvelle partie...",coulerRouge);
                    positiontxt.x=400;
                    positiontxt.y=500;
                    SDL_BlitSurface (texte,NULL,fenetre,&positiontxt);
 
                   SDL_BlitSurface(newgame1,&positionecran,fenetre,&newgamePosition);
                   Mix_PlayChannel(1, bip,0);
               pos=4;
              break;

              }
              case 2 : 
               { 
            texte=TTF_RenderText_Blended(police,"Continue la partie...",coulerRouge);
                   positiontxt.x=400;
                  positiontxt.y=500;
                  SDL_BlitSurface (texte,NULL,fenetre,&positiontxt);
                  SDL_BlitSurface(continuer1,&positionecran,fenetre,&continuerPosition);
                 Mix_PlayChannel(1, bip,0);
           
            pos =1; 
              break;
             }
              case 3 : 
             { 
            
           texte=TTF_RenderText_Blended(police,"A propo de jeu...",coulerRouge);
                   positiontxt.x=400;
                   positiontxt.y=500;
                   SDL_BlitSurface (texte,NULL,fenetre,&positiontxt);
                  SDL_BlitSurface(option1,&positionecran,fenetre,&optionPosition);
                 Mix_PlayChannel(1, bip,0);
             pos=2; 
              break;
              }
             case 4:
               {texte=TTF_RenderText_Blended(police,"Quitter le jeu...",coulerRouge);
                 positiontxt.x=400;
                 positiontxt.y=500;
                 SDL_BlitSurface (texte,NULL,fenetre,&positiontxt);
                 SDL_BlitSurface(exit1,&positionecran,fenetre,&exitPosition);
                Mix_PlayChannel(1, bip,0);
                 pos =3;
               break;
               }
               }
 

             }  









}
   
 
case SDL_KEYDOWN:
  {if(event.key.keysym.sym==SDLK_ESCAPE)
    done=0;
      

  if(event.key.keysym.sym==SDLK_n)
	{
  	SDL_BlitSurface(newgame2,&positionecran,fenetre,&newgame2Position);
	SDL_BlitSurface(bk,NULL,fenetre,&positionecran);
	SDL_BlitSurface(retour,&positionecran,fenetre,&positionecran);
	a=1;
        }
  if(event.key.keysym.sym==SDLK_o)
      {	SDL_BlitSurface(bk,NULL,fenetre,&positionecran);
	if(s==1){SDL_BlitSurface(mon,&positionecran,fenetre,&monPosition);}
        if(s==0){SDL_BlitSurface(moff,&positionecran,fenetre,&moffPosition);}
	SDL_BlitSurface(barres,&positionecran,fenetre,&barresPosition);
	SDL_BlitSurface(moin,&positionecran,fenetre,&plusPosition);
	SDL_BlitSurface(plus,&positionecran,fenetre,&moinPosition);
        SDL_BlitSurface(retour,&positionecran,fenetre,&retourPosition);
	a=2;
      }
  if(event.key.keysym.sym==SDLK_e)
    done=0;
      break;}
case SDL_MOUSEMOTION : 
{
 
 x=event.motion.x;
 y=event.motion.y;
 
if        ( x > 150 && x< 305 && y > 320 && y <390  && a==0 ) {
texte=TTF_RenderText_Blended(police,"Commencer une nouvelle partie...",coulerRouge);
positiontxt.x=400;
positiontxt.y=500;
SDL_BlitSurface (texte,NULL,fenetre,&positiontxt);

SDL_BlitSurface(newgame1,&positionecran,fenetre,&newgame1Position);
Mix_PlayChannel(1, bip,0); } 

else if   ( x > 150 && x< 305 && y > 390 && y < 460 && a==0 ) {
texte=TTF_RenderText_Blended(police,"Continue la partie...",coulerRouge);
positiontxt.x=400;
positiontxt.y=500;
SDL_BlitSurface (texte,NULL,fenetre,&positiontxt);
SDL_BlitSurface(continuer1,&positionecran,fenetre,&continuer1Position);
Mix_PlayChannel(1, bip,0);}

else if   ( x > 150 && x< 305 && y > 460 && y < 530 && a==0 ) {
texte=TTF_RenderText_Blended(police,"A propo de jeu...",coulerRouge);
positiontxt.x=400;
positiontxt.y=500;
SDL_BlitSurface (texte,NULL,fenetre,&positiontxt);
SDL_BlitSurface(option1,&positionecran,fenetre,&option1Position);
Mix_PlayChannel(1, bip,0);}

else if   ( x > 150 && x< 305 && y > 530 && y < 600 && a==0 ) {
texte=TTF_RenderText_Blended(police,"Quitter le jeu...",coulerRouge);
positiontxt.x=400;
positiontxt.y=500;
SDL_BlitSurface (texte,NULL,fenetre,&positiontxt);
SDL_BlitSurface(exit1,&positionecran,fenetre,&exit1Position);
Mix_PlayChannel(1, bip,0);}

  break;
}
 
 case SDL_MOUSEBUTTONDOWN : 
{
 
 x=event.button.x;
 y=event.button.y ;

if        ( x > 150 && x< 305 && y > 320 && y < 390 && a==0 ) 
{
	SDL_BlitSurface(newgame2,&positionecran,fenetre,&newgame2Position);
	Mix_PlayChannel(1, bip,0);
} 

else if   ( x > 150 && x< 305 && y > 390 && y < 460 && a==0 ) 
{
	SDL_BlitSurface(continuer2,&positionecran,fenetre,&continuer2Position);
	Mix_PlayChannel(1, bip,0);
}

else if   ( x > 150 && x< 305 && y > 460 && y < 530 && a==0 ) 
{
	SDL_BlitSurface(option2,&positionecran,fenetre,&option2Position);
	Mix_PlayChannel(1, bip,0);
}

else if   ( x > 150 && x< 305 && y > 530 && y < 600 && a==0 ) 
{
	SDL_BlitSurface(exit2,&positionecran,fenetre,&exit2Position);
	Mix_PlayChannel(1, bip,0);
}

break ;

}

case SDL_MOUSEBUTTONUP : 
{
 if(event.button.button == SDL_BUTTON_LEFT)
{
 x=event.button.x;
 y=event.button.y ;

if        ( x > 150 && x< 305 && y > 320 && y < 390 && a==0) 
{
	SDL_BlitSurface(bk,NULL,fenetre,&bkPosition);
        SDL_BlitSurface(retour,&positionecran,fenetre,&positionecran);
SDL_BlitSurface(singel,NULL,fenetre,&possing);
SDL_BlitSurface(multiplayer,NULL,fenetre,&posmul);
	a=1;
} 

else if   ( x > 150 && x< 305 && y > 390 && y < 460 && a==0) 
{
	SDL_BlitSurface(continuer2,&positionecran,fenetre,&continuer2Position);
}
//new game
else if        ( x > 150 && x< 305 && y > 320 && y < 390 && a==1) 
{
	SDL_BlitSurface(bk,NULL,fenetre,&bkPosition);
        SDL_BlitSurface(retour,&positionecran,fenetre,&positionecran);

	a=3;
	done=0;
} 

else if   ( x > 150 && x< 305 && y > 390 && y < 460 && a==1) 
{
	SDL_BlitSurface(continuer2,&positionecran,fenetre,&continuer2Position);
}

//partie setting aka a==2
else if   ( x > 150 && x< 305 && y > 460 && y < 530 && a==0) 
{
	SDL_BlitSurface(bk,NULL,fenetre,&positionecran);
	if(s==1){SDL_BlitSurface(mon,&positionecran,fenetre,&monPosition);}
        if(s==0){SDL_BlitSurface(moff,&positionecran,fenetre,&moffPosition);}
	SDL_BlitSurface(barres,&positionecran,fenetre,&barresPosition);
	SDL_BlitSurface(moin,&positionecran,fenetre,&plusPosition);
	SDL_BlitSurface(plus,&positionecran,fenetre,&moinPosition);
        SDL_BlitSurface(retour,&positionecran,fenetre,&retourPosition);
	a=2;
}
else if(x>400 && x<450 && y>20 && y<70 && (a==2&&s==1))
{ 
	Mix_PauseMusic(); 
	s=0; 
	SDL_BlitSurface(moff,&positionecran,fenetre,&moffPosition); 
}

else if(x>400 && x<450 && y>20 && y<70 && (a==2&&s==0))
{ 		      
    Mix_ResumeMusic();  
	s=1; 
	SDL_BlitSurface(mon,&positionecran,fenetre,&monPosition);
}	
else if(x>0 && x<50 && y>0 && y<50 && (a==2||a==1))
{ 
	a=0;                           
}
//full screen
else if(x>100 && x<150 && y>0 && y<50 && (a==0&&fs==1))
{ 
	fenetre=SDL_SetVideoMode(1300,768,32,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
		fs=0;
}
else if(x>100 && x<150 && y>0 && y<50 && (a==0&&fs==0))
{ 
	fenetre=SDL_SetVideoMode(1300,768,32,SDL_SWSURFACE|SDL_DOUBLEBUF);
		fs=1;
}
//change music
else if(x>320 && x<350 && y>200 && y<230 && (a==2&&v==1))
{ 
		 Mix_VolumeMusic(MIX_MAX_VOLUME/2);
		  Mix_VolumeChunk(bip,MIX_MAX_VOLUME/2);
		 v=2;
}
else if(x>320 && x<350 && y>200 && y<230 && (a==2&&v==2))
	{
		 Mix_VolumeMusic(MIX_MAX_VOLUME);
		  Mix_VolumeChunk(bip,MIX_MAX_VOLUME);
		 v=3;
	}

else if(x>20 && x<50 && y>200 && y<230 && (a==2&&v==3))
{ 
		 Mix_VolumeMusic(MIX_MAX_VOLUME/2);
		  Mix_VolumeChunk(bip,MIX_MAX_VOLUME/2);
		 v=2;
}
else if(x>20 && x<50 && y>200 && y<230 && (a==2&&v==2))
	{
		 Mix_VolumeMusic(MIX_MAX_VOLUME*0);
		  Mix_VolumeChunk(bip,MIX_MAX_VOLUME*0);
		 v=1;
	}


//fin de partie settings
else if   ( x  > 150 && x< 305 && y > 530 && y < 600 )
{
	done=0;
}

}
break ;}
}

SDL_Flip(fenetre);
}
}


//liberartion memoire
SDL_FreeSurface(background);
SDL_FreeSurface(newgame);
SDL_FreeSurface(option);
SDL_FreeSurface(exit);
SDL_Quit();
pause=getchar();
SDL_Delay(10);

Mix_FreeMusic(music);

return a;
}



