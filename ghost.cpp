void DrawGhost(ghostController ghost) { //M. Hisyam A
    int posX = ghost.pos.x * GRIDSIZE;
    int posY = ghost.pos.y * GRIDSIZE;
    switch(ghost.ghostType) {
        case KUNTILANAK : readimagefile("assets/images/Ghost1.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);break;
        case POCONG : readimagefile("assets/images/Ghost2.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);break;
        case TENGKORAK : readimagefile("assets/images/Ghost3.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);break;
        case TUYUL : readimagefile("assets/images/Ghost4.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);break;
    }
}
void InitGhost(ghostController *ghost, position pos, int ghostType) {//M. Hisyam A
    ghost->initPos.x = pos.x;
    ghost->initPos.y = pos.y;
    ghost->ghostType = ghostType;
}
int CanMove(ghostController ghost, int direction) {//M. Hisyam A
    switch(direction) {
        case RIGHT : return ((levelMap[ghost.pos.x+1][ghost.pos.y].Wall == EMPTY || levelMap[ghost.pos.x+1][ghost.pos.y].Wall == WALL_GHOST) && (levelMap[ghost.pos.x+1][ghost.pos.y].Object == EMPTY || levelMap[ghost.pos.x+1][ghost.pos.y].Object == PACMAN));
        case LEFT : return ((levelMap[ghost.pos.x-1][ghost.pos.y].Wall == EMPTY || levelMap[ghost.pos.x-1][ghost.pos.y].Wall == WALL_GHOST) && (levelMap[ghost.pos.x-1][ghost.pos.y].Object == EMPTY  || levelMap[ghost.pos.x-1][ghost.pos.y].Object == PACMAN));
        case UP : return ((levelMap[ghost.pos.x][ghost.pos.y-1].Wall == EMPTY || levelMap[ghost.pos.x][ghost.pos.y-1].Wall == WALL_GHOST) && (levelMap[ghost.pos.x][ghost.pos.y-1].Object == EMPTY  || levelMap[ghost.pos.x][ghost.pos.y-1].Object == PACMAN));
        case DOWN : return ((levelMap[ghost.pos.x][ghost.pos.y+1].Wall == EMPTY || levelMap[ghost.pos.x][ghost.pos.y+1].Wall == WALL_GHOST) && (levelMap[ghost.pos.x][ghost.pos.y+1].Object == EMPTY  || levelMap[ghost.pos.x][ghost.pos.y+1].Object == PACMAN));
    }
}
void BlackSquareCheck(position pos) {//M. Hisyam A
    if (levelMap[pos.x][pos.y].Food!= EMPTY) {
        DrawFood(levelMap[pos.x][pos.y].Food, pos);
    }
    else if (levelMap[pos.x][pos.y].Wall == WALL_GHOST){
        DrawWall(WALL_GHOST, pos);
    }
    else {
        BlackSquare(pos.x, pos.y);
    }
}
void GhostMove(ghostController *ghost) {//M. Hisyam A
    setfillstyle(SOLID_FILL, 0);
    switch(ghost->direction)
    {
        case RIGHT :
            if(CanMove(*ghost, RIGHT)){
                BlackSquareCheck(ghost->pos);
                levelMap[ghost->pos.x][ghost->pos.y].Object = EMPTY;
                ghost->pos.x++;
                levelMap[ghost->pos.x][ghost->pos.y].Object = ghost->ghostType;
            }break;
        case LEFT :
            if(CanMove(*ghost, LEFT)){ // Cek apakah ada tembok atau tidak
                BlackSquareCheck(ghost->pos);
                levelMap[ghost->pos.x][ghost->pos.y].Object = EMPTY;
                ghost->pos.x--;
                levelMap[ghost->pos.x][ghost->pos.y].Object = ghost->ghostType;
            }break;
        case UP :
            if(CanMove(*ghost, UP)){ // Cek apakah ada tembok atau tidak
                BlackSquareCheck(ghost->pos);
                levelMap[ghost->pos.x][ghost->pos.y].Object = EMPTY;
                ghost->pos.y--;
                levelMap[ghost->pos.x][ghost->pos.y].Object = ghost->ghostType;
            }break;
        case DOWN :
            if(CanMove(*ghost, DOWN)){ // Cek apakah ada tembok atau tidak
                BlackSquareCheck(ghost->pos);
                levelMap[ghost->pos.x][ghost->pos.y].Object = EMPTY;
                ghost->pos.y++;
                levelMap[ghost->pos.x][ghost->pos.y].Object = ghost->ghostType;
            }break;
    }
    DrawGhost(*ghost);
}

void GhostAutoMove(ghostController *ghost, int nodepos[]) {//M. Hisyam A
        int moved =1;
        //printf("am %d %d\n", nodepos[0], nodepos[1]);
        if (abs(nodepos[0] - ghost->pos.x) > abs(nodepos[1] - ghost->pos.y) && (CanMove(*ghost, RIGHT) || CanMove(*ghost, LEFT))) {
            if(nodepos[0] > ghost->pos.x && CanMove(*ghost, RIGHT)) {
                ghost->direction = RIGHT;
            }

            else {
                ghost->direction = LEFT;
            }

        }
        else if (CanMove(*ghost, UP) || CanMove(*ghost, DOWN)){
            if(nodepos[1] > ghost->pos.y && CanMove(*ghost, DOWN)) {
                ghost->direction = DOWN;
            }
            else {
                ghost->direction = UP;
            }
        }
        // if (!moved) {
        //     if (CanMove(*ghost, UP)) {
        //          ghost->direction = UP;
        //     }
        //     else if (CanMove(*ghost, LEFT)) {
        //          ghost->direction = LEFT;
        //     }
        //     else if (CanMove(*ghost, DOWN)) {
        //          ghost->direction = DOWN;
        //     }
        //     else {
        //          ghost->direction = RIGHT;
        //     }
        // }
        GhostMove(ghost);
}

void GeneratePath(int prev[], int start, int End, Stack *path) {
    int i=End;
    while(prev[i]!=-1) {
        Push(path, i);
        //printf("%d ", i);
        i = prev[i];
    }
}

void PrintPath(Stack path) {
    while (Top(path)!=Nil) {
        printf("%d ", Info(Top(path)));
        Top(path) = Next(Top(path));
    }
}

void bfs(int v, int prev[], int GraphLevel[]) {
    Queue Q;
    CreateQueue(&Q);
    EnQueue(&Q, v);

    int visited[nodeCount] = {0};
    int node = DeQueue(&Q);
    visited[v] = 1;

    //printf("%d ", node);
    int i;
    for(i=0;i<nodeCount;i++) {
        prev[i] = -1;
    }
    while (1) {

        for(i=0;i<nodeCount;i++) {

            if (GraphLevel[node*nodeCount+i] == 1 && visited[i] == 0) {
                prev[i] = node;
                visited[i] = 1;
                EnQueue(&Q, i);
            }
        }
        if (Front(Q) == Nil) {
            break;
        }
        else {
            node = DeQueue(&Q);
            //printf("%d ", node);
        }
    }
}
