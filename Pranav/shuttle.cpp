#include<iostream.h>
void shuttle()
{

 clrscr();
 gotoxy(50,5);
 cout<<"MAP OF BANGALORE CITY";
 gotoxy(55,6);
 cout<<"NOT TO SCALE";
 gotoxy(50,9);
 cout<<"Press a key to continue ";
 gotoxy(35,3);
 cout<<" BIAL  ";
 gotoxy(33,3);
 cout<<"..";
 for(int i=3;i<=23;i++)
 {
  if(i==7 || i==13 || i==23)
	{gotoxy(33,i); cout<<"@";}
  else
  {gotoxy(33,i); cout<<".";}
 }
 gotoxy(8,11); cout<<"..........................";
 gotoxy(8,12); cout<<".";
 gotoxy(8,13); cout<<".";
 gotoxy(8,14); cout<<".";
 gotoxy(8,15); cout<<".";
 gotoxy(8,16); cout<<"@";
 gotoxy(33,15); cout<<"...................@";
 gotoxy(53,15); cout<<"...................@";
 gotoxy(27,17); cout<<"......";
 gotoxy(26,18); cout<<".";
 gotoxy(25,19); cout<<".";
 gotoxy(24,20); cout<<".";
 gotoxy(23,21); cout<<".";
 gotoxy(22,22); cout<<".";
 gotoxy(18,22); cout<<"@....";
 gotoxy(5,21); cout<<"Basavanagudi (8)";
 gotoxy(33,17); cout<<"......";
 gotoxy(39,18); cout<<".";
 gotoxy(40,19); cout<<".";
 gotoxy(41,20); cout<<".";
 gotoxy(42,21); cout<<".";
 gotoxy(43,22); cout<<"............@";
 gotoxy(46,21); cout<<"Electronics City (7)";
 gotoxy(65,16); cout<<"Whitefield (6)";
 gotoxy(47,16); cout<<"M G Road (4)";
 gotoxy(4,17); cout<<"Mysore Road (3)";
 gotoxy(22,7); cout<<"Hebbal (1)";
 gotoxy(35,13); cout<<"Majestic (2)";
 gotoxy(24,24); cout<<"Jayanagar 4th Block (5)";
 gotoxy(74,9);
 getch();
 clrscr();
 cout<<endl<<endl<<"________________________________________________________________________________"<<endl;
 gotoxy(5,4); cout<<"Start";
 gotoxy(25,4); cout<<"End";
 gotoxy(30,4); cout<<"Bus Number";
 gotoxy(45,4); cout<<"First Departure";
 gotoxy(65,4); cout<<"Frequency"<<endl;
 cout<<"________________________________________________________________________________"<<endl;
 gotoxy(5,6); cout<<"Hebbal"; gotoxy(25,6); cout<<"BIA"; gotoxy(32,6); cout<<"BIA 1"; gotoxy(45,6); cout<<"4:00 AM"; gotoxy(65,6); cout<<"1 hour";
 gotoxy(5,8); cout<<"Majestic"; gotoxy(25,8); cout<<"BIA"; gotoxy(32,8); cout<<"BIA 2"; gotoxy(45,8); cout<<"4:30 AM"; gotoxy(65,8); cout<<"1 hour";
 gotoxy(5,10); cout<<"Mysore Road"; gotoxy(25,10); cout<<"BIA"; gotoxy(32,10); cout<<"BIA 3"; gotoxy(45,10); cout<<"5:00 AM"; gotoxy(65,10); cout<<"0.5 hours";
 gotoxy(5,12); cout<<"M G Road"; gotoxy(25,12); cout<<"BIA"; gotoxy(32,12); cout<<"BIA 4"; gotoxy(45,12); cout<<"5:00 AM"; gotoxy(65,12); cout<<"1 hour";
 gotoxy(5,14); cout<<"Jayangar 4th Block"; gotoxy(25,14); cout<<"BIA"; gotoxy(32,14); cout<<"BIA 5"; gotoxy(45,14); cout<<"5:00 AM"; gotoxy(65,14); cout<<"1.5 hours";
 gotoxy(5,16); cout<<"Whitefield"; gotoxy(25,16); cout<<"BIA"; gotoxy(32,16); cout<<"BIA 6"; gotoxy(45,16); cout<<"5:00 AM"; gotoxy(65,16); cout<<"1.5 hours";
 gotoxy(5,18); cout<<"Electonics City"; gotoxy(25,18); cout<<"BIA"; gotoxy(32,18); cout<<"BIA 7"; gotoxy(45,18); cout<<"6:00 AM"; gotoxy(65,18); cout<<"2 hours";
 gotoxy(5,20); cout<<"Basavanagudi"; gotoxy(25,20); cout<<"BIA"; gotoxy(32,20); cout<<"BIA 8"; gotoxy(45,20); cout<<"5:00 AM"; gotoxy(65,20); cout<<"1.5 hours"<<endl;;
 cout<<"________________________________________________________________________________"<<endl;
 gotoxy(30,23); cout<<"Press a key to continue ";
 getch();
 clrscr();
}
