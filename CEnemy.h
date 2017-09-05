#ifndef _CENEMY_H_
#define _CENEMY_H_
#include "CEntity.h"
#include "CBullet.h"
using namespace std;

class CEnemy : public CEntity {
	private :
		int shots;
		string typeShot;
	protected :

	public :

        virtual void trajectory();
        void onLoop();
        virtual bool onCollision(CEntity* entity);
        void onRender(SDL_Surface* surface);
        void onCleanup();
        void onAnimate();
        void shoot(string typeShot);
        void addBullet(float x, float y,string type);
        bool posValid(int newX, int newY);
        bool posValidEntity(CEntity* entity, int newX, int newY);
        virtual string getEntityName();
        CEnemy();
		virtual ~CEnemy();
};

#endif
