#include <SDL2/SDL.h>
#include <stdlib.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false;

bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
void render();

int main(int argc, char* argv[])
{
    if (init("Breaking Up HelloSDL",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 640, 480,
        SDL_WINDOW_SHOWN))
    {
        g_bRunning = true;
    }
    else
    {
        return 1; // something's wrong
    }

    int count = 0;

    while (g_bRunning)
    {
        if (count == 10) break;
        // handle input - update - render
        render();
        count++;
    }

    SDL_Quit();
    return 0;
}

bool init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {

        g_pWindow = SDL_CreateWindow(
            title, xpos, ypos, height, width, flags);

        if (g_pWindow != 0) {
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
        }

    }
    else {
        return false;
    }

    SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 0, 255);

    return true;
}

void render()
{
  //  SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 0, 255);
    
    // 그리기 수행  
    SDL_SetRenderDrawColor(g_pRenderer, rand() % 256, rand() % 256, rand() % 256, 255);
    SDL_Delay(1000);

    SDL_RenderClear(g_pRenderer);


    SDL_RenderPresent(g_pRenderer);
}