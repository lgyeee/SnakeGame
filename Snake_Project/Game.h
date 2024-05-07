// Game.h
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Fruit.h"

// 表示整個貪吃蛇遊戲的類
class Game {
public:
    // 建構函數：初始化遊戲窗口和元件
    Game();

    // 運行遊戲循環
    void run();

private:
    // 處理用戶輸入事件
    void handleInput();

    // 更新遊戲狀態
    void update();

    // 渲染遊戲畫面
    void render();

    sf::RenderWindow window; // 渲染窗口
    Snake snake;             // 貪吃蛇
    Fruit fruit;             // 水果
    sf::Texture tileTexture, entityTexture; // 紋理
    sf::Sprite tileSprite, entitySprite;    // 精靈
};

#endif // GAME_H
