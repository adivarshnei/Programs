#include<iostream.h>
#include<conio.h>
#include<process.h>

typedef int add;
typedef int uptriadd;
typedef int transpose;

void addition(int **a, int **b, int n){
	int **arr3;

	cout<<"Added array: "<<endl;
	
	for(int i=0; i<n; i++){
		
		for(int j=0; j<n; j++){
			arr3[i][j]=a[i][j]+b[i][j];
			cout<<arr3[i][j]<<'\t';
		}

		cout<<endl;
	}

}
void utrisum(int **a, int n){
	
	int usum;
	
	for(int k=0; k<n; k++){

		for(int l=0; l<n; l++){

			if(k<l){
				usum+=a[k][l];
			}

		}

	}

	cout<<"Sum of upper triangle elements: "<<usum;
}

void transpose(int **a, int n){

	int **b;

	for(int k=0; k<n; k++){

		for(int l=0; l<n; l++){
			b[l][k]=a[k][l];
		}

	}

	cout<<"Transposed Matrix:";

	for(int p=0; p<n; p++){
		
		for(int q=0; q<n; q++){
			cout<<b[p][q]<<"\t";
		}

		cout<<endl;
	}

}

long count=0;

int main(void){
	int rep=1;
	
	while(rep==1){
		clrscr();

		int **a, **b, **c;
		int n, choice;

		cout<<"Enter the limit of the square matrices: ";
		cin>>n;

		cout<<"1. Add two entered matrices"<<endl;
		cout<<"2. Printing the sum of upper triangular elments of one matrix"<<endl;
		cout<<"3. Printing Transpose of an array"<<endl;
		cin>>choice;

		cout<<"Input array 1:"<<endl;

		for(int i=0; i<n; i++){
			cout<<"Row "<<i+1<<": "<<endl;

			for(int j=0; j<n; j++){
				cout<<"Column "<<j+1<<": ";

				cin>>a[i][j];
			}

		}

		switch(choice){
			
			case 1:
				cout<<"Input array 2:"<<endl;

				for(int k=0; k<n; k++){
					cout<<"Row "<<k+1<<": "<<endl;

					for(int l=0; l<n; l++){
						cout<<"Column "<<l+1<<": ";

						cin>>b[k][l];
					}

				}

				addition(a, b, n);

				break;
			
			case 2:
				utrisum(a,n);
				break;
			
			case 3:
				transpose(a, n);
				break;
			
			default:
				cout<<"Wrong Choice";
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