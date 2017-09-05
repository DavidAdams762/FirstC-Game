#ifndef _SCORE_H_
#define _SCORE_H_

class Score {
	private :
		int shots;
        int points;
        int level;
        int passed;
	public :
		Score();

		int getShots();
        int getPoints();
        int getLevel();
        int getPassed();

		void setShots(int shots);
		void setPoints(int points);
		void setLevel(int level);
		void setPassed(int passed);
};

#endif