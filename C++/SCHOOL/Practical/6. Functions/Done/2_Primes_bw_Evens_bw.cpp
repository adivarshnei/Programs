#include<iostream.h>
#include<conio.h>
#include<process.h>

typedef long int pr;
typedef long int ev;

int no_of_primes(pr a, pr b){
	int number=0, flag;

	for(int i=a+1; i<b; i++){
		flag=0;

		for(int j=2; j<i; j++){

			if(i%j==0){
				flag=1;
				break;
			}

		}

		if(flag==1){
			flag=0;
		}

		else{
			cout<<i<<' ';
			number++;
		}

	}

	return number;

}

int no_of_evens(ev a, ev b){
	int number=0;

	for(int i=a+1; i<b; i++){

		if(i%2==0){
			cout<<i<<' ';
			number++;
		}

	}

	return number;
}

long count=0;

int main(void){
	int rep=1;

	while(rep==1){
		clrscr();

		int choice, no;
		pr p1, p2;
		ev e1, e2;

		option:
		cout<<"1. Find number of primes between two entered values"<<endl;
		cout<<"2. Find number of even numbers between two entered values"<<endl;
		cin>>choice;

		switch(choice){

			case 1:
				cout<<"Enter the two numbers"<<endl;
				cin>>p1>>p2;

				cout<<"List of primes: ";
				no=no_of_primes(p1, p2);
				cout<<endl<<"Number of primes between "<<p1<<" and "<<p2<<" is: "<<no<<endl;

				break;

			case 2:
				cout<<"Enter the two numbers"<<endl;
				cin>>e1>>e2;

				cout<<"List of even numbers: ";
				no=no_of_evens(e1, e2);
				cout<<endl<<"Number of even numbers between "<<e1<<" and "<<e2<<" is: "<<no<<endl;

				break;

			default:
				cout<<"Wrong Choice"<<endl;
				goto option;

		}

		cout<<"Repeat Program?"<<endl;
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