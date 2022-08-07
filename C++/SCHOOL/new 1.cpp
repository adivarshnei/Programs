#include<iostream.h>
#include<conio.h>
void main()
{
	//Algorithm 1
	//To display the sum total of three numbers
	clrscr();
	int x,y,z,tot;
	cout<<"Enter the First Number: ";
	cin>>x;
	cout<<"Enter the Second Number: ";
	cin>>y;
	cout<<"Enter the Third Number: ";
	cin>>z;
	tot=x+y+z;
	cout<<"The Total is: "<<tot<<endl;
	getch();
}

#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
int p,t,r,si,amt;
{
	//Algorithm 2
	//To calculate simple interest
	clrscr();
	cout<<"Enter the Principal: ";
	cin>>p;
	cout<<"Enter the Rate of Interest: ";
	cin>>r;
	cout<<"Enter the Time Period: ";
	cin>>t;
	si=(p*t*r)/100
	amt=si+p
	cout<<"The Simple Interest to be paid is: "<<si<<endl;
	cout<<"The Amount to be paid is: "<<amt<<endl;
	getch();
}

#include<iostream.h>
#include<conio.h>
void main()
{
	//Algorithm 3
	//To check for odd/even nos.
	clrscr();
	int n;
	cout<<"Enter the number: ";
	cin>>n;
	if (n%2==0)
		cout<<"The number entered is even";
	else
		cout<<"The number entered is odd";
	getch();
}
#include<iostream.h>
#include<conio.h>
void main()
{
	//Algorithm 4
	//To find the average of any 'n' numbers
	clrscr();
	int n,x,tot,a;
	float ave;
	cout<<"Enter the number of values to be added"<<endl;
	cin>>n;
	tot=0;
	for (a=0;a<n;a++)
		{
			cout<<"Enter the value of number to be added"<<endl;
			cin>>x;
			tot=tot+x;
		}
	ave=tot/n;
	cout<<"The total is:"<<tot<<" and the average is:"<<ave<<endl;
	getch();
}

#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
	//Algorithm 6
	//To convert Centigrade into Fahrenheit
	clrscr();
	float c,f,k;
	cout<<"Enter the temperature in Centigrade"<<endl;
	cin>>c;
	f=(1.8*c)+32;
	k=c+273.15;
	cout<<"The Temperature in fahrenheit is: "<<f<<endl;
	cout<<"The Temperature in kelvin is: "<<k<<endl;
	getch();
}

#include<iostream.h>
#include<conio.h>
void main()
{
	//To print the sum of the first n natural numbers
	clrscr();
	int n,p,a,tot;
	cout<<"Enter no. of values"<<endl;
	cin>>n;
	a=1;
	tot=0;
	for (p=0;p<n;p++,a++)
		{
			tot=tot+a;
		}
	cout<<"The sum of the first "<<n<<" natural numbers is "<<tot<<endl;
	getch();
}

#include<iostream.h>
#include<conio.h>
void main()
{
    //Algorithm 5
    //To find age and gender of 5 people and compute number of males and females who are above 30 years
    int x,g,count,m,f,a;
    clrscr();
    m=0;
    f=0;
    for (count=0;count<5;count++)
    {
        cout<<"Enter the age of the person"<<endl;
        cin>>x;
        cout<<"Enter the gender of the person (1 for female, 2 for male)"<<endl;
        cin>>g;
        switch(g)
        {
            case 1:
                if(x<30)
                {
                    f=f+1;
                }
                else
                {
                    cout<<"";
                }
                break;
            case 2:
                if(x<30)
                {
                    m=m+1;
                }
                else
                {
                    cout<<"";
                }
                break;
            default:
                cout<<"invalid numeric entry";
                break;
        }
    }
    cout<<"No of males under 30="<<m<<endl;
    cout<<"No of females under 30="<<f<<endl;
    getch();
}

#include<iostream.h>
#include<conio.h>
void main()
{
	//Algorithm 7
	//To find the area of a square, circle or rectangle
	clrscr();
	int sh;
	float ar;
	cout<<"Enter shape code (1=square), (2=circle), (3=rectangle)"<<endl;
	cin>>sh;
	switch (sh)
		{
			case 1:
				float a;
				cout<<"Enter the side of the square"<<endl;
				cin>>a;
				ar=a*a;
				cout<<"Area of the square is:"<<ar<<endl;
				break;
			case 2:
				float pi, r;
				cout<<"Enter the radius of the circle"<<endl;
				cin>>r;
				pi=22/7;
				ar=pi*(r*r);
				cout<<"Area of the circle is:"<<ar<<endl;
				break;
			case 3:
				float l,b;
				cout<<"Enter the length of the rectangle"<<endl;
				cin>>l;
				cout<<"Enter the breadth of the rectangle"<<endl;
				cin>>b;
				ar=l*b;
				cout<<"Area of the rectangle is:"<<ar<<endl;
				break;
			default:
				cout<<"Invalid number entered"<<endl;
				break;
		}
	getch();
}

#include<iostream.h>
#include<conio.h>
void main()
{
    //To program a calculator with addition, subtraction, multiplication and division
	int count, op;
    float x, y, pro, sum, dif_a, dif_b, quo_a, quo_b;
    clrscr();
    label:
    cout<<"Enter the two numbers"<<endl;
    cin>>x>>y;
    cout<<"Enter the operator (1=+,2=-,3=X,4=/,5=all)"<<endl;
    cin>>op;
    switch(op)
    {
	case 1:
	    sum=x+y;
	    cout<<x<<" + "<<y<<" = "<<sum<<endl;
	    cout<<"Repeat Program?(1=Yes, 2=No)"<<endl;
	    cin>>count;
	    break;
	case 2:
	    dif_a=x-y;
	    dif_b=y-x;
	    cout<<x<<" - "<<y<<" = "<<dif_a<<endl;
	    cout<<y<<" - "<<x<<" = "<<dif_b<<endl;
	    cout<<"Repeat Program?(1=Yes, 2=No)"<<endl;
	    cin>>count;
	    break;
	case 3:
	    pro=x*y;
	    cout<<x<<" X "<<y<<" = "<<pro<<endl;
	    cout<<"Repeat Program?(1=Yes, 2=No)"<<endl;
	    cin>>count;
	    break;
	case 4:
	    quo_a=x/y;
	    quo_b=y/x;
	    cout<<x<<" / "<<y<<" = "<<quo_a<<endl;
	    cout<<y<<" / "<<x<<" = "<<quo_b<<endl;
	    cout<<"Repeat Program?(1=Yes, 2=No)"<<endl;
	    cin>>count;
	    break;
	case 5:
	    sum=x+y;
	    dif_a=x-y;
	    dif_b=y-x;
	    pro=x*y;
	    quo_a=x/y;
	    quo_b=y/x;
	    cout<<x<<" + "<<y<<" = "<<sum<<endl;
	    cout<<x<<" - "<<y<<" = "<<dif_a<<endl;
	    cout<<y<<" - "<<x<<" = "<<dif_b<<endl;
	    cout<<x<<" X "<<y<<" = "<<pro<<endl;
	    cout<<x<<" / "<<y<<" = "<<quo_a<<endl;
	    cout<<y<<" / "<<x<<" = "<<quo_b<<endl;
	    cout<<"Repeat Program?(1=Yes, 2=No)"<<endl;
	    cin>>count;
    }
    if(count==1)
    {
	goto label;
    }
    else if(count==2)
    {
	cout<<""<<endl;
    }
    else
    {
	cout<<"INVALID"<<endl;
    }
    getch();
}

#include<iostream.h>
#include<conio.h>
void main()
{
    //To make a multiplication table
	clrscr();
    int x, count, y;
    float n, pro;
    cout<<"Enter the number whose multiplication table is to be drawn"<<endl;
    cin>>n;
    cout<<"Enter the number upto which the table is to be drawn"<<endl;
    cin>>x;
    for(count=0;count<x;count++)
    {
	y=count+1;
	pro=n*y;
	cout<<n<<"X"<<y<<"="<<pro<<endl;
    }
    getch();
}

#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
    //To find the roots of a quadratic equation
    clrscr();
    float x_a, x_b, d;
    int a, b, c;
    cout<<"Let the quad eqn. be = ax^2 + bx + c=0"<<endl;
    cout<<"Enter the value of a, b and c respectively"<<endl;
    cin>>a>>b>>c;
    d=(b*b)-(4*a*c);
    if (d>0)
    {
	x_a=(-b+sqrt(d))/(2*a);
	x_b=(-b-sqrt(d))/(2*a);
	cout<<"The roots are real and unequal"<<endl;
	cout<<"x = "<<x_a<<", "<<x_b<<endl;
    }
    else if (d==0)
    {
	x_a=(-b+sqrt(d))/(2*a);
	cout<<"The roots are real and equal"<<endl;
	cout<<"x = "<<x_a<<endl;
    }
    else if (d<0)
    {
	cout<<"The roots are imaginary"<<endl;
    }
    getch();
}