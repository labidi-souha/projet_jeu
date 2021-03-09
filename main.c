#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonctions.h"

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *imageBoutonQuitter = NULL, *imageBoutonJouer = NULL, *imageBoutonOptions = NULL,*imageBoutonQuitter2 = NULL, *imageBoutonJouer2 = NULL, *imageBoutonOptions2 = NULL, *imageDeFondJouer = NULL, *imageDeFondOptions = NULL, *imageBoutonRetourMenu= NULL, *imageVolume=NULL, *imagePasVolume=NULL,
    *texte= NULL;
    SDL_Rect positionFond, positionQuitter, positionJouer, positionOptions, positionFondJouer, positionFondOptions, positionBoutonRetourMenu, positionimageVolume, positionimagePasVolume;
    SDL_Event event;
    Mix_Music *music, *music2, *music3;
    Mix_Chunk *son;
    int continuer=1 ; 
    TTF_Font *police =NULL;
    SDL_Color couleurNoir={0,0,0};

    positionFond.x = 0;
    positionFond.y = 0;
    positionQuitter.x = (800/2)-(100/2);
    positionQuitter.y = 300/*(600/2)-(75/2)*/;  
    positionJouer.x= (800/2)-(100/2);
    positionJouer.y = 400;
    positionOptions.x= (800/2)-(100/2);
    positionOptions.y= 500;
    positionFondJouer.x = 0;
    positionFondJouer.y = 0;
    positionFondOptions.x = 0;
    positionFondOptions.y = 0;
    positionBoutonRetourMenu.x = 20;
    positionBoutonRetourMenu.y = 20;
    positionimageVolume.x=720;
    positionimageVolume.y= 30;
    positionimagePasVolume.x= 720;
    positionimagePasVolume.y = 100;



    Mix_AllocateChannels(32);
    
    
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
    TTF_Init();

    // overture de la fenetre
    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
    SDL_WM_SetCaption("Jeu video groupe DIVINE 1A10", NULL);
    if(ecran==NULL)
    	{
        	printf("ERREUR: %s\n", SDL_GetError());
        	return 1;
       }

    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024 );
    /* Chargement d'une image Bitmap dans une surface */
    imageDeFond = SDL_LoadBMP("./mediajeux/bg1.bmp");
    imageBoutonQuitter=SDL_LoadBMP("./mediajeux/bouton_quitter_1.bmp");
    imageBoutonJouer=SDL_LoadBMP("./mediajeux/bouton_jouer_1.bmp");
    imageBoutonOptions=SDL_LoadBMP("./mediajeux/bouton_options_1.bmp");

    music = Mix_LoadMUS("./mediajeux/boucle.mp3"); // Charge notre musique
    son = Mix_LoadWAV("./mediajeux/drip.wav"); //Charger un wav dans un pointeur

    police=TTF_OpenFont("./mediajeux/Ubuntu-Bold.ttf" , 65); 
    texte=TTF_RenderText_Blended(police , "DIVINE", couleurNoir);

    // jouer
    imageDeFondJouer = SDL_LoadBMP("./mediajeux/bg2.bmp");
    imageBoutonRetourMenu = IMG_Load("./mediajeux/RetourMenu.png");

    music2 = Mix_LoadMUS("./mediajeux/boucle2.mp3"); // Charge notre musique

    //options
    imageDeFondJouer = SDL_LoadBMP("./mediajeux/bg3.bmp");
    imageBoutonRetourMenu = IMG_Load("./mediajeux/RetourMenu.png");
    imageVolume = IMG_Load("./mediajeux/Son_on_50.png");
    imagePasVolume = IMG_Load("./mediajeux/Son_off_50.png"); 

    music3 = Mix_LoadMUS("./mediajeux/boucle3.mp3"); // Charge notre musique

    imageBoutonQuitter2=SDL_LoadBMP("./mediajeux/bouton_quitter_2.bmp");
    imageBoutonJouer2=SDL_LoadBMP("./mediajeux/bouton_jouer_2.bmp");
    imageBoutonOptions2=SDL_LoadBMP("./mediajeux/bouton_options_2.bmp");

   
	continuer= 1;
	while (continuer)
  {
	      switch (continuer)
      {
      //appeler ecran menu
      case 1:
          continuer = Menu(ecran, imageDeFondJouer ,imageDeFondOptions ,imageBoutonRetourMenu,  positionFondJouer,  positionFondOptions,  positionBoutonRetourMenu,  event, imageDeFond ,imageBoutonQuitter ,imageBoutonJouer ,imageBoutonOptions ,imageBoutonQuitter2 ,imageBoutonJouer2 ,imageBoutonOptions2, positionFond,  positionQuitter,  positionJouer,  positionOptions ,  music, son, police, texte, couleurNoir);

      break;
      //options
      case 2:
          continuer = jouer(ecran,imageDeFondJouer ,imageDeFondOptions ,imageBoutonRetourMenu,  positionFondJouer,  positionFondOptions,  positionBoutonRetourMenu,  event, imageDeFond ,imageBoutonQuitter ,imageBoutonJouer ,imageBoutonOptions ,  positionFond,  positionQuitter,  positionJouer,  positionOptions ,  music2);
      break;
      case 3:
          continuer = options(ecran,imageDeFondJouer ,imageDeFondOptions ,imageBoutonRetourMenu,  positionFondJouer,  positionFondOptions,  positionBoutonRetourMenu,  event, imageDeFond ,imageBoutonQuitter ,imageBoutonJouer ,imageBoutonOptions ,  positionFond,  positionQuitter,  positionJouer,  positionOptions ,  music3, imageVolume, imagePasVolume, positionimageVolume, positionimagePasVolume);
      break;
      }     
}

    TTF_CloseFont (police);
    TTF_Quit();

    Mix_FreeChunk(son);
    Mix_FreeMusic(music);
    Mix_FreeMusic(music2); // Libére en mémoire notre musique
    Mix_FreeMusic(music3);
    Mix_CloseAudio(); // Quitter correctement SDL_Mixer
    
   /* On libère la surface */
    SDL_FreeSurface( ecran);
    SDL_FreeSurface( imageDeFond);
    SDL_FreeSurface( imageBoutonQuitter);
    SDL_FreeSurface( imageBoutonJouer);
    SDL_FreeSurface( imageBoutonOptions);
    SDL_FreeSurface( imageBoutonQuitter2);
    SDL_FreeSurface( imageBoutonJouer2);
    SDL_FreeSurface( imageBoutonOptions2);
    SDL_FreeSurface( imageDeFondJouer);
    SDL_FreeSurface( imageDeFondOptions);
    SDL_FreeSurface( imageBoutonRetourMenu);
    SDL_FreeSurface( imageVolume);
    SDL_FreeSurface( imagePasVolume);
    SDL_FreeSurface( texte);
    
    SDL_Quit();

    return EXIT_SUCCESS;
}
