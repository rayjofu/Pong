#include "Paddle.h"

using namespace sf;

Paddle::Paddle() {
	paddle.setSize(Vector2f(20.f, 90.f));
}

Paddle::Paddle(float width, float height) {
	paddle.setSize(Vector2f(width, height));
}

Vector2f Paddle::getPosition() {
	return paddle.getPosition();
}

void Paddle::setPosition(Vector2f newPos) {
	pos = newPos;
	paddle.setPosition(pos);
}

void Paddle::setPosition(float x, float y) {
	pos = Vector2f(x, y);
	paddle.setPosition(pos);
}

void Paddle::setOrigin(float x, float y) {
	paddle.setOrigin(x, y);
}

void Paddle::draw(RenderWindow& window) {
	window.draw(paddle);
}

float Paddle::getWidth() {
	return paddle.getSize().x;
}

float Paddle::getHeight() {
	return paddle.getSize().y;
}

void Paddle::setFillColor(Color color) {
	paddle.setFillColor(color);
}