#include "ScoreBoard.h"

//篶ㄧ计﹍てscore10
ScoreBoard::ScoreBoard() :score(10) {}

//莉だ计
int ScoreBoard::getScore() {
    return score;
}

//糤だ计
int ScoreBoard::increaseScore(int value) {
    score += value;
    return score;
}

//搭ぶだ计
int ScoreBoard::decreaseScore(int value) {
    score -= value;
    return score;
}

//竚だ计10
void ScoreBoard::resetScore() {
    score = 10;
}
