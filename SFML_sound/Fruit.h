// Fruit.h
#ifndef FRUIT_H
#define FRUIT_H

// �w�q���G����
class Fruit {
public:
    // �غc��ơG��l�Ƥ��G���H���ͦ���m
    Fruit();

    // ���s�H���ͦ����G����m
    void respawn();

    // ������G����y��
    int getX() const;

    // ������G���a�y��
    int getY() const;

private:
    int x, y; // ���G���y��
};

#endif // FRUIT_H
