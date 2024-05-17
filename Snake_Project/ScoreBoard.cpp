#include "ScoreBoard.h"

ScoreBoard::ScoreBoard():score(0){}
    
int ScoreBoard::getScore(){
    return score;
}
int ScoreBoard::increaseScore(int value){
    score += value;
}
int ScoreBoard::decreaseScore(int value){
    score -= value;
}
void ScoreBoard::resetScore(){
    score = 0;
}
