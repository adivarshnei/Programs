#include<iostream.h>

#include<conio.h>

#include<process.h>

#include<dos.h>

#include<stdlib.h>

#include<string.h>

#include<stdio.h>

int count = 0, d;


/*
Define a class Library with data members -bookno(int),bookname(20 characters),author(20 characters),
price(float),no._of_copies(int), no._of copies_issued(int). 
Include the member functions: to accept initial values,
issue a book after checking its availability, to return a book and 
to display book information after taking book no from user . 
Write a menu driven interface to apply the above given operations on 5 books.
*/

//************************************************

class library {
    private:
        int book_no;
        char book_name[20];
        char author[20];
        float price;
        int no_of_copies;
        int no_of_copies_issued;

    public:
        void enter_data();
        void book_issue();
        void book_return();
        int stock_check();
        void no_check(int);
        void show_data();
        int name_check(char[]);
};

//***************************************************
void library::enter_data() {
    cout << "enter the book number:\n";
    cin >> book_no;
    cout << "enter the book name:\n";
    gets(book_name);
    cout << "enter the author name:\n";
    gets(author);
    cout << "enter the price:\n";
    cin >> price;
    cout << "enter the number of copies available:\n";
    cin >> no_of_copies;
}

//***********************************************************

int library::stock_check() {
    if (no_of_copies > 0) {
        return 1;
    } else {
        return 0;
    }
}

//*************************************************************

void library::book_issue() {
    int x = stock_check();
    if (x == 0) {
        cout << "sorry book not available\n";
    }
    if (x == 1) {
        cout << "book is available.you can take one\n";
        no_of_copies--;
    }
}

//****************************************************************

void library::book_return() {
    cout << "thank you for returning\n";
    no_of_copies++;
}

//*******************************************************************

void library::no_check(int n) {
    if (n == book_no)
        show_data();
}

//********************************************************************

void library::show_data() {
    cout << "book number:  " << book_no << endl;
    cout << "book name:  " << book_name << endl;
    cout << "author name:  " << author << endl;
    cout << "price:  Rs " << price << endl;
    cout << "number of books available:  " << no_of_copies << endl;
}

//********************************************************************

int library::name_check(char n[20]) {
    if (strcmp(n, book_name) == 0) {
        return 1;
    } else {
        return 0;
    }

}

//********************************************************************
void main() {
    char rep = '1';

    while (rep == '1') {
        clrscr();
        int label;

        library l[5];

        for (int i = 0; i < 5; i++) {
            l[i].enter_data();
        }

        do {
            cout << "1.return book\n";
            cout << "2.withdraw book\n";
            cout << "3.find book by book number\n";
            cout << "4.exit\n";
            int ch;
            cout << "enter your choice\n";
            cin >> ch;

            switch (ch) {

                case 1:
                    cout << "enter the book name:  ";
                    char b[20];
                    int x;
                    gets(b);
                    for (i = 0; i < 5; i++) {
                        x = l[i].name_check(b);

                        if (x == 1) {
                            l[i].book_return();
                        }
                        if (x == 0) {
                            cout << "sorry,no book found\n";
                        }
                    }

                    break;

                case 2:
                    cout << "enter the book name:  ";
                    gets(b);
                    for (i = 0; i < 5; i++) {
                        int x = l[i].name_check(b);

                        if (x == 1) {
                            l[i].book_issue();
                        }

                        if (x == 0) {
                            cout << "sorry no book found with this name\n";
                        }
                    }
                    break;


                case 3:
                    cout << "enter the book number:  ";
                    int y;
                    cin >> y;
                    for (i = 0; i < 5; i++) {
                        l[i].no_check(y);
                    }
                    break;

                case 4:
                    exit(0);

                default:
                    cout << "wrong choice entered enter again";

            }
        } while (1);

        cout << "\nRepeat Program?" << endl;
        cin >> rep;
        count++;

        if (count >= 50) {
            clrscr();
            cout << "GOING INTO THE INFINITY LOOP";
            for (d = 1; d < 150; d++) {
                cout << ".";
                delay(50);
            }
            cout << endl << "EXECUTION TERMINATED";
            getch();
            exit(0);
        }

    }

    cout << "NORMAL EXIT" << endl;
    getch();
}