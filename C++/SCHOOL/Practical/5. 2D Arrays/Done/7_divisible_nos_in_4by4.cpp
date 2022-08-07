#include<iostream.h>
#include<conio.h>
#include<process.h>

long count=0;

int main(void){
	int rep=1;
	
	while(rep==1){
		clrscr();
		
		int a[4][4];
		int n;

		cout<<"Enter the matrix elements"<<endl;

		for(int i=0; i<4; i++){
			cout<<"Row "<<i+1<<": "<<endl;

			for(int j=0; j<4; j++){
				cout<<"Column "<<j+1<<": ";

				cin>>a[i][j];
			}

		}

		cout<<endl<<"Matrix is as follows: "<<endl;

		for(int x=0; x<4; x++){

			for(int y=0; y<4; y++){
				cout<<a[x][y]<<"\t";
			}

			cout<<endl;
		}

		cout<<endl;

		cout<<"Enter a number"<<endl;
		cin>>n;

		cout<<endl;

		for(int k=0; k<4; k++){

			for(int l=0; l<4; l++){

				if(a[k][l]%n==0){
					cout<<a[k][l]<<", ";
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