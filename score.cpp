#include "includes/score.h"

playerControl player1;

void initScore(playerControl *player){
    player->score=0;
}

void initLives(playerControl *player){
    player->lives=3;
}

void incScore(int food, playerControl *player){
   switch(food){
   case RFOOD1:
       player->score+=FOOD1_SCORE;
       break;
   case RFOOD2:
       player->score+=FOOD2_SCORE;
       break;
   case RFOOD3:
       player->score+=FOOD3_SCORE;
       break;
   case RFOOD4:
       player->score+=FOOD4_SCORE;
       break;
   case RFOOD5:
       player->score+=FOOD5_SCORE;
       break;
   }
}

void eatFood(playerControl *player){
    incScore(levelMap[player->peciman.posX][player->peciman.posY].Food, player);
    levelMap[player->peciman.posX][player->peciman.posY].Food=REMPTY;
}

void incLives(playerControl *player){
    if(player->score==2500 || player->score==5000 || player->score==15000 || player->score==25000 || player->score==40000)
        player->lives++;
}

int randomise(int min, int max){
    srand(time(NULL));
    return rand()%(max+1-min)+min;
}

int foodType(int x){
    switch(x){
        case 1 ... 40: return RFOOD2; break;    //40%
        case 41 ... 70: return RFOOD3; break;   //30%
        case 71 ... 90: return RFOOD4; break;   //20%
        case 91 ... 100: return RFOOD5; break;  //10%
    }
}

void addBonus(MapController *map, int posX, int posY){
    map->Food=foodType(randomise(1,100));
    DrawFood(map->Food,posX*GRIDSIZE,posY*GRIDSIZE);
}

void delBonus(MapController *map, int posX, int posY){
  map->Food=REMPTY;
  setcolor(BLACK);
  bar(posX * GRIDSIZE, posY* GRIDSIZE, (posX * GRIDSIZE) + GRIDSIZE, posY*GRIDSIZE + GRIDSIZE);
}
