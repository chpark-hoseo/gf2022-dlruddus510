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

    //실습 애니메이션
    SDL_Surface* pTempSurface = SDL_LoadBMP("assets/animate.bmp");
    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
   // SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
    m_sourceRectangle.w = 128;
    m_sourceRectangle.h = 82;
    m_destinationRectangle.w = m_sourceRectangle.w;
    m_destinationRectangle.h = m_sourceRectangle.h;
    m_destinationRectangle.x = 0;
    m_destinationRectangle.y = 0;
    m_sourceRectangle.x = 0;
    m_sourceRectangle.y = 0;
   
    //다른 애니메이션 스프라이트
    SDL_Surface* walkTempSurface = SDL_LoadBMP("assets/walk.bmp");
    walk_Texture = SDL_CreateTextureFromSurface(m_pRenderer, walkTempSurface);
    SDL_FreeSurface(walkTempSurface);
    //SDL_QueryTexture(walk_Texture, NULL, NULL, &walk_sourceRectangle.w, &walk_sourceRectangle.h);
    walk_sourceRectangle.w = 128;
    walk_sourceRectangle.h = 240;
    walk_destinationRectangle.w = 200;
    walk_destinationRectangle.h = 500;
    walk_sourceRectangle.x = 0;
    walk_sourceRectangle.y = 60;
    walk_destinationRectangle.x = 0;
    walk_destinationRectangle.y = 100;
    
    //위와 같은 애니메이션이지만 다른속도로 나타내는걸 비교하기위한 스프라이트
    SDL_Surface* runTempSurface = SDL_LoadBMP("assets/walk.bmp");
    run_Texture = SDL_CreateTextureFromSurface(m_pRenderer, runTempSurface);
    SDL_FreeSurface(runTempSurface);
    //SDL_QueryTexture(walk_Texture, NULL, NULL, &walk_sourceRectangle.w, &walk_sourceRectangle.h);
    run_sourceRectangle.w = 128;
    run_sourceRectangle.h = 240;
    run_destinationRectangle.w = 200;
    run_destinationRectangle.h = 500;
    run_sourceRectangle.x = 0;
    run_sourceRectangle.y = 60;
    run_destinationRectangle.x = 200;
    run_destinationRectangle.y = 100;

    m_bRunning = true;
    return true;
}

void  Game::update()
{
    m_sourceRectangle.x = 128 * ((SDL_GetTicks() / 100) % 6);
    walk_sourceRectangle.x = 128 * ((SDL_GetTicks() / 100) % 8); // 다른 애니메이션
    run_sourceRectangle.x = 128 * ((SDL_GetTicks() / 50) % 8); // 속도 조절한 애니메이션
}

void Game::render()
{     
    SDL_RenderClear(m_pRenderer);
    SDL_RenderCopy(m_pRenderer, walk_Texture, &walk_sourceRectangle, &walk_destinationRectangle);
    SDL_RenderCopy(m_pRenderer, run_Texture, &run_sourceRectangle, &run_destinationRectangle);
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);       
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