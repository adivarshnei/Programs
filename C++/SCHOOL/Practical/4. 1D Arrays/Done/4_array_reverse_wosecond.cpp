#include<iostream.h>
#include<conio.h>
#include<process.h>

long count=0;

/*
Write a program to reverse the elements in an array without using second array.
*/

//************************************************************

void reverse(int a[50], int n){
	int temp;

	for(int q=n-1, w=0; q>w; q--, w++){
		temp=a[w];
		a[w]=a[q];
		a[q]=temp;
	}

	cout<<endl<<endl<<"Reversed Array: ";

	for(int s=0; s<n; s++){
		cout<<a[s]<<" ";
	}

}

//************************************************************

int main(void){
	int rep=1;

	while(rep==1){
		clrscr();
		
		cout<<"Assignment 4"<<endl<<"Practical 4"<<endl<<endl;

		int a[50];
		int n, temp;

		cout<<"Enter the limit of the array: ";
		cin>>n;

		if(n>50){
			cout<<endl<<"Overflow"<<endl;

			getch();

			break;
		}

		cout<<endl<<"Enter the elements of the array:"<<endl;

		for(int i=0; i<n; i++){
			cin>>a[i];
		}

		cout<<endl<<"Original array: ";

		for(int j=0; j<n; j++){
			cout<<a[j]<<" ";
		}

		reverse(a, n);

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