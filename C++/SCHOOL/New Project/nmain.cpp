#include "npredef.h"
#include "ntrig.h"
#include "ninvtrig.h"
#include "ncombos.h"
#include "nhistory.h"

mainMenuInput   input;
coordinate      c1;
mod             modifiers;
history         hist;
background      bg;
trigGraphs      tGraph;
invTrigGraphs   itGraph;
historyTextFile textFile;

mod
modifierInput(mod modifiers) {
   cout << "Enter argument mod: ";
   cin >> modifiers.arg;
   cout << "Enter coefficient of x: ";
   cin >> modifiers.coeffX;
   cout << "enter coefficient of y: ";
   cin >> modifiers.coeffY;

   return modifiers;
}

int  color;
long count      = 0;
int  noOfGraphs = 1;

int
main(void) {
   int  rep = 1;
   int  gd  = DETECT, gm;
   char ch;

   randomize();
   textFile.fileCheck();

   initgraph(&gd, &gm, "C:\\turboc3\\bgi");
   setgraphmode(VGAHI);

   timesUsedVar var;
   var.sinUsed = var.cosUsed = var.tanUsed = 0;
   var.cotUsed = var.secUsed = var.cosecUsed = 0;

   loading();

   while ( rep == 1 ) {
      int repChoice;
      int masterChoice;
      int choice;

      clrscr();
      cleardevice();

      input = bg.drawBackground();

      color = 1 + random(14);

      switch ( input ) {
      case sinX:
         cleardevice();
         setbkcolor(BLACK);

      sinXComp:
         modifiers = modifierInput(modifiers);

         gcvt(modifiers.arg, 4, hist.arg);
         gcvt(modifiers.coeffX, 4, hist.coeffX);
         gcvt(modifiers.coeffY, 4, hist.coeffY);

         if ( noOfGraphs != 2 ) {
            clrscr();
            cleardevice();
         }

         bg.drawAxes(color);

         tGraph.sinGraph(c1, modifiers, color);
         cout << modifiers.coeffY << "y=" << modifiers.coeffX << "sin("
              << modifiers.arg << "x)";
         strcat(hist.overall, hist.coeffY);
         strcat(hist.overall, "y=");
         strcat(hist.overall, hist.coeffX);
         strcat(hist.overall, "sin(");
         strcat(hist.overall, hist.arg);
         strcat(hist.overall, "x)\n");
         var.sinUsed++;

         if ( noOfGraphs == 1 ) {
            cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
            cin >> repChoice;

            noOfGraphs = 2;

            if ( repChoice == 1 ) {
               goto sinXComp;
            }
         }

         getch();
         break;

      case cosX:
         cleardevice();
         setbkcolor(BLACK);

         noOfGraphs = 1;

      cosXComp:
         modifiers = modifierInput(modifiers);

         gcvt(modifiers.arg, 4, hist.arg);
         gcvt(modifiers.coeffX, 4, hist.coeffX);
         gcvt(modifiers.coeffY, 4, hist.coeffY);

         if ( noOfGraphs != 2 ) {
            clrscr();
            cleardevice();
         }

         bg.drawAxes(color);

         tGraph.cosGraph(c1, modifiers, color);
         cout << modifiers.coeffY << "y=" << modifiers.coeffX << "cos("
              << modifiers.arg << "x)";
         strcat(hist.overall, hist.coeffY);
         strcat(hist.overall, "y=");
         strcat(hist.overall, hist.coeffX);
         strcat(hist.overall, "cos(");
         strcat(hist.overall, hist.arg);
         strcat(hist.overall, "x)\n");
         var.cosUsed++;

         if ( noOfGraphs == 1 ) {
            cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
            cin >> repChoice;

            noOfGraphs = 2;

            if ( repChoice == 1 ) {
               goto cosXComp;
            }
         }

         getch();
         break;

      case tanX:
         cleardevice();
         setbkcolor(BLACK);

         noOfGraphs = 1;

      tanXComp:
         modifiers = modifierInput(modifiers);

         gcvt(modifiers.arg, 4, hist.arg);
         gcvt(modifiers.coeffX, 4, hist.coeffX);
         gcvt(modifiers.coeffY, 4, hist.coeffY);

         if ( noOfGraphs != 2 ) {
            clrscr();
            cleardevice();
         }

         bg.drawAxes(color);

         tGraph.tanGraph(c1, modifiers, color);
         cout << modifiers.coeffY << "y=" << modifiers.coeffX << "tan("
              << modifiers.arg << "x)";
         strcat(hist.overall, hist.coeffY);
         strcat(hist.overall, "y=");
         strcat(hist.overall, hist.coeffX);
         strcat(hist.overall, "tan(");
         strcat(hist.overall, hist.arg);
         strcat(hist.overall, "x)\n");
         var.tanUsed++;

         if ( noOfGraphs == 1 ) {
            cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
            cin >> repChoice;

            noOfGraphs = 2;

            if ( repChoice == 1 ) {
               goto tanXComp;
            }
         }

         getch();
         break;

      case cotX:
         cleardevice();
         setbkcolor(BLACK);

         noOfGraphs = 1;

      cotXComp:
         modifiers = modifierInput(modifiers);

         gcvt(modifiers.arg, 4, hist.arg);
         gcvt(modifiers.coeffX, 4, hist.coeffX);
         gcvt(modifiers.coeffY, 4, hist.coeffY);

         if ( noOfGraphs != 2 ) {
            clrscr();
            cleardevice();
         }

         bg.drawAxes(color);

         tGraph.cotGraph(c1, modifiers, color);
         cout << modifiers.coeffY << "y=" << modifiers.coeffX << "cot("
              << modifiers.arg << "x)";
         strcat(hist.overall, hist.coeffY);
         strcat(hist.overall, "y=");
         strcat(hist.overall, hist.coeffX);
         strcat(hist.overall, "cot(");
         strcat(hist.overall, hist.arg);
         strcat(hist.overall, "x)\n");
         var.cotUsed++;

         if ( noOfGraphs == 1 ) {
            cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
            cin >> repChoice;

            noOfGraphs = 2;

            if ( repChoice == 1 ) {
               goto cotXComp;
            }
         }

         getch();
         break;

      case secX:
         cleardevice();
         setbkcolor(BLACK);

         noOfGraphs = 1;

      secXComp:
         modifiers = modifierInput(modifiers);

         gcvt(modifiers.arg, 4, hist.arg);
         gcvt(modifiers.coeffX, 4, hist.coeffX);
         gcvt(modifiers.coeffY, 4, hist.coeffY);

         if ( noOfGraphs != 2 ) {
            clrscr();
            cleardevice();
         }

         bg.drawAxes(color);

         tGraph.secGraph(c1, modifiers, color);
         cout << modifiers.coeffY << "y=" << modifiers.coeffX << "sec("
              << modifiers.arg << "x)";
         strcat(hist.overall, hist.coeffY);
         strcat(hist.overall, "y=");
         strcat(hist.overall, hist.coeffX);
         strcat(hist.overall, "sec(");
         strcat(hist.overall, hist.arg);
         strcat(hist.overall, "x)\n");
         var.secUsed++;

         if ( noOfGraphs == 1 ) {
            cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
            cin >> repChoice;

            noOfGraphs = 2;

            if ( repChoice == 1 ) {
               goto secXComp;
            }
         }

         getch();
         break;

      case cosecX:
         cleardevice();
         setbkcolor(BLACK);

         noOfGraphs = 1;

      cosecXComp:
         modifiers = modifierInput(modifiers);

         gcvt(modifiers.arg, 4, hist.arg);
         gcvt(modifiers.coeffX, 4, hist.coeffX);
         gcvt(modifiers.coeffY, 4, hist.coeffY);

         if ( noOfGraphs != 2 ) {
            clrscr();
            cleardevice();
         }

         bg.drawAxes(color);

         tGraph.cosecGraph(c1, modifiers, color);
         cout << modifiers.coeffY << "y=" << modifiers.coeffX << "cosec("
              << modifiers.arg << "x)";
         strcat(hist.overall, hist.coeffY);
         strcat(hist.overall, "y=");
         strcat(hist.overall, hist.coeffX);
         strcat(hist.overall, "cosec(");
         strcat(hist.overall, hist.arg);
         strcat(hist.overall, "x)\n");
         var.cosecUsed++;

         if ( noOfGraphs == 1 ) {
            cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
            cin >> repChoice;

            noOfGraphs = 2;

            if ( repChoice == 1 ) {
               goto cosecXComp;
            }
         }

         getch();
         break;

      case sinY:
         cleardevice();
         setbkcolor(BLACK);

         noOfGraphs = 1;

      sinYComp:
         modifiers = modifierInput(modifiers);

         gcvt(modifiers.arg, 4, hist.arg);
         gcvt(modifiers.coeffX, 4, hist.coeffX);
         gcvt(modifiers.coeffY, 4, hist.coeffY);

         if ( noOfGraphs != 2 ) {
            clrscr();
            cleardevice();
         }

         bg.drawAxes(color);

         itGraph.invSinGraph(c1, modifiers, color);
         cout << modifiers.coeffX << "x=" << modifiers.coeffY << "sin("
              << modifiers.arg << "y)";

         strcat(hist.overall, hist.coeffX);
         strcat(hist.overall, "x=");
         strcat(hist.overall, hist.coeffY);
         strcat(hist.overall, "sin(");
         strcat(hist.overall, hist.arg);
         strcat(hist.overall, "y)\n");
         var.sinUsed++;

         if ( noOfGraphs == 1 ) {
            cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
            cin >> repChoice;

            noOfGraphs = 2;

            if ( repChoice == 1 ) {
               goto sinYComp;
            }
         }

         getch();
         break;

      case cosY:
         cleardevice();
         setbkcolor(BLACK);

         noOfGraphs = 1;

      cosYComp:
         modifiers = modifierInput(modifiers);

         gcvt(modifiers.arg, 4, hist.arg);
         gcvt(modifiers.coeffX, 4, hist.coeffX);
         gcvt(modifiers.coeffY, 4, hist.coeffY);

         if ( noOfGraphs != 2 ) {
            clrscr();
            cleardevice();
         }

         bg.drawAxes(color);

         itGraph.invCosGraph(c1, modifiers, color);
         cout << modifiers.coeffX << "x=" << modifiers.coeffY << "cos("
              << modifiers.arg << "y)";

         strcat(hist.overall, hist.coeffX);
         strcat(hist.overall, "x=");
         strcat(hist.overall, hist.coeffY);
         strcat(hist.overall, "cos(");
         strcat(hist.overall, hist.arg);
         strcat(hist.overall, "y)\n");
         var.cosUsed++;

         if ( noOfGraphs == 1 ) {
            cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
            cin >> repChoice;

            noOfGraphs = 2;

            if ( repChoice == 1 ) {
               goto cosYComp;
            }
         }

         getch();
         break;

      case tanY:
         cleardevice();
         setbkcolor(BLACK);

         noOfGraphs = 1;

      tanYComp:
         modifiers = modifierInput(modifiers);

         gcvt(modifiers.arg, 4, hist.arg);
         gcvt(modifiers.coeffX, 4, hist.coeffX);
         gcvt(modifiers.coeffY, 4, hist.coeffY);

         if ( noOfGraphs != 2 ) {
            clrscr();
            cleardevice();
         }

         bg.drawAxes(color);

         itGraph.invTanGraph(c1, modifiers, color);
         cout << modifiers.coeffX << "x=" << modifiers.coeffY << "tan("
              << modifiers.arg << "y)";

         strcat(hist.overall, hist.coeffX);
         strcat(hist.overall, "x=");
         strcat(hist.overall, hist.coeffY);
         strcat(hist.overall, "tan(");
         strcat(hist.overall, hist.arg);
         strcat(hist.overall, "y)\n");
         var.tanUsed++;

         if ( noOfGraphs == 1 ) {
            cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
            cin >> repChoice;

            noOfGraphs = 2;

            if ( repChoice == 1 ) {
               goto tanYComp;
            }
         }

         getch();
         break;

      case cotY:
         cleardevice();
         setbkcolor(BLACK);

         noOfGraphs = 1;

      cotYComp:
         modifiers = modifierInput(modifiers);

         gcvt(modifiers.arg, 4, hist.arg);
         gcvt(modifiers.coeffX, 4, hist.coeffX);
         gcvt(modifiers.coeffY, 4, hist.coeffY);

         if ( noOfGraphs != 2 ) {
            clrscr();
            cleardevice();
         }

         bg.drawAxes(color);

         itGraph.invCotGraph(c1, modifiers, color);
         cout << modifiers.coeffX << "x=" << modifiers.coeffY << "cot("
              << modifiers.arg << "y)";

         strcat(hist.overall, hist.coeffX);
         strcat(hist.overall, "x=");
         strcat(hist.overall, hist.coeffY);
         strcat(hist.overall, "cot(");
         strcat(hist.overall, hist.arg);
         strcat(hist.overall, "y)\n");
         var.cotUsed++;

         if ( noOfGraphs == 1 ) {
            cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
            cin >> repChoice;

            noOfGraphs = 2;

            if ( repChoice == 1 ) {
               goto cotYComp;
            }
         }

         getch();
         break;

      case secY:
         cleardevice();
         setbkcolor(BLACK);

         noOfGraphs = 1;

      secYComp:
         modifiers = modifierInput(modifiers);

         gcvt(modifiers.arg, 4, hist.arg);
         gcvt(modifiers.coeffX, 4, hist.coeffX);
         gcvt(modifiers.coeffY, 4, hist.coeffY);

         if ( noOfGraphs != 2 ) {
            clrscr();
            cleardevice();
         }

         bg.drawAxes(color);

         itGraph.invSecGraph(c1, modifiers, color);
         cout << modifiers.coeffX << "x=" << modifiers.coeffY << "sec("
              << modifiers.arg << "y)";

         strcat(hist.overall, hist.coeffX);
         strcat(hist.overall, "x=");
         strcat(hist.overall, hist.coeffY);
         strcat(hist.overall, "sec(");
         strcat(hist.overall, hist.arg);
         strcat(hist.overall, "y)\n");
         var.secUsed++;

         if ( noOfGraphs == 1 ) {
            cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
            cin >> repChoice;

            noOfGraphs = 2;

            if ( repChoice == 1 ) {
               goto secYComp;
            }
         }

         getch();
         break;

      case cosecY:
         cleardevice();
         setbkcolor(BLACK);

         noOfGraphs = 1;

      cosecYComp:
         modifiers = modifierInput(modifiers);

         gcvt(modifiers.arg, 4, hist.arg);
         gcvt(modifiers.coeffX, 4, hist.coeffX);
         gcvt(modifiers.coeffY, 4, hist.coeffY);

         if ( noOfGraphs != 2 ) {
            clrscr();
            cleardevice();
         }

         bg.drawAxes(color);

         itGraph.invCosecGraph(c1, modifiers, color);
         cout << modifiers.coeffX << "x=" << modifiers.coeffY << "cosec("
              << modifiers.arg << "y)";

         strcat(hist.overall, hist.coeffX);
         strcat(hist.overall, "x=");
         strcat(hist.overall, hist.coeffY);
         strcat(hist.overall, "cosec(");
         strcat(hist.overall, hist.arg);
         strcat(hist.overall, "y)\n");
         var.cosecUsed++;

         if ( noOfGraphs == 1 ) {
            cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
            cin >> repChoice;

            noOfGraphs = 2;

            if ( repChoice == 1 ) {
               goto cosecYComp;
            }
         }

         getch();
         break;

      case spec:
         cleardevice();
         setbkcolor(BLACK);

         cout << "1. Addition Combination Graphs" << endl;
         cout << "2. Multiplication Combination Graphs" << endl;
         cout << "3. Nested Combination Graphs" << endl;
         cout << "4. History Display" << endl;
         cin >> masterChoice;

         switch ( masterChoice ) {
         case 4:
            textFile.writeToFile(hist);
            strcpy(hist.overall, "");

            textFile.readFromFile();
            break;
         }

         getch();

         break;
      }
   }
   closegraph();
   getch();
}