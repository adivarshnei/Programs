#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>

int x;

/*Define a class country with the data members: country-id(int), country_name(20 characters), capital(20 characters),
president(structure having lname,fname), population(long) and member functions: get_data(), show_data() .
Write functions search() - to display the information of a country by taking the country name and object array
as parameters, and count() to count and return the number of countries whose population is more
 than the population given as parameter along with the object array.
  Write a menu driven program to call these functions
*/
//*************************************************

class country
{
 private:
    int country_id;
    char capital[20];
    struct president
    {
	char fname[20];
	char lname[20];
    }p1;
    char country_name[20];
    long population;
 public:

    void get_data();
    void show_data();
    int search(char n[20]);
    int count(long);
};

//***************************************************

void country::get_data()
{
  cout<<"Enter Country Id\n";
  cin>>country_id;
  cout<<"Enter Country Name\n";
  gets(country_name);
  cout<<"Enter the capital\n";
  gets(capital);
  cout<<"Enter President first name\n";
  gets(p1.fname);
  cout<<"Enter President last name\n";
  gets(p1.lname);
  cout<<"Enter Country population\n";
  cin>>population;
}

//************************************************

void country::show_data()
{
  cout<<"**************COUNTRY DETAILS**************\n";
  cout<<"Country Name : "<<country_name<<endl;
  cout<<"Country Id : "<<country_id<<endl;
  cout<<"Country Capital : "<<capital<<endl;
  cout<<"Country Population : "<<population<<endl;
  cout<<"President Name : "<<p1.fname<<"\t"<<p1.lname<<endl;
}

//***********************************************

int country::search(char n[20])
{
	if(strcmp(n,country_name)==0)
		return 1;
	else
		return 0;
}

//***************************************************

int country::count(long p)
{

	if(p<population)
	{
	return 1;
	}
	else

		return 0;
}

//************************************************

void main()
{
  clrscr();
  country a[3];

  for(int i=0;i<3;i++)
  {
	a[i].get_data();
  }
  int ch;

  do
  {
  cout<<"\n1.Search country name and display details\n";
  cout<<"2.Count no of countries greater than given population\n";
  cout<<"3 exit\n";
  cout<<"Enter Choice\n";
  cin>>ch;

    switch(ch)
    {
	    case 1:
		int z=0;
		char d[20];
		cout<<"enter the name of the country to be searched:\n";
		gets(d);
		for(i=0;i<3;i++)
		{
			z=a[i].search(d);
			if(z==1)
			{
				a[i].show_data();
				break;
			}

		}
		if(z==0)
		cout<<"no result found\n";
		break;
	    case 2:
		{
		long po;
		int y=0;
		x=0;
		   cout<<"Enter population\n";
		   cin>>po;
		   for(i=0;i<3;i++)
		   {
			y=y+a[i].count(po);
		   }
	       cout<<"Required result\n";
	       cout<<y;
		   break;
	    }

	case 3:
	exit(0);

    default:
	cout<<"Wrong choice\n";

	}
    }while(1);

}