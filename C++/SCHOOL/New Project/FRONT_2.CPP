#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
#include<stdio.h>

void bg()
{
		    char ch;

	    setbkcolor(RED);
	    setcolor(YELLOW);
	    settextstyle(7,0,3);
	    outtextxy(80,15,"TRIGONOMETRIC GRAPHING CALCULATOR");
	    setlinestyle(3,1,3);
	    line(75,10,595,10);
	    line(170,15,480,15);
	    line(170,45,480,45);
	    line(75,50,595,50);
	    settextstyle(8,0,1);
	    outtextxy(50,60,"y=sin(x)");
	    outtextxy(190,60,"y=cos(x)");
	    outtextxy(330,60,"y=tan(x)");
	    outtextxy(470,60,"y=cot(x)");
	    outtextxy(50,120,"y=sec(x)");
	    outtextxy(190,120,"y=cosec(x)");
	    outtextxy(330,120,"x=sin(y)");
	    outtextxy(470,120,"x=cos(y)");
	    outtextxy(50,180,"x=tan(y)");
	    outtextxy(190,180,"x=cot(y)");
	    outtextxy(330,180,"x=sec(y)");
	    outtextxy(470,180,"x=cosec(y)");
	    outtextxy(50,240,"Specials");
	    settextstyle(0,0,0);
	    outtextxy(560,430,"made by:-");
	    outtextxy(500,440,"Pranav garg and");
	    outtextxy(520,450,"Adersh varshnei");

	    settextstyle(8,0,3);
	    outtextxy(50,300,"NOTE:-");
	    settextstyle(6,0,2);
	    outtextxy(50,330,"press 'w' and 's' to move the box up and downwards");
	    outtextxy(50,350,"press 'd' and 'a' to move the box sidewards");
	    outtextxy(50,370,"press 'enter'to selected the covered area");
	    outtextxy(50,390,"press 'e' to exit");


	    //to make the arrow
	    int m=0;
	    setlinestyle(0,0,0);
	    int x1=30,y1=65,x2=40,y2=75,x3=30,y3=75;
	    int poly[]={x1,y1,x2,y2,x3,y3};
	    fillpoly(3,poly);
	    int a[]={x1,85,x2,y2,x3,y3,x1,85};
	    drawpoly(4,a);

	    for(int i=0;;i++){
	    switch((ch=getch()))
	    {
		case 77:
			//to move arrow right side
		if(y1==205)
		{
			continue;
		}
		else if(x1==450)
		{
			continue;
		}
		int x=0;
		x1+=140;
		x2+=140;
		x3+=140;
		setcolor(YELLOW);
		int g[]={x1,y1,x2,y2,x3,y3};
		int f[]={x1,y1+25,x2,y2,x3,y3,x1,y1+25};
		int ag[]={x1-140,y1,x2-140,y2,x3-140,y3};
		int af[]={x1-140,y1+25,x2-140,y2,x3-140,y3,x1-140,y1+25};

			setcolor(RED);
			setfillstyle(1,4);
			fillpoly(3,ag);
			drawpoly(4,af);
			setcolor(YELLOW);
			setfillstyle(1,14);
		while(x==0){
		setcolor(RED);
		setfillstyle(1,4);
		fillpoly(3,poly);
		drawpoly(4,a);
		setcolor(YELLOW);
		setfillstyle(1,14);
		x++;}


		fillpoly(3,g);
		drawpoly(4,f);

		continue;

		case 75:		//to move left
			if (x1 == 30) {
						continue;
					} else


					x1-=140;
					x2-=140;
					x3-=140;

			setcolor(YELLOW);
		int b[]={x1,y1,x2,y2,x3,y3};
		int c[]={x1,y1+25,x2,y2,x3,y3,x1,y1+25};
		int ac[]={x1+140,y1,x2+140,y2,x3+140,y3};
		int ab[]={x1+140,y1+25,x2+140,y2,x3+140,y3,x1+140,y1+25};
		int z=0;
			setcolor(RED);
			setfillstyle(1,4);
			fillpoly(3,ac);
			drawpoly(4,ab);
			setcolor(YELLOW);
			setfillstyle(1,14);
		while(z==0){
		setcolor(RED);
		setfillstyle(1,4);
		fillpoly(3,poly);
		drawpoly(4,a);
		setcolor(YELLOW);
		setfillstyle(1,14);
		z++;}


		fillpoly(3,b);
		drawpoly(4,c);

		continue;

		case 80:		//to move it down


			y1+=60;
			y2+=60;
			y3+=60;


		int d[]={x1,y1,x2,y2,x3,y3};
		int e[]={x1,y1+25,x2,y2,x3,y3,x1,y1+25};
		int ae[]={x1,y1-60,x2,y2-60,x3,y3-60};
		int ad[]={x1,y1-35,x2,y2-60,x3,y3-60,x1,y1-35};

			setcolor(RED);
			setfillstyle(1,4);
			fillpoly(3,ae);
			drawpoly(4,ad);
			setcolor(YELLOW);
			setfillstyle(1,14);
		while(m==0)
		{
		setcolor(RED);
		setfillstyle(1,4);
		fillpoly(3,poly);
		drawpoly(4,a);
		setcolor(YELLOW);
		setfillstyle(1,14);
		m++;
		}

	      setcolor(YELLOW);
		fillpoly(3,d);
		drawpoly(4,e);
		 continue;


		 case 72:		//to move the box upward
			y1-=60;
			y2-=60;
			y3-=60;


		int p[]={x1,y1,x2,y2,x3,y3};
		int r[]={x1,y1+25,x2,y2,x3,y3,x1,y1+25};
		int ar[]={x1,y1+60,x2,y2+60,x3,y3+60};
		int ap[]={x1,y1+85,x2,y2+60,x3,y3+60,x1,y1+85};
			int n=0;
			setcolor(RED);
			setfillstyle(1,4);
			fillpoly(3,ar);
			drawpoly(4,ap);
			setcolor(YELLOW);
			setfillstyle(1,14);
		while(n==0)
		{
		setcolor(RED);
		setfillstyle(1,4);
		fillpoly(3,poly);
		drawpoly(4,a);
		setcolor(YELLOW);
		setfillstyle(1,14);
		n++;
		}

	      setcolor(YELLOW);
		fillpoly(3,p);
		drawpoly(4,r);
		 continue;

		case 'e':
		case 'E':
			exit(0);
	    }
	    }



}


void main()
{
	    clrscr();

	    int gd=DETECT,gm;
	     initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	    bg();


	    getch();



}