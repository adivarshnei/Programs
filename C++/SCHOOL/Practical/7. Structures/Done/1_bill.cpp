#include<iostream.h>
#include<conio.h>
#include<conioh.h>
#include<process.h>
#include<stdio.h>

//********************************************************************

typedef long int id;
typedef char string;
typedef int value;
typedef float money;

//********************************************************************

typedef struct shop{
	id cust_no;
	string name[50];
	value units;
	money tariff;
};

//********************************************************************

void print_bill(shop b1){
	if(b1.units<100){
		b1.tariff=0.4;
	}

	else if(b1.units>=100 && b1.units<200){
		b1.tariff=0.5;
	}

	else if(b1.units>=200 && b1.units<300){
		b1.tariff=0.75;
	}

	else if(b1.units>=300){
		b1.tariff=1;
	}

	cout<<endl<<endl<<"BILL"<<endl<<endl;
	cout<<"Name of customer:       ";
	puts(b1.name);
	cout<<"Customer ID:            "<<b1.cust_no<<endl;
	cout<<"Units consumed:         "<<b1.units<<endl;
	cout<<"Tariff per unit:        "<<b1.tariff<<endl;
	cout<<"Total Amount:           "<<b1.units*b1.tariff<<endl<<endl<<endl;
}

//********************************************************************

long count=0;

//********************************************************************

int main(void){
	int rep=1;

	shop bill;
	
	while(rep==1){
		//clrscr();
		
		cout<<"Enter the customer ID"<<endl;
		cin>>bill.cust_no;

		cout<<"Enter the name of the customer"<<endl;
		gets(bill.name);

		cout<<"Enter the number of units"<<endl;
		cin>>bill.units;

		print_bill(bill);
		
		cout<<"Repeat Program?"<<endl;
		cin>>rep;
		count++;
		
		if(count>=50){
			//clrscr();
			
			cout<<"Abnormal END"<<endl;
			
			getch();
			exit(0);
		}
	
	}
	
	cout<<"Normal END"<<endl;
	
	getch();
	return 0;
}
