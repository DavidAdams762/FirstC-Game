#include "TheGame.h"

void TheGame::onLoop() {
	//	animShip.onAnimate();
	for(int i = 0;i < CEntity::entityList.size();i++) {
		if(!CEntity::entityList[i]) continue;

		CEntity::entityList[i]->onLoop();
        if(CEntity::entityList[i]->y > WHEIGHT) {
            CEntity::entityList.erase(CEntity::entityList.begin() + i);
        }
        else if(CEntity::entityList[i]->y < 0){
            if (CEntity::entityList[i]->getEntityName() == "lazer" && CEntity::entityList[i]->moveUp == true)
                CEntity::entityList.erase(CEntity::entityList.begin() + i);       
        }
        if(CEntity::entityList[i]->dead == true){
            CEntity::entityList[i]->onCleanup();
            CEntity::entityList.erase(CEntity::entityList.begin() + i);
        }
	}

    for(int i = 0;i < CEntityCol::entityColList.size();i++) {
        CEntity* entityA = CEntityCol::entityColList[i].entityA;
        CEntity* entityB = CEntityCol::entityColList[i].entityB;
     
        if(entityA == NULL || entityB == NULL) continue;
     
        if(entityA->onCollision(entityB)) {
            entityB->onCollision(entityA);
        }
    }
 
    CEntityCol::entityColList.clear();

	CFPS::FPSControl.onLoop();
    CLevel::level.onLoop();
}

void TheGame::onLoopMenu() {
	if(menu.getIsSelect()) {
        //Test parmi les choix possibles
        switch(menu.getCurrentIndex()) {
            case MENU_GAME:
                state = game;
                cout << "Menu Game" << endl << flush;
            break;
            case MENU_SCORE:
                cout << "Menu Score" << endl << flush;
            break;
            case MENU_OPTION:
                cout << "Menu Option" << endl << flush;
            break;
            case MENU_QUIT:
                cout << "Menu Quitter" << endl << flush;
                onExit();
            break;
        }
    }
}
