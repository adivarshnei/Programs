#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

void loading() {
     //variables for arcs
     int x = 317, y = 236;
     int v1 = 0, v2 = 0, v3 = 0, num = 0, n = 0;

     while (1) {
          cleardevice();
          //show loaded percent
          gotoxy(40, 15);
          cout << num << "%";

          setcolor(YELLOW);
          outtextxy(282, 80, "Loading....");

          //draw the arcs
          setlinestyle(0, 0, 3);
          setcolor(GREEN);
          arc(x, y, 270 + v2, 90 + v2, 40);

          setcolor(LIGHTRED);
          arc(x, y, 320 - v2, 120 - v2, 70);
          arc(x, y, 320 - v2, 120 - v2, 72);

          setcolor(CYAN);
          arc(x, y, 30 + v1, 160 + v1, 92);

          setcolor(BLUE);
          arc(x, y, 300 - v1, 40 - v1, 111);

          setcolor(LIGHTMAGENTA);
          arc(x, y, 300 + v3, 140 + v3, 131);
          arc(x, y, 300 + v3, 140 + v3, 133);

          if (num >= 100) { //when loading gets complete
               num += 0;

               delay(500);
               cleardevice();

               setcolor(YELLOW);
               outtextxy(200, 150, "Loading complete");

               setcolor(MAGENTA);
               outtextxy(180, 300, "Press any key to continue...");

               getch();
               exit(0);
          } //assigning increase and decrease values of arc

          v1 += 4 + rand() % 8;
          v2 += 6 + rand() % 8;
          v3 += 4 + rand() % 8;

          randomize();

          num = num + n;
          n = rand() % 2;

          delay(30);
     }

}

void main() {
     int gd = DETECT, gm;
     initgraph( & gd, & gm, "C:\\turboc3\\bgi");
     loading();

}