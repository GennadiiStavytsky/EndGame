#include "../inc/header.h"
void mx_switch(int n, t_bullets *bul, int *del,float max_del){
switch (n) {
    case 1:
        bul[0].pos_x=5;
        bul[0].pos_y=10;  // стартовые позиции пуль (от первой до 8)
        bul[0].angle=25;  // угол
        bul[0].speed_x=3; // скорости и траэктории пуль  x- горизонт y- вертикаль
        bul[0].speed_y=2;
        bul[0].oper=true;
        bul[0].oper2=true;
        bul[0].created=true;
        bul[0].position=1;
        bul[0].size_x=50;
        bul[0].size_y=30;
        bul[0].reflected=false;
        bul[0].hit=false;
        *del=max_del-bul[0].dspeed;
        break;
    case 2:
        bul[1].pos_x=465;
        bul[1].pos_y=5;
        bul[1].angle=90;
        bul[1].speed_x=0;
        bul[1].speed_y=2;
        bul[1].oper=true;
        bul[1].oper2=true;
        bul[1].created=true;
        bul[1].position=2;
        bul[1].size_x=50;
        bul[1].size_y=30;
        bul[1].reflected=false;
        bul[1].hit=false;
        *del=max_del-bul[0].dspeed;
        break;
    case 3:
        bul[2].pos_x=965;
        bul[2].pos_y=5;
        bul[2].angle=135;
        bul[2].speed_x=3;
        bul[2].speed_y=2;
        bul[2].oper=false;
        bul[2].oper2=true;
        bul[2].created=true;
        bul[2].position=3;
        bul[2].size_x=50;
        bul[2].size_y=30;
        bul[2].reflected=false;
        bul[2].hit=false;
        *del=max_del-bul[0].dspeed;
        break;
    case 4:
        bul[3].pos_x=5;
        bul[3].pos_y=374;
        bul[3].angle=0;
        bul[3].speed_x=3;
        bul[3].speed_y=0;
        bul[3].oper=true;
        bul[3].oper2=true;
        bul[3].created=true;
        bul[3].position=4;
        bul[3].size_x=50;
        bul[3].size_y=30;
        bul[3].reflected=false;
        bul[3].hit=false;
        *del=max_del-bul[0].dspeed;
        break;
    case 5:
        bul[4].pos_x=975;
        bul[4].pos_y=374;
        bul[4].angle=180;
        bul[4].speed_x=3;
        bul[4].speed_y=0;
        bul[4].oper=false;
        bul[4].oper2=true;
        bul[4].created=true;
        bul[4].position=5;
        bul[4].size_x=50;
        bul[4].size_y=30;
        bul[4].reflected=false;
        bul[4].hit=false;
        *del=max_del-bul[0].dspeed;
        break;
    case 6:
        bul[5].pos_x=5;
        bul[5].pos_y=700;
        bul[5].angle=315;
        bul[5].speed_x=3;
        bul[5].speed_y=2;
        bul[5].oper=true;
        bul[5].oper2=false;
        bul[5].created=true;
        bul[5].position=6;
        bul[5].size_x=50;
        bul[5].size_y=30;
        bul[5].reflected=false;
        bul[5].hit=false;
        *del=max_del-bul[0].dspeed;
        break;
    case 7:
        bul[6].pos_x=465;
        bul[6].pos_y=700;
        bul[6].angle=270;
        bul[6].speed_x=0;
        bul[6].speed_y=2;
        bul[6].oper=true;
        bul[6].oper2=false;
        bul[6].created=true;
        bul[6].position=7;
        bul[6].size_x=50;
        bul[6].size_y=30;
        bul[6].reflected=false;
        bul[6].hit=false;
        *del=max_del-bul[0].dspeed;
        break;
    case 8:
        bul[7].pos_x=975;
        bul[7].pos_y=700;
        bul[7].angle=225;
        bul[7].speed_x=3;
        bul[7].speed_y=2;
        bul[7].oper=false;
        bul[7].oper2=false;
        bul[7].created=true;
        bul[7].position=8;
        bul[7].size_x=50;
        bul[7].size_y=30;
        bul[7].reflected=false;
        bul[7].hit=false;
        *del=max_del-bul[0].dspeed;
        break;    
    default: 
    break;
    } 
}
