#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<string.h>

//********************************************************************

typedef long int id;
typedef char string;
typedef int a;

//********************************************************************

typedef struct census{
	id no;
	string name[50];
	string nation[50];
	string address[100];
	a age;
};

//********************************************************************

void record_print(census *s1){

	for(int i=0; s1[i].name!='\0'; i++){

		if(strcmp(s1[i].nation,"indian")==0){

			if(s1[i].age>=18){
				cout<<endl<<"ID Number:      "<<s1[i].no<<endl;
				cout<<"Name:           ";
				puts(s1[i].name);
				cout<<"Age:            "<<s1[i].age<<endl;
				cout<<"Address:        ";
				puts(s1[i].address);
				getch();
			}

		}

	}

}

//********************************************************************

void search(census *s1, long int x){
	int flag=0, location;

	for(int i=0; s1[i].name!='\0'; i++){

		if(s1[i].no==x){
			flag=1;
			location=i;
			break;
		}

	}

	if(flag==0){
		cout<<"Search unsucessful"<<endl;
	}

	else if(flag==1){
		cout<<"Search successful"<<endl;
		cout<<"ID Number:      "<<s1[location].no;
		cout<<endl<<"Name:           ";
		puts(s1[location].name);
		cout<<"Age:            "<<s1[location].age;
		cout<<endl<<"Address:        ";
		puts(s1[location].address);
		cout<<endl;
	}
}

//********************************************************************

void arrange(census *s1){
	census temp;

	for(int i=0; s1[i].name!='\0'; i++){

		for(int j=i+1; s1[j].name!='\0'; j++){

			if(s1[i].no<s1[j].no){
				temp=s1[i];
				s1[i]=s1[j];
				s1[j]=temp;
			}

		}

	}

	cout<<endl<<endl<<"Citizens in ascending order of ID: ";

	for(int l=0; s1[l].name!='\0'; l++){
		cout<<"ID Number: "<<s1[l].no<<endl<<"Citizen Name: ";
		puts(s1[l].name);
		cout<<endl;
	}

}

//********************************************************************

census input(int &i){
	++i;

	census p;

	cout<<"Enter the name of the citizen: ";
	gets(p.name);
	
	cout<<"Enter the age: ";
	cin>>p.age;
	
	cout<<"Enter the nationality: ";
	gets(p.nation);
	
	cout<<"Enter the citizen ID number: ";
	cin>>p.no;
	
	cout<<"Enter the address: ";
	gets(p.address);

	return p;
}

//********************************************************************

long count=0;

//********************************************************************

int main(void){
	int rep=1;

	census p[20];

	while(rep==1){
		clrscr();

		int i=0, choice, para, conbrk;
		
		cout<<"Enter the name of the citizen: ";
		gets(p[i].name);
		
		cout<<"Enter the age: ";
		cin>>p[i].age;
		
		cout<<"Enter the nationality: ";
		gets(p[i].nation);
		
		cout<<"Enter the citizen ID number: ";
		cin>>p[i].no;
		
		cout<<"Enter the address: ";
		gets(p[i].address);

		for(;;){
			cout<<endl<<endl<<"1. Print record of all people allowed to vote in India"<<endl;
			cout<<"2. Search citizens by ID"<<endl;
			cout<<"3. Arrange all records by ID"<<endl;
			cout<<"4. Enter data for more citizens"<<endl;
			cout<<"5. Exit"<<endl;
			cin>>choice;

			conbrk=0;

			switch(choice){
				
				case 1: 
					record_print(p);
					conbrk=0;
					break;

				case 2:
					cout<<"Enter the ID to be searched: ";
					cin>>para;
					
					search(p, para);

					conbrk=0;
					break;

				case 3:
					arrange(p);
					conbrk=0;
					break; 
				
				case 4:
					p[i+1]=input(i);
					conbrk=0;
					break;

				case 5: 
					conbrk=1;
					break;
				
				default: 
					cout<<"Wrong Choice"<<endl;
					conbrk=0;
					break;

			}

			if(conbrk==1){
				break;
			}

			else if(conbrk==0){
				continue;
			}

		}
		
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