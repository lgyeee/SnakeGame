// Mine.cpp
#include "../include/Mine.h"
#include <cstdlib>
#include <ctime>

// 建構函數：初始化地雷並隨機生成位置
Mine::Mine() {
    std::srand(static_cast<unsigned>(std::time(0)));
    respawn();
}

// 重新隨機生成地雷的位置
void Mine::respawn() {
    x = std::rand() % 30; // 網格寬度
    y = std::rand() % 20; // 網格高度
}

// 獲取地雷的橫座標
int Mine::getX() const {
    return x;
}

// 獲取地雷的縱座標
int Mine::getY() const {
    return y;
}
