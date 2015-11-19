#include<fstream.h>
#include<time.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include"plane.cpp"
#include"airlines.cpp"
#include"shuttle.cpp"
int a;
class date
{
public:
 int dd,mm,yy;
};
float delay(float b)
{
	float sec;
	clock_t start,end;
	start=clock();
	a:

	end=clock();
	sec=(end-start)/CLK_TCK;
	if(sec>b)
		return sec;
	goto a;
}
class ticket
{
 public:
 int passengers;
 float price,total;
 date depart, arrive;
 char destination[30];
 char airline[30];
 char code[3];
 ticket()
 {
  strcpy(code," ");
 }
 void book_ticket();
};
ticket ABC;
void ticket::book_ticket()
{
 B:
 char choice;
 clrscr();
 gotoxy(25,3);
 ticket t;
 cout<<"Welcome to the Ticket Center !!!";
 gotoxy(10,6);
 cout<<"-> Enter the type of travel - ";
 gotoxy(15,7);
 cout<<"-> 1. One Way ";
 gotoxy(15,8);
 cout<<"-> 2. Round Trip";
 gotoxy(41,6);
 cin>>a;
 gotoxy(10,10);
 cout<<"-> Enter the number of passengers traveling - ";
 cin>>t.passengers;
 gotoxy(10,12);
 cout<<"-> Enter your destination - ";
 gets(t.destination);
 gotoxy(10,14);
 if(a==1)
 {
  cout<<"-> Enter the date of departure - ";
  cin>>t.depart.dd>>t.depart.mm>>t.depart.yy;
  gotoxy(20,18);
  cout<<"Press any key to continue ... ";
  getch();
  clrscr();
 }
 else if(a==2)
 {
  cout<<"-> Enter the date of departure - ";
  cin>>t.depart.dd>>t.depart.mm>>t.depart.yy;
  gotoxy(10,16);
  cout<<"-> Enter the date of arrival - ";
  cin>>t.arrive.dd>>t.arrive.mm>>t.arrive.yy;
  if(t.arrive.mm < t.depart.mm)
  {
	gotoxy(15,20);
	cout<<"Date of Arrival cannot be before Date of Departure !!!";
	gotoxy(33,21);
	cout<<"Try Again ";
	getch();
	goto B;
  }
  else if(t.arrive.yy < t.depart.yy)
  {
	gotoxy(15,20);
	cout<<"Date of Arrival cannot be before Date of Departure !!!";
	gotoxy(33,21);
	cout<<"Try Again ";
	getch();
	goto B;
  }
  gotoxy(20,20);
  cout<<"Press any key to continue ... ";
  getch();
  clrscr();
 }
 for(int i=0;i<3;i++)
 {
  gotoxy(18,10);
  cout<<"Please wait while flights are being processed ";
  gotoxy(35,12);
  cout<<"Loading .";
  delay(0.3);
  clrscr();
  gotoxy(18,10);
  cout<<"Please wait while flights are being processed ";
  gotoxy(35,12);
  cout<<"Loading ..";
  delay(0.3);
  clrscr();
  gotoxy(18,10);
  cout<<"Please wait while flights are being processed ";
  gotoxy(35,12);
  cout<<"Loading ...";
  delay(0.3);
  clrscr();
 }
 if(strcmpi(t.destination,"New Delhi")==0)
 {
  cout<<endl<<endl<<"_______________________________________________________________________________";
  gotoxy(1,4);
  cout<<"S No.";
  gotoxy(10,4);
  cout<<"Airline";
  gotoxy(30,4);
  cout<<"Class";
  gotoxy(50,4);
  cout<<"Departure";
  gotoxy(60,4);
  cout<<"Arrival";
  gotoxy(70,4);
  cout<<"Price"<<endl;
  cout<<"_______________________________________________________________________________";
  gotoxy(1,6);
  cout<<"1.";
  gotoxy(10,6);
  cout<<"Kingfisher ";
  gotoxy(30,6);
  cout<<"Business";
  gotoxy(50,6);
  cout<<"7:00 AM";
  gotoxy(60,6);
  cout<<"9:30 AM";
  gotoxy(70,6);
  cout<<"6000";
  gotoxy(1,7);
  cout<<"2.";
  gotoxy(10,7);
  cout<<"Air India";
  gotoxy(30,7);
  cout<<"Economy";
  gotoxy(50,7);
  cout<<"6:00 PM";
  gotoxy(60,7);
  cout<<"8:30 PM";
  gotoxy(70,7);
  cout<<"3000";
  gotoxy(1,8);
  cout<<"3.";
  gotoxy(10,8);
  cout<<"Indigo";
  gotoxy(30,8);
  cout<<"Economy";
  gotoxy(50,8);
  cout<<"3:00 PM";
  gotoxy(60,8);
  cout<<"5:30 PM";
  gotoxy(70,8);
  cout<<"2750";
  gotoxy(30,15);
  cout<<"Choose a flight to proceed - ";
  cin>>choice;
  cout<<choice;
  getch();
  for(int i=0;i<3;i++)
  {
	gotoxy(18,10);
	cout<<"Please wait while tickets are being processed ";
	gotoxy(35,12);
	cout<<"Loading .";
	delay(0.3);
	clrscr();
	gotoxy(18,10);
	cout<<"Please wait while tickets are being processed ";
	gotoxy(35,12);
	cout<<"Loading ..";
	delay(0.3);
	clrscr();
	gotoxy(18,10);
	cout<<"Please wait while tickets are being processed ";
	gotoxy(35,12);
	cout<<"Loading ...";
	delay(0.3);
	clrscr();
  }
  fstream f("NewDelhi.dat",ios::out|ios::binary);
  if (choice==1)
  {
	if((strcmp(code," ")==0) && passengers<=3)
	{
	 strcpy(code,"A1");
	 f.write((char *)&t,sizeof(t));
	}
	else
	{
	 cout<<"The flight is completely booked";
	}
  }
  if (choice==2)
  {
	if((strcmp(code," ")==0) && passengers<=3)
	{
	 strcpy(code,"A2");
	 f.write((char *)&t,sizeof(t));
	}
	else
	{
	 cout<<"The flight is completely booked";
	}
  }
  if (choice==3)
  {
	if((strcmp(code," ")==0) && passengers<=3)
	{
	 strcpy(code,"A3");
	 f.write((char *)&t,sizeof(t));
	}
	else
	{
	 cout<<"The flight is completely booked";
	}
  }
 }
 getch();
}
void welcome()
{
 A:
 int a;
 do
 {
 cout<<"    ------------------------------------------------------------------------"<<endl;
		for(int i=0;i<=21;i++)
			cout<<"   |                                                                        |"<<endl;
		cout<<"   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
		delay(0.1);
		clrscr();
		cout<<endl;
		cout<<"     -----------------------------------------------------------------------"<<endl;
		for(i=0;i<=19;i++)
			cout<<"    |                                                                      |"<<endl;
		cout<<"      _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  "<<endl;
		delay(0.1);
		clrscr();
		cout<<endl<<endl;
		cout<<"      -----------------------------------------------------------------"<<endl;
		for(i=0;i<=17;i++)
			cout<<"     |                                                                 |"<<endl;
		cout<<"      _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  "<<endl;
		delay(0.1);
 gotoxy(25,7);
 cout<<"BANGALORE INTERNATIONAL AIRPORT ";
 gotoxy(31,9);
 cout<<"1. Book a Ticket";
 gotoxy(27,10);
 cout<<"2. Airport Shuttle Timings";
 gotoxy(28,11);
 cout<<"3. Airlines Flying Here..";
 gotoxy(35,12);
 cout<<"4. Exit";
 gotoxy(33,14);
 cout<<"Choose - ";
 cin>>a;
 switch(a)
 {
  case 1:
	ABC.book_ticket();
	break;
  case 2:
	shuttle();
	break;
  case 3:
	airlines();
	break;
  case 4:
	clrscr();
	gotoxy(34,11);
	cout<<"Thank You !!!";
	exit(0);
	break;
  default:
	gotoxy(30,15);
	cout<<"Invaild Entry..";
	gotoxy(28,16);
	cout<<"Please Try Again .. ";
	getch();
	clrscr();
	goto A;
	break;
 }
}while(a>=1 && a<=4);
}
void main()
{
  gotoxy(36,6);
  cout<<"WELCOME";
  delay(1);
  gotoxy(38,12);
  cout<<"TO..";
  delay(1);
  gotoxy(25,18);
  cout<<"BANGALORE INTERNATIONAL AIRPORT";
  delay(1);
  clrscr();
  plane();
  welcome();
}
