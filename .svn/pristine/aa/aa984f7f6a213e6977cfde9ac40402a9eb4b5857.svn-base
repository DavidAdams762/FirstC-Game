#ifndef _CFPS_H_
#define _CFPS_H_
#include "SDL/SDL.h"

class CFPS {
	public :
		static CFPS FPSControl;
	private :
		int 	oldTime;
		int 	lastTime;
		float 	speedFactor;
		int 	numFrames;
		int 	frames;
		float	inGameTime; 	

	public :
		CFPS();

		void 	onLoop();
		int 	getFPS();
		float	getSpeedFactor();
		void 	resetInGameTime();
		float	getInGameTime();
};
#endif