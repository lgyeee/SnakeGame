#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <vector>

class ScoreBoard {
public:
    ScoreBoard();//篶ㄧ计

    int getScore();//莉だ计

    int increaseScore(int value); //糤だ计

    int decreaseScore(int value);//搭ぶだ计

    void resetScore();//竚だ计10

private:
    int score; //だ计
};

#endif
