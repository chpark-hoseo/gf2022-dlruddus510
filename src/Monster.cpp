#include "Monster.h"

void Monster::load(int x, int y, int width, int height, std::string textureID)
{
    GameObject::load(x, y, width, height, textureID);
}

void Monster::draw(SDL_Renderer* pRenderer)
{
    GameObject::draw(pRenderer);
}

void Monster::update()
{
    if (turn == 0) {
        m_x -= 1;
        if (m_x < 200) turn = 1;
    }
    if (turn == 1) {
        m_x += 1;
        if (m_x > 400) turn = 0;
    }
}

void Monster::update2()
{
    if (turn2 == 0) {
        m_x -= 5;
        if (m_x < 200) turn2 = 1;
    }
    if (turn2 == 1) {
        m_x += 5;
        if (m_x > 400) turn2 = 0;
    }
}