#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#define GRIDSIZE 30
#define EMPTY 1
#define PACMAN 2
#define GHOST1 3
#define GHOST2 4
#define GHOST3 5
#define GHOST4 6
#define FOOD1 7
#define FOOD2 8
#define FOOD3 9
#define FOOD4 10
#define FOOD5 11
#define WALL_HOR 12
#define WALL_VER 13
#define WALL_COR_UPRIGHT 14
#define WALL_COR_UPLEFT 15
#define WALL_COR_UNDERRIGHT 16
#define WALL_COR_UNDERLEFT 17
#define WALL_LIMIT_UP 18
#define WALL_LIMIT_DOWN 19
#define WALL_LIMIT_LEFT 20
#define WALL_LIMIT_RIGHT 21
#define WALL_GHOST 22
#define RPACMAN 1
#define KUNTILANAK 2
#define POCONG 3
#define TENGKORAK 4
#define TUYUL 5
#define RFOOD1 1
#define RFOOD2 2
#define RFOOD3 3
#define RFOOD4 4
#define RFOOD5 5
#define RWALL_HOR 1
#define RWALL_VER 2
#define RWALL_COR_UPRIGHT 3
#define RWALL_COR_UPLEFT 4
#define RWALL_COR_UNDERRIGHT 5
#define RWALL_COR_UNDERLEFT 6
#define RWALL_LIMIT_UP 7
#define RWALL_LIMIT_DOWN 8
#define RWALL_LIMIT_LEFT 9
#define RWALL_LIMIT_RIGHT 10
#define RWALL_GHOST 11
#define RWALL_PORTAL_RIGHT 12
#define REMPTY 0

typedef struct{
    int Object;
    int Wall;
    int Food;
} MapController;

MapController levelMap[20][20];
//void CreateMap(int maps);
void DrawMap();
void CreateMap(int maps[20][20], pacmanController *peciman);

#endif // MAP_H_INCLUDED
