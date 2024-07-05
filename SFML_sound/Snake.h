// Snake.h
#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <SFML/Graphics.hpp>

// �T�|�w�q�D�����ʤ�V
enum Direction {
    Down,  // �V�U
    Left,  // �V��
    Right, // �V�k
    Up     // �V�W
};

// �w�q�D����
class Snake {
public:
    // �غc��ơG��l�ƳD����l��m�P��V
    Snake();

    // ���ܳD�����ʤ�V
    void changeDirection(Direction dir);

    // Direction getter
    Direction getDirection() const;

    // ���ʳD
    void move();

    // �W�[�D������
    void grow();

    // ����D���Ҧ��`�I
    const std::vector<sf::Vector2i>& getBody() const;

    // ����D�Y����m
    sf::Vector2i getHeadPosition() const;

    bool isOutOfBounds() const; // �s�W����k�G�ˬd�D�Y�O�_�W�X���
    bool isSelfCollision() const; // �s�W����k�G�ˬd�D�O�_����ۤv
    void modifiedSnake();

private:
    std::vector<sf::Vector2i> body; // �D���Ҧ��`�I
    Direction direction;            // �D�����ʤ�V
    Direction newDirection;

};

#endif // SNAKE_H
