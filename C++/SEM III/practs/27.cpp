// Write a program to find the volume of a sphere, cone and cylinder using
// virtual functions

#include <iostream>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

using namespace std;

class Sphere {
protected:
   int r;
   float shapeArea;
   float shapeVolume;

public:
   Sphere(int r) : r(r) { }

   virtual void area() { shapeArea = 4 * PI * r * r; }

   virtual void volume() { shapeVolume = PI * r * r * r; }

   virtual void display() const {
      cout << "Sphere radius: " << r << endl;
      cout << "Sphere surface area: " << shapeArea << endl;
      cout << "Sphere volume: " << shapeVolume << endl;
   }
};

class Cylinder : public Sphere {
private:
   int h;

public:
   Cylinder(int r, int h) : h(h), Sphere(r) { }

   void area() { shapeArea = 2 * PI * r * (h + r); }

   void volume() { shapeVolume = PI * r * r * h; }

   void display() const {
      cout << "Cylinder radius: " << r << endl;
      cout << "Cylinder height: " << h << endl;
      cout << "Cylinder surface area: " << shapeArea << endl;
      cout << "Cylinder volume: " << shapeVolume << endl;
   }
};

class Cone : public Sphere {
private:
   int h;

public:
   Cone(int r, int h) : h(h), Sphere(r) { }

   void area() { shapeArea = PI * r * (r + sqrt(r * r + h * h)); }

   void volume() { shapeVolume = PI * r * r * h / 3.0; }

   void display() const {
      cout << "Cone radius: " << r << endl;
      cout << "Cone height: " << h << endl;
      cout << "Cone surface area: " << shapeArea << endl;
      cout << "Cone volume: " << shapeVolume << endl;
   }
};

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      Sphere* ptr;

      ptr = new Sphere(5);
      ptr->area();
      ptr->volume();
      ptr->display();

      ptr = new Cylinder(6, 7);
      ptr->area();
      ptr->volume();
      ptr->display();

      ptr = new Cone(8, 9);
      ptr->area();
      ptr->volume();
      ptr->display();

      delete ptr;

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
