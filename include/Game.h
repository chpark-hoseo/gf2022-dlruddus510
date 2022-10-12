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

	// ������
	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle; // ���� �簢��
	SDL_Rect m_destinationRectangle; // ��� �簢��

	// �ȴ� �ִϸ��̼�
	SDL_Texture* walk_pTexture;
	SDL_Rect walk_sourceRectangle; // ���� �簢��
	SDL_Rect walk_destinationRectangle; // ��� �簢��

	// ���
	SDL_Texture* b_pTexture;
	SDL_Rect b_sourceRectangle; // ���� �簢��
	SDL_Rect b_destinationRectangle; // ��� �簢��

	int flag = 0;
	bool m_bRunning;
};

