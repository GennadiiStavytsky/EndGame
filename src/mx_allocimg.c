#include "../inc/header.h"
void mx_allocimg(SDL_Renderer *renderer,t_allimg *allimg){
    // ----------- ALLOCATING MEMORY FOR STRUCT S_ALLIMG ---------

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
    allimg->bg1 = IMG_LoadTexture(renderer, MX_GAME_BACKGROUND1);
    allimg->gr = IMG_LoadTexture(renderer, MX_GROUND);
    allimg->mage = IMG_LoadTexture(renderer, MX_MAGE);
    allimg->bullet_txd = IMG_LoadTexture(renderer, MX_BULLET);
    allimg->title = IMG_LoadTexture(renderer, MX_TITLE);
    allimg->heart = IMG_LoadTexture(renderer, MX_HEART);
}
