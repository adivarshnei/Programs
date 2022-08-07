// Consider an example of book shop which sells books and video tapes. These two
// classes are inherited from base class called media. The media class has
// command data members such as title and publication. The book class has data
// members for storing number of pages in a book and tape class has playing time
// in a tape, Each class will have member functions such as read() and show().
// In the base class, these members have to be defined as virtual functions.
// Write a program to models the class hierarchy for book shop and processes
// objects of these classes using pointers to base class.

#include <iostream>
#include <stdlib.h>

#define MAX_STRING 10

using namespace std;

typedef char String;

class Media {
protected:
   String title[MAX_STRING];
   String publication[MAX_STRING];

public:
   virtual void read() = 0;
   virtual void isValid() = 0;
   virtual void show() const = 0;
};

class Books : public Media {
private:
   int pages;

public:
   void read() {
      cout << "Enter book title: ";
      cin.getline(this->title, MAX_STRING);
      cout << "Enter book publication: ";
      cin.getline(this->publication, MAX_STRING);
      cout << "Enter number of pages: ";
      cin >> this->pages;
      cin.ignore(256, '\n');

      this->isValid();
   }

   void isValid() {
      if (this->pages < 0) {
         cout << "Invalid Number of Pages. Enter Again: ";
         cin >> this->pages;
         cin.ignore(256, '\n');

         this->isValid();
      }
   }

   void show() const {
      cout << endl << "Book Title: " << this->title << endl;
      cout << "Book Publication: " << this->publication << endl;
      cout << "Book Page Length: " << this->pages << endl << endl;
   }
};

class VideoTapes : public Media {
private:
   int playTime;

public:
   void read() {
      cout << "Enter video tape title: ";
      cin.getline(this->title, MAX_STRING);
      cout << "Enter video tape publication: ";
      cin.getline(this->publication, MAX_STRING);
      cout << "Enter playtime: ";
      cin >> this->playTime;
      cin.ignore(256, '\n');

      this->isValid();
   }

   void isValid() {
      if (this->playTime < 0) {
         cout << "Invalid Play Time. Enter Again: ";
         cin >> this->playTime;
         cin.ignore(256, '\n');

         this->isValid();
      }
   }

   void show() const {
      cout << endl << "Video Tape Title: " << this->title << endl;
      cout << "Video Tape Publication: " << this->publication << endl;
      cout << "Video Tape Play Time: " << this->playTime << endl << endl;
   }
};

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      int choice;
      Media* media;

      do {
         cout << "1. Enter/Show Book Data" << endl;
         cout << "2. Enter/Show Video Tape Data" << endl;
         cout << "3. Exit" << endl;
         cout << "Enter Choice: ";
         cin >> choice;
         cin.ignore(256, '\n');

         switch (choice) {
         case 1:
            media = new Books();
            media->read();
            media->show();
            break;

         case 2:
            media = new VideoTapes();
            media->read();
            media->show();

         case 3:
            break;

         case 4:
            break;

         default:
            cout << endl << "Wrong Choice" << endl;
            break;
         }
      } while (choice != 3);

      cout << endl << "Repeat Program? (1 = YES): ";
      cin >> shouldRepeat;
      cin.ignore(256, '\n');

      if (shouldRepeat == 1) {
         continue;
      } else {
         cout << endl << "END" << endl;
         break;
      }
   }

   system("pause");
   return 0;
}
