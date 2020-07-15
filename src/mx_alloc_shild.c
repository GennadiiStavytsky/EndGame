#include "header.h"

t_shild_inf *mx_alloc_shild(void) {
    t_shild_inf *shild = (t_shild_inf *)malloc(sizeof(t_shild_inf));

    shild->x = 500;
    shild->y = 500;
    shild->hp = 3;
    shild->hp1 = 3;
    shild->score = 0;
    return shild;
}
