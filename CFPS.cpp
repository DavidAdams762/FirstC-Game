#include "CFPS.h"
#include <iostream>
CFPS CFPS::FPSControl;

CFPS::CFPS() {
	oldTime = 0;
	lastTime = 0;
	inGameTime = 0;
	speedFactor = 0;

	frames = 0;
	numFrames = 0;
}

void CFPS::onLoop() {
	if (oldTime + 1000 < SDL_GetTicks()){
		oldTime = SDL_GetTicks();
		if (inGameTime == 0)
			inGameTime = SDL_GetTicks();
		numFrames = frames;
		frames = 0;
		std::cout << numFrames << std::endl;
	}

    if (lastTime == 0)
        lastTime = SDL_GetTicks();
	speedFactor = ((SDL_GetTicks() - lastTime) / 1000.0f) * 32.0f;
	lastTime = SDL_GetTicks();
	frames++;
}

int CFPS::getFPS(){
	return numFrames;
}

float CFPS::getSpeedFactor(){
	return speedFactor;
}

float CFPS::getInGameTime(){
	return inGameTime;
}

void CFPS::resetInGameTime(){
	inGameTime = 0;
}
