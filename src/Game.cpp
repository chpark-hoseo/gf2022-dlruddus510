#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_pWindow = SDL_CreateWindow(
            title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0) {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
                SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
            }
            else {
                return false; // ������ ���� ����
            }
        }
        else {
            return false; // ������ ���� ���� l
        }
    }
    else {
        return false; // SDL �ʱ�ȭ ����
    }

    
   //SDL_Surface* pTempSurface = IMG_Load("assets/animate.png"); // �ǽ� 1��
    SDL_Surface* pTempSurface = IMG_Load("assets/animate-alpha.png"); // �ǽ� 2��
    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    m_sourceRectangle.w = 128;
    m_sourceRectangle.h = 82;
    m_destinationRectangle.w = m_sourceRectangle.w;
    m_destinationRectangle.h = m_sourceRectangle.h;
    m_sourceRectangle.x = 0;
    m_sourceRectangle.y = 0;
    m_destinationRectangle.x = 300;
    m_destinationRectangle.y = 380;

    //������ piskel 
    SDL_Surface* walkTempSurface = IMG_Load("assets/Walk2.png");
    walk_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, walkTempSurface);
    SDL_FreeSurface(walkTempSurface);
    walk_sourceRectangle.w = 128;
    walk_sourceRectangle.h = 128;
    walk_destinationRectangle.w = 128;
    walk_destinationRectangle.h = 128;
    walk_sourceRectangle.x = 0;
    walk_sourceRectangle.y = 0;
    walk_destinationRectangle.x = 0;
    walk_destinationRectangle.y = 0;

    // ����ȭ��
    SDL_Surface* bTempSurface = IMG_Load("assets/background.png");
    b_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, bTempSurface);
    SDL_FreeSurface(bTempSurface);
    b_sourceRectangle.w = 2360;
    b_sourceRectangle.h = 640;
    b_destinationRectangle.w = 2360;
    b_destinationRectangle.h = 640;
    b_sourceRectangle.x = 0;
    b_sourceRectangle.y = 0;
    b_destinationRectangle.x = 0;
    b_destinationRectangle.y = 0;

    m_bRunning = true;
    return true;
}

void  Game::update()
{
    m_sourceRectangle.x = 128 * ((SDL_GetTicks() / 100) % 6);
    walk_sourceRectangle.x = 128 * ((SDL_GetTicks() / 100) % 8);

    // ������ �Ʒ��� �������� ������Ʈ �ٴڿ��� ����
    if (walk_destinationRectangle.y <= 340) walk_destinationRectangle.y = walk_destinationRectangle.y + 50;

    // ������ ���ڸ� ����
    if (flag == 1)
    {
        m_destinationRectangle.y = m_destinationRectangle.y - 20;
        if (m_destinationRectangle.y == 300) flag = 0;
    }
    if (flag == 0)
    {
        m_destinationRectangle.y = m_destinationRectangle.y + 20;
        if (m_destinationRectangle.y == 400) flag = 1;
    }

    // ȭ�� ���������� ����
    b_destinationRectangle.x = b_destinationRectangle.x - 10;
    if (b_destinationRectangle.x == -1720) b_destinationRectangle.x = 0;
    
    
    SDL_Delay(100);
}

void Game::render()
{     
    SDL_RenderClear(m_pRenderer);
    SDL_RenderCopy(m_pRenderer, b_pTexture, &b_sourceRectangle, &b_destinationRectangle); // ���
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle); // ������ 
    SDL_RenderCopy(m_pRenderer, walk_pTexture, &walk_sourceRectangle, &walk_destinationRectangle); // �ȴ� �ִϸ��̼�
    SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
    return m_bRunning;
}

void Game::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            m_bRunning = false;
            break;
        default:
            break;
        }
    }
}

void Game::clean()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}