#pragma once
#include <SDL2/SDL.h>   
#include <vector>
enum mouse_buttons {
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};
class Vector2D;
class InputHandler {
public:
    InputHandler();
    ~InputHandler() {}
    static InputHandler* Instance() {
        if (s_pInstance == 0) {
            s_pInstance = new InputHandler();
        }
        return s_pInstance;
    }
    bool isKeyDown(SDL_Scancode key);
    void update();
    bool getMouseButtonState(int buttonNumber);
    Vector2D* getMousePosition();
    void clean() {}

private:  
    std::vector<bool> m_mouseButtonStates;
    Vector2D* m_mousePosition;
    static InputHandler* s_pInstance;
    const Uint8* m_keystates;
};
typedef InputHandler TheInputHandler;
