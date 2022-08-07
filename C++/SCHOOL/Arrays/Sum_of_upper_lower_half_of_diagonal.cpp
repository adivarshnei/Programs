#include<iostream.h>
#include<conio.h>
#include<process.h>

long count=0;

int main(void){
	int rep=1;
	
	while(rep==1){
		clrscr();
		
		int arr[3][3];
		int usum=0, lsum=0;

		cout<<"Enter the elements of the matrix (row-wise)"<<endl;

		for(int i=0; i<3; i++){

			for(int j=0; j<3; j++){
				cin>>arr[i][j];
			}

		}

		for(int k=0; k<3; k++){

			for(int l=0; l<3; l++){
				
				if(l<k){
					lsum+=arr[k][l];
				}

				if(k<l){
					usum+=arr[k][l];
				}

			}

		}

		cout<<endl<<"The matrix is as follows:"<<endl;

		for(int m=0; m<3; m++){

			for(int n=0; n<3; n++){
				cout<<arr[m][n]<<'\t';
			}

			cout<<endl;
		}

		cout<<"The sum of the upper diagonal elements: "<<usum<<endl;
		cout<<"The sum of the lower diagonal elements: "<<lsum<<endl;

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