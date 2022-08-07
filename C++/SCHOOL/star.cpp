#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>

//typedef

//functions

//typedef structs

long count=0;

int main(void){
	int rep=1;

	while(rep==1){
		//clrscr();
		system("cls");
		
		for(int lim=0; lim<no; lim++){
		for(int i=0; i<3; i++){
		cout<<" ";
		}

  		cout<<"Repeat Program?"<<endl;
		cin>>rep;
		count++;

		if(count>=50){
			//clrscr();
			system("cls");

			cout<<"Abnormal END"<<endl;

			getch();
			exit(0);
		}

	}

	cout<<"Normal END"<<endl;

	getch();
	return 0;
}

