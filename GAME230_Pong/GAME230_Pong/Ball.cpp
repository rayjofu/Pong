#include "Ball.h"

using namespace sf;

Ball::Ball() {
	ball.setRadius(10.f);
	ball.setOrigin(10.f, 10.f);
	ball.setFillColor(Color::Red);
}

Ball::Ball(int r, Color color) {
	ball.setRadius(r);
	ball.setOrigin(r, r);
	ball.setFillColor(color);
}

void Ball::setColor(Color color) {
	ball.setFillColor(color);
}

Vector2f Ball::getPosition() {
	return ball.getPosition();
}

void Ball::setPosition(Vector2f newPos) {
	pos = newPos;
	ball.setPosition(pos);
}

void Ball::setPosition(float x, float y) {
	pos = Vector2f(x, y);
	ball.setPosition(pos);
}

void Ball::setVelocity(Vector2f newVel) {
	vel = newVel;
}

void Ball::draw(RenderWindow& window) {
	window.draw(ball);
}

float Ball::getSpeed() {
	return speed;
}
void Ball::setSpeed(float s) {
	speed = s;
}
Vector2f Ball::getVelocity() {
	return vel;
}