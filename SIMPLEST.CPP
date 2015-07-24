// Simplest Protocol in Noiseless Channel

//If you run it more no. of loops it may show graphic error, test it for less no. of turns

#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include <graphics.h>
#include <stdlib.h>
#include<stdio.h>

void disp();

//Sender site Functions

void getData();   	// Getting Data
void makeFrame();       // Preparing Frame
void sendFrame();       // Sending frame to Receiver

//Reciever site functions
void RecieveFrame();    // Receive Frame
void ExtractData();     // extract Info
void DeliverData();     //Deliver to higher layer

int main()
{
   int totframe=0;

 for(int i=0;i<2;i++)
 {
	totfame++;

	 getData();
	 delay(270);
	 getch();

	makeFrame();
	delay(270);
	getch();

	sendFrame();

	RecieveFrame();
	getch();

	ExtractData();
	getch();

	DeliverData();
	getch();


	gotoxy(4,20);
	cout<<endl<<"Frame "<<totframe<<" sent";
	getch();

  }

gotoxy(21,20);
cout<<"Total Frame sent :  "<<totframe;

getch();
closegraph();
return 0;

}

void getData()
{

for(int i=0;i<3;i++)
{
	disp();
	gotoxy(30,16);
	cout<<"Preparing data";

	    for(int j=0;j<5;j++)

	    {

		    cout<<"."  ;
		    delay(300);
	    }

		 closegraph();
		 delay(45);

		 clrscr();


} //end of outer for loop

		disp();

     gotoxy(30,16);
     cout<<"Data prepared";


} // end of getdata


void disp()
{
/* request auto detection */
int gdriver = DETECT, gmode, errorcode;
int xmax, ymax;

/* initialize graphics and local variables */
initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

/* read result of initialization */
errorcode = graphresult();
/* an error occurred */
if (errorcode != grOk)
{
   printf("Graphics error: %s\n", grapherrormsg(errorcode));
   printf("Press any key to halt:");
   getch();
   exit(1);
}

//Sender Side

rectangle(75,80,165,210);
// Get Data
line(75,120,165,120);
//Send Frame

line(75,175,165,175);

line(120,115,120,125);
line(120,172,120,182);
line(120,210,120,230);


line(120,230,520,230);
gotoxy(7,4);
cout<<"Sender";

gotoxy(70,4);
cout<<"Receiver";

gotoxy(1,7);
cout<<"Network";

gotoxy(12,7);
cout<<"Get data" ;

gotoxy(1,9);
cout<<"Data Link";

gotoxy(1,12);
cout<<"Physical";

gotoxy(11,13);
cout<<"Send frame";

//--------------------//




//Reciever
rectangle(475,80,565,210);
line(475,120,565,120);
line(475,175,565,175);


line(520,115,520,125);
line(520,172,520,182);
line(520,210,520,230);

gotoxy(72,7);
cout<<"Network";

gotoxy(61,7);
cout<<"Delvr data" ;

gotoxy(72,9);
cout<<"Data Link";

gotoxy(72,12);
cout<<"Physical";

gotoxy(61,13);
cout<<"Recv frame";

}//end of disp

void makeFrame()
{
	for(int i=0;i<3;i++)
	{
	disp();
	gotoxy(30,16);
	cout<<"Making Frame";


		for(int j=0;j<5;j++)
		{

		    cout<<"."  ;
		    delay(300);
		}

		 closegraph();
		 delay(45);
		 clrscr();


	}

		disp();

     gotoxy(30,16);
     cout<<"Frame Ready";



}//end of makeframe

void sendFrame()

{

	for(int i=1;i<7;i+=3)
	{

		disp();
		gotoxy(25+(i*i),14);
		cout<<"->->";
		gotoxy(25+(i*i),13);
		cout<<"data";

		delay(600);
	}

closegraph();
clrscr();
disp();

}// end of send frame

void RecieveFrame()
{
	for(int i=0;i<3;i++)
	{
	disp();
	gotoxy(30,16);
	cout<<"Recieveing Frame from physical Layer";

		for(int j=0;j<5;j++)
		{

		    cout<<"."  ;
		    delay(300);
		}

		 closegraph();
		 delay(45);
		 clrscr();
	}

		disp();
		gotoxy(30,16);
		cout<<"Frame Recieved ";

} // end of ReceiveFrame

void ExtractData()
{

for(int i=0;i<3;i++)
{
	disp();
	gotoxy(30,16);
	cout<<"Extracting Data from Frame ";

	for(int j=0;j<5;j++)
	{
	    cout<<"."  ;
	    delay(300);


	}
		 closegraph();
		 delay(45);
		 clrscr();

}

		disp();
		gotoxy(30,16);
		cout<<"Extraction Complete. ";


} // End of Extract data

void DeliverData()
{
	for(int i=0;i<3;i++)
	{
		disp();
		gotoxy(30,16);
		cout<<"Delivering Data to Network layer ";

		for(int j=0;j<5;j++)
		{
			cout<<"."  ;
			delay(300);
		}
		 closegraph();
		 delay(45);
		 clrscr();


	}

		disp();
		gotoxy(30,16);
		cout<<"Data Delieverd. ";

}//End of Deliver Data

//Program by Mohd Monis