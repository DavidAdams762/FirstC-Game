#include "CEnemy.h"

CEnemy::CEnemy(){
	this->lives = 5;
	this->shots = 5;
	maxSpeedY = 1;
	moveDown = true;
	this->typeShot = "images/bad-laser.png";
	lastShoot = 0.0f;
}

CEnemy::~CEnemy(){

}

void CEnemy::shoot(string typeShot){

    if (lastShoot + 1000 < SDL_GetTicks()) {
	    addBullet(this->x, this->y, (string)typeShot);
	    lastShoot = SDL_GetTicks();
	}
}

void CEnemy::addBullet(float positionX, float positionY, string type){
	CBullet* bullet = new CBullet();

	string str = type;
    const char *pStr = str.c_str();

	bullet->onLoad((char*)pStr, 2, 8, 1);
	bullet->setPosition(positionX + 25.0f, positionY + 50.0f);

	entityList.push_back(bullet);
}

void CEnemy::trajectory() {
}

void CEnemy::onLoop(){
	shoot(typeShot);
	trajectory();
	CEntity::onLoop();
}

void CEnemy::onRender(SDL_Surface* surface) {
	CEntity::onRender(surface);
}

void CEnemy::onCleanup(){
	CEntity::onCleanup();
}

bool CEnemy::onCollision(CEntity* entity) {
	return true;
}


void CEnemy::onAnimate(){

}

bool CEnemy::posValid(int newX, int newY){
	bool retour = true;
	int startX = newX + colX;
	int startY = newY + colY;

	int endX = ((newX + colX) + width - colWidth - 1);
	int endY = ((newY + colY) + height - colHeight - 1);

	for(int i = 0; i < entityList.size(); i++){
		if(posValidEntity(entityList[i], newX, newY) == false) {
			retour = false;
		}
	}
	return retour;
}

bool CEnemy::posValidEntity(CEntity* entity, int newX, int newY){
	if(this != entity && entity != NULL && entity->dead == false &&
		entity->collides(newX + colX, newY + colY, width - colWidth - 1 , height - colHeight - 1 ) == true) {
		CEntityCol entityCol;
		entityCol.entityA = this;
		entityCol.entityB = entity;

		CEntityCol::entityColList.push_back(entityCol);

	}
	return true;
}

string CEnemy::getEntityName(){
	return "enemy";
}






