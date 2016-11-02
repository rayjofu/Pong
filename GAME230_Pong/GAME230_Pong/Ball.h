#pragma once

#include <SFML/Graphics.hpp>

class Ball {
public:
	Ball();
	Ball(int radius, sf::Color color);
	void setColor(sf::Color color);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f newPos);
	void setPosition(float x, float y);
	float getSpeed();
	void setSpeed(float s);
	sf::Vector2f getVelocity();
	void setVelocity(sf::Vector2f newVel);
	void draw(sf::RenderWindow& window);
private:
	sf::Vector2f pos;
	int radius;
	float speed;
	sf::Vector2f vel;
	sf::CircleShape ball;
};