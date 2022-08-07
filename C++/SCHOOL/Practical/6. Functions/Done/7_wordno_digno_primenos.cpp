#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>

typedef char str;
typedef int digno;
typedef long int pr;

int function(str *a){
	int no=0;

	for(int i=0; a[i]!='\0'; i++){
		
		if(a[i]==' '){
			no++;
		}

	}

	return no+1;
}

int function(digno a){
	int no=0;

	for(int i=0; a!=0; i++){
		a/=10;
		no++;
	}

	return no;
}

int function(pr *a, int n){
	int number=0, flag;

	for(int i=0; i<n; i++){
		flag=0;

		for(int j=2; j<a[i]; j++){

			if(a[i]==0||a[i]==1){
				flag=1;
				break;
			}

			if(a[i]%j==0){
				flag=1;
				break;
			}

		}

		if(flag==1){
			flag=0;
			cout<<'\t'<<a[i]<<endl;
		}

		else{
			cout<<a[i]<<endl;
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

		int choice;
		
		option:
		cout<<"1. Count words in a string"<<endl;
		cout<<"2. Count digits in an integer"<<endl;
		cout<<"3. Count number of primes in an integer array"<<endl;
		cin>>choice;

		switch(choice){

			case 1:
				char *a;
				int n_1;

				cout<<"Enter the string"<<endl;
				gets(a);

				n_1=function(a);
				
				cout<<"Number of words in the string: "<<n_1;
				break;

			case 2:
				digno b;
				int n_2;
				
				cout<<"Enter the number"<<endl;
				cin>>b;
				
				n_2=function(b);

				cout<<"Number of digits in the integer: "<<n_2;
				break;

			case 3:
				pr *c;
				int n;
				int n_3;

				cout<<"Enter the array limit"<<endl;
				cin>>n;
				
				cout<<"Enter the array of numbers"<<endl;
				
				for(int i=0; i<n; i++){
					cin>>c[i];
				}

				n_3=function(c,n);

				cout<<"Number of primes in the array: "<<n_3;
				break;

			default:
				cout<<"Wrong Choice";
				goto option;
				break;

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