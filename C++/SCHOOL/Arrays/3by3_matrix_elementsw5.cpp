#include<iostream.h>
#include<conio.h>
#include<process.h>

long count=0;

int main(void){
	int rep=1;
	
	while(rep==1){
		clrscr();
		
		int arr[3][3];

		cout<<"Enter the elements of the 3X3 matrix (row-wise)"<<endl;

		for(int i=0; i<3; i++){

			for(int j=0; j<3; j++){
				cin>>arr[i][j];
			}

		}

		cout<<endl<<"The matrix is as follows: "<<endl;

		for(int k=0; k<3; k++){

			for(int l=0; l<3; l++){
				cout<<arr[k][l]<<'\t';
			}

			cout<<endl;
		}

		cout<<endl;

		for(int m=0; m<3; m++){

			for(int n=0; n<3; n++){

				if((arr[m][n]%10)==5){
					cout<<"Element '"<<arr[m][n]<<"' of row "<<m+1<<" and column "<<n+1<<" ends with 5"<<endl;
				}

			}

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