// Game.cpp
#include "Game.h"
#include <iostream>

const int GRID_WIDTH = 30; // 網格寬度
const int GRID_HEIGHT = 20; // 網格高度
const int TILE_SIZE = 16; // 單位格子尺寸
const int WINDOW_WIDTH = TILE_SIZE * GRID_WIDTH + 200; // 窗口寬度
const int WINDOW_HEIGHT = TILE_SIZE * GRID_HEIGHT; // 窗口高度

// 建構函數：初始化遊戲窗口和元件
Game::Game() :
    snake(),
    fruit(),
    scoreboard(),
    window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake Game"),
    isPaused(false),
    gameOver(false) 
    {
    tileTexture.loadFromFile("white.png");
    fruitTexture.loadFromFile("apple.png");
    tileSprite.setTexture(tileTexture);
    fruitSprite.setTexture(fruitTexture);

    snakeBodyTexture.loadFromFile("snakebody.png");
    snakeBodySprite.setTexture(snakeBodyTexture);

    snakeheadTexture.loadFromFile("snakehead.png");
    snakeheadSprite.setTexture(snakeheadTexture);
    if (!font2.loadFromFile("font2.ttf")) {
        // 错误处理
    }
    if (!font.loadFromFile("font.ttf")) {
        // 错误处理
    }


    scoreText.setFont(font2);
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setStyle(sf::Text::Bold);

    scoreBackground.setSize(sf::Vector2f(200, 50));
    scoreBackground.setFillColor(sf::Color(0, 0, 0, 150));
    scoreBackground.setPosition(5, 5);

}


void Game::run() {
    //創建一個時鐘物件
    sf::Clock clock;
    float timer = 0.0f, delay = 0.1f;

    // 主遊戲循環：當窗口未關閉時繼續執行
    while (window.isOpen()) {
        // 計算自上次重置以來的經過時間（秒）
        float elapsedTime = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += elapsedTime;

        handleInput();

        if (!isPaused && timer > delay && !gameOver) {
            timer = 0.0f;
            update();
        }

        render();
    }
}

// 處理用戶輸入事件
// void Game::handleInput() {
//     sf::Event event;
//     while (window.pollEvent(event)) {
//         if (event.type == sf::Event::Closed) {
//             window.close();
//         }
//         // if (event.type == sf::Event::KeyPressed){
//         //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
            
//         // }
//         // 更改蛇的方向
//         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) snake.changeDirection(Left);
//         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) snake.changeDirection(Right);
//         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) snake.changeDirection(Up);
//         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) snake.changeDirection(Down);
//         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
//             isPaused = !isPaused; // 切换暂停状态
//         }
//         // if (event.key.code == sf::Keyboard::P) {
//         //         isPaused = !isPaused; // 切换暂停状态
//         //     }
//     }
// }

// 處理输入事件
void Game::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            // debug: 印出所有KeyPressed
            std::cout << "Key pressed: " << event.key.code << std::endl;

            // 檢查是否按下 P
            if (event.key.code == sf::Keyboard::P) {
                isPaused = !isPaused; // 切換暫停狀態
            }
            // 檢查是否按下 ESC
            if (event.key.code == sf::Keyboard::Escape) {
                window.close(); // 關掉視窗
            }
            // 檢查是否按下 R
            if (event.key.code == sf::Keyboard::R) {
                reset();
            }
        }
    }

    // 更改蛇的方向
    if (!isPaused) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) snake.changeDirection(Left);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) snake.changeDirection(Right);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) snake.changeDirection(Up);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) snake.changeDirection(Down);
    }
}


// 更新遊戲狀態
void Game::update() {

    snake.move();

    if(snake.isSelfCollision()){
        snake.modifiedSnake();
        int newSize = snake.getBody().size();
        scoreboard.resetScore();
        int addPoints = newSize * 10 - 10;
        scoreboard.increaseScore(addPoints);
    }

    if(snake.isOutOfBounds()) {
        gameOver = true;
        return;
    }

    // 如果蛇吃到水果，增加長度並重新生成水果
    if (snake.getHeadPosition() == sf::Vector2i(fruit.getX(), fruit.getY())) {
        snake.grow();
        fruit.respawn();
        scoreboard.increaseScore(10);
    }
}

void Game::render() {
    window.clear();
    // 绘制背景格子
    for (int i = 0; i < GRID_WIDTH; ++i) {
        for (int j = 0; j < GRID_HEIGHT; ++j) {
            // 计算矩形的位置和大小
            sf::RectangleShape rect(sf::Vector2f(TILE_SIZE, TILE_SIZE));
            rect.setPosition(i * TILE_SIZE, j * TILE_SIZE);

            // 交替绘制不同颜色的矩形以模拟网格线
            if ((i + j) % 2 == 0) {
                rect.setFillColor(sf::Color(117, 191, 255)); // 淺藍色
            } else {
                rect.setFillColor(sf::Color(117, 185, 255)); // 藍色
            }

            // 绘制矩形
            window.draw(rect);
        }
    }

//     // 绘制水平网格线
// for (int i = 0; i <= GRID_HEIGHT; ++i) {
//     sf::Vertex line[] = {
//         sf::Vertex(sf::Vector2f(0, i * TILE_SIZE)),
//         sf::Vertex(sf::Vector2f(GRID_WIDTH * TILE_SIZE, i * TILE_SIZE))
//     };
//     window.draw(line, 2, sf::Lines);
// }

// // 绘制垂直网格线
// for (int i = 0; i <= GRID_WIDTH; ++i) {
//     sf::Vertex line[] = {
//         sf::Vertex(sf::Vector2f(i * TILE_SIZE, 0)),
//         sf::Vertex(sf::Vector2f(i * TILE_SIZE, GRID_HEIGHT * TILE_SIZE))
//     };
//     window.draw(line, 2, sf::Lines);
// }

    // 繪製蛇頭
    sf::Vector2i headPos = snake.getHeadPosition();
    snakeheadSprite.setPosition(headPos.x * TILE_SIZE, headPos.y * TILE_SIZE);
    window.draw(snakeheadSprite);

    // 繪製蛇身
    const auto& body = snake.getBody();
    for (size_t i = 1; i < body.size(); ++i) {
        snakeBodySprite.setPosition(body[i].x * TILE_SIZE, body[i].y * TILE_SIZE);
        window.draw(snakeBodySprite);
    }

    for (int i = GRID_WIDTH; i < WINDOW_WIDTH ; i = i + TILE_SIZE) {
        for (int j = 0; j < WINDOW_HEIGHT;j = j + TILE_SIZE) {
        tileSprite.setPosition(i * TILE_SIZE, j * TILE_SIZE);
        window.draw(tileSprite);
        }
    }

    // 繪製水果
    fruitSprite.setPosition(fruit.getX() * TILE_SIZE, fruit.getY() * TILE_SIZE);
    window.draw(fruitSprite);

     // 如果遊戲暫停，顯示paused
    if (isPaused) {
        sf::Text pausedText;
        pausedText.setFont(font);
        pausedText.setCharacterSize(30);
        pausedText.setFillColor(sf::Color::Yellow);
        pausedText.setString("Paused");
        pausedText.setPosition(WINDOW_WIDTH - pausedText.getGlobalBounds().width - 50,
                               WINDOW_HEIGHT/2  - pausedText.getGlobalBounds().height -50);
        window.draw(pausedText);
    }

    //繪製背景分數
    scoreText.setString("Score: " + std::to_string(scoreboard.getScore()));
    scoreText.setPosition(window.getSize().x - 150, window.getSize().y - 100); // 调整文本位置，确保不会与背景重叠
    scoreBackground.setPosition(window.getSize().x - 150, window.getSize().y ); 
    scoreText.setFillColor(sf::Color(100, 40, 30, 255));
    scoreBackground.setFillColor(sf::Color(255, 255, 255, 255));
    window.draw(scoreBackground);
    window.draw(scoreText);

    // 如果遊戲結束，顯示Game Over
    if (gameOver) {
        sf::Text gameOverText;
        gameOverText.setFont(font);
        gameOverText.setCharacterSize(30);
        gameOverText.setFillColor(sf::Color::Red);
        gameOverText.setString("Game Over");
        gameOverText.setPosition(WINDOW_WIDTH/2 - gameOverText.getGlobalBounds().width/2,
                                 WINDOW_HEIGHT/2 - gameOverText.getGlobalBounds().height/2);
        window.draw(gameOverText);
    }

    // 顯示已繪製的畫面
    window.display();
}

// 重置遊戲
void Game::reset() {
    snake = Snake();
    fruit.respawn();
    scoreboard.resetScore();
    isPaused = false;
    gameOver = false;
}
