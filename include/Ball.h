#pragma once
#include "TextureManager.h"

class Ball
{
private:
	int Ball_width;
	int Ball_height;
	int Ball_x;
	int Ball_y;
	int BallSpeed_x;
	int BallSpeed_y;
	int Ballturn;
	int Max_x;
	int Max_y;
	int Min_x;
	int Min_y;
	int direction;//방향값(0이면 왼쪽에서, 1이면 오른쪽에서)

public:
	Ball(int Ball_width, int Ball_height, int Ball_x, int Ball_y, int BallSpeed_x, int BallSpeed_y, int Max_y, int Min_y, int direction);
	~Ball() {}
	void setBall_width(int Ball_width);
	void setBall_height(int Ball_height);
	void setBall_x(int Ball_x);
	void setBall_y(int Ball_y);
	void setBallSpeed_x(int BallSpeed_x);
	void setBallSpeed_y(int BallSpeed_y);
	void setMax_y(int Max_y);
	void setMin_y(int Min_y);

	int getBall_width();
	int getBall_height();
	int getBall_x();
	int getBall_y();
	int getBallSpeed_x();
	int getBallSpeed_y();
	int getMax_x();
	int getMax_y();
	int getMin_x();
	int getMin_y();

	void BallMove();
	void BallDraw();
};

