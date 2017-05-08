void InitLevel(playerControl *player);
void InitGame(playerControl *player) {//M. Hisyam A
    initScore(player);
    initLives(player);
    player->level = 1;
    InitLevel(player);
}
void GameRoundCheck();

void InitLevel(playerControl *player) { //M. Hisyam A
    switch(player->level) {
        case 1 : CreateMap(level1, player);createNodes(player);break;
        case 2 : CreateMap(level2, player);break;
        case 3 : CreateMap(level3, player);break;
    }
}
void ResetPosition(playerControl *player) {//M. Hisyam A
    player->peciman.pos.x = player->peciman.initPos.x;
    player->peciman.pos.y = player->peciman.initPos.y;
    player->ghost1.pos.x = player->ghost1.initPos.x;
    player->ghost1.pos.y = player->ghost1.initPos.y;
    player->ghost2.pos.x = player->ghost2.initPos.x;
    player->ghost2.pos.y = player->ghost2.initPos.y;
    player->ghost3.pos.x = player->ghost3.initPos.x;
    player->ghost3.pos.y = player->ghost3.initPos.y;
    player->ghost4.pos.x = player->ghost4.initPos.x;
    player->ghost4.pos.y = player->ghost4.initPos.y;
}
void GameStart(playerControl *player) { //Hisyam, Fadhit, Fahmi
    int rekamana;
    clock_t begin;
    clock_t end;
    char choose;
    int time_spent;
    int step = 0;
    char scoreText[20];
    char livesText[20];
    int liveGiven=0;
    char lepel[2];
    CreateStack(&player->ghost1.path);
    int prev[56];
    int speed;
    //PrintPath(path);
    while (player->lives>0 && player->level<=3) {
        cleardevice();
        DrawSideMenu();
        settextstyle(8, HORIZ_DIR,1);
        outtextxy(660, 165,player->name);
        ResetPosition(player);
        DrawMap();
        DrawGhost(player->ghost1);
        DrawPacman(player->peciman);
        begin = clock();
        srand(time(NULL));
        PlaySound("sounds/pacman_beginning.wav",NULL,SND_ASYNC);
        printScore(player->score, 660, 285);
        printLives(player->lives, 627, 405);
        sprintf(lepel, "%d", player->level);
        //BlackSquare(24*GRIDSIZE,GRIDSIZE*2.8);
        outtextxy(720,84, lepel);
        EmptyStack(&player->ghost1.path);
        player->ghost1.lastNode = 29;
        player->peciman.lastNode = 28;
        bfs(player->ghost1.lastNode, prev);
        GeneratePath(prev, player->ghost1.lastNode, player->peciman.lastNode, &player->ghost1.path);
        while(player->foodCount > 0) {
            if((player->peciman.pos.x==player->ghost1.pos.x) && (player->peciman.pos.y == player->ghost1.pos.y))
                break;
            //printf("%d ",player->foodCount);
            step++;
//                        int i, j;
//            for(i=0;i<20;i++) {
//                for(j=0;j<20;j++) {
//                    printf("%d ",levelMap[j][i].node);
//                }
//                printf("\n");
//            }
//            system("pause");
            if(kbhit())
            {
                choose = getch();
                switch(choose){ // untuk menyimpan direction yang akan dilakukan
                case RIGHTARROW :
                    player->peciman.nextDirection = RIGHT;
                    break;

                case LEFTARROW :
                    player->peciman.nextDirection = LEFT;
                    break;

                case DOWNARROW :
                    player->peciman.nextDirection = DOWN;
                    break;

                case UPARROW :
                     player->peciman.nextDirection = UP;
                    break;

                //case 13: spawnFood(&levelMap[9][12],9,12); break;
                }
            }
            if (step%8 == 0){
                if (CanMovePeciman(player->peciman , player->peciman.nextDirection)) // dicek apakah ada penghalang tembok atau tidak
                {
                    player->peciman.direction = player->peciman.nextDirection; // perubahan arah jika tidak ada tembok
                }
                Move(&player->peciman);
                if(levelMap[player->peciman.pos.x][player->peciman.pos.y].Food != 0){
                    eatFood(player);
                    printScore(player->score, 660, 285);
                    incLives(player, &liveGiven);
                    printLives(player->lives, 627, 405);
                }
                changeState(&player->peciman); // mengubah keadaan pacman dari membuka menjadi tertutup
                if(levelMap[player->peciman.pos.x][player->peciman.pos.y].node != -1) {
                    player->peciman.lastNode = levelMap[player->peciman.pos.x][player->peciman.pos.y].node;
                }
            }
            //speed = (0.5*16);
            printf("%d %d %d\n", player->ghost1.lastNode,player->peciman.lastNode, rekamana);
            if (step%8 == 0) {

                if (Top(player->ghost1.path)!=Nil) {
                    printf("%d\n", Top(player->ghost1.path));
                    printf("\n========================\n");
                    PrintPath(player->ghost1.path);
                    printf("\n========================\n");
                    if (player->ghost1.pos.x!=NodeLevel1[Info(Top(player->ghost1.path))][0] || player->ghost1.pos.y!=NodeLevel1[Info(Top(player->ghost1.path))][1]) {
                        GhostAutoMove(&player->ghost1, NodeLevel1[Info(Top(player->ghost1.path))]);
                        // gotoXY(startX, startY, nodepos[Info(Top(*path))][0], nodepos[Info(Top(*path))][1]);
                    }
                    else {
                        player->ghost1.lastNode = Pop(&player->ghost1.path);
//
                    }

                }
                if (player->ghost1.lastNode!=player->peciman.lastNode && Top(player->ghost1.path)==Nil){
                    rekamana = player->peciman.lastNode;
                    EmptyStack(&player->ghost1.path);
                    bfs(player->ghost1.lastNode, prev);
                    GeneratePath(prev, player->ghost1.lastNode, player->peciman.lastNode, &player->ghost1.path);
                }
            }

            GetCursorPos(&cursorPosition);
            mX=cursorPosition.x;
            mY=cursorPosition.y;

            if (GetAsyncKeyState(VK_LBUTTON) && mX>=624 && mX<=780 && mY>=550 && mY<=600){
                menuutama();
                break;
            }
            delay(10);
            end = clock();
            time_spent = (int)(end - begin) / CLOCKS_PER_SEC; // Ulah di hapus
            // printf("%d %d %d\n", player->score, player->lives, time_spent);
            if(time_spent==60){
                spawnFood(&levelMap[9][12],9,12);
                begin=clock();
            }
            if((time_spent==20 && (levelMap[9][12].Food==FOOD2 || levelMap[9][12].Food==FOOD3)) || (time_spent==15 && levelMap[9][12].Food==FOOD4) || (time_spent==10 && levelMap[9][12].Food==FOOD5)){
                despawnFood(&levelMap[9][12],9,12);
            }
        }
        if (player->foodCount == 0) {
            printf("Game End");
            player->level++;
            InitLevel(player);
        }
        else {
            PlaySound("sounds/pacman_death.wav",NULL,SND_ASYNC);
            player->lives--;
            delay(1500);
        }

    }
    cleardevice();
    settextstyle(8, HORIZ_DIR,30);
    setcolor(WHITE);
    if (player->lives==0){
        outtext("GAME OVER");
        PlaySound("sounds/pacman_intermission.wav",NULL,SND_ASYNC);
         menuutama();
    }
    else{
        outtext("PLAYER WIN");
        PlaySound("sounds/pacman_intermission.wav",NULL,SND_ASYNC);
         menuutama();
    }
}
