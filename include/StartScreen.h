#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <SFML/Graphics.hpp>

class StartScreen {
public:
    StartScreen(float width, float height);
    void draw(sf::RenderWindow& window);

private:
    sf::Font font;
    sf::Text title;
    sf::Text instructions;
};

#endif // STARTSCREEN_H
