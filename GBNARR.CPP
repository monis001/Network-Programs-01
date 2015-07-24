//Go back Automatic Repeat Request 

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>   //for power function
#include<dos.h>
#include<time.h>
#include<stdio.h>

//sn denotes sequence number
int ackno=0,flagack=0;
void getdata();
void makeframe(int sn);
void storeframe(int sn);
void sendframe(int sn, int &sn1) ;
void starttimer(int sn,int &sf);

int Reciever(int sn);
int Recieve(int sn);
void deliverData(int sn);

void main()
{
	int sw,sf=0,sn=0;
	int cnt=0,start=1,evnt;
	sw=pow(2,4)-1;
	clrscr();
	while(start)
	{

		time_t t;

		srand((unsigned) time(&t));
	    
	    //	evnt=rand() % 3;     // You can make it dynamic using rand() function and according to it change it further
		
		evnt=0 ;  //static value 					
		cnt++;
		delay(1000);
		gotoxy(21,2);
	    //	cout<<cnt;
	    //	cout<<endl<<evnt;
		if(cnt==5)
		{
			start=0;
		}

		if(evnt==0)
		{
			if(sn-sf>=sw)  //if window is full
			{
			    break;
			}
			else    	//window is not full
			{
			     getdata();
			     makeframe(sn);
			     storeframe(sn);
			     sendframe(sn, sn);
			   //  gotoxy(21,9);
			   //  cout<<"sn is "<<  sn;
			   starttimer(sn-1,sf);
			}


		}
		else if(evnt!=0)
		{
			gotoxy(21,4);
			cout<<"No request from the upper layer ";
			delay(800);
			clrscr();
		}

		delay(1000);
		gotoxy(61,24);
		cout<<"Next Loop ";
		getch();

	}



	getch();


}

void getdata()
{
	gotoxy(21,2);
	cout<<"Getting Data ";
	delay(700);
	gotoxy(21,2);
	cout<<"data ready....";

}
void makeframe(int sn)
{

	gotoxy(21,3);
	cout<<"Making frame "<<sn;



}
void storeframe(int sn)
{
	gotoxy(21,5);
	cout<<"[ Storing Frame "<<sn<<" ]" ;


}

void sendframe(int sn, int &sn1)
{
	sn1=sn1+1;
	gotoxy(21,7);
	cout<<" Sending Frame "<<sn<<" to reciever ";

}

void starttimer(int sn,int &sf)
{
	int cnt=0,flag=1,getack;
	gotoxy(21,22);
	cout<<"Starting Timer " ;
	while(flag)
	{
		 struct dostime_t t;
		_dos_gettime(&t);
		gotoxy(21,23);
		 printf(" %2d:%02d:%02d\n", t.hour, t.minute,t.second);
			cnt++;



		delay(1000);
		if(cnt==5)
		{
			flag=0;
		}

		getack=Reciever( sn);
		if(getack==10)
		{
			gotoxy(21,13);
			cout<<"Have to Resend ";
			return;
		}

		 if(getack==1) // 1 tells that acknowledgemt received is corrupted
		 {
			gotoxy(21,15);
			cout<<"Acknowledgement not Receieved";
			getch();
			return;

		 }

		 else
		 {
		      if((ackno>sf)&&(ackno<=sn))
		      {
				gotoxy(21,15);
				cout<<"valid Acknowledgement ............";

			while(sf<=ackno)
			{
				sf=sf+1;
			}


		    }


		 }

	 }

}

int Reciever(int sn)
{
	int rn=0, true=1,evnt,frmstat,ack;

		time_t t;

		srand((unsigned) time(&t));
		evnt=rand() % 3;

		if(evnt==1) // 1 denotes successful arrival of frame
		{
			frmstat=Recieve(sn);
			if(frmstat ==1)
			{
				gotoxy(21,12);
				cout<<"Corrupted Frame ";
				return (10);
			}
			else    // Receive frame is not corrupted
			{
				if(sn==rn)   // if recieved frame is same what send frame is
				{
				     deliverData(sn);
				     rn=rn+1;
				     gotoxy(21,13);
				     cout<<"Sending Acknowledgement ";
				     randomize();
				    ack=random(1);

				    if(flagack==0)    //for very first frame
				    {
					flagack++;
					ackno++;
				    }
				    if(flagack>0)
				    {
					ackno++;
				    }
				    return(ack);

				}
			}

		}


 return(0);

}


int Recieve(int sn)
{
	gotoxy(21,11);
	cout<<"Receiveing Frame "<<sn;
	delay(1000);
	gotoxy(21,11);
	cout<<"Frame Receieved .. .. . .";

		time_t t;

		srand((unsigned) time(&t));
		return (rand() % 1);



}

void deliverData(int sn)
{
	gotoxy(21,12);
	cout<<"Delivering Data ";
	delay(1000);
	gotoxy(21,12);
	cout<<"Deliver Data......." ;

}