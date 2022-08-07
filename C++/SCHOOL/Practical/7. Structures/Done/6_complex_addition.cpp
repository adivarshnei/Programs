#include<iostream.h>
#include<conio.h>
#include<process.h>

//********************************************************************

typedef float real;
typedef float imag;

//********************************************************************

typedef struct complex{
	real re;
	imag im;
};

//********************************************************************

complex add(complex z1, complex z2){
	complex z3;

	z3.re=z1.re+z2.re;
	z3.im=z1.im+z2.im;

	return z3;
}

//********************************************************************

long count=0;

//********************************************************************

int main(void){
	int rep=1;

	while(rep==1){
		clrscr();

		complex c1, c2;

		cout<<"Enter first complex number: "<<endl;
		cout<<"Real part: ";
		cin>>c1.re;
		cout<<"Complex part: ";
		cin>>c1.im;

		cout<<endl<<"Enter second complex number: "<<endl;
		cout<<"Real part: ";
		cin>>c2.re;
		cout<<"Complex part: ";
		cin>>c2.im;

		complex c3=add(c1,c2);

		cout<<endl<<"("<<c1.re<<" + "<<c1.im<<"i)"<<" + "<<"("<<c2.re<<" + "<<c2.im<<"i) = "<<c3.re<<" + "<<c3.im<<"i"<<endl<<endl;

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