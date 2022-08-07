#include<iostream.h>
#include<conio.h>
#include<process.h>

//*************************************************************

long column_product(int a[50][50], int r, int c){
	long product=1;
	for(int i=0; i<r; i++){
		product*=a[i][c];
	}
	return product;
}

//************************************************************

long row_product(int a[50][50], int r, int c){
	long product=1;
	for(int i=0; i<c; i++){
		product*=a[r][i];
	}
	return product;
}

//************************************************************

long count=0;

//************************************************************

int main(void){
	int rep=1;

	while(rep==1){
		clrscr();

		int r, c;
		int a[50][50];
		int r_prod, c_prod;

		cout<<"Enter the number of rows"<<endl;
		cin>>r;
		cout<<"Enter the number of columns"<<endl;
		cin>>c;

		if(r>50||c>50){
			cout<<endl<<"Overflow"<<endl;

			getch();

			exit(0);
		}

		cout<<"Enter the array elements:"<<endl;

		for(int i=0; i<r; i++){
			cout<<"Row "<<i+1<<": "<<endl;

			for(int j=0; j<c; j++){
				cout<<"Column "<<j+1<<": ";

				cin>>a[i][j];
			}

		}

		cout<<"The matrix is as follows: "<<endl;

		for(int k=0; k<r; k++){

			for(int l=0; l<c; l++){
				cout<<a[k][l]<<"  ";
			}

			cout<<endl;
		}

		for(int m=0; m<r; m++){
			r_prod=row_product(a,m,c);
			cout<<"Product of Row "<<m+1<<" = "<<r_prod<<endl;
		}

		for(int n=0; n<c; n++){
			c_prod=column_product(a,r,n);
			cout<<"Product of Column "<<n+1<<" = "<<c_prod<<endl;

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