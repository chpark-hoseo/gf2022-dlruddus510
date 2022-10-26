#include "Ball.h"

Ball::Ball(int Ball_width, int Ball_height, int Ball_x, int Ball_y, int BallSpeed_x, int BallSpeed_y, int Max_y, int Min_y, int direction) {
	//좌표의 x좌표 시작점과 끝점은 고정
	this->direction = direction;
	this->Max_x = 1000;
	this->Min_x = 0;
	setBall_width(Ball_width);
	setBall_height(Ball_height);
	setBall_x(Ball_x);
	setBall_y(Ball_y);
	setBallSpeed_x(BallSpeed_x);
	setBallSpeed_y(BallSpeed_y);
	setMax_y(Max_y);
	setMin_y(Min_y);
}

void Ball::BallMove()
{
    if (Ballturn == 0)
    {
        Ball_y = Ball_y + BallSpeed_y;
        Ball_x = Ball_x + BallSpeed_x;
		if (Ball_y >= Min_y - Ball_height) { Ballturn = 1; }
    }
    if (Ballturn == 1)
    {
		Ball_y = Ball_y - BallSpeed_y;
        Ball_x = Ball_x + BallSpeed_x;
        if (Ball_y <= Max_y) Ballturn = 0;
    }
	if (direction == 0) {
		if (Ball_x > Max_x) Ball_x = Min_x;
	}
	else {
		if (Ball_x < Min_x) Ball_x = Max_x;
	}
}
void Ball::setBall_width(int Ball_width){
	this->Ball_width = Ball_width;
}
void Ball::setBall_height(int Ball_height) {
	this->Ball_height = Ball_height;
}
void Ball::setBall_x(int Ball_x) {
	this->Ball_x = Ball_x;
}
void Ball::setBall_y(int Ball_y) {
	this->Ball_y = Ball_y;
}
void Ball::setBallSpeed_x(int BallSpeed_x) {
	this->BallSpeed_x = BallSpeed_x;
}
void Ball::setBallSpeed_y(int BallSpeed_y) {
	this->BallSpeed_y = BallSpeed_y;
}
void Ball::setMax_y(int Max_y) {
	this->Max_y = Max_y;
}
void Ball::setMin_y(int Min_y) {
	this->Min_y = Min_y;
}

int Ball::getBall_width() {
	return Ball_width;
}
int Ball::getBall_height() {
	return Ball_height;
}
int Ball::getBall_x() {
	return Ball_x;
}
int Ball::getBall_y() {
	return Ball_y;
}
int Ball::getBallSpeed_x() {
	return BallSpeed_x;
}
int Ball::getBallSpeed_y() {
	return BallSpeed_y;
}
int Ball::getMax_x() {
	return Max_y;
}
int Ball::getMax_y() {
	return Max_y;
}
int Ball::getMin_x() {
	return Min_x;
}
int Ball::getMin_y() {
	return Min_y;
}
void Ballmove();