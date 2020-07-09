#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#define MX_MENU_IMAGE "res/images/menu_image.png"
#define MX_D_UP "res/images/up.png"
#define MX_D_TOPLEFT "res/images/topleft.png"
#define MX_D_TOPRIGHT "res/images/topright.png"
#define MX_D_DOWNLEFT "res/images/downleft.png"
#define MX_D_DOWNRIGHT "res/images/downright.png"
#define MX_D_DOWN "res/images/down.png"
#define MX_D_RIGHT "res/images/right.png"
#define MX_D_LEFT "res/images/left.png"
#define MX_GAME_BACKGROUND "res/images/background.png"
#define MX_MAGE "res/images/mage.png"

typedef struct s_allimg {
    SDL_Texture *menu_image;
    SDL_Texture *image;
    SDL_Texture *topleft;
    SDL_Texture *topright;
    SDL_Texture *downleft;
    SDL_Texture *downright;
    SDL_Texture *down;
    SDL_Texture *right;
    SDL_Texture *left;
    SDL_Texture *bg;
    SDL_Texture *mage;
}              t_allimg;

typedef struct s_shild_inf {
    int x;
    int y;
    SDL_Rect player_rect;
    SDL_Rect shield_rectR;
    SDL_Rect shield_rect;
    SDL_Rect shield_rectL;
}              t_shild_inf;

void mx_shild_dir(SDL_Renderer *renderer, t_allimg *allimg, t_shild_inf *sd);
t_shild_inf *mx_alloc_shild(void);

#endif

