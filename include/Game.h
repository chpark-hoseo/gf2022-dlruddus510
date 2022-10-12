#pragma once
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>

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

	// 강아지
	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle; // 원본 사각형
	SDL_Rect m_destinationRectangle; // 대상 사각형

	// 걷는 애니메이션
	SDL_Texture* walk_pTexture;
	SDL_Rect walk_sourceRectangle; // 원본 사각형
	SDL_Rect walk_destinationRectangle; // 대상 사각형

	// 배경
	SDL_Texture* b_pTexture;
	SDL_Rect b_sourceRectangle; // 원본 사각형
	SDL_Rect b_destinationRectangle; // 대상 사각형

	int flag = 0;
	bool m_bRunning;
};

