#include<iostream.h>
#include<conio.h>
#include<time.h>

float delay1(float b)
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
void border()
{
for(int i=2;i<=79;i++)
{
 gotoxy(i,1);cout<<"-";
 gotoxy(i,25);cout<<"-";
}
for(int j=2;j<25;j++)
{
 gotoxy(2,j);cout<<"|";
 gotoxy(79,j);cout<<"|";
}

}
void pic(int i)
{
gotoxy(i,9); cout<<"|---\\            |---\\ "<<endl;
gotoxy(i,10);cout<<"|    \\           |    \\ "<<endl;
gotoxy(i,11);cout<<"----------------------------\\"<<endl;
gotoxy(i,12);cout<<"|     []  []  []             \\ "<<endl;
gotoxy(i,13);cout<<"-------------------------------"<<endl;
gotoxy(i,14);cout<<"                 |    / "<<endl;
gotoxy(i,15);cout<<"                 |---/ "<<endl;
}
plane()
{
for(int i=1;i<=45;i++)
{
gotoxy(30,3);cout<<" AIRTRAVEL.com \n";
gotoxy(29,4);cout<<"Fly to your DREAM\n";
pic(i);
border();
delay1(0.001);
clrscr();
}

}
