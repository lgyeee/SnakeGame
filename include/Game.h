// Game.h
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Fruit.h"
#include "ScoreBoard.h"
#include "StartScreen.h"

// ��ܾ�ӳg�Y�D�C������
class Game {
public:
    // �غc��ơG��l�ƹC�����f�M����
    Game();

    // �B��C���`��
    void run();

private:
    // �B�z�Τ��J�ƥ�
    void handleInput();

    // ��s�C�����A
    void update();

    // ��V�C���e��
    void render();

    sf::RenderWindow window; // ��V���f
    Snake snake;             // �g�Y�D
    Fruit fruit;             // ���G
    ScoreBoard scoreboard;   //�p���O
    StartScreen startScreen; //�_�l�e��
    sf::Texture tileTexture, snakeheadTexture, snakeBodyTexture, fruitTexture, gameOverTextTexture; // ���z
    sf::Sprite tileSprite, snakeheadSprite, snakeBodySprite, fruitSprite, gameOverTextSprite;    // ���F
    sf::Font font, font2, font3, font4, font5;
    sf::Text scoreText;
    sf::RectangleShape scoreBackground;
    bool isPaused; // �Ȱ����A
    void reset(); // ���m�C��
    bool gameOver; // �C���������A
    int gamestate;
};

#endif // GAME_H
