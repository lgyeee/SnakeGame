// Game.cpp
#include "Game.h"

const int GRID_WIDTH = 30; // 網格寬度
const int GRID_HEIGHT = 20; // 網格高度
const int TILE_SIZE = 16; // 單位格子尺寸
const int WINDOW_WIDTH = TILE_SIZE * GRID_WIDTH; // 窗口寬度
const int WINDOW_HEIGHT = TILE_SIZE * GRID_HEIGHT; // 窗口高度

// 建構函數：初始化遊戲窗口和元件
Game::Game() :
    snake(),
    fruit(),
    window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake Game") {
    tileTexture.loadFromFile("white.png");
    entityTexture.loadFromFile("red.png");
    tileSprite.setTexture(tileTexture);
    entitySprite.setTexture(entityTexture);
}

// 運行遊戲循環
void Game::run() {
    sf::Clock clock;
    float timer = 0.0f, delay = 0.1f;

    while (window.isOpen()) {
        float elapsedTime = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += elapsedTime;

        handleInput();

        if (timer > delay) {
            timer = 0.0f;
            update();
        }

        render();
    }
}

// 處理用戶輸入事件
void Game::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }

    // 更改蛇的方向
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) snake.changeDirection(Left);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) snake.changeDirection(Right);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) snake.changeDirection(Up);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) snake.changeDirection(Down);
}

// 更新遊戲狀態
void Game::update() {
    snake.move();

    // 如果蛇吃到水果，增加長度並重新生成水果
    if (snake.getHeadPosition() == sf::Vector2i(fruit.getX(), fruit.getY())) {
        snake.grow();
        fruit.respawn();
    }
}

void Game::render() {
    window.clear();

    // 繪製背景格子
    for (int i = 0; i < GRID_WIDTH; ++i) {
        for (int j = 0; j < GRID_HEIGHT; ++j) {
            tileSprite.setPosition(i * TILE_SIZE, j * TILE_SIZE);
            window.draw(tileSprite);
        }
    }

    // 繪製蛇
    for (const auto& segment : snake.getBody()) {
        entitySprite.setPosition(segment.x * TILE_SIZE, segment.y * TILE_SIZE);
        window.draw(entitySprite);
    }

    // 繪製水果
    entitySprite.setPosition(fruit.getX() * TILE_SIZE, fruit.getY() * TILE_SIZE);
    window.draw(entitySprite);

    // 顯示已繪製的畫面
    window.display();
}
