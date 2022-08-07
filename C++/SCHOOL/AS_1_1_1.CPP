/*
2. Define a class Student to have the 
Private data members: 	
			admno(int),
			sname(20 characters), 
			mark[5](float), 
			total(float) and 
			a member function calculate()- to calculate average of 5 subjects
			and returns a float. 

public member: 		
			takedata() which will accept values for admno, sname, marks in 5
			subjects and invoke calculate() to calculate total and
			showdata() to display all data members.
*/

#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<stdio.h>

int count=0,d;

//*************************

class Student
{
	private:
		int admno;
		char sname[20];
		float mark[5];
		float total;

		float calculate() {
			float ave = (total / 5);

			return ave;
		}

	public:
		float takedata();
		void showdata();
};

//*************************

float Student::takedata() 
{
	cout << "Enter admission number: ";
	cin >> admno;

	cout << "Enter name of the student: ";
	gets(sname);

	cout << "Enter marks: " << endl;

	total = 0;

	for (int i = 0; i < 5; i++) {
		cout << "Subject " << i + 1 << ": ";
		cin >> mark[i];
		total += mark[i];
	}

	return calculate();
}

//*************************

void Student::showdata() 
{
	cout << endl << endl << "Admission Number: " << admno << endl;
	cout << "Student Name: ";
	puts(sname);

	for (int i = 0; i < 5; i++) {
		cout << "Marks in subject " << i + 1 << ": " << mark[i] << endl;
	}

	cout << "Total marks: " << total << endl;

	cout << "Average marks: " << calculate() << endl;
}

//*************************

//long count = 0;

//*************************

void main() 
{
	clrscr();
	int rep = 1;
	Student s;


		s.takedata();

		cout << "Show Data? " << endl;
		system("pause");

		s.showdata();

	    
	    
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
	    
    
    cout<<"NORMAL EXIT"<<endl;
    getch();
}