#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
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

    if (!TheTextureManager::Instance()->load("assets/Background.png", "BG", m_pRenderer))
    {
        return false;
    }

    if (!TheTextureManager::Instance()->load("assets/Player.png", "Player", m_pRenderer))
    {
        return false;
    }

    if (!TheTextureManager::Instance()->load("assets/Ball.png", "Ball", m_pRenderer))
    {
        return false;
    }

    if (!TheTextureManager::Instance()->load("assets/Ball2.png", "Ball2", m_pRenderer))
    {
        return false;
    }

    if (!TheTextureManager::Instance()->load("assets/Ball3.png", "Ball3", m_pRenderer))
    {
        return false;
    }

    m_bRunning = true;
    return true;
}

void  Game::update()
{
    if (Ballturn == 0)
    {
        Ball_y = Ball_y + 5;
        Ball_x = Ball_x + 2;
        if (Ball_y >= 320) Ballturn = 1;
    }
    if (Ballturn == 1)
    {
        Ball_y = Ball_y - 5;
        Ball_x = Ball_x + 2;
        if (Ball_y <= 0) Ballturn = 0;
    }
    if (Ball_x > 1000) Ball_x = -100;


    if (Ballturn2 == 0)
    {
        Ball2_y = Ball2_y + 4;
        Ball2_x = Ball2_x - 2;
        if (Ball2_y >= 410) Ballturn2 = 1;
    }
    if (Ballturn2 == 1)
    {
        Ball2_y = Ball2_y - 4;
        Ball2_x = Ball2_x - 2;
        if (Ball2_y <= 200) Ballturn2 = 0;
    }
    if (Ball2_x < 0) Ball2_x = 1000;


    if (Ballturn3 == 0)
    {
        Ball3_y = Ball3_y + 3;
        Ball3_x = Ball3_x + 1;
        if (Ball3_y >= 400) Ballturn3 = 1;
    }
    if (Ballturn3 == 1)
    {
        Ball3_y = Ball3_y - 3;
        Ball3_x = Ball3_x + 1;
        if (Ball3_y <= -100) Ballturn3 = 0;
    }
    if (Ball3_x > 1000) Ball3_x = 0;

    
    m_currentFrame = ((SDL_GetTicks() / 100) % 8);
    SDL_Delay(10);
}

void Game::render()
{     
    SDL_RenderClear(m_pRenderer); 

    TheTextureManager::Instance()->draw("BG", 0, 0, 1000, 640,
        m_pRenderer);
    TheTextureManager::Instance()->drawFrame("Player", Player_x, Player_y, 128,
        128, 0, m_currentFrame, m_pRenderer);
    TheTextureManager::Instance()->draw("Ball", Ball_x, Ball_y, 180, 180,
        m_pRenderer);
    TheTextureManager::Instance()->draw("Ball2", Ball2_x, Ball2_y, 90, 90,
        m_pRenderer);
    TheTextureManager::Instance()->draw("Ball3", Ball3_x, Ball3_y, 100, 100,
        m_pRenderer);

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