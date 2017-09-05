#include "TheGame.h"
using namespace std;



TheGame::TheGame() {
	ecran = NULL;
//	ecranTest = NULL;
	gameOn = true;
	Uint8 *keyStates = 0;
	state = home;
}

int TheGame::onExecute() {
    log.deleteFile();
	if(onInit() == false){
        log.writeLog(ERROR, "onInit() Failed << TheGame.cpp");
		return -1;
	}
	SDL_Event event;
    // Variables Chrono
    Uint32 old_time, current_time;
    float ftime;
    current_time = SDL_GetTicks();
	SDL_Surface *texteTitle = NULL;

    initMenu();
	texteTitle = initTitleGame();
	while(gameOn) {

		while(SDL_PollEvent(&event)){
			onEvent(&event);
		}

		if (state == home) {
            onRenderHome(texteTitle, 120, 200);
		}
		else if (state == menus) {
			onLoopMenu();
	        menu.OnRender(ecran);
			onRenderTitle(texteTitle, 180);
		}
		else if (state == game) {
		    onLoop();
            onRender();
            //onKeyStates();
		}

		//Chrono
		old_time = current_time;
        current_time = SDL_GetTicks();
        ftime = current_time / 1000.0f;

       // cout << ftime << endl;
       // cout << "-" << endl;

            	//TODO : create CEnemy dynamically
        //	    if (ftime >= 0.0f) {
        //	    	if ((int)ftime % 2 == 1) {
        //	        	entity2.moveSet(1.0f, 1.0f);
        //	        }
        //	        else {
        //	        	entity2.moveSet(-1.0f, 1.0f);
        //	        }
        //	    }
        //	    if ((int)ftime % 10 == 0 && ftime > 10.0f) {
        //		    onAppearEnemies(ftime);
        //		}
        //
        //		if (ftime >= 0.0f) {
        //	    	if ((int)ftime % 2 == 1) {
        //	        	entity3.moveSet(2.0f, 2.0f);
        //	        }
        //	        else {
        //	        	entity3.moveSet(2.0f, -2.0f);
        //	        }
        //	    }

        //keyStates = SDL_GetKeyState(NULL);
         onClear();
	}
	onCleanup();
	return 0;
}


int main(int argc, char* argv[]) {
	TheGame herc;
	return herc.onExecute();
}
