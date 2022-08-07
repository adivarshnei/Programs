#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<string.h>

//********************************************************************

typedef int date;
typedef long int e_no;
typedef char string;
typedef double money;
typedef float perk;

//********************************************************************

typedef struct employee{
	e_no number;
	string name[50];
	string desig[50];
	
	struct date_of_birth{
		date day;
		date month;
		date year;
	}dob;

	money base_sal;

	struct perks{
		perk da;
		perk hra;
		perk bonus;
	}prk;

	money net_sal;

};

//********************************************************************

void payslip(employee e1){
	e1.prk.bonus=800;
	e1.prk.da=(15*e1.base_sal)/100;
	e1.prk.hra=(12*e1.base_sal)/100;

	e1.net_sal=e1.base_sal+e1.prk.bonus+e1.prk.da+e1.prk.hra;

	if(e1.net_sal>=25000){
		strcpy(e1.desig, "Manager");
	}

	else if(e1.net_sal<25000 && e1.net_sal>=15000){
		strcpy(e1.desig, "Executive");
	}

	else if(e1.net_sal<15000){
		strcpy(e1.desig, "Non Executive");
	}

	cout<<endl<<endl<<"PAYSLIP"<<endl<<endl;
	cout<<"Employee Number:           "<<e1.number<<endl;
	cout<<"Employee Name:             ";
	puts(e1.name);
	cout<<"Designation:               ";
	puts(e1.desig);
	cout<<"Date of Birth:             "<<e1.dob.day<<"/"<<e1.dob.month<<"/"<<e1.dob.year<<endl;
	cout<<endl<<"Salary Breakdown:"<<endl;
	cout<<"Base Salary:               "<<e1.base_sal<<endl;
	cout<<"DA:                        "<<e1.prk.da<<endl;
	cout<<"HRA:                       "<<e1.prk.hra<<endl;
	cout<<"Bonus:                     "<<e1.prk.bonus<<endl;
	cout<<"Total Net Salary:          "<<e1.net_sal<<endl;
}

//********************************************************************

long count=0;

//********************************************************************

int main(void){
	int rep=1;

	employee emp;
	
	while(rep==1){
		clrscr();
		
		cout<<"Enter the employee number: ";
		cin>>emp.number;

		cout<<"Enter the employee name: ";
		gets(emp.name);

		cout<<"Enter the employee date of birth: "<<endl;
		cout<<"Date: ";
		cin>>emp.dob.day;
		cout<<"Month: ";
		cin>>emp.dob.month;
		cout<<"Year: ";
		cin>>emp.dob.year;

		cout<<"Enter the base salary of the employee: ";
		cin>>emp.base_sal;

		payslip(emp);
		
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