# ifndef _combos_h_
	# define _combos_h

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

	# ifndef _combo_classes_
		# define _combo_classes_

		class constituents {
			public:
				double sinComboX(double, mod);
				double cosComboX(double, mod);
				double tanComboX(double, mod);
				double cotComboX(double, mod);
				double secComboX(double, mod);
				double cosecComboX(double, mod);
		};

		double constituents::sinComboX(double i, mod m1) {
			double sinC;
			sinC = m1.coeffX * sin(m1.arg * i * pi / 100);
			return sinC;
		}

		double constituents::cosComboX(double i, mod m1) {
			double cosC;
			cosC = m1.coeffX * cos(m1.arg * i * pi / 100);
			return cosC;
		}

		double constituents::tanComboX(double i, mod m1) {
			double tanC;
			tanC = m1.coeffX * tan(m1.arg * i * pi / 100);
			return tanC;
		}

		double constituents::cotComboX(double i, mod m1) {
			double cotC;
			cotC = m1.coeffX * (1 / tan(m1.arg * i * pi / 100));
			return cotC;
		}

		double constituents::secComboX(double i, mod m1) {
			double secantC;
			secantC = m1.coeffX * (1 / cos(m1.arg * i * pi / 100));
			return secantC;
		}

		double constituents::cosecComboX(double i, mod m1) {
			double cosecantC;
			cosecantC = m1.coeffX * (1 / sin(m1.arg * i * pi / 100));
			return cosecantC;
		}

		class choices {
			public:
				int baseChoice;
				int modChoice;
		};

		choices ch1;

		class comboGraphs: public constituents, public background {
			public: 
				string * addComboGraph(coordinate, int);
				string * mulComboGraph(coordinate, int);
				string * nestComboGraph(coordinate, int);
		};

		string * comboGraphs::addComboGraph(coordinate c1, int color) {
			history graphBase, graphAdd;
			string final[100];

			mod mBase, mAdd;

			cout << "Choose the base equation: " << endl;
			cout << "1. y=sin(x)" << endl;
			cout << "2. y=cos(x)" << endl;
			cout << "3. y=tan(x)" << endl;
			cout << "4. y=cot(x)" << endl;
			cout << "5. y=sec(x)" << endl;
			cout << "6. y=cosec(x)" << endl;
			cin >> ch1.baseChoice;

			cout << "Modification: " << endl;
			cout << "Enter the argument multiple: ";
			cin >> mBase.arg;
			cout << "Enter the coefficient of x: ";
			cin >> mBase.coeffX;
			cout << "Enter the coefficient of y: ";
			cin >> mBase.coeffY;

			gcvt(mBase.arg, 4, graphBase.arg);
			gcvt(mBase.coeffX, 4, graphBase.coeffX);
			gcvt(mBase.coeffY, 4, graphBase.coeffY);

			cout << "Choose what to add: " << endl;
			cout << "1. sin(x)" << endl;
			cout << "2. cos(x)" << endl;
			cout << "3. tan(x)" << endl;
			cout << "4. cot(x)" << endl;
			cout << "5. sec(x)" << endl;
			cout << "6. cosec(x)" << endl;
			cin >> ch1.modChoice;

			cout << "Modification: " << endl;
			cout << "Enter the argument multiple: ";
			cin >> mAdd.arg;
			cout << "Enter the coefficient of x: ";
			cin >> mAdd.coeffX;

			gcvt(mAdd.arg, 4, graphAdd.arg);
			gcvt(mAdd.coeffX, 4, graphAdd.coeffX);
			gcvt(mAdd.coeffY, 4, graphAdd.coeffY);

			clrscr();
			cleardevice();
			drawAxes(color);

			for (double i = -320; i <= 320; i += 0.01) {
				c1.x = 0;
				c1.y = 0;

				switch (ch1.baseChoice) {
					case 1:
						c1.x -= sinComboX(i, mBase);
						c1.y += mBase.coeffY * i;
						break;

					case 2:
						c1.x -= cosComboX(i, mBase);
						c1.y += mBase.coeffY * i;
						break;

					case 3:
						c1.x -= tanComboX(i, mBase);
						c1.y += mBase.coeffY * i;
						break;

					case 4:
						c1.x -= cotComboX(i, mBase);
						c1.y += mBase.coeffY * i;
						break;

					case 5:
						c1.x -= secComboX(i, mBase);
						c1.y += mBase.coeffY * i;
						break;

					case 6:
						c1.x -= cosecComboX(i, mBase);
						c1.y += mBase.coeffY * i;
						break;

					default:
						break;
				}

				switch (ch1.modChoice) {
					case 1:
						c1.x -= sinComboX(i, mAdd);
						break;

					case 2:
						c1.x -= cosComboX(i, mAdd);
						break;

					case 3:
						c1.x -= tanComboX(i, mAdd);
						break;

					case 4:
						c1.x -= cotComboX(i, mAdd);
						break;

					case 5:
						c1.x -= secComboX(i, mAdd);
						break;

					case 6:
						c1.x -= cosecComboX(i, mAdd);
						break;

					default:
						break;
				}

				putpixel(320 + c1.y, 250 + c1.x * 25, color);

			}

			switch (ch1.baseChoice) {
				case 1:
					cout << mBase.coeffY << "y=" << mBase.coeffX << "sin(" << mBase.arg << "x)+";

					strcat(final, graphBase.coeffY);
					strcat(final, "y=");
					strcat(final, graphBase.coeffX);
					strcat(final, "sin(");
					strcat(final, graphBase.arg);
					strcat(final, "x)+");
					break;

				case 2:
					cout << mBase.coeffY << "y=" << mBase.coeffX << "cos(" << mBase.arg << "x)+";

					strcat(final, graphBase.coeffY);
					strcat(final, "y=");
					strcat(final, graphBase.coeffX);
					strcat(final, "cos(");
					strcat(final, graphBase.arg);
					strcat(final, "x)+");
					break;

				case 3:
					cout << mBase.coeffY << "y=" << mBase.coeffX << "tan(" << mBase.arg << "x)+";

					strcat(final, graphBase.coeffY);
					strcat(final, "y=");
					strcat(final, graphBase.coeffX);
					strcat(final, "tan(");
					strcat(final, graphBase.arg);
					strcat(final, "x)+");
					break;

				case 4:
					cout << mBase.coeffY << "y=" << mBase.coeffX << "cot(" << mBase.arg << "x)+";

					strcat(final, graphBase.coeffY);
					strcat(final, "y=");
					strcat(final, graphBase.coeffX);
					strcat(final, "cot(");
					strcat(final, graphBase.arg);
					strcat(final, "x)+");
					break;

				case 5:
					cout << mBase.coeffY << "y=" << mBase.coeffX << "sec(" << mBase.arg << "x)+";

					strcat(final, graphBase.coeffY);
					strcat(final, "y=");
					strcat(final, graphBase.coeffX);
					strcat(final, "sec(");
					strcat(final, graphBase.arg);
					strcat(final, "x)+");
					break;

				case 6:
					cout << mBase.coeffY << "y=" << mBase.coeffX << "cosec(" << mBase.arg << "x)+";

					strcat(final, graphBase.coeffY);
					strcat(final, "y=");
					strcat(final, graphBase.coeffX);
					strcat(final, "cosec(");
					strcat(final, graphBase.arg);
					strcat(final, "x)+");
					break;

				default:
					break;

			}

			switch (ch1.modChoice) {
				case 1:
					cout << mAdd.coeffX << "sin(" << mAdd.arg << "x)" << endl;
					strcat(final, graphAdd.coeffX);
					strcat(final, "sin(");
					strcat(final, graphAdd.arg);
					strcat(final, "x)\n");
					break;

				case 2:
					cout << mAdd.coeffX << "cos(" << mAdd.arg << "x)" << endl;
					strcat(final, graphAdd.coeffX);
					strcat(final, "cos(");
					strcat(final, graphAdd.arg);
					strcat(final, "x)\n");
					break;

				case 3:
					cout << mAdd.coeffX << "tan(" << mAdd.arg << "x)" << endl;
					strcat(final, graphAdd.coeffX);
					strcat(final, "tan(");
					strcat(final, graphAdd.arg);
					strcat(final, "x)\n");
					break;

				case 4:
					cout << mAdd.coeffX << "cot(" << mAdd.arg << "x)" << endl;
					strcat(final, graphAdd.coeffX);
					strcat(final, "cot(");
					strcat(final, graphAdd.arg);
					strcat(final, "x)\n");
					break;

				case 5:
					cout << mAdd.coeffX << "sec(" << mAdd.arg << "x)" << endl;
					strcat(final, graphAdd.coeffX);
					strcat(final, "sec(");
					strcat(final, graphAdd.arg);
					strcat(final, "x)\n");
					break;

				case 6:
					cout << mAdd.coeffX << "cosec(" << mAdd.arg << "x)" << endl;
					strcat(final, graphAdd.coeffX);
					strcat(final, "cosec(");
					strcat(final, graphAdd.arg);
					strcat(final, "x)\n");
					break;

				default:
					break;
			}

			return final;
		}

		string * comboGraphs::mulComboGraph(coordinate c1, int color) {
			history graphBase, graphAdd;
			string final[100];

			mod mBase, mAdd;

			cout << "Choose the base equation: " << endl;
			cout << "1. y=sin(x)" << endl;
			cout << "2. y=cos(x)" << endl;
			cout << "3. y=tan(x)" << endl;
			cout << "4. y=cot(x)" << endl;
			cout << "5. y=sec(x)" << endl;
			cout << "6. y=cosec(x)" << endl;
			cin >> ch1.baseChoice;

			cout << "Modification: " << endl;
			cout << "Enter the argument multiple: ";
			cin >> mBase.arg;
			cout << "Enter the coefficient of x: ";
			cin >> mBase.coeffX;
			cout << "Enter the coefficient of y: ";
			cin >> mBase.coeffY;

			gcvt(mBase.arg, 4, graphBase.arg);
			gcvt(mBase.coeffX, 4, graphBase.coeffX);
			gcvt(mBase.coeffY, 4, graphBase.coeffY);

			cout << "Choose what to multiply: " << endl;
			cout << "1. sin(x)" << endl;
			cout << "2. cos(x)" << endl;
			cout << "3. tan(x)" << endl;
			cout << "4. cot(x)" << endl;
			cout << "5. sec(x)" << endl;
			cout << "6. cosec(x)" << endl;
			cin >> ch1.modChoice;

			cout << "Modification: " << endl;
			cout << "Enter the argument multiple: ";
			cin >> mAdd.arg;
			cout << "Enter the coefficient of x: ";
			cin >> mAdd.coeffX;

			gcvt(mAdd.arg, 4, graphAdd.arg);
			gcvt(mAdd.coeffX, 4, graphAdd.coeffX);
			gcvt(mAdd.coeffY, 4, graphAdd.coeffY);

			clrscr();
			cleardevice();
			drawAxes(color);

			for (double i = -320; i <= 320; i += 0.01) {
				c1.x = 1;
				c1.y = 0;

				switch (ch1.baseChoice) {
					case 1:
						c1.x *= sinComboX(i, mBase);
						c1.y += mBase.coeffY * i;
						break;

					case 2:
						c1.x *= cosComboX(i, mBase);
						c1.y += mBase.coeffY * i;
						break;

					case 3:
						c1.x *= tanComboX(i, mBase);
						c1.y += mBase.coeffY * i;
						break;

					case 4:
						c1.x *= cotComboX(i, mBase);
						c1.y += mBase.coeffY * i;
						break;

					case 5:
						c1.x *= secComboX(i, mBase);
						c1.y += mBase.coeffY * i;
						break;

					case 6:
						c1.x *= cosecComboX(i, mBase);
						c1.y += mBase.coeffY * i;
						break;

					default:
						break;
				}

				switch (ch1.modChoice) {
					case 1:
						c1.x *= sinComboX(i, mAdd);
						break;

					case 2:
						c1.x *= cosComboX(i, mAdd);
						break;

					case 3:
						c1.x *= tanComboX(i, mAdd);
						break;

					case 4:
						c1.x *= cotComboX(i, mAdd);
						break;

					case 5:
						c1.x *= secComboX(i, mAdd);
						break;

					case 6:
						c1.x *= cosecComboX(i, mAdd);
						break;

					default:
						break;
				}

				putpixel(320 + c1.y, 250 + c1.x * 25, color);

			}

			switch (ch1.baseChoice) {
				case 1:
					cout << mBase.coeffY << "y=" << mBase.coeffX << "sin(" << mBase.arg << "x)*";

					strcat(final, graphBase.coeffY);
					strcat(final, "y=");
					strcat(final, graphBase.coeffX);
					strcat(final, "sin(");
					strcat(final, graphBase.arg);
					strcat(final, "x)*");
					break;

				case 2:
					cout << mBase.coeffY << "y=" << mBase.coeffX << "cos(" << mBase.arg << "x)*";

					strcat(final, graphBase.coeffY);
					strcat(final, "y=");
					strcat(final, graphBase.coeffX);
					strcat(final, "cos(");
					strcat(final, graphBase.arg);
					strcat(final, "x)*");
					break;

				case 3:
					cout << mBase.coeffY << "y=" << mBase.coeffX << "tan(" << mBase.arg << "x)*";

					strcat(final, graphBase.coeffY);
					strcat(final, "y=");
					strcat(final, graphBase.coeffX);
					strcat(final, "tan(");
					strcat(final, graphBase.arg);
					strcat(final, "x)*");
					break;

				case 4:
					cout << mBase.coeffY << "y=" << mBase.coeffX << "cot(" << mBase.arg << "x)*";

					strcat(final, graphBase.coeffY);
					strcat(final, "y=");
					strcat(final, graphBase.coeffX);
					strcat(final, "cot(");
					strcat(final, graphBase.arg);
					strcat(final, "x)*");
					break;

				case 5:
					cout << mBase.coeffY << "y=" << mBase.coeffX << "sec(" << mBase.arg << "x)*";

					strcat(final, graphBase.coeffY);
					strcat(final, "y=");
					strcat(final, graphBase.coeffX);
					strcat(final, "sec(");
					strcat(final, graphBase.arg);
					strcat(final, "x)*");
					break;

				case 6:
					cout << mBase.coeffY << "y=" << mBase.coeffX << "cosec(" << mBase.arg << "x)*";

					strcat(final, graphBase.coeffY);
					strcat(final, "y=");
					strcat(final, graphBase.coeffX);
					strcat(final, "cosec(");
					strcat(final, graphBase.arg);
					strcat(final, "x)*");
					break;

				default:
					break;

			}

			switch (ch1.modChoice) {
				case 1:
					cout << mAdd.coeffX << "sin(" << mAdd.arg << "x)" << endl;
					strcat(final, graphAdd.coeffX);
					strcat(final, "sin(");
					strcat(final, graphAdd.arg);
					strcat(final, "x)\n");
					break;

				case 2:
					cout << mAdd.coeffX << "cos(" << mAdd.arg << "x)" << endl;
					strcat(final, graphAdd.coeffX);
					strcat(final, "cos(");
					strcat(final, graphAdd.arg);
					strcat(final, "x)\n");
					break;

				case 3:
					cout << mAdd.coeffX << "tan(" << mAdd.arg << "x)" << endl;
					strcat(final, graphAdd.coeffX);
					strcat(final, "tan(");
					strcat(final, graphAdd.arg);
					strcat(final, "x)\n");
					break;

				case 4:
					cout << mAdd.coeffX << "cot(" << mAdd.arg << "x)" << endl;
					strcat(final, graphAdd.coeffX);
					strcat(final, "cot(");
					strcat(final, graphAdd.arg);
					strcat(final, "x)\n");
					break;

				case 5:
					cout << mAdd.coeffX << "sec(" << mAdd.arg << "x)" << endl;
					strcat(final, graphAdd.coeffX);
					strcat(final, "sec(");
					strcat(final, graphAdd.arg);
					strcat(final, "x)\n");
					break;

				case 6:
					cout << mAdd.coeffX << "cosec(" << mAdd.arg << "x)" << endl;
					strcat(final, graphAdd.coeffX);
					strcat(final, "cosec(");
					strcat(final, graphAdd.arg);
					strcat(final, "x)\n");
					break;

				default:
					break;
			}

			return final;
		}

		string * comboGraphs::nestComboGraph(coordinate c1, int color) {
			history graphBase, graphAdd;
			string final[100];

			strcpy(final, "");

			mod mBase, mAdd;

			cout << "Choose the base equation: " << endl;
			cout << "1. y=sin(x)" << endl;
			cout << "2. y=cos(x)" << endl;
			cout << "3. y=tan(x)" << endl;
			cout << "4. y=cot(x)" << endl;
			cout << "5. y=sec(x)" << endl;
			cout << "6. y=cosec(x)" << endl;
			cin >> ch1.baseChoice;

			cout << "Modification: " << endl;
			cout << "Enter the argument multiple: ";
			cin >> mBase.arg;
			cout << "Enter the coefficient of x: ";
			cin >> mBase.coeffX;
			cout << "Enter the coefficient of y: ";
			cin >> mBase.coeffY;

			gcvt(mBase.arg, 4, graphBase.arg);
			gcvt(mBase.coeffX, 4, graphBase.coeffX);
			gcvt(mBase.coeffY, 4, graphBase.coeffY);

			cout << "Choose what to nest: " << endl;
			cout << "1. sin(x)" << endl;
			cout << "2. cos(x)" << endl;
			cout << "3. tan(x)" << endl;
			cout << "4. cot(x)" << endl;
			cout << "5. sec(x)" << endl;
			cout << "6. cosec(x)" << endl;
			cin >> ch1.modChoice;

			clrscr();
			cleardevice();
			drawAxes(color);

			for (double i = -320; i <= 320; i += 0.01) {
				c1.x = 0;
				c1.y = 0;

				switch (ch1.baseChoice) {
					case 1:
						c1.x = sinComboX(i, mBase);
						c1.y += mBase.coeffY * i;
						break;

					case 2:
						c1.x = cosComboX(i, mBase);
						c1.y += mBase.coeffY * i;
						break;

					case 3:
						c1.x = tanComboX(i, mBase);
						c1.y += mBase.coeffY * i;
						break;

					case 4:
						c1.x = cotComboX(i, mBase);
						c1.y += mBase.coeffY * i;
						break;

					case 5:
						c1.x = secComboX(i, mBase);
						c1.y += mBase.coeffY * i;
						break;

					case 6:
						c1.x = cosecComboX(i, mBase);
						c1.y += mBase.coeffY * i;
						break;

					default:
						break;
				}

				switch (ch1.modChoice) {
					case 1:
						c1.x = sin(c1.x);
						break;

					case 2:
						c1.x = cos(c1.x);
						break;

					case 3:
						c1.x = tan(c1.x);
						break;

					case 4:
						c1.x = (1 / tan(c1.x));
						break;

					case 5:
						c1.x = (1 / cos(c1.x));
						break;

					case 6:
						c1.x = (1 / sin(c1.x));
						break;

					default:
						break;
				}

				putpixel(320 + c1.y, 250 + c1.x * 25, color);

			}

			switch (ch1.modChoice) {
				case 1:
					cout << mBase.coeffY << "y=sin(" << mBase.coeffX;

					strcat(final, graphBase.coeffY);
					strcat(final, "y=sin(");
					strcat(final, graphBase.coeffX);
					break;

				case 2:
					cout << mBase.coeffY << "y=" << "cos(" << mBase.coeffX;

					strcat(final, graphBase.coeffY);
					strcat(final, "y=cos(");
					strcat(final, graphBase.coeffX);
					break;

				case 3:
					cout << mBase.coeffY << "y=" << "tan(" << mBase.coeffX;

					strcat(final, graphBase.coeffY);
					strcat(final, "y=tan(");
					strcat(final, graphBase.coeffX);
					break;

				case 4:
					cout << mBase.coeffY << "y=" << "tan(" << mBase.coeffX;

					strcat(final, graphBase.coeffY);
					strcat(final, "y=cot(");
					strcat(final, graphBase.coeffX);
					break;

				case 5:
					cout << mBase.coeffY << "y=" << "cot(" << mBase.coeffX;

					strcat(final, graphBase.coeffY);
					strcat(final, "y=sec(");
					strcat(final, graphBase.coeffX);
					break;

				case 6:
					cout << mBase.coeffY << "y=" << "cosec(" << mBase.coeffX;

					strcat(final, graphBase.coeffY);
					strcat(final, "y=cosec(");
					strcat(final, graphBase.coeffX);
					break;

				default:
					break;
			}

			switch (ch1.baseChoice) {
				case 1:
					cout << "sin(" << mBase.arg << "x))" << endl;

					strcat(final, "sin(");
					strcat(final, graphBase.arg);
					strcat(final, "x))\n");
					break;

				case 2:
					cout << "cos(" << mBase.arg << "x))" << endl;

					strcat(final, "cos(");
					strcat(final, graphBase.arg);
					strcat(final, "x))\n");
					break;

				case 3:
					cout << "tan(" << mBase.arg << "x))" << endl;

					strcat(final, "tan(");
					strcat(final, graphBase.arg);
					strcat(final, "x))\n");
					break;

				case 4:
					cout << "cot(" << mBase.arg << "x))" << endl;

					strcat(final, "cot(");
					strcat(final, graphBase.arg);
					strcat(final, "x))\n");
					break;

				case 5:
					cout << "sec(" << mBase.arg << "x))" << endl;

					strcat(final, "sec(");
					strcat(final, graphBase.arg);
					strcat(final, "x))\n");
					break;

				case 6:
					cout << "cosec(" << mBase.arg << "x))" << endl;

					strcat(final, "cosec(");
					strcat(final, graphBase.arg);
					strcat(final, "x))\n");
					break;

				default:
					break;
			}

			getch();
			return final;
		}

	# endif

# endif