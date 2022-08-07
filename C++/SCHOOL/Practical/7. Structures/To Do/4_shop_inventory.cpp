#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<string.h>

//********************************************************************

typedef long int id;
typedef char string;
typedef double money;
typedef int date;

//********************************************************************

typedef struct dop{
	date day;
	date month;
	date year;
};

//********************************************************************

typedef struct inventory{
	id itemno;
	string name[50];
	money price;
	string category[50];
	dop date_of_purchase;
};

//********************************************************************

void cat_disp(inventory *a, string *cat){

	for(int i=0; a[i].name!='\0'; i++){

		if(strcmp(a[i].category,cat)==0){
			cout<<"Item Number: "<<a[i].itemno<<endl;;
			cout<<"Item Name: ";
			puts(a[i].name);
			cout<<"Item Price: "<<a[i].price<<endl;
			cout<<"Date of Purchase: "<<a[i].date_of_purchase.day<<"/"<<a[i].date_of_purchase.month<<"/"<<a[i].date_of_purchase.year<<endl;
		}

	}

}

//********************************************************************

void arrange(inventory *s1){
	inventory temp;

	for(int i=0; s1[i].name!='\0'; i++){

		for(int j=i+1; s1[j].name!='\0'; j++){

			if(s1[i].price<s1[j].price){
				temp=s1[i];
				s1[i]=s1[j];
				s1[j]=temp;
			}

		}

	}

	cout<<endl<<endl<<"Items in ascending order of Price: ";

	for(int l=0; s1[l].name!='\0'; l++){
		cout<<"Item No: "<<s1[l].itemno<<endl<<"Item Name: ";
		puts(s1[l].name);
		cout<<"Item Price: "<<s1[l].price<<endl;
	}

}

//********************************************************************

int count_price(inventory a){
	int num=0;

		if(a.price>=500){
			num=1;
		}


	return num;
}

//********************************************************************

int count_date(inventory a, dop date){
	int num=0;

	if(a.date_of_purchase.day==date.day && a.date_of_purchase.month==date.month && a.date_of_purchase.year==date.year){
		num=1;
	}

	return num;
}

//********************************************************************

inventory input(int &i){
	++i;

	inventory p;

	cout<<"Enter the name of the item: ";
	gets(p.name);

	cout<<"Enter the price: ";
	cin>>p.price;

	cout<<"Enter the category: ";
	gets(p.category);

	cout<<"Enter the item number: ";
	cin>>p.itemno;

	cout<<"Enter the date of purchase: "<<endl;
	cout<<"Date: ";
	cin>>p.date_of_purchase.day;
	cout<<"Month: ";
	cin>>p.date_of_purchase.month;
	cout<<"Year: ";
	cin>>p.date_of_purchase.year;

	return p;
}

//********************************************************************

long count=0;

//********************************************************************

int main(void){
	int rep=1;
	inventory items[10];
	int i=0, choice, conbrk, num;
	dop date;
	string cate[50];

	while(rep==1){
		clrscr();

		cout<<"Enter the name of the item: ";
		gets(items[i].name);

		cout<<"Enter the price: ";
		cin>>items[i].price;

		cout<<"Enter the category: ";
		gets(items[i].category);

		cout<<"Enter the item number: ";
		cin>>items[i].itemno;

		cout<<"Enter the date of purchase: "<<endl;
		cout<<"Date: ";
		cin>>items[i].date_of_purchase.day;
		cout<<"Month: ";
		cin>>items[i].date_of_purchase.month;
		cout<<"Year: ";
		cin>>items[i].date_of_purchase.year;

		for(;;){
			cout<<endl<<endl<<"1. Display item details of a specific category"<<endl;
			cout<<"2. Arrange items according to ascending order of price"<<endl;
			cout<<"3. Count number of items with price more than 500"<<endl;
			cout<<"4. Count number of items purchased on a particular date"<<endl;
			cout<<"5. Enter Data for more items"<<endl;
			cout<<"6. Exit"<<endl;
			cin>>choice;

			switch(choice){

				case 1:
					cout<<"Enter category to be searched"<<endl;
					gets(cate);

					cat_disp(items, cate);

					conbrk=0;
					break;

				case 2:
					arrange(items);

					conbrk=0;
					break;

				case 3:
					for(int j=0; items[j].name!='\0';j++){
						num+=count_price(items[j]);
					}

					cout<<"Number of items with price greater than 500: "<<num<<endl;

					conbrk=0;
					break;

				case 4:
					cout<<"Enter the date of purchase to be searched: "<<endl;
					cout<<"Date: ";
					cin>>date.day;
					cout<<"Month: ";
					cin>>date.month;
					cout<<"Year: ";
					cin>>date.year;

					for(int k=0; items[k].name!='\0';k++){
						num+=count_date(items[k], date);
					}

					cout<<"Number of items purchased on "<<items[i].date_of_purchase.day<<"/"<<items[i].date_of_purchase.month<<"/"<<items[i].date_of_purchase.year<<": "<<num<<endl;
					conbrk=0;
					break;

				case 5:
					items[i+1]=input(i);
					conbrk=0;
					break;

				case 6:
					conbrk=1;
					break;

				default:
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