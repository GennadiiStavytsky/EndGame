// Example program:
// Using SDL2 to create an application window

#include "header.h"

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

    SDL_Renderer *renderer = SDL_CreateRenderer(window, 0,
                                                SDL_RENDERER_ACCELERATED);

    SDL_Event event;
    int running = 1;

    int x_c = 1024 / 2;
    int y_c = 768 / 2;

    int bullet_x = 0;
    int bullet_y = 0;

    // ----------- ALLOCATING MEMORY FOR STRUCT S_ALLIMG ---------
    t_allimg *allimg = (t_allimg *)malloc(sizeof(t_allimg));

    allimg->menu_image = IMG_LoadTexture(renderer, MX_MENU_IMAGE);
    allimg->image = IMG_LoadTexture(renderer, MX_D_UP);
    allimg->topleft = IMG_LoadTexture(renderer, MX_D_TOPLEFT);
    allimg->topright = IMG_LoadTexture(renderer, MX_D_TOPRIGHT);
    allimg->downleft = IMG_LoadTexture(renderer, MX_D_DOWNLEFT);
    allimg->downright = IMG_LoadTexture(renderer, MX_D_DOWNRIGHT);
    allimg->down = IMG_LoadTexture(renderer, MX_D_DOWN);
    allimg->right = IMG_LoadTexture(renderer, MX_D_RIGHT);
    allimg->left = IMG_LoadTexture(renderer, MX_D_LEFT);
    allimg->bg = IMG_LoadTexture(renderer, MX_GAME_BACKGROUND);
    allimg->mage = IMG_LoadTexture(renderer, MX_MAGE);
    allimg->bullet_txd = IMG_LoadTexture(renderer, MX_BULLET);
    // -------------------------------------------------------------

    // ----------- ALLOCATING MEMORY FOR STRUCT S_SHILD_INF ---------
    t_shild_inf *shild = mx_alloc_shild();

    // SDL_Texture *sh = IMG_LoadTexture(renderer, "shilde.png");
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
            SDL_RenderCopy(renderer, allimg->menu_image, NULL, NULL);
            SDL_RenderPresent(renderer);
            SDL_Delay(5);

        }
        else if (running == 2) {

            while (SDL_PollEvent(&event)) {
                if ((SDL_QUIT == event.type)
                    || (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
                    running = 0;
                if (SDL_MOUSEMOTION == event.type) {
                    SDL_GetMouseState(&(shild->x), &(shild->y));
                }
            }

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

            // RENDER
            SDL_RenderCopy(renderer, allimg->bg, NULL, NULL);

            // SDL_Rect box = {x_c - (200 / 2), y_c - (200 / 2), 200, 200};
            // SDL_RenderFillRect(renderer, &box);
            // SDL_RenderCopy(renderer, sh, NULL, &box);

            // -------------- RECTS FOR SHILD CREATING ------------------------
            shild->player_rect = (SDL_Rect){x_c-(100/2), y_c-(100/2), 100, 100};
            shild->shield_rectR = (SDL_Rect){x_c-(50/2), y_c+25, 80, 80};
            shild->shield_rect = (SDL_Rect){x_c-(100/2), y_c+45, 90, 80};
            shild->shield_rectL = (SDL_Rect){x_c-(180/2), y_c+25, 80, 80};
            // ----------------------------------------------------------------

            // SDL_Point p_c = {50, 50};
            // SDL_RenderCopy(renderer, image, NULL, &player_rect);
            // if (flip == SDL_FLIP_NONE)
            //     flip = SDL_FLIP_HORIZONTAL;
            // else
            //     flip = SDL_FLIP_NONE;

            // SDL_RenderCopyEx(renderer, image, NULL, &player_rect, 0, &p_c, flip);

            // --------------- BULLET --------------------
            SDL_Rect bullet_rect = {bullet_x, bullet_y, 50, 50};
            SDL_RenderCopyEx(
                renderer,
                allimg->bullet_txd,
                NULL,
                &bullet_rect,
                12,
                NULL,
                SDL_FLIP_NONE
            );
            bullet_x += 2;
            bullet_y += 3;
            // --------------------------------------------

            mx_shild_dir(renderer, allimg, shild);

            SDL_RenderPresent(renderer);
            SDL_Delay(50);
        }
    }

    // ---------- FREE STRUCT S_ALLIMG ------------------
    SDL_DestroyTexture(allimg->menu_image);
    SDL_DestroyTexture(allimg->image);
    SDL_DestroyTexture(allimg->topleft);
    SDL_DestroyTexture(allimg->topright);
    SDL_DestroyTexture(allimg->downleft);
    SDL_DestroyTexture(allimg->downright);
    SDL_DestroyTexture(allimg->down);
    SDL_DestroyTexture(allimg->right);
    SDL_DestroyTexture(allimg->left);
    SDL_DestroyTexture(allimg->bg);
    SDL_DestroyTexture(allimg->mage);
    SDL_DestroyTexture(allimg->bullet_txd);
    free(allimg);
    // --------------------------------------------------

    // ---------- FREE STRUCT S_SHILD_INF ---------------
    free(shild);
    // --------------------------------------------------

    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}
