#ifndef _CBULLET_H
#define _CBULLET_H
#include <string>
#include "CEntity.h"

class CBullet : public CEntity
{

	public:
		CBullet();
		bool posValid(int newX, int newY);
		bool posValidEntity(CEntity* entity, int newX, int newY);
		bool onCollision(CEntity* entity);
		string getEntityName();
};

#endif
