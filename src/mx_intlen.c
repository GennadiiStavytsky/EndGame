#include "../inc/header.h"

int mx_intlen(int var) {
    int i = 0;
    
    if (var == 0)
        return 1;
    while (var != 0) {
        var /= 10;
        i++;
    }
    return i;
}
