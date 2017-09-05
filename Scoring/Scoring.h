#ifndef _SCORING_H_
#define _SCORING_H_

#include "Score.h"

class Scoring {
	private :

	public :
		Scoring();
		Score resetScore(Score score);

		Score updateScore(CEnemy enemy, Score score);
		enum stateGameOver(CPlayer player);
};

#endif