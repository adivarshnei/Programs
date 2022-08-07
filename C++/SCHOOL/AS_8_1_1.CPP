#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<dos.h>

int count=0,d;

/*
Define a class Time which will have the data members:
hours(int), minutes(int), second(int)
and member functions read Time(int h,int m,int s) 
to initialize data members to h, m and s,
showtime() and addtime( Time t1,Time t2) to add two Time.
*/

//********************************************************************

class Time
{
    private:
	    int hours;
	    int minutes;
	    int second;
    public:
	    void get_data()
	    {
	        int hr,min,sec;
	        cout<<"enter hours:\n";
	        cin>>hr;
	        cout<<"enter minutes:\n";
	        cin>>min;
	        cout<<"enter seconds:\n";
	        cin>>sec;
		read_data(hr,min,sec);
	    }
	    void show_time();
	    void read_data(int,int,int);
	    void add_time(Time t1,Time t2);

};

//*******************************************************************

void Time::show_time()
{
    cout<<"Time entered is:- "<<hours<<':'<<minutes<<':'<<second<<endl;
}

//*********************************************************************

void Time::add_time(Time t1,Time t2)
{
    second=t1.second+t2.second;
	minutes=second/60;
	second=second%60;
	minutes=minutes+t1.minutes+t2.minutes;
	hours=minutes/60;
	minutes=minutes%60;
	hours=hours+t1.hours+t2.hours;
}

//********************************************************************

void Time::read_data(int h,int m,int s)
{
    hours=h;
    minutes=m;
    second=s;
}

//**********************************************************************

void main()
{
    char rep='1';

    while(rep=='1')
    {
	    clrscr();

	Time t1,t2,t3;

	t1.get_data();
	t2.get_data();
	cout<<"the 1st Time entered:\n";
	t1.show_time();
	cout<<"the 2nd Time entered:\n";
	t2.show_time();
	t3.add_time(t1,t2);
	cout<<"Time after adding:\n";
	t3.show_time();


	    cout<<"\nRepeat Program?"<<endl;
	    cin>>rep;
	    count++;

	    if(count>=50)
	    {
		    clrscr();
			cout<<"GOING INTO THE INFINITY LOOP";
			for(d=1;d<150;d++)
			{
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