#include "CGrayalien.h"
#include <iostream>
CGrayalien::CGrayalien() {
	this->typeShot = "images/bad-laser.png";
	this->lives = GRAY_ALIEN_LIFE;
}


void CGrayalien::trajectory() {
	float posX = (float)this->x;
	float posY = (float)this->y;

	float coteSquare = 50.0f;

	if (posY > departY + coteSquare && posX < departX + coteSquare) {
		//cout << "Right" <<endl;
        maxSpeedX = 1;
		moveDown = false;
        moveRight = true;
	}
	else if (posX >= departX + coteSquare && posY <  departY + (2 * coteSquare)){
		//cout << "Je redescent" <<endl;
		maxSpeedY = 1;
	    moveRight = false;
	    moveDown = true;
	}  /*
	else if (posX >= departX && posY >= departY + (1.5f * coteSquare)) {
	    cout << "Up" <<endl;
	    moveLeft = false;
	    moveUp = true;
	    maxSpeedY = 1;
    }
	else if (posY > departY + (2 * coteSquare) && posX >= departX) {
		cout << "Left" <<endl;
        moveDown = false;
        moveLeft = true;
        maxSpeedX = 1;
	}   */
	else {
        //cout << "Down" <<endl;
		moveLeft = false;
		moveUp = false;
		moveRight = false;
        moveDown = true;
	    maxSpeedY = 1;
	}
}

bool CGrayalien::onCollision(CEntity* entity){
    if(entity->getEntityName() == "hero") {
			dead = true;
    }
    else if (entity->getEntityName() == "laser") {
    	if(entity->moveUp == true){
    		this->lives -= entity->lives;
    		if (this->lives < 0)
    			dead = true;
    	}
    }
    return true;
}
string CGrayalien::getEntityName(){
	return "grayalien";
}

