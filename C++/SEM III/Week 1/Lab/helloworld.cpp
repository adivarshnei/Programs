#include <iostream.h>
#include <stdlib.h>

enum Bool {
   YES = 1,
   NO = 0
};

Bool shouldRepeat;

int main(void) {
   system("cls");

   float a = 9.0;

   cout << "Hello World" << endl;
   cout << "a = " << a << endl;

   cout << endl << "Repeat Program? (1 = YES): ";
   cin >> shouldRepeat;

   (shouldRepeat == YES) ? main() : cout << endl << "END";
} // int main( void )

// Function Definitions