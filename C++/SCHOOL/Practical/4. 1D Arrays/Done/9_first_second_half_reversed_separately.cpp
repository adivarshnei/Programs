#include<iostream.h>
#include<conio.h>
#include<process.h>

long count=0;

/*
Write a program to declare and accept values into an integer array. Re-arrange the array in such a way that all elements in the first half are reversed and all elements in the second half of the array are reversed
Example: If the array contains: 3,4,5,6,7,8,9,10;
Then after re-arranging the array should be: 6,5,4,3,10,9,8,7
*/

void reverse(int a[50], int n){
	int temp;

	for(int q=n-1, w=0; q>w; q--, w++){
		temp=a[w];
		a[w]=a[q];
		a[q]=temp;
	}

	for(int s=0; s<n; s++){
		cout<<a[s]<<" ";
	}

}

int main(void){
	int rep=1;

	while(rep==1){
		clrscr();

		cout<<"Assignment 4"<<endl<<"Practical 4"<<endl<<endl;

		int n;
		int a[50];
		int b[50], c[50];

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

		for(int k=0; k<n/2; k++){
			b[k]=a[k];
		}

		for(int l=0; l<n/2; l++){
			c[l]=a[(n/2)+l];
		}

		cout<<endl<<endl<<"Modified Array: ";

		reverse(b,n/2);
		reverse(c,n/2);

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