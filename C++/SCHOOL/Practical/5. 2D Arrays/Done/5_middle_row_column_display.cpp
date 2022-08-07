#include<iostream.h>
#include<conio.h>
#include<process.h>

long count=0;

int main(void){
	int rep=1;

	while(rep==1){
		clrscr();

		int r, c;
		int a[50][50];

		cout<<"Enter the number of columns of the matrix (even numbers will be incremented by one)"<<endl;
		cin>>c;

		if(c>50){
			cout<<endl<<"Overflow"<<endl;

			getch();

			exit(0);
		}

		if(c%2==0){
			++c;
		}

		cout<<"Enter the number of rows of the matrix (even numbers will be incremented by one)"<<endl;
		cin>>r;

		if(r>50){
			cout<<endl<<"Overflow"<<endl;

			getch();

			exit(0);
		}

		if(r%2==0){
			++r;
		}

		cout<<"Enter the matrix elements"<<endl;

		for(int i=0; i<r; i++){
			cout<<"Row "<<i+1<<": "<<endl;

			for(int j=0; j<c; j++){
				cout<<"Column "<<j+1<<": ";

				cin>>a[i][j];
			}

		}

		cout<<"The matrix is as follows:"<<endl;

		for(int x=0; x<r; x++){

			for(int y=0; y<c; y++){
				cout<<a[x][y]<<"\t";
			}

			cout<<endl;
		}


		cout<<endl<<"Middle Row: ";

		for(int k=0; k<c; k++){
			cout<<a[((r+1)/2)-1][k]<<"  ";
		}

		cout<<endl<<"Middle Column: ";

		for(int l=0; l<r; l++){
			cout<<a[l][((c+1)/2)-1]<<"  ";
		}

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