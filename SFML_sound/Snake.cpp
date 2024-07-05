// Snake.cpp
#include "Snake.h"

// �غc��ơG��l�ƳD����l��m�P��V
Snake::Snake() : direction(Down), newDirection(Down) {
    body.emplace_back(15, 10); // ��l��m
}

void Snake::changeDirection(Direction dir) {
    // �T�O���|�������Y
    if ((direction == Up && dir != Down) ||
        (direction == Down && dir != Up) ||
        (direction == Left && dir != Right) ||
        (direction == Right && dir != Left)) {
        newDirection = dir;
    }
}

Direction Snake::getDirection() const {
    return this->direction;
}
// ���ʳD
void Snake::move() {
    direction = newDirection;  // �b���ʤ��e��s��V

    std::vector<sf::Vector2i> newBody = body;
    // �N�C�@�`�D���V�e����
    for (size_t i = body.size() - 1; i > 0; --i) {
        newBody[i] = body[i - 1];
    }

    // �ھڤ�V���ʳD�Y
    switch (direction) {
    case Down: newBody[0].y += 1; break; // �V�U
    case Left: newBody[0].x -= 1; break; // �V��
    case Right: newBody[0].x += 1; break; // �V�k
    case Up: newBody[0].y -= 1; break; // �V�W
    }
    body = newBody;
}

void Snake::modifiedSnake() {
    std::vector<sf::Vector2i> newBody = body;
    // �ˬd�D�O�_����ۤv
    for (size_t i = 1; i < newBody.size(); ++i) {
        if (newBody[0] == newBody[i]) {
            newBody.resize(i); // ����ۤv���Y�u
            break;
        }
    }

    body = newBody;
}

// �ˬd�D�Y�O�_�W�X���
bool Snake::isOutOfBounds() const {
    return body[0].x < 0 || body[0].x >= 30 || body[0].y < 0 || body[0].y >= 30;
}
// �W�[�D������
void Snake::grow() {
    body.push_back(body.back());
}

// ����D���Ҧ��`�I
const std::vector<sf::Vector2i>& Snake::getBody() const {
    return body;
}

// ����D�Y����m
sf::Vector2i Snake::getHeadPosition() const {
    return body[0];
}

//�T�{�|���|�ۼ�
bool Snake::isSelfCollision() const {
    for (size_t i = 1; i < body.size(); ++i) {
        if (body[0] == body[i]) {
            return true;
        }
    }
    return false;
}

