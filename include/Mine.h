// Mine.h
#ifndef MINE_H
#define MINE_H

// 定義地雷的類
class Mine {
public:
    // 建構函數：初始化地雷並隨機生成位置
    Mine();

    // 重新隨機生成地雷的位置
    void respawn();

    // 獲取地雷的橫座標
    int getX() const;

    // 獲取地雷的縱座標
    int getY() const;

private:
    int x, y; // 地雷的座標
};

#endif // MINE_H
