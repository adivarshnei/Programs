# ifndef _binary_h_
	# define _binary_h_

	# ifndef _predef_h_
		# include "npredef.h"
	# endif

	# ifndef _trig_h_
		# include "ntrig.h"
	# endif

	# ifndef _i_trig_h_
		# include "ninvtrig.h"
	# endif

	# ifndef _history_
		# include "nhistory.h"
	# endif

	# ifndef _combos_h_
		# include "ncombos.h"
	# endif

	# ifndef _binary_classes_
		# define _binary_classes_

		class binaryClass {
			public:
				graphCategory graphCat;
				trigFunc categoryOne;
				invTrigFunc invCategory;
				mod modifiersOne;
				history hist;
				binaryClass();
				void modEmpty(mod);
				void graphInput();
				void graphPrint();
		};

		void binaryClass::modEmpty(mod m) {
			m.arg = 0;
			m.coeffX = 0;
			m.coeffY = 0;
		}

		binaryClass::binaryClass() {
			graphCat = nullCat;
			categoryOne = nullTrig;
			invCategory = nullInv;
			modEmpty(modifiersOne);
		}

		void binaryClass::graphInput() {
			int choice;

			switchMasterOption:
			cout << "Enter Graph Type: " << endl;
			cout << "1. Simple Trigonometric Graph" << endl;
			cout << "2. Simple Inverse Trigonometric Graph" << endl;
			cin >> choice;

			switch (choice) {
				case 1:
					graphCat = simpleTrig;
					break;

				case 2:
					graphCat = simpleInvTrig;
					break;

				default:
					goto switchMasterOption;
					break;
			}

			int graphType;

			if (graphCat == simpleTrig) {
				oneTrigChoice: cout << "Enter graph type: " << endl;
				cout << "1. y=sin(x)" << endl;
				cout << "2. y=cos(x)" << endl;
				cout << "3. y=tan(x)" << endl;
				cout << "4. y=cot(x)" << endl;
				cout << "5. y=sec(x)" << endl;
				cout << "6. y=cosec(x)" << endl;
				cin >> graphType;

				switch (graphType) {
					case 1:
						categoryOne = sinx;
						break;

					case 2:
						categoryOne = cosx;
						break;

					case 3:
						categoryOne = tanx;
						break;

					case 4:
						categoryOne = cotx;
						break;

					case 5:
						categoryOne = secx;
						break;

					case 6:
						categoryOne = cosecx;
						break;

					default:
						goto oneTrigChoice;
						break;
				}

				modifiersOne = modifierInput(modifiersOne);
			}
			else if (graphCat == simpleInvTrig) {
				oneInvChoice: cout << "Enter graph type: " << endl;
				cout << "1. x=sin(y)" << endl;
				cout << "2. x=cos(y)" << endl;
				cout << "3. x=tan(y)" << endl;
				cout << "4. x=cot(y)" << endl;
				cout << "5. x=sec(y)" << endl;
				cout << "6. x=cosec(y)" << endl;
				cin >> graphType;

				switch (graphType) {
					case 1:
						invCategory = invSin;
						break;

					case 2:
						invCategory = invCos;
						break;

					case 3:
						invCategory = invTan;
						break;

					case 4:
						invCategory = invCot;
						break;

					case 5:
						invCategory = invSec;
						break;

					case 6:
						invCategory = invCosec;
						break;

					default:
						goto oneInvChoice;
						break;
				}

				modifiersOne = modifierInput(modifiersOne);
			}
		}

		class binaryFile {
			public:
				void fileCheck();
				void writeToBinary(binaryClass);
				string * printGraphFromBin(binaryClass, coordinate, int);
				void printFromBinary(coordinate, int);
		};

		void binaryFile::fileCheck() {
			fstream binFile("graphs.dat", ios::out | ios::noreplace);

			if (!binFile) {
				remove("graphs.dat");

				fstream binFile("graphs.dat", ios::out | ios::trunc);
			}

			binFile.close();
		}

		void binaryFile::writeToBinary(binaryClass b) {
			fstream binFile("graphs.dat", ios:: in | ios::out | ios::binary | ios::app);
			binFile.write((char * ) & b, sizeof(b));
			binFile.close();
		}

		string * binaryFile::printGraphFromBin(binaryClass b, coordinate c1, int color) {
			if (b.graphCat == simpleTrig) {
				if (b.categoryOne == sinx) {
					for (double i = -320; i < 320; i += 0.01) {
						c1.x = 320 + (b.modifiersOne.coeffX * i);
						c1.y = 250 - (b.modifiersOne.coeffY * sin(b.modifiersOne.arg * i * pi / 100) * 15);
						putpixel(c1.x, c1.y, color);
					}

					gcvt(b.modifiersOne.arg, 4, b.hist.arg);
					gcvt(b.modifiersOne.coeffX, 4, b.hist.coeffX);
					gcvt(b.modifiersOne.coeffY, 4, b.hist.coeffY);

					cout << b.modifiersOne.coeffY << "y=" << b.modifiersOne.coeffX << "sin(" << b.modifiersOne.arg << "x)";
					strcat(b.hist.overall, b.hist.coeffY);
					strcat(b.hist.overall, "y=");
					strcat(b.hist.overall, b.hist.coeffX);
					strcat(b.hist.overall, "sin(");
					strcat(b.hist.overall, b.hist.arg);
					strcat(b.hist.overall, "x)\n");


				} else if (b.categoryOne == cosx) {
					for (double i = -320; i < 320; i += 0.01) {
						c1.x = 320 + (b.modifiersOne.coeffX * i);
						c1.y = 250 - (b.modifiersOne.coeffY * cos(b.modifiersOne.arg * i * pi / 100) * 15);
						putpixel(c1.x, c1.y, color);
					}

					gcvt(b.modifiersOne.arg, 4, b.hist.arg);
					gcvt(b.modifiersOne.coeffX, 4, b.hist.coeffX);
					gcvt(b.modifiersOne.coeffY, 4, b.hist.coeffY);

					cout << b.modifiersOne.coeffY << "y=" << b.modifiersOne.coeffX << "cos(" << b.modifiersOne.arg << "x)";
					strcat(b.hist.overall, b.hist.coeffY);
					strcat(b.hist.overall, "y=");
					strcat(b.hist.overall, b.hist.coeffX);
					strcat(b.hist.overall, "cos(");
					strcat(b.hist.overall, b.hist.arg);
					strcat(b.hist.overall, "x)\n");

				} else if (b.categoryOne == tanx) {
					for (double i = -320; i < 320; i += 0.01) {
						c1.x = 320 + (b.modifiersOne.coeffX * i);
						c1.y = 250 - (b.modifiersOne.coeffY * tan(b.modifiersOne.arg * i * pi / 100) * 15);
						putpixel(c1.x, c1.y, color);
					}

					gcvt(b.modifiersOne.arg, 4, b.hist.arg);
					gcvt(b.modifiersOne.coeffX, 4, b.hist.coeffX);
					gcvt(b.modifiersOne.coeffY, 4, b.hist.coeffY);

					cout << b.modifiersOne.coeffY << "y=" << b.modifiersOne.coeffX << "tan(" << b.modifiersOne.arg << "x)";
					strcat(b.hist.overall, b.hist.coeffY);
					strcat(b.hist.overall, "y=");
					strcat(b.hist.overall, b.hist.coeffX);
					strcat(b.hist.overall, "tan(");
					strcat(b.hist.overall, b.hist.arg);
					strcat(b.hist.overall, "x)\n");
				} else if (b.categoryOne == cotx) {
					for (double i = -320; i < 320; i += 0.01) {
						c1.x = 320 + (b.modifiersOne.coeffX * i);
						c1.y = 250 - (b.modifiersOne.coeffY * (1 / tan(b.modifiersOne.arg * i * pi / 100) * 15));
						putpixel(c1.x, c1.y, color);
					}

					gcvt(b.modifiersOne.arg, 4, b.hist.arg);
					gcvt(b.modifiersOne.coeffX, 4, b.hist.coeffX);
					gcvt(b.modifiersOne.coeffY, 4, b.hist.coeffY);

					cout << b.modifiersOne.coeffY << "y=" << b.modifiersOne.coeffX << "cot(" << b.modifiersOne.arg << "x)";
					strcat(b.hist.overall, b.hist.coeffY);
					strcat(b.hist.overall, "y=");
					strcat(b.hist.overall, b.hist.coeffX);
					strcat(b.hist.overall, "cot(");
					strcat(b.hist.overall, b.hist.arg);
					strcat(b.hist.overall, "x)\n");
				} else if (b.categoryOne == secx) {
					for (double i = -320; i < 320; i += 0.01) {
						c1.x = 320 + (b.modifiersOne.coeffX * i);
						c1.y = 250 - (b.modifiersOne.coeffY * (1 / cos(b.modifiersOne.arg * i * pi / 100) * 15));
						putpixel(c1.x, c1.y, color);
					}

					gcvt(b.modifiersOne.arg, 4, b.hist.arg);
					gcvt(b.modifiersOne.coeffX, 4, b.hist.coeffX);
					gcvt(b.modifiersOne.coeffY, 4, b.hist.coeffY);

					cout << b.modifiersOne.coeffY << "y=" << b.modifiersOne.coeffX << "sec(" << b.modifiersOne.arg << "x)";
					strcat(b.hist.overall, b.hist.coeffY);
					strcat(b.hist.overall, "y=");
					strcat(b.hist.overall, b.hist.coeffX);
					strcat(b.hist.overall, "sec(");
					strcat(b.hist.overall, b.hist.arg);
					strcat(b.hist.overall, "x)\n");
				} else if (b.categoryOne == cosecx) {
					for (double i = -320; i < 320; i += 0.01) {
						c1.x = 320 + (b.modifiersOne.coeffX * i);
						c1.y = 250 - (b.modifiersOne.coeffY * (1 / sin(b.modifiersOne.arg * i * pi / 100) * 15));
						putpixel(c1.x, c1.y, color);
					}

					gcvt(b.modifiersOne.arg, 4, b.hist.arg);
					gcvt(b.modifiersOne.coeffX, 4, b.hist.coeffX);
					gcvt(b.modifiersOne.coeffY, 4, b.hist.coeffY);

					cout << b.modifiersOne.coeffY << "y=" << b.modifiersOne.coeffX << "cosec(" << b.modifiersOne.arg << "x)";
					strcat(b.hist.overall, b.hist.coeffY);
					strcat(b.hist.overall, "y=");
					strcat(b.hist.overall, b.hist.coeffX);
					strcat(b.hist.overall, "cosec(");
					strcat(b.hist.overall, b.hist.arg);
					strcat(b.hist.overall, "x)\n");
				}
			} else if (b.graphCat == simpleInvTrig) {
				if (b.categoryOne == invSin) {
					for (double i = -320; i < 320; i += 0.01) {
						c1.y = 250 + (b.modifiersOne.coeffX * i);
						c1.x = 320 - (b.modifiersOne.coeffY * sin(b.modifiersOne.arg * i * pi / 100) * 15);
						putpixel(c1.x, c1.y, color);
					}
					gcvt(b.modifiersOne.arg, 4, b.hist.arg);
					gcvt(b.modifiersOne.coeffX, 4, b.hist.coeffX);
					gcvt(b.modifiersOne.coeffY, 4, b.hist.coeffY);

					cout << b.modifiersOne.coeffX << "x=" << b.modifiersOne.coeffY << "sin(" << b.modifiersOne.arg << "y)";

					strcat(b.hist.overall, b.hist.coeffX);
					strcat(b.hist.overall, "x=");
					strcat(b.hist.overall, b.hist.coeffY);
					strcat(b.hist.overall, "sin(");
					strcat(b.hist.overall, b.hist.arg);
					strcat(b.hist.overall, "y)\n");

				} else if (b.categoryOne == invCos) {
					for (double i = -320; i < 320; i += 0.01) {
						c1.y = 250 + (b.modifiersOne.coeffX * i);
						c1.x = 320 - (b.modifiersOne.coeffY * cos(b.modifiersOne.arg * i * pi / 100) * 15);
						putpixel(c1.x, c1.y, color);
					}
					gcvt(b.modifiersOne.arg, 4, b.hist.arg);
					gcvt(b.modifiersOne.coeffX, 4, b.hist.coeffX);
					gcvt(b.modifiersOne.coeffY, 4, b.hist.coeffY);

					cout << b.modifiersOne.coeffX << "x=" << b.modifiersOne.coeffY << "cos(" << b.modifiersOne.arg << "y)";

					strcat(b.hist.overall, b.hist.coeffX);
					strcat(b.hist.overall, "x=");
					strcat(b.hist.overall, b.hist.coeffY);
					strcat(b.hist.overall, "cos(");
					strcat(b.hist.overall, b.hist.arg);
					strcat(b.hist.overall, "y)\n");
				} else if (b.categoryOne == invTan) {
					for (double i = -320; i < 320; i += 0.01) {
						c1.y = 250 + (b.modifiersOne.coeffX * i);
						c1.x = 320 - (b.modifiersOne.coeffY * tan(b.modifiersOne.arg * i * pi / 100) * 15);
						putpixel(c1.x, c1.y, color);
					}
					gcvt(b.modifiersOne.arg, 4, b.hist.arg);
					gcvt(b.modifiersOne.coeffX, 4, b.hist.coeffX);
					gcvt(b.modifiersOne.coeffY, 4, b.hist.coeffY);

					cout << b.modifiersOne.coeffX << "x=" << b.modifiersOne.coeffY << "tan(" << b.modifiersOne.arg << "y)";

					strcat(b.hist.overall, b.hist.coeffX);
					strcat(b.hist.overall, "x=");
					strcat(b.hist.overall, b.hist.coeffY);
					strcat(b.hist.overall, "tan(");
					strcat(b.hist.overall, b.hist.arg);
					strcat(b.hist.overall, "y)\n");
				} else if (b.categoryOne == invCot) {
					for (double i = -320; i < 320; i += 0.01) {
						c1.y = 250 + (b.modifiersOne.coeffX * i);
						c1.x = 320 - (b.modifiersOne.coeffY * (1 / tan(b.modifiersOne.arg * i * pi / 100) * 15));
						putpixel(c1.x, c1.y, color);
					}
					gcvt(b.modifiersOne.arg, 4, b.hist.arg);
					gcvt(b.modifiersOne.coeffX, 4, b.hist.coeffX);
					gcvt(b.modifiersOne.coeffY, 4, b.hist.coeffY);

					cout << b.modifiersOne.coeffX << "x=" << b.modifiersOne.coeffY << "cot(" << b.modifiersOne.arg << "y)";

					strcat(b.hist.overall, b.hist.coeffX);
					strcat(b.hist.overall, "x=");
					strcat(b.hist.overall, b.hist.coeffY);
					strcat(b.hist.overall, "cot(");
					strcat(b.hist.overall, b.hist.arg);
					strcat(b.hist.overall, "y)\n");
				} else if (b.categoryOne == invSec) {
					for (double i = -320; i < 320; i += 0.01) {
						c1.y = 250 + (b.modifiersOne.coeffX * i);
						c1.x = 320 - (b.modifiersOne.coeffY * (1 / cos(b.modifiersOne.arg * i * pi / 100) * 15));
						putpixel(c1.x, c1.y, color);
					}
					gcvt(b.modifiersOne.arg, 4, b.hist.arg);
					gcvt(b.modifiersOne.coeffX, 4, b.hist.coeffX);
					gcvt(b.modifiersOne.coeffY, 4, b.hist.coeffY);

					cout << b.modifiersOne.coeffX << "x=" << b.modifiersOne.coeffY << "sec(" << b.modifiersOne.arg << "y)";

					strcat(b.hist.overall, b.hist.coeffX);
					strcat(b.hist.overall, "x=");
					strcat(b.hist.overall, b.hist.coeffY);
					strcat(b.hist.overall, "sec(");
					strcat(b.hist.overall, b.hist.arg);
					strcat(b.hist.overall, "y)\n");
				} else if (b.categoryOne == invCosec) {
					for (double i = -320; i < 320; i += 0.01) {
						c1.y = 250 + (b.modifiersOne.coeffX * i);
						c1.x = 320 - (b.modifiersOne.coeffY * (1 / sin(b.modifiersOne.arg * i * pi / 100) * 15));
						putpixel(c1.x, c1.y, color);
					}
					gcvt(b.modifiersOne.arg, 4, b.hist.arg);
					gcvt(b.modifiersOne.coeffX, 4, b.hist.coeffX);
					gcvt(b.modifiersOne.coeffY, 4, b.hist.coeffY);

					cout << b.modifiersOne.coeffX << "x=" << b.modifiersOne.coeffY << "cosec(" << b.modifiersOne.arg << "y)";

					strcat(b.hist.overall, b.hist.coeffX);
					strcat(b.hist.overall, "x=");
					strcat(b.hist.overall, b.hist.coeffY);
					strcat(b.hist.overall, "cosec(");
					strcat(b.hist.overall, b.hist.arg);
					strcat(b.hist.overall, "y)\n");
				}

			}

			return b.hist.overall;
		}

		void binaryFile::printFromBinary(coordinate c1, int color) {
			fstream binFile("graphs.dat", ios:: in | ios::out | ios::binary);
			binaryClass b;
			history histBin;
			historyTextFile textFile;
	
			while (binFile.read((char * ) & b, sizeof(b))) {
				c1.x = c1.y = 0;
				color = 1 + random(14);
				setcolor(color);
		
				strcpy(histBin.overall, printGraphFromBin(b, c1, color));
				textFile.writeToFile(histBin);
		
				cout << endl;
				getch();
			}
		
			binFile.close();
		}

		# endif

# endif