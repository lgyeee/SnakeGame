#include "ScoreBoard.h"

//�غc��ơG��l��score�Ȭ�10
ScoreBoard::ScoreBoard() :score(10) {}

//������ƪ�����
int ScoreBoard::getScore() {
    return score;
}

//�W�[����
int ScoreBoard::increaseScore(int value) {
    score += value;
    return score;
}

//��֤���
int ScoreBoard::decreaseScore(int value) {
    score -= value;
    return score;
}

//���m���Ƭ�10
void ScoreBoard::resetScore() {
    score = 10;
}
