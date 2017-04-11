// #include <stdio.h>
// #include <graphics.h>
// #include <windows.h>
// #include <stdlib.h>
#include "includes/interfaces.h"

void DrawSideMenu() {
    setcolor(WHITE);
    readimagefile("picture/pecimen.bmp",20.3*GRIDSIZE,GRIDSIZE/2,26.5*GRIDSIZE,GRIDSIZE*2);
    rectangle(20.2*GRIDSIZE,GRIDSIZE/2,26.5*GRIDSIZE,19.8*GRIDSIZE);
    rectangle(20.3*GRIDSIZE,GRIDSIZE*2,26.4*GRIDSIZE,19.7*GRIDSIZE);

    settextstyle(8, HORIZ_DIR,1);

    rectangle(20.8*GRIDSIZE,GRIDSIZE*2.5,26*GRIDSIZE,3.5*GRIDSIZE);
    outtextxy(21.5*GRIDSIZE,GRIDSIZE*2.8,"LEVEL");

    outtextxy(21.5*GRIDSIZE, 4.2*GRIDSIZE,"NAMA PLAYER");
   // sprintf(nameText, "Nama Player  : ", player1.name);
   //outtextxy(21*GRIDSIZE,3*GRIDSIZE, nameText);
   rectangle(20.8*GRIDSIZE,GRIDSIZE*4,26*GRIDSIZE,5*GRIDSIZE);
    rectangle(20.8*GRIDSIZE,GRIDSIZE*4,26*GRIDSIZE,7*GRIDSIZE);

    outtextxy(22.5*GRIDSIZE, 8.2*GRIDSIZE,"SCORE");
    rectangle(20.8*GRIDSIZE,GRIDSIZE*8,26*GRIDSIZE,9*GRIDSIZE);
    rectangle(20.8*GRIDSIZE,GRIDSIZE*8,26*GRIDSIZE,11*GRIDSIZE);

    outtextxy(22.5*GRIDSIZE, 12.2*GRIDSIZE,"LIVES");
    rectangle(20.8*GRIDSIZE,GRIDSIZE*12,26*GRIDSIZE,13*GRIDSIZE);
    rectangle(20.8*GRIDSIZE,GRIDSIZE*12,26*GRIDSIZE,16.5*GRIDSIZE);

	outtextxy(21.2*GRIDSIZE, 17.2*GRIDSIZE,"BACK TO MENU");
	rectangle(20.8*GRIDSIZE,GRIDSIZE*17,26*GRIDSIZE,18*GRIDSIZE);

    settextstyle(2, HORIZ_DIR,0.2);
    outtextxy(22.5*GRIDSIZE,18.5*GRIDSIZE, "GOOD LUCK!");
}

int kursor(int option, int x, int y)
{
	int select=1, p=x+25, q=y+25;
	int input;
	readimagefile("picture/pacman1.bmp",x, y, p, q); //menampilkan lambang kursor
	do
	{
		input=getch();
		if(input==80) //80 kode ASCII kursor bawah
		{
			readimagefile("picture/black.bmp",x, y, p, q);
			y=y+25;
			q=q+25;
			select++;
			if(select>option)
			{
				y=y-(25*option);
				q=q-(25*option);
				select=1;
			}
			readimagefile("picture/pacman1.bmp",x, y, p, q);
		}
		if(input==72) //72 kode ASCII kursor atas
		{
			readimagefile("picture/black.bmp",x, y, p, q);
			y=y-25;
			q=q-25;
			select--;
			if (select<1)
			{
				y=y+(25*option);
				q=q+(25*option);
				select=option;
			}
			readimagefile("picture/pacman1.bmp",x, y, p, q);
		}
	}
	while(input!=13);
	return select;
}

void tampilan()
{
    //setbkcolor(2);
    setfillstyle(SOLID_FILL, 10);
    readimagefile("picture/pecimen.bmp",100, 10 , 700, 210);
    readimagefile("picture/pacman.bmp",50, 250, 300, 550);
    readimagefile("assets/images/ghost1.bmp",550, 300, 600, 350);
    readimagefile("assets/images/ghost2.bmp",700, 350, 750, 400);
    readimagefile("assets/images/ghost3.bmp",600, 400, 650, 450);
    readimagefile("assets/images/ghost4.bmp",700, 450, 750, 500);
    readimagefile("assets/images/ghost5.bmp",550, 500, 600, 550);
}

void tampilan2()
{
    //setbkcolor(2);
    setfillstyle(SOLID_FILL, 10);
    readimagefile("picture/pecimen.bmp",100, 10 , 700, 210);
    readimagefile("picture/pacman2.bmp",0, 200, 150, 580);
    readimagefile("picture/pacman2.bmp",650, 200, 800, 580);
}

void storymode()
{
    playerControl player1;
    cleardevice();
    tampilan();
    inputnama(&player1);
    InitGame(&player1);
    GameStart(&player1);
}

void versusmode()
{
    cleardevice();
    tampilan();
    //inputnama(&player1);
}

void menuplay()
{
   // setactivepage(2);
    cleardevice();
    tampilan();
    setcolor(15);
    settextstyle(9,HORIZ_DIR,2);
    outtextxy(375,300, "PLAYER");
    settextstyle(8,HORIZ_DIR,1);
    setcolor(9);
    outtextxy(385,355, "STORY MODE");
    outtextxy(380,382, "VERSUS MODE");
    setcolor(4);
    outtextxy(370,408, "BACK TO MENU");
    setcolor(15);
    //setvisualpage(2);
    while(1)
    {
        GetCursorPos(&cursorPosition);
        mX=cursorPosition.x;
        mY=cursorPosition.y;

       if (GetAsyncKeyState(VK_LBUTTON) && mX>=400 && mX<=470 && mY>=382 && mY<=407)
       {
           storymode();
       }
        else if (GetAsyncKeyState(VK_LBUTTON) && mX>=400 && mX<=470 && mY>=408&& mY<=432)
       {
           versusmode();
       }
        else if (GetAsyncKeyState(VK_LBUTTON) && mX>=400 && mX<=470 && mY>=440&& mY<=464)
       {
           menuutama();
       }
    }
   /* int player = kursor(3,325,350);
    switch(player) //kursor di 3 posisi, x=325, y=350

{
    case 1 : storymode();break;
	case 2 : versusmode();break;
    case 3 : menuutama();break;
	}*/
}

void menuscore()
{
    setactivepage(3);
    cleardevice();
    tampilan2();
   // DWORD screenWidth = GetSystemMetrics ( SM_CXSCREEN);
    //DWORD screenHeight = GetSystemMetrics (SM_CYSCREEN);
   // initwindow(screenWidth, screenHeight, "", -3,-3);

   // POINT cursorPosition;
    //int mX, mY;
    outtextxy(275,250,"NAMA");
    outtextxy(525,250,"SCORE");
    setcolor(4);
    readimagefile("picture/pacman1.bmp",335, 565, 360, 590);
    readimagefile("picture/pacman3.bmp",515, 565, 540, 590);
	outtextxy(370,570,"BACK TO MENU");
	setvisualpage(3);
    while(1)
    {
        GetCursorPos(&cursorPosition);
        mX=cursorPosition.x;
        mY=cursorPosition.y;

       if (GetAsyncKeyState(VK_LBUTTON) && mX>=370 && mX<=470 && mY>=570)
       {
           menuutama();
       }
    }
}

void howtoplay()
{
    int a=5,b=32,c=17;
    //setactivepage(4);
    cleardevice();
    readimagefile("picture/pacman1.bmp",200, 5, 225, 30);
    readimagefile("picture/pacman3.bmp",575, 5, 600, 30);
    settextstyle(8,HORIZ_DIR,3);
    outtextxy(320,5, "How To Play");
    settextstyle(8,HORIZ_DIR,1);
    outtextxy(a,b,"> Game ini dapat dimainkan 1 � 2 Orang  ");
    outtextxy(a,b+(1*c),"> Peci-men dikontrol menggunakan keyboard. ");
    outtextxy(a,b+(2*c),"> Setiap player menggerakan 1 Peci-men. ");
    outtextxy(a,b+(3*c),"> Kontrol Player 1 :   ");
    outtextxy(a+50,b+(4*c),"o Arrow atas untuk menggerakan ke atas ");
    outtextxy(a+50,b+(5*c),"o Arrow bawah untuk menggerakan ke bawah  ");
    outtextxy(a+50,b+(6*c),"o Arrow kanan untuk menggerakan ke kanan  ");
    outtextxy(a+50,b+(7*c),"o Arrow kiri untuk menggerakan ke kiri ");
    outtextxy(a,b+(8*c),"> Kontrol Player 2 :   ");
	outtextxy(a+50,b+(9*c),"o Tombol W untuk menggerakan ke atas  ");
	outtextxy(a+50,b+(10*c),"o Tombol S untuk menggerakan ke bawah  ");
	outtextxy(a+50,b+(11*c),"o Tombol D untuk menggerakan ke kanan  ");
	outtextxy(a+50,b+(12*c),"o Tombol A untuk menggerakan ke kiri  ");
    outtextxy(a,b+(13*c),"> Peci-Men tidak dapat menembus pembatas/dinding labirin  ");
    outtextxy(a,b+(14*c),"> Pada sisi kanan dan kiri ada pintu khusus yang membuat Peci-Men");
    outtextxy(a,b+(15*c),"  berpindah tempat / teleport dari satu sisi ke sisi lainnya.  ");
    outtextxy(a,b+(16*c),"> Setiap player diberikan 3 Nyawa ? Terdapat bonus / sesajen untuk");
    outtextxy(a,b+(17*c),"  menambah skor dan lives (nyawa) dari karakter Pac-Man yang dimainkan.  ");
    outtextxy(a,b+(18*c),"> Dalam mode multi-player, Peci-Men yang paling cepat menghabiskan");
    outtextxy(a,b+(19*c),"  dan mendapat skor yang paling tinggi menjadi pemenangnya  ");
    outtextxy(a,b+(20*c),"> Peci-Men dapat memakan musuh dengan memakan �bonus�, sehingga musuh");
    outtextxy(a,b+(21*c),"  berubah warna dan mencoba menghindari Peci-Men.  ");
    outtextxy(a,b+(22*c),"> Kondisi menang ditentukan saat semua �Pac-Dot� termakan oleh karakter");
    outtextxy(a,b+(23*c),"  Peci-Men ? Player akan dinyatakan kalah / Game Over jika Peci-Men");
    outtextxy(a,b+(24*c),"  terkena musuh.");
    outtextxy(a,b+(25*c),"> Jika nyawa Peci-Men habis maka game akan dihentikan.  ");
    outtextxy(a,b+(26*c),"> Kemampuan tiap hantu :  ");
	outtextxy(a+50,b+(27*c),"o Tuyul : Lari cepat dan mengambil skor ")  ;
	outtextxy(a+50,b+(28*c),"o Kuntilanak : Bisa menembut 1 tembok  ");
	outtextxy(a+50,b+(29*c),"o Pocong : Meloncat 2 petak  ");
	outtextxy(a+50,b+(30*c),"o Tengkorak : Mengfreze peci-men ");
	readimagefile("picture/pacman1.bmp",335, 565, 360, 590);
	readimagefile("picture/pacman3.bmp",515, 565, 540, 590);
	setcolor(4);
	outtextxy(370,570,"BACK TO MENU");
	//setvisualpage(4);
	while(1)
    {
        GetCursorPos(&cursorPosition);
        mX=cursorPosition.x;
        mY=cursorPosition.y;

       if (GetAsyncKeyState(VK_LBUTTON) && mX>=370 && mX<=470 && mY>=570)
       {
           menuutama();
       }
    }
	/*int how = kursor(1,325,570);
    switch(how)
    {
        case 1 : menuutama();break;
    }*/
}

void aboutus()
{
    //setactivepage(5);
    cleardevice();
    outtextxy(45,30, "  AAA    BBBBBBB   OOOOO  UUUU UUUU TTTTTTT   UUUU UUUU SSSSSSS");
    outtextxy(45,47, " AA AA    BB   BB OO   OO  UU   UU    TTT      UU   UU  SS   SS");
    outtextxy(45,64, "AA   AA   BB   BB OO   OO  UU   UU    TTT      UU   UU  SS");
    outtextxy(45,81, "AAAAAAA   BBBBBB  OO   OO  UU   UU    TTT      UU   UU  SSSSSSS");
    outtextxy(45,98, "AA   AA   BB   BB OO   OO  UU   UU    TTT      UU   UU       SS");
    outtextxy(45,115,"AA   AA   BB   BB OO   OO  UU   UU    TTT      UU   UU  SS   SS");
    outtextxy(35,130,"AAAA AAAA BBBBBBB   OOOOO   UUUUUUU    TTT      UUUUUUU  SSSSSSS ");
    rectangle(20,164,755,270);
    rectangle(20,270,755,490);
    outtextxy(350,185,"<Leader>");
    outtextxy(280,220,"Nama : Pega Kurniawan");
    outtextxy(280,240,"NIM  : 161511060");
    outtextxy(25,300,"Nama : Auliya Aqma Dinilah");
    outtextxy(25,320,"NIM  : 161511006");
    outtextxy(25,380,"Nama : Haya Utami Lutfi");
    outtextxy(25,400,"NIM  : 161511011");
    outtextxy(400,300,"Nama : Achmad Fadhitya Muharram");
    outtextxy(400,320,"NIM  : 161511034");
    outtextxy(400,380,"Nama : Fahmi Rosdiansyah Mahdani");
    outtextxy(400,400,"NIM  : 161511044");
    outtextxy(280,440,"Nama : Muhamad Hisyam Anshory");
    outtextxy(280,460,"NIM  : 161511052");
    setcolor(15);
    settextstyle(8,HORIZ_DIR,1);
    outtextxy(200,550,"Kelompok 9 - D3 Teknik Informatika");
    outtextxy(250,570,"POLITEKNIK NEGERI BANDUNG");
    readimagefile("picture/pacman1.bmp",315, 500, 340, 525);
    readimagefile("picture/pacman3.bmp",495, 500, 520, 525);
    setcolor(4);
    outtextxy(350,505, "BACK TO MENU");
    while(1)
    {
        GetCursorPos(&cursorPosition);
        mX=cursorPosition.x;
        mY=cursorPosition.y;

       if (GetAsyncKeyState(VK_LBUTTON) && mX>=370 && mX<=470 && mY>=505 && mY<=550)
       {
           menuutama();
       }
    }
    //setvisualpage(5);
   /* int player = kursor(1,325,500);
    switch(player) //kursor di 4 posisi, x=50, y=32
    {
        case 1 : menuutama();break;
	}*/
}

void menuutama()
{
    setactivepage(1);
    cleardevice();
    tampilan();
    menu :
    setcolor(15);
    rectangle(350,280,505,340);
    settextstyle(9,HORIZ_DIR,2);
    outtextxy(385,300, "MENU");
    settextstyle(8,HORIZ_DIR,1);
    setcolor(9);
    outtextxy(400,355, "PLAY");
    outtextxy(395,380, "SCORE");
    outtextxy(370,405, "HOW TO PLAY");
    outtextxy(385,430, "ABOUT US");
    setcolor(4);
    outtextxy(400,458, "EXIT");
    setcolor(15);
    setvisualpage(1);
    while(1)
    {
        GetCursorPos(&cursorPosition);
        mX=cursorPosition.x;
        mY=cursorPosition.y;

       if (GetAsyncKeyState(VK_LBUTTON) && mX>=400 && mX<=470 && mY>=380 && mY<=404)
       {
           menuplay();
       }
        else if (GetAsyncKeyState(VK_LBUTTON) && mX>=400 && mX<=470 && mY>=405&& mY<=429)
       {
           menuscore();
       }
        else if (GetAsyncKeyState(VK_LBUTTON) && mX>=400 && mX<=470 && mY>=430&& mY<=454)
       {
           howtoplay();
       }
        else if (GetAsyncKeyState(VK_LBUTTON) && mX>=400 && mX<=470 && mY>=455&& mY<=479)
       {
           aboutus();
       }
       else if (GetAsyncKeyState(VK_LBUTTON) && mX>=400 && mX<=470 && mY>=485 && mY<=509)
       {
           exit(1);
       }
    }
    /*int menu = kursor(5,325,350);
    switch(menu) //kursor di 5 posisi, x=350, y=350
{
	case 1 : menuplay();break;
	case 2 : menuscore ();break;
	case 3 : howtoplay(); break;
	case 4 : aboutus();break;
	case 5 : exit;
	}*/
}

void inputnama(playerControl *player) {
    char inputbuf[MAX_INPUT_LEN];
    for(int idx=0;idx<MAX_INPUT_LEN;idx++)
        inputbuf[idx]=0;
    int input_pos = 0;
    int the_end=0;
    char c;

    do
    {
       cleardevice();
       readimagefile("picture/pecimen.bmp",100,10,700,160);
       rectangle(100,250,700,400);
       settextstyle(3, HORIZ_DIR,4);
       outtextxy(280,260,"Nama Player:");
       outtextxy (280, 300, inputbuf);
       c = getch();
       switch (c)
       {
            case 8: /* backspace */
              if (input_pos)
              {
                 input_pos--;
                 inputbuf[input_pos] = 0;
              }
              break;
            case 13: /* return */
              the_end = 1;
              break;
            case 27: /* Escape = Abort */
              inputbuf[0] = 0;
              the_end = 1;
              break;
            default:
              if (input_pos < MAX_INPUT_LEN-1 && c >= ' ' && c <= '~')
              {
                 inputbuf[input_pos] = c;
                 input_pos++;
                 inputbuf[input_pos] = 0;
              }
       }

    } while (!the_end);
    strcpy(player->name, inputbuf);
    cleardevice();
    printf("%s", player->name);
    //getchar(playerControl player1.name);
}

void drawNumber(int x, int posX, int posY, int posisi){
  posX+=posisi*GRIDSIZE/2;
  switch(x){
    case 0: readimagefile("assets/images/0.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
    case 1: readimagefile("assets/images/1.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
    case 2: readimagefile("assets/images/2.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
    case 3: readimagefile("assets/images/3.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
    case 4: readimagefile("assets/images/4.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
    case 5: readimagefile("assets/images/5.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
    case 6: readimagefile("assets/images/6.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
    case 7: readimagefile("assets/images/7.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
    case 8: readimagefile("assets/images/8.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
    case 9: readimagefile("assets/images/9.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
  }
}

void printScore(int score, int posX, int posY){
  drawNumber((((((score/10)/10)/10)/10)/10)%10,posX,posY,HUNDREDTHOUSANDS);
  drawNumber(((((score/10)/10)/10)/10)%10,posX,posY,TENTHOUSANDS);
  drawNumber((((score/10)/10)/10)%10,posX,posY,THOUSANDS);
  drawNumber(((score/10)/10)%10,posX,posY,HUNDREDS);
  drawNumber((score/10)%10,posX,posY,TENS);
  drawNumber(score%10,posX,posY,ONES);
}

void printLives(int lives, int posX, int posY){
  int i, x=posX;
  for(i=0;i<lives;i++){
    readimagefile("assets/images/PacmanRightOpen.bmp", x, posY, x+GRIDSIZE, posY+GRIDSIZE);
    x+=GRIDSIZE;
    if((i+1)%3==0){
      posY+=GRIDSIZE;
      x=posX;
    }
  }
}
