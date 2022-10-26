#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
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
    B1.BallMove();
    B2.BallMove();
    B3.BallMove();

    m_currentFrame = ((SDL_GetTicks() / 100) % 8);
    SDL_Delay(10);
}

void Game::render()
{     
    SDL_RenderClear(m_pRenderer);
    TheTextureManager::Instance()->draw("BG", 0, 0, 1000, 640, m_pRenderer);
    TheTextureManager::Instance()->drawFrame("Player", Player_x, Player_y, 128, 128, 0, m_currentFrame, m_pRenderer);
    TheTextureManager::Instance()->draw("Ball", B1.getBall_x(), B1.getBall_y(), B1.getBall_width(), B1.getBall_height(), m_pRenderer);
    TheTextureManager::Instance()->draw("Ball2", B2.getBall_x(), B2.getBall_y(), B2.getBall_width(), B2.getBall_height(), m_pRenderer);
    TheTextureManager::Instance()->draw("Ball3", B3.getBall_x(), B3.getBall_y(), B3.getBall_width(), B3.getBall_height(), m_pRenderer);
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