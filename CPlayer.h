#ifndef _CPLAYER_H_
#define _CPLAYER_H_
#include "CEntity.h"
#include <string>
#include <iostream>
#include "Define.h"
#include "CFPS.h"
#include "CBullet.h"
class CPlayer : public CEntity {

public:
	CPlayer();
	string typeShot;
	bool isShot;
	float invulnerable;
	bool onLoad(char* file, int width, int height, int maxFrames);

	void onLoop();

	void onRender(SDL_Surface* surface);

	void onCleanup();

	void onAnimate();

	bool onCollision(CEntity* entity);

	bool posValidEntity(CEntity* entity, int newX, int newY);

	bool estInvulnerable();

	 void shoot(string typeShot);
            void addBullet(float x, float y,string type);

	string getEntityName();

};
#endif
