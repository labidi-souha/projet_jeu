#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonctions.h"

void Afficher_menu_principal(SDL_Surface *ecran , SDL_Surface *imageDeFond ,SDL_Surface *imageBoutonQuitter ,SDL_Surface *imageBoutonJouer ,SDL_Surface *imageBoutonOptions , SDL_Rect positionFond, SDL_Rect positionQuitter, SDL_Rect positionJouer, SDL_Rect positionOptions , Mix_Music* music, Mix_Chunk* son, TTF_Font *police, SDL_Surface *texte, SDL_Color couleurNoir)
{ 
    /* On blitte par-dessus l'écran */
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    SDL_BlitSurface(imageBoutonQuitter, NULL, ecran, &positionQuitter);

    SDL_BlitSurface(imageBoutonJouer, NULL, ecran, &positionJouer);
    
    SDL_BlitSurface(imageBoutonOptions, NULL, ecran, &positionOptions);

    SDL_BlitSurface(texte, NULL, ecran, &positionFond);
    SDL_Flip(ecran);

    Mix_PlayMusic(music, -1); // Joue notre musique 
       
}


void Afficher_menu_jouer(SDL_Surface *ecran , SDL_Surface *imageDeFondJouer ,SDL_Surface *imageBoutonRetourMenu , SDL_Rect positionBoutonRetourMenu, SDL_Rect positionFondJouer, Mix_Music* music2 )
{  
              
    SDL_BlitSurface(imageDeFondJouer, NULL, ecran, &positionFondJouer);
                     
    SDL_BlitSurface(imageBoutonRetourMenu, NULL, ecran, &positionBoutonRetourMenu);
    SDL_Flip(ecran);
    
    Mix_PlayMusic(music2, -1); // Joue notre musique     

}

void Afficher_menu_options(SDL_Surface *ecran , SDL_Surface *imageDeFondJouer ,SDL_Surface *imageBoutonRetourMenu , SDL_Rect positionBoutonRetourMenu, SDL_Rect positionFondJouer, Mix_Music* music3 ,SDL_Surface *imageVolume, SDL_Surface *imagePasVolume, SDL_Rect positionimageVolume, SDL_Rect positionimagePasVolume )
{                    
    SDL_BlitSurface(imageDeFondJouer, NULL, ecran, &positionFondJouer);
                    
    SDL_BlitSurface(imageBoutonRetourMenu, NULL, ecran, &positionBoutonRetourMenu);
    
    SDL_BlitSurface(imageVolume, NULL, ecran, &positionimageVolume);
    
    SDL_BlitSurface(imagePasVolume, NULL, ecran, &positionimagePasVolume);   
    SDL_Flip(ecran);

    Mix_PlayMusic(music3, -1); // Joue notre musique     
}

int Menu(SDL_Surface *ecran,SDL_Surface *imageDeFondJouer ,SDL_Surface *imageDeFondOptions ,SDL_Surface *imageBoutonRetourMenu, SDL_Rect positionFondJouer, SDL_Rect positionFondOptions, SDL_Rect positionBoutonRetourMenu, SDL_Event event,SDL_Surface *imageDeFond ,SDL_Surface *imageBoutonQuitter ,SDL_Surface *imageBoutonJouer ,SDL_Surface *imageBoutonOptions ,SDL_Surface *imageBoutonQuitter2 ,SDL_Surface *imageBoutonJouer2 ,SDL_Surface *imageBoutonOptions2, SDL_Rect positionFond, SDL_Rect positionQuitter, SDL_Rect positionJouer, SDL_Rect positionOptions , Mix_Music* music, Mix_Chunk *son, TTF_Font *police, SDL_Surface *texte, SDL_Color couleurNoir)
{
    int continuer, etatboutonQuitter, etatboutonJouer, etatboutonOptions;

    Afficher_menu_principal(ecran , imageDeFond ,imageBoutonQuitter ,imageBoutonJouer ,imageBoutonOptions , positionFond, positionQuitter, positionJouer, positionOptions , music ,son, police, texte, couleurNoir);
       

    //Mix_AllocateChannels(32); //Allouer 32 canaux
    Mix_Volume(1, MIX_MAX_VOLUME); //Mettre à mi-volume le post 1
    //Mix_Chunk *son;//Créer un pointeur pour stocker un .WAV
    son = Mix_LoadWAV("./mediajeux/drip.wav"); //Charger un wav dans un pointeur
    Mix_VolumeChunk(son, MIX_MAX_VOLUME); //Mettre un volume pour ce wav
    //Mix_PlayChannel(1, son, 0); 

    SDL_WaitEvent(&event); /* On attend un événement qu'on récupère dans event */
    etatboutonQuitter=0;
    etatboutonJouer=0;
    etatboutonOptions=0;

    do 
    {
     /* On attend un événement qu'on récupère dans event */
   
        switch(event.type) /* On teste le type d'événement */
        {
            case SDL_QUIT: /* Si c'est un événement QUITTER */
                continuer = 0; /* On met le booléen à 0, donc la boucle va s'arrêter */
                return continuer;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE: /* Appui sur la touche Echap, on arrête le programme */
                        continuer = 0;
                        return continuer;
                        break;
                    case SDLK_q: /* Appui sur la touche q, on arrête le programme */
                        continuer = 0;
                        return continuer;
                        break;
                    case SDLK_j: /* Appui sur la touche j, on va vers jouer */
                        continuer = 2;
                        return continuer;
                        break;
                }
                break;
                
            case SDL_MOUSEBUTTONUP:
            // clique bouton quitter
            	if(event.button.x >= positionQuitter.x && event.button.x <= (positionQuitter.x+imageBoutonQuitter->w) && event.button.y >= positionQuitter.y && event.button.y <= (positionQuitter.y+imageBoutonQuitter->h))
            		{
            		 continuer = 0;
            		 return continuer;
            		}
            //clique bouton jouer
		        else if(event.button.x >= positionJouer.x && event.button.x <= (positionJouer.x+imageBoutonJouer->w) && event.button.y >= positionJouer.y && event.button.y <= (positionJouer.y+imageBoutonJouer->h))
            		{          		

                        continuer = 2;
                        return continuer;
                    }
            //clique bouton options
                    else if(event.button.x >= positionOptions.x && event.button.x <= (positionOptions.x+imageBoutonOptions->w) && event.button.y >= positionOptions.y && event.button.y <= (positionOptions.y+imageBoutonOptions->h))
            		{

                        continuer = 3;
                        return continuer;
                    }
            	break;

            case SDL_MOUSEMOTION:
            //changement image bouton quitter 
                if( event.motion.x >= positionQuitter.x && event.motion.x <= (positionQuitter.x+imageBoutonQuitter->w) && event.motion.y >= positionQuitter.y && event.motion.y <= (positionQuitter.y+imageBoutonQuitter->h) && etatboutonQuitter==0)
                {
                    
                    Mix_PlayChannel(1, son, 0);
                    //Mix_FreeChunk(son);

                    SDL_BlitSurface(imageBoutonQuitter2, NULL, ecran, &positionQuitter);
                    SDL_Flip(imageBoutonQuitter);
                    etatboutonQuitter=1;
                }
                if( event.motion.x < positionQuitter.x || event.motion.x > (positionQuitter.x+imageBoutonQuitter->w) || event.motion.y < positionQuitter.y || event.motion.y > (positionQuitter.y+imageBoutonQuitter->h) && etatboutonQuitter==1)
                {
                    
                    SDL_BlitSurface(imageBoutonQuitter, NULL, ecran, &positionQuitter);
                    SDL_Flip(imageBoutonQuitter);
                    etatboutonQuitter=0;
                }
            //changement image bouton jouer
                if( event.motion.x >= positionJouer.x && event.motion.x <= (positionJouer.x+imageBoutonJouer->w) && event.motion.y >= positionJouer.y && event.motion.y <= (positionJouer.y+imageBoutonJouer->h) && etatboutonJouer==0)
                {
                    Mix_PlayChannel(1, son, 0);

                    
                    SDL_BlitSurface(imageBoutonJouer2, NULL, ecran, &positionJouer);
                    SDL_Flip(ecran);
                    etatboutonJouer=1;
                }
                if( event.motion.x < positionJouer.x || event.motion.x >(positionJouer.x+imageBoutonJouer->w) || event.motion.y < positionJouer.y || event.motion.y >(positionJouer.y+imageBoutonJouer->h) && etatboutonJouer==1)
                {
                    
                    SDL_BlitSurface(imageBoutonJouer, NULL, ecran, &positionJouer);
                    SDL_Flip(ecran);
                    etatboutonJouer=0;
                }
            //changement image bouton options
                if( event.motion.x >= positionOptions.x && event.motion.x <= (positionOptions.x+imageBoutonOptions->w) && event.motion.y >= positionOptions.y && event.motion.y <= (positionOptions.y+imageBoutonOptions->h) && etatboutonOptions==0)
                {
                    Mix_PlayChannel(1, son, 0);
                    
                    SDL_BlitSurface(imageBoutonOptions2, NULL, ecran, &positionOptions);
                    SDL_Flip(ecran);
                    etatboutonOptions=1;
                }
                if(event.motion.x < positionOptions.x || event.motion.x >(positionOptions.x+imageBoutonOptions->w) || event.motion.y < positionOptions.y || event.motion.y >(positionOptions.y+imageBoutonOptions->h) && etatboutonOptions==1)
                {
                    
                    SDL_BlitSurface(imageBoutonOptions, NULL, ecran, &positionOptions);
                    SDL_Flip(ecran);
                    etatboutonOptions=0;
                }
                break;
        }
    }while(SDL_WaitEvent(&event));
}

int jouer(SDL_Surface *ecran,SDL_Surface *imageDeFondJouer ,SDL_Surface *imageDeFondOptions ,SDL_Surface *imageBoutonRetourMenu, SDL_Rect positionFondJouer, SDL_Rect positionFondOptions, SDL_Rect positionBoutonRetourMenu, SDL_Event event,SDL_Surface *imageDeFond ,SDL_Surface *imageBoutonQuitter ,SDL_Surface *imageBoutonJouer ,SDL_Surface *imageBoutonOptions , SDL_Rect positionFond, SDL_Rect positionQuitter, SDL_Rect positionJouer, SDL_Rect positionOptions , Mix_Music* music2)
{
    int continuer;
    Afficher_menu_jouer(ecran , imageDeFondJouer ,imageBoutonRetourMenu , positionBoutonRetourMenu, positionFondJouer, music2 );
    SDL_WaitEvent(&event); /* On attend un événement qu'on récupère dans event */
    do 
    {
        switch(event.type) /* On teste le type d'événement */
        {
            case SDL_QUIT: /* Si c'est un événement QUITTER */
                continuer = 0; /* On met le booléen à 0, donc la boucle va s'arrêter */
                return continuer;
                break;
                
            case SDL_MOUSEBUTTONUP:
            // clique bouton quitter
                if(event.button.x >= positionBoutonRetourMenu.x && event.button.x <= (positionBoutonRetourMenu.x+imageBoutonRetourMenu->w) && event.button.y >= positionBoutonRetourMenu.y && event.button.y <= (positionBoutonRetourMenu.y+imageBoutonRetourMenu->h))
                    {
                     continuer = 1;
                     return continuer;
                    }
                break;
        }
    }while(SDL_WaitEvent(&event));

}

int options(SDL_Surface *ecran,SDL_Surface *imageDeFondJouer ,SDL_Surface *imageDeFondOptions ,SDL_Surface *imageBoutonRetourMenu, SDL_Rect positionFondJouer, SDL_Rect positionFondOptions, SDL_Rect positionBoutonRetourMenu, SDL_Event event,SDL_Surface *imageDeFond ,SDL_Surface *imageBoutonQuitter ,SDL_Surface *imageBoutonJouer ,SDL_Surface *imageBoutonOptions , SDL_Rect positionFond, SDL_Rect positionQuitter, SDL_Rect positionJouer, SDL_Rect positionOptions , Mix_Music* music3 ,SDL_Surface *imageVolume, SDL_Surface *imagePasVolume, SDL_Rect positionimageVolume, SDL_Rect positionimagePasVolume)
{
    int continuer;
    Afficher_menu_options(ecran , imageDeFondJouer ,imageBoutonRetourMenu , positionBoutonRetourMenu, positionFondJouer, music3, imageVolume, imagePasVolume, positionimageVolume,  positionimagePasVolume );
    SDL_WaitEvent(&event); /* On attend un événement qu'on récupère dans event */
    do 
    {
        switch(event.type) /* On teste le type d'événement */
        {
            case SDL_QUIT: /* Si c'est un événement QUITTER */
                continuer = 0; /* On met le booléen à 0, donc la boucle va s'arrêter */
                return continuer;
                break;
                
            case SDL_MOUSEBUTTONUP:
            // clique bouton retour menu
                if(event.button.x >= positionBoutonRetourMenu.x && event.button.x <= (positionBoutonRetourMenu.x+imageBoutonRetourMenu->w) && event.button.y >= positionBoutonRetourMenu.y && event.button.y <= (positionBoutonRetourMenu.y+imageBoutonRetourMenu->h))
                    {
                     continuer = 1;
                     return continuer;
                    }
                if(event.button.x >= positionimageVolume.x && event.button.x <= (positionimageVolume.x+imageVolume->w) && event.button.y >= positionimageVolume.y && event.button.y <= (positionimageVolume.y+imageVolume->h))
                    {
                     Mix_VolumeMusic(MIX_MAX_VOLUME);
                    }
                if(event.button.x >= positionimagePasVolume.x && event.button.x <= (positionimagePasVolume.x+ imagePasVolume->w ) && event.button.y >= positionimagePasVolume.y && event.button.y <= (positionimagePasVolume.y+imagePasVolume->h))
                    {
                     Mix_VolumeMusic(0);

                    

                     //const SDL_VideoInfo* myPointer = SDL_GetVideoInfo();
 
                    // Reconfigure le mode vidéo
                    //SDL_SetVideoMode(myPointer->current_w, myPointer->current_h, 16, SDL_DOUBLEBUF|SDL_FULLSCREEN);
                    }
                break;
                
        }
    }while(SDL_WaitEvent(&event));

}
