#pragma once

#include <SFML/Graphics.hpp>

class Paddle {
public:
	Paddle();
	Paddle(float width, float height);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f pos);
	void setPosition(float x, float y);
	void setOrigin(float x, float y);
	void draw(sf::RenderWindow& window);
	float getWidth();
	float getHeight();
	void setFillColor(sf::Color color);
private:
	sf::RectangleShape paddle;
	sf::Vector2f pos;
};