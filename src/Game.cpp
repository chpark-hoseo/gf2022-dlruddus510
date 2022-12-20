#include "Game.h"
#include "TextureManager.h"
#include <random>

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
    //m_Ball1 = new Ball();
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

    if (!TheTextureManager::Instance()->load("assets/Player.png", "Player", m_pRenderer))
    {
        return false;
    }

    if (!TheTextureManager::Instance()->load("assets/Background.png", "BG", m_pRenderer))
    {
        return false;
    }

    if (!TheTextureManager::Instance()->load("assets/Ball.png", "Ball1", m_pRenderer))
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

    // 시드값을 얻기 위한 random_device 생성.
    std::random_device rd;

    // random_device 를 통해 난수 생성 엔진을 초기화 한다.
    std::mt19937 gen(rd());

    // 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
    std::uniform_int_distribution<int> randomBall1_X(0, 1);
    int Ball1_x = randomBall1_X(gen) * 1000;
    if (Ball1_x == 0)
        Ball1_x -= 180;
    else
        Ball1_x += 180;

    std::uniform_int_distribution<int> randomBall2_X(0, 1);
    int Ball2_x = randomBall2_X(gen) * 1000;
    if (Ball2_x == 0)
        Ball2_x -= 90;
    else
        Ball2_x += 90;

    std::uniform_int_distribution<int> randomBall3_X(0, 1);
    int Ball3_x = randomBall3_X(gen) * 1000;
    if (Ball3_x == 0)
        Ball3_x -= 100;
    else
        Ball3_x += 100;

    m_gameObjects.push_back(new Player(new LoaderParams(300, 400, 128, 128, "Player")));

    for (int i = 0; i < 6; i++)
    {
        std::uniform_int_distribution<int> ballNumber(0, 2);
        if (ballNumber(gen) == 0)
            m_gameObjects.push_back(new Ball(new LoaderParams(Ball1_x, 0, 180, 180, "Ball1")));
        else if (ballNumber(gen) == 1)
            m_gameObjects.push_back(new Ball(new LoaderParams(Ball2_x, 0, 90, 90, "Ball2")));
        else
            m_gameObjects.push_back(new Ball(new LoaderParams(Ball3_x, 0, 100, 100, "Ball3")));     
    }

    m_bRunning = true;
    return true;
}

void Game::update()
{
    for (int i = 0; i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void Game::render()
{     
    SDL_RenderClear(m_pRenderer);

    TheTextureManager::Instance()->draw("BG", 0, 0, 1000, 640, m_pRenderer);
    for (int i = 0; i != m_gameObjects.size(); i++) 
    {
        m_gameObjects[i]->draw();
    }

    SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
    return m_bRunning;
}

void Game::handleEvents()
{
    TheInputHandler::Instance()->update();
}

void Game::clean()
{
    TheInputHandler::Instance()->clean();
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

