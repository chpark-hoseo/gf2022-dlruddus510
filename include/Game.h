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

	std::vector<GameObject*> m_gameObjects;

	GameObject* m_go = new GameObject();
	GameObject* m_player = new Player();
	GameObject* m_monster = new Monster();

	bool m_bRunning;
};

