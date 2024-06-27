// Fruit.cpp
#include "Fruit.h"
#include <cstdlib>
#include <ctime>

// �غc��ơG��l�Ƥ��G���H���ͦ���m
Fruit::Fruit() {
    std::srand(static_cast<unsigned>(std::time(0)));
    respawn();
}

// ���s�H���ͦ����G����m
void Fruit::respawn() {
    x = std::rand() % 30; // ����e��
    y = std::rand() % 20; // ���氪��
}

// ������G����y��
int Fruit::getX() const {
    return x;
}

// ������G���a�y��
int Fruit::getY() const {
    return y;
}
