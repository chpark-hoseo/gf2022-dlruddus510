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
	SDL_Renderer* renderer;

	// 원본 사각형
	SDL_Rect m_sourceRectangle;

	// 대상 사각형
	SDL_Rect m_destinationRectangle;

	SDL_Texture* m_pTexture2;

	// 원본 사각형
	SDL_Rect m_sourceRectangle2;

	// 대상 사각형
	SDL_Rect m_destinationRectangle2;


	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	int flag = 0;
	bool m_bRunning;
};

