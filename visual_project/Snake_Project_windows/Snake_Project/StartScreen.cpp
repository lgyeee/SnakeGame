#include "StartScreen.h"

StartScreen::StartScreen(float width, float height) {
    if (!font.loadFromFile("Font/font2.ttf")) {
        // Handle error
        printf("test\n");
    }

    title.setFont(font);
    title.setString("Snake");
    title.setCharacterSize(70);
    title.setFillColor(sf::Color::White);
    title.setStyle(sf::Text::Bold);
    title.setPosition(sf::Vector2f(width / 2 - title.getGlobalBounds().width / 2, height / 4));

    instructions.setFont(font);
    instructions.setString("Press Enter to Start");
    instructions.setCharacterSize(50);
    instructions.setFillColor(sf::Color::White);
    instructions.setStyle(sf::Text::Italic);
    instructions.setPosition(sf::Vector2f(width / 2 - instructions.getGlobalBounds().width / 2, height / 2));
}

void StartScreen::draw(sf::RenderWindow& window) {
    window.draw(title);
    window.draw(instructions);
}
