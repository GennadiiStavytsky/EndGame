#include "../inc/header.h"
void mx_destroyimg(t_allimg *allimg){
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
    SDL_DestroyTexture(allimg->bg1);
    SDL_DestroyTexture(allimg->gr);
    SDL_DestroyTexture(allimg->mage);
    SDL_DestroyTexture(allimg->bullet_txd);
    SDL_DestroyTexture(allimg->title);
    SDL_DestroyTexture(allimg->heart);
}
