#include "CBullet.h"

CBullet::CBullet() {
	this->lives = BULLET_LIFE;
	speedY = 4;
	moveDown = true;
	lastShoot = 0.0f;
}

bool CBullet::posValid(int newX, int newY){
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

bool CBullet::posValidEntity(CEntity* entity, int newX, int newY){
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

bool CBullet::onCollision(CEntity* entity){
    if(entity->getEntityName() != "laser") {
    	if(this->moveDown == true){
    		if(entity->getEntityName() == "hero"){
    			dead = true;
    		}
    	}
    	else if (this->moveUp == true){
    		if(entity->getEntityName() == "grayalien")
    			dead = true;
    	}
	}
	return true;
}

string CBullet::getEntityName(){
	return "laser";
}



