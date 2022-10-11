#pragma once
//#include "SDL2/SDL.h"
//#include <SDL2/SDL_image.h>
#include "TextureManager.h"

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

	TextureManager m_textureManager;
	int m_currentFrame;
	int w_currentFrame;

	bool m_bRunning;
};

