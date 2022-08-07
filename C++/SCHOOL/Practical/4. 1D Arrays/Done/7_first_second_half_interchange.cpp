#include<iostream.h>
#include<conio.h>
#include<process.h>

long count=0;

/*
Write a program to declare and accept values into an integer array. Re-arrange the array in such a way that the first half side elements are exchanged with second half side elements of the array.
Example: If the array contains: 3,4,5,6,7,8,9,10,11,12’
Then after re-arranging the array should be: 8,9,10,11,12,3,4,5,6,7
*/

//************************************************************

void reverse(int a[50], int n){
	int temp;

	for(int q=(n/2), w=0; w<(n/2); q++, w++){
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

		cout<<"Assignment 4"<<endl<<"Practical 7"<<endl<<endl;

		int n;
		int a[50];

		cout<<"Enter number of elements in array (Odd numbers will be incremented by one): "<<endl;
		cin>>n;

		if(n>50){
			cout<<endl<<"Overflow"<<endl;

			getch();

			break;
		}

		else if(n<=50){

			if(n%2==0){
				cout<<"";
			}

			else if(n%2!=0){
				n++;
			}

		}

		cout<<endl<<"Enter the elements of the array"<<endl;

		for(int i=0; i<n; i++){
			cin>>a[i];
		}

		cout<<endl<<"Original Array: ";

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