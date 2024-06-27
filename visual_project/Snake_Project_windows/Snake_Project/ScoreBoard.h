#ifdef SCOREBOARD_H
#endif SCOREBOARD_H

#include <vector>

class ScoreBoard {
public:
    ScoreBoard();

    int getScore();
    void increaseScore(int value);
    void decreaseScore(int value);
    void resetScore();
private:
    int score;
};
