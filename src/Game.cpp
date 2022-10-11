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

    m_textureManager.load("assets/animate-alpha.png", "animate", m_pRenderer);
    m_textureManager.load("assets/Walk2.png", "walk", m_pRenderer); // png 파일 로드
    m_bRunning = true;
    return true;
}

void  Game::update()
{
    m_currentFrame = ((SDL_GetTicks() / 100) % 6);
    w_currentFrame = ((SDL_GetTicks() / 100) % 8); // 애니메이션
}

void Game::render()
{     
    SDL_RenderClear(m_pRenderer);   
    m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);
    m_textureManager.drawFrame("walk", 200, 200, 128, 128, 0, w_currentFrame, m_pRenderer); // 첫번째줄 시트 나타내기
    m_textureManager.drawFrame("walk", 200, 328, 128, 128, 1, w_currentFrame, m_pRenderer); // 두번째줄 시트 나타내기
    m_textureManager.drawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame, m_pRenderer);
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