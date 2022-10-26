#pragma once
#include "Ball.h"

class Game
{
public:
	Game():B1(Ball(180, 180, 0, 0, 2, 5, 0, 500, 0)), B2(Ball(90, 90, 1000, 0, -2, 4, 100, 500, 1)), B3(Ball(100, 100, 0, 100, 3, 5, 150, 500, 0)) {}
	~Game() { }

	bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();

	

private:
	Ball B1;
	Ball B2;
	Ball B3;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_currentFrame;

	int Ballturn = 0;
	int Ballturn2 = 0;
	int Ballturn3 = 0;
	int Playerturn = 0;

	int Ball_x = 0;
	int Ball_y = 0;

	int Ball2_x = 1000;
	int Ball2_y = 0;

	int Ball3_x = 0;
	int Ball3_y = 100;

	int Player_x = 200;
	int Player_y = 390;

	bool m_bRunning;
};

