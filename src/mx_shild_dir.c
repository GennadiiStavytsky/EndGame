#include "header.h"

void mx_shild_dir(SDL_Renderer *renderer, t_allimg *allimg, t_shild_inf *sd) {
    if (sd->x < 341) {
        if (sd->y < 256) {
            SDL_RenderCopy(renderer, allimg->topleft, NULL, &(sd->player_rect));
            SDL_RenderPresent(renderer);
        }
        else if (sd->y > 256 && sd->y < 512){
            SDL_RenderCopy(renderer, allimg->left, NULL, &(sd->player_rect));
            SDL_RenderPresent(renderer);
        } 
        else if (sd->y > 512) {
            SDL_RenderCopy(renderer, allimg->mage, NULL, &(sd->player_rect));
            SDL_RenderCopy(renderer, allimg->downleft, NULL, &(sd->shield_rectL));
        }
    }
    else if (sd->x > 341 && sd->x < 683) {
        if (sd->y < 256) {
            SDL_RenderCopy(renderer, allimg->image, NULL, &(sd->player_rect));
        }
        else if (sd->y > 512) {
            SDL_RenderCopy(renderer, allimg->mage, NULL, &(sd->player_rect));
            SDL_RenderCopy(renderer, allimg->down, NULL, &(sd->shield_rect));
        }
        else {
            SDL_RenderCopy(renderer, allimg->mage, NULL, &(sd->player_rect));
        }
    }
    else if (sd->x > 683) {
        if (sd->y < 256) {
            SDL_RenderCopy(renderer, allimg->topright, NULL, &(sd->player_rect));
        }
        else if (sd->y > 256 && sd->y < 512) {
            SDL_RenderCopy(renderer, allimg->right, NULL, &(sd->player_rect));
        } 
        else if (sd->y > 512) {
            SDL_RenderCopy(renderer, allimg->mage, NULL, &(sd->player_rect));
            SDL_RenderCopy(renderer, allimg->downright, NULL, &(sd->shield_rectR));
        }
    }
}
