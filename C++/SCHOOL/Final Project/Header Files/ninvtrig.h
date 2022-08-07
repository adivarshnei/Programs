# ifndef _i_trig_h_
	# define _i_trig_h_

	# ifndef _predef_h_
		# include "npredef.h"
	# endif

	# ifndef _inv_trig_graph_class_

		class invTrigGraphs {
			public:
				void invSinGraph(coordinate, mod, int);
				void invCosGraph(coordinate, mod, int);
				void invTanGraph(coordinate, mod, int);
				void invCotGraph(coordinate, mod, int);
				void invSecGraph(coordinate, mod, int);
				void invCosecGraph(coordinate, mod, int);
		};

		void invTrigGraphs::invSinGraph(coordinate c1, mod m1, int color) {
			for (double i = -320; i < 320; i += 0.01) {
				c1.y = 250 + (m1.coeffY * i);
				c1.x = 320 - (m1.coeffX * sin(m1.arg * i * pi / 100) * 15);
				putpixel(c1.x, c1.y, color);
			}
		}

		void invTrigGraphs::invCosGraph(coordinate c1, mod m1, int color) {
			for (double i = -320; i < 320; i += 0.01) {
				c1.y = 250 + (m1.coeffY * i);
				c1.x = 320 - (m1.coeffX * cos(m1.arg * i * pi / 100) * 15);
				putpixel(c1.x, c1.y, color);
			}
		}

		void invTrigGraphs::invTanGraph(coordinate c1, mod m1, int color) {
			for (double i = -320; i < 320; i += 0.01) {
				c1.y = 250 + (m1.coeffY * i);
				c1.x = 320 - (m1.coeffX * tan(m1.arg * i * pi / 100) * 15);
				putpixel(c1.x, c1.y, color);
			}
		}

		void invTrigGraphs::invCotGraph(coordinate c1, mod m1, int color) {
			for (double i = -320; i < 320; i += 0.01) {
				c1.y = 250 + (m1.coeffY * i);
				c1.x = 320 - (m1.coeffX * (1 / tan(m1.arg * i * pi / 100) * 15));
				putpixel(c1.x, c1.y, color);
			}
		}

		void invTrigGraphs::invSecGraph(coordinate c1, mod m1, int color) {
			for (double i = -320; i < 320; i += 0.01) {
				c1.y = 250 + (m1.coeffY * i);
				c1.x = 320 - (m1.coeffX * (1 / cos(m1.arg * i * pi / 100) * 15));
				putpixel(c1.x, c1.y, color);
			}
		}

		void invTrigGraphs::invCosecGraph(coordinate c1, mod m1, int color) {
			for (double i = -320; i < 320; i += 0.01) {
				c1.y = 250 + (m1.coeffY * i);
				c1.x = 320 - (m1.coeffX * (1 / sin(m1.arg * i * pi / 100) * 15));
				putpixel(c1.x, c1.y, color);
			}
		}

	# endif

# endif