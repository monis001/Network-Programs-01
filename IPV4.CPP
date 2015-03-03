#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<math.h>

int bin[8];

int chck(int arr[],int size);
void binary(int num);
void classes(int num,int arr[]);

void dec(int arr[]);
void binchck(int arr[]);

void main()
{
	clrscr();
	int point[4],chk;
	int arr[32],cnt=32,size=0;
	int m=0,chc=0;

	cout<<endl<<"\n\t\t 1.  Enter Decimal Values ";
	cout<<endl<<"\n\t\t 2.  Enter Binary Values ";
	cout<<endl<<endl<<"\t\t\t Your choice (1-2) : ";
	cin>>chc;

	switch(chc)
	{
		case 1:
		clrscr();
			for(int i=0;i<4;i++)
		{
			cout<<"Enter "<<i+1<<" Part : ";
			cin>>point[i];

		}

	       cout<<"\nIP address is  :\n";

		 for(i=0;i<4;i++)
		 {
			cout<<point[i];
			if(i<3)
			{
				cout<<"." ;
			}
		}

	chk=chck(point,4);

	if(chk==0)
	{
		cout<<"Exiting ";
		exit(0);
	}
	else
	{
		cout<<"\t\tIP address eneterd is in a correct format : ";
		cout<<"\n\n\nBinary equivalent :\n ";
		binary(point[0]);
		cout<<" ";
		binary(point[1]);
		cout<<" ";
		binary(point[2]);
		cout<<" ";
		binary(point[3]);
		 cout<<endl<<endl;
		classes(point[0],arr);
	}



		break;

		case 2:
		 clrscr();
		cout<<"Enter the binary values for : ";
		for(int k=0;k<32;k++)
		{
			cnt--;
			gotoxy(61,2);
			cout<<cnt;
			gotoxy(2,4);
			cin>>arr[size];
			gotoxy(4,8);
			cout<<"You have entered ";
			gotoxy(11+m,10);
			cout<<arr[size];
			  m++;
			size++;
		}

		dec(arr);  // binary to decimal
		cout<<endl<<endl;
		binchck( arr);  //checking classes

		break;

	  }

	getch();

}

int chck(int arr[],int size)
{

	for(int i=0;i<size;i++)
	{


		if(arr[i]>255)
		{
		      cout<<"\nWrong IP address entered in "<<i+1<<" part, cannot exceed 255 ";
		      getch();
		      return(0);
		}
	}

	return(1);

}
void binary(int num)
{
	int i=8,temp,k=8;


	while(i!=0)
	{
	     if(num!=0)
	     {
	       k--;

	     temp=num%2;
	     bin[k]=temp;

	     num=num/2;
	     }

	   else  if(num==0)
	     {    	k--;

		bin[k]=0;



	     }

	     i--;




	}
	  for(i=0;i<8;i++)
	  {
		cout<<""<<bin[i];
	  }
}

void classes(int num,int arr[])
{

			if(num>1 && num< 128)
	     {
		cout<<"The following IP address belongs to Class A \n";
		cout<<num<<" is the  net id  and remaining host";
	     }
	    else if(num>127 && num< 192)
	     {
		cout<<"The following IP address belongs to Class B\n";
		cout<<num<<" "<<arr[1]<<" is the  net id and remaining host id";
	     }

	   else  if(num>191 && num< 224)
	     {
		cout<<"The following IP address belongs to Class C\n";
		cout<<num<<" "<<arr[1]<<" "<<arr[2]<<" is the net id  and remaining host id";
	     }
	  else   if(num>223 && num< 240)
	     {
		cout<<"The following IP address belongs to Class D";
	     }

	  else   if(num>239 && num< 257)
	     {
		cout<<"The following IP address belongs to Class E";
	     }


}

void dec(int arr[])
{
    int num,powr,k=0;
    cout<<endl;
    for(int i=0;i<4;i++)
    {
	powr=7;
	num=0;

	for( k=8*i;k<8*(i+1);k++)
	{
		    num=num+ (arr[k]*pow(2,powr));
		powr--;


	}
	cout<<endl<<i+1<<" Octet is : "<<num;

    }


}
void binchck(int arr[])
{

int i=0,cnt0=0;

if(arr[0]==0 && (arr[1]==0 || arr[1]==1))
		{
			gotoxy(17,17);
			cout<<"This is Class A address ";

		}

		else
		{
			i=0;
			while(arr[i]!=0)
			{
				cnt0++;
				i++;
			}


		}

		switch(cnt0)
		{
		   case 1:
		   gotoxy(17,17);
		   cout<<"This is Class B address ";
		   break;

		   case 2:
		   gotoxy(17,17);
		   cout<<"This is Class c address ";
		   break;

		   case 3:
		   gotoxy(17,17);
		   cout<<"This is Class D address ";
		   break;

		   case 4:
		   gotoxy(17,17);
		   cout<<"This is Class E address ";
		   break;
		   case 8:
		   gotoxy(17,17);
		   cout<<"This is Class E address ";

		   break;



		}

}