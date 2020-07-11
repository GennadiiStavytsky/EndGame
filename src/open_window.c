// Example program:
// Using SDL2 to create an application window

#include "../inc/header.h"

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
    t_bullets *hate=malloc(sizeof(t_bullets));
    hate->created=false;
    int x_c = 1024 / 2;
    int y_c = 768 / 2;
    int d=0;
    int num;
    // int bullet_x = 0;
    // int bullet_y = 0;

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
            SDL_Delay(10);
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
            
        
            if (d<=0){
            for (int j=0; j<100; j++){
            num = (rand() % (8 - 1 + 1)) + 1; 
            // num =3;
            if (hate[num-1].created==true){
            printf("?");
            }
            else if (hate[num-1].created==false) { 
                printf("%s","NUMBER HERE");
                printf("%d",hate[num-1].created);
                printf("%d",num);
                break;
            }
            }
            // int num=3;
            // t_bulletsList *node = (t_bulletsList *)malloc(sizeof(t_bulletsList));
           
            switch (num)
            {
            case 1:
            printf("2\n");

                hate[0].pos_x=5;
                hate[0].pos_y=5;
                hate[0].angle=25;
                hate[0].speed_x=3;
                hate[0].speed_y=2;
                hate[0].oper=true;
                hate[0].oper2=true;
                hate[0].created=true;
                hate[0].position=1;
            printf("2 \n");
                d=100;
                break;
            case 2:
            printf("3\n");
                hate[1].pos_x=465;
                hate[1].pos_y=5;
                hate[1].angle=90;
                hate[1].speed_x=0;
                hate[1].speed_y=2;
                hate[1].oper=true;
                hate[1].oper2=true;
                hate[1].created=true;
                hate[1].position=2;
            printf("3\n");
                d=100;
                break;
            case 3:
            printf("4\n");
                hate[2].pos_x=965;
                hate[2].pos_y=5;
                hate[2].angle=135;
                hate[2].speed_x=3;
                hate[2].speed_y=2;
                hate[2].oper=false;
                hate[2].oper2=true;
                hate[2].created=true;
                hate[2].position=3;
            printf("4\n");
                d=100;
                break;
            case 4:
            printf("5\n");
                hate[3].pos_x=5;
                hate[3].pos_y=374;
                hate[3].angle=0;
                hate[3].speed_x=3;
                hate[3].speed_y=0;
                hate[3].oper=true;
                hate[3].oper2=true;
                hate[3].created=true;
                hate[3].position=4;
            printf("5\n");
                d=100;
                break;
            case 5:
            printf("6\n");
                hate[4].pos_x=975;
                hate[4].pos_y=374;
                hate[4].angle=180;
                hate[4].speed_x=3;
                hate[4].speed_y=0;
                hate[4].oper=false;
                hate[4].oper2=true;
                hate[4].created=true;
                hate[4].position=5;
            printf("6\n");
                d=100;
                break;
            case 6:
            printf("7\n");
                hate[5].pos_x=5;
                hate[5].pos_y=700;
                hate[5].angle=315;
                hate[5].speed_x=3;
                hate[5].speed_y=2;
                hate[5].oper=true;
                hate[5].oper2=false;
                hate[5].created=true;
                hate[5].position=6;
            printf("7\n");
                d=100;
                break;
            case 7:
            printf("8\n");
                hate[6].pos_x=465;
                hate[6].pos_y=700;
                hate[6].angle=270;
                hate[6].speed_x=0;
                hate[6].speed_y=2;
                hate[6].oper=true;
                hate[6].oper2=false;
                hate[6].created=true;
                hate[6].position=7;
            printf("8\n");
                d=100;
                break;
            case 8:
            printf("9\n");
                hate[7].pos_x=975;
                hate[7].pos_y=700;
                hate[7].angle=225;
                hate[7].speed_x=3;
                hate[7].speed_y=2;
                hate[7].oper=false;
                hate[7].oper2=false;
                hate[7].created=true;
                hate[7].position=8;
            printf("9\n");
                d=100;
                break;    
            default: 
            break;
            }
            }
            
            // }
            // bullet_x += 3;
            // bullet_y += 2;
            // --------------------------------------------
            
            
            mx_spawn_bullet(renderer, allimg, hate, shild); 
            // bulletsList=bulletsList->t_bullets_next; }
            mx_shild_dir(renderer, allimg, shild);
            d-=1;
            SDL_RenderPresent(renderer);
            
            SDL_Delay(5);
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
