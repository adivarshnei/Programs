#include<IOSTREAM.H>
#include<CONIO.H>
#include<process.h>

typedef long int fib;
typedef long int trib;

void fibonacci(fib &n1, fib &n2){
	fib n3;

	n3=n1+n2;

	n1=n2;
	n2=n3;
}

void tribonacci(trib &n1, trib &n2, trib &n3){
	trib n4;

	n4=n1+n2+n3;

	n1=n2;
	n2=n3;
	n3=n4;
}

long count=0;

int main(void){
	int rep=1;
	
	while(rep==1){
		clrscr();

		int choice, n;
		fib f1, f2;
		trib t1, t2, t3;

		option:		
		cout<<"1. Fibonacci Series"<<endl;
		cout<<"2. Tribonacci Series"<<endl;
		cin>>choice;

		switch(choice){
			
			case 1:
				cout<<"Enter the first two numbers"<<endl;
				cin>>f1>>f2;
				
				cout<<"Enter the number of elements in the series"<<endl;
				cin>>n;

				cout<<endl<<"The series is: "<<f1<<'\t'<<f2<<'\t';

				for(int i=0; i<n-2; i++){
					fibonacci(f1,f2);
					cout<<f2<<'\t';
				}

				break;

			case 2:
				cout<<"Enter the first three numbers"<<endl;
				cin>>t1>>t2>>t3;

				cout<<"Enter the number of elements in the series"<<endl;
				cin>>n;

				cout<<endl<<"The series is: "<<t1<<'\t'<<t2<<'\t'<<t3<<'\t';

				for(int j=0; j<n-3; j++){
					tribonacci(t1,t2,t3);
					cout<<t3<<'\t';
				}

				break;

			default:
				cout<<"Wrong choice"<<endl;
				goto option;
				
		}
		
		cout<<endl<<endl<<"Repeat Program?"<<endl;
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
