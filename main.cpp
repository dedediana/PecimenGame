#include <stdio.h>
#include <graphics.h>
#include "includes/peciman.h"
#include "includes/map.h"
#include "includes/score.h"
#include "map.cpp"
#include "peciman.cpp"
#include "score.cpp"
#include <time.h>

int main()
{
    clock_t begin;

    /* here, do your time-consuming job */

    clock_t end;
    double time_spent;

    pacmanController peciman;
    initwindow(800, 600, "Pecimen Game");
    initScore(&player1);
    initLives(&player1);
    CreateMap(level1, &peciman);
    char choose;
    int step = 0;

    DrawMap();
    while (true)
    {
        step++;
        begin = clock();
        if(kbhit())
        {
            choose = getch();
            switch(choose){
            case RIGHTARROW :   peciman.direction = RIGHT;break;
            case LEFTARROW :   peciman.direction = LEFT;break;
            case DOWNARROW :   peciman.direction = DOWN;break;
            case UPARROW :   peciman.direction = UP;break;
            }
        }
        if (step%200 == 0){
//          printf("%d",step);
            Move(&peciman);
            if(levelMap[peciman.posX][peciman.posY].Food != 0){
            	eatFood(&peciman);
	            incLives(&player1);
            }
            changeState(&peciman);
        }
//        printf("%d\n",step);
       // printf("%d %d\n",peciman.posX,peciman.posY);
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC; // Ulah di hapus
//      printf("Time = %f\n",time_spent);
        printf("%d %d\n", player1.score, player1.lives);
    }

    getch();
    return 0;
}
