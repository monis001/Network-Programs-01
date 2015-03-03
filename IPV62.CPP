#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

char ch1[39];    //final array
int pos=0;     //global pointer

void initial(char arr[],int val);   // initial insertion till :
void insrtmid(int scnt1,char arr[]); // insertion of set of zeroes
void insertlast(char arr[],int fpos,int len);  //remaing insertion

void main()
{
	clrscr();
	char ch[30];
	int len,flag=0,m=0,n=0,pos1,dcnt=0,scnt=0,tval=0,fpos=0;
	cout<<endl<<endl<<" Enter the hexa number : ";
	gets(ch);
	 len=strlen(ch);

	 for(int i=0;i<len;i++)
	 {


	      if(ch[i]==':'&& ch[i+1]==':')
	      {

		flag=1;
		pos1=i;  //first occurence of ::
		 fpos=i+2;   // position of a number after ::

	      }
			else if(ch[i-1]!=':'&&ch[i]==':' && ch[i+1]!=':')
			{
				scnt++;
				cout<<"\n scnt is : "<<scnt;//checking single :
			}
	 }



			if(flag==1)
			{
				cout<<"\nFlag is true ";

				initial(ch,pos1);
				 insrtmid( scnt,ch);
			   //	 insertlast(ch,fpos,len);

			}







	  for(i=0;i<pos;i++)
	  {


		cout<<" "<<ch1[i];

	  }







	getch();



}

void initial(char arr[],int pos1)
{

	for(int i=0;i<=pos1;i++)
	{
		ch1[pos]=arr[i];
		pos++;
	}
}

void insrtmid(int scnt1,char arr[])
{
	int tval,cnt=0,i,k;

	tval=6-scnt1;  //how many insertion of sets of zeroes
	cout<<endl<<endl<<tval<<endl;

	k=4*tval+tval;

	 for(i=pos;i<k;i++)
	 {
	     ch1[pos]='0';
	     cnt++;
	      pos++;
	     if(cnt==4)
	     {
	     ch1[pos]=':';
	     cnt=0;
	     pos++;

	     }



	 }


	 cout<<endl<<"no. of loops to run : "<<k<<endl;
	cout<<endl<<" current position : "<<pos<<endl;


}

void insertlast(char arr[],int fpos,int len)
{

	 cout<<endl<<"position is : "<<arr[fpos-1]<<"\n\n";
		cout<<endl<<"Position is : "<<ch1[pos]<<endl;



	for(int i=fpos;i<len;i++)
	{
		ch1[pos]=arr[i];
		pos++;

	}


}
