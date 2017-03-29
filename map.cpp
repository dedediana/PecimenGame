//prosedur untuk mengambar Wall menggunakan sprite sesuai kondisi di array dengan parameter jenis wall , posisi x, posisi y (by pega)
void DrawWall(int wall,int posX, int posY) {
    switch(wall){
        case RWALL_HOR : readimagefile("assets/images/Wall_Hor.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_VER : readimagefile("assets/images/Wall_Ver.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_COR_UNDERLEFT : readimagefile("assets/images/Wall_Cor_DownLeft.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_COR_UNDERRIGHT : readimagefile("assets/images/Wall_Cor_DownRight.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_COR_UPLEFT : readimagefile("assets/images/Wall_Cor_UPLEFT.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_COR_UPRIGHT : readimagefile("assets/images/Wall_Cor_UPRIGHT.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_LIMIT_UP : readimagefile("assets/images/Wall_Limit_Up.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_LIMIT_DOWN : readimagefile("assets/images/Wall_Limit_Down.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_LIMIT_LEFT : readimagefile("assets/images/Wall_Limit_Left.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_LIMIT_RIGHT : readimagefile("assets/images/Wall_Limit_Right.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_GHOST : readimagefile("assets/images/Wall_Ghost.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
    }
}
//prosedur untuk mengambar food menggunakan sprite sesuai kondisi di array dengan parameter jenis food , posisi x , posisi y (by pega)
void DrawFood(int food,int posX, int posY) {
    switch(food){
        case RFOOD1 : readimagefile("assets/images/FOOD1.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RFOOD2 : readimagefile("assets/images/FOOD2.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RFOOD3 : readimagefile("assets/images/FOOD3.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RFOOD4 : readimagefile("assets/images/FOOD4.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RFOOD5 : readimagefile("assets/images/FOOD5.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
    }
}

//prosedure untuk menggambar arena dengan struktur data array berukuran 20x20 dengan ukuran pixel 30 (by pega)
void DrawMap()
{
     int i, j;
    for (i=0;i<20;i++) { //mengecek posisi array ke arah y
        for(j=0;j<20;j++) { //Mengecek posisi array ke arah x
            if(levelMap[i][j].Wall!=0) //pengecekan jika kondisi isi array menunjukan WALL
                {
                DrawWall(levelMap[i][j].Wall,i*GRIDSIZE,j*GRIDSIZE);
                }
            if(levelMap[i][j].Food!=0) //pengecekan jika kondisi isi array menunjukan food
                {
                DrawFood(levelMap[i][j].Food,i*GRIDSIZE,j*GRIDSIZE);
                }
        }
    }
}

//struktur data aray untuk level 1 berukuran 20x20 (by Pega)
int level1[20][20]= {
                    {15, 12,12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 14},
                    {13,  7, 7,  7,  7,  7,  7,  7,  7, 13, 13,  7,  7,  7,  7,  7,  7,  7,  7, 13},
                    {13, 7, 15, 12, 14,  7, 15, 14,  7, 13, 13,  7, 15, 14,  7, 15, 12, 14,  7, 13},
                    {13, 7, 17, 12, 16,  7, 17, 16,  7, 19, 19,  7, 17, 16,  7, 17, 12, 16,  7, 13},
                    {13, 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 13},
                    {13, 7, 15, 14,  7,  18, 7, 18,  7,  7,  7,  7, 18,  7, 18,  7, 15, 14,  7, 13},
                    {13, 7, 17, 16,  7,  13, 7, 17, 12, 12, 12, 12, 16,  7, 13,  7, 17, 16,  7, 13},
                    {13, 7,  7,  7,  7,  13, 1,  1,   1, 1,  1,  1,  1,  1, 13,  7,  7,  7,  7, 13},
                    {17,12, 12, 12, 12,  16, 1, 15,  21,22, 22, 20, 14,  1, 17, 12, 12, 12, 12, 16},
                    { 1, 1,  1,  1,  1,   1, 1, 13,   1, 1,  1,  1, 13,  1,  1,  2,  1,  1,  1, 1},
                    { 1, 1,  1,  1,  1,   1, 1, 13,   1, 4,  5,  6, 13,  1,  1,  1,  1,  1,  1, 1},
                    {15,12, 12, 12, 12,  21, 1, 17,  12,12, 12, 12, 16,  1, 20, 12, 12, 12, 12, 14},
                    {13, 7,  7,  7,  7,   7, 1,  1,   1, 11,  1,  1,  1,  1,  7,  7,  7,  7,  7, 13},
                    {13, 7, 15, 21,  7,  18, 7, 20,  12,12, 12, 12, 21,  7, 18,  7, 20, 14,  7, 13},
                    {13, 7, 13,  7,  7,  13, 7,  7,   7, 7,  7,  7,  7,  7, 13,  7,  7, 13,  7, 13},
                    {13, 7, 13,  7, 20,  16, 7, 18,   7,18, 18,  7, 18,  7, 17, 21,  7, 13,  7, 13},
                    {13, 7, 13,  7,  7,   7, 7, 13,   7,13, 13,  7, 13,  7,  7,  7,  7, 13,  7, 13},
                    {13, 7, 17, 12, 21,   7,20, 16,   7,19, 19,  7, 17, 21,  7, 20, 12, 16,  7, 13},
                    {13, 7,  7,  7,  7,   7, 7,  7,   7, 7,  7,  7,  7,  7,  7,  7,  7,  7,  3, 13},
                    {17, 12, 12,12, 12,  12, 12, 12, 12, 12, 12, 12,12, 12, 12, 12, 12, 12, 12, 16}
                    };
//struktur data aray untuk level 2 berukuran 20x20 (by Pega)
int level2[20][20]= {
                    {15,12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 14},
                    {13, 7,  7,  7,  7, 18,  7,  7,  7, 15, 14,  7,  7,  7, 18,  7,  7,  7,  7, 13},
                    {13, 7, 20, 21,  7, 19,  7, 18,  7, 17, 16,  7, 18,  7, 19,  7, 20, 21,  7, 13},
                    {13, 7, 7,  7,  7,  7,  7, 13,  7,  7,  7,  7, 13,  7,  7,  7,  7,  7,  7, 13},
                    {13, 7, 20, 12, 12, 21,  7, 17, 12, 12, 12, 12, 16,  7, 20, 12, 12, 21,  7, 13},
                    {13, 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 13},
                    {17,12, 12, 21,  7, 15, 12, 12, 21,  7,  7, 20, 12, 12, 14,  7, 20, 12, 12, 16},
                    {7 , 7,  7,  7,  7, 13,  7,  7,  7,  7,  7,  7,  7,  7, 13,  7,  7,  7,  7,  7},
                    {18, 7, 15, 14,  7, 13,  7, 15, 21, 22, 22, 20, 14,  7, 13,  7, 15, 14,  7, 18},
                    {13, 7, 17, 16,  7, 19,  7, 13,  1,  1,  1,  1, 13,  7, 19,  7, 17, 16,  7, 13},
                    {13, 7,  7,  7,  7,  7,  7, 13,  1,  1,  1,  1, 13,  7,  7,  7,  7,  7,  7, 13},
                    {19, 7, 20, 21,  7, 20, 21, 17, 12, 12, 12, 12, 16, 20, 21,  7, 20, 21,  7, 19},
                    {7 , 7,  7,  7,  7,  7,  7,  7,  7, 11,  7,  7,  7,  7,  2,  7,  7,  7,  7,  7},
                    {15,12, 12, 12, 21,  7, 20, 21,  7, 20, 21,  7, 20, 21,  7, 20, 12, 12, 12, 14},
                    {13, 7,  7,  7,  7,  7,  7,  7,  7,  3,  7,  7,  7,  7,  7,  7,  7,  7,  7, 13},
                    {13, 7, 18,  7, 20, 12, 21,  7, 20, 14, 15, 21,  7, 20, 12, 21,  7, 18,  7, 13},
                    {13, 7, 13,  7,  7,  7,  7,  7,  7, 13, 13,  7,  7,  7,  7,  7,  7, 13,  7, 13},
                    {13, 7, 17, 21,  7, 20, 12, 21,  7, 13, 13,  7, 20, 12, 21,  7, 20, 16,  7, 13},
                    {13, 7,  7,  7,  7,  7,  7,  7,  7, 19, 19,  7,  7,  7,  7,  7,  7,  7,  7, 13},
                    {17, 12, 12,12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 16}
                    };
//struktur data aray untuk level 2 berukuran 20x20 (by Pega)
 int level3[20][20]= {
                    {15,12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 14},
                    {13, 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 13},
                    {13, 7, 15, 12, 21,  7, 20, 12, 12, 12, 12, 12, 12, 21,  7, 20, 12, 14,  7, 13},
                    {13, 7, 13,  7,  7,  7,  7,  7,  7,  4,  7,  7,  7,  7,  7,  7,  7, 13,  7, 13},
                    {13, 7, 13,  7, 20, 14,  7, 20, 12, 12, 12, 12, 21,  7, 15, 21,  7, 13,  7, 13},
                    {13, 7, 13,  7,  7, 13,  7,  7,  7,  7,  7,  7,  7,  7, 13,  7,  7, 13,  7, 13},
                    {13, 7, 17, 21,  7, 19,  7, 20, 12, 12, 12, 12, 21,  7, 19,  7, 20, 16,  7, 13},
                    {13, 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  2,  7,  7,  7, 13},
                    {17,12, 12, 12, 12, 21,  7, 15, 21, 22, 22, 20, 14,  7, 20, 12, 12, 12, 12, 16},
                    { 1, 1,  1,  1,  1,  1,  7, 13,  1,  1,  1,  1, 13,  7,  1,  1,  1,  1,  1,  1},
                    { 1, 1,  1,  1,  1,  1,  7, 13,  1,  1,  1,  1, 13,  7,  1,  1,  1,  1,  1,  1},
                    {15,12, 12, 12, 12, 21,  7, 17, 12, 12, 12, 12, 16,  7, 20, 12, 12, 12, 12, 14},
                    {13, 7,  7,  7,  7,  7,  7,  1,  1, 11,  1,  1,  1,  7,  7,  7,  7,  7,  7, 13},
                    {13, 7, 15, 21,  7, 18,  7, 20, 12, 12, 12, 12, 21,  7, 18,  7, 20, 14,  7, 13},
                    {13, 7, 13,  7,  7, 13,  7,  7,  7,  7,  7,  7,  7,  7, 13,  7,  7, 13,  7, 13},
                    {13, 7, 13,  7, 20, 16,  7, 20, 12, 12, 12, 12, 21,  7, 17, 21,  7, 13,  7, 13},
                    {13, 7, 13,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 13,  7, 13},
                    {13, 7, 17, 12, 21,  7, 20, 12, 12, 12, 12, 12, 12, 21,  7, 20, 12, 16,  7, 13},
                    {13, 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 13},
                    {17, 12, 12,12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 16}
                    };
//Prosedure untuk membuat map dengan parameter
void CreateMap(int maps[20][20], playerControl *player)
{
       int i, j;
       player->foodCount = 0;
    for (i=0;i<20;i++) {
        for(j=0;j<20;j++) {
            // Kondisi pengecekan untuk setiap jenis wall
            if (maps[j][i]==WALL_HOR) {
                levelMap[i][j].Wall=RWALL_HOR;
            }
            else if (maps[j][i]==WALL_VER) {
                levelMap[i][j].Wall=RWALL_VER;
            }
            else if (maps[j][i]==WALL_COR_UNDERLEFT) {
                levelMap[i][j].Wall=RWALL_COR_UNDERLEFT;
            }
            else if (maps[j][i]==WALL_COR_UNDERRIGHT) {
                levelMap[i][j].Wall=RWALL_COR_UNDERRIGHT;
            }
            else if (maps[j][i]==WALL_COR_UPLEFT) {
                levelMap[i][j].Wall=RWALL_COR_UPLEFT;
            }
            else if (maps[j][i]==WALL_COR_UPRIGHT) {
                levelMap[i][j].Wall=RWALL_COR_UPRIGHT;
            }
            else if (maps[j][i]==WALL_LIMIT_UP) {
                levelMap[i][j].Wall=RWALL_LIMIT_UP;
            }
            else if (maps[j][i]==WALL_LIMIT_DOWN) {
                levelMap[i][j].Wall=RWALL_LIMIT_DOWN;
            }
            else if (maps[j][i]==WALL_LIMIT_LEFT) {
                levelMap[i][j].Wall=RWALL_LIMIT_LEFT;
            }
            else if (maps[j][i]==WALL_LIMIT_RIGHT) {
                levelMap[i][j].Wall=RWALL_LIMIT_RIGHT;
            }
            else if (maps[j][i]==WALL_GHOST) {
                levelMap[i][j].Wall=RWALL_GHOST;
            }
            else {
                levelMap[i][j].Wall=REMPTY;
            }

            // Kondisi pengecekan untuk Objek bergerak
            if (maps[j][i]==GHOST1) {
                levelMap[i][j].Object=KUNTILANAK;
                InitGhost(&player->ghost1, i, j, KUNTILANAK);
            }
            else if (maps[j][i]==GHOST2) {
                levelMap[i][j].Object=POCONG;
                InitGhost(&player->ghost2, i, j, POCONG);
            }
            else if (maps[j][i]==GHOST3) {
                levelMap[i][j].Object=TENGKORAK;
                InitGhost(&player->ghost3, i, j, TENGKORAK);
            }
            else if (maps[j][i]==GHOST4){
                levelMap[i][j].Object=TUYUL;
                InitGhost(&player->ghost4, i, j, TUYUL);
            }
            else if (maps[j][i]==PACMAN) {
                levelMap[i][j].Object=RPACMAN; // Masukan RPACMAN ke record jika angka yang di map adalah angka pacman
                InitPacman(&player->peciman, i, j); // Kondisi pertama pacman

            }
            else{
                  levelMap[i][j].Object=REMPTY;
            }

            // Kondisi pengecekan untuk Food
            if (maps[j][i]==FOOD1) {
                levelMap[i][j].Food=RFOOD1;
                player->foodCount++;
            }
            else if (maps[j][i]==FOOD2) {
                levelMap[i][j].Food=RFOOD2;
            }
            else if (maps[j][i]==FOOD3) {
                levelMap[i][j].Food=RFOOD3;
            }
            else if (maps[j][i]==FOOD4) {
                levelMap[i][j].Food=RFOOD4;
            }
            else if (maps[j][i]== FOOD5) {
                levelMap[i][j].Food=RFOOD5;
            }
            else{
                levelMap[i][j].Food=REMPTY;
            }
        }
    }
}
