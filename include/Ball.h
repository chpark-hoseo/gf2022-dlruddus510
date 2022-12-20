#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Player.h"

class Ball : public SDLGameObject
{
public:
    Ball(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void BallMove();
    void HandleInput();
private:
    int Ballturn = 0;
    float acceleration;
    int velocity;
    int startX;
};