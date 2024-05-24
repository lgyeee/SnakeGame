#ifdef SCOREBOARD_H
#endif SCOREBOARD_H

#include <vector>

class ScoreBoard{
public:
    ScoreBoard();

    int getScore();
    int increaseScore(int value);
    int decreaseScore(int value);
    void resetScore();
private:
    int score;
};
