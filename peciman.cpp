#include "includes/peciman.h"
#include <graphics.h>

int CanMovePeciman(pacmanController peciman, int nextDirection) // Untuk mencek apakah ada tembok atau tidak, jika tidak maka akan return true
{ //A. Fadhitya
    switch(nextDirection) {
        case RIGHT : return levelMap[peciman.pos.x+1][peciman.pos.y].Wall == EMPTY;
        case LEFT : return levelMap[peciman.pos.x-1][peciman.pos.y].Wall == EMPTY;
        case UP : return levelMap[peciman.pos.x][peciman.pos.y-1].Wall == EMPTY;
        case DOWN : return levelMap[peciman.pos.x][peciman.pos.y+1].Wall == EMPTY;
    }
}

void DrawPacman(pacmanController peciman)//A. Fadhitya
{
    int posX = peciman.pos.x * GRIDSIZE;
    //peciman.pos.x *= GRIDSIZE;
    int posY = peciman.pos.y * GRIDSIZE;
    char *str1 = "assets/images/";

    char *strpacman11 = "PacmanUpOpen.bmp";
    char *strpacman10 = "PacmanUpClose.bmp";
    char *strpacman21 = "PacmanDownOpen.bmp";
    char *strpacman20 = "PacmanDownClose.bmp";
    char *strpacman31 = "PacmanRightOpen.bmp";
    char *strpacman30 = "PacmanRightClose.bmp";
    char *strpacman41 = "PacmanLeftOpen.bmp";
    char *strpacman40 = "PacmanLeftClose.bmp";


    char temp[255];
    strcpy(temp,str1);

    switch (peciman.skin)
    {
        case 1: strcat(temp,"RedPacman/");
                break;
        case 2:strcat(temp,"GreenPacman/");
                break;
    }

    switch (peciman.direction) {
      case UP:
          if (peciman.state == 1) // if open
          {
            strcat(temp,strpacman11);
            readimagefile(temp, posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);

          }
          else  // close
          {
            strcat(temp,strpacman10);
            readimagefile(temp, posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
          }
      break;

      case DOWN:
              if (peciman.state == 1) // if open
              {
                strcat(temp,strpacman21);
                readimagefile(temp, posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
              }
              else // close
              {
                strcat(temp,strpacman20);
                readimagefile(temp, posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
              }

      break;

      case RIGHT:
              if (peciman.state == 1) // if open
              {
                strcat(temp,strpacman31);
                readimagefile(temp, posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
              }
              else // close
              {
                strcat(temp,strpacman30);
                readimagefile(temp, posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
              }
              break;

      case LEFT:
              if (peciman.state == 1) // if open
              {
                strcat(temp,strpacman41);
                readimagefile(temp, posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
              }
              else// close
              {
                strcat(temp,strpacman40);
                readimagefile(temp, posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
              }
      break;
    }
    if (CanMovePeciman(peciman , peciman.nextDirection))
    {
        peciman.direction = peciman.nextDirection;
    }
}

void InitPacman (pacmanController *peciman, int i, int j) // keadaan awal peciman
{//A. Fadhitya
    peciman->initPos.x = i;
    peciman->initPos.y = j;
    peciman->direction = LEFT;
    peciman->nextDirection = peciman->direction;
    peciman->state = 1;
}

void changeState(pacmanController *peciman)
{//A. Fadhitya
    if (peciman->state == 0)
    {
      peciman->state = 1; // change to open
    }
    else
    {
      peciman->state = 0; // change to close
    }
}

void BlackSquare(int posX, int posY)
{//A. Fadhitya
    setcolor(0);
    bar(posX * GRIDSIZE, posY* GRIDSIZE, (posX * GRIDSIZE) + GRIDSIZE, posY*GRIDSIZE + GRIDSIZE);
}

void Move(pacmanController *peciman)
{//A. Fadhitya
    setfillstyle(SOLID_FILL, 0);
    switch(peciman->direction)
    {
        case RIGHT :
            if (peciman->pos.x == 19){
            BlackSquare(peciman->pos.x, peciman->pos.y);
            peciman->pos.x = 0;
            levelMap[peciman->pos.x][peciman->pos.y].Object = PACMAN;
            }

            else if(levelMap[peciman->pos.x+1][peciman->pos.y].Wall == 0){ // Cek apakah ada tembok atau tidak dan print ke array index selanjutnya
            BlackSquare(peciman->pos.x, peciman->pos.y);
            levelMap[peciman->pos.x][peciman->pos.y].Object = EMPTY;
            peciman->pos.x++;
            levelMap[peciman->pos.x][peciman->pos.y].Object = PACMAN;
            }
            break;

        case LEFT :
            if (peciman->pos.x == 0){
            BlackSquare(peciman->pos.x, peciman->pos.y);
            peciman->pos.x = 19 ;
            levelMap[peciman->pos.x][peciman->pos.y].Object = PACMAN;
            }

            else if(levelMap[peciman->pos.x-1][peciman->pos.y].Wall == 0 ){
            BlackSquare(peciman->pos.x, peciman->pos.y);
            levelMap[peciman->pos.x][peciman->pos.y].Object = EMPTY;
            peciman->pos.x--;
            levelMap[peciman->pos.x][peciman->pos.y].Object = PACMAN;
            }

            break;

        case UP :
            if (peciman->pos.y == 0){
            BlackSquare(peciman->pos.x, peciman->pos.y);
            peciman->pos.y = 19;
            levelMap[peciman->pos.x][peciman->pos.y].Object = PACMAN;
            }

            else if(levelMap[peciman->pos.x][peciman->pos.y-1].Wall == 0){
            BlackSquare(peciman->pos.x, peciman->pos.y);
            levelMap[peciman->pos.x][peciman->pos.y].Object = EMPTY;
            peciman->pos.y--;
            levelMap[peciman->pos.x][peciman->pos.y].Object = PACMAN;
            }
            break;

        case DOWN :
            if (peciman->pos.y == 19){
            BlackSquare(peciman->pos.x, peciman->pos.y);
            peciman->pos.y = 0;
            levelMap[peciman->pos.x][peciman->pos.y].Object = PACMAN;
            }

            else if(levelMap[peciman->pos.x][peciman->pos.y+1].Wall == 0){
            BlackSquare(peciman->pos.x, peciman->pos.y);
            levelMap[peciman->pos.x][peciman->pos.y].Object = EMPTY;
            peciman->pos.y++;
            levelMap[peciman->pos.x][peciman->pos.y].Object = PACMAN;
            }
            break;
    }
    DrawPacman(*peciman); // men-draw pacman sesuai dengan arah yang telah ditentukan
}
