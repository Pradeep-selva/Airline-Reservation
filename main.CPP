#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<graphics.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
#include<iomanip.h>
 ifstream fin;                   int i=0;
 ofstream fout;
int strval(char s[]) //to validate strings
{
int k=0;int c=0;
for(int i =0; i<strlen(s); i++)
{
if(!(isalpha(s[i])|| s[i] ==' '))
k++;
if(s[i]==' ')
c++;
}
if(k !=0||c==strlen(s))
return 0;
else
return 1;
}
int intval(char s[])  //to validate integers
{
int k =0;
for(int i =0; i<strlen(s);i++)
{
if(!(isdigit(s[i])))
k++;
}
if(k!=0)
return 0;
else
{
int n =atoi(s);
return n;
}
}


class passenger
{
int ticket;
char nm[30];
char sex[5];
int age;
char nationality[30];
public:
int seatn;
passenger()  //constructor of class passenger
{
ticket=0;
strcpy(nm,"NULL");
strcpy(sex,"NULL");
strcpy(nationality,"NULL");
age=0;
seatn=0;
}
void getdata(); //to accept values for data members of class passengers
void showdata()//to diplay the datamembers of class passengers
{ cout<<"\n\t\tFLIGHT DETAILS~\n";
cout<<"\n\t\t-------------------------------"<<endl;
cout<<"\n       NAME: ";puts(nm);
cout<<"\n        AGE: "<<age;
cout<<"\n        SEX: ";puts(sex);
cout<<"\nNATIONALITY: ";puts(nationality);
cout<<"\n   SEAT NO.: "<<seatn;
cout<<"\n    TICKETS: "<<ticket;
cout<<"\n-------------------------------"<<endl;
}
void reset() // to initialize values of all datamembers to null
{
ticket=0;
strcpy(nm,"NULL");
strcpy(sex,"NULL");
strcpy(nationality,"NULL");
age=0;
seatn=0;
}
char *retname()  //accessor funtion to return nm
{
return nm;
}
int getticket() //accessor funtion to return ticket
{
return ticket;
}
};
void passenger::getdata()
{
randomize();
ticket = random(500-10+1)+10;
cout<<"\n\t\tTICKET: "<<ticket;
L:
cout<<"\n\t\tEnter your name  :  ";
char s[30];
gets(s);
int n = strval(s);
if(n==1)
strcpy(nm,s);
else
{
cout<<"\n\t\tINVALID INPUT!  Press any key to re-enter\n\t\t";
getch();
goto L;
}
L2:
cout<<"\n\t\tEnter your age  :  ";
char s1[30];
gets(s1);
age = intval(s1);
if(age==0)
{
cout<<"\n\t\tINVALID INPUT!  Press any key to re-enter\n\t\t";
getch();
goto L2;
}
L3:
cout<<"\n\t\tEnter your sex (M/F) :  ";
char s2[30];
gets(s2);
int n2= strval(s2);
if(n2 == 1&&(strcmpi(s2,"m")==0 || strcmpi(s2,"f")==0))
strcpy(sex,s2);
else
{
cout<<"\n\t\tINVALID INPUT!  Press any key to re-enter\n\t\t";
getch();
goto L3;

}
L4:
cout<<"\n\t\tEnter your nationality (ind/other) :  ";
char s3[30];
gets(s3);
int n3=strval(s3) ;
if(n3==1)
strcpy(nationality,s3);
else
{
cout<<"\n\t\tINVALID INPUT!  Press any key to re-enter\n\t\t";
getch();
goto L4;

}
}
class airline
{ int fno;
  char n[30];
  int dt;
  float cost;
  char des[30];
  int d,m,y;
  public:
  int sb;
  passenger s[10];
  int getfnum() //to return fno
  {
    return fno;
  }
  airline()//contructor for class airline
 {
   fno=0;
   strcpy(n,"NULL");
   strcmpi(des,"NULL");
   cost=0;
   d=m=y=0;
   dt=0;
  }
   void addf();//to accept values of all data members of class airline
   void modify();//to accept values of all dtat members of class airline for modification
   void displayf() //to display all values of datamembers of class airline in tabular
  {

    cout<<endl<<setw(3)<<fno<<setw(18)<<n<<" "<<setw(4)<<d<<"/"<<setw(3)<<m<<"/"<<setw(5)<<y<<setw(7)<<" "<<des<<setw(5)<<cost;
  }
  void displayt(int j)//to diplay data members in non tabular form
 {
   cout<<"\t\t";
   cout<<"\n-------------------------------";
   cout<<"\n\t  flight number:"<<fno;
   cout<<"\n\t  flight   name:"<<n;
   cout<<"\n\t  Passenger name:"<<s[j].retname();
   cout<<"\n\t    Destination:"<<des;
   cout<<"\n\t Departure Time:"<<dt;
   cout<<"\n\tdate of journey:"<<d<<"/"<<m<<"/"<<y;
   cout<<"\n\t    seat number:"<<s[j].seatn;
   cout<<"\n\t  ticket number:"<<s[j].getticket();
   cout<<"\n\t           cost:"<<cost;
   cout<<"\n";
   cout<<"-------------------------------";
  }
  void cancelticket(int j)//to null all values of s[j]
  {
   s[j].reset();
  }
  int returnfno()// accessor function to return fno
  {
    return fno;
  }
  char*returndes() // accessor function to return des
  {
    return des;
  }
  void displaypass();//to diplay all datamembers of containership class
 }A;


void airline::modify()
{

cout<<"\n\t\tFlight no: "<<fno;
Z1:
cout<<"\n\t\tEnter flight name:  ";
char q[30];gets(q);
int n4 =strval(q);
if(n4==1)
strcpy(n,q);
else
{
cout<<"\n\t\tINVALID INPUT!  Press any key to re-enter\n\t\t";
getch();
goto Z1;
}
Z2:
cout<<"\n\t\tEnter the departure time (24 hours format):  ";
char q1[30];gets(q1);
dt = intval(q1);
if(dt == 0||dt>24)
{
cout<<"\n\t\tINVALID INPUT! Press any key to re-enter\n\t\t";
getch();
goto Z2;
}
Z3:
cout<<"\n\t\tEnter flight destination:  ";
char q2[30];gets(q2);
int n5 =strval(q2);
if(n5==1)
strcpy(des,q2);
else
{
cout<<"\n\t\tINVALID INPUT!  Press any key to re-enter\n\t\t";
getch();
goto Z3;
}XX:
clrscr();
cout<<"\n\t\t----------ENTER TIME-----------\n\t\t";
Z4:
cout<<"\n\t\t Enter day  : ";
char q4[30];gets(q4);
d = intval(q4);
if(d<1 || d>31)
{
cout<<"\n\t\tINVALID INPUT! Press any key to re-enter\n\t\t";
getch();
goto Z4;
}
Z5:
cout<<"\n\t\tEnter months  :  ";
char q5[30];gets(q5);
m = intval(q5);
if(m<1|| m >12)
{
cout<<"\n\t\tINVALID INPUT! Press any key to re-enter\n";
getch();

goto Z5;
}
Z6:
cout<<"\n\t\tEnter year(from 2018-2025) :  ";
char q6[30];gets(q6);
y = intval(q6);
if(y<2018 || y>2025)
{
cout<<"\n\t\tINVALID INPUT! Press any key to re-enter\n";
getch();
goto Z6;
}
if(!(((m==1 ||m==3||m==5||m==7||m==8||m==10||m==12)&&(d>0 && d<=31))||!((m==4||m==6||m==9||m==11)&&(d>0&&d<31))||!(m==2&&(d>0&&d<29))))
{cout<<"\n\t\tINVALID INPUT! Press any key to re-enter\n";
getch();
goto XX;
}
Z7:
cout<<"\n\t\tEnter cost  :  ";
char q7[30];gets(q7);
cost = intval(q7);
if(cost == 0)
{
cout<<"\n\t\tINVALID INPUT! Press any key to re-enter\n";
getch();
goto Z7;
}
}

void airline::addf()
{
randomize();
fno = random(859-10+1)+10;
cout<<"\n\t\tFlight no: "<<fno;
G1:
cout<<"\n\t\tEnter flight name:  ";
char q[30];gets(q);
int n4 =strval(q);
if(n4==1)
strcpy(n,q);
else
{
cout<<"\n\t\tINVALID INPUT!  Press any key to re-enter\n";
getch();
goto G1;
}
G2:
cout<<"\n\t\tEnter the departure time(24 hour format):  ";
char q1[30];gets(q1);
dt = intval(q1);
if(dt == 0|| dt>24)
{
cout<<"\n\t\tINVALID INPUT! Press any key to re-enter\n";
getch();
goto G2;
}
G3:
cout<<"\n\t\tEnter flight destination:  ";
char q2[30];gets(q2);
int n5 =strval(q2);
if(n5==1)
strcpy(des,q2);
else
{
cout<<"\n\t\tINVALID INPUT!  Press any key to re-enter\n";
getch();
goto G3;
}XY:
clrscr();
cout<<"\n\t\t----------ENTER TIME-----------\n";
G4:
cout<<"\n\t\tEnter day  :  ";
char q4[30];gets(q4);
d = intval(q4);
if(d<1 || d>31)
{
cout<<"\n\t\tINVALID INPUT! Press any key to re-enter\n\n\t\t";
getch();
goto G4;
}
G5:
cout<<"\n\t\tEnter months  :  ";
char q5[30];gets(q5);
m = intval(q5);
if(m<1|| m >12)
{
cout<<"\n\t\tINVALID INPUT! Press any key to re-enter\n";
getch();

goto G5;
}
G6:
cout<<"\n\t\tEnter year(from 2018-2025):  ";
char q6[30];gets(q6);
y = intval(q6);
if(y<2018 || y>2025)
{
cout<<"\n\t\tINVALID INPUT! Press any key to re-enter\n";
getch();
goto G6;
}
if(!(((m==1 ||m==3||m==5||m==7||m==8||m==10||m==12)&&(d>0 && d<=31))||((m==4||m==6||m==9||m==11)&&(d>0&&d<31))||(m==2&&(d>0&&d<29))))
{cout<<"\n\t\tINVALID INPUT! Press any key to re-enter\n";
getch();
goto XY;
}
G7:
cout<<"\n\t\tEnter cost  :  ";
char q7[30];gets(q7);
cost = intval(q7);
if(cost == 0)
{
cout<<"\n\t\tINVALID INPUT! Press any key to re-enter\n";
getch();
goto G7;
}
}
void airline::displaypass()
{
   int u=0;
   for(int b=0;b<10;++b)
   {
    if(s[b].seatn!=0)
    {
     if(u==0)
     {
      cout<<endl<<"\t\t   "<<setw(10)<<"Ticket_No"<<setw(20)<<"Name"<<setw(10)<<"Seat_No";
      cout<<endl<<"\t\t   -----------------------------------------------";
     }
     ++u;
     cout<<endl<<"\t\t   "<<setw(10)<<s[b].getticket()<<setw(20)<<s[b].retname()<<setw(10)<<s[b].seatn;
    }
   }
}
void bookticket() // to book a ticket
{
int a;
int f1 =0;
A1:
cout<<"\n\t\tEnter flight number  :\n";
char q8[30];gets(q8);
a = intval(q8);
if(a == 0)
{
cout<<"\n\t\tINVALID INPUT! Press any key to re-enter\n";
getch();
goto A1;
} fstream f;
 f.open("flight.dat",ios::in|ios::out|ios::binary);

	   if(!f){cout<<"ERROR";exit(1);}
	   while(!f.eof())
	   {
	    int poo = f.tellg();
	    f.read((char*)&A,sizeof(A));
	    if(f.eof())break;
	if(A.returnfno() == a)
	    {
	     f1 = 1;
	     if(A.sb ==10)
		    {
		     cout<<"\n\n\t\t Seats are full\n";
		       getch();
		       break;

		    }
	     else
	     {
	      for(int j = 0; j<10; j++)
		 {
		  if(A.s[j].seatn==0)
		   {
		    A.s[j].getdata();
		    A.s[j].seatn = j+1;
		    A.sb++;
		    f.seekp(poo);
		    f.write((char*)&A,sizeof(A));
		    cout<<"\n\n\t\t Seat Booked\n";
		    cout<<"\n\t\tPress 'y' key and press enter to book another seat\n";
		    cout<<"\n\t\tPress any other key and press enter to go to menu\n";
		    char ch;
		    cin>>ch;
		    if(ch!='y')
		    break;

		   }
		 }
	      }
 } }
f.close();
if(f1==0)
cout<<"\n\n\t\t FLIGHT NOT FOUND\n";

}
void header() //to display the default header part of the program
{
clrscr();
textmode(3);
textbackground(GREEN);
textcolor(BLUE);
cprintf( "   \b\b\b\b                                                 ");
cprintf( "                                                            ");
cprintf( " AIRLINE RESERVATION SYSTEM                                 ");
cprintf( "                                                                       ");
textmode(3);
 textbackground(WHITE);
 textcolor(BLUE);
}
 void main()   //main funtions
{
clrscr();
 int ch;

 int gd=DETECT,gm;

 initgraph(&gd,&gm,"c:\\tc\\bgi");

 setbkcolor(EGA_GREEN);
 settextstyle(0,0,4.5);
  rectangle(20,20,620,400);
 outtextxy(230,100,"AIRLINE");
 outtextxy(30,200,"RESERVATION SYSTEM");

 settextstyle(0,0,2.0);
 outtextxy(300,440,"Project done by ");
 outtextxy(350,460,"Pradeep & Anirudh ");
 delay(3500);

 textmode(3);
 textbackground(WHITE);
 textcolor(BLUE);
 int n=0;
 A2:
 header();

 gotoxy(15,8);
 textmode(3);
 textbackground(EGA_BLUE);
 textcolor(WHITE);
 cprintf("                          MENU                             ");
 textmode(3);
 textbackground(WHITE);
 textcolor(BLUE);
  gotoxy(15,9);
 cprintf("1.Add Flight");
  gotoxy(15,10);
 cprintf("2.Modify Flight");
  gotoxy(15,11);
 cprintf("3.List all Flights");
  gotoxy(15,12);
 cprintf("4.List all flight to a destination");
  gotoxy(15,13);
 cprintf("5.Delete a Flight");
  gotoxy(15,14);
 cprintf("6.Book a ticket");
  gotoxy(15,15);
 cprintf("7.View a ticket");
  gotoxy(15,16);
 cprintf("8.Delete a Ticket");
  gotoxy(15,17);
 cprintf("9.List all passengers of a flight");
  gotoxy(15,18);
 cprintf("10.To exit");
 gotoxy(15,19);
 cprintf("ENTER YOUR CHOICE");
 cout<<endl;  cout<<"\t\t\t";
char cha[1];gets(cha);
ch = intval(cha);
if(ch<1 || ch>10)
{
cout<<"\n\t\tINVALID INPUT! press any key to re-enter\n";

getch();
goto A2;
}
 switch(ch)
{
case 1: clrscr();
	header();
	fout.open("flight.dat",ios::app|ios::binary);
	if(!fout){cout<<"ERROR";exit(1);}
	textmode(3);
 textbackground(EGA_BLUE);
 textcolor(WHITE);
   gotoxy(17,6);
       cprintf("ADDING NEW FLIGHT");
	A.sb=0;
	textmode(3);
 textbackground(WHITE);
 textcolor(BLUE);
	A.addf();
	fout.write((char*)&A,sizeof(A));
	   gotoxy(17,6); clrscr();header();
	cprintf("FLIGHT ADDED SUCCESSFULY");
	n++;
	gotoxy(17,7);
	cprintf("Press any key to go to menu ");
			fout.close();
	getch();
	goto A2;

case 2:clrscr();
	header();
       if(n==0)                                           {
       cout<<"\n\t\tNO ENTRIES.Press any key to go to menu\n";

       getch();
       goto A2;}
       textmode(3);
 textbackground(EGA_BLUE);
 textcolor(WHITE);              gotoxy(17,7);
       cprintf("MODIFYING FLIGHT");
       textmode(3);
 textbackground(WHITE);
 textcolor(BLUE);
       int c;
       A3:
       cout<<"\n\t\tEnter flight number\n";
       char ert[30];
       gets(ert);
       c = intval(ert);
       if(c==0)
       {
       cout<<"\n\t\tINVALID INPUT! press any key to re-enter\n";

       getch();
       goto A3;
       }int k =0;
       fin.open("flight.dat",ios::in|ios::binary);
       fout.open("temp.dat",ios::app|ios::binary);
       if(!fin||!fout){cout<<"ERROR";exit(1);}
       while(!fin.eof())
       {
       fin.read((char*)&A,sizeof(A));
       if(fin.eof())break;
       if(A.returnfno() == c)
       {
	 k++;
	A.modify();

	fout.write((char*)&A,sizeof(A));
	}
	else
		fout.write((char*)&A,sizeof(A));

	}
	fout.close();
	fin.close();
	if(k==0)                   {
	cout<<"\n\t\tRECORD NOT FOUND\n";
	cout<<"\n\t\tPRESS ANY KEY TO EXIT TO MENU\n";

	getch();
	}
	else
	{ remove("flight.dat");
	rename("temp.dat","flight.dat" );
	 gotoxy(17,7);   clrscr();
	      cprintf("DETAILS MODIFIED SUCCESFULLY");

 cout<<endl;
  cout<<"\n\t\t\t Press any key to exit to main menu\n";
	   } getch();
	goto A2;
    case 3: clrscr(); 	header();
     if(n==0)                                           {
       cout<<"\n\t\tNO ENTRIES.Press any key to go to menu\n";
	      getch();
       goto A2;}
    textmode(3);
 textbackground(EGA_BLUE);
 textcolor(WHITE);      gotoxy(17,7);
	      cprintf("DISPLAYING DETAILS...");
	    textmode(3);
 textbackground(WHITE);
 textcolor(BLUE);   int ii=0;
	 //   cout<<endl<<setw(3)<<"FNo."<<setw(18)<<"NAME"<<" "<<setw(12)<<"DATE"<<setw(7)<<" "<<"DEST."<<setw(5)<<"COST";
	   fin.open("flight.dat",ios::in|ios::binary);
	   if(!fin){cout<<"ERROR";exit(1);}
	   while(!fin.eof())
	   {
	    fin.read((char*)&A,sizeof(A));
	    if(fin.eof())break;
	    ii+=1;
	    if(ii==1)
	    cout<<endl<<setw(3)<<"FNo."<<setw(18)<<"NAME"<<" "<<setw(12)<<"DATE"<<setw(7)<<" "<<"DEST."<<setw(5)<<"COST";
	    A.displayf();cout<<endl;
	   }
	    if (ii==0)
	       cout<<"\n\t\tNO FLIGHTS...";
	    cout<<"\n\t\tPress any key to go to main\n";
	    fin.close();
	    getch();
	    goto A2;
    case 4:clrscr();	header();
       if(n==0)                                           {
       cout<<"\n\t\tNO ENTRIES.Press any key to go to menu\n";

       getch();
       goto A2;}
	    A8:
	    cout<<"\n\t\tEnter Destination: \n";
	    char o[30];char o1[30];
	    gets(o1);
	    int w = strval(o1);
	    if(w == 1)
	    strcpy(o,o1);
	    else
	    {
	    cout<<"\n\t\tINVALID INPUT! press any key to re-enter\n" ;

	    getch();
	    goto A8;
	    }
	   textmode(3);
 textbackground(EGA_BLUE);
 textcolor(WHITE);      gotoxy(17,7); clrscr();header();
	    cprintf("DISPLAYING DETAILS OF FLIGHTS");
	    textmode(3);
 textbackground(WHITE);
 textcolor(BLUE);
	 //	cout<<endl<<setw(3)<<"FNo."<<setw(18)<<"NAME"<<" "<<setw(12)<<"DATE"<<setw(7)<<" "<<"DEST."<<setw(5)<<"    "<<"COST";
	   int u=0;
	    fin.open("flight.dat",ios::in|ios::binary);
	   if(!fin){cout<<"ERROR";exit(1);}
	   while(!fin.eof())
	   {
	    fin.read((char*)&A,sizeof(A));
	    if(fin.eof())break;
	   if(strcmpi(o,A.returndes())==0)
	  {u++;
	  if(u==1)
	     cout<<endl<<setw(3)<<"FNo."<<setw(18)<<"NAME"<<" "<<setw(12)<<"DATE"<<setw(7)<<" "<<"DEST."<<setw(5)<<"    "<<"COST";
	  A.displayf();
	    }
	    }
	    if(u==0)
	    {clrscr();
		header();

	    cout<<"\n\t\t RECORD NOT FOUND.\n";

	    }
	    cout<<"\n\t\tPress any key to go to main\n";
			fin.close();
	    getch();
	    goto A2;

  case 5:    clrscr();	header();
	   if(n==0)                                           {
       cout<<"\n\t\tNO ENTRIES.Press any key to go to menu\n";

       getch();
       goto A2;}
       textmode(3);
 textbackground(EGA_BLUE);
 textcolor(WHITE);              gotoxy(17,7);
       cprintf("DELETING FLIGHT");
       textmode(3);
 textbackground(WHITE);
 textcolor(BLUE);
       int c1;
       Am:
       cout<<"\n\t\tEnter flight number\n";
       char ert1[30];
       gets(ert1);
       c1 = intval(ert1);
       if(c1==0)
       {
       cout<<"\n\t\tINVALID INPUT! press any key to re-enter\n";

       getch();
       goto Am;
       }
       int k1 =0;
       fin.open("flight.dat",ios::in|ios::binary);
       fout.open("temp.dat",ios::out|ios::binary);
       if(!fin||!fout){cout<<"ERROR";exit(1);}
       while(!fin.eof())
       {
       fin.read((char*)&A,sizeof(A));
       if(fin.eof())break;
       if(A.returnfno() != c1)
       {
	 fout.write((char*)&A,sizeof(A));
	}
	else
	k1++;

	}
	fout.close();
	fin.close();
	if(k1==0)                   {
	cout<<"\n\t\tRECORD NOT FOUND\n";
	cout<<"\n\t\tPRESS ANY KEY TO EXIT TO MENU\n";

	getch();
	}
	else
	{ remove("flight.dat");
	rename("temp.dat","flight.dat" );
	 gotoxy(17,7);   clrscr();
	      cprintf("RECORDS DELETED SUCCESFULLY");

 cout<<endl;
  cout<<"\n\t\t\t Press any key to exit to main menu\n";
	   } getch();
	goto A2;

  case 6: clrscr();	header();
  if(n==0)                                           {
       cout<<"\n\t\tNO ENTRIES.Press any key to go to menu\n";

       getch();
       goto A2;}
      textmode(3);
 textbackground(EGA_BLUE);
 textcolor(WHITE);      gotoxy(17,7);
	cprintf("BOOKING TICKETS...\n");
	textmode(3);
 textbackground(WHITE);
 textcolor(BLUE);
	  bookticket();



	  getch();
	  goto A2;
  case 7: clrscr();	header();
	 if(n==0)                                           {
       cout<<"\n\t\tNO ENTRIES.Press any key to go to menu\n";

       getch();
       goto A2;}
	  An:
	  int c2=0;
       cout<<"\n\t\tEnter flight number\n";
       char ert2[30];
       gets(ert2);
       c2 = intval(ert2);
       if(c2==0)
       {
       cout<<"\n\t\tINVALID INPUT! press any key to re-enter\n";

       getch();
       goto An;
       }
	A4:
       cout<<"\n\t\tEnter Ticket no.: \n";
       char et[30];
       gets(et);
       int tic = intval(et);
       if(tic==0)
       {
       cout<<"\n\t\tINVALID INPUT! press any key to re-enter\n";

       getch();
       goto A4;
       } int km=0;     int kk=0;
       textmode(3);
 textbackground(EGA_BLUE);
 textcolor(WHITE);      gotoxy(17,7);   clrscr();
       cprintf("DISPLAYING DETAILS...");
       textmode(3);
 textbackground(WHITE);
 textcolor(BLUE);
       fin.open("flight.dat",ios::in|ios::binary);
	   if(!fin){cout<<"ERROR";exit(1);}
	   while(!fin.eof())
	   {
	    fin.read((char*)&A,sizeof(A));
	    if(fin.eof())break;

	 if(A.returnfno()== c2)
	 {
		   kk++;
		   for(int n=0; n<10;n++)
		   {
		      if(tic==A.s[n].getticket())
			 {km++;
			 A.displayt(n);
			  }
		   }
	 }
       }
       if(km==0)
       {
       cout<<"\n\t\tTICKET NOT FOUND\n" ;
       }
       else if(kk==0)
       cout<<"\n\t\tFLIGHT NOT FOUND\n";
       cout<<"\n\t\tPress any key to go to menu\n ";
				    fin.close();
       getch();
       goto A2;

  case 8: clrscr();	header();
	 if(n==0)                                           {
       cout<<"\n\t\tNO ENTRIES.Press any key to go to menu\n";

       getch();
       goto A2;}
       textmode(3);
 textbackground(EGA_BLUE);
 textcolor(WHITE);      gotoxy(17,7);
       cprintf("CANCEL TICKETS");
       textmode(3);
 textbackground(WHITE);
 textcolor(BLUE);  int c3;
      Ak:
       cout<<"\n\t\tEnter flight number\n";
       char ert3[30];
       gets(ert3);
       c3 = intval(ert3);
       if(c3==0)
       {
       cout<<"\n\t\tINVALID INPUT! press any key to re-enter\n";

       getch();
       goto Ak;
       }
	A5:
       cout<<"\n\t\tEnter Ticket no.: \n";
       char tt[30];
       gets(tt);
       int ticc = intval(tt);
       if(ticc==0)
       {
       cout<<"\n\t\tINVALID INPUT! press any key to re-enter\n";

       getch();
       goto A5;
       } int  k2=0;  int ky=0;fstream ff;
	ff.open("flight.dat",ios::in|ios::out|ios::binary);

	   if(!ff){cout<<"ERROR";exit(1);}
	   while(!ff.eof())
	   {   int poss= ff.tellg();
	    ff.read((char*)&A,sizeof(A));
	    if(ff.eof())break;
	    if(A.returnfno()== c3)
	 {
		   ky++;
		   for(int n=0; n<10;n++)
		   {
       if(ticc==A.s[n].getticket())
       {
	 k2++;
	 A.cancelticket(n);
	 A.sb--;
	 ff.seekp(poss);


	ff.write((char*)&A,sizeof(A));
       }

       }
       }
       }

       ff.close();
       if(kk==0)
      { cout<<"\n\t\tFLIGHT NOT FOUND\n"; getch();goto A2;}
       if(k2==0)
       {
       cout<<"\n\t\tTICKET NOT FOUND\n" ;getch();goto A2;  }

       cout<<"\n\t\tRECORD DELETED\n";
       cout<<"\n\t\tPress any key to go to menu\n ";

       getch();
       goto A2;

 case 9:clrscr(); 	header();
      if(n==0)                                           {
       cout<<"\n\t\tNO ENTRIES.Press any key to go to menu\n";

       getch();
       goto A2;}
	    A6:
	    cout<<"\n\t\tEnter Flight no.: \n";
	    int b;char b1[30];
	    gets(b1);
	    b = intval(b1);
	    if(b == 0)
		    {
	    cout<<"\n\t\tINVALID INPUT! press any key to re-enter\n";

	    getch();
	    goto A6;
	    }
	   int uu=0;
	 textmode(3);
 textbackground(EGA_BLUE);
 textcolor(WHITE);      gotoxy(17,7);                clrscr();    header();
	   cprintf("DISPLAYING DETAILS OF PASSENGER");
	   textmode(3);
 textbackground(WHITE);
 textcolor(BLUE);
	    cout<<endl;int ccc=0;
	    fin.open("flight.dat",ios::in|ios::binary);
	   if(!fin){cout<<"ERROR";exit(1);}
	   while(!fin.eof())
	   {
	    fin.read((char*)&A,sizeof(A));
	    if(fin.eof())break;
	   if(b==A.returnfno())
	   { uu++;
		   if(A.sb!=0)
		   { ccc++;
		    A.displaypass();  }
	    }
	    }
	    if(uu==0||ccc==0)
	    {clrscr();
		header();

	    cout<<"\n\t\tRECORD NOT FOUND.\n";

	    }

	    cout<<"\n\t\tPress any key to go to main\n";
							    fin.close();
	    getch();
	    goto A2;
 case 10:    clrscr();             textmode(3);
 textbackground(EGA_BLUE);
 textcolor(WHITE);      gotoxy(17,7);
	 cprintf("PRESS ANY KEY TO EXIT\n"); textmode(3);
 textbackground(WHITE);   remove("flight.dat");
 textcolor(BLUE);
	 getch();
	 cout<<"\n\t\t...Exitting...\n";   delay(1000);
	 exit(0);
	 break;
 default:
	cout<<"\n\t\tINVALID INPUT! Press any key to go to menu\n";

	getch();
	goto A2;
	}



    }