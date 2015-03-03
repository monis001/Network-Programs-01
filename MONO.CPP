#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
void main()
{
	clrscr();
	char ch[80];
	int x,key,y,value=64;
	cout<<"Enter the text (in CAPS) to be encrypted : ";
	gets(ch);
	x=strlen(ch);
	cout<<"Enter the key : ";
	cin>>key;
	cout<<endl<<endl<<"Cipher Text is : ";
	for(int i=0;i<x;i++)
	{

		y=ch[i];
		y+=key;
		if(y>90)
		{
			value+=(y-90);
			y=value;
			value=64;

		}
		ch[i]=y;
	       cout<<"\t"<<ch[i];
	}

	getch();

}