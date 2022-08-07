#include<iostream.h>
#include<conio.h>
#include<process.h>

typedef long int gr;
typedef long int asc;
typedef long int rev;

gr greatest(gr *a, int n){
	gr max=a[0];

	for(int i=0; i<n; i++){

		if(a[i]>max){
			max=a[i];
		}

	}

	return max;
}

void ascending(asc *a, int n){
	int temp;

	for(int i=0; i<n; i++){

		for(int j=i+1; j<n; j++){

			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}

		}

	}

	cout<<endl<<endl<<"Array in Ascending Order: ";

	for(int l=0; l<n; l++){
		cout<<a[l]<<" ";
	}

}

void reverse(rev *a, int n){
	rev b[50];

	for(int j=0; j<n; j++){
		b[j]=a[n-(j+1)];
	}

	cout<<endl<<"Initial array:\t";

	for(int k=0; k<n; k++){
		cout<<a[k]<<' ';
	}

	cout<<endl<<endl<<"Reversed array:\t";

	for(int m=0; m<n; m++){
		cout<<b[m]<<' ';
	}

}

long count=0;

int main(void){
	int rep=1;
	
	while(rep==1){
		clrscr();

		int choice, n;

		option:
		cout<<"1. Greatest Value in array"<<endl;
		cout<<"2. Sort elements of array in ascending order"<<endl;
		cout<<"3. Reverse elemnts of array"<<endl;
		cin>>choice;

		cout<<endl<<"Enter the limit of the array: ";
		cin>>n;

		switch(choice){
			case 1:
				gr *a;
				cout<<"Enter the array: "<<endl;

				for(int i=0; i<n; i++){
					cin>>a[i];
				}

				gr max=greatest(a,n);

				cout<<"Largest element in array: "<<max<<endl;

				break;

			case 2:
				asc *b;
				cout<<"Enter the array: "<<endl;

				for(i=0; i<n; i++){
					cin>>b[i];
				}

				ascending(b,n);

				break;

			case 3:
				rev *c;
				cout<<"Enter the array: "<<endl;

				for(i=0; i<n; i++){
					cin>>c[i];
				}

				reverse(c,n);

				break;

			default:
				cout<<"Wrong choice"<<endl;
				goto option;
				break;

		}
		
		cout<<endl<<endl<<"Repeat Program?"<<endl;
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