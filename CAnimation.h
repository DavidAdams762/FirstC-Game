#ifndef _CANIMATION_H_
#define _CANIMATION_H_

#include "SDL/SDL.h"

class CAnimation {
	private :
		int currentFrame;
		int frameInc;

		int framerate;
		long oldTime;

	public :
		int maxFrames;
		bool oscillate;

		CAnimation();
		void onAnimate();

		void setFramerate(int rate);
		void setCurrentFrame(int frame);

		int getCurrentFrame();
};

#endif