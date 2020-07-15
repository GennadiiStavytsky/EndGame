#include "../inc/header.h"

void mx_spawn_bullet(SDL_Renderer *renderer, t_allimg *allimg, t_bullets *h, t_shild_inf *b){
    for (int i=0; i<8; i++) {
        if (h[i].reflected && h[i].size_x>0 && h[i].size_y>0){
            h[i].size_x-=1;
            h[i].size_y-=1;
        }
        if (h[i].oper){
        h[i].pos_x= h[i].pos_x+ h[i].speed_x;
        }
        else {h[i].pos_x= h[i].pos_x - h[i].speed_x; }
        if (h[i].oper2){
        h[i].pos_y= h[i].pos_y+ h[i].speed_y;
        }
        else {h[i].pos_y= h[i].pos_y - h[i].speed_y; }
        if (h[i].pos_x> 412 && h[i].pos_x< 562 && h[i].pos_y>  304 && h[i].pos_y< 514 && b->position==h[i].position){  // проверка на дотрагивание челика, x левый край x+100 правый край y= верхний y+100
            h[i].created=false;
            h[i].oper=!h[i].oper;
            h[i].oper2=!h[i].oper2;
            h[i].reflected=true;
            if (h[i].angle>180){
                h[i].angle-=180;
            }
            else if (h[i].angle<=180){
                h[i].angle+=180;
            }
            if (h[0].dspeed<55){
            h[0].dspeed+=0.5;}
        }
        else if (h[i].pos_x> 412 && h[i].pos_x< 562 && h[i].pos_y>  304 && h[i].pos_y< 450 && b->position!=h[i].position && h[i].hit == false){
            h[i].created=false;
            h[i].speed_x=0;
            h[i].speed_y=0;
            printf("-hp\n");
            b->hp1 -= 1;
            if (b->hp1 == 0) {
                b->hp -= 1;
                b->hp1 = 3;
            }
            h[i].hit = true; 
        }
        else{
        SDL_Rect br = {h[i].pos_x, h[i].pos_y, h[i].size_x, h[i].size_y};
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
