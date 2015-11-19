#include<fstream>
#include<time.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<dos.h>
#include"plane.cpp"
#include"dest.cpp"
#include"shuttle.cpp"

int a,i;

int check_count;    //to check if both flights are booked for that day

int countnd1=0,countnd2=0,countnd3=0,countnd4=0;     //to keep count of no.of passengers in each flight
int countmu1=0,countmu2=0,countmu3=0,countmu4=0;
int countcn1=0,countcn2=0,countcn3=0,countcn4=0;
int countko1=0,countko2=0,countko3=0,countko4=0;
int counthy1=0,counthy2=0,counthy3=0,counthy4=0;
int countlo1=0,countlo2=0;
int countpa1=0,countpa2=0;
int countdu1=0,countdu2=0;
int countsi1=0,countsi2=0;
int counthk1=0,counthk2=0;

int choice;

void welcome();

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
struct date1
{
 int dd,mm,yy;
};

class ticket
{
 public:
 int passengers;
 date1 depart;
 char destination[30];
 char airline[30];
 char name[5][40];
 char boarding_time[10];
 char depart_time[10];
 char travel_class;
 char flight_code[10];
 int gate;
 unsigned long int price, total;
 ticket()
 {
  passengers=0;
  strcpy(destination," ");
  strcpy(airline," ");
  strcpy(name[0]," ");
  strcpy(name[1]," ");
  strcpy(name[2]," ");
  strcpy(name[3]," ");
  strcpy(name[4]," ");
  strcpy(boarding_time," ");
  strcpy(depart_time," ");
  strcpy(flight_code," ");
  travel_class='\0';
  gate=0;
  price=0;
  total=0;
  depart.dd=0;
  depart.mm=0;
  depart.yy=0;

 }

 int check(int nop)
 {
	if(nop<=5)
		return 1;
	else
	  return 0;
 }
 void book_ticket();
};//end of class

ticket ABC;

void gen_ticket(ticket t)     //function to generate boarding pass
{
 for(int i=0;i<3;i++)
 {
  clrscr();
  gotoxy(15,10);
  cout<<"Please Wait While your Boarding Pass is Being Processed ";
  gotoxy(35,12);
  cout<<"Loading .";
  delay(0.3);
  clrscr();
  gotoxy(15,10);
  cout<<"Please Wait While your Boarding Pass is Being Processed ";
  gotoxy(35,12);
  cout<<"Loading ..";
  delay(0.3);
  clrscr();
  gotoxy(15,10);
  cout<<"Please Wait While your Boarding Pass is Being Processed ";
  gotoxy(35,12);
  cout<<"Loading ...";
  delay(0.3);
  clrscr();
 }
 gotoxy(2,1);
 for(i=1;i<=78;i++)
  cout<<char(0);
 for(i=2;i<=18;i++)
 {
  gotoxy(2,i); cout<<char(0);
  gotoxy(79,i); cout<<char(0)<<endl;
 }
 gotoxy(2,19);
 for(i=1;i<=78;i++)
  cout<<char(0);
 gotoxy(33,2);
 cout<<"BOARDING PASS";
 gotoxy(33,18);
 cout<<"Airline - " <<t.airline;
 gotoxy(15,4);
 cout<<"Name(s)";
 int j=5;
 for(i=0;i<t.passengers;i++,j++)
 {
  gotoxy(15,j);
  cout<<"-> "<<t.name[i];
 }
 gotoxy(15,11);
 cout<<"From - ";
 cout<<"Bengaluru";
 gotoxy(15,12);
 cout<<"To - ";
 cout<<t.destination;
 gotoxy(45,4);
 cout<<"Flight No. - ";
 cout<<t.flight_code;
 gotoxy(45,6);
 cout<<"Class - ";
 cout<<t.travel_class;
 gotoxy(45,8);
 cout<<"Date - ";
 cout<<t.depart.dd<<"/"<<t.depart.mm<<"/"<<t.depart.yy;
 gotoxy(45,9);
 cout<<"Boarding Time - ";
 cout<<t.boarding_time;
 gotoxy(45,11);
 cout<<"Gate - ";
 cout<<t.gate;
 gotoxy(45,13);
 cout<<"Departure Time - ";
 cout<<t.depart_time;
 gotoxy(21,15);
 cout<<"Total price = "<<t.price<<" X "<<t.passengers<<" = Rs. "<<t.total;
 gotoxy(28,22);
 cout<<"Please print your boarding pass ";
 gotoxy(22,23);
 cout<<"Press any key to go back to the main menu ";
 getch();
 clrscr();
}
void ticket::book_ticket()
{
 ticket t;
 clrscr();
 D:
 gotoxy(25,1);
 cout<<"Welcome to the Ticket Center !!!";
 gotoxy(10,3);
 cout<<"PLEASE NOTE :TICKETS CAN BE BOOKED FOR TODAY AND TOMORROW ONLY";
 gotoxy(7,6);
 for(i=1;i<=65;i++)
 cout<<char(0);
 for(i=7;i<=22;i++)
 {
  gotoxy(7,i); cout<<char(0);
  gotoxy(71,i); cout<<char(0);
 }
 gotoxy(7,23);
 for(i=1;i<=65;i++)
 cout<<char(0);
 gotoxy(21,8);
 cout<<"Domestic";
 gotoxy(20,10);
 cout<<"New Delhi";
 gotoxy(20,11);
 cout<<"Mumbai";
 gotoxy(20,12);
 cout<<"Chennai";
 gotoxy(20,13);
 cout<<"Kolkata";
 gotoxy(20,14);
 cout<<"Hyderabad";
 gotoxy(43,8);
 cout<<"International";
 gotoxy(46,10);
 cout<<"London";
 gotoxy(46,11);
 cout<<"Paris";
 gotoxy(46,12);
 cout<<"Dubai";
 gotoxy(46,13);
 cout<<"Singapore ";
 gotoxy(46,14);
 cout<<"Hong Kong";
 gotoxy(10,16);
 cout<<"-> Enter your destination - ";
 gotoxy(38,16);
 gets(t.destination);
 if ((strcmpi(t.destination,"New Delhi")!=0) && (strcmpi(t.destination,"Mumbai")!=0) && (strcmpi(t.destination,"Chennai")!=0) && (strcmpi(t.destination,"Kolkata")!=0) && (strcmpi(t.destination,"Hyderabad")!=0) && (strcmpi(t.destination,"London")!=0) && (strcmpi(t.destination,"Paris")!=0) && (strcmpi(t.destination,"Dubai")!=0) && (strcmpi(t.destination,"Singapore")!=0) && (strcmpi(t.destination,"Hong Kong")!=0))
 {
  gotoxy(19,19);
  cout<<"Destination Not Available /Check spelling ";
  gotoxy(31,20);
  cout<<"Please Re- Enter ";
  getch();
  clrscr();
  goto D;
 }
 E:
 gotoxy(10,18);
 cout<<"-> Enter the number of passengers traveling - ";
 cin>>t.passengers;
 if(t.passengers > 5 || t.passengers<=0)
  {
	gotoxy(13,21);
	cout<<"Flight capacity is 5/Invalid Entry,Please Re-Enter ";
	getch();
	gotoxy(13,21);
	cout<<"                                                     ";
	gotoxy(10,18);
	cout<<"                                                   ";
	goto E;
  }
 gotoxy(23,21);
 cout<<"Press any key to continue ...";
 getch();
 clrscr();
 B:
 clrscr();
 gotoxy(7,6);
 for(i=1;i<=65;i++)
 cout<<char(0);
 for(i=7;i<=20;i++)
 {
  gotoxy(7,i); cout<<char(0);
  gotoxy(71,i); cout<<char(0);
 }
 gotoxy(7,21);
 for(i=1;i<=65;i++)
 cout<<char(0);
 gotoxy(17,10);
 cout<<"-> Enter the date of departure - ";
 gotoxy(25,11);
 cout<<"(dd mm yyyy)";
 gotoxy(50,10);
 cin>>t.depart.dd>>t.depart.mm>>t.depart.yy;


																								 // DATE CHECK
	struct date d;

	getdate(&d);

  if(((int)(d.da_day)==31 &&((int)(d.da_day) != 31 && (int)(d.da_day) != 1) && ((int)d.da_mon)!=12)   || t.depart.mm < ((int)d.da_mon))
	{
	gotoxy(15,15);
	cout<<"* Tickets can be booked only for today and tomorrow\n";
	gotoxy(9,16);
	cout<<"* Check if the date entered is in the correct format as shown ";
	gotoxy(33,17);
	cout<<"Please re-enter";
	getch();
	goto B;
  }
  else if((int)(d.da_day)==30 &&((int)(d.da_day) != 30 && (int)(d.da_day) != 1) || t.depart.mm < ((int)d.da_mon))
	{
	gotoxy(15,15);
	cout<<"* Tickets can be booked only for today and tomorrow\n";
	gotoxy(9,16);
	cout<<"* Check if the date entered is in the correct format as shown ";
	gotoxy(33,17);
	cout<<"Please re-enter";
	getch();
	goto B;
  }
  else if((int)(d.da_day)==28 &&((int)(d.da_day) != 28 && (int)(d.da_day) != 1) || t.depart.mm < ((int)d.da_mon))
	{
	gotoxy(15,15);
	cout<<"* Tickets can be booked only for today and tomorrow\n";
	gotoxy(9,16);
	cout<<"* Check if the date entered is in the correct format as shown ";
	gotoxy(33,17);
	cout<<"Please re-enter";
	getch();
	goto B;
  }
  else if((int)(d.da_day)==31 &&((int)(d.da_day) != 31 && (int)(d.da_day) != 1) || t.depart.mm > ((int)d.da_mon))
	{
	gotoxy(15,15);
	cout<<"* Tickets can be booked only for today and tomorrow\n";
	gotoxy(9,16);
	cout<<"* Check if the date entered is in the correct format as shown ";
	gotoxy(33,17);
	cout<<"Please re-enter";
	getch();
	goto B;
  }
 if(t.depart.dd < (int)(d.da_day) || t.depart.mm < (int)(d.da_mon) || t.depart.yy < d.da_year )
  {
	gotoxy(15,15);
	cout<<"* Tickets can be booked only for today and tomorrow\n";
	gotoxy(9,16);
	cout<<"* Check if the date entered is in the correct format as shown ";
	gotoxy(33,17);
	cout<<"Please re-enter";
	getch();
	goto B;
  }
  else if(t.depart.dd > ((int)(d.da_day) + 1) || t.depart.mm > (int)(d.da_mon) + 1 || t.depart.yy > (d.da_year + 1) )
  {
	gotoxy(15,15);
	cout<<"* Tickets can be booked only for today and tomorrow\n";
	gotoxy(9,16);
	cout<<"* Check if the date entered is in the correct format as shown ";
	gotoxy(33,17);
	cout<<"Please re-enter";
	getch();
	goto B;
  }

  gotoxy(27,16);
  cout<<"Press any key to continue ";
  getch();
  clrscr();




																	// END OF DATE CHECK


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
 //**************************************** NEW DELHI ***********************************************************
 if(strcmpi(t.destination,"New Delhi")==0)
 {
 Cnd:
  gotoxy(30,2);
  cout<<" Choose your Flight ...";
  cout<<endl<<endl<<endl<<"_______________________________________________________________________________";
  gotoxy(1,6);
  cout<<"S No.";
  gotoxy(10,6);
  cout<<"Airline";
  gotoxy(25,6);
  cout<<"Class";
  gotoxy(40,6);
  cout<<"Departure";
  gotoxy(55,6);
  cout<<"Arrival";
  gotoxy(65,6);
  cout<<"Price (in Rs.)"<<endl;
  cout<<"_______________________________________________________________________________";
  gotoxy(1,8);
  cout<<"1.";
  gotoxy(10,8);
  cout<<"IndiGo";
  gotoxy(25,8);
  cout<<"Economy";
  gotoxy(40,8);
  cout<<"6:00 AM";
  gotoxy(55,8);
  cout<<"8:45 AM";
  gotoxy(68,8);
  cout<<"8,397";
  gotoxy(1,9);
  cout<<"2.";
  gotoxy(10,9);
  cout<<"Air India";
  gotoxy(25,9);
  cout<<"Business";
  gotoxy(40,9);
  cout<<"10:30 AM";
  gotoxy(55,9);
  cout<<"1:05 PM";
  gotoxy(68,9);
  cout<<"8,691";
  gotoxy(25,17);
  cout<<"Choose a flight to proceed - ";
  cin>>choice;

  for(int i=0;i<3;i++)
  {
	clrscr();
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
  if((int)d.da_day==t.depart.dd && choice==1)   //if departure date is today and flight chosen is 1
  {
	fstream f1("NewDelhi-1a.dat",ios::out|ios::in|ios::binary);
	if(check(countnd1+t.passengers)==1)  //to check flight availability
	{
	 clrscr();
	 int j;
	 gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"5:30 AM");
	  strcpy(t.depart_time,"6:30 AM");
	  strcpy(t.flight_code,"6E 334");
	  strcpy(t.airline,"IndiGo");
	  t.gate=1;
	  t.travel_class='E';
	  t.price=8397;
	  t.total=t.price*t.passengers;
	  f1.write((char *)&t,sizeof(t));
	  countnd1++;
	 }
	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f1.close();
	}

	else
	{
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(27,12);cout<<"Please try the other flight ";
	 check_count++;
	 if(check_count==2)   //if both flights are booked
	 {
	  gotoxy(17,11); cout<<"All flights to New Delhi today are completely booked";
	  gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	  getch();
	  clrscr();
	  welcome();
	 }
	 getchar();
	 clrscr();
	 goto Cnd;
	}
 }
 else if((int)d.da_day==t.depart.dd && choice==2)   //if departure date is today and flight chosen is 2
 {
	clrscr();
	fstream f2("New_Delhi-1b.dat",ios::out|ios::in|ios::binary);
	if(check(countnd2+t.passengers)==1)
	{
	 int j;
	 gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"10:00 AM");
	  strcpy(t.depart_time,"10:30 AM");
	  strcpy(t.flight_code,"AI 123");
	  strcpy(t.airline,"Air India");
	  t.gate=15;
	  t.travel_class='B';
	  t.price=8691;
	  t.total=t.price*t.passengers;
	  f2.write((char *)&t,sizeof(t));
	  countnd2++;
	 }
	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f2.close();
	}

	else
	{
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(27,12);cout<<"Please try the other flight ";
	 check_count++;
	 if(check_count==2)  //
	 {
	  gotoxy(17,11); cout<<"All flights to New Delhi today are completely booked";
	  gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	  getch();
	  clrscr();
	  welcome();
	 }
	 getchar();
	 clrscr();
	 goto Cnd;
	}
 }

 else if(((int)d.da_day)+1==t.depart.dd && choice==1)       //if departure date is the next day and flight chosen is 1
 {
	fstream f3("New_Delhi-2a.dat",ios::out|ios::in|ios::binary);

	if(check(countnd3+t.passengers)==1)
	{
	 clrscr();
	 int j;
	 gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"5:30 AM");
	  strcpy(t.depart_time,"6:00 AM");
	  strcpy(t.flight_code,"6E 334");
	  strcpy(t.airline,"IndiGo");
	  t.gate=1;
	  t.travel_class='E';
	  t.price=8397;
	  t.total=t.price*t.passengers;
	  f3.write((char *)&t,sizeof(t));
	  countnd3++;
	 }
	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f3.close();
	}

	else
	{
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(27,12);cout<<"Please try the other flight ";
	 check_count++;
	 if(check_count==2)
	 {
	  gotoxy(17,11); cout<<"All flights to New Delhi today are completely booked";
	  gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	  getch();
	  clrscr();
	  welcome();
	 }
	 getchar();
	 clrscr();
	 goto Cnd;
	}
 }
 else if((int)d.da_day+1==t.depart.dd && choice==2)       //if departure date is the next day and flight chosen is 2
 {
	clrscr();
	fstream f4("New_Delhi-2b.dat",ios::out|ios::in|ios::binary);
	if(check(countnd4+t.passengers)==1)
	{
	 int j;
	 gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"10:00 AM");
	  strcpy(t.depart_time,"10:30 AM");
	  strcpy(t.flight_code,"AI 123");
	  strcpy(t.airline,"Air India");
	  t.gate=15;
	  t.travel_class='B';
	  t.price=8691;
	  t.total=t.price*t.passengers;
	  f4.write((char *)&t,sizeof(t));
	  countnd4++;
	 }

	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f4.close();
	}

	else
	{
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(27,12);cout<<"Please try the other flight ";
	 check_count++;
	 if(check_count==2)
	 {
	  gotoxy(17,11); cout<<"All flights to New Delhi today are completely booked";
	  gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	  getch();
	  clrscr();
	  welcome();
	 }
	 getchar();
	 clrscr();
	 goto Cnd;
	}
 }
}
//***************************************   MUMBAI   *********************************************************
else if(strcmpi(t.destination,"Mumbai")==0)
 {
 Cm:
 gotoxy(30,2);
  cout<<" Choose your Flight ...";
  cout<<endl<<endl<<endl<<"_______________________________________________________________________________";
  gotoxy(1,6);
  cout<<"S No.";
  gotoxy(10,6);
  cout<<"Airline";
  gotoxy(25,6);
  cout<<"Class";
  gotoxy(40,6);
  cout<<"Departure";
  gotoxy(55,6);
  cout<<"Arrival";
  gotoxy(65,6);
  cout<<"Price (in Rs.)"<<endl;
  cout<<"_______________________________________________________________________________";
  gotoxy(1,8);
  cout<<"1.";
  gotoxy(10,8);
  cout<<"Go Air ";
  gotoxy(25,8);
  cout<<"Economy";
  gotoxy(40,8);
  cout<<"5:55 AM";
  gotoxy(55,8);
  cout<<"7:25 AM";
  gotoxy(68,8);
  cout<<"5,512";
  gotoxy(1,9);
  cout<<"2.";
  gotoxy(10,9);
  cout<<"Jet Airways";
  gotoxy(25,9);
  cout<<"Business";
  gotoxy(40,9);
  cout<<"11:25 AM";
  gotoxy(55,9);
  cout<<"12:55 PM";
  gotoxy(68,9);
  cout<<"5,565";
  gotoxy(25,17);
  cout<<"Choose a flight to proceed - ";
  cin>>choice;

  for(int i=0;i<3;i++)
  {
	clrscr();
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
  if((int)d.da_day==t.depart.dd && choice==1)
  {
	fstream f1("Mumbai-1a.dat",ios::out|ios::in|ios::binary);
	if(check(countmu1+t.passengers)==1)
	{
	 clrscr();
	 int j;
    gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"5:25 AM");
	  strcpy(t.depart_time,"5:55 AM");
	  strcpy(t.flight_code,"G8 512");
	  strcpy(t.airline,"Go Air");
	  t.gate=5;
	  t.travel_class='E';
	  t.price=5512;
	  t.total=t.price*t.passengers;
	  f1.write((char *)&t,sizeof(t));
	  countmu1++;
	 }

	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f1.close();
	}

	else
	{
	 clrscr();
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(27,12);cout<<"Please try the other flight ";
    check_count++;
	 if(check_count==2)
	 {
	  gotoxy(17,11); cout<<"All flights to Mumbai today are completely booked";
	  gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	  getch();
	  clrscr();
	  welcome();
	 }
	 getchar();
	 clrscr();
	 goto Cm;
	}
 }
 else if((int)d.da_day==t.depart.dd && choice==2)
 {
	clrscr();
	fstream f2("Mumbai-1b.dat",ios::out|ios::in|ios::binary);
	if(check(countmu2+t.passengers)==1)
	{
	 int j;
    gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"10:55 AM");
	  strcpy(t.depart_time,"11:25 AM");
	  strcpy(t.flight_code,"9W 123");
	  strcpy(t.airline,"Jet Airways");
	  t.gate=15;
	  t.travel_class='B';
	  t.price=5565;
	  t.total=t.price*t.passengers;
	  f2.write((char *)&t,sizeof(t));
	  countmu2++;
	 }
	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f2.close();
	}

	else
	{
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(27,12);cout<<"Please try the other flight ";
    check_count++;
	 if(check_count==2)
	 {
	  gotoxy(17,11); cout<<"All flights to Mumbai today are completely booked";
	  gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	  getch();
	  clrscr();
	  welcome();
	 }
	 getchar();
	 clrscr();
	 goto Cm;
	}
 }
 else if(((int)d.da_day)+1==t.depart.dd && choice==1)
 {
	fstream f3("Mumbai-2a.dat",ios::out|ios::in|ios::binary);

	if(check(countmu3+t.passengers)==1)
	{
	 clrscr();
	 int j;
	 gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter Name of Passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"5:25 AM");
	  strcpy(t.depart_time,"5:55 AM");
	  strcpy(t.flight_code,"G8 512");
	  strcpy(t.airline,"Go Air");
	  t.gate=5;
	  t.travel_class='E';
	  t.price=5512;
	  t.total=t.price*t.passengers;
	  f3.write((char *)&t,sizeof(t));
	  countmu3++;
	 }

	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f3.close();
	}

	else
	{
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(27,12);cout<<"Please try the other flight ";
    check_count++;
	 if(check_count==2)
	 {
	  gotoxy(17,11); cout<<"All flights to Mumbai today are completely booked";
	  gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	  getch();
	  clrscr();
	  welcome();
	 }
	 getchar();
	 clrscr();
	 goto Cm;
	}
 }
  //*****************************************************************************************************************
 else if((int)d.da_day+1==t.depart.dd && choice==2)
 {
	clrscr();
	fstream f4("Mumbai-2b.dat",ios::out|ios::in|ios::binary);
	if(check(countmu4+t.passengers)==1)
	{
	 clrscr();
	 int j;
	 gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"10:55 AM");
	  strcpy(t.depart_time,"11:25 AM");
	  strcpy(t.flight_code,"9W 123");
	  strcpy(t.airline,"Jet Airways");
	  t.gate=15;
	  t.travel_class='B';
	  t.price=5565;
	  t.total=t.price*t.passengers;
	  f4.write((char *)&t,sizeof(t));
	  countmu4++;
	 }

	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f4.close();
	}

	else
	{
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(27,12);cout<<"Please try the other flight ";
    check_count++;
	 if(check_count==2)
	 {
	  gotoxy(17,11); cout<<"All flights to Mumbai today are completely booked";
	  gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	  getch();
	  clrscr();
	  welcome();
	 }
	 getchar();
	 clrscr();
	 goto Cm;
	}
 }
}
//***************************************  CHENNAI  *******************************************************************
 if(strcmpi(t.destination,"Chennai")==0)
 {
 Ccn:
 gotoxy(30,2);
  cout<<" Choose your Flight ...";
  cout<<endl<<endl<<endl<<"_______________________________________________________________________________";
  gotoxy(1,6);
  cout<<"S No.";
  gotoxy(10,6);
  cout<<"Airline";
  gotoxy(25,6);
  cout<<"Class";
  gotoxy(40,6);
  cout<<"Departure";
  gotoxy(55,6);
  cout<<"Arrival";
  gotoxy(65,6);
  cout<<"Price (in Rs.)"<<endl;
  cout<<"_______________________________________________________________________________";
  gotoxy(1,8);
  cout<<"1.";
  gotoxy(10,8);
  cout<<"Spicejet ";
  gotoxy(25,8);
  cout<<"Economy";
  gotoxy(40,8);
  cout<<"9:05 AM";
  gotoxy(55,8);
  cout<<"10:25 AM";
  gotoxy(68,8);
  cout<<"4,043";
  gotoxy(1,9);
  cout<<"2.";
  gotoxy(10,9);
  cout<<"Jet Airways";
  gotoxy(25,9);
  cout<<"Business";
  gotoxy(40,9);
  cout<<"7:35 PM";
  gotoxy(55,9);
  cout<<"8:20 PM";
  gotoxy(68,9);
  cout<<"4,253";
  gotoxy(25,17);
  cout<<"Choose a flight to proceed - ";
  cin>>choice;

  for(int i=0;i<3;i++)
  {
	clrscr();
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
  if((int)d.da_day==t.depart.dd && choice==1)
  {
	fstream f1("Chennai-1a.dat",ios::out|ios::in|ios::binary);
	if(check(countcn1+t.passengers)==1)
	{
	 clrscr();
	 int j;
	 gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"8:35 AM");
	  strcpy(t.depart_time,"9:05 AM");
	  strcpy(t.flight_code,"SG 153");
	  strcpy(t.airline,"Spicejet");
	  t.gate=17;
	  t.travel_class='E';
	  t.price=4043;
	  t.total=t.price*t.passengers;
	  f1.write((char *)&t,sizeof(t));
	  countcn1++;
	 }
	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f1.close();
	}

	else
	{
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(27,12);cout<<"Please try the other flight ";
	 check_count++;
	 if(check_count==2)
	 {
	  gotoxy(17,11); cout<<"All flights to Chennai today are completely booked";
	  gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	  getch();
	  clrscr();
	  welcome();
	 }
	 getchar();
	 clrscr();
	 goto Ccn;
	}
 }
 else if((int)d.da_day==t.depart.dd && choice==2)
 {
	clrscr();
	fstream f2("Chennai-1b.dat",ios::out|ios::in|ios::binary);
	if(check(countcn2+t.passengers)==1)
	{
	 clrscr();
	 int j;
    gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"7:05 PM");
	  strcpy(t.depart_time,"7:35 PM");
	  strcpy(t.flight_code,"9W 576");
	  strcpy(t.airline,"Jet Airways");
	  t.gate=13;
	  t.travel_class='B';
	  t.price=4253;
	  t.total=t.price*t.passengers;
	  f2.write((char *)&t,sizeof(t));
	  countcn2++;
	 }
	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f2.close();
	}

	else
	{
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(27,12);cout<<"Please try the other flight ";
    check_count++;
	 if(check_count==2)
	 {
	  gotoxy(17,11); cout<<"All flights to Chennai today are completely booked";
	  gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	  getch();
	  clrscr();
	  welcome();
	 }
	 getchar();
	 clrscr();
	 goto Ccn;
	}
 }

 else if(((int)d.da_day)+1==t.depart.dd && choice==1)
 {
	fstream f3("Chennai-2a.dat",ios::out|ios::in|ios::binary);

	if(check(countcn3+t.passengers)==1)
	{
	 clrscr();
	 int j;
    gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"8:35 AM");
	  strcpy(t.depart_time,"9:05 AM");
	  strcpy(t.flight_code,"SG 153");
	  strcpy(t.airline,"Spicejet");
	  t.gate=17;
	  t.travel_class='E';
	  t.price=4043;
	  t.total=t.price*t.passengers;
	  f3.write((char *)&t,sizeof(t));
	  countcn3++;
	 }
	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f3.close();
	}

	else
	{
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(27,12);cout<<"Please try the other flight ";
    check_count++;
	 if(check_count==2)
	 {
	  gotoxy(17,11); cout<<"All flights to Chennai today are completely booked";
	  gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	  getch();
	  clrscr();
	  welcome();
	 }
	 getchar();
	 clrscr();
	 goto Ccn;
	}
 }
 else if((int)d.da_day+1==t.depart.dd && choice==2)
 {
	clrscr();
	fstream f4("Chennai-2b.dat",ios::out|ios::in|ios::binary);
	if(check(countcn4+t.passengers)==1)
	{
	 clrscr();
	 int j;
    gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"7:05 PM");
	  strcpy(t.depart_time,"7:35 PM");
	  strcpy(t.flight_code,"9W 576");
	  strcpy(t.airline,"Jet Airways");
	  t.gate=13;
	  t.travel_class='B';
	  t.price=4253;
	  t.total=t.price*t.passengers;
	  f4.write((char *)&t,sizeof(t));
	  countcn4++;
	 }

	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f4.close();
	}

	else
	{
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(27,12);cout<<"Please try the other flight ";
    check_count++;
	 if(check_count==2)
	 {
	  gotoxy(17,11); cout<<"All flights to Chennai today are completely booked";
	  gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	  getch();
	  clrscr();
	  welcome();
	 }
	 getchar();
	 clrscr();
	 goto Ccn;
	}
 }
}
//**************************************************** KOLKATA  *************************************************
 if(strcmpi(t.destination,"Kolkata")==0)
 {
 Cko:
  gotoxy(30,2);
  cout<<" Choose your Flight ...";
  cout<<endl<<endl<<endl<<"_______________________________________________________________________________";
  gotoxy(1,6);
  cout<<"S No.";
  gotoxy(10,6);
  cout<<"Airline";
  gotoxy(25,6);
  cout<<"Class";
  gotoxy(40,6);
  cout<<"Departure";
  gotoxy(55,6);
  cout<<"Arrival";
  gotoxy(65,6);
  cout<<"Price (in Rs.)"<<endl;
  cout<<"_______________________________________________________________________________";
  gotoxy(1,8);
  cout<<"1.";
  gotoxy(10,8);
  cout<<"IndiGo ";
  gotoxy(25,8);
  cout<<"Economy";
  gotoxy(40,8);
  cout<<"7:00 AM";
  gotoxy(55,8);
  cout<<"9:25 AM";
  gotoxy(68,8);
  cout<<"7,597";
  gotoxy(1,9);
  cout<<"2.";
  gotoxy(10,9);
  cout<<"Jet Airways";
  gotoxy(25,9);
  cout<<"Economy";
  gotoxy(40,9);
  cout<<"4:20 PM";
  gotoxy(55,9);
  cout<<"6:45 PM";
  gotoxy(68,9);
  cout<<"8,115";
  gotoxy(25,17);
  cout<<"Choose a flight to proceed - ";
  cin>>choice;

  for(int i=0;i<3;i++)
  {
	clrscr();
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
  if((int)d.da_day==t.depart.dd && choice==1)
  {
	fstream f1("Kolkata-1a.dat",ios::out|ios::in|ios::binary);
	if(check(countko1+t.passengers)==1)
	{
	 clrscr();
	 int j;
    gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"6:30 AM");
	  strcpy(t.depart_time,"7:00 AM");
	  strcpy(t.flight_code,"6E 512");
	  strcpy(t.airline,"IndiGo");
	  t.gate=1;
	  t.travel_class='E';
	  t.price=7597;
	  t.total=t.price*t.passengers;
	  f1.write((char *)&t,sizeof(t));
	  countko1++;
	 }
	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f1.close();
	}

	else
	{
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(27,12);cout<<"Please try the other flight ";
    check_count++;
	 if(check_count==2)
	 {
	  gotoxy(17,11); cout<<"All flights to Kolkata today are completely booked";
	  gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	  getch();
	  clrscr();
	  welcome();
	 }
	 getchar();
	 clrscr();
	 goto Cko;
	}
 }
 else if((int)d.da_day==t.depart.dd && choice==2)
 {
	clrscr();
	fstream f2("Kolkata-1b.dat",ios::out|ios::in|ios::binary);
	if(check(countko2+t.passengers)==1)
	{
	 clrscr();
	 int j;
    gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"3:50 PM");
	  strcpy(t.depart_time,"4:20 PM");
	  strcpy(t.flight_code,"9W 526");
	  strcpy(t.airline,"Jet Airways");
	  t.gate=9;
	  t.travel_class='E';
	  t.price=8115;
	  t.total=t.price*t.passengers;
	  f2.write((char *)&t,sizeof(t));
	  countko2++;
	 }
	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f2.close();
	}

	else
	{
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(27,12);cout<<"Please try the other flight ";
    check_count++;
	 if(check_count==2)
	 {
	  gotoxy(17,11); cout<<"All flights to Kolkata today are completely booked";
	  gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	  getch();
	  clrscr();
	  welcome();
	 }
	 getchar();
	 clrscr();
	 goto Cko;
	}
 }

 else if(((int)d.da_day)+1==t.depart.dd && choice==1)
 {
	fstream f3("Kolkata-2a.dat",ios::out|ios::in|ios::binary);

	if(check(countko3+t.passengers)==1)
	{
	 clrscr();
	 int j;
    gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"6:30 AM");
	  strcpy(t.depart_time,"7:00 AM");
	  strcpy(t.flight_code,"6E 512");
	  strcpy(t.airline,"IndiGo");
	  t.gate=1;
	  t.travel_class='E';
	  t.price=7597;
	  t.total=t.price*t.passengers;
	  f3.write((char *)&t,sizeof(t));
	  countko3++;
	 }
	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f3.close();
	}

	else
	{
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(27,12);cout<<"Please try the other flight ";
    check_count++;
	 if(check_count==2)
	 {
	  gotoxy(17,11); cout<<"All flights to Kolkata today are completely booked";
	  gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	  getch();
	  clrscr();
	  welcome();
	 }
	 getchar();
	 clrscr();
	 goto Cko;
	}
 }
 else if((int)d.da_day+1==t.depart.dd && choice==2)
 {
	clrscr();
	fstream f4("Kolkata-2b.dat",ios::out|ios::in|ios::binary);
	if(check(countko4+t.passengers)==1)
	{
	 clrscr();
	 int j;
    gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"3:50 PM");
	  strcpy(t.depart_time,"4:20 PM");
	  strcpy(t.flight_code,"9W 526");
	  strcpy(t.airline,"Jet Airways");
	  t.gate=9;
	  t.travel_class='E';
	  t.price=8115;
	  t.total=t.price*t.passengers;
	  f4.write((char *)&t,sizeof(t));
	  countko4++;
	 }

	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f4.close();
	}

	else
	{
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(27,12);cout<<"Please try the other flight ";
    check_count++;
	 if(check_count==2)
	 {
	  gotoxy(17,11); cout<<"All flights to Kolkata today are completely booked";
	  gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	  getch();
	  clrscr();
	  welcome();
	 }
	 getchar();
	 clrscr();
	 goto Cko;
	}
 }
}
//*************************************************** HYDERABAD ***********************************************
 if(strcmpi(t.destination,"Hyderabad")==0)
 {
 Chy:
 gotoxy(30,2);
  cout<<" Choose your Flight ...";
  cout<<endl<<endl<<endl<<"_______________________________________________________________________________";
  gotoxy(1,6);
  cout<<"S No.";
  gotoxy(10,6);
  cout<<"Airline";
  gotoxy(25,6);
  cout<<"Class";
  gotoxy(40,6);
  cout<<"Departure";
  gotoxy(55,6);
  cout<<"Arrival";
  gotoxy(65,6);
  cout<<"Price (in Rs.)"<<endl;
  cout<<"_______________________________________________________________________________";
  gotoxy(1,8);
  cout<<"1.";
  gotoxy(10,8);
  cout<<"IndiGo ";
  gotoxy(25,8);
  cout<<"Economy";
  gotoxy(40,8);
  cout<<"8:20 AM";
  gotoxy(55,8);
  cout<<"9:25 AM";
  gotoxy(68,8);
  cout<<"4,043";
  gotoxy(1,9);
  cout<<"2.";
  gotoxy(10,9);
  cout<<"Air India";
  gotoxy(25,9);
  cout<<"Economy";
  gotoxy(40,9);
  cout<<"6:50 PM";
  gotoxy(55,9);
  cout<<"7:55 PM";
  gotoxy(68,9);
  cout<<"4,211";
  gotoxy(25,17);
  cout<<"Choose a flight to proceed - ";
  cin>>choice;

  for(int i=0;i<3;i++)
  {
	clrscr();
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
  if((int)d.da_day==t.depart.dd && choice==1)
  {
	fstream f1("Hyderabad-1a.dat",ios::out|ios::in|ios::binary);
	if(check(counthy1+t.passengers)==1)
	{
	 clrscr();
	 int j;
    gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"7:50 AM");
	  strcpy(t.depart_time,"8:20 AM");
	  strcpy(t.flight_code,"6E 159");
	  strcpy(t.airline,"IndiGo");
	  t.gate=13;
	  t.travel_class='E';
	  t.price=4043;
	  t.total=t.price*t.passengers;
	  f1.write((char *)&t,sizeof(t));
	  counthy1++;
	 }
	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f1.close();
	}

	else
	{
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(27,12);cout<<"Please try the other flight ";
    check_count++;
	 if(check_count==2)
	 {
	  gotoxy(17,11); cout<<"All flights to Hyderabad today are completely booked";
	  gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	  getch();
	  clrscr();
	  welcome();
	 }
	 getchar();
	 clrscr();
	 goto Chy;
	}
 }
 else if((int)d.da_day==t.depart.dd && choice==2)
 {
	clrscr();
	fstream f2("Hyderabad-1b.dat",ios::out|ios::in|ios::binary);
	if(check(counthy2+t.passengers)==1)
	{
	 clrscr();
	 int j;
	 gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"6:20 PM");
	  strcpy(t.depart_time,"6:50 PM");
	  strcpy(t.flight_code,"AI 782");
	  strcpy(t.airline,"Air India");
	  t.gate=11;
	  t.travel_class='E';
	  t.price=4211;
	  t.total=t.price*t.passengers;
	  f2.write((char *)&t,sizeof(t));
	  counthy2++;
	 }
	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f2.close();
	}

	else
	{
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(27,12);cout<<"Please try the other flight ";
    check_count++;
	 if(check_count==2)
	 {
	  gotoxy(17,11); cout<<"All flights to Hyderabad today are completely booked";
	  gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	  getch();
	  clrscr();
	  welcome();
	 }
	 getchar();
	 clrscr();
	 goto Chy;
	}
 }

 else if(((int)d.da_day)+1==t.depart.dd && choice==1)
 {
	fstream f3("Hyderabad-2a.dat",ios::out|ios::in|ios::binary);

	if(check(counthy3+t.passengers)==1)
	{
	 clrscr();
	 int j;
    gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"7:50 AM");
	  strcpy(t.depart_time,"8:20 AM");
	  strcpy(t.flight_code,"6E 159");
	  strcpy(t.airline,"IndiGo");
	  t.gate=13;
	  t.travel_class='E';
	  t.price=4043;
	  t.total=t.price*t.passengers;
	  f3.write((char *)&t,sizeof(t));
	  counthy3++;
	 }
	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f3.close();
	}

	else
	{
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(27,12);cout<<"Please try the other flight ";
    check_count++;
	 if(check_count==2)
	 {
	  gotoxy(17,11); cout<<"All flights to Hyderabad today are completely booked";
	  gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	  getch();
	  clrscr();
	  welcome();
	 }
	 getchar();
	 clrscr();
	 goto Chy;
	}
 }
 else if((int)d.da_day+1==t.depart.dd && choice==2)
 {
	clrscr();
	fstream f4("Hyderabad-2b.dat",ios::out|ios::in|ios::binary);
	if(check(counthy4+t.passengers)==1)
	{
	 clrscr();
	 int j;
    gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"6:20 PM");
	  strcpy(t.depart_time,"6:50 PM");
	  strcpy(t.flight_code,"AI 782");
	  strcpy(t.airline,"Air India");
	  t.gate=11;
	  t.travel_class='E';
	  t.price=4211;
	  t.total=t.price*t.passengers;
	  f4.write((char *)&t,sizeof(t));
	  counthy4++;
	 }

	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f4.close();
	}

	else
	{
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(27,12);cout<<"Please try the other flight ";
    check_count++;
	 if(check_count==2)
	 {
	  gotoxy(17,11); cout<<"All flights to Hyderabad today are completely booked";
	  gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	  getch();
	  clrscr();
	  welcome();
	 }
	 getchar();
	 clrscr();
	 goto Chy;
	}
 }
}

//*************************************************** LONDON ************************************************
else if(strcmpi(t.destination,"London")==0)
 {
  gotoxy(30,1);
  cout<<"Your Flight Details";
  gotoxy(27,2);
  cout<<"NOTE - ALL TIMES ARE LOCAL";
  cout<<endl<<endl<<endl<<endl<<"_______________________________________________________________________________";
  gotoxy(1,7);
  cout<<"S No.";
  gotoxy(10,7);
  cout<<"Airline";
  gotoxy(25,7);
  cout<<"Class";
  gotoxy(40,7);
  cout<<"Departure";
  gotoxy(55,7);
  cout<<"Arrival";
  gotoxy(65,7);
  cout<<"Price (in Rs.)"<<endl;
  cout<<"_______________________________________________________________________________";
  gotoxy(1,9);
  cout<<"1.";
  gotoxy(7,9);
  cout<<"British Airways ";
  gotoxy(25,9);
  cout<<"Economy";
  gotoxy(40,9);
  cout<<"8:00 AM";
  gotoxy(55,9);
  cout<<"1:25 PM ";
  gotoxy(68,9);
  cout<<"32,191";
  gotoxy(27,20);
  cout<<"Press any key to continue .. ";
  getch();

  for(int i=0;i<3;i++)
  {
	clrscr();
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
  if((int)d.da_day==t.depart.dd )
  {
	fstream f1("London-1a.dat",ios::out|ios::in|ios::binary);
	if(check(countlo1+t.passengers)==1)
	{
	 clrscr();
	 int j;
    gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"7:00 AM");
	  strcpy(t.depart_time,"8:00 AM");
	  strcpy(t.flight_code,"BA 112");
	  strcpy(t.airline,"British Airways");
	  t.gate=20;
	  t.travel_class='E';
	  t.price=32191;
	  t.total=t.price*t.passengers;
	  f1.write((char *)&t,sizeof(t));
	  countlo1++;
	 }

	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f1.close();
	}

	else
	{
	 clrscr();
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	 getch();
	 clrscr();
	}
 }

 else if(((int)d.da_day)+1==t.depart.dd )
 {
	fstream f2("London-2a.dat",ios::out|ios::in|ios::binary);

	if(check(countlo2+t.passengers)==1)
	{
	 clrscr();
	 int j;
	 gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"7:00 AM");
	  strcpy(t.depart_time,"8:00 AM");
	  strcpy(t.flight_code,"BA 112");
	  strcpy(t.airline,"British Airways");
	  t.gate=20;
	  t.travel_class='E';
	  t.price=32191;
	  t.total=t.price*t.passengers;
	  f2.write((char *)&t,sizeof(t));
	  countlo2++;
	 }

	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f2.close();
	}

	else
	{
	 clrscr();
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	 getch();
	 clrscr();
	}
 }
}
//*************************************************** PARIS ************************************************
else if(strcmpi(t.destination,"Paris")==0)
 {
  cout<<endl<<endl<<endl<<"_______________________________________________________________________________";
  gotoxy(1,5);
  cout<<"S No.";
  gotoxy(10,5);
  cout<<"Airline";
  gotoxy(25,5);
  cout<<"Class";
  gotoxy(40,5);
  cout<<"Departure";
  gotoxy(55,5);
  cout<<"Arrival";
  gotoxy(65,5);
  cout<<"Price (in Rs.)"<<endl;
  cout<<"_______________________________________________________________________________";
  gotoxy(1,7);
  cout<<"1.";
  gotoxy(10,7);
  cout<<"Air France ";
  gotoxy(25,7);
  cout<<"Economy";
  gotoxy(40,7);
  cout<<"2:20 AM";
  gotoxy(55,7);
  cout<<"8:35 AM";
  gotoxy(68,7);
  cout<<"58,832";
  gotoxy(30,1);
  cout<<"ALL TIMES ARE LOCAL";
  gotoxy(27,18);
  cout<<"Press any key to continue .. ";
  getch();

  for(int i=0;i<3;i++)
  {
	clrscr();
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
  if((int)d.da_day==t.depart.dd )
  {
	fstream f1("Paris-1a.dat",ios::out|ios::in|ios::binary);
	if(check(countpa1+t.passengers)==1)
	{
	 clrscr();
	 int j;
	 gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"1:20 AM");
	  strcpy(t.depart_time,"2:20 AM");
	  strcpy(t.flight_code,"AF 221");
	  strcpy(t.airline,"Air France");
	  t.gate=20;
	  t.travel_class='E';
	  t.price=58832;
	  t.total=t.price*t.passengers;
	  f1.write((char *)&t,sizeof(t));
	  countpa1++;
	 }

	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f1.close();
	}

	else
	{
	 clrscr();
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	 getch();
	 clrscr();
	}
 }

 else if(((int)d.da_day)+1==t.depart.dd )
 {
	fstream f2("Paris-2a.dat",ios::out|ios::in|ios::binary);

	if(check(countpa2+t.passengers)==1)
	{
	 clrscr();
	 int j;
    gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"1:20 AM");
	  strcpy(t.depart_time,"2:20 AM");
	  strcpy(t.flight_code,"AF 221");
	  strcpy(t.airline,"Air France");
	  t.gate=20;
	  t.travel_class='E';
	  t.price=58832;
	  t.total=t.price*t.passengers;
	  f2.write((char *)&t,sizeof(t));
	  countpa2++;
	 }

	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f2.close();
	}

	else
	{
	 clrscr();
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	 getch();
	 clrscr();
	}
 }
}
//*************************************************** DUBAI ************************************************
else if(strcmpi(t.destination,"Dubai")==0)
 {
  cout<<endl<<endl<<endl<<"_______________________________________________________________________________";
  gotoxy(1,5);
  cout<<"S No.";
  gotoxy(10,5);
  cout<<"Airline";
  gotoxy(25,5);
  cout<<"Class";
  gotoxy(40,5);
  cout<<"Departure";
  gotoxy(55,5);
  cout<<"Arrival";
  gotoxy(65,5);
  cout<<"Price (in Rs.)"<<endl;
  cout<<"_______________________________________________________________________________";
  gotoxy(1,7);
  cout<<"1.";
  gotoxy(10,7);
  cout<<"Emirates";
  gotoxy(25,7);
  cout<<"Economy";
  gotoxy(40,7);
  cout<<"4:15 AM";
  gotoxy(55,7);
  cout<<"6:50 AM";
  gotoxy(68,7);
  cout<<"18,448";
  gotoxy(30,1);
  cout<<"ALL TIMES ARE LOCAL";
  gotoxy(27,18);
  cout<<"Press any key to continue .. ";
  getch();

  for(int i=0;i<3;i++)
  {
	clrscr();
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
  if((int)d.da_day==t.depart.dd )
  {
	fstream f1("Dubai-1a.dat",ios::out|ios::in|ios::binary);
	if(check(countdu1+t.passengers)==1)
	{
	 clrscr();
	 int j;
	 gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"3:15 AM");
	  strcpy(t.depart_time,"4:15 AM");
	  strcpy(t.flight_code,"EK 129");
	  strcpy(t.airline,"Emirates");
	  t.gate=20;
	  t.travel_class='E';
	  t.price=18848;
	  t.total=t.price*t.passengers;
	  f1.write((char *)&t,sizeof(t));
	  countdu1++;
	 }

	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f1.close();
	}

	else
	{
	 clrscr();
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	 getch();
	 clrscr();
	}
 }

 else if(((int)d.da_day)+1==t.depart.dd )
 {
	fstream f2("Dubai-2a.dat",ios::out|ios::in|ios::binary);

	if(check(countdu2+t.passengers)==1)
	{
	 clrscr();
	 int j;
    gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"3:15 AM");
	  strcpy(t.depart_time,"4:15 AM");
	  strcpy(t.flight_code,"EK 129");
	  strcpy(t.airline,"Emirates");
	  t.gate=20;
	  t.travel_class='E';
	  t.price=18848;
	  t.total=t.price*t.passengers;
	  f2.write((char *)&t,sizeof(t));
	  countdu2++;
	 }

	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f2.close();
	}

	else
	{
	 clrscr();
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	 getch();
	 clrscr();
	}
 }
}
//*************************************************** SINGAPORE ************************************************
else if(strcmpi(t.destination,"Singapore")==0)
 {
  cout<<endl<<endl<<endl<<"_______________________________________________________________________________";
  gotoxy(1,5);
  cout<<"S No.";
  gotoxy(10,5);
  cout<<"Airline";
  gotoxy(25,5);
  cout<<"Class";
  gotoxy(40,5);
  cout<<"Departure";
  gotoxy(55,5);
  cout<<"Arrival";
  gotoxy(65,5);
  cout<<"Price (in Rs.)"<<endl;
  cout<<"_______________________________________________________________________________";
  gotoxy(1,7);
  cout<<"1.";
  gotoxy(5,7);
  cout<<"Singapore Airlines";
  gotoxy(25,7);
  cout<<"Economy";
  gotoxy(40,7);
  cout<<"9:45 AM";
  gotoxy(55,7);
  cout<<"4:50 PM";
  gotoxy(68,7);
  cout<<"17,702";
  gotoxy(30,1);
  cout<<"ALL TIMES ARE LOCAL";
  gotoxy(27,18);
  cout<<"Press any key to continue .. ";
  getch();

  for(int i=0;i<3;i++)
  {
	clrscr();
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
  if((int)d.da_day==t.depart.dd )
  {
	fstream f1("Singapore-1a.dat",ios::out|ios::in|ios::binary);
	if(check(countsi1+t.passengers)==1)
	{
	 clrscr();
	 int j;
	 gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"8:45 AM");
	  strcpy(t.depart_time,"9:45 AM");
	  strcpy(t.flight_code,"SQ 225");
	  strcpy(t.airline,"Singapore Airlines");
	  t.gate=20;
	  t.travel_class='E';
	  t.total=t.price*t.passengers;
	  t.price=17702;	  f1.write((char *)&t,sizeof(t));
	  countsi1++;
	 }

	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f1.close();
	}

	else
	{
	 clrscr();
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	 getch();
	 clrscr();
	}
 }

 else if(((int)d.da_day)+1==t.depart.dd )
 {
	fstream f2("Singapore-2a.dat",ios::out|ios::in|ios::binary);

	if(check(countsi2+t.passengers)==1)
	{
	 clrscr();
	 int j;
    gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=3;i<t.passengers;i++,j++)
	 {
	  gotoxy(20,j);
	  cout<<"Enter name of passenger "<<(i+1);
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"8:45 AM");
	  strcpy(t.depart_time,"9:45 AM");
	  strcpy(t.flight_code,"SQ 225");
	  strcpy(t.airline,"Singapore Airlines");
	  t.gate=20;
	  t.travel_class='E';
	  t.price=17702;
	  t.total=t.price*t.passengers;
	  f2.write((char *)&t,sizeof(t));
	  countsi2++;
	 }

	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f2.close();
	}

	else
	{
	 clrscr();
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	 getch();
	 clrscr();
	}
 }
}
//*************************************************** HONG KONG ************************************************
else if(strcmpi(t.destination,"Hong Kong")==0)
 {
  cout<<endl<<endl<<endl<<"_______________________________________________________________________________";
  gotoxy(1,5);
  cout<<"S No.";
  gotoxy(10,5);
  cout<<"Airline";
  gotoxy(25,5);
  cout<<"Class";
  gotoxy(40,5);
  cout<<"Departure";
  gotoxy(55,5);
  cout<<"Arrival";
  gotoxy(65,5);
  cout<<"Price (in Rs.)"<<endl;
  cout<<"_______________________________________________________________________________";
  gotoxy(1,7);
  cout<<"1.";
  gotoxy(10,7);
  cout<<"Cathay Pacific";
  gotoxy(25,7);
  cout<<"Economy";
  gotoxy(40,7);
  cout<<"3:00 AM";
  gotoxy(55,7);
  cout<<"11:00 AM";
  gotoxy(68,7);
  cout<<"28,007";
  gotoxy(30,1);
  cout<<"ALL TIMES ARE LOCAL";
  gotoxy(27,17);
  cout<<"Press any key to continue .. ";
  getch();

  for(int i=0;i<3;i++)
  {
	clrscr();
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
  if((int)d.da_day==t.depart.dd )
  {
	fstream f1("Hong Kong-1a.dat",ios::out|ios::in|ios::binary);
	if(check(counthk1+t.passengers)==1)
	{
	 clrscr();
	 int j;
    gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=8;i<t.passengers;i++,j++)
	 {
	  gotoxy(17,j);
	  cout<<"Enter name of passenger "<<(i+1)<<" - ";
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"2:00 AM");
	  strcpy(t.depart_time,"3:00 AM");
	  strcpy(t.flight_code,"CK 154");
	  strcpy(t.airline,"Cathay Pacific");
	  t.gate=20;
	  t.travel_class='E';
	  t.price=28007;
	  t.total=t.price*t.passengers;
	  f1.write((char *)&t,sizeof(t));
	  counthk1++;
	 }

	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
    getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f1.close();
	}

	else
	{
	 clrscr();
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
	 gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	 getch();
	 clrscr();
	}
 }

 else if(((int)d.da_day)+1==t.depart.dd )
 {
	fstream f2("Hong Kong-2a.dat",ios::out|ios::in|ios::binary);

	if(check(counthk2+t.passengers)==1)
	{
	 clrscr();
	 int j;
	 gotoxy(8,3);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 for(i=4;i<=17;i++)
	 {
	  gotoxy(8,i); cout<<char(0);
	  gotoxy(71,i); cout<<char(0);
	 }
	 gotoxy(8,i);
	 for(i=1;i<=64;i++)
	  cout<<char(0);
	 gotoxy(20,5);
	 cout<<"Enter the Details of the Passengers";
	 for(i=0,j=3;i<t.passengers;i++,j++)
	 {
	  gotoxy(20,j);
	  cout<<"Enter name of passenger "<<(i+1);
	  gets(t.name[i]);
	  strcpy(t.boarding_time,"2:00 AM");
	  strcpy(t.depart_time,"3:00 AM");
	  strcpy(t.flight_code,"CK 154");
	  strcpy(t.airline,"Cathay Pacific");
	  t.gate=20;
	  t.travel_class='E';
	  t.price=28007;
	  t.total=t.price*t.passengers;
	  f2.write((char *)&t,sizeof(t));
	  counthk2++;
	 }

	 gotoxy(23,15);
	 cout<<"Press any key to continue ... ";
	 getch();
	 clrscr();
	 gen_ticket(t);
	 clrscr();
	 f2.close();
	}

	else
	{
	 clrscr();
	 gotoxy(22,11);cout<<"Sorry, This Flight is Completely Booked";
    gotoxy(21,12); cout<<"Press any key to go back to the main menu ";
	 getch();
	 clrscr();
	}
 }
} 
}//end of book_ticket()

void welcome()
{
 check_count=0;
 A:
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
 gotoxy(33,11);
 cout<<"3. Flying to";
 gotoxy(35,12);
 cout<<"4. Exit";
 gotoxy(33,14);
 cout<<"Choose - ";
 cin>>a;
 switch(a)
 {
  case 1:
	ABC.book_ticket();
	clrscr();
	break;
  case 2:
	shuttle();
	break;
  case 3:
	destinations();
	break;
  case 4:
	clrscr();
	gotoxy(34,10);
	cout<<"Thank You !!!";
	gotoxy(28,12);
	cout<<"Have a pleasant trip!! :)";
	delay(3);
	clrscr();
	exit(0);
	break;
  default:
	gotoxy(32,16);
	cout<<"Invaild Entry..";
	gotoxy(30,17);
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


