#include "ScoreBoard.h"

ScoreBoard::ScoreBoard() :score(10) {}

int ScoreBoard::getScore() {
    return score;
}
void ScoreBoard::increaseScore(int value) {
    score += value;
}
void ScoreBoard::decreaseScore(int value) {
    score -= value;
}
void ScoreBoard::resetScore() {
    score = 10;
}
