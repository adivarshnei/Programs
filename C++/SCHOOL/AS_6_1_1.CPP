#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<stdio.h>

int count=0,d;

/*
Define a class account with the data members account no, name, and balance amount.
The class should contain member functions to do the following.
-	To accept and display data members
-	For transaction, where the function should take the type of transaction (d for deposit /w for withdrawal)
 and  the transaction amount as parameter and update the balance amount. The function should return 1 
 if the transaction is successful otherwise for unsuccessful transaction, it should return 0. 
 The transaction will be unsuccessful if after withdrawal the balance is less than 1000 and 
 in that case balance will not be updated.
Also display the total withdrawal and total deposit made by all account holders. 
Use the above given operations in an object array of size 5.

*/

//*****************************************************************************************

class account
{
	private:
		char name[20];
	double transaction_amount;
		double balance_amount;

	public:
		int account_no;
		void enter_data();
		void show_data();
		int transaction(char,double);
		double withdraw_count(double);
		double deposit_count(double);
		int wsum;
		int dsum;

};

//*******************************************************************************************

int wsum=0;
int dsum=0;
void account::enter_data()
{
	cout<<"enter the account number\n";
	cin>>account_no;
	cout<<"enter the name of the account holder\n";
    gets(name);
    cout<<"enter the balance amount in the account\n";
    cin>>balance_amount;
}

//*****************************************************************************************

void account::show_data()
{
    cout<<"account number:  "<<account_no<<endl;
    cout<<"name of the account holder:  "<<name<<endl;
    cout<<"balance in the account:  "<<balance_amount<<endl;
    cout<<"amount of withdraws:  "<<wsum<<endl;
    cout<<"amount of deposits:  "<<dsum<<endl;

}

//***************************************************************************************

double account::withdraw_count(double n)
{


    wsum+=n;
    return wsum;
}

//**************************************************************************************

double account::deposit_count(double n)
{


    dsum+=n;
    return dsum;
}

//**************************************************************************************

int account::transaction(char n,double t)
{
    if(n=='d')
    {
        balance_amount+=t;
        deposit_count(t);
        return 1;
    }

    if(n=='w')
    {
        double x=balance_amount-t;
        if(x<1000)
        {

            return 0;
        }

        if(x>=1000)
        {
	    balance_amount-=t;
            withdraw_count(t);
            return 1;
        }
    }
}

//*******************************************************************************************

void main()
{
    char rep='1';

    while(rep=='1')
    {
	    clrscr();

	account a[5];

	for(int i=0;i<5;i++)
	{
	    a[i].enter_data();
	}
	do
        {
            
	    int ch;
                cout<<"1.update in account\n";
            
            cout<<"2.exit to main menu\n";
            cout<<"enter your choice\n";
            cin>>ch;

            switch(ch)
            {
            case 1:
                    char h;
                    int s;
                    cout<<"for which account do you want to update(enter account number):\n";
		    cin>>s;
                    for(int i = 0; i < 5; i++)
                    {
			if(s==a[i].account_no);
			{

			    cout<<"do you want to withdraw money(press w) or deposit money(press d)\n";
			    cin>>h;
		    int am;
		    cout<<"enter the amount:\n";
		    cin>>am;
		    int x;
		    x=a[i].transaction(h,am);
		    if(x==0)
		    {
			cout<<"transaction unsuccesful due to less amount of balance\n";
		    }

		    if(x==1)
		    {
			cout<<"transection successful\n";
		    }
		    }
		    goto ex;
		    }
		    ex:
		    break;

	    case 2:
                    goto label;
		    break;

            default:
                    cout<<"wrong choice entered.try again\n";

            }
        }while(1);
        label:

	cout<<"information of the the accounts:\n";
       for(i=0;i<5;i++)
       {
        a[i].show_data();
        system("pause");
       }
        
	    
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