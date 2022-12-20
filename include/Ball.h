#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"

class Ball : public SDLGameObject
{
public:
    Ball(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    int getBallX(int getX);
    void BallMove();
    void HandleInput();
private:
    int Ballturn = 0;
    int x;
    int y;
    float acceleration;
    int velocity;
    int height;
    int width;
    int ballNumber;
};