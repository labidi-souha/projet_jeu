#ifndef FONCTIONS_H_
#define FONCTIONS_H_

void Afficher_menu_principal(SDL_Surface *ecran , SDL_Surface *imageDeFond ,SDL_Surface *imageBoutonQuitter ,SDL_Surface *imageBoutonJouer ,SDL_Surface *imageBoutonOptions , SDL_Rect positionFond, SDL_Rect positionQuitter, SDL_Rect positionJouer, SDL_Rect positionOptions , Mix_Music* music, Mix_Chunk* son, TTF_Font *police, SDL_Surface *texte, SDL_Color couleurNoir);
int Menu(SDL_Surface *ecran,SDL_Surface *imageDeFondJouer ,SDL_Surface *imageDeFondOptions ,SDL_Surface *imageBoutonRetourMenu, SDL_Rect positionFondJouer, SDL_Rect positionFondOptions, SDL_Rect positionBoutonRetourMenu, SDL_Event event,SDL_Surface *imageDeFond ,SDL_Surface *imageBoutonQuitter ,SDL_Surface *imageBoutonJouer ,SDL_Surface *imageBoutonOptions ,SDL_Surface *imageBoutonQuitter2 ,SDL_Surface *imageBoutonJouer2 ,SDL_Surface *imageBoutonOptions2, SDL_Rect positionFond, SDL_Rect positionQuitter, SDL_Rect positionJouer, SDL_Rect positionOptions , Mix_Music* music, Mix_Chunk *son, TTF_Font *police, SDL_Surface *texte, SDL_Color couleurNoir);
void Afficher_menu_jouer(SDL_Surface *ecran , SDL_Surface *imageDeFondJouer ,SDL_Surface *imageBoutonRetourMenu , SDL_Rect positionBoutonRetourMenu, SDL_Rect positionFondJouer, Mix_Music* music2 );
int jouer(SDL_Surface *ecran,SDL_Surface *imageDeFondJouer ,SDL_Surface *imageDeFondOptions ,SDL_Surface *imageBoutonRetourMenu, SDL_Rect positionFondJouer, SDL_Rect positionFondOptions, SDL_Rect positionBoutonRetourMenu, SDL_Event event,SDL_Surface *imageDeFond ,SDL_Surface *imageBoutonQuitter ,SDL_Surface *imageBoutonJouer ,SDL_Surface *imageBoutonOptions , SDL_Rect positionFond, SDL_Rect positionQuitter, SDL_Rect positionJouer, SDL_Rect positionOptions , Mix_Music* music2);
void Afficher_menu_options(SDL_Surface *ecran , SDL_Surface *imageDeFondJouer ,SDL_Surface *imageBoutonRetourMenu , SDL_Rect positionBoutonRetourMenu, SDL_Rect positionFondJouer, Mix_Music* music3,SDL_Surface *imageVolume, SDL_Surface *imagePasVolume, SDL_Rect positionimageVolume, SDL_Rect positionimagePasVolume );
int options(SDL_Surface *ecran,SDL_Surface *imageDeFondJouer ,SDL_Surface *imageDeFondOptions ,SDL_Surface *imageBoutonRetourMenu, SDL_Rect positionFondJouer, SDL_Rect positionFondOptions, SDL_Rect positionBoutonRetourMenu, SDL_Event event,SDL_Surface *imageDeFond ,SDL_Surface *imageBoutonQuitter ,SDL_Surface *imageBoutonJouer ,SDL_Surface *imageBoutonOptions , SDL_Rect positionFond, SDL_Rect positionQuitter, SDL_Rect positionJouer, SDL_Rect positionOptions , Mix_Music* music3, SDL_Surface *imageVolume, SDL_Surface *imagePasVolume, SDL_Rect positionimageVolume, SDL_Rect positionimagePasVolume);
#endif
