#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>

#define MX_MENU_IMAGE "resource/images/menu_image.png"
#define MX_D_UP "resource/images/up.png"
#define MX_D_TOPLEFT "resource/images/topleft.png"
#define MX_D_TOPRIGHT "resource/images/topright.png"
#define MX_D_DOWNLEFT "resource/images/downleft.png"
#define MX_D_DOWNRIGHT "resource/images/downright.png"
#define MX_D_DOWN "resource/images/down.png"
#define MX_D_RIGHT "resource/images/right.png"
#define MX_D_LEFT "resource/images/left.png"
#define MX_GAME_BACKGROUND "resource/images/background.png"
#define MX_GAME_BACKGROUND1 "resource/images/background1.png"
#define MX_GROUND "resource/images/ground.png"
#define MX_MAGE "resource/images/mage.png"
#define MX_BULLET "resource/images/bullets.png"
#define MX_TITLE "resource/images/title.png"
#define MX_HEART "resource/images/heart.png"
#define MX_FONT "resource/fonts/ml-90.ttf"

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
    SDL_Texture *bg1;
    SDL_Texture *gr;
    SDL_Texture *mage;
    SDL_Texture *bullet_txd;
    SDL_Texture *title;
    SDL_Rect title_rect;
    SDL_Texture *heart;
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
    Mix_Chunk *ref_sound;
    Mix_Chunk *hit_sound;
    bool hit;
};


typedef struct s_shild_inf {
    int x;
    int y;
    int position; 
    SDL_Rect player_rect;
    SDL_Rect shield_rectR;
    SDL_Rect shield_rect;
    SDL_Rect shield_rectL;
    SDL_Rect player_platform;
    int hp;
    // int hp1;
    int score;
}              t_shild_inf;

int mx_intlen(int var);
void mx_shild_dir(SDL_Renderer *renderer, t_allimg *allimg, t_shild_inf *sd);
t_shild_inf *mx_alloc_shild(void);
void mx_spawn_bullet(SDL_Renderer *renderer, t_allimg *allimg, t_bullets *h, t_shild_inf *b);
void mx_switch(int n, t_bullets *bul, int *del, float max_del);
void mx_destroyimg(t_allimg *allimg);
void mx_allocimg(SDL_Renderer *renderer, t_allimg *allimg);
// void mx_set_bullet(int num, t_bullets *hate);
// void mx_alloc_bullet(t_bulletsList **list, t_bullets *data, int * f);
// t_bulletsList *mx_create_node(t_bullets *data, int *g);
// t_bullets *mx_create_node2(t_bullets *data2);
#endif

