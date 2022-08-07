#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<dos.h>

int count=0,d;

/*
Define a class complexnum with data members real(int) and imaginary(int).
Include member function - readdata() to read the complex no,
display() to display the complex no,  addcomplex(complexnum n2) to
add two complex no and   subcomplex (complexnum n2) to subtract two complex no.
 Both addcomplex and subcomplex should return resultant complex num object.
*/

//*******************************************************************************

class complex
{
   private:
	int real;
	int img;
   public:
	void read_data();
	complex sum(complex n2);
	void disp();
    complex sub(complex n2);
};

//************************************************************************************

void complex::read_data()
{
    cout<<"enter the real part of the complex number\n";
    cin>>real;
    cout<<"enter the imaginary part of the complex number\n";
    cin>>img;
}

//**************************************************************************
complex complex::sum(complex n2)
{
	complex n;
	n.real = real + n2.real;
	n.img = img + n2.img;
	return n;
}

//*********************************************************************************

complex complex::sub(complex n2)
{
	complex n;
	n.real = real - n2.real;
	n.img = img - n2.img;
	return n;
}

//*******************************************************************************

void complex::disp()
{
	cout<<real<<" + i"<<img<<endl;
}


void main()
{
	char rep='1';

    while(rep=='1')
    {
    complex c1,c2,c3,c4;
    c1.read_data();
    c2.read_data();
	c3=c1.sum(c2);
    c4=c1.sub(c2);

	cout<<"\n complex Number 1 = ";c1.disp();
	cout<<"\n complex Number 2 = ";c2.disp();
	cout<<"\n complex Number 3 = ";c3.disp();
	cout<<"\n complex Number 4 = ";c4.disp();

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