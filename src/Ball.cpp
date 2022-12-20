#include "Ball.h"
#include "Vector2D.h"
#include <random>

Ball::Ball(const LoaderParams* pParams) : SDLGameObject(pParams) 
{
	// �õ尪�� ��� ���� random_device ����.
	std::random_device rd;

	// random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.
	std::mt19937 gen(rd());

	// 0 ���� 99 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.
	std::uniform_int_distribution<int> randomX(0, 1);
	x = randomX(gen) * 1000;
	y = 0;
	getBallX(x);

	std::uniform_int_distribution<int> randomAcc(10, 20);
	acceleration = randomAcc(gen) / 100.0;

	std::uniform_int_distribution<int> randomVel(1, 3);
	velocity = randomVel(gen);

	std::uniform_int_distribution<int> randomBallNum(1, 3);
	ballNumber = randomBallNum(gen);
	for (int i = 0; i < 5; i++) {
		std::cout << "���� : " << randomAcc(gen) / 100.0 << std::endl;
	}
}

int getBallX(int getX)
{
	return getX;
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
	/*if (Ballturn = 0)
	{
		m_velocity.setX(2);
		m_acceleration.setY(0.1);
	}*/
	m_velocity.setX(5);
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