#include "npredef.h"
#include "ntrig.h"
#include "ninvtrig.h"
#include "ncombos.h"
#include "nhistory.h"
#include "nbinary.h"

mainMenuInput input;
coordinate c1;
mod modifiers;
history hist;
background bg;
trigGraphs tGraph;
invTrigGraphs itGraph;
comboGraphs cGraph;
historyTextFile textFile;
binaryClass binClass;
binaryFile binFile;

int color;
long count = 0;
int noOfGraphs = 1;

int main(void) {
	int rep = 1;
	int gd = DETECT, gm;
	char ch;

	randomize();
	textFile.fileCheck();
	binFile.fileCheck();


	loading_2();

	initgraph( & gd, & gm, "C:\\turboc3\\bgi");
	setgraphmode(VGAHI);

	enter_password();

	loading();

	while (rep == 1) {
		int repChoice;
		int masterChoice;
		int choice;
		int binGraphChoice = 1;

		clrscr();
		cleardevice();

		input = bg.drawBackground();

		color = 1 + random(14);

		switch (input) {
			case sinX:
				closegraph();

				loading_2();

				initgraph( & gd, & gm, "C:\\turboc3\\bgi");
				setgraphmode(VGAHI);
				cleardevice();
				setbkcolor(BLACK);

				sinXComp:
				modifiers = modifierInput(modifiers);

				gcvt(modifiers.arg, 4, hist.arg);
				gcvt(modifiers.coeffX, 4, hist.coeffX);
				gcvt(modifiers.coeffY, 4, hist.coeffY);

				if (noOfGraphs != 2) {
					clrscr();
					cleardevice();
				}

				bg.drawAxes(color);

				color = 1 + random(14);
				setcolor(color);
				tGraph.sinGraph(c1, modifiers, color);
				cout << modifiers.coeffY << "y=" << modifiers.coeffX << "sin(" << modifiers.arg << "x)";
				strcat(hist.overall, hist.coeffY);
				strcat(hist.overall, "y=");
				strcat(hist.overall, hist.coeffX);
				strcat(hist.overall, "sin(");
				strcat(hist.overall, hist.arg);
				strcat(hist.overall, "x)\n");

				textFile.writeToFile(hist);
				strcpy(hist.overall, "");

				if (noOfGraphs == 1) {
					cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
					cin >> repChoice;

					noOfGraphs = 2;

					if (repChoice == 1) {
						goto sinXComp;
					}
				} else if (noOfGraphs == 2) {
					noOfGraphs = 1;
				}

				getch();
				break;

			case cosX:
				closegraph();

				loading_2();

				initgraph( & gd, & gm, "C:\\turboc3\\bgi");
				setgraphmode(VGAHI);
				cleardevice();
				setbkcolor(BLACK);

				noOfGraphs = 1;

				cosXComp:
				modifiers = modifierInput(modifiers);

				gcvt(modifiers.arg, 4, hist.arg);
				gcvt(modifiers.coeffX, 4, hist.coeffX);
				gcvt(modifiers.coeffY, 4, hist.coeffY);

				if (noOfGraphs != 2) {
					clrscr();
					cleardevice();
				}

				bg.drawAxes(color);

				color = 1 + random(14);
				setcolor(color);
				tGraph.cosGraph(c1, modifiers, color);
				cout << modifiers.coeffY << "y=" << modifiers.coeffX << "cos(" << modifiers.arg << "x)";
				strcat(hist.overall, hist.coeffY);
				strcat(hist.overall, "y=");
				strcat(hist.overall, hist.coeffX);
				strcat(hist.overall, "cos(");
				strcat(hist.overall, hist.arg);
				strcat(hist.overall, "x)\n");

				textFile.writeToFile(hist);
				strcpy(hist.overall, "");

				if (noOfGraphs == 1) {
					cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
					cin >> repChoice;

					noOfGraphs = 2;

					if (repChoice == 1) {
						goto cosXComp;
					}
				} else if (noOfGraphs == 2) {
					noOfGraphs = 1;
				}

				getch();
				break;

			case tanX:

				closegraph();

				loading_2();

				initgraph( & gd, & gm, "C:\\turboc3\\bgi");
				setgraphmode(VGAHI);
				cleardevice();
				setbkcolor(BLACK);

				noOfGraphs = 1;

				tanXComp:
				modifiers = modifierInput(modifiers);

				gcvt(modifiers.arg, 4, hist.arg);
				gcvt(modifiers.coeffX, 4, hist.coeffX);
				gcvt(modifiers.coeffY, 4, hist.coeffY);

				if (noOfGraphs != 2) {
					clrscr();
					cleardevice();
				}

				bg.drawAxes(color);

				color = 1 + random(14);
				setcolor(color);
				tGraph.tanGraph(c1, modifiers, color);
				cout << modifiers.coeffY << "y=" << modifiers.coeffX << "tan(" << modifiers.arg << "x)";
				strcat(hist.overall, hist.coeffY);
				strcat(hist.overall, "y=");
				strcat(hist.overall, hist.coeffX);
				strcat(hist.overall, "tan(");
				strcat(hist.overall, hist.arg);
				strcat(hist.overall, "x)\n");

				textFile.writeToFile(hist);
				strcpy(hist.overall, "");

				if (noOfGraphs == 1) {
					cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
					cin >> repChoice;

					noOfGraphs = 2;

					if (repChoice == 1) {
						goto tanXComp;
					}
				} else if (noOfGraphs == 2) {
					noOfGraphs = 1;
				}

				getch();
				break;

			case cotX:
				closegraph();

				loading_2();

				initgraph( & gd, & gm, "C:\\turboc3\\bgi");
				setgraphmode(VGAHI);
				cleardevice();
				setbkcolor(BLACK);

				noOfGraphs = 1;

				cotXComp:
				modifiers = modifierInput(modifiers);

				gcvt(modifiers.arg, 4, hist.arg);
				gcvt(modifiers.coeffX, 4, hist.coeffX);
				gcvt(modifiers.coeffY, 4, hist.coeffY);

				if (noOfGraphs != 2) {
					clrscr();
					cleardevice();
				}

				bg.drawAxes(color);

				color = 1 + random(14);
				setcolor(color);
				tGraph.cotGraph(c1, modifiers, color);
				cout << modifiers.coeffY << "y=" << modifiers.coeffX << "cot(" << modifiers.arg << "x)";
				strcat(hist.overall, hist.coeffY);
				strcat(hist.overall, "y=");
				strcat(hist.overall, hist.coeffX);
				strcat(hist.overall, "cot(");
				strcat(hist.overall, hist.arg);
				strcat(hist.overall, "x)\n");

				textFile.writeToFile(hist);
				strcpy(hist.overall, "");

				if (noOfGraphs == 1) {
					cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
					cin >> repChoice;

					noOfGraphs = 2;

					if (repChoice == 1) {
						goto cotXComp;
					}
				} else if (noOfGraphs == 2) {
					noOfGraphs = 1;
				}

				getch();
				break;

			case secX:
				closegraph();

				loading_2();

				initgraph( & gd, & gm, "C:\\turboc3\\bgi");
				setgraphmode(VGAHI);
				cleardevice();
				setbkcolor(BLACK);

				noOfGraphs = 1;

				secXComp:
				modifiers = modifierInput(modifiers);

				gcvt(modifiers.arg, 4, hist.arg);
				gcvt(modifiers.coeffX, 4, hist.coeffX);
				gcvt(modifiers.coeffY, 4, hist.coeffY);

				if (noOfGraphs != 2) {
					clrscr();
					cleardevice();
				}

				bg.drawAxes(color);

				color = 1 + random(14);
				setcolor(color);
				tGraph.secGraph(c1, modifiers, color);
				cout << modifiers.coeffY << "y=" << modifiers.coeffX << "sec(" << modifiers.arg << "x)";
				strcat(hist.overall, hist.coeffY);
				strcat(hist.overall, "y=");
				strcat(hist.overall, hist.coeffX);
				strcat(hist.overall, "sec(");
				strcat(hist.overall, hist.arg);
				strcat(hist.overall, "x)\n");

				textFile.writeToFile(hist);
				strcpy(hist.overall, "");

				if (noOfGraphs == 1) {
					cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
					cin >> repChoice;

					noOfGraphs = 2;

					if (repChoice == 1) {
						goto secXComp;
					}
				} else if (noOfGraphs == 2) {
					noOfGraphs = 1;
				}

				getch();
				break;

			case cosecX:
				closegraph();

				loading_2();

				initgraph( & gd, & gm, "C:\\turboc3\\bgi");
				setgraphmode(VGAHI);
				cleardevice();
				setbkcolor(BLACK);

				noOfGraphs = 1;

				cosecXComp:
				modifiers = modifierInput(modifiers);

				gcvt(modifiers.arg, 4, hist.arg);
				gcvt(modifiers.coeffX, 4, hist.coeffX);
				gcvt(modifiers.coeffY, 4, hist.coeffY);

				if (noOfGraphs != 2) {
					clrscr();
					cleardevice();
				}

				bg.drawAxes(color);

				color = 1 + random(14);
				setcolor(color);
				tGraph.cosecGraph(c1, modifiers, color);
				cout << modifiers.coeffY << "y=" << modifiers.coeffX << "cosec(" << modifiers.arg << "x)";
				strcat(hist.overall, hist.coeffY);
				strcat(hist.overall, "y=");
				strcat(hist.overall, hist.coeffX);
				strcat(hist.overall, "cosec(");
				strcat(hist.overall, hist.arg);
				strcat(hist.overall, "x)\n");

				textFile.writeToFile(hist);
				strcpy(hist.overall, "");

				if (noOfGraphs == 1) {
					cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
					cin >> repChoice;

					noOfGraphs = 2;

					if (repChoice == 1) {
						goto cosecXComp;
					}
				} else if (noOfGraphs == 2) {
					noOfGraphs = 1;
				}

				getch();
				break;

			case sinY:
				closegraph();

				loading_2();

				initgraph( & gd, & gm, "C:\\turboc3\\bgi");
				setgraphmode(VGAHI);
				cleardevice();
				setbkcolor(BLACK);

				noOfGraphs = 1;

				sinYComp:
				modifiers = modifierInput(modifiers);

				gcvt(modifiers.arg, 4, hist.arg);
				gcvt(modifiers.coeffX, 4, hist.coeffX);
				gcvt(modifiers.coeffY, 4, hist.coeffY);

				if (noOfGraphs != 2) {
					clrscr();
					cleardevice();
				}

				bg.drawAxes(color);

				color = 1 + random(14);
				setcolor(color);
				itGraph.invSinGraph(c1, modifiers, color);
				cout << modifiers.coeffX << "x=" << modifiers.coeffY << "sin(" << modifiers.arg << "y)";

				strcat(hist.overall, hist.coeffX);
				strcat(hist.overall, "x=");
				strcat(hist.overall, hist.coeffY);
				strcat(hist.overall, "sin(");
				strcat(hist.overall, hist.arg);
				strcat(hist.overall, "y)\n");

				textFile.writeToFile(hist);
				strcpy(hist.overall, "");

				if (noOfGraphs == 1) {
					cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
					cin >> repChoice;

					noOfGraphs = 2;

					if (repChoice == 1) {
						goto sinYComp;
					}
				} else if (noOfGraphs == 2) {
					noOfGraphs = 1;
				}

				getch();
				break;

			case cosY:
				closegraph();

				loading_2();

				initgraph( & gd, & gm, "C:\\turboc3\\bgi");
				setgraphmode(VGAHI);
				cleardevice();
				setbkcolor(BLACK);

				noOfGraphs = 1;

				cosYComp:
				modifiers = modifierInput(modifiers);

				gcvt(modifiers.arg, 4, hist.arg);
				gcvt(modifiers.coeffX, 4, hist.coeffX);
				gcvt(modifiers.coeffY, 4, hist.coeffY);

				if (noOfGraphs != 2) {
					clrscr();
					cleardevice();
				}

				bg.drawAxes(color);

				color = 1 + random(14);
				setcolor(color);
				itGraph.invCosGraph(c1, modifiers, color);
				cout << modifiers.coeffX << "x=" << modifiers.coeffY << "cos(" << modifiers.arg << "y)";

				strcat(hist.overall, hist.coeffX);
				strcat(hist.overall, "x=");
				strcat(hist.overall, hist.coeffY);
				strcat(hist.overall, "cos(");
				strcat(hist.overall, hist.arg);
				strcat(hist.overall, "y)\n");

				textFile.writeToFile(hist);
				strcpy(hist.overall, "");

				if (noOfGraphs == 1) {
					cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
					cin >> repChoice;

					noOfGraphs = 2;

					if (repChoice == 1) {
						goto cosYComp;
					}
				} else if (noOfGraphs == 2) {
					noOfGraphs = 1;
				}

				getch();
				break;

			case tanY:
				closegraph();

				loading_2();

				initgraph( & gd, & gm, "C:\\turboc3\\bgi");
				setgraphmode(VGAHI);
				cleardevice();
				setbkcolor(BLACK);

				noOfGraphs = 1;

				tanYComp:
				modifiers = modifierInput(modifiers);

				gcvt(modifiers.arg, 4, hist.arg);
				gcvt(modifiers.coeffX, 4, hist.coeffX);
				gcvt(modifiers.coeffY, 4, hist.coeffY);

				if (noOfGraphs != 2) {
					clrscr();
					cleardevice();
				}

				bg.drawAxes(color);

				color = 1 + random(14);
				setcolor(color);
				itGraph.invTanGraph(c1, modifiers, color);
				cout << modifiers.coeffX << "x=" << modifiers.coeffY << "tan(" << modifiers.arg << "y)";

				strcat(hist.overall, hist.coeffX);
				strcat(hist.overall, "x=");
				strcat(hist.overall, hist.coeffY);
				strcat(hist.overall, "tan(");
				strcat(hist.overall, hist.arg);
				strcat(hist.overall, "y)\n");

				textFile.writeToFile(hist);
				strcpy(hist.overall, "");

				if (noOfGraphs == 1) {
					cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
					cin >> repChoice;

					noOfGraphs = 2;

					if (repChoice == 1) {
						goto tanYComp;
					}
				} else if (noOfGraphs == 2) {
					noOfGraphs = 1;
				}

				getch();
				break;

			case cotY:
				closegraph();

				loading_2();

				initgraph( & gd, & gm, "C:\\turboc3\\bgi");
				setgraphmode(VGAHI);
				cleardevice();
				setbkcolor(BLACK);

				noOfGraphs = 1;

				cotYComp:
				modifiers = modifierInput(modifiers);

				gcvt(modifiers.arg, 4, hist.arg);
				gcvt(modifiers.coeffX, 4, hist.coeffX);
				gcvt(modifiers.coeffY, 4, hist.coeffY);

				if (noOfGraphs != 2) {
					clrscr();
					cleardevice();
				}

				bg.drawAxes(color);

				color = 1 + random(14);
				setcolor(color);
				itGraph.invCotGraph(c1, modifiers, color);
				cout << modifiers.coeffX << "x=" << modifiers.coeffY << "cot(" << modifiers.arg << "y)";

				strcat(hist.overall, hist.coeffX);
				strcat(hist.overall, "x=");
				strcat(hist.overall, hist.coeffY);
				strcat(hist.overall, "cot(");
				strcat(hist.overall, hist.arg);
				strcat(hist.overall, "y)\n");

				textFile.writeToFile(hist);
				strcpy(hist.overall, "");

				if (noOfGraphs == 1) {
					cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
					cin >> repChoice;

					noOfGraphs = 2;

					if (repChoice == 1) {
						goto cotYComp;
					}
				} else if (noOfGraphs == 2) {
					noOfGraphs = 1;
				}

				getch();
				break;

			case secY:
				closegraph();

				loading_2();

				initgraph( & gd, & gm, "C:\\turboc3\\bgi");
				setgraphmode(VGAHI);
				cleardevice();
				setbkcolor(BLACK);

				noOfGraphs = 1;

				secYComp:
				modifiers = modifierInput(modifiers);

				gcvt(modifiers.arg, 4, hist.arg);
				gcvt(modifiers.coeffX, 4, hist.coeffX);
				gcvt(modifiers.coeffY, 4, hist.coeffY);

				if (noOfGraphs != 2) {
					clrscr();
					cleardevice();
				}

				bg.drawAxes(color);

				color = 1 + random(14);
				setcolor(color);
				itGraph.invSecGraph(c1, modifiers, color);
				cout << modifiers.coeffX << "x=" << modifiers.coeffY << "sec(" << modifiers.arg << "y)";

				strcat(hist.overall, hist.coeffX);
				strcat(hist.overall, "x=");
				strcat(hist.overall, hist.coeffY);
				strcat(hist.overall, "sec(");
				strcat(hist.overall, hist.arg);
				strcat(hist.overall, "y)\n");

				textFile.writeToFile(hist);
				strcpy(hist.overall, "");

				if (noOfGraphs == 1) {
					cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
					cin >> repChoice;

					noOfGraphs = 2;

					if (repChoice == 1) {
						goto secYComp;
					}
				} else if (noOfGraphs == 2) {
					noOfGraphs = 1;
				}

				getch();
				break;

			case cosecY:
				closegraph();

				loading_2();

				initgraph( & gd, & gm, "C:\\turboc3\\bgi");
				setgraphmode(VGAHI);
				cleardevice();
				setbkcolor(BLACK);

				noOfGraphs = 1;

				cosecYComp:
				modifiers = modifierInput(modifiers);

				gcvt(modifiers.arg, 4, hist.arg);
				gcvt(modifiers.coeffX, 4, hist.coeffX);
				gcvt(modifiers.coeffY, 4, hist.coeffY);

				if (noOfGraphs != 2) {
					clrscr();
					cleardevice();
				}

				bg.drawAxes(color);

				color = 1 + random(14);
				setcolor(color);
				itGraph.invCosecGraph(c1, modifiers, color);
				cout << modifiers.coeffX << "x=" << modifiers.coeffY << "cosec(" << modifiers.arg << "y)";

				strcat(hist.overall, hist.coeffX);
				strcat(hist.overall, "x=");
				strcat(hist.overall, hist.coeffY);
				strcat(hist.overall, "cosec(");
				strcat(hist.overall, hist.arg);
				strcat(hist.overall, "y)\n");

				textFile.writeToFile(hist);
				strcpy(hist.overall, "");

				if (noOfGraphs == 1) {
					cout << endl << endl << "Enter another graph (1=Yes, 2=No)" << endl;
					cin >> repChoice;

					noOfGraphs = 2;

					if (repChoice == 1) {
						goto cosecYComp;
					}
				} else if (noOfGraphs == 2) {
					noOfGraphs = 1;
				}

				getch();
				break;

			case spec:
				closegraph();

				loading_2();

				initgraph( & gd, & gm, "C:\\turboc3\\bgi");
				setgraphmode(VGAHI);
				cleardevice();
				setbkcolor(BLACK);

				cout << "1. Addition Combination Graphs" << endl;
				cout << "2. Multiplication Combination Graphs" << endl;
				cout << "3. Nested Combination Graphs" << endl;
				cout << "4. Enter Graphs Into Binary" << endl;
				cout << "5. Print Graphs From Binary" << endl;
				cout << "6. Empty Binary File" << endl;
				cout << "7. History Display" << endl;
				cin >> masterChoice;

				switch (masterChoice) {
					case 1:
						strcpy(hist.overall, cGraph.addComboGraph(c1, color));

						textFile.writeToFile(hist);
						strcpy(hist.overall, "");
						break;

					case 2:
						strcpy(hist.overall, cGraph.mulComboGraph(c1, color));

						textFile.writeToFile(hist);
						strcpy(hist.overall, "");
						break;

					case 3:
						strcpy(hist.overall, cGraph.nestComboGraph(c1, color));

						textFile.writeToFile(hist);
						strcpy(hist.overall, "");
						break;

					case 4:
						while (binGraphChoice == 1) {
							binClass.graphInput();
							binFile.writeToBinary(binClass);

							cout << "Enter more graphs? (1=Yes, 2=No): ";
							cin >> binGraphChoice;
						}

						break;

					case 5:
						clrscr();
						cleardevice();
						bg.drawAxes(color);

						binFile.printFromBinary(c1, color);

						break;

					case 6:
						binFile.fileCheck();
						break;

					case 7:
						textFile.readFromFile();
						break;
				}

				getch();

				break;

		}

	}
	closegraph();
	getch();

	return 0;
}