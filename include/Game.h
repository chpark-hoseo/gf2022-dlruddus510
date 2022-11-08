#pragma once

#include "GameObject.h"
#include "Player.h"


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
	std::vector<GameObject*> m_gameObjects;

	GameObject* m_go = new GameObject();
	GameObject* m_player = new Player();

	bool m_bRunning;
};

