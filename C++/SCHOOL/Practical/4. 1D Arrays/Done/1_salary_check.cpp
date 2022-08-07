#include<iostream.h>
#include<conio.h>
#include<process.h>

long count=0;

/*
Write a program to count the number of employees earning more than Rs. 1 lakh per annum. The monthly salaries of 10 employees are to be inputted from the user. (Hint: Salary per annum is calculated as 12*monthly salary).
*/

//************************************************************

int num_chk(int a){
	int n=0;

	if(a*12>100){
		n=1;
	}

	else{
		n=0;
	}

	return n;
}

//************************************************************

int main(void){
	int rep=1;

	while(rep==1){
		clrscr();

     	cout<<"Assignment 4"<<endl<<"Practical 1"<<endl<<endl;

		int mnth_sal[10];
		int no=0;

		cout<<endl<<"Enter the monthly salary of 10 employees (in thousands)"<<endl;

		for(int i=0; i<10; i++){
			cin>>mnth_sal[i];
		}

		for(int j=0; j<10; j++){
			no+=num_chk(mnth_sal[j]);
		}

		cout<<endl<<"No of employees with salary greater than 1 lakh per annum is "<<no<<endl;
		
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