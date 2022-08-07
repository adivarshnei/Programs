#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<math.h>

long factorial(int x){
	long fact=1;

	for(int i=x; i>1; i--){
		fact*=i;
	}

	return fact; 
}

long double series(int x, int n){
	int sign=-1;
	long double ser=0;

	for(int i=1; i<=n; i++){
		ser+=(sign*factorial((2*i)+1))/(pow(x,2*i));
		sign*=-1;
	}

	return ser;
}

long count=0;

int main(void){
	int rep=1;
	
	while(rep==1){
		clrscr();

		int x, n;
		long double sum;
		
		cout<<"Enter the value of x: ";
		cin>>x;
		cout<<"Enter the value of n: ";
		cin>>n;

		sum=series(x,n);

		cout<<endl<<"Sum of the series is "<<sum<<endl;
		
		cout<<endl<<"Repeat Program?"<<endl;
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