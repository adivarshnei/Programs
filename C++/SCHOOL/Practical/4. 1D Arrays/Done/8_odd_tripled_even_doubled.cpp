#include<iostream.h>
#include<conio.h>
#include<process.h>

long count=0;

/*
Write a program to declare and accept values into an integer array. Re-arrange the array in such a way that odd values are replaced with thrice their value and even values of the array are replaced with twice their value.
Example: If the array contains: 3,4,5,6,7,8,9,10;
Then after re-arranging the array should be: 9,8,15,12,21,16,27,20
*/

//************************************************************

int odd_even_chk(int a){
	int flag;
	
	if(a%2==0){
		flag=0;
	}

	if(a%2!=0){
		flag=1;
	}

	return flag;
}

//************************************************************

int odd_three(int a){
	a*=3;
	return a;
}

//************************************************************

int even_two(int a){
	a*=2;
	return a;
}

//************************************************************

int main(void){
	int rep=1;
	
	while(rep==1){
		clrscr();

		cout<<"Assignment 4"<<endl<<"Practical 4"<<endl<<endl;
		
		int n, flag;
		int a[50];

		cout<<"Enter number of elements in array: "<<endl;
		cin>>n;

		if(n>50){
			cout<<endl<<"Overflow"<<endl;

			getch();

			break;
		}

		cout<<endl<<"Enter the elements of the array"<<endl;

		for(int i=0; i<n; i++){
			cin>>a[i];
		}

		cout<<endl<<"Original Array: ";

		for(int j=0; j<n; j++){
			cout<<a[j]<<" ";
		}

		cout<<endl<<endl<<"Modified Array: ";

		for(int k=0; k<n; k++){
			flag=odd_even_chk(a[k]);

			switch(flag){

				case 0:
					a[k]=even_two(a[k]);
					break;

				case 1:
					a[k]=odd_three(a[k]);
					break;
					
			}

			cout<<a[k]<<" ";
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