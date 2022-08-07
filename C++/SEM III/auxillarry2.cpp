#include <iostream>

#define MAX_STRING 10

using namespace std;

typedef char String;

class Media {
protected:
   String title[MAX_STRING];
   String publication[MAX_STRING];

public:
   virtual void read() = 0;
   virtual void show() = 0;
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
   }

   void show() {
      cout << "Book Title: " << this->title << endl;
      cout << "Book Publication: " << this->publication << endl;
      cout << "Book Page Length: " << this->pages << endl;
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
   }

   void show() {
      cout << "Video Tape Title: " << this->title << endl;
      cout << "Video Tape Publication: " << this->publication << endl;
      cout << "Video Tape Play Time: " << this->playTime << endl;
   }
};

int main(void) {
   Media* B = new Books();
   Media* VT = new VideoTapes();

   B->read();
   B->show();

   VT->read();
   VT->show();
}
