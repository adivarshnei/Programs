#include<iostream.h>
#include<conio.h>
#include<process.h>

long count=0;

/*
Write a program to input book number, cost of the book, quantity. Calculate amount as cost * quantity. Store them in separate arrays. Search for a particular book number inputted by the user and display the information for that book, if book is found. If the book is not found, display the message “book not present”
*/

int main(void){
	int rep=1;

	while(rep==1){
		clrscr();

		cout<<"Assignment 4"<<endl<<"Practical 5"<<endl<<endl;

		int choice;
		int bookno=0, bn, no, n_f;
		long book_no[50], cost[50], amount[50], quantity[50];

		cout<<"Enter book number: ";
		cin>>book_no[bookno];

		cout<<"Enter cost of book: ";
		cin>>cost[bookno];

		cout<<"Enter quantity of book: ";
		cin>>quantity[bookno];

		amount[bookno]=cost[bookno]*quantity[bookno];
		bookno++;

		while(choice!=3){
			cout<<endl<<"1. Enter more books"<<endl;
			cout<<"2. Search for a book"<<endl;
			cout<<"3. Exit"<<endl;
			cin>>choice;

			switch(choice){

				case 1:
					cout<<endl<<"Enter book number: ";
					cin>>book_no[bookno];

					cout<<"Enter cost of book: ";
					cin>>cost[bookno];

					cout<<"Enter quantity of book: ";
					cin>>quantity[bookno];

					amount[bookno]=cost[bookno]*quantity[bookno];
					bookno++;

					break;

				case 2:
					cout<<endl<<"Enter book number: ";
					cin>>bn;

					for(int i=0; i<50; i++){

						if(bn==book_no[i]){
							no=i;
						}

						else{
							n_f=1;
						}

					}

					if(n_f==1){
						cout<<"Book not present"<<endl;

						break;
					}

					else{
						cout<<endl<<"Book Number: "<<book_no[no]<<endl;
						cout<<"Cost: "<<cost[no]<<endl;
						cout<<"Quantity: "<<quantity[no]<<endl;
						cout<<"Amount: "<<amount[no]<<endl;

						break;
					}

				default:

					if(choice!=3){
						continue;
					}

					else{
						break;
					}
			}

			count++;

			if(count>=50){
				clrscr();

				cout<<"Abnormal END"<<endl;

				getch();
				exit(0);
			}

		}

		cout<<endl<<"Repeat Program?"<<endl;
		cin>>rep;
		count++;

		if(count>=50){
			clrscr();

			cout<<"Abnormal END"<<endl;

			getch();
			exit(0);
		}

	}

	cout<<"Normal END"<<endl;

	getch();
	return 0;
}