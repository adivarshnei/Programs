#include<iostream.h>
#include<conio.h>
#include<process.h>

long count=0;

/*
Write a program to reverse the elements of an array and store them in another array.
*/

int main(void){
	int rep=1;
	
	while(rep==1){
		clrscr();
		
		cout<<"Assignment 4"<<endl<<"Practical 3"<<endl<<endl;
		
		int l;

		cout<<"Enter the limit of the array";
		cin>>l;

		if(l>50){
			cout<<endl<<"Overflow"<<endl;

			getch();

			break;
		}

		int a[50], b[50];

		cout<<endl<<"Enter the array elements: "<<endl;

		for(int i=0; i<l; i++){
			cin>>a[i];
		}

		for(int j=0; j<l; j++){
			b[j]=a[l-(j+1)];
		}

		cout<<endl<<"Initial array:\t";

		for(int k=0; k<l; k++){
			cout<<a[k]<<' ';
		}

		cout<<endl<<endl<<"Reversed array:\t";

		for(int m=0; m<l; m++){
			cout<<b[m]<<' ';
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