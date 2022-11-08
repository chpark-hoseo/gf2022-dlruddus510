#pragma once

#include "GameObject.h"
#include "Player.h"


class Game
{
public:
	static Game* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();

	

private:
	Game() {}
	static Game* s_pInstance;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	std::vector<GameObject*> m_gameObjects;

	GameObject* m_go = new GameObject();
	GameObject* m_player = new Player();

	bool m_bRunning;
};

typedef Game TheGame;