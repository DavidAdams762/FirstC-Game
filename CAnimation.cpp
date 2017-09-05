#include "CAnimation.h"

CAnimation::CAnimation(){
	currentFrame = 0;
	maxFrames = 0;
	frameInc = 1;

	framerate = 100;
	oldTime = 0;

	oscillate = false;
}

void CAnimation::onAnimate(){
	if (oldTime + framerate > SDL_GetTicks()){
		return ;
	}

	oldTime = SDL_GetTicks();

	currentFrame += frameInc;

	if(oscillate){
		if(frameInc > 0){
			if(currentFrame >= maxFrames) {
				frameInc = -frameInc;
			}
		}
		else {
			if (currentFrame <= 0){
				frameInc = -frameInc;
			}
		}
	}
	else {
		if(currentFrame >= maxFrames - 1){
			currentFrame = 0;
		}
	}
}

void CAnimation::setFramerate(int rate){
	framerate = rate;
}

void CAnimation::setCurrentFrame(int frame){
	if (frame < 0 || frame > maxFrames)
		return ;

	currentFrame = frame;
}

int CAnimation::getCurrentFrame(){
	return currentFrame;
}
