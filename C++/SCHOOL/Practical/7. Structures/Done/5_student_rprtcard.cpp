#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<string.h>

//********************************************************************

typedef int date;
typedef long int id;
typedef char string;
typedef int intarray;

//********************************************************************

typedef struct dob{
	date day;
	date month; 
	date year;
};

//********************************************************************

typedef struct student{
	id rno;
	string name[50];
	dob date_of_birth;
	intarray marks[3];
};

//********************************************************************

void rprtcard(student *s, int roll){

	for(int j=0; s[j].name!='\0'; j++){
									
		if(s[j].rno==roll){
			cout<<endl<<endl<<"REPORT CARD: "<<endl;
			cout<<"Name: ";
			puts(s[j].name);
			cout<<"Roll Number: "<<s[j].rno<<endl;
			cout<<"Date of Birth: "<<s[j].date_of_birth.day<<"/"<<s[j].date_of_birth.month<<"/"<<s[j].date_of_birth.year<<endl;
			cout<<endl<<"Marks: "<<endl;
			cout<<"Subject 1: "<<s[j].marks[0]<<endl;
			cout<<"Subject 2: "<<s[j].marks[1]<<endl;
			cout<<"Subject 3: "<<s[j].marks[2]<<endl;
			cout<<"Average: "<<(s[j].marks[0]+s[j].marks[1]+s[j].marks[2])/3<<endl;

			if((s[j].marks[0]+s[j].marks[1]+s[j].marks[2])/3>=40){
				cout<<"PASSED"<<endl;
			}

			else{
				cout<<"FAILED"<<endl;
			}

		}

	}

}

//********************************************************************

student input(int &i){
	++i;

	student p;

	cout<<"Enter the name of the student: ";
	gets(p.name);
	cout<<"Enter the roll number of the student: ";
	cin>>p.rno;

	cout<<endl<<"Enter the student date of birth: "<<endl;
	cout<<"Date: ";
	cin>>p.date_of_birth.day;
	cout<<"Month: ";
	cin>>p.date_of_birth.month;
	cout<<"Year: ";
	cin>>p.date_of_birth.year;

	for(int j=0; j<3; j++){
		cout<<"Enter marks in subject "<<j+1<<": ";
		cin>>p.marks[j];
	}

	return p;
}

//********************************************************************

long count=0;

//********************************************************************

int main(void){
	int rep=1;
	int i=0, choice, roll, conbrk=0;
	student s[10];

	while(rep==1){
		clrscr();

		cout<<"Enter the name of the student: ";
		gets(s[i].name);
		cout<<"Enter the roll number of the student: ";
		cin>>s[i].rno;

		cout<<"Enter the student date of birth: "<<endl;
		cout<<"Date: ";
		cin>>s[i].date_of_birth.day;
		cout<<"Month: ";
		cin>>s[i].date_of_birth.month;
		cout<<"Year: ";
		cin>>s[i].date_of_birth.year;

		for(int j=0; j<3; j++){
			cout<<"Enter marks in subject "<<j+1<<": ";
			cin>>s[i].marks[j];
		}

		for(;;){
			cout<<"1. Print report card by roll number"<<endl;
			cout<<"2. Enter data for more students"<<endl;
			cout<<"3. Exit"<<endl;
			cin>>choice;

			switch(choice){
				case 1:
					cout<<"Enter the roll no: ";
					cin>>roll;

					rprtcard(s, roll);

					conbrk=0;
					break;

				case 2:
					s[i+1]=input(i);
					conbrk=0;
					break;

				case 3:
					conbrk=1;
					break;
					
			}

			if(conbrk==1){
				break;
			}

			else if(conbrk==0){
				continue;
			}

			count++;

			if(count>=50){
				clrscr();

				cout<<"Abnormal END"<<endl;

				getch();
				exit(0);
			}

		}

		cout<<endl<<"Repeat Program?"<<endl;
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