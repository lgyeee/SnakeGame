// Snake.cpp
#include "Snake.h"

// 建構函數：初始化蛇的初始位置與方向
Snake::Snake() : direction(Down) {
    body.emplace_back(15, 10); // 初始位置
}

// 改變蛇的移動方向
void Snake::changeDirection(Direction dir) {
    direction = dir;
}

// 移動蛇
void Snake::move() {
    std::vector<sf::Vector2i> newBody = body;
    // 將每一節蛇身向前移動
    for (size_t i = body.size() - 1; i > 0; --i) {
        newBody[i] = body[i - 1];
    }

    // 根據方向移動蛇頭
    switch (direction) {
        case Down: newBody[0].y += 1; break; // 向下
        case Left: newBody[0].x -= 1; break; // 向左
        case Right: newBody[0].x += 1; break; // 向右
        case Up: newBody[0].y -= 1; break; // 向上
    }

    // 如果蛇頭超出邊界，則從另一側循環
    if (newBody[0].x >= 30) newBody[0].x = 0;
    if (newBody[0].x < 0) newBody[0].x = 29;
    if (newBody[0].y >= 20) newBody[0].y = 0;
    if (newBody[0].y < 0) newBody[0].y = 19;

    // 檢查蛇是否撞到自己
    for (size_t i = 1; i < newBody.size(); ++i) {
        if (newBody[0] == newBody[i]) {
            newBody.resize(i); // 撞到自己後縮短
            break;
        }
    }

    body = newBody;
}

// 增加蛇的長度
void Snake::grow() {
    body.push_back(body.back());
}

// 獲取蛇的所有節點
const std::vector<sf::Vector2i>& Snake::getBody() const {
    return body;
}

// 獲取蛇頭的位置
sf::Vector2i Snake::getHeadPosition() const {
    return body[0];
}
