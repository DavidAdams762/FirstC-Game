Scoring::Scoring(){
}

Score resetScore(Score score) {
	score.shots = 0;
	score.points = 0;
	score.level = 1;
	score.passed = 0;
	return score;
}

Score updateScore(CEnemy enemy, Score score) {
	score.points = enemy.score;
    return score;
}

enum stateGameOver(CPlayer player) {
	if (player->getLife() < 0)
    {
      state = game_over;
    }
    return state;
}
