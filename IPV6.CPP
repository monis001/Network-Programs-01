#include<iostream.h>
#include<conio.h>
#include<ctype.h>
void main()
{
	clrscr();
	char ch[39],ch1[39];
	int j=0,cnt=0,temp=0,temp1=0,flag=0,pos[7],m=0,k=0;

	cout<<"Enter the Hexadecimal no. :" ;
// loop for entering Ipv6 in hexa form

	for(int i=0;i<39;i++)
	{
		gotoxy(17,3);
		cin>>ch[i];
		gotoxy(21,5);
		cout<<"You have entered ";
		gotoxy(11+i,7);
		ch[i]=toupper(ch[i]);
		cout<<ch[i];


	}

//loop for checking continuous zeroes

	  for(i=0;i<39;i++)
	  {
		  if((ch[i]==':' && ch[i+1]=='0') ||(ch[0]=='0'))   //checking : and adjacent 0
		  {
			temp1=i+1;

			for(int k=temp1;k<temp1+4;k++)
			{
				if(k==i+1)  // telling : and 0 matched
				{
				  flag=0;
				}

				if(ch[k]=='0'&& flag==0) // checking continuous zeroes
				{
				   //	cout<<"\n matched at "<<k<<" Value  "<<ch[k];
					temp++;  // counting no. of zeroes
				}

				else
				{
				       //  cout<<"\nnot matched at "<<k<<" value  "<<ch[k];
					flag=1;     //if not matched to come out
					temp=0;     //making counter 0
					continue;
				}

			}

			if(temp==4)  //if there are continuous 4 zeros
			{
			     pos[cnt]=temp1; //storing starting position of 0
			     cnt++;  // counting such sets
			     flag=0;
			     temp=0;   // making counter 0 for next set


			}
		  }




	  }

	      m=cnt*2; // hepful in decideing the size of aaray

	       flag=1;  // making flag true
	       temp=0;  //temp to 0
	       m=39-m;  //setting new values for m


	 i=0,j=0,k=0;


	 while(flag)         // assigning values to new array
	 {
	    ch1[i]=ch[j];

	    i++;
	    j++;


	    if(pos[k]==j)
	    {

		j=j+4;
		ch1[i]='0';



		i++;
		k++;

	    }




	      if(i==m|| j==39)
	      {

		flag=0;
	      }


	 }


cout<<endl<<endl;

for(i=0;i<m-cnt;i++)
{
	cout<<" "<<ch1[i];
}
		      int z=1,num,posn=0;

     for(i=0;i<cnt;i++)
	       {

		      if(pos[i]+5==pos[i+1])
		      {     z++;
		     num=pos[i];



		      }

		      if(z>2 && (pos[i]+5!=pos[i+1]))
		      {
			break;
		      }





	       }


	       cout<<endl<<"Continuous zeroes sets are :  "<<z;
		posn=z-2;


			cout<<endl<<endl;
			temp=num;
			 temp=temp-(5*posn);


			if(z>1)
			{
				for(i=0;i<39;i++)
				{
				     if(i!=temp)
				     {
					 cout<<" "<<ch[i];
				      }

				    if(i==temp)
				    {
				       ch[temp]=':';
				       cout<<ch[temp];

				      i=num+9;

				    }



				}


			}




	getch();

}