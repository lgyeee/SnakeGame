#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <vector>

class ScoreBoard {
public:
    ScoreBoard();//�غc���

    int getScore();//������ƪ�����

    int increaseScore(int value); //�W�[����

    int decreaseScore(int value);//��֤���

    void resetScore();//���m���Ƭ�10

private:
    int score; //����
};

#endif
