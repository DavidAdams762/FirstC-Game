#ifndef _THEGAME_H_
#define _THEGAME_H_
#include <iostream>
#include <string.h>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "Define.h"
#include "CEntity.h"
#include "CEnemy.h"
#include "CGrayalien.h"
#include "CBullet.h"
#include "CAnimation.h"
#include "CEvent.h"
#include "CSurface.h"
#include "CPlayer.h"
#include "Menu.h"
#include "Log.h"
#include "CLevel.h"
using namespace std;


enum state_t {home, menus, options, game, game_over, pause};
enum MENU_LINK {
MENU_GAME,
MENU_OPTION,
MENU_SCORE,
MENU_QUIT
};
class TheGame : public CEvent {
	private :
		bool gameOn;
		SDL_Surface* ecran;
//		SDL_Surface* ecranTest;
		CAnimation 	 animShip;
		CEntity entity1;
		CGrayalien entity2;
		CEnemy entity3;
		CPlayer blueBlur;
		Menu menu;
		enum state_t state;
		Log log;
		//Uint8 *keyStates;

	public :
		TheGame();
		int onExecute();
	public :

		bool onInit(); //Initialisation du jeu
		void onEvent(SDL_Event* Event);

        void onExit();
		void onLoop(); //Le jeu "tourne"
		void onRender(); //Gestion de l'affichage
		void onRenderTitle(SDL_Surface* source, int x = 0, int y = 0);
		void onRenderHome(SDL_Surface* source, int x = 0, int y = 0);
		void onCleanup(); //Fermeture
		//void onKeyStates();
		void onClear();
		void onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
		void onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
		bool onAppearEnemies(float ftime);

		void initMenu(); //Init menu
		SDL_Surface* initTitleGame(); //Init title Game
		void onLoopMenu(); //Le menu tourne
};

#endif
