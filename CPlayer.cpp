#include "CPlayer.h"

CPlayer::CPlayer() {
	this->lives = HERO_LIFE;
	this->typeShot = "images/player-laser.png";
	this->isShot = false;
	invulnerable = 0.0f;
}

bool CPlayer::onLoad(char* file, int width, int height, int maxFrames){
	if(CEntity::onLoad(file,width,height,maxFrames) == false) return false;
	return true;
}

void CPlayer::onLoop(){
	if (isShot == true)
		shoot(typeShot);
	CEntity::onLoop();
}

void CPlayer::onRender(SDL_Surface* surface) {
	CEntity::onRender(surface);
}

void CPlayer::onCleanup(){
	CEntity::onCleanup();
}

void CPlayer::onAnimate(){
	if(speedX != 0) {
		animControl.maxFrames = HERO_MAX_FRAME;
	}
	else {
		animControl.maxFrames = 0;
	}
	CEntity::onAnimate();
}

bool CPlayer::onCollision(CEntity* entity) {
    if(entity->getEntityName() == "grayalien") {
    	if(!estInvulnerable()){
			this->lives -= 50;
			if (this->lives < 0)
				dead = true;
		}
    }
	else if(entity->getEntityName() == "laser") {
		if(entity->moveDown == true){
	    	if(!estInvulnerable()){
	    		this->lives -= entity->lives;
	    		if (this->lives < 0)
	    			dead = true;
			}
    	}
    }
	return true;

}

bool CPlayer::posValidEntity(CEntity* entity, int newX, int newY) {
	if(this != entity && entity != NULL && entity->dead == false &&
		entity->collides(newX + colX, newY + colY, width - colWidth - 1 , height - colHeight - 1 ) == true) {
		CEntityCol entityCol;
		entityCol.entityA = this;
		entityCol.entityB = entity;
		//std::cout<< "coordonnes x " <<  entity->x << endl;
		//std::cout<< "taille " << entity->width << endl;
		//std::cout<< "coordonnes endx " << entity->x + entity->width << endl;

		CEntityCol::entityColList.push_back(entityCol);

	}
	return true;
}

string CPlayer::getEntityName() {
	return "hero";
}

void CPlayer::shoot(string typeShot) {
   if (lastShoot + 250 < SDL_GetTicks()) {
   	    addBullet(this->x, this->y, (string)typeShot);
   	    lastShoot = SDL_GetTicks();
   	}
}

 void CPlayer::addBullet(float positionX, float positionY,string type) {
	CBullet* bullet = new CBullet();

	string str = type;
	const char *pStr = str.c_str();

	bullet->onLoad((char*)pStr, 2, 8, 1);
	bullet->setPosition(positionX + 25.0f, positionY - 10.0f);
	bullet->moveUp = true;
	bullet->moveDown = false;

	entityList.push_back(bullet);
 }

 bool CPlayer::estInvulnerable(){
 	if ((SDL_GetTicks() - invulnerable) /1000 < 2.0){
 		return true;
 	}
 	invulnerable = SDL_GetTicks();
 	return false;
 }
