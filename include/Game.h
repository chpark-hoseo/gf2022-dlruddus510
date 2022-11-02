#pragma once

#include "GameObject.h"
#include "Player.h"
#include "Monster.h"


class Game
{
public:
	Game() { }
	~Game() { }

	bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();

	

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	GameObject m_go;
	Player m_player;
	Monster m_Monster;
	Monster m_Monster2;

	bool m_bRunning;
};

