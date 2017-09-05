#include "TheGame.h"

void TheGame::onCleanup() {
	SDL_FreeSurface(ecran);
//	SDL_FreeSurface(ecranTest);
	for(int i = 0;i < CEntity::entityList.size();i++) {
		if(!CEntity::entityList[i]) continue;

    	CEntity::entityList[i]->onCleanup();
	}

	CEntity::entityList.clear();
	TTF_Quit();
	SDL_Quit();
}
