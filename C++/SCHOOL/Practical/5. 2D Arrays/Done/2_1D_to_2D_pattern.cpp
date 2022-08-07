#include<iostream.h>
#include<conio.h>
#include<process.h>

long count=0;

int main(void){
	int rep=1;

	while(rep==1){
		clrscr();

		int n;
		int a[50];
		int b[50][50];

		cout<<"Enter the number of elements of the array"<<endl;
		cin>>n;

		if(n>50){
			cout<<endl<<"Overflow"<<endl;

			getch();

			exit(0);
		}

		cout<<"Enter the array elements"<<endl;

		for(int i=0; i<n; i++){
			cin>>a[i];
		}

		int o=1;

		for(int j=0; j<n; j++){
			
			for(int k=0; k<n; k++){
				b[j][k]=a[k];
				
				for(int l=o;l<n; l++){
					b[j][l]=0;
				}

			}

			o++;
		}

		cout<<"The entered array is as follows: ";

		for(int f=0; f<n; f++){
			cout<<a[f]<<"  ";
		}

		cout<<endl<<"The matrix is as follows: "<<endl;

		for(int m=0; m<n; m++){

			for(int p=0; p<n; p++){
				cout<<b[m][p]<<"  ";
			}

			cout<<endl;
		}

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