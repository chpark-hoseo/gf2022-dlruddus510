#pragma once
#include "SDL2/SDL.h"


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

	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle; // 원본 사각형
	SDL_Rect m_destinationRectangle; // 대상 사각형

	SDL_Texture* walk_Texture;
	SDL_Rect walk_sourceRectangle;
	SDL_Rect walk_destinationRectangle;

	SDL_Texture* run_Texture;
	SDL_Rect run_sourceRectangle;
	SDL_Rect run_destinationRectangle;

	bool m_bRunning;
};

