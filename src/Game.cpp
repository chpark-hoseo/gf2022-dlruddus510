#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
    SCREEN_WIDTH = width;
    SCREEN_HEIGHT = height;
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_pWindow = SDL_CreateWindow(
            title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0) {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
                SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
            }
            else {
                return false; // 랜더러 생성 실패
            }
        }
        else {
            return false; // 윈도우 생설 실패 l
        }
    }
    else {
        return false; // SDL 초기화 실패
    }

    SDL_Surface* pTempSurface = SDL_LoadBMP("assets/rider.bmp");

    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

    SDL_FreeSurface(pTempSurface);

    SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
    m_destinationRectangle.w = m_sourceRectangle.w;
    m_destinationRectangle.h = m_sourceRectangle.h;
    m_destinationRectangle.x = 0;
    m_destinationRectangle.y = 0;
    m_sourceRectangle.x = 0;
    m_sourceRectangle.y = 0;

    SDL_Surface* pTempSurface2 = SDL_LoadBMP("assets/fishbackground_parts.bmp");

    m_pTexture2 = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface2);

    SDL_FreeSurface(pTempSurface2);

    SDL_QueryTexture(m_pTexture2, NULL, NULL, &m_sourceRectangle2.w, &m_sourceRectangle2.h);
    m_destinationRectangle2.w = m_sourceRectangle2.w;
    m_destinationRectangle2.h = m_sourceRectangle2.h;
    m_destinationRectangle2.x = 0;
    m_destinationRectangle2.y = 100;
    m_sourceRectangle.x = 0;
    m_sourceRectangle.y = 0;
    

    m_bRunning = true;
    return true;
}

void  Game::update()
{

}

void Game::render()
{   
    //좌우 반복과 다른이미지 추가
    /*if (flag == 0) 
    {
        m_destinationRectangle.x++;
        if (m_destinationRectangle.x == 520) flag = 1;
    } 
    if (flag == 1)
    {
        m_destinationRectangle.x--;
        if (m_destinationRectangle.x == 0) flag = 0;
    }
    SDL_RenderClear(m_pRenderer);
    SDL_RenderCopy(m_pRenderer, m_pTexture2, &m_sourceRectangle2, &m_destinationRectangle2);
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    
    SDL_RenderPresent(m_pRenderer);
    SDL_Delay(5);   */

    SDL_RenderClear(m_pRenderer);

    SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
    SDL_RenderClear(m_pRenderer);

    SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
    SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
    SDL_RenderFillRect(m_pRenderer, &fillRect);

    SDL_Rect outlineRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
    SDL_SetRenderDrawColor(m_pRenderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(m_pRenderer, &outlineRect);

    SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 255, 255);
    SDL_RenderDrawLine(m_pRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

    SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 0, 255);
    for (int i = 0; i < SCREEN_HEIGHT; i += 4)
    {
        SDL_RenderDrawPoint(m_pRenderer, SCREEN_WIDTH / 2, i);
    }
    
    SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
    return m_bRunning;
}

void Game::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
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