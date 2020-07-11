#include "header.h"

void mx_shild_dir(SDL_Renderer *renderer, t_allimg *allimg, t_shild_inf *sd) {
    if (sd->x < 341) {
        if (sd->y < 256) {
            SDL_RenderCopy(renderer, allimg->topleft, NULL, &(sd->player_rect));
            sd->position=1;
            
        }
        else if (sd->y > 256 && sd->y < 512){
            SDL_RenderCopy(renderer, allimg->left, NULL, &(sd->player_rect));
            sd->position=4;
            
        } 
        else if (sd->y > 512) {
            SDL_RenderCopy(renderer, allimg->mage, NULL, &(sd->player_rect));
            SDL_RenderCopy(renderer, allimg->downleft, NULL, &(sd->shield_rectL));
            sd->position=6;
        }
    }
    else if (sd->x > 341 && sd->x < 683) {
        if (sd->y < 256) {
            SDL_RenderCopy(renderer, allimg->image, NULL, &(sd->player_rect));
            sd->position=2;
        }
        else if (sd->y > 512) {
            SDL_RenderCopy(renderer, allimg->mage, NULL, &(sd->player_rect));
            SDL_RenderCopy(renderer, allimg->down, NULL, &(sd->shield_rect));
            sd->position=7;
        }
        else {
            SDL_RenderCopy(renderer, allimg->mage, NULL, &(sd->player_rect));
        }
    }
    else if (sd->x > 683) {
        if (sd->y < 256) {
            SDL_RenderCopy(renderer, allimg->topright, NULL, &(sd->player_rect));
            sd->position=3;
        }
        else if (sd->y > 256 && sd->y < 512) {
            SDL_RenderCopy(renderer, allimg->right, NULL, &(sd->player_rect));
            sd->position=5;
        } 
        else if (sd->y > 512) {
            SDL_RenderCopy(renderer, allimg->mage, NULL, &(sd->player_rect));
            SDL_RenderCopy(renderer, allimg->downright, NULL, &(sd->shield_rectR));
            sd->position=8;
        }
    }
}
