#include<iostream.h>
#include<conio.h>
#include<process.h>

long count=0;

int main(void){
	int rep=1;
	
	while(rep==1){
		clrscr();

		int n, r, c;
		int a[50];
		int b[50][50];

		cout<<"Enter the number of elements of the array"<<endl;
		cin>>n;

		if(n>50){
			cout<<endl<<"Overflow"<<endl;

			getch();

			exit(0);
		}

		cout<<"Enter the array elements: "<<endl;

		for(int i=0; i<n; i++){
			cin>>a[i];
		}

		cout<<endl;

		for(; n%r!=0;){
			cout<<"Enter number of rows(number must divide elements of array completely)"<<endl;
			cin>>r;

			if(n%r!=0){
				cout<<"Complete division impossible"<<endl;
				cout<<"Enter new value for number of rows"<<endl;
				continue;
			}

			else if(n%r==0){
				c=n/r;
			}

		}

		int x=0;

		for(int j=0; j<r; j++){

			for(int k=0; k<c; k++){
				b[j][k]=a[x];
				++x;
			}

		}

		cout<<"The matrix is: "<<endl;

		for(int l=0; l<r; l++){

			for(int m=0; m<c; m++){
				cout<<b[l][m]<<"  ";
			}

			cout<<endl;
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