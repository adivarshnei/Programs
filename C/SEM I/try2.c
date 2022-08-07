#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void delay( int sec ) {
	clock_t stTime = clock();

	while (clock() < stTime + sec) { }
}

int main( void ) {
	int i = 0, j = 0, k = 0;

	// const char* a[4] = {
	// 	"   \n---\n   ",
	// 	"\\  \n \\ \n  \\",
	// 	" | \n | \n | ",
	// 	"  /\n / \n/  "
	// };

	const char a[4] = {
		 '\\',
		 '|',
		 '/',
		 '-'
	};

	while (!kbhit()) {
		system( "cls" );
		fprintf( stdout, "%s", a[i % 4] );
		delay( 30 );
		i++;
	}

}