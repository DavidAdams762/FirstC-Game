#include "TheGame.h"
#include <iostream>

using namespace std;

void TheGame::onEvent(SDL_Event* event) {
	CEvent::onEvent(event);
}

void TheGame::onExit() {
    gameOn = false;
}

void TheGame::onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch(sym) {
        case SDLK_ESCAPE : {
            onExit();
            break;
        }
        case SDLK_LEFT : {
            blueBlur.moveLeft = true;
            break;
        }
        case SDLK_RIGHT : {
            blueBlur.moveRight = true;
            break;
        }
        case SDLK_UP : {
            if (state == menus)
                menu.moveUp();
            else if (state == game)
                blueBlur.moveUp = true;
            break;
        }
        case SDLK_DOWN : {
            if (state == menus)
                menu.moveDown();
            else if  (state == game)
                blueBlur.moveDown = true;
            break;
        }
        case SDLK_RETURN : {
            if (state == menus)
                menu.select();
            else if  (state == home)
                state = menus;
            break;
        }
        case SDLK_SPACE : {
            if (state == home)
                state = menus;
            if (state == game) {
               blueBlur.isShot = true;
            }

            break;
        }
        default : {

        }
    }
}
void TheGame::onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch(sym) {
        case SDLK_LEFT : {
            blueBlur.moveLeft = false;
            break;
        }
        case SDLK_RIGHT : {
            blueBlur.moveRight = false;
            break;
        }
        case SDLK_UP : {
            blueBlur.moveUp = false;
            break;
        }
        case SDLK_DOWN : {
            blueBlur.moveDown = false;
            break;
        }
        case SDLK_RETURN : {
            menu.setSelect(false);
        }
        case SDLK_SPACE : {
            if (state == game) {
               blueBlur.isShot = false;
            }
            break;
        }
        default : {

        }
    }
}
//void TheGame::onKeyStates() {
//    if (keyStates[SDLK_ESCAPE]) {
//       onExit();
//    }
//    if (keyStates[SDLK_LEFT]) {
//        entity1.x -= MOVE_SPEED_PLAYER;
//    }
//    if (keyStates[SDLK_RIGHT]) {
//        entity1.x += MOVE_SPEED_PLAYER;
//    }
//    if (keyStates[SDLK_DOWN]) {
//        entity1.y += MOVE_SPEED_PLAYER;
//    }
//    if (keyStates[SDLK_UP]) {
//        entity1.y -= MOVE_SPEED_PLAYER;
//    }
//}
