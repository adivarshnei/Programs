#include<iostream.h>
#include<process.h>

/*********************************************************************/

enum flag {
   YES = 1,
   NO
}; //enum flag

/*********************************************************************/

class circQueue {
private:
   int queue[100];
   int front;
   int rear;

public:
   circQueue();
   void insertElement(int);
   int deleteElement(flag&);
   void displayData();

}; //class circQueue

/*********************************************************************/

circQueue::circQueue() {
   front = 0;
   rear = 0;
} //circQueue::circQueue()

/*********************************************************************/

void circQueue::insertElement(int insertNo) {
   if ((rear + 1) % 100 == front) {
      cout << endl << "Circular Queue is full" << endl;
   } else {
      rear = (rear + 1) % 100;
      queue[rear] = insertNo;
   } //End of extended if clause
} //void circQueue::insertElement(int insertNo)

/*********************************************************************/

int circQueue::deleteElement(flag& f) {
   int deleteNo;

   if (front == rear) {
      cout << endl << "Circular queue is empty" << endl;

      f = NO;

      return 0;
   } else {
      front = (front + 1) % 100;
      deleteNo = queue[front];

      return deleteNo;
   } //End of extended if clause

   cout << endl;
} //int circQueue::deleteElement(flag & f)

/*********************************************************************/

void circQueue::displayData() {
   if (front == rear) {
      cout << endl << "Circular queue is empty" << endl;
   } else {
      cout << "Queue is: ";

      int i = front;

      do {
         i = (i + 1) % 100;
         cout << queue[i] << "\t";
      } while (i != rear);

   } //End of extended if clause

   cout << endl;
} //void circQueue::displayData()

/*********************************************************************/

unsigned long int count = 0;

/*********************************************************************/

int main(void) {
   unsigned int rep = 1;

   while (rep == 1) {
      system("cls");

      int choice, queueInpOut;
      circQueue queue;
      flag f = YES;

      do {
         switchChoice: cout << endl << "Circular Queue" << endl;
         cout << "1. Insertion" << endl;
         cout << "2. Deletion" << endl;
         cout << "3. Display Queue" << endl;
         cout << "4. Quit" << endl;
         cout << "Enter choice: ";
         cin >> choice;

         switch (choice) {
         case 1:
            cout << "Enter the number to be inserted: ";
            cin >> queueInpOut;

            queue.insertElement(queueInpOut);
            break;

         case 2:
            queueInpOut = queue.deleteElement(f);

            if (f == YES) {
               cout << "The deleted element is: " << queueInpOut;
            } else if (f == NO) {
               cout << "";
            } //End of extended if clause

            break;

         case 3:
            queue.displayData();
            system("pause");

            break;

         case 4:
            goto exitLoop;
            break;

         default:
            goto switchChoice;
            break;

         } //switch (choice)

      } while (choice != 0);


      exitLoop:
      cout << "Repeat Program?" << endl;
      cin >> rep;
      count++;

      if (count >= 50) {
         system("cls");

         cout << "Abnormal END" << endl;

         system("pause");
         exit(0);
      } //if (count >= 50)

   } //while (rep == 1)

   cout << "Normal END" << endl;

   system("pause");
   return 0;
} //int main(void)