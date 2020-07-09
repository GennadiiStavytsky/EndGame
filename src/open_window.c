// Example program:
// Using SDL2 to create an application window

#include "header.h"

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

int main(int argc, char* argv[]) {

    (void)argc;
    (void)argv;

    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

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

    int x = 500;
    int y = 500;

    SDL_Texture *menu_image = IMG_LoadTexture(renderer, "menu_image.png");

    SDL_Texture *image = IMG_LoadTexture(renderer, "up.png");
    SDL_Texture *topleft = IMG_LoadTexture(renderer, "topleft.png");
    SDL_Texture *topright= IMG_LoadTexture(renderer, "topright.png");
    SDL_Texture *downleft= IMG_LoadTexture(renderer, "downleft.png");
    SDL_Texture *downright= IMG_LoadTexture(renderer, "downright.png");
    SDL_Texture *down= IMG_LoadTexture(renderer, "down.png");
    SDL_Texture *right= IMG_LoadTexture(renderer, "right.png");
    SDL_Texture *left= IMG_LoadTexture(renderer, "left.png");
    SDL_Texture *bg = IMG_LoadTexture(renderer, "background.png" );
    SDL_Texture *mage = IMG_LoadTexture(renderer, "mage.png" );
    // SDL_Texture *sh = IMG_LoadTexture(renderer, "shilde.png" );

    // SDL_RendererFlip flip = SDL_FLIP_NONE;
    while (running) {

        if (running == 1) {

            while (SDL_PollEvent(&event)) {
                if ((SDL_QUIT == event.type)
                    || (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
                    running = 0;
                if (SDL_MOUSEBUTTONDOWN == event.type)
                    running = 2;
            }

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, menu_image, NULL, NULL);
            SDL_RenderPresent(renderer);
            SDL_Delay(5);

        }
        else if (running == 2) {

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
            SDL_RenderCopy(renderer, bg, NULL, NULL);
            // SDL_Rect box = {x_c - (200 / 2), y_c - (200 / 2), 200, 200};
            //SDL_RenderFillRect(renderer, &box);
            // SDL_RenderCopy(renderer, sh, NULL, &box);
            SDL_Rect player_rect = {x_c-(100/2), y_c-(100/2), 100, 100};
            SDL_Rect shield_rectR = {x_c-(50/2), y_c+25, 80, 80};
            SDL_Rect shield_rect = {x_c-(100/2), y_c+45, 90, 80};
            SDL_Rect shield_rectL = {x_c-(180/2), y_c+25, 80, 80};
            // SDL_Point p_c = {50, 50};
            //SDL_RenderCopy(renderer, image, NULL, &player_rect);
            // if (flip == SDL_FLIP_NONE)
            //     flip = SDL_FLIP_HORIZONTAL;
            // else
            //     flip = SDL_FLIP_NONE;

            // SDL_RenderCopyEx(renderer, image, NULL, &player_rect, 0, &p_c, flip);
            // SDL_RenderPresent(renderer);
            SDL_Delay(50);
        if (x<341){
            if (y<256){
            // SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, topleft, NULL, &player_rect);  
            SDL_RenderPresent(renderer);
            }
            else if (y>256 && y<512){
            // SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, left, NULL, &player_rect);  
            SDL_RenderPresent(renderer);
            } 
            else if (y>512){
            // SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, mage, NULL, &player_rect);  
            SDL_RenderCopy(renderer, downleft, NULL, &shield_rectL);  
            SDL_RenderPresent(renderer);}
        }
        else if (x>341 && x<683){
            if (y<256){
            // SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, image, NULL, &player_rect);  
            SDL_RenderPresent(renderer);
            }
            else if (y>512){
            // SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, mage, NULL, &player_rect);  
            SDL_RenderCopy(renderer, down, NULL, &shield_rect);  
            SDL_RenderPresent(renderer);}
        }
        else if (x>683){
            if (y<256){
            // SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, topright, NULL, &player_rect);  
            SDL_RenderPresent(renderer);
            }
            else if (y>256 && y<512){
            // SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, right, NULL, &player_rect);  
            SDL_RenderPresent(renderer);
            } 
            else if (y>512){
            // SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, mage, NULL, &player_rect);  
            SDL_RenderCopy(renderer, downright, NULL, &shield_rectR);  
            SDL_RenderPresent(renderer);}
        }
    }
}

    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
