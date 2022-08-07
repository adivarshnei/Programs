# ifndef _trig_h_
	# define _trig_h_

	# ifndef _predef_h_
		# include "npredef.h"
	# endif

	# ifndef _trig_graph_class_

		class trigGraphs {
			public:
				void sinGraph(coordinate, mod, int);
				void cosGraph(coordinate, mod, int);
				void tanGraph(coordinate, mod, int);
				void cotGraph(coordinate, mod, int);
				void secGraph(coordinate, mod, int);
				void cosecGraph(coordinate, mod, int);
		};

		void trigGraphs::sinGraph(coordinate c1, mod m1, int color) {
			for (double i = -320; i < 320; i += 0.01) {
				c1.x = 320 + (m1.coeffX * i);
				c1.y = 250 - (m1.coeffY * sin(m1.arg * i * pi / 100) * 15);
				putpixel(c1.x, c1.y, color);
			}
		}

		void trigGraphs::cosGraph(coordinate c1, mod m1, int color) {
			for (double i = -320; i < 320; i += 0.01) {
				c1.x = 320 + (m1.coeffX * i);
				c1.y = 250 - (m1.coeffY * cos(m1.arg * i * pi / 100) * 15);
				putpixel(c1.x, c1.y, color);
			}
		}

		void trigGraphs::tanGraph(coordinate c1, mod m1, int color) {
			for (double i = -320; i < 320; i += 0.01) {
				c1.x = 320 + (m1.coeffX * i);
				c1.y = 250 - (m1.coeffY * tan(m1.arg * i * pi / 100) * 15);
				putpixel(c1.x, c1.y, color);
			}
		}

		void trigGraphs::cotGraph(coordinate c1, mod m1, int color) {
			for (double i = -320; i < 320; i += 0.01) {
				c1.x = 320 + (m1.coeffX * i);
				c1.y = 250 - (m1.coeffY * (1 / tan(m1.arg * i * pi / 100) * 15));
				putpixel(c1.x, c1.y, color);
			}
		}

		void trigGraphs::secGraph(coordinate c1, mod m1, int color) {
			for (double i = -320; i < 320; i += 0.01) {
				c1.x = 320 + (m1.coeffX * i);
				c1.y = 250 - (m1.coeffY * (1 / cos(m1.arg * i * pi / 100) * 15));
				putpixel(c1.x, c1.y, color);
			}
		}

		void trigGraphs::cosecGraph(coordinate c1, mod m1, int color) {
			for (double i = -320; i < 320; i += 0.01) {
				c1.x = 320 + (m1.coeffX * i);
				c1.y = 250 - (m1.coeffY * (1 / sin(m1.arg * i * pi / 100) * 15));
				putpixel(c1.x, c1.y, color);
			}
		}

	# endif

# endif