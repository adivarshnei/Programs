#include<iostream.h>
#include<conio.h>
#include<process.h>

long count=0;

int main(void){
	int rep=1;

	while(rep==1){
		clrscr();

		int a[3][3];

		cout<<"Enter the matrix elements"<<endl;

		for(int i=0; i<3; i++){
			cout<<"Row "<<i+1<<": "<<endl;

			for(int j=0; j<3; j++){
				cout<<"Column "<<j+1<<": ";

				cin>>a[i][j];
			}

		}

		cout<<"Original Matrix: "<<endl;

		for(int x=0; x<3; x++){

			for(int y=0; y<3; y++){
				cout<<a[x][y]<<"\t";
			}

			cout<<endl;
		}

		int temp;

		for(i=0;i<3;i++){

			for(int j=0;j<3;j++){

				if(i<j){
					temp=a[i][j];
					a[i][j]=a[j][i];
					a[j][i]=temp;
				}

			}

		}

		for(i=0;i<3;i++){

			for(int j=0;j<3;j++){
				temp=a[i][j];
				a[i][j]=a[j][i];
				a[j][i]=temp;
			}

		}

		cout<<"Final Matrix: "<<endl;

		for(int e=0; e<3; e++){

			for(int f=0; f<3; f++){
				cout<<a[e][f]<<"\t";
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