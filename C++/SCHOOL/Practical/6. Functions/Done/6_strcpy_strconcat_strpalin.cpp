#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<stdio.h>

typedef char strcopy;
typedef char strconcat;
typedef char strpalin;

void str1to2(strcopy *str1){
	strcopy *str2;

	for(int i=0; str1[i]!='\0'; i++){
		str2[i]=str1[i];
	}

	cout<<"Copied string: ";
	
	puts(str2);

}

void strcnct(strconcat *str1, strconcat *str2){
	strconcat *str3;

	for(int i=0; str1[i]!='\0'; i++){
		str3[i]=str1[i];
	}

	for(int j=0; str2[j]!='\0'; j++){
		str3[i+j]=str2[j];
	}

	cout<<"Concatenated string: ";

	puts(str3);

}

void strpalindrome(strpalin *str1){
	strpalin *str2;
	int cmp;
	int n=strlen(str1);

	for(int j=0; str1[j]!='\0'; j++){
		str2[j]=str1[n-(j+1)];
	}

	cmp=strcmp(str1, str2);

	if(cmp==0){
		cout<<"String is a palindrome";
	}

	else{
		cout<<"String is not a palindrome";
	}
	
}

long count=0;

int main(void){
	int rep=1;
	
	while(rep==1){
		clrscr();

		int choice;
		
		option:
		cout<<"1. Copy one string to another"<<endl;
		cout<<"2. Concatenate two strings"<<endl;
		cout<<"3. Check string for palindromality"<<endl;
		cin>>choice;

		switch(choice){

			case 1:
				strcopy *a;

				cout<<"Enter the string: ";
				gets(a);
				
				str1to2(a);

				break;

			case 2:
				strconcat *b, *c;

				cout<<"Enter the two strings: ";
				gets(b);
				gets(c);

				strcnct(b,c);

				break;

			case 3:
				strpalin *d;

				strpalindrome(d);
				
				break;

			default:
				cout<<"Wrong Choice"<<endl;
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