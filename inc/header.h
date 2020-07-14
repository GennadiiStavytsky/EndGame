#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
#define MX_BULLET "res/images/bullets.png"
#define MX_TITLE "res/images/title.png"

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
    SDL_Texture *bullet_txd;
    SDL_Texture *title;
    SDL_Rect title_rect;
}              t_allimg;


typedef struct s_bullets t_bullets;


struct s_bullets{
    int pos_x;
    int pos_y;
    int speed_x;
    int speed_y;
    bool oper;
    bool oper2;
    bool created;
    int angle;  
    int position;
    bool reflected;
    int size_x;
    int size_y;
    float dspeed;
};


typedef struct s_shild_inf {
    int x;
    int y;
    int position; 
    SDL_Rect player_rect;
    SDL_Rect shield_rectR;
    SDL_Rect shield_rect;
    SDL_Rect shield_rectL;
}              t_shild_inf;

void mx_shild_dir(SDL_Renderer *renderer, t_allimg *allimg, t_shild_inf *sd);
t_shild_inf *mx_alloc_shild(void);
void mx_spawn_bullet(SDL_Renderer *renderer, t_allimg *allimg, t_bullets *h, t_shild_inf *b);
// void mx_set_bullet(int num, t_bullets *hate);
// void mx_alloc_bullet(t_bulletsList **list, t_bullets *data, int * f);
// t_bulletsList *mx_create_node(t_bullets *data, int *g);
// t_bullets *mx_create_node2(t_bullets *data2);
#endif

