#include<iostream.h>
#include<conio.h>
#include<process.h>

long count=0;

int main(void){
	int rep=1;
	
	while(rep==1){
		clrscr();

		int n;
		int a[50][50];
		int usum=0, diag=0;
		int choice;

		cout<<"Enter the number of elements of the square matrix"<<endl;
		cin>>n;

		if(n>50){
			cout<<endl<<"Overflow"<<endl;

			getch();

			exit(0);
		}

		cout<<"Enter the matrix elements"<<endl;

		for(int i=0; i<n; i++){
			cout<<"Row "<<i+1<<": "<<endl;

			for(int j=0; j<n; j++){
				cout<<"Column "<<j+1<<": ";

				cin>>a[i][j];
			}

		}

		for(int x=0; x<n; x++){

			for(int y=0; y<n; y++){
				cout<<a[x][y]<<"  ";
			}

			cout<<endl;
		}

		for(int k=0; k<n; k++){

			for(int l=0; l<n; l++){

				if(k<l){
					usum+=a[k][l];
				}

				if(k==l||k+l==n){
					diag+=a[k][l];
				}

			}

		}

		choice:

		cout<<"1. Sum of diagonal elements"<<endl;
		cout<<"2. Sum of upper triangle"<<endl;
		cin>>choice;

		switch(choice){

			case 1:
				cout<<endl<<"The sum of the upper diagonal elements: "<<diag<<endl;
				break;

			case 2:
				cout<<endl<<"The sum of the upper triangle elements: "<<usum<<endl;
				break;

			default:
				cout<<"Wrong option"<<endl;
				goto choice;

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