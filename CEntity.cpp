#include "CEntity.h"
#include <iostream>
std::vector<CEntity*> CEntity::entityList;

CEntity::CEntity(){
	imgEntity = NULL;
	x = y = 0.0f;
	width = height = 0;
	animState = 0;
	moveLeft = false;
	moveRight = false;
	moveDown = false;
	moveUp = false;
	lastShoot = 0.0f;

	type = ENTITY_TYPE_GENERIC;
	dead = false;
	flags = ENTITY_FLAG_NONE;

	speedX = 0;
	speedY = 0;

	accelX = 0;
	accelY = 0;

	maxSpeedX = 7;
	maxSpeedY = 7;

	currentFrameCol = 0;
	currentFrameRow = 0;
	//offset de colision
	colX = 0;
	colY = 0;
	//largeur et hauteur de celle-ci
	colHeight = 0;
	colWidth = 0;
}

CEntity::~CEntity(){
}

bool CEntity::onLoad(char* file, int width, int height, int maxFrames) {
	if((imgEntity = CSurface::onLoad(file)) == NULL)
		return false;

	this->width = width;
	this->height = height;

	animControl.maxFrames = maxFrames;

	return true;
}

void CEntity::onLoop(){
	if (moveLeft == false && moveRight == false){
		stopMoveHorizontal();
	}
	if(moveUp == false && moveDown == false){
		stopMoveVertical();
	}
	if(moveLeft){
		accelX = -1.0;

	}
	else if(moveRight){
		accelX = 1.0;
	}
	if(moveUp) {
		accelY = -1.0;
	}
	else if(moveDown){
		accelY = 1.0;
	}
	speedX += accelX * CFPS::FPSControl.getSpeedFactor();
	speedY += accelY * CFPS::FPSControl.getSpeedFactor();

	if(speedX > maxSpeedX)
		speedX = maxSpeedX;
	if(speedX < -maxSpeedX)
		speedX = -maxSpeedX;
	if(speedY > maxSpeedY)
		speedY = maxSpeedY;
	if(speedY < -maxSpeedY)
		speedY = -maxSpeedY;

	onAnimate();
	onMove(speedX, speedY);
}

void CEntity::onRender(SDL_Surface* display){
	if (display == NULL || display == NULL) return;
	CSurface::onDraw(display, imgEntity, x, y, currentFrameCol * width, (currentFrameRow + animControl.getCurrentFrame()) * height, width, height);
}

void CEntity::onCleanup(){
	if(imgEntity)
		SDL_FreeSurface(imgEntity);
	imgEntity = NULL;
}

void CEntity::onAnimate(){
	if(moveLeft) {
		currentFrameCol = 0;
	}
	else if (moveRight) {
		currentFrameCol = 1;
	}
	animControl.onAnimate();
}

bool CEntity::onCollision(CEntity* entity){
	return true;
}

void CEntity::onMove(float moveX, float moveY){
	if (moveX == 0 && moveY == 0) return ;

	double newX = 0;
	double newY = 0;

	moveX *= CFPS::FPSControl.getSpeedFactor();
	moveY *= CFPS::FPSControl.getSpeedFactor();

	if(moveX != 0){
		if(moveX >= 0)
			newX = CFPS::FPSControl.getSpeedFactor();
		else
			newX = -CFPS::FPSControl.getSpeedFactor();
	}
	if (moveY != 0){
		if(moveY >= 0)
			newY = CFPS::FPSControl.getSpeedFactor();
		else
			newY = -CFPS::FPSControl.getSpeedFactor();
	}
	while(true){

		if(posValid((int)(x + newX), (int)(y)))
			x += newX;
		else
			speedX = 0;
		if(posValid((int)(x), (int) (y + newY)))
			y += newY;
		else
			speedY = 0;

		moveX += -newX;
		moveY += -newY;

		if(newX > 0 && moveX <= 0) newX = 0;
		if(newX < 0 && moveX >= 0) newX = 0;

		if(newY > 0 && moveY <= 0) newY = 0;
		if(newY < 0 && moveY >= 0) newY = 0;

		if(moveX == 0) newX = 0;
		if(moveY == 0) newY = 0;

		if(moveX == 0 && moveY == 0) break;
		if(newX == 0 && newY == 0) break;
	}
}

void CEntity::stopMoveHorizontal() {
	if(speedX > 0)
		accelX = -1;
	if(speedX < 0)
		accelX = 1;
	if(speedX < 1.0f && speedX > -1.0f){
		accelX = 0;
		speedX = 0;
	}
}
void CEntity::stopMoveVertical(){
	if(speedY > 0)
		accelY = -1;
	if(speedY < 0)
		accelY = 1;
	if(speedY < 2.0f && speedY > -2.0f){
		accelY = 0;
		speedY = 0;
	}
}

bool CEntity::collides(int oX, int oY, int oW, int oH){
	int leftA, topA, bottomA, rightA;
	int leftB, topB, bottomB, rightB;

	int tX = (int) x + colX;
	int tY = (int) y + colY;

	leftA = tX;
	leftB = oX;

	rightA = leftA + width - 1 - colWidth;
	rightB = oX + oW - 1;

	topA = tY;
    topB = oY;

	bottomA = topA + height - 1 - colHeight;
	bottomB = oY + oH - 1;
	if(bottomA < topB) return false;
	if(topA > bottomB) return false;

	if(rightA < leftB) return false;
	if(leftA > rightB) return false;

	return true;
}

bool CEntity::posValid(int newX, int newY){
	bool retour = true;
	int startX = newX + colX;
	int startY = newY + colY;

	int endX = ((newX + colX) + width - colWidth - 1);
	int endY = ((newY + colY) + height - colHeight - 1);

	if(startX < 0 || startY < 0)
		retour = false;
	if(endX > WWIDTH || endY > WHEIGHT)
		retour = false;
	for(int i = 0; i < entityList.size(); i++){
		if(posValidEntity(entityList[i], newX, newY) == false) {
			retour = false;
		}
	}
	return retour;
}

bool CEntity::posValidEntity(CEntity* entity, int newX, int newY) {
	if(this != entity && entity != NULL && entity->dead == false &&
		entity->collides(newX + colX, newY + colY, width - colWidth - 1 , height - colHeight - 1 ) == true) {
		CEntityCol entityCol;
		entityCol.entityA = this;
		entityCol.entityB = entity;
		//std::cout<< "coordonnes x " <<  entity->x << endl;
		//std::cout<< "taille " << entity->width << endl;
		//std::cout<< "coordonnes endx " << entity->x + entity->width << endl;

		CEntityCol::entityColList.push_back(entityCol);

		return false;
	}
	return true;
}

void CEntity::setPosition(float x, float y) {
	this->x = x;
    this->y = y;
	this->departX = x;
	this->departY = y;
}

string CEntity::getEntityName(){
	return "entity";
}


void CEntity::addBullet(float positionX, float positionY){
}


void CEntity::shoot(string typeShot) {
}
