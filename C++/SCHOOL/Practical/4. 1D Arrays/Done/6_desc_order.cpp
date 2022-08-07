#include<iostream.h>
#include<conio.h>
#include<process.h>

long count=0;

/*
Write a program to input 5 elements in an array and arrange them in descending order.
*/

//************************************************************

void desc_order(int arr1[50], int n){
	int temp;

	for(int i=0; i<n; i++){

		for(int j=i+1; j<n; j++){

			if(arr1[i]<arr1[j]){
				temp=arr1[i];
				arr1[i]=arr1[j];
				arr1[j]=temp;
			}

		}

	}

	cout<<endl<<endl<<"Array in Descending Order: ";

	for(int l=0; l<n; l++){
		cout<<arr1[l]<<" ";
	}

}

//************************************************************

int main(void){
	int rep=1;

	while(rep==1){
		clrscr();

		cout<<"Assignment 4"<<endl<<"Practical 6"<<endl<<endl;

		int a[50];
		int l;

		cout<<"Enter the limit of the array: ";
		cin>>l;

		if(l>50){
			cout<<endl<<"Overflow"<<endl;

			getch();

			break;
		}

		cout<<endl<<"Enter the array elements: "<<endl;

		for(int i=0; i<l; i++){
			cin>>a[i];
		}

		cout<<endl<<"Original Array: ";

		for(int j=0; j<l; j++){
			cout<<a[j]<<" ";
		}

		desc_order(a,l);

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