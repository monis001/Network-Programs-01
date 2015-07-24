//Leaky Bucket Example
//representation of Leaky Bucket

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>
#include<iostream.h>

void elipse();


int main(void)
{
clrscr();
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy;

   int size, rad,num=20,val;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi"); //change path according to ur system path

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

   setcolor(getmaxcolor());

 cout<<"Enter the size of packet : (e.g. 16/32/64/128) : ";
 cin>>size;
  switch(size)
  {
	case 16:
	rad=5;
	break;
		case 32:
	rad=7;
	break;

		case 64:
	rad=9;
	break;

		case 128:
	rad=11;
	break;

	default:
	cout<<"Wromg Choice : ";
	rad=2;


  }


   for(int i=0;i<50;i++)
   {
	clrscr();
	 circle(100, 20+i, rad);
	 circle(100,45+i,rad);
	 circle(100,70+i,rad);
	 circle(100,95+i,rad);

	   elipse();



delay(100);
   }
    getch();
    clrscr();

   randomize();
   val=(rand() % 5);
   if(val==0)
   {
	cout<<"\n All packets can be sent ";
   }
   if(val==1)
   {
	cout<<"\n There is an overflow ";
   }
   if(val==2)
   {
	cout<<"\n All packets can be sent ";
   }
   if(val==3)
   {
	cout<<"\n There is an overflow ";
   }
if(val==4)
   {
	cout<<"\n All packets can be sent ";
   }
   if(val==5)
   {
	cout<<"\n There is an overflow ";
   }



   /* clean up */
   getch();
   closegraph();
   return 0;
}

void elipse()
{
   int stangle=0, endangle=360;

	  /* drawing bucket */
   ellipse(100, 100, stangle, endangle,
	   40, 20);
	  line(60,100,60,190);
	  line(140,100,140,190);
   ellipse(100, 190, stangle, endangle,
	   40, 20);


}