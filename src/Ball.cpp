#include "Ball.h"
#include "Vector2D.h"
#include <random>
#include <stdio.h>

Ball::Ball(const LoaderParams* pParams) : SDLGameObject(pParams) 
{
	// �õ尪�� ��� ���� random_device ����.
	std::random_device rd;

	// random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.
	std::mt19937 gen(rd());

	// 0 ���� 99 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.
	std::uniform_int_distribution<int> randomAcc(20, 40);
	acceleration = randomAcc(gen) / 100.0;

	std::uniform_int_distribution<int> randomVel(4, 6);
	velocity = randomVel(gen);	

	if (m_position.getX() <= 0)
		startX = 0;
	else
		startX = 1;
}


void Ball::draw()
{
	SDLGameObject::draw();
}

void Ball::update()
{
	SDLGameObject::update();
	BallMove();
}

void Ball::BallMove()
{
	if (startX == 0)
	{
		m_velocity.setX(velocity);
		if (m_position.getX() >= 1000)
			m_position.setX(-180);
	}
	else
	{
		m_velocity.setX(-velocity);
		if (m_position.getX() <= -180)
			m_position.setX(1180);
	}

	if (m_position.getY() >= 500 - m_height)
		Ballturn = 1;
	else //if (m_position.getY() <= 0)
		Ballturn = 0;
	
	if (Ballturn == 1)
	{
		if (m_velocity.getY() >= 0)
		{
			m_velocity.setY(-m_velocity.getY()-acceleration);
		}		
	}
	m_acceleration.setY(acceleration);
}



void Ball::HandleInput()
{
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
		printf("shoot \n");
	}
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;

}

void Ball::clean() {}

