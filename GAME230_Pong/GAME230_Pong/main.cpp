/*
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <cmath>

using namespace sf;

void update_state(float dt);
void update_ball(float dt);
void update_paddle(float dt);
void render_frame();

RenderWindow window(VideoMode(800, 600), "Pong");
CircleShape ball(10.f);
Vector2f vel(300.f, 300.f);
RectangleShape paddle;

int main()
{

	Clock clock;
	ball.setFillColor(Color::Red);
	ball.setOrigin(ball.getRadius(), ball.getRadius());
	ball.setPosition(window.getSize().x/2, window.getSize().y/2);
	paddle.setSize(Vector2f(20.f, 90.f));
	paddle.setPosition(paddle.getSize().x/2, paddle.getSize().y/2);
	paddle.setOrigin(paddle.getSize().x/2, paddle.getSize().y/2);

	float dt;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		dt = clock.restart().asSeconds();
		update_state(dt);
		render_frame();
		window.display();
	}

	return 0;
}

void update_state(float dt) {
	update_paddle(dt);
	update_ball(dt);
}

void update_ball(float dt) {
	Vector2f ballPos = ball.getPosition();
	Vector2f paddlePos = paddle.getPosition();
	ballPos += vel * dt;

	// if ball hits the window
	if (ballPos.y > window.getSize().y && vel.y > 0) {
		vel.y = -vel.y;
	}
	if (ballPos.y < 0 && vel.y < 0) {
		vel.y = -vel.y;
	}

	// win or lose conditions
	if (ballPos.x > window.getSize().x && vel.x > 0) {
		vel.x = -vel.x;
	}
	
	if (ballPos.x < 0 && vel.x < 0) {
		vel.x = -vel.x;
	}

	// if ball hits the paddle
	if (ballPos.x < paddlePos.x + paddle.getSize().x / 2 &&
		abs(ballPos.y - paddlePos.y) < paddle.getSize().y / 2) {
			vel.x = -vel.x;
	}

	ball.setPosition(ballPos);
}

void update_paddle(float dt) {
	Vector2i mousePos = Mouse::getPosition(window);
	Vector2f paddlePos = paddle.getPosition();
	paddlePos.y = mousePos.y;
	
	if (paddlePos.y > window.getSize().y - paddle.getSize().y/2) {
		paddlePos.y = window.getSize().y - paddle.getSize().y/2;
	}
	if (paddlePos.y < paddle.getSize().y/2) {
		paddlePos.y = paddle.getSize().y/2;
	}

	paddle.setPosition((float)paddlePos.x, (float)paddlePos.y);
}

void render_frame() {
	window.clear();
	window.draw(paddle);
	window.draw(ball);
}
*/

#include "Pong.h"
#include <iostream>
using namespace std;

int main() {
	Pong* p = new Pong();
	p->play();
	delete p;

	return 0;
}