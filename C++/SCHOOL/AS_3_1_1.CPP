#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>

int count=0,d;

/*Define a class floppy box with data members: floppyno (int), size (int) and name(20 characters).
Include member functions: getdata(), showdata() and a function findsize() - To display the size of the given name of the floppy.
Write a menu driven program to
 -	search and display the floppy details by taking the floppy no as parameter
-	Sort the array in descending order of size and display the sorted array
-	Count the number of floppies of a given floppy name (the floppy name is given as parameter
*/

//****************************************************************************

class floppy
{
	private:
		int floppy_no;
		char name[20];

	public:
		void get_data();
		void show_data();
		int find_size();
		void search_floppy(int);
		int name_search(char []);
		int size;
		void sort(int []);
};

//**************************************************************************

void floppy::get_data()
{
	cout<<"enter the floppy number:\n";
	cin>>floppy_no;
	cout<<"enter the floppy size:\n";
	cin>>size;
	cout<<"enter the floppy name:\n";
	gets(name);
}

//**************************************************************************

void floppy::show_data()
{
	cout<<"floppy number:  "<<floppy_no<<endl;
	cout<<"floppy name:  "<<name<<endl;
	cout<<"size:  "<<size<<endl;
}

//****************************************************************************

int floppy::find_size()
{
	cout<<"enter the name\n";
	gets(name);
	int x=strlen(name);
	cout<<"the string length is:  "<<x<<endl;
	return 0;
}

//***********************************************************************

void floppy::search_floppy(int n)
{
	if(n==floppy_no)
	{
		cout<<"floppy found:\n";
		cout<<"its details:\n";
		show_data();
	}
	else
	{
		cout<<"no match found\n";
	}

}

//**************************************************************************

int floppy::name_search(char n[])
{

	if(strcmp(n,name)==0)
	{
		count++;
	}
	return count;
}

//**************************************************************************

void floppy::sort(int b[])
{
	int temp;
	int max=b[0];
	for(int i=1;i<5;i++)
	{
		if(b[i]>max)
		{
			temp=b[i];
			b[i]=max;
			b[i-1]=temp;

		}
	}
	cout<<endl;
	for(i=0;i<5;i++)
	{
		cout<<b[i]<<">"<<"\b";
	}
	cout<<endl;

}

//****************************************************************************
void main()
{
    char rep='1';

    while(rep=='1')
    {
	    clrscr();
	    int ch;
	    floppy f[5];

		for(int i=0;i<5;i++)
		{
			f[i].get_data();
		}
		do
		{
			cout<<"1.search floppy with floppy number\n";
			cout<<"2.count the number of floppy with same name\n";
			cout<<"3.sort the floppy by floppy size\n";
			cout<<"4.find the length of the floppy name\n";
			cout<<"5.exit\n";
			cout<<"enter tyour choice:\n";
			cin>>ch;

			switch(ch)
			{
				case 1:
					int x;
					cout<<"enter the floppy number\n";
					cin>>x;
					for(int i=0;i<5;i++)
					{
						f[i].search_floppy(x);
					}

					break;

				case 2:
					char a[20];
					cout<<"enter the name of the floppy you want to check:\n";
					gets(a);
					int y;
					for(i=0;i<5;i++)
					{
						y=f[i].name_search(a);
					}
					cout<<"number of floppy with same name:  "<<y<<endl;
					break;

				case 3:
					int c[5];
					for(i=0;-i<5;i++)
					{
						c[i]=f[i].size;
					}
					for(i=0;i<5;i++)
					{
						f[i].sort(c);
					}
					break;

				case 4:

					f[i].find_size();
					break;
				case 5:
					exit(0);

				default:
					cout<<"wrong entry,try again\n";
			}

		}while(1);
	    
	    cout<<"\nRepeat Program?"<<endl;
	    cin>>rep;
	    count++;
	    
	    if(count>=50)
	    {
		    clrscr();
			cout<<"GOING INTO THE INFINITY LOOP";
			for(d=1;d<150;d++){
			cout<<".";
			delay(50);
			}
			cout<<endl<<"EXECUTION TERMINATED";
		    getch();
		    exit(0);
	    }
	    
    }
    
    cout<<"NORMAL EXIT"<<endl;
    getch();
}