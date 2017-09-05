#include "TheGame.h"
#include <iomanip>

bool TheGame::onInit(){

	//On doit Initialiser SDL_ttf dans la partie Init de notre structure basique
	TTF_Init();
	SDL_WM_SetCaption(TITLE_GAME, NULL);

	char ent1[] = "images/blueblur.png";
	char ent2[] = "images/gray-alien.png";
	char* ptdFondEcran = ent1;
	char* yosh = ent2;

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
		log.writeLog(ERROR, "SDL_Init() Failed << TheGame_OnInit.cpp");
		return false;
	}
	SDL_ShowCursor(SDL_DISABLE);
	CLevel::level.buildLevel();
	if((ecran = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL){
		log.writeLog(ERROR, "SDL_SetVideoMode() Failed << TheGame_OnInit.cpp");
		return false;
	}


	if (blueBlur.onLoad(ptdFondEcran, 50, 50, HERO_MAX_FRAME) == false){
		log.writeLog(ERROR, "blueBlur.onLoad() Failed << TheGame_OnInit.cpp");
		return false;
	}

	blueBlur.setPosition(WWIDTH/2, WHEIGHT - 50);


    CEntity::entityList.push_back(&blueBlur);
    log.writeLog(INFO, "TheGame::onInit() Succeded << TheGame_OnInit.cpp");
	return true;
}

void TheGame::initMenu(){
    //Défini la police et la taille à utiliser dans tout le menu
    menu.setFontStyle(MENU_FONT, MENU_SIZE);

    //Défini la position du menu à l'image
    menu.setPosition(200, 200);

    //Défini les couleurs
    SDL_Color hoverColor = {0, 66, 99};
    SDL_Color normalColor = {153, 0, 102};
    menu.setColor(normalColor, hoverColor);

    //Ajoute les liens de notre menu
    menu.addRow("New Game");
	menu.addRow("Options");
    menu.addRow("Score");
    menu.addRow("Quitter");
}

SDL_Surface* TheGame::initTitleGame() {

	TTF_Font *police = NULL;
	SDL_Color couleur = {0, 66, 99};
	SDL_Surface *texte = NULL;

	/* Chargement de la police */
    police = TTF_OpenFont(TITLE_FONT, TITLE_SIZE);
        /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, TITLE_GAME, couleur);
    TTF_CloseFont(police);
    return texte;
}



