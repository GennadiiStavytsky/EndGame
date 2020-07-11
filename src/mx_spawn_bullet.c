#include "../inc/header.h"

void mx_spawn_bullet(SDL_Renderer *renderer, t_allimg *allimg, t_bullets *h, t_shild_inf *b){
    for (int i=0; i<8; i++) {
        if (h[i].oper){
        h[i].pos_x= h[i].pos_x+ h[i].speed_x;
        }
        else {h[i].pos_x= h[i].pos_x - h[i].speed_x; }
        if (h[i].oper2){
        h[i].pos_y= h[i].pos_y+ h[i].speed_y;
        }
        else {h[i].pos_y= h[i].pos_y - h[i].speed_y; }
        if (h[i].pos_x>512-(100/2) && h[i].pos_x< 512-(100/2)+100 && h[i].pos_y>384-(100/2) && h[i].pos_y< 384-(100/2)+100 && b->position==h[i].position){
            h[i].created=false;
            h[i].oper=!h[i].oper;
            h[i].oper2=!h[i].oper2;
        }
        else{
        SDL_Rect br = {h[i].pos_x, h[i].pos_y, 50, 30};
        SDL_RenderCopyEx(
            renderer,
            allimg->bullet_txd,
            NULL,
            &br,
            h[i].angle,
            NULL,
            SDL_FLIP_NONE
        );
    
    }}
}
