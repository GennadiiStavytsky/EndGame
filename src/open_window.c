// Example program:
// Using SDL2 to create an application window

#include "header.h"

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

int main(int argc, char* argv[]) {

    (void)argc;
    (void)argv;

    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window *window = SDL_CreateWindow(
        "Our Game !",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1024,
        768,
        SDL_WINDOW_POPUP_MENU
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);

    SDL_Event event;
    int running = 1;

    int x_c = 1024 / 2;
    int y_c = 768 / 2;

    int x = 0;
    int y = 0;

    SDL_Texture *image = IMG_LoadTexture(renderer, "sample.png");

    while (running) {
        while (SDL_PollEvent(&event)) {
            if ((SDL_QUIT == event.type)
                || (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
                running = 0;
            if (SDL_MOUSEMOTION == event.type) {
                SDL_GetMouseState(&x, &y);
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

        // RENDER

        SDL_Rect box = {x_c - (200 / 2), y_c - (200 / 2), 200, 200};
        SDL_RenderFillRect(renderer, &box);

        SDL_Rect player_rect = {x - 50, y - 50, 100, 100};
        SDL_RenderCopy(renderer, image, NULL, &player_rect);

        SDL_RenderPresent(renderer);
        SDL_Delay(5);
    }

    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}

