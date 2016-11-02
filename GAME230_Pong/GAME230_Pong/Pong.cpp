#include "Pong.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

using namespace sf;
#include <iostream>
using namespace std;

Pong::Pong() {
	window = new RenderWindow(VideoMode(800.f, 600.f), "Pong");
	ball1 = new Ball(10.f, Color::Red);
	ball2 = new Ball(10.f, Color::Red);

	paddleLeft = new Paddle(20.f, 90.f);
	paddleLeft->setOrigin(0, paddleLeft->getHeight() / 2);
	paddleLeft->setFillColor(Color::Blue);

	paddleRight = new Paddle(20.f, 90.f);
	paddleRight->setOrigin(paddleRight->getWidth(), paddleRight->getHeight() / 2);
	paddleRight->setFillColor(Color::Green);

	obstacle1 = new Paddle(20.f, 90.f);
	obstacle1->setOrigin(paddleLeft->getWidth() / 2, paddleLeft->getHeight() / 2);
	obstacle1->setFillColor(Color::White);
	obstacle1->setPosition(window->getSize().x / 2, window->getSize().y / 3);

	obstacle2 = new Paddle(20.f, 90.f);
	obstacle2->setOrigin(paddleLeft->getWidth() / 2, paddleLeft->getHeight() / 2);
	obstacle2->setFillColor(Color::White);
	obstacle2->setPosition(window->getSize().x / 2, window->getSize().y * 2 / 3);

	initialSpeed = 500.f;
	speedMultiplier = 1.1f;
	srand(time(NULL));

	if (!textFont.loadFromFile("arial.ttf")) {
		cout << "Font [ arial.ttf ] not found in project directory!" << endl;
	}
	
	scoreLeftText.setFont(textFont);
	scoreLeftText.setCharacterSize(24);
	scoreLeftText.setColor(Color::Blue);
	scoreLeftText.setPosition(window->getSize().x / 3, window->getSize().y / 3);

	scoreRightText.setFont(textFont);
	scoreRightText.setCharacterSize(24);
	scoreRightText.setColor(Color::Green);
	scoreRightText.setPosition(window->getSize().x * 2 / 3, window->getSize().y / 3);

	victoryText.setFont(textFont);
	victoryText.setCharacterSize(48);
	victoryText.setColor(Color::Red);
	victoryText.setPosition(window->getSize().x / 2, window->getSize().y / 2);

	if (!backgroundTexture.loadFromFile("pong_background.png")) {
		cout << "Image [ pong_background.png ] not found in project directory!" << endl;
		return;
	}
	backgroundSprite = Sprite(backgroundTexture);
	backgroundSprite.setScale(window->getSize().x / backgroundSprite.getLocalBounds().width, window->getSize().y / backgroundSprite.getLocalBounds().height);

	if (!windowCollisionBuffer.loadFromFile("window_collision.wav")) {
		cout << "Audio [ window_collision.wav ] not found in project directory!" << endl;
		return;
	}
	windowCollision.setBuffer(windowCollisionBuffer);
	
	if (!paddleCollisionBuffer.loadFromFile("paddle_collision.wav")) {
		cout << "Audio [ paddle_collision.wav ] not found in project directory!" << endl;
		return;
	}
	paddleCollision.setBuffer(paddleCollisionBuffer);

	if (!victoryBuffer.loadFromFile("victory.wav")) {
		cout << "Audio [ victory.wav ] not found in project directory!" << endl;
		return;
	}
	victory.setBuffer(victoryBuffer);

	if (!defeatBuffer.loadFromFile("defeat.wav")) {
		cout << "Audio [ defeat.wav ] not found in project directory!" << endl;
		return;
	}
	defeat.setBuffer(defeatBuffer);

	if (!countdownBuffer.loadFromFile("countdown.wav")) {
		cout << "Audio [ countdown.wav ] not found in project directory!" << endl;
		return;
	}
	countdown.setBuffer(countdownBuffer);
}

Pong::Pong(int width, int height) {
	window = new RenderWindow(VideoMode(width, height), "Pong");
	ball1 = new Ball(10.f, Color::Red);
	ball2 = new Ball(10.f, Color::Red);

	paddleLeft = new Paddle(20.f, 90.f);
	paddleLeft->setOrigin(0, paddleLeft->getHeight() / 2);
	paddleLeft->setFillColor(Color::Blue);

	paddleRight = new Paddle(20.f, 90.f);
	paddleRight->setOrigin(paddleRight->getWidth(), paddleRight->getHeight() / 2);
	paddleRight->setFillColor(Color::Green);

	obstacle1 = new Paddle(20.f, 90.f);
	obstacle1->setOrigin(paddleLeft->getWidth() / 2, paddleLeft->getHeight() / 2);
	obstacle1->setFillColor(Color::White);
	obstacle1->setPosition(window->getSize().x / 2, window->getSize().y / 3);

	obstacle2 = new Paddle(20.f, 90.f);
	obstacle2->setOrigin(paddleLeft->getWidth() / 2, paddleLeft->getHeight() / 2);
	obstacle2->setFillColor(Color::White);
	obstacle2->setPosition(window->getSize().x / 2, window->getSize().y * 2 / 3);

	initialSpeed = 500.f;
	speedMultiplier = 1.1f;
	srand(time(NULL));

	if (!textFont.loadFromFile("arial.ttf")) {
		cout << "font not found!" << endl;
	}

	scoreLeftText.setFont(textFont);
	scoreLeftText.setCharacterSize(24);
	scoreLeftText.setColor(Color::Blue);

	scoreRightText.setFont(textFont);
	scoreRightText.setCharacterSize(24);
	scoreRightText.setColor(Color::Green);

	victoryText.setFont(textFont);
	victoryText.setCharacterSize(48);
	victoryText.setColor(Color::Red);
	victoryText.setPosition(window->getSize().x / 2, window->getSize().y / 2);

	if (!backgroundTexture.loadFromFile("pong_background.png")) {
		cout << "imagine not found!" << endl;
	}
	backgroundSprite = Sprite(backgroundTexture);

	if (!windowCollisionBuffer.loadFromFile("window_collision.wav")) {
		cout << "Audio [ window_collision.wav ] not found in project directory!" << endl;
	}
	windowCollision.setBuffer(windowCollisionBuffer);

	if (!paddleCollisionBuffer.loadFromFile("paddle_collision.wav")) {
		cout << "Audio [ paddle_collision.wav ] not found in project directory!" << endl;
	}
	paddleCollision.setBuffer(paddleCollisionBuffer);

	if (!victoryBuffer.loadFromFile("victory.wav")) {
		cout << "Audio [ victory.wav ] not found in project directory!" << endl;
		return;
	}
	victory.setBuffer(victoryBuffer);

	if (!defeatBuffer.loadFromFile("defeat.wav")) {
		cout << "Audio [ defeat.wav ] not found in project directory!" << endl;
		return;
	}
	defeat.setBuffer(defeatBuffer);

	if (!countdownBuffer.loadFromFile("countdown.wav")) {
		cout << "Audio [ countdown.wav ] not found in project directory!" << endl;
		return;
	}
	countdown.setBuffer(countdownBuffer);
}

void Pong::play() {
	Clock clock;
	int random;
	Event event;
	int result;
	bool gameover;
	FloatRect textRect;
	int randX, randY;
	while (window->isOpen()) {
		scoreLeft = 0;
		scoreRight = 0;
		
		// game loop
		gameover = false;
		while (!gameover) {
			// readjust position of text in case text changes size
			scoreLeftText.setString(to_string(scoreLeft));
			textRect = scoreLeftText.getLocalBounds();
			scoreLeftText.setOrigin(textRect.left + textRect.width / 2.f, textRect.top + textRect.height / 2.f);
			scoreRightText.setString(to_string(scoreRight));
			textRect = scoreRightText.getLocalBounds();
			scoreRightText.setOrigin(textRect.left + textRect.width / 2.f, textRect.top + textRect.height / 2.f);

			// randomly set direction of ball1. ball2 will always start in the complete opposite direction
			randX = pow(-1, rand() % 2);
			randY = pow(-1, rand() % 2);
			ball1->setPosition(window->getSize().x / 2, window->getSize().y / 2);
			ball1->setSpeed(initialSpeed);
			ball1->setVelocity(Vector2f(randX * ball1->getSpeed() / sqrt(2), randY * ball1->getSpeed() / sqrt(2)));
			ball2->setPosition(window->getSize().x / 2, window->getSize().y / 2);
			ball2->setSpeed(initialSpeed);
			ball2->setVelocity(Vector2f(-randX * ball2->getSpeed() / sqrt(2), -randY * ball2->getSpeed() / sqrt(2)));

			// reset paddle positions to center
			paddleLeft->setPosition(0, window->getSize().y / 2);
			paddleRight->setPosition(window->getSize().x, window->getSize().y / 2);

			// render initial frame
			render_frame();
			window->display();

			// countdown
			clock.restart();
			countdown.play();
			while (clock.getElapsedTime().asSeconds() < 2.f);
			clock.restart();

			// round loop
			roundover = false;
			while (!roundover) {
				while (window->pollEvent(event)) {
					if (event.type == Event::Closed) {
						window->close();
						return;
					}
				}

				dt = clock.restart().asSeconds();
				
				update_state();
				// update score here before rendering so final score is displayed
				if (roundover) {
					scoreRightText.setString(to_string(scoreRight));
					scoreLeftText.setString(to_string(scoreLeft));
				}
				render_frame();
				window->display();
			}

			clock.restart();
			while (clock.getElapsedTime().asSeconds() < 1.f);
			clock.restart();

			// win/lose text
			if (scoreLeft >= 5) {
				victory.play();
				victoryText.setString("Blue wins!\nPress [ Space ] to retry");
				textRect = victoryText.getLocalBounds();
				victoryText.setOrigin(textRect.left + textRect.width / 2.f, textRect.top + textRect.height / 2.f);
				render_frame();
				window->draw(victoryText);
				window->display();
				gameover = true;
			}
			if (scoreRight >= 5) {
				defeat.play();
				victoryText.setString("Green wins!\nPress [ Space ] to retry");
				textRect = victoryText.getLocalBounds();
				victoryText.setOrigin(textRect.left + textRect.width / 2.f, textRect.top + textRect.height / 2.f);
				render_frame();
				window->draw(victoryText);
				window->display();
				gameover = true;
			}
		}
		while (!Keyboard::isKeyPressed(Keyboard::Space)) {
			while (window->pollEvent(event)) {
				if (event.type == Event::Closed) {
					window->close();
					return;
				}
			}
		}
	}
}

Pong::~Pong() {
	delete ball1;
	delete ball2;
	delete paddleLeft;
	delete paddleRight;
	delete obstacle1;
	delete obstacle2;
	delete window;
}

void Pong::update_state() {
	update_left_paddle();
	update_right_paddle();
	update_ball1();
	update_ball2();
}

void Pong::update_ball1() {
	Vector2f ballPos = ball1->getPosition();
	Vector2f paddleLeftPos = paddleLeft->getPosition();
	Vector2f paddleRightPos = paddleRight->getPosition();
	Vector2f obstacle1Pos = obstacle1->getPosition();
	Vector2f obstacle2Pos = obstacle2->getPosition();
	Vector2f vel = ball1->getVelocity();
	ballPos += vel * dt;

	// if ball hits the window
	if (ballPos.y > window->getSize().y && vel.y > 0) {
		vel.y = -vel.y;
		windowCollision.play();
	}
	if (ballPos.y < 0 && vel.y < 0) {
		vel.y = -vel.y;
		windowCollision.play();
	}

	// win or lose conditions
	if (ballPos.x > window->getSize().x && vel.x > 0) {
		++scoreLeft;
		roundover = true;
		return;
	}

	if (ballPos.x < 0 && vel.x < 0) {
		++scoreRight;
		roundover = true;
		return;
	}

	// if ball hits obstacle1
	if (ballPos.x > obstacle1Pos.x - obstacle1->getWidth() / 2 &&
		ballPos.x < obstacle1Pos.x + obstacle1->getWidth() / 2 &&
		abs(ballPos.y - obstacle1Pos.y) < obstacle1->getHeight() / 2) {

		vel = ballPos - obstacle1Pos;
		vel = ball1->getSpeed() * Vector2f(vel.x / sqrt(vel.x * vel.x + vel.y * vel.y), vel.y / sqrt(vel.x * vel.x + vel.y * vel.y));

		paddleCollision.play();
	}

	// if ball hits obstacle2
	if (ballPos.x > obstacle2Pos.x - obstacle2->getWidth() / 2 &&
		ballPos.x < obstacle2Pos.x + obstacle2->getWidth() / 2 &&
		abs(ballPos.y - obstacle2Pos.y) < obstacle2->getHeight() / 2) {

		vel = ballPos - obstacle2Pos;
		vel = ball1->getSpeed() * Vector2f(vel.x / sqrt(vel.x * vel.x + vel.y * vel.y), vel.y / sqrt(vel.x * vel.x + vel.y * vel.y));

		paddleCollision.play();
	}

	// if ball hits the left paddle
	if (vel.x < 0 &&
		ballPos.x < paddleLeftPos.x + paddleLeft->getWidth() &&
		abs(ballPos.y - paddleLeftPos.y) < paddleLeft->getHeight() / 2) {

		// speed ball up with each hit
		ball1->setSpeed(ball1->getSpeed() * speedMultiplier);

		vel = ballPos - paddleLeftPos;
		vel = ball1->getSpeed() * Vector2f(vel.x / sqrt(vel.x * vel.x + vel.y * vel.y), vel.y / sqrt(vel.x * vel.x + vel.y * vel.y));

		paddleCollision.play();
	}

	// if ball hits the right paddle
	if (vel.x > 0 &&
		ballPos.x > paddleRightPos.x - paddleRight->getWidth() &&
		abs(ballPos.y - paddleRightPos.y) < paddleRight->getHeight() / 2) {

		// speed ball up with each hit
		ball1->setSpeed(ball1->getSpeed() * speedMultiplier);

		// 
		vel = ballPos - paddleRightPos;
		vel = ball1->getSpeed() * Vector2f(vel.x / sqrt(vel.x * vel.x + vel.y * vel.y), vel.y / sqrt(vel.x * vel.x + vel.y * vel.y));

		paddleCollision.play();
	}

	ball1->setVelocity(vel);
	ball1->setPosition(ballPos);
}

void Pong::update_ball2() {
	Vector2f ballPos = ball2->getPosition();
	Vector2f paddleLeftPos = paddleLeft->getPosition();
	Vector2f paddleRightPos = paddleRight->getPosition();
	Vector2f obstacle1Pos = obstacle1->getPosition();
	Vector2f obstacle2Pos = obstacle2->getPosition();
	Vector2f vel = ball2->getVelocity();
	ballPos += vel * dt;

	// if ball hits the window
	if (ballPos.y > window->getSize().y && vel.y > 0) {
		vel.y = -vel.y;
		windowCollision.play();
	}
	if (ballPos.y < 0 && vel.y < 0) {
		vel.y = -vel.y;
		windowCollision.play();
	}

	// win or lose conditions
	if (ballPos.x > window->getSize().x && vel.x > 0) {
		++scoreLeft;
		roundover = true;
		return;
	}

	if (ballPos.x < 0 && vel.x < 0) {
		++scoreRight;
		roundover = true;
		return;
	}

	// if ball hits obstacle1
	if (ballPos.x > obstacle1Pos.x - obstacle1->getWidth() / 2 &&
		ballPos.x < obstacle1Pos.x + obstacle1->getWidth() / 2 &&
		abs(ballPos.y - obstacle1Pos.y) < obstacle1->getHeight() / 2) {

		vel = ballPos - obstacle1Pos;
		vel = ball2->getSpeed() * Vector2f(vel.x / sqrt(vel.x * vel.x + vel.y * vel.y), vel.y / sqrt(vel.x * vel.x + vel.y * vel.y));

		paddleCollision.play();
	}

	// if ball hits obstacle2
	if (ballPos.x > obstacle2Pos.x - obstacle2->getWidth() / 2 &&
		ballPos.x < obstacle2Pos.x + obstacle2->getWidth() / 2 &&
		abs(ballPos.y - obstacle2Pos.y) < obstacle2->getHeight() / 2) {

		vel = ballPos - obstacle2Pos;
		vel = ball2->getSpeed() * Vector2f(vel.x / sqrt(vel.x * vel.x + vel.y * vel.y), vel.y / sqrt(vel.x * vel.x + vel.y * vel.y));

		paddleCollision.play();
	}

	// if ball hits the left paddle
	if (vel.x < 0 &&
		ballPos.x < paddleLeftPos.x + paddleLeft->getWidth() &&
		abs(ballPos.y - paddleLeftPos.y) < paddleLeft->getHeight() / 2) {

		// speed ball up with each hit
		ball2->setSpeed(ball2->getSpeed() * speedMultiplier);

		vel = ballPos - paddleLeftPos;
		vel = ball2->getSpeed() * Vector2f(vel.x / sqrt(vel.x * vel.x + vel.y * vel.y), vel.y / sqrt(vel.x * vel.x + vel.y * vel.y));

		paddleCollision.play();
	}

	// if ball hits the right paddle
	if (vel.x > 0 &&
		ballPos.x > paddleRightPos.x - paddleRight->getWidth() &&
		abs(ballPos.y - paddleRightPos.y) < paddleRight->getHeight() / 2) {

		// speed ball up with each hit
		ball2->setSpeed(ball2->getSpeed() * speedMultiplier);

		// 
		vel = ballPos - paddleRightPos;
		vel = ball2->getSpeed() * Vector2f(vel.x / sqrt(vel.x * vel.x + vel.y * vel.y), vel.y / sqrt(vel.x * vel.x + vel.y * vel.y));

		paddleCollision.play();
	}

	ball2->setVelocity(vel);
	ball2->setPosition(ballPos);
}

void Pong::update_left_paddle() {
	Vector2i mousePos = Mouse::getPosition(*window);
	Vector2f paddlePos = paddleLeft->getPosition();
	paddlePos.y = mousePos.y;

	if (paddlePos.y > window->getSize().y - paddleLeft->getHeight() / 2) {
		paddlePos.y = window->getSize().y - paddleLeft->getHeight() / 2;
	}
	if (paddlePos.y < paddleLeft->getHeight() / 2) {
		paddlePos.y = paddleLeft->getHeight() / 2;
	}

	paddleLeft->setPosition((float)paddlePos.x, (float)paddlePos.y);
}

void Pong::update_right_paddle() {
/*
	Vector2i mousePos = Mouse::getPosition(*window);
	Vector2f paddlePos = paddleRight->getPosition();
	paddlePos.y = mousePos.y;

	if (paddlePos.y > window->getSize().y - paddleRight->getHeight() / 2) {
		paddlePos.y = window->getSize().y - paddleRight->getHeight() / 2;
	}
	if (paddlePos.y < paddleRight->getHeight() / 2) {
		paddlePos.y = paddleRight->getHeight() / 2;
	}

	paddleRight->setPosition((float)paddlePos.x, (float)paddlePos.y);
*/
/*
	// insane ai
	Vector2f pos = Vector2f(paddleRight->getPosition().x, ball->getPosition().y * dt);
	if (pos.y > window->getSize().y - paddleRight->getHeight() / 2) {
		pos.y = window->getSize().y - paddleRight->getHeight() / 2;
	}
	if (pos.y < paddleRight->getHeight() / 2) {
		pos.y = paddleRight->getHeight() / 2;
	}
	paddleRight->setPosition(pos);
*/
	if (ball1->getVelocity().x < 0 && ball2->getVelocity().x < 0) {
		return;
	}

	Ball *ball;
	if (ball1->getVelocity().x > 0 && ball2->getVelocity().x < 0) {
		ball = ball1;
	}
	else if (ball1->getVelocity().x < 0 && ball2->getVelocity().x > 0) {
		ball = ball2;
	}
	// both balls are approaching right paddle
	else {
		if (ball1->getPosition().x > ball2->getPosition().x) {
			ball = ball1;
		}
		else {
			ball = ball2;
		}
	}

	float ballPosY = ball->getPosition().y;
	float paddlePosY = paddleRight->getPosition().y;
	float vel = (ballPosY - paddlePosY) * 16 * dt;
	paddlePosY += vel;
	if (paddlePosY > window->getSize().y - paddleRight->getHeight() / 2) {
		paddlePosY = window->getSize().y - paddleRight->getHeight() / 2;
	}
	if (paddlePosY < paddleRight->getHeight() / 2) {
		paddlePosY = paddleRight->getHeight() / 2;
	}
	paddleRight->setPosition(paddleRight->getPosition().x, paddlePosY);
}

void Pong::render_frame() {
	window->clear();
	window->draw(backgroundSprite);
	obstacle1->draw(*window);
	obstacle2->draw(*window);
	paddleLeft->draw(*window);
	paddleRight->draw(*window);
	ball1->draw(*window);
	ball2->draw(*window);
	window->draw(scoreLeftText);
	window->draw(scoreRightText);
}