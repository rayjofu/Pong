#pragma once

#include "Ball.h"
#include "Paddle.h"
#include <SFML/Audio.hpp>

class Pong {
public:
	Pong();
	Pong(int width, int height);
	~Pong();
	void play();
private:
	Ball* ball1;
	Ball* ball2;
	Paddle* paddleLeft;
	Paddle* paddleRight;
	sf::RenderWindow* window;
	float dt;
	void update_state();
	void update_ball1();
	void update_ball2();
	void update_left_paddle();
	void update_right_paddle();
	void render_frame();
	float speedMultiplier;
	float initialSpeed;
	int scoreLeft;
	int scoreRight;
	sf::Text scoreLeftText;
	sf::Text scoreRightText;
	sf::Font textFont;
	sf::Text victoryText;
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;
	sf::Sound windowCollision;
	sf::SoundBuffer windowCollisionBuffer;
	sf::Sound paddleCollision;
	sf::SoundBuffer paddleCollisionBuffer;
	sf::Sound defeat;
	sf::SoundBuffer defeatBuffer;
	sf::Sound victory;
	sf::SoundBuffer victoryBuffer;
	sf::Sound countdown;
	sf::SoundBuffer countdownBuffer;
	Paddle* obstacle1;
	Paddle* obstacle2;
	bool roundover;
};