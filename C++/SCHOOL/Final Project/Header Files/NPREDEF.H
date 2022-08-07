# ifndef _predef_h_
	# define _predef_h

	# ifndef _headers
		# define _headers_

		# include <fstream.h> 
		# include <conio.h> 
		# include <stdlib.h> 
		# include <stdio.h> 
		# include <graphics.h> 
		# include <math.h> 
		# include <string.h>
		# include <dos.h>

	# endif

	# ifndef _absc_ordi_
		# define _absc_ordi_

		typedef struct coordinate {
			double x;
			double y;
		};

	# endif

	# ifndef _modifiers_
		# define _modifiers_

		typedef struct mod {
			double arg;
			double coeffX;
			double coeffY;
		};

	# endif

	# ifndef _defs_
		# define _defs_

		typedef char string;
		const int pi = 3.14;
	# endif

	# ifndef _enumerations_
		# define _enumerations_

		enum mainMenuInput {
			sinX,
			cosX,
			tanX,
			cotX,
			secX,
			cosecX,
			sinY,
			cosY,
			tanY,
			cotY,
			secY,
			cosecY,
			spec
		};

		enum graphCategory{
			nullCat,
			simpleTrig,
			simpleInvTrig,
			addnComboGraph,
			multComboGraph,
			nestedComboGraph
		};
		
		enum trigFunc{
			nullTrig,
			sinx,
			cosx,
			tanx,
			cotx,
			secx,
			cosecx
		};

		enum invTrigFunc{
			nullInv,
			invSin,
			invCos,
			invTan,
			invCot,
			invSec,
			invCosec
		};

	# endif

	#ifndef _mod_function_
		#define _mod_function_

		mod modifierInput(mod modifiers) {
			cout<<"Enter argument mod: ";
			cin>>modifiers.arg;
			cout<<"Enter coefficient of x: ";
			cin>>modifiers.coeffX;
			cout<<"enter coefficient of y: ";
			cin>>modifiers.coeffY;

			return modifiers;
		}

	#endif

	# ifndef _loading_2_
		# define _loading_2_

		void loading_2()
{
     clrscr();
         
          int i, o ;

        gotoxy(33,9) ; cout << "_________________" ;    //  TO
        gotoxy(32,10) ; cout << "/" ;                   //   PRINT
        gotoxy(49,10) ; cout << "/" ;                   //        BOX
	    gotoxy(37,8) ;cout << "LOADING..." ;

        for(o=0; o<6; o++)       // LOOP TO ANIMATE LOADING
        {

            for(i=0; i<800; i++){ gotoxy(33,10) ; cout << "\f" ;}
            for(i=0; i<800; i++){ gotoxy(34,10) ; cout << "\f" ; }
            for(i=0; i<800; i++){ gotoxy(35,10) ; cout << "\f" ; }
            for(i=0; i<800; i++){ gotoxy(36,10) ; cout << "\f" ; }
            for(i=0; i<800; i++){ gotoxy(37,10) ; cout << "\f" ; }
            for(i=0; i<800; i++){ gotoxy(38,10) ; cout << "\f" ; }
            for(i=0; i<800; i++){ gotoxy(39,10) ; cout << "\f" ; }
            for(i=0; i<800; i++){ gotoxy(40,10) ; cout << "\f" ; }
            for(i=0; i<800; i++){ gotoxy(41,10) ; cout << "\f" ; }
            for(i=0; i<800; i++){ gotoxy(42,10) ; cout << "\f" ; }
            for(i=0; i<800; i++){ gotoxy(43,10) ; cout << "\f" ; }
            for(i=0; i<800; i++){ gotoxy(44,10) ; cout << "\f" ; }
            for(i=0; i<800; i++){ gotoxy(45,10) ; cout << "\f" ; }
            for(i=0; i<800; i++){ gotoxy(46,10) ; cout << "\f" ; }
            for(i=0; i<800; i++){ gotoxy(47,10) ; cout << "\f" ; }
            for(i=0; i<800; i++){ gotoxy(48,10) ; cout << "\f" ; }

            for(i=0; i<800; i++){ gotoxy(34,10) ; cout << "\b_";  }
            for(i=0; i<800; i++){ gotoxy(35,10) ; cout << "\b_"; }
            for(i=0; i<800; i++){ gotoxy(36,10) ; cout << "\b_"; }
            for(i=0; i<800; i++){ gotoxy(37,10) ; cout << "\b_"; }
            for(i=0; i<800; i++){ gotoxy(38,10) ; cout << "\b_"; }
            for(i=0; i<800; i++){ gotoxy(39,10) ; cout << "\b_"; }
            for(i=0; i<800; i++){ gotoxy(40,10) ; cout << "\b_";  }
            for(i=0; i<800; i++){ gotoxy(41,10) ; cout << "\b_"; }
            for(i=0; i<800; i++){ gotoxy(42,10) ; cout << "\b_"; }
            for(i=0; i<800; i++){ gotoxy(43,10) ; cout << "\b_"; }
            for(i=0; i<800; i++){ gotoxy(44,10) ; cout << "\b_"; }
            for(i=0; i<800; i++){ gotoxy(45,10) ; cout << "\b_"; }
            for(i=0; i<800; i++){ gotoxy(46,10) ; cout << "\b_";  }
            for(i=0; i<800; i++){ gotoxy(47,10) ; cout << "\b_"; }
            for(i=0; i<800; i++){ gotoxy(48,10) ; cout << "\b_"; }
            for(i=0; i<800; i++){ gotoxy(49,10) ; cout << "\b_";  }

        }
}

#endif

	# ifndef _loading_
		# define _loading_

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
					break;
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

	# endif

	# ifndef _enter_password_
		# define _enter_password_

	void enter_password()
{
     char pass[10],ch;
      int i,k,midx,midy,left,top,label;
      label:
	 int gd=DETECT,gm;
	 initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	 setbkcolor(BLUE);
	 setcolor(GREEN);
	 settextstyle(2, HORIZ_DIR,5);
      i=k=0;

      left=getmaxx()/2-200;
      top=getmaxy()/2-50;
      midx=getmaxx()/2;
      midy=getmaxy()/2;

      outtextxy(left+40,top,"Enter Password:");
	  while((ch=getch())!=13)  //13 is ascii code of enter key
	  {
	       k=k+10;
	       outtextxy(left+160+k,top,"*");
	       pass[i]=ch;
	       i++;

	  }
	  pass[i]='\0';
	  if(strcmp(pass,"admin")==0)
	  {
	       outtextxy(midx-100,midy,"password accepted....please wait");
	       delay(1000);
		  setbkcolor(BLACK);
	  }

	else
	  {
	       outtextxy(midx-100,midy,"access denied.......try again");
	       delay(1000);
	       goto label;
	  }

}


	#endif
	

	# ifndef _background_class_
		# define _background_class_

		class background {
			public:
				void drawAxes(int);
				mainMenuInput drawBackground();
		};

		void background::drawAxes(int color) {
			setcolor(WHITE);
			line(0, 250, getmaxx(), 250);
			int i=0;

			for (float lineX = 320-6*(50*M_PI)/pi; lineX <= 640; lineX += (50*M_PI)/pi) {
				setcolor(WHITE);

				if (i != 6) {
					setcolor(DARKGRAY);
				}

				line(lineX, 0, lineX, getmaxy());
				i++;
			}

			setcolor(WHITE);
			settextstyle(0, 0, 0);

			outtextxy(324, 254, "0");
			outtextxy(2, 255, "-X");
			outtextxy(getmaxx() - 10, 255, "X");
			outtextxy(324, 2, "Y");
			outtextxy(324, getmaxy() - 10, "-Y");

			setcolor(color);
		}

		mainMenuInput background::drawBackground() {
			char ch;

			setbkcolor(RED);
			setcolor(YELLOW);
			
			settextstyle(7, 0, 3);
			outtextxy(80, 15, "TRIGONOMETRIC GRAPHING CALCULATOR");
			setlinestyle(3, 1, 3);

			line(75, 10, 595, 10);
			line(170, 15, 480, 15);
			line(170, 45, 480, 45);
			line(75, 50, 595, 50);

			settextstyle(8, 0, 1);
			outtextxy(50, 60, "y=sin(x)");
			outtextxy(190, 60, "y=cos(x)");
			outtextxy(330, 60, "y=tan(x)");
			outtextxy(470, 60, "y=cot(x)");
			outtextxy(50, 120, "y=sec(x)");
			outtextxy(190, 120, "y=cosec(x)");
			outtextxy(330, 120, "x=sin(y)");
			outtextxy(470, 120, "x=cos(y)");
			outtextxy(50, 180, "x=tan(y)");
			outtextxy(190, 180, "x=cot(y)");
			outtextxy(330, 180, "x=sec(y)");
			outtextxy(470, 180, "x=cosec(y)");
			outtextxy(50, 240, "Specials");

			settextstyle(0, 0, 0);
			outtextxy(560, 430, "made by:-");
			outtextxy(500, 440, "Pranav Garg and");
			outtextxy(520, 450, "Adersh Varshnei");

			settextstyle(8, 0, 3);
			outtextxy(50, 300, "NOTE:-");
			settextstyle(6, 0, 2);
			outtextxy(50, 330, "Press up and down to move the box up and downwards");
			outtextxy(50, 350, "Press left and right to move the box sidewards");
			outtextxy(50, 370, "Press 'enter' to select an option");
			outtextxy(50, 390, "Press 'e' to exit");


			//to make the arrow
			int m = 0;

			setlinestyle(0, 0, 0);

			int x1 = 30, y1 = 65, x2 = 40, y2 = 75, x3 = 30, y3 = 75;

			int poly[] = {
				x1,
				y1,
				x2,
				y2,
				x3,
				y3
			};

			fillpoly(3, poly);

			int a[] = {
				x1,
				85,
				x2,
				y2,
				x3,
				y3,
				x1,
				85
			};

			drawpoly(4, a);

			for (int i = 0;; i++) {
				switch ((ch = getch())) {
					case 77:
						//to move arrow right side
						if (y1 == 205) {
							continue;
						} else if (x1 == 450) {
							continue;
						} else if (y1 == 245) {
							continue;
						}

						int x = 0;
						x1 += 140;
						x2 += 140;
						x3 += 140;

						setcolor(YELLOW);

						int g[] = {
							x1,
							y1,
							x2,
							y2,
							x3,
							y3
						};

						int f[] = {
							x1,
							y1 + 25,
							x2,
							y2,
							x3,
							y3,
							x1,
							y1 + 25
						};

						int ag[] = {
							x1 - 140,
							y1,
							x2 - 140,
							y2,
							x3 - 140,
							y3
						};

						int af[] = {
							x1 - 140,
							y1 + 25,
							x2 - 140,
							y2,
							x3 - 140,
							y3,
							x1 - 140,
							y1 + 25
						};

						setcolor(RED);
						setfillstyle(1, 4);

						fillpoly(3, ag);
						drawpoly(4, af);

						setcolor(YELLOW);
						setfillstyle(1, 14);

						while (x == 0) {
							setcolor(RED);
							setfillstyle(1, 4);

							fillpoly(3, poly);
							drawpoly(4, a);

							setcolor(YELLOW);
							setfillstyle(1, 14);

							x++;
						}

						fillpoly(3, g);
						drawpoly(4, f);

						continue;

					case 75: //to move left
						if (x1 == 30) {
							continue;
						}

						x1 -= 140;
						x2 -= 140;
						x3 -= 140;

						setcolor(YELLOW);

						int b[] = {
							x1,
							y1,
							x2,
							y2,
							x3,
							y3
						};

						int c[] = {
							x1,
							y1 + 25,
							x2,
							y2,
							x3,
							y3,
							x1,
							y1 + 25
						};

						int ac[] = {
							x1 + 140,
							y1,
							x2 + 140,
							y2,
							x3 + 140,
							y3
						};

						int ab[] = {
							x1 + 140,
							y1 + 25,
							x2 + 140,
							y2,
							x3 + 140,
							y3,
							x1 + 140,
							y1 + 25
						};
						
						int z = 0;

						setcolor(RED);
						setfillstyle(1, 4);
						
						fillpoly(3, ac);
						drawpoly(4, ab);
						
						setcolor(YELLOW);
						setfillstyle(1, 14);

						while (z == 0) {
							setcolor(RED);
							setfillstyle(1, 4);

							fillpoly(3, poly);
							drawpoly(4, a);
							
							setcolor(YELLOW);
							setfillstyle(1, 14);
							
							z++;
						}

						fillpoly(3, b);
						drawpoly(4, c);

						continue;

					case 80: //to move it down
						if (y1 == 245) {
							continue;
						} else if (y1 == 185 && x1 != 30) {
							continue;
						}

						y1 += 60;
						y2 += 60;
						y3 += 60;

						int d[] = {
							x1,
							y1,
							x2,
							y2,
							x3,
							y3
						};

						int e[] = {
							x1,
							y1 + 25,
							x2,
							y2,
							x3,
							y3,
							x1,
							y1 + 25
						};

						int ae[] = {
							x1,
							y1 - 60,
							x2,
							y2 - 60,
							x3,
							y3 - 60
						};

						int ad[] = {
							x1,
							y1 - 35,
							x2,
							y2 - 60,
							x3,
							y3 - 60,
							x1,
							y1 - 35
						};

						setcolor(RED);
						setfillstyle(1, 4);
						
						fillpoly(3, ae);
						drawpoly(4, ad);
						
						setcolor(YELLOW);
						setfillstyle(1, 14);

						while (m == 0) {
							setcolor(RED);
							setfillstyle(1, 4);
							
							fillpoly(3, poly);
							drawpoly(4, a);
							
							setcolor(YELLOW);
							setfillstyle(1, 14);
							
							m++;
						}

						setcolor(YELLOW);
						fillpoly(3, d);
						drawpoly(4, e);

						continue;


					case 72: //to move the box upward
						if (y1 == 65) {
							continue;
						}

						y1 -= 60;
						y2 -= 60;
						y3 -= 60;


						int p[] = {
							x1,
							y1,
							x2,
							y2,
							x3,
							y3
						};
						
						int r[] = {
							x1,
							y1 + 25,
							x2,
							y2,
							x3,
							y3,
							x1,
							y1 + 25
						};
						
						int ar[] = {
							x1,
							y1 + 60,
							x2,
							y2 + 60,
							x3,
							y3 + 60
						};
						
						int ap[] = {
							x1,
							y1 + 85,
							x2,
							y2 + 60,
							x3,
							y3 + 60,
							x1,
							y1 + 85
						};
						
						int n = 0;
						
						setcolor(RED);
						setfillstyle(1, 4);
						
						fillpoly(3, ar);
						drawpoly(4, ap);
						
						setcolor(YELLOW);
						setfillstyle(1, 14);
						
						while (n == 0) {
							setcolor(RED);
							setfillstyle(1, 4);

							fillpoly(3, poly);
							drawpoly(4, a);
							
							setcolor(YELLOW);
							setfillstyle(1, 14);
							
							n++;
						}

						setcolor(YELLOW);
						fillpoly(3, p);
						drawpoly(4, r);
						continue;

					case 13:
						if (x1 == 30 && y1 == 65) {
							return sinX;
						} //sin(x)
						if (x1 == 170 && y1 == 65) {
							return cosX;
						} //cos(x)
						if (x1 == 310 && y1 == 65) {
							return tanX;
						} //tan(x)
						if (x1 == 450 && y1 == 65) {
							return cotX;
						} //cot(x)
						if (x1 == 30 && y1 == 125) {
							return secX;
						} //sec(x)
						if (x1 == 170 && y1 == 125) {
							return cosecX;
						} //cosec(x)
						if (x1 == 310 && y1 == 125) {
							return sinY;
						} //sin(y)
						if (x1 == 450 && y1 == 125) {
							return cosY;
						} //cos(y)
						if (x1 == 30 && y1 == 185) {
							return tanY;
						} //tan(y)
						if (x1 == 170 && y1 == 185) {
							return cotY;
						} //cot(y)
						if (x1 == 310 && y1 == 185) {
							return secY;
						} //sec(y)
						if (x1 == 450 && y1 == 185) {
							return cosecY;
						} //cosec(y)
						if (x1 == 30 && y1 == 245) {
							return spec;
						} //Specials
						
						break;
			
					case 'e':
					case 'E':
						exit(0);
				}
			
			}

		}

	# endif

# endif