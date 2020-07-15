#include "../inc/header.h"

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    TTF_Init(); 
    // Initialize SDL video and audio systems
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    // Initialize SDL mixer
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    // Load audio files
    Mix_Music *backgroundSound = Mix_LoadMUS("resource/Sound/backgroundSound.mp3");
    SDL_Window *window = SDL_CreateWindow(
        "Our Game !",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1024,
        768,
        SDL_WINDOW_POPUP_MENU
    );
    if (!window)
        exit(1);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, 0,
                                                SDL_RENDERER_ACCELERATED);
    int running = 1;
    t_bullets *hate=(t_bullets *)malloc((sizeof(t_bullets) * 16) + 1);
    hate[0].ref_sound=Mix_LoadWAV("resource/Sound/fireball.wav");
    hate[0].hit_sound=Mix_LoadWAV("resource/Sound/hit.wav");
    for (int i=0; i<8; i++) {
        hate[i].created=false;
        hate[i].size_x=1;
        hate[i].size_y=1;
        hate[i].hit = false;
    }
    int x_c = 1024 / 2;
    int y_c = 768 / 2;
    int d=0;
    int num;
    float max_delay=100;
    t_allimg *allimg = (t_allimg *)malloc(sizeof(t_allimg));
    mx_allocimg(renderer,allimg);
    t_shild_inf *shild = mx_alloc_shild();
    // Start the background music
    Mix_PlayMusic(backgroundSound, -1); 
    while (running) {
        SDL_Event event;
        if (running == 1) {
            shild->hp = 5;
            shild->score = 0;
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
            allimg->title_rect= (SDL_Rect){x_c-400, y_c-300,800, 400};
            SDL_RenderCopy(renderer, allimg->title, NULL, &allimg->title_rect);
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
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            // RENDER
            SDL_RenderCopy(renderer, allimg->bg, NULL, NULL);
            SDL_RenderCopy(renderer, allimg->bg1, NULL, NULL);
            // -------------- RECTS FOR SHILD CREATING ------------------------
            shild->player_rect = (SDL_Rect){x_c-(100/2), y_c-(100/2), 100, 100};
            shild->shield_rectR = (SDL_Rect){x_c-(50/2), y_c+25, 80, 80};
            shild->shield_rect = (SDL_Rect){x_c-(100/2), y_c+45, 90, 80};
            shild->shield_rectL = (SDL_Rect){x_c-(180/2), y_c+25, 80, 80};
            shild->player_platform = (SDL_Rect){x_c-(200/2), y_c-(220/2), 200, 200};
            // --------------- BULLET -------------------- 
            if (d<=0){
                for (int j=0; j<100; j++){
                num = (rand() % (8 - 1 + 1)) + 1; 
                    if (hate[num-1].created==true){}
                    else if (hate[num-1].created==false) { 
                        // printf("%s","NUMBER HERE");
                        // printf("%d",hate[num-1].created);
                        // printf("%d",num);
                        break;
                    }
                }      
                mx_switch(num, hate,&d, max_delay);
            }
            mx_spawn_bullet(renderer, allimg, hate, shild); 
            // GAME OVER CASE
            if (shild->hp == 0) {
                // printf("%s", "Your final score is: ");
                // printf("%d",shild->score);
                // printf("%s","\n");
                running = 1;
            }
            // HEARTS RENDER
            for (int i = 0; i < shild->hp; i++) {
                SDL_Rect heartsrect = {10 + (i * 30), 10, 30, 30};
                SDL_RenderCopy(renderer, allimg->heart, NULL, &heartsrect);
            }
            SDL_RenderCopy(renderer, allimg->gr, NULL, &shild->player_platform);
            mx_shild_dir(renderer, allimg, shild);
            d-=1;
            SDL_RenderPresent(renderer);  
            SDL_Delay(7);
        }    
    }
    mx_destroyimg(allimg);
    // ---------- FREE STRUCT S_SHILD_INF ---------------
    free(allimg);
    free(shild);
    free(hate);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_FreeMusic(backgroundSound);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
    return 0;
}
