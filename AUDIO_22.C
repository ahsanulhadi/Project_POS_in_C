#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<ctype.h>
#include<graphics.h>

#define AT(X,Y,tc,S); { gotoxy(X,Y); textcolor(tc);cprintf(S);}

void front_p(void);
void fillup(int x1, int y1, int x2, int y2,char fill);
void w_box(int x1,int y1, int x2, int y2, int type, int fg, int bg, char fill);


void x_line(int x,int y,int x2,int y2,char c,int clr);
void y_line(int x,int y,int x2,int y2,char c,int clr);
void joint(int x,int y,char c,int clr);


void box(int x1,int y1,int x2,int y2,int clr);
void c_box(int x1,int y1,int x2,int y2,int clr);
void border(int x1,int y1,int x2, int y2,int clr);

void m_switch();
char menu();


void stk_switch();
char stk_menu();
void inp_stk();
void outp_stk();
void srch_stk();
void del_stk();
void stk_filedel();


void pur_switch();
char pur_menu();
void pur_inp();
void pur_outp();
void srch_pur();
void r_order();
void pur_filedel();


void sl_switch();
char sl_menu();
void outp_rec();
void outp_slp();
void inp_ord();
void inp_pay();
void deliverN();


void rep_switch();
char rep_menu();
void ts_report();
void ps_report();

void adm_switch();
char adm_menu();
void inp_rec();
void inp_slp();
void rec_mody();
void slp_mody();


void col_switch();
char col_menu();
void inp_song();
void outp_col();
void del_col();

void hlp_guide();



struct brand{
	int c_no;
	char b_name[10];
	char  b_type[10];
	int   qty;
	int   reorder;
	};


struct catagory{
	char c_name[10];
	int c_no;

	}  c[] ={"cassette",1,"cd",2 };



struct  Date{
	 int day;
	 int month;
	 int year;
	};


struct purchase{

	int    c_no;
	char   b_type[10];
	int    qty;
	int    p_price;
	struct Date pd;

	};


struct slprice{

	char  b_type[10];
	int   sl_price;

	};



struct reccharge{

	char  rec_type[10];
	int   rec_chrg;

	};


struct cassale{

	int    memo_no;
	char   type[10];
	int    qty;
	int    price;

	};



struct delivery{

	int    memo_no;
	char   cus_name[20];
	char   deliver;
	struct Date od;
	struct Date md;
	struct Date ad;

	};


struct payments{

	int memo_no;
	int receive;
	int due;
	struct Date rd;

	};


struct songtype{
	char t_name[10];
	int t_no;

	} st [] ={"BANGLA",1,"ENGLISH",2 };


struct  Time{
	 int min;
	 int sec;
	};




struct collection{
	int t_no;
	char album[20];
	char artiste[30];
	struct Time t;
	};





/************************* LINE JOINT FUNCTION ****************************/



void joint(int x,int y,char c,int clr)
{

  textattr(clr);
  gotoxy(x,y);   cprintf("%c",c );

}


/************************ TO PRINT A ROW ( x_line) **********************/


void x_line(int x,int y,int x2,int y2,char c,int clr)
{

  int p,q;
  textattr(clr);

	for(q=y;q<=y2;++q)
	  {
	for(p=x;p<=x2;p++)
	   {
		 gotoxy(p,q);
		 cprintf("%c",c);
		  }
	 }

}



/**********************  TO PRINT A COLUMN ( y_line)  ********************/


void y_line(int x,int y,int x2,int y2,char c,int clr)
{

  int i,j;
  textattr(clr);

	for(i=y;i<y2;i++)
	 {
	   for(j=x;j<=x2;j++)
	 {
	   gotoxy(j,i);
	   cprintf("%c",c);
	  }
	   }

}


/***************************    FOR BOX (Shading)   *****************************/

	 /*-------------------- FOR BOX ---------------------*/


void box(int x1,int y1,int x2,int y2,int clr)
{
  int i,j;
  textattr(clr);

	for(i=x1;i<x2;i++)
	   {
		 for(j=y1;j<y2;j++)
		 {
		   gotoxy(i,j);
		   cprintf("°" );
		 }

	 }

}


/*****************************  FOR COLOUR BOX   **************************/



void c_box(int x1,int y1,int x2,int y2,int clr)
{

 int i,j;
 textattr(clr);
   for(i=x1;i<x2;i++)
	   {
	  for(j=y1;j<y2;j++)
		{
		  gotoxy(i,j);
		  cprintf(" " );
		 }

	  }

}



/******************************  (RECTANGALE) BORDER   ******************************/


void border(int x1,int y1,int x2, int y2,int clr)
{
	int i,j;
	textattr(clr);

	for(i = x1; i<x2; i++)
	{
		gotoxy(i,y1);
		cprintf("%c",196);
		gotoxy(i,y2);
		cprintf("%c",196);
	}
	for(j = y1; j<y2; j++)
	{
		gotoxy(x1,j);
		cprintf("%c",179);
		gotoxy(x2,j);
		cprintf("%c",179);
	}
	gotoxy(x1,y1);
	cprintf	("%c",218);
	gotoxy(x2,y1);
	cprintf("%c",191);
	gotoxy(x1,y2);
	cprintf("%c",192);
	gotoxy(x2,y2);
	cprintf("%c",217);

}



/***********************  FRONT PAGE OF THE PROGRAM  ***********************/



void front_p(void)
{

	int y,z;
  //	int music[6] = {1500,900,1600,900,1700};
	int i;


	char *str = "Û";

	textbackground(BLACK);
	textcolor(WHITE);
	clrscr();

	w_box(2,1,79,25,1,DARKGRAY,LIGHTCYAN,176);         //MAIN BORDER.

	w_box(21,4,60,6,4,LIGHTGRAY,BLACK,178);     // SHADE ,,  .
	w_box(20,3,59,5,4,YELLOW,LIGHTGRAY,' ');   //TITLE  ,,  .
	AT(23,4,RED,"þ  AUDIO RECORDING CENTRE  þ");

	w_box(22,10,62,23,4,BLACK,BLACK,178);     // SHADE ,,  .
	w_box(20,9,60,22,1,DARKGRAY,LIGHTGRAY,' ');
	AT(23,10,BLACK,"IDCS-PROJECT, 18th Batch, MAR 2000.");
	AT(22,11,BLACK,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	AT(23,12,BLUE,"þ Project Manager:");
	  AT(27,13,RED,"MD.IMRANUL QUADER IMU");
		AT(32,14,BROWN,"(M.Sc in Computer science)");
	AT(23,15,BLUE,"þ Designed & Developed by:");
	  AT(27,16,RED,"AHSAN UL HADI ADIL.");
	AT(23,17,BLUE,"þ My Gratitude to:");
	  AT(27,18,RED,"IMU Bhai.");
	  AT(27,19,RED,"MD.ZULKERNINE RISVI.");
		AT(41,20,BROWN,"(Ncc-IAD student)");

	  c_box(5,24,77,25,0x44);
	  gotoxy(5,24);     // LOADING.
	  for(y=0;y<72;y+=1)
		{
		  z=26;
		  textattr(0x1e);
		  cputs(str);
		  textattr(0x03);
			  for(i = 0; i <2;i++)
				 {
				  sound(90-y);
				 //  sound(music[i]);
				   delay(100);
				  }
		  movetext(1,1, strlen(str),1,y,z);
		  }
		sound(90-y);
		delay(3000);
	   nosound();

}


//----------------------- FRONT WINDOW BOX .


void w_box(int x1,int y1, int x2, int y2, int type, int fg, int bg, char fill)
   {
	 int i, lt, rt, lb, rb, hr, vt;
	 textcolor(fg); textbackground(bg);
	 switch (type)
		  {
			case 1:
				lt=201; rt=187;hr=205;lb=200;rb=188;vt=186;
				break;
			default:
				lt=218;rt=191;hr=196;lb=192;rb=217;vt=179;
				break;
		   }

	 fillup(x1,y1,x2,y2,fill);

	 gotoxy(x1,y1); putch(lt);
	 gotoxy(x2,y1); putch(rt);
	 gotoxy(x1,y2); putch(lb);
	 gotoxy(x2,y2); putch(rb);

	 for(i=x1+1;i<x2;i++)
		   {
			 gotoxy(i,y1); putch(hr);
			 gotoxy(i,y2); putch(hr);
			}

	 for(i=y1+1;i<y2;i++)
			{
			 gotoxy(x1,i); putch(vt);
			 gotoxy(x2,i); putch(vt);
			 }

		}


//-------------------  BACKGROUND FOR FRONT PAGE .


void fillup(int x1, int y1, int x2, int y2,char fill)
 {

  int i, x12,y12;
  x12=(x1+x2)/2; y12=(y1+y2)/2;

	 for(;(x1<=x12) && (y1<=y12); x1+=3,y1++,x2-=3,y2--)
		 {
		  for(i=x1;i<=x2;i++)
			  {
			   gotoxy(i,y1);
			   putch(fill);
			   }
			  for(i=y1+1;i<=y2;i++)
				   {
					gotoxy(x2-2,i);
					cprintf("%c%c%c",fill,fill,fill);
					}
				 for (i=x2-1;i>=x1;i--)
					   {
						gotoxy(i,y2);
						putch(fill);
						}
					 for(i=y2-1;i >= y1+1;i--)
							{
							 gotoxy(x1,i);
							 cprintf("%c%c%c",fill,fill,fill);
							 }

		  }

 }






/**************************** FUNTION NO: [1] *****************************/
		 /*-------------- MAIN() --------------*/

void main()
{
 clrscr();
 front_p();
 m_switch();
// c_box(0,0,81,26,0x0f);     // Clear all the screen.
clrscr();
}





/*********************   FOR MENU SELECTION & SWITCHING  *******************/



void m_switch()


{
	char ch;
	int n;
	  do
	  {
	  clrscr();
	  ch=menu();

		switch(ch)
		{
		 case'A':
		 case'a':
			 stk_switch();
			 break;

		 case'B':
		 case'b':
			 pur_switch();
			 break;

		 case'C':
		 case'c':
			  sl_switch();
			  break;

		 case'D':
		 case'd':
			  rep_switch();
			  break;

		case'E':
		case'e':
			  adm_switch();
			  break;

		case'F':
		case'f':
			  col_switch();
			  break;

		case'G':
		case'g':
			  hlp_guide();
			  break;


	default:
	  if(ch!='q'&& ch!='Q')
		 {
		   c_box(32,21,50,22,0x24);
		   gotoxy(32,21); printf("  Wrong Input !!  ");
		   getch();
		 }


		}

	}while(ch!='q'&&ch!='Q');

 }



/******************************   MAIN MENU    ****************************/


char menu()

{
   char ch;

   clrscr();
	 //textcolor(0);

		c_box(0,0,81,26,0x67);     /*outer color box */
		border(1,1,79,25,0x60);    /*outer bordr */

		c_box(3,2,14,25,0xf6);  //keyboard.
		c_box(3,3,11,4,0x06);
		c_box(3,5,11,6,0x06);
		c_box(3,7,11,8,0x06);
		c_box(3,9,11,10,0x06);
		c_box(3,11,11,12,0x06);
		c_box(3,13,11,14,0x06);
		c_box(3,15,11,16,0x06);
		c_box(3,17,11,18,0x06);
		c_box(3,19,11,20,0x06);
		c_box(3,21,11,22,0x06);
		c_box(3,23,11,24,0x06);   //kb/

		box(22,5,70,24,0x70);     /* shade of the box */
		c_box(19,4,66,22,0x1e);    /* inner box */
		border(19,3,66,22,0x1b);    /* inner border line*/


 //	 border(20,4,65,6,0x1e);    /* inner border line*/
	 c_box(21,5,64,6,0x1a);    //for the heading.
	 gotoxy(22,5);  printf("/*******  AUDIO RECORDING CENTRE ********/");

	 c_box(25,7,28,19,0x1c);//for the numbering [a]..

	 gotoxy(25,7);  printf("[a]   STOCK ENTRY & INQUIRY .");
	 gotoxy(25,8);  printf("[b]   PURCHASE ENTRY & INQUIRY.");
	 gotoxy(25,9);  printf("[c]   SALES & RECORDING FORM.");
	 gotoxy(25,10); printf("[d]   REPORT ON SALES.");
	 gotoxy(25,11); printf("[e]   ADMINISTRATIVE INQUIRY.");
	 gotoxy(30,12); printf(" (Recording charge/Selling price..)");
	 gotoxy(25,13); printf("[f]   SONG COLLECTION.");
	 gotoxy(25,14); printf("[g]   HELP GUIDE .");
	 gotoxy(25,16); printf("[q]   QUIT .");



	 gotoxy(25,18); printf("[ ]   Enter your choice_ ");
	 gotoxy(30,19); printf("    _then press ENTER key .");
	//scanf("%c",&ch);

	gotoxy(26,18);
	 fflush(stdin);
	 ch=getchar();

	 return(ch);      /*--------- back to funct [4]------------- */


}



/*************************  FOR STOCK ENQUERY SWITCH  ****************/


void stk_switch()
{

  char ch;
  int n;
	  do
	  {
	  clrscr();
	  ch=stk_menu();

		switch(ch)
		{
		case'A':
		case'a':
			 inp_stk();
			 break;
		case'B':
		case'b':
			 outp_stk();
			 break;
		case'C':
		case'c':
			 srch_stk();
			 break;
		 case'D':
		 case'd':
			 del_stk();
			 break;
		case'e':
			 stk_filedel();
			 break;

	default:
	  if(ch!='q'&& ch!='Q')
			{
			c_box(40,22,57,23,0x4);
			gotoxy(40,22); printf("  Wrong Input !!  ");
			getch();
			}

		}

	}while(ch!='q'&&ch!='Q');     /* back to function[4] */

 }


/*******************  FOR STOCK SUB MENU  (Stock enquery form) **********/


char stk_menu()
{

	char ch;
	clrscr();
	// textcolor(10);
	 c_box(1,1,81,26,0x90);
	 c_box(25,2,72,5,0xa0);
	 box(25,6,72,25,0x0b);

	 gotoxy(27,3);  printf("/****** STOCK ENTRY & INQUIRY FORM ******/");

	 gotoxy(30,7);  printf("[a]  INPUT ENTRY FORM FOR STOCK.");
	 gotoxy(30,9);  printf("[b]  LIST OF CURRENT STOCK.");
	 gotoxy(30,11); printf("[c]  SEARCHING FOR SPECIFIC ITEM.");
	 gotoxy(30,13); printf("[d]  DELETING SPECIFIC ITEM.");
	 gotoxy(30,15); printf("[e]  DELETING STOCK RELATED FILE.");
	 gotoxy(30,17); printf("[q]  EXIT TO MAIN MENU.");
	 gotoxy(30,19); printf("[ ]   Enter your choice_");
	 gotoxy(40,20); printf("_then press the enter key.");
	//scanf("%c",&ch);

	 gotoxy(31,19);
	 fflush(stdin);
	 ch=getchar();

	 return(ch);   /* Return to function [5]  */

}


/****************************** FOR FILE DELETING ***********************/

void stk_filedel()
{

 char ch,c;
 int i,x=650;
 clrscr();
 fflush(stdin);



 printf("\n ENTER PASSWORD TO CONTINUE [3 digit]:  ");
 scanf("%d",&i);

 if (i==x)
	 {
	fflush(stdin);
	printf("\n\n Do you want to delete stock files(y/n):  ");
	scanf("%c",&ch);

	fflush(stdin);
	   if (ch=='y')
		  {
		printf("\n Are you sure, you want to Delete the file(y/n):  ");
		scanf("%c",&c);

		  if(c=='y')
			 {
			  remove("stock.dat");
			  }

		  }

	  }


}


/**************************** FUNCTION NO:[7] ******************************/
	  /*------------- INPUT ENTRY FORM FOR CASSETTE & CD -----------------*/



void inp_stk()
{
	char ch, b_type[10];
	int i,t,found,f;
	struct brand b,bt;


	FILE *fp;
	fp=fopen("stock.dat","ab+");


  do

	 {
	  clrscr();

	  border(17,1,68,3,0x0d);
	  c_box(18,2,66,3,0x0a);
	  gotoxy(19,2);	printf("*** STOCK INPUT FORM FOR CASSETTE's & CD's ***");
	  fflush(stdin);

	  c_box(25,4,38,9,0x0e);
	  gotoxy(4,4);  printf("INPUT CATAGORY NO:   [...]   ");
	  gotoxy(4,5);  printf("CATAGORY NAME    :   .........  ");
	  gotoxy(4,6);  printf("INPUT BRAND NAME :   .........  ");
	  gotoxy(4,7);  printf("INPUT BRAND TYPE :   .........  ");
	  gotoxy(4,8);  printf("INPUT REORDER LEVEL: .......");




x_line(2,9,79,9,'Ä',0x0d);
x_line(2,11,79,11,'Ä',0x0d);
x_line(2,16,79,16,'Ä',0x0d);
x_line(2,18,79,18,'Ä',0x0d);
x_line(2,23,79,23,'Ä',0x0d);

y_line(2,10,2,23,'³',0x0d);
y_line(23,10,23,23,'³',0x0d);
y_line(79,10,79,23,'³',0x0e0d);


 joint(2,9,'Ú',0x0d);      joint(79,9,'¿',0x0d);
joint(2,11,'Ã',0x0d);     joint(79,11,'´',0x0d);
joint(2,16,'Ã',0x0d);     joint(79,16,'´',0x0d);
joint(2,18,'Ã',0x0d);     joint(79,18,'´',0x0d);
joint(2,23,'À',0x0d);     joint(79,23,'Ù',0x0d);


 joint(23,9,'Â',0x0d);
joint(23,11,'Å',0x0d);
joint(23,16,'Å',0x0d);
joint(23,18,'Å',0x0d);
joint(23,23,'Á',0x0d);

	   c_box(3,10,22,11,0x0a);
	   gotoxy(3,10);printf("CASSETTE BRAND NAME");
	   gotoxy(7,12);printf("TDK.");
	   gotoxy(7,13);printf("SONY.");
	   gotoxy(7,14);printf("MAXELL.");
	   c_box(35,10,66,11,0x0a);
	   gotoxy(35,10);printf("**** CASSETTE BRAND TYPES ****");
	   gotoxy(25,12);printf("  D-90 / D-60 / B-90 / B-60 /A-90 / A-60");
	   gotoxy(25,13);printf("  HF-90 / HF-60 / EF-90 / EF-60");
	   gotoxy(25,14);printf("  UL-90 / UL-60 / XL-90 / XL-60");


	   c_box(3,17,22,18,0x0a);
	   gotoxy(3,17);printf(" CD BRAND NAME");
	   gotoxy(7,19);printf("BRANDLESS.");
	   gotoxy(7,20);printf("VERBATIM.");
	   gotoxy(7,21);printf("MAXELL.");
	   c_box(35,17,66,18,0x0a);
	   gotoxy(35,17);printf("******  CD BRAND TYPES  ******");
	   gotoxy(25,19);printf("  BL-CD /    [ Default ] ");
	   gotoxy(25,20);printf("  VR-CD /    [ Default ] ");
	   gotoxy(25,21);printf("  MX-CD /    [ Default ] ");


	   do
		 {

		  found=0;
		  gotoxy(26,4);  printf("...");
		  gotoxy(27,4);
		  scanf("%d",& b.c_no);

		  for(i=0;i<2;i++)
			 if(b.c_no==c[i].c_no)
			   {

				 fflush(stdin);
				 gotoxy(25,5);
				 puts( c[i].c_name);

				 gotoxy(25,6);
				 gets(b.b_name);
				 strupr(b.b_name);

				 do
				   {
					f=0;
					gotoxy(25,7);printf("........");
					gotoxy(25,7);

					gets(b_type);
					strupr(b_type);
					rewind(fp);

					  while(fread(&bt,sizeof(bt),1,fp)==1)
						{
						  if(strcmp(bt.b_type,b_type)==0)
							{
							 f=1;
							 break;
							 }
						}

					 if(f==0)
					 break;


					}while(1);


			   strcpy(b.b_type,b_type);
			   gotoxy(25,8);
			   scanf("%d",& b.reorder);

			   fflush(stdin);
			   b.qty=0;

			   found=1;

			   gotoxy(4,24);
			   printf("DO YOU WANT TO SAVE THE RECORD(y/n):[ ] ?   ");
			   gotoxy(41,24);
			   ch=getche();
			   getch();
				  if(ch=='y'|| ch=='Y')
					 {
					  fwrite(&b,sizeof(b),1,fp);
					   }

			   break;

			   }


		if(found)
		  {
		   break;
		   }

	   }while(1);

	  gotoxy(4,25);
	  printf("Do you want to continue(y)\\Back to menu(m):[ ] ??");
	  gotoxy(48,25);
	  ch=getche();
	  getch();

	  c_box(1,1,79,25,0x0b);


	}while(ch=='y'||ch=='Y');    /*---------------- back to func [7]  */

fclose(fp);

}



/******************* TO VIEW THE LIST OF CASSETTE / CD STOCK **********************/


void outp_stk()
{


	int x,i,c=0, y=6,found=0;
	struct brand b;
	FILE *fp;
	fp=fopen("stock.dat","rb");
	clrscr();


	border(1,1,30,4,0x0a);
	c_box(2,2,18,4,0x0e);
	c_box(19,2,29,4,0x0c);

	gotoxy(2,2); printf("þ Catagory # 1 =  CASSETTE.");
	gotoxy(2,3); printf("þ Catagory # 2 =  CD.");
	gotoxy(2,8); printf("Type '1' or '2' to view the list of stock.  ");
	printf("\n INPUT CATAGORY NO:   ");

	scanf("%d",&x);
	clrscr();


 while(fread(&b,sizeof(b),1,fp)==1)
  {

	if(x==b.c_no)
	   {
		  if(c==0)
			{
			   if(x==1)
				  {

					border(18,1,59,3,0x06);
					c_box(21,2,58,3,0x0e);

					gotoxy(22,2);   printf("******  LIST OF CASSETTE's  ******");
					c_box(2,5,78,6,0x0a);
					border(1,4,79,25,0x06);
					x_line(1,6,79,6,'Ä',0x06);
					joint(1,6,'Ã',0x06);
					joint(79,6,'´',0x06);

					gotoxy(6,5);   printf("BRAND NAME.");
					gotoxy(22,5);  printf("BRAND TYPE.");
					gotoxy(42,5);  printf("QUANTITY.");
					gotoxy(60,5);  printf("REORDER LEVEL.");
				   }


				else
				   {

					border(18,1,59,3,0x06);
					c_box(21,2,58,3,0x0e);

					gotoxy(22,2);   printf("*********  LIST OF CD's  *********");
					c_box(2,5,78,6,0x0a);
					border(1,4,79,25,0x06);
					x_line(1,6,79,6,'Ä',0x06);
					joint(1,6,'Ã',0x06);
					joint(79,6,'´',0x06);

					gotoxy(6,5);   printf("BRAND NAME.");
					gotoxy(22,5);  printf("BRAND TYPE.");
					gotoxy(42,5);  printf("QUANTITY.");
					gotoxy(60,5);  printf("REORDER LEVEL.");

					}

			  c=1;

			 }


		gotoxy(8,y+1);   printf("%s",b.b_name);
		gotoxy(24,y+1);  printf("%s",b.b_type);
		gotoxy(44,y+1);  printf("%d",b.qty);
		gotoxy(63,y+1);  printf("%d",b.reorder);

		y++;
		found=1;

	  }

  }

if(fp==NULL)
  {
	gotoxy(26,10);
	puts("File Not Found.[ Press any key to exit.]");

   }
 else if(!found)
   {
	gotoxy(26,10);
	puts(" There is no data in this file.");
	}

 fclose(fp);
 getch();


}





/*****************************FUNCTION NO:[17]  ****************************/
		 /*---------- CASSETTE/CD- STOCK SEARCHING -----------------*/


void srch_stk()
{


  int found,c,y;
  char ch;

  struct brand b;
  FILE *fp;
  fp=fopen("stock.dat","rb");

  do
   {

	 clrscr();
	 c=0;
	 y=6;
	 c_box(1,1,80,26,0x0b);
	 c_box(19,2,60,3,0x0a);  //heading.
	 border(17,1,61,3,0x06);//border.

	 gotoxy(19,2); printf("SEARCHING FOR SPECIFIC CASSETTE & CD ITEM");

	 c_box(8,5,18,6,0x0c); //b.name high lighting.
	 gotoxy(2,5); printf("ENTER BRAND NAME FOR SEARCHING:  ");
	 gotoxy(35,5); scanf(" %s",ch);
	 strupr(ch);

	 found=0;


	while(fread(&b,sizeof(b),1,fp)==1)
	  {
		 if(strcmp(ch,b.b_name)==0)
		  {
		   if(c==0)
				{
				 clrscr();
				 border(18,1,59,3,0x06);    //heading border.
				 c_box(21,2,58,3,0x0e);     //  ,,    color.

				 gotoxy(22,2);   printf("******  LIST OF THE ITEM's  ******");
				 c_box(2,5,78,6,0x0a);
				 border(1,4,79,24,0x06);  //main border.
				 x_line(1,6,79,6,'Ä',0x06);
				 joint(1,6,'Ã',0x06);
				 joint(79,6,'´',0x06);

				 gotoxy(6,5);   printf("BRAND NAME.");
				 gotoxy(22,5);  printf("BRAND TYPE.");
				 gotoxy(42,5);  printf("QUANTITY.");
				 gotoxy(60,5);  printf("REORDER LEVEL.");

				 c=1;

				}


		   gotoxy(8,y+1);   printf("%s",b.b_name);
		   gotoxy(24,y+1);  printf("%s",b.b_type);
		   gotoxy(44,y+1);  printf("%d",b.qty);
		   gotoxy(63,y+1);  printf("%d",b.reorder);

		   y++;
		   found=1;

		  }

	  }

	rewind(fp);

	if(!found)
		 printf("\n\tITEM NOT FOUND !!!");


	 gotoxy(12,25);
		   printf("Do you want to continue(y/n):[ ]");
	 gotoxy(42,25);
		  ch=getche();


   }while(ch=='y'||ch=='Y');

fclose(fp);
getch();


}




/******************************* FUNCTION [21] **************/
	 /*----------------- DELETE  CASSETTE STOCK ----------- */

void del_stk()
{
	char ch='y',c,d_type[10];
	struct brand b;
	FILE *fp,*ft ;


	while(ch=='y'||ch=='Y')
	  {

		 clrscr();
		 c_box(1,1,80,25,0x0b);
		 c_box(15,2,69,3,0x0a);
		 border(13,1,70,3,0x06);
		 gotoxy(15,2); printf("FOR DELETING ANY SPECIFIC ITEM OF CASSETTE OR CD STOCK");

		 c_box(21,6,31,7,0x0c);
		 gotoxy(2,6); printf("Enter Cassette/Cd  BRAND TYPE to delete :   ");
		 gotoxy(44,6); scanf("%s",d_type);
		 strupr(d_type);

		 printf("\n Are you sure you want to DELETE that record !!(Y/N):  ");
		 scanf(" %c",&c);

		   if(c=='y'||c=='Y')
			  {
			   fp=fopen("stock.dat","rb+");
			   ft=fopen("temp.dat","wb");
			   rewind(fp);

				 while(fread(&b,sizeof(b),1,fp)==1)
					{

					  if(strcmp(b.b_type,d_type)!=0)
						 {
						  fwrite(&b,sizeof(b),1,ft);
						  }


					   }


				fclose(fp);
				fclose(ft);
				remove("stock.dat");
				rename("temp.dat","stock.dat");


			   }

	   printf("\n Do you want to continue ???(Y/N):");
	   fflush(stdin);
	   ch=getche();
	   getch();

	 }


}                       /*----------------- back to function (19)




/************************* PURCHASE STOCK SWITCH ************************/



void pur_switch()
{

	 char ch;
	int n;
	  do
	  {
	  clrscr();
	  ch=pur_menu();

		switch(ch)
		{
		case'A':
		case'a':
			 pur_inp();
			 break;
		case'B':
		case'b':
			 pur_outp();
			 break;
		case'C':
		case'c':
			 srch_pur();
			 break;
		 case'D':
		 case'd':
			 r_order();
			 break;
		case'e':
			 pur_filedel();
			 break;

	default:
	  if(ch!='q'&& ch!='Q')
			{
			c_box(40,22,57,23,0x4);
			gotoxy(40,22); printf("  Wrong Input !!  ");
			getch();
			}

		}

	}while(ch!='q'&&ch!='Q');

 }


/**********  FOR STOCK PURCHASE SUB MENU  (purchase enquery form) **********/


char pur_menu()
{

	char ch;
	clrscr();


	 c_box(1,1,81,26,0xc0);
	 c_box(25,2,75,5,0xa0);
	 box(25,6,75,25,0x0b);


  //	 c_box(1,1,81,26,0x0);
  //	 c_box(25,2,74,5,0xa0);
 //	 box(25,6,74,25,0x0b);
	 gotoxy(28,3);  printf("*****  PURCHASE ENTRY & INQUIRY FORM  *****");
	 gotoxy(30,7);  printf("[a]  INPUT ENTRY FORM FOR PURCHASING. ");
	 gotoxy(30,9);  printf("[b]  LIST OF PURCHASED STOCK. ");
	 gotoxy(30,11); printf("[c]  PURCHASE INQUIRY(Searching MONTHwise).");
	 gotoxy(30,13); printf("[d]  SHOW ITEMS UNDER REORDER LEVEL.");
	 gotoxy(30,15); printf("[e]  DELETE PURCHASE LIST(monthwise).");
	 gotoxy(30,17); printf("[q]  EXIT TO MAIN MENU.");
	 gotoxy(30,19); printf("[ ]   Enter your choice_");
	 gotoxy(40,20); printf("_then press the enter key.");


	 gotoxy(31,19);
	 fflush(stdin);
	 ch=getchar();

	 return(ch);

}


/********************  STOCK PURCHASING ( Input ) FORM  ********************/



void pur_inp()
{
	char ch, btype[10];
	long int recsize;
	int i,t,found,f;

	struct date d;
	struct brand b;
	struct purchase pr;

	FILE *ft,*fp;
	ft=fopen("purchase.dat","ab+");
	fp=fopen("stock.dat","rb+");
	recsize=sizeof(b);

  do
	{
	  clrscr();
	  c_box(1,1,80,26,0x0b);

	  border(15,1,67,3,0x06);
	  c_box(16,2,66,3,0x0a);
	  gotoxy(17,2);	printf("*** PURCHASE ENTRY FORM FOR CASSETTE's & CD's ***");

	  fflush(stdin);

	 c_box(23,4,36,9,0x0e);
	 gotoxy(4,4);  printf("INPUT CATAGORY NO: [...]   ");
	 gotoxy(4,5);  printf("CATAGORY NAME    : ........  ");
	 gotoxy(4,6);  printf("INPUT BRAND TYPE : .........  ");
	 gotoxy(4,7);  printf("INPUT QUANTITY   : .........  ");
	 gotoxy(4,8);  printf("INPUT PRICE      : .......TK/-  (per unit) ");
	 gotoxy(45,4);  printf("CURRENT DATE :");



/*---------------------------  CHART  --------------------------------*/


x_line(2,9,80,9,'Ä',0x0d);
x_line(2,11,80,11,'Ä',0x0d);
x_line(2,16,80,16,'Ä',0x0d);
x_line(2,18,80,18,'Ä',0x0d);
x_line(2,23,80,23,'Ä',0x0d);

y_line(2,10,2,23,'³',0x0d);
y_line(23,10,23,23,'³',0x0d);
y_line(80,10,80,23,'³',0x0e0d);
//y_line(80,3,80,25,'³',0x0e0d);
//joint(24,2,'Â',0x0e0d);
 joint(2,9,'Ú',0x0d);      joint(80,9,'¿',0x0d);
joint(2,11,'Ã',0x0d);     joint(80,11,'´',0x0d);
joint(2,16,'Ã',0x0d);     joint(80,16,'´',0x0d);
joint(2,18,'Ã',0x0d);     joint(80,18,'´',0x0d);
joint(2,23,'À',0x0d);     joint(80,23,'Ù',0x0d);

 joint(23,9,'Â',0x0d);
joint(23,11,'Å',0x0d);
joint(23,16,'Å',0x0d);
joint(23,18,'Å',0x0d);
joint(23,23,'Á',0x0d);
	   c_box(3,10,22,11,0x0a);
	   gotoxy(3,10);printf("CASSETTE BRAND NAME");
	   gotoxy(7,12);printf("TDK.");
	   gotoxy(7,13);printf("SONY.");
	   gotoxy(7,14);printf("MAXELL.");

	   c_box(35,10,75,11,0x0a);
	   gotoxy(35,10);printf("**** CASSETTE BRAND TYPES ****");
	   gotoxy(25,12);printf("  D-90 / D-60 / B-90 / B-60 /A-90 / A-60");
	   gotoxy(25,13);printf("  HF-90 / HF-60 / EF-90 / EF-60");
	   gotoxy(25,14);printf("  UL-90 / UL-60 / XL-90 / XL-60");

	   c_box(3,17,22,18,0x0a);
	   gotoxy(3,17);printf(" CD BRAND NAME");
	   gotoxy(7,19);printf("BRANDLESS.");
	   gotoxy(7,20);printf("VERBATIM.");
	   gotoxy(7,21);printf("MAXELL.");

	   c_box(35,17,75,18,0x0a);
	   gotoxy(35,17);printf("******  CD BRAND TYPES  ******");
	   gotoxy(25,19);printf("  BL-CD /    [ Default ] ");
	   gotoxy(25,20);printf("  VR-CD /    [ Default ] ");
	   gotoxy(25,21);printf("  MX-CD /    [ Default ] ");

/*---------------------------------------------------------------------*/


	 do
	   {

	  found=0;
	   getdate(&d);
	   c_box(59,4,70,5,0x0e);
	   gotoxy(60,4);
	   printf("%d.%d.%d",d.da_day,d.da_mon,d.da_year);

	   pr.pd.day=d.da_day;   // System date copied to:- Struct pr (Purchase date).
	   pr.pd.month=d.da_mon;
	   pr.pd.year=d.da_year;



	  gotoxy(25,4);  printf("..");
	  gotoxy(25,4);
	  scanf("%d",& pr.c_no);

	   for(i=0;i<2;i++)
		   if(pr.c_no==c[i].c_no)
			{
			  gotoxy(25,5);
			  fflush(stdin);
			  puts( c[i].c_name);

				 do
				   {
					f=0;
					gotoxy(25,6);printf(".......");
					gotoxy(25,6);
					gets(btype);
					strupr(btype);

				  rewind(fp);
					 while(fread(&b,sizeof(b),1,fp)==1)
					   {
						 if(strcmp(b.b_type,btype)==0)
							{
							 f=1;
							  break;
							  }

						  }

					if(f==1)
					break;


				  }while(1);

		   strcpy(pr.b_type,btype);

		   gotoxy(25,7);
		   scanf("%d",& pr.qty);



			 rewind(fp);
				 while(fread(&b,recsize,1,fp)==1)
					{
					  if(strcmp(b.b_type,pr.b_type)==0)
						  {
							b.qty = b.qty+pr.qty;
							fseek(fp,-recsize,SEEK_CUR);
							fwrite(&b,recsize,1,fp);
					 //break;
							}

						}


			 fflush(stdin);

			 gotoxy(25,8);
			 scanf("%d",&pr.p_price);
			 fflush(stdin);



			 gotoxy(4,24);
			 printf("DO YOU WANT TO SAVE THE RECORD(y/n):[ ] ?   ");
			 gotoxy(41,24);
			 ch=getche();
			 getch();
			 if(ch=='y'||ch=='Y')
				{
				 fwrite(&pr,sizeof(pr),1,ft);
				 }

			 found=1;
			 break;

			} /*  if block */

		if(found)
		break;

	  }while(1);

	 gotoxy(4,25);
	 printf("Do you want to continue(y)\\Back to menu(m):[ ] ??");
	 gotoxy(48,25);
	 ch=getche();
	 getch();



   }while(ch=='y'||ch=='Y');    /*---------------- back to func [7]  */



fclose(ft);
fclose(fp);

}



/**********************  STOCK PURCHASE MONITORING  ***********************/






void pur_outp()
{


	int x,i,c=0, y=6,f=0,found=0;
	char ch;

	struct purchase pr;
	struct brand b;
	FILE *fp,*ft;
	fp=fopen("purchase.dat","rb");
	ft=fopen("stock.dat","rb");

	clrscr();

	border(1,1,30,4,0x0a);
	c_box(2,2,18,4,0x0e);
	c_box(19,2,29,4,0x0c);

	gotoxy(2,2); printf("þ Catagory # 1 =  CASSETTE.");
	gotoxy(2,3); printf("þ Catagory # 2 =  CD.");
	gotoxy(2,8); printf("Type '1' or '2' to Monitor stock purchasing.");
	printf("\n INPUT CATAGORY NO:   ");

	scanf("%d",&x);
	clrscr();

  while(fread(&pr,sizeof(pr),1,fp)==1)
	 {

		if(x==pr.c_no)
		  {
			if(c==0)
			   {
				if(x==1)
					 {
					   border(18,1,63,3,0x06);
					   c_box(21,2,61,3,0x0e);

					   c_box(2,5,78,6,0x0a);
					   border(1,4,79,23,0x06);
					   x_line(1,6,79,6,'Ä',0x06);
					   joint(1,6,'Ã',0x06);
					   joint(79,6,'´',0x06);



					  gotoxy(22,2);  printf("****  LIST OF PURCHASED CASSETTEs  ****");
					  gotoxy(4,5);   printf("BRAND NAME.");
					  gotoxy(18,5);  printf("BRAND TYPE.");
					  gotoxy(32,5);  printf("QUANTITY.");
					  gotoxy(43,5);  printf("PURCHASE PRICE.");
					  gotoxy(62,5);  printf("PURCHASE DATE.");

					  c=1;
					  }

				   else
					  {

					   border(18,1,62,3,0x06);
					   c_box(21,2,60,3,0x0e);

					   c_box(2,5,78,6,0x0a);
					   border(1,4,79,23,0x06);
					   x_line(1,6,79,6,'Ä',0x06);
					   joint(1,6,'Ã',0x06);
					   joint(79,6,'´',0x06);

						gotoxy(22,2);  printf("******  LIST OF PURCHASED CDs  ******");
						gotoxy(4,5);   printf("BRAND NAME.");
						gotoxy(18,5);  printf("BRAND TYPE.");
						gotoxy(32,5);  printf("QUANTITY.");
						gotoxy(43,5);  printf("PURCHASE PRICE.");
						gotoxy(62,5);  printf("PURCHASE DATE.");

					  c=1;
					   }



				}

			   while (fread (&b,sizeof(b),1,ft)==1)
				   {

				   if(strcmp(b.b_type,pr.b_type)==0)
					  {

						gotoxy(7,y+1);   printf("%s",b.b_name);
						gotoxy(21,y+1);  printf("%s",pr.b_type);
						gotoxy(34,y+1);  printf("%d",pr.qty);
						gotoxy(47,y+1);  printf("%d",pr.p_price);
						gotoxy(64,y+1);  printf("%d.%d.%d",pr.pd.day,pr.pd.month,pr.pd.year);

						if(y==21)
						   {
							c_box(15,25,78,26,0x0f);
							gotoxy(15,25); printf("PRESS *[TAB]* KEY TO SEE THE NEXT PAGE.");
							ch=getch();
							  if(ch=='\t')
								 {
								  y=5;
								  c_box(7,7,76,23,0x0c);
								  c_box(15,25,78,26,0x0f);
								  gotoxy(19,25); printf("è PRESS ANY KEY TO EXIT è.");
								  }
							   else
								   f=1;

							}


						  else
							{
							 c_box(15,25,78,26,0x0f);
							 gotoxy(19,25); printf("è PRESS ANY KEY TO EXIT è.");
							 }


						y++;
						found=1;
						rewind(ft);
						break;

						}

					}

		   } // main if block

	if(f==1)
	break;

	}

	   if(fp==NULL)
		  {
		 gotoxy(26,10);
		 puts("File Not Found.[ Press any key to exit.]");
		   }
		 else if(!found)
			{
			  gotoxy(26,10);
			  puts(" There is no data in this file.");
			 }



 fclose(fp);
 fclose(ft);
 getch();

}



/******************  SEARCHING PURCHASE INFO.( Monthwise)  ***************/



void srch_pur()
{

	char c,*m;
	int x, y=6,found=0,mm,yy;

	struct purchase pr;
	FILE *fp;
	fp=fopen("purchase.dat","rb");
	clrscr();

	do
	 {
	   x=0;
	   fflush(stdin);
	   clrscr();

	   border(1,2,64,4,0x09);
	   c_box(3,3,48,4,0x0e);
	   c_box(11,3,23,4,0x0c);
	   gotoxy(3,3); printf("þ ENTER MONTH & YEAR FOR SEARCHING (mm.yy) : ");
	   scanf("%d.%d",&mm,&yy);

	 if (mm<1 || mm>12)
	   {

	   //	  c_box(57,9,63,15,0xa0);
	  //	  c_box(57,16,63,18,0xa0);
		  gotoxy(18,13); printf("!!! INVALID MONTH (Are you a crackpot ?)");
		  getch();
		  x=1;
		}

	   }while(x==1);


   if (mm==1)
	 m="JANUARY";
   if (mm==2)
	 m="FEBRUARY";
   if (mm==3)
	 m="MARCH";
   if (mm==4)
	 m="APRIL";
   if (mm==5)
	 m="MAY";
   if (mm==6)
	 m="JUNE";
   if (mm==7)
	m="JULY";
   if (mm==8)
	m="AUGUST";
   if (mm==9)
	m="SEPTEMBER";
   if (mm==10)
	m="OCTOBER";
   if (mm==11)
	m="NOVEMBER";
   if (mm==12)
	m="DECEMBER";




  clrscr();

  border(18,1,64,3,0x06);
  c_box(21,2,63,3,0x0e);

  c_box(2,5,78,6,0x0a);
  border(1,4,79,25,0x06);
  x_line(1,6,79,6,'Ä',0x06);
  joint(1,6,'Ã',0x06);
  joint(79,6,'´',0x06);

  gotoxy(22,2); printf("***** ITEMS PURCHASED IN %s *****",m);
  gotoxy(5,5);   printf("BRAND TYPE.");
  gotoxy(20,5);  printf("QUANTITY.");
  gotoxy(38,5);  printf("PURCHASE PRICE.");
  gotoxy(61,5);  printf("PURCHASE DATE.");


  while(fread(&pr,sizeof(pr),1,fp)==1)
	 {
	 if ((mm==pr.pd.month)&&(yy==pr.pd.year))
		   {

			gotoxy(7,y+1);   printf("%s",pr.b_type);
			gotoxy(22,y+1);  printf("%d",pr.qty);
			gotoxy(43,y+1);  printf("%d",pr.p_price);
			gotoxy(64,y+1);  printf("%d.%d.%d",pr.pd.day,pr.pd.month,pr.pd.year);

			y++;
			}

	   found=1;

	  }

	  rewind(fp);


	  if(fp==NULL)
	{
	 gotoxy(26,10);puts("File Are Not Found");
	}

	  else if(!found)
	{
	 gotoxy(26,10);puts(" Data Are Not Store In This File");
	}


	   fclose(fp);

	   getch();


 }



/******************  SHOW ITEMS UNDER REORDER LEVEL  *********************/



void r_order()
{

	int c=0, y=6,found=0;
	struct brand b;
	FILE *fp;
	fp=fopen("stock.dat","rb");
	clrscr();

 while(fread(&b,sizeof(b),1,fp)==1)
  {
  if(b.qty<=b.reorder)
	 {
	 if(c==0)
		  {
		   border(15,1,67,3,0x06);
		   c_box(17,2,66,3,0x0e);

		   gotoxy(17,2);   printf("******  LIST OF ITEMS UNDER REORDER LEVEL  ******");
		   c_box(2,5,78,6,0x0a);  //list heading color.
		   border(1,4,79,24,0x06);  //list border.
		   x_line(1,6,79,6,'Ä',0x06);
		   joint(1,6,'Ã',0x06);
		   joint(79,6,'´',0x06);

		   gotoxy(6,5);   printf("BRAND NAME.");
		   gotoxy(22,5);  printf("BRAND TYPE.");
		   gotoxy(42,5);  printf("QUANTITY.");
		   gotoxy(60,5);  printf("REORDER LEVEL.");

		   c=1;
		  }

	  gotoxy(8,y+1);   printf("%s",b.b_name);
	  gotoxy(24,y+1);  printf("%s",b.b_type);
	  gotoxy(44,y+1);  printf("%d",b.qty);
	  gotoxy(63,y+1);  printf("%d",b.reorder);

	  y++;
	  found=1;
	 }

  }


 if(!found)
   {
	clrscr();
	gotoxy(26,10);
	puts(" é THERE ARE NO ITEMS UNDER REORDER LEVEL é");
	c_box(26,11,52,12,0x0f);
	gotoxy(26,11);
	puts(" é Press any key to exit é");
	}
 else
	{
	c_box(20,25,78,26,0x0f);
	gotoxy(20,25); printf("è  PRESS ANY KEY TO EXIT  è.");
	}

 fclose(fp);
 getch();


}




/******************  FOR DELETING PURCHASE RELATED FILES  ******************/



void pur_filedel()
{

 char ch,c,mm,*m;
 int i,q=0,x=650; //x=password.
 struct purchase pr;
 FILE *fp,*ft;

 clrscr();
 fflush(stdin);

 printf("ENTER PASSWORD TO CONTINUE [3 digit]:  ");
 scanf("%d",&i);
 if (i==x) //main IF .
  {
//------------------------------------------------------------------------



 do
  {


	 do
	  {
	   x=0;
	   fflush(stdin);
	   clrscr();

	   border(1,2,70,4,0x09);
	   c_box(3,3,68,4,0x0e);
	   c_box(40,3,51,4,0x0c);  //highlighting Enter month.
	   gotoxy(3,3); printf("þ To DELETE a month's purchase list- ENTER MONTH (in number): ");
	   scanf("%d",&mm);

	   if (mm<1 || mm>12)
		 {
		   c_box(60,9,64,15,0xab);
		   c_box(60,16,64,18,0xab);
		   gotoxy(18,13); printf("!!! INVALID MONTH (Are you a crackpot ?)");
		   getch();
		   textattr(3);
		   x=1;
		  }

	   }while(x==1);


   if (mm==1)
	 m="JANUARY";
   if (mm==2)
	 m="FEBRUARY";
   if (mm==3)
	 m="MARCH";
   if (mm==4)
	 m="APRIL";
   if (mm==5)
	 m="MAY";
   if (mm==6)
	 m="JUNE";
   if (mm==7)
	m="JULY";
   if (mm==8)
	m="AUGUST";
   if (mm==9)
	m="SEPTEMBER";
   if (mm==10)
	m="OCTOBER";
   if (mm==11)
	m="NOVEMBER";
   if (mm==12)
	m="DECEMBER";




  clrscr();

  border(3,5,61,7,0x09);
  c_box(4,6,60,7,0x0e);
  border(62,5,65,7,0x06);
  fflush(stdin);

  gotoxy(5,6);  printf("Do you want to DELETE Purchase files of %s (y/n) ",m );
  gotoxy(63,6); scanf("%c",&ch);
  fflush(stdin);

	   if (ch=='y'||ch=='Y')
		{
		   border(3,10,61,12,0x09);
		   c_box(4,11,60,12,0x02);
		   border(62,10,65,12,0x06);

		   gotoxy(5,11); printf("Are you sure, you want to Delete the file(y/n):  ");
		   gotoxy(63,11); scanf("%c",&c);

			if(c=='y'||ch=='Y')
			 {
			  fp=fopen("purchase.dat","rb+");
			  ft=fopen("temp.dat","wb");
			  rewind(fp);

			  while(fread(&pr,sizeof(pr),1,fp)==1)
					{
					if(mm!=pr.pd.month)
					   {
						fwrite(&pr,sizeof(pr),1,ft);
						q=1;
						}

					  }


			  fclose(fp);
			  fclose(ft);
			  remove("purchase.dat");
			  rename("temp.dat","purchase.dat");

			  if(q==0)
			  {
			   c_box(16,17,60,18,0xe2);
			   gotoxy(17,17); printf("NO ITEMS PURCHASED IN %s ",m );
			   textattr(3);
			   }


			 }
		 }



	   gotoxy(15,20); printf("Do you want to continue ???(Y/N):");
	   fflush(stdin);
	   ch=getche();
	   getch();

	 } while(ch=='y'||ch=='Y');

 }  //main END IF.


}

/***********************  REPORT SWITCH ********************************/



void rep_switch()
{

  char ch;
  int n;
	  do
	  {
	  clrscr();
	  ch=rep_menu();

		switch(ch)
		{
		case'A':
		case'a':
			ts_report();
			 break;
		case'B':
		case'b':
			ps_report();
			 break;
		case'C':
		case'c':
		   //	 srch_stk();
			 break;
		 case'D':
		 case'd':
		  //	 del_stk();
			 break;
		case'e':
		  //	 stk_filedel();
			 break;

	default:
	  if(ch!='q'&& ch!='Q')
			{
			c_box(40,22,57,23,0x4);
			gotoxy(40,22); printf("  Wrong Input !!  ");
			getch();
			}

		}

	}while(ch!='q'&&ch!='Q');     /* back to function[4] */

 }


/*******************  FOR REPORT MENU  (SALES enquery form) **********/


char rep_menu()
{

	char ch;
	clrscr();

	 c_box(1,1,81,26,0x90);
	 c_box(25,2,72,5,0xa0);
	 box(25,6,72,25,0x0b);

	 gotoxy(27,3);  printf("/********* SALES REPORT FORM ***********/");

	 gotoxy(30,7);  printf("[a]  REPORT ON TODAY's SALE. ");
	 gotoxy(30,9);  printf("[b]  REPORT ON SALE (By Date).");
	 gotoxy(30,11); printf("[c]  ............................");
	 gotoxy(30,13); printf("[d]  .......................");
	 gotoxy(30,15); printf("[e]  ............................");
	 gotoxy(30,17); printf("[q]  EXIT TO MAIN MENU.");
	 gotoxy(30,19); printf("[ ]  Enter your choice_");
	 gotoxy(40,20); printf("_then press the enter key.");

	 gotoxy(31,19);
	 fflush(stdin);
	 ch=getchar();

	 return(ch);   /* Return to function [5]  */

}



/*********************  SHOW TODAYS SALE  REPORT *************************/



void ts_report()
{

int i=8,q;
//  int  b_total=0;
int received=0,due=0;
FILE *fp;
struct payments pay;
struct date d;

fp=fopen("payment.dat","rb");
clrscr();


	border(3,1,36,3,0x09);
	c_box(4,2,21,3,0x0a);
	c_box(22,2,34,3,0x0c);
	gotoxy(5,2); printf("þ CURRENT DATE : ");

	getdate(&d);
	gotoxy(24,2);
	printf("%d.%d.%d",d.da_day,d.da_mon,d.da_year);



	border(3,4,54,25,0x09);

	border(5,5,16,7,0x06);
	c_box(6,6,15,7,0x0e);
	gotoxy(7,6);printf("MEMO NO.");

	border(19,5,37,7,0x06);
	c_box(20,6,36,7,0x0e);
	gotoxy(21,6);printf("TODAY RECEIVED.");

	border(40,5,53,7,0x06);
	c_box(41,6,52,7,0x0e);
	gotoxy(42,6);printf("TODAY DUE.");


	while(fread(&pay,sizeof(pay),1,fp)==1)
	  {
	  if(pay.rd.day==d.da_day&&pay.rd.month==d.da_mon&&pay.rd.year==d.da_year)
		  {
		   gotoxy(9,i);printf("%d",pay.memo_no);
		   gotoxy(25,i);printf("%d TK/-",pay.receive);
		   gotoxy(44,i);printf("%d TK/-",pay.due);
		   received+=pay.receive;
		   due+=pay.due;
		   i++;
		  }

		}
border(55,20,79,22,0x09);
c_box(56,21,73,22,0x0a);
c_box(74,21,78,22,0x0c);
gotoxy(56,21); printf("þ TOTAL RECEIVED: %d",received);


border(55,23,79,25,0x09);
c_box(56,24,73,25,0x0a);
c_box(74,24,78,25,0x0c);
gotoxy(56,24); printf("þ TOTAL DUES....: %d",due);



getch();
fclose(fp);
}




/*******************  SHOW PREVIOUS DATE'S SALES REPORT ********************/



void ps_report()
{

int i=8,q,x,dd,mm,yy;
int received=0,due=0;
FILE *fp;
struct payments pay;
struct date d;

fp=fopen("payment.dat","rb");
getdate(&d);
clrscr();

do
  {
	x=0;
	fflush(stdin);
	clrscr();

	border(1,2,64,4,0x09);
	c_box(3,3,48,4,0x0e);
	c_box(22,3,34,4,0x0c);
	gotoxy(3,3); printf("þ ENTER A DATE FOR SALES REPORT (dd.mm.yy) : ");
	scanf("%d.%d.%d",&dd,&mm,&yy);

	 if (mm<1 || mm>12 || dd<1 || dd>32)
	   {
		gotoxy(3,13); printf("!!!(Are you a crackpot ?)....PRESS ANY KEY (hmmm..world is getting full of idiots!!");
		getch();
		x=1;
		textattr(11);
		}

  }while(x==1);

	clrscr();
	border(3,1,30,3,0x09);
	c_box(4,2,20,3,0x0a);
	c_box(20,2,29,3,0x0c);
	gotoxy(4,2); printf("þREPORT OF DATE: ");

	gotoxy(20,2);
	printf("%d.%d.%d",dd,mm,yy);

	border(31,1,54,3,0x09);
	c_box(32,2,44,3,0x0a);
	c_box(44,2,54,3,0x0d);
	gotoxy(32,2); printf("þTODAY DATE:");

	getdate(&d);
	gotoxy(44,2);
	printf("%d.%d.%d",d.da_day,d.da_mon,d.da_year);



	border(3,4,54,25,0x09);

	border(5,5,16,7,0x06);
	c_box(6,6,15,7,0x0e);
	gotoxy(7,6);printf("MEMO NO.");

	border(19,5,37,7,0x06);
	c_box(20,6,36,7,0x0e);
	gotoxy(21,6);printf("TODAY RECEIVED.");

	border(40,5,53,7,0x06);
	c_box(41,6,52,7,0x0e);
	gotoxy(42,6);printf("TODAY DUE.");


	while(fread(&pay,sizeof(pay),1,fp)==1)
	  {
	  if(pay.rd.day==dd&&pay.rd.month==mm&&pay.rd.year==yy)
		  {
		   gotoxy(9,i);printf("%d",pay.memo_no);
		   gotoxy(25,i);printf("%d TK/-",pay.receive);
		   gotoxy(44,i);printf("%d TK/-",pay.due);
		   received+=pay.receive;
		   due+=pay.due;
		   i++;
		  }

		}
border(55,20,79,22,0x09);
c_box(56,21,73,22,0x0a);
c_box(74,21,78,22,0x0c);
gotoxy(56,21); printf("þ TOTAL RECEIVED: %d",received);


border(55,23,79,25,0x09);
c_box(56,24,73,25,0x0a);
c_box(74,24,78,25,0x0c);
gotoxy(56,24); printf("þ TOTAL DUES....: %d",due);



getch();
fclose(fp);
}











/***********************  FOR ADMINISTRATION SWITCH  ***********************/


void adm_switch()
{

 char ch;
 int n,i,x=650;
 clrscr();
 c_box(1,1,81,26,0x0);
 box(2,2,79,25,0x3);
 c_box(7,7,55,10,0x60);

  gotoxy(8,8); printf("ENTER PASSWORD TO CONTINUE [3 digit]:   ");
  gotoxy(45,8);  scanf("%d",&i);

  if (i==x)
   {
	fflush(stdin);


	  do
	{
	 clrscr();
	 ch=adm_menu();

	 switch(ch)
	   {

		case'A':
		case'a':
			 inp_rec();
			 break;

		case'B':
		case'b':
			 inp_slp();
			 break;

		case'C':
		case'c':
			 rec_mody();
			 break;

		case'D':
		case'd':
			slp_mody();
			 break;
		case'e':
		//     stk_filedel();
			 break;

	default:
	  if(ch!='q'&& ch!='Q')
			{
			c_box(40,23,57,24,0x4);
			gotoxy(40,23); printf("  Wrong Input !!  ");
			getch();
			}

		}

	  }while(ch!='q'&&ch!='Q');

	 }


 }




/**********************  FOR ADMINISTRATION MENU  **************************/


char adm_menu()
{

	char ch;
	clrscr();
	// textcolor(10);

	c_box(1,1,81,26,0x90);
	c_box(25,3,72,6,0xa0);
	box(25,7,72,25,0x0b);

	gotoxy(27,4);  printf("/******** ADMINISTRATIVE INQUIRY *********/");

	gotoxy(30,8);  printf("[a]  DEFINE RECORDING CHARGE");
	gotoxy(30,10); printf("[b]  DEFINE SELLING PRICE.");
	gotoxy(30,12); printf("[c]  MODIFY RECORDING CHARGE.");
	gotoxy(30,14); printf("[d]  MODIFY SELLING PRICE.");
	gotoxy(30,16); printf("[e]  ............................");
	gotoxy(30,18); printf("[q]  EXIT TO MAIN MENU.");
	gotoxy(30,20); printf("[ ]  Enter your choice_");
	gotoxy(40,21); printf("_then press the enter key.");


	 gotoxy(31,20);
	 fflush(stdin);
	 ch=getchar();

	 return(ch);

}






/*************************  DEFINE RECORDING CHARGE ********************/


void inp_rec()
{

 char ch;
 int i,x=1975;

 struct reccharge rc;
 FILE *fp;

 clrscr();
 fflush(stdin);

 printf("ENTER PASSWORD TO CONTINUE [3 digit]:  ");
 scanf("%d",&i);

 if (i==x)
   {

	 fp=fopen("recchrge.dat","ab+");

	do
	   {

		  clrscr();

		  printf("\t\t*** RECORDING CHARGE INPUT FORM FOR CASSETTE's & CD's ****");
		  fflush(stdin);

		  gotoxy(4,3);  printf("DEFINE RECORDING TYPE   :          ");
		  gotoxy(4,4);  printf("DEFINE RECORDING CHARGE :          TK/-");

		  c_box(10,6,64,9,0x60);
		  gotoxy(11,7);  printf("******  ADMINISTRATOR DEFINED RECORDING TYPE  ******");

		  border(4,9,80,22,0x7);
		  x_line(4,11,80,11,'Ä',0x7);
		  y_line(40,10,40,22,'³',0x7);

		  joint(40,9,'Â',0x7);
		  joint(40,11,'Å',0x7);
		  joint(40,22,'Á',0x7);
		  joint(4,11,'Ã',0x7);
		  joint(80,11,'´',0x7);



		  gotoxy(10,10);printf("FOR.........");
		  gotoxy(10,12);printf("MIXED-90m cassette recording.");
		  gotoxy(10,13);printf("MIXED-60m    ,,        ,,   .");
		  gotoxy(10,14);printf("ALBUM-90m    ,,        ,,   .");
		  gotoxy(10,15);printf("ALBUM-60m    ,,        ,,   .");
		  gotoxy(10,17);printf("MIXED- CD    ,,        ,,   .");
		  gotoxy(10,18);printf("ALBUM- CD    ,,        ,,   .");


		  gotoxy(44,10);printf("INPUT RECORDING TYPE........");
		  gotoxy(46,12);printf("M-90.");
		  gotoxy(46,13);printf("M-60.");
		  gotoxy(46,14);printf("A-90.");
		  gotoxy(46,15);printf("A-60.");
		  gotoxy(46,17);printf("M-CD.");
		  gotoxy(46,18);printf("A-CD.");



		  gotoxy(30,3);
		  gets(rc.rec_type);
		  strupr(rc.rec_type);

		  gotoxy(30,4);
		  scanf("%d",&rc.rec_chrg);

		  fflush(stdin);

		  gotoxy(4,24);
			  printf("DO YOU WANT TO SAVE THE RECORD(y/n):[ ] ?   ");
		  gotoxy(41,24);
			  ch=getche();

		   if(ch=='y'||ch=='Y')
			{
			  fwrite(&rc,sizeof(rc),1,fp);
			 }


		   gotoxy(4,25);
			 printf("Do you want to continue(y)\\Back to menu(m):[ ] ??");
		   gotoxy(48,25);
			 ch=getche();
			 getch();


	}while(ch=='y'||ch=='Y');

	fclose(fp);


	  }


}



/**********************  DEFINE SELLING PRICE  ***************************/


void inp_slp()
{


 char ch,targ[30];
 int i,x=1975,y=5;

 struct slprice slp;
 struct purchase pr;
 struct brand b;
 FILE *fp,*ft,*fs;

 clrscr();
 fflush(stdin);

 printf("ENTER PASSWORD TO CONTINUE [3 digit]: ");
 scanf("%d",&i);

 if (i==x)
   {

	 fp=fopen("slprice.dat","ab+");
	 ft=fopen("purchase.dat","rb");
	 fs=fopen("stock.dat","rb");

	 clrscr();
	 fflush(stdin);

	 c_box(39,1,79,25,0x30);
	 border(39,1,79,25,0x30);
	 border(40,2,78,4,0x30);
	 c_box(41,3,77,4,0x34);  //main heading.
	 c_box(41,5,77,6,0x31);  //brand type heading.
	 gotoxy(42,3);	printf("****  LIST OF PURCHASED STOCK  ****");
	 gotoxy(41,5);  printf("BRAND NAME+TYPE.");
	 gotoxy(60,5);  printf("PURCHASE PRICE.");

	while(fread(&pr,sizeof(pr),1,ft)==1)
	 {
		 rewind(fs);
		 while(fread(&b,sizeof(b),1,fs)==1)
			 {
			  if(strcmp(pr.b_type,b.b_type)==0)
				{
				 strcpy(targ,b.b_name);
				 strcat(targ," ");
				 strcat(targ,pr.b_type);
				 break;
				 }

			 }

	 gotoxy(43,y+1); printf("%s",targ);
	 gotoxy(63,y+1);  printf("%d",pr.p_price);

	 y++;

	 }

 fclose(ft);
 fclose(fs);

 c_box(1,1,36,25,0x20);
 border(1,1,36,25,0x20);
 border(2,2,35,4,0x20);
 c_box(3,3,35,4,0x24);


		 do
		  {

			   gotoxy(3,3);	printf("*** SELLING PRICE INPUT FORM ***");

			   gotoxy(2,8);  printf(" DEFINE BRAND TYPE :  ");
			   gotoxy(2,9);  printf(" òò         ");
			   gotoxy(2,11); printf(" DEFINE SELLING PRICE : ");
			   gotoxy(2,12); printf(" òò         TK/-");


			   gotoxy(6,9);
			   gets(slp.b_type);
			   strupr(slp.b_type);

			   gotoxy(6,12);
			   scanf("%d",&slp.sl_price);

			   fflush(stdin);

			   gotoxy(2,16);
			   printf(" þ SAVE THE RECORD(y/n):[ ] ?   ");
			   gotoxy(27,16);
			   ch=getche();
			   getch();


			   if(ch=='y'||ch=='Y')
					 {
					 fwrite(&slp,sizeof(slp),1,fp);
					  }


			   gotoxy(2,18);
			   printf(" þ CONTINUE(y/n):[ ] ??");
			   gotoxy(20,18);
			   ch=getche();
			   getch();

			   gotoxy(27,16);
			   printf(" ");
			   gotoxy(20,18);
			   printf(" ");



			 }while(ch=='y'||ch=='Y');

			fclose(fp);


	}


}



/*********************  MODIFY RECORDING CHARGE INFO. *********************/




void rec_mody()
{
	char ch,btype[10];
	long int recsize;
	struct reccharge rc;

	FILE *fp;
	fp=fopen("recchrge.dat","rb+");
	recsize=sizeof(rc);


 do
	{
	 clrscr();
	 fflush(stdin);
	 border(1,2,45,4,0x09);
	 c_box(3,3,35,4,0x0e);
	 gotoxy(3,3);  printf("Enter RECORDING TYPE to modify :");


	 gotoxy(36,3);
	 gets(btype);
	 strupr(btype);

	 rewind(fp);
	 while(fread(&rc,recsize,1,fp)==1)
		 {
		if(strcmp(rc.rec_type,btype)==0)
			 {
			  border(1,7,30,10,0x09);
			  c_box(3,8,18,10,0x0e);

			  gotoxy(3,8);  printf("REC_TYPE......: %s",rc.rec_type);
			  gotoxy(3,9);  printf("PREVIOUS PRICE: %d",rc.rec_chrg);

			  border(1,13,36,15,0x09);
			  c_box(3,14,30,15,0x0e);
			  gotoxy(3,14);
			  printf("Input New RECORDING CHARGE: ");

			  gotoxy(31,14);
			  scanf("%d",&rc.rec_chrg);
			  fflush(stdin);

			   gotoxy(3,23);
			   printf("þ SAVE THE RECORD(y/n):[ ] ?   ");
			   gotoxy(27,23);
			   ch=getche();
			   getch();


				 if(ch=='y'||ch=='Y')
					 {
						fseek(fp,-recsize,SEEK_CUR);
						fwrite(&rc,recsize,1,fp);
						break;

					  }
				else
					break;





			  }//(end if).


		  } //(end while).

	   gotoxy(3,24);
	   printf("þ Modify another record(Y/N):[  ] ");
	   fflush(stdin);
	   gotoxy(33,24);
	   ch=getche();
	   getch();
	   c_box(1,1,79,25,0x0b);
	 }while(ch=='y'||ch=='Y');


fclose(fp);
}











/**********************    MODIFY SELLING PRICE   ************************/




void slp_mody()
{
	char ch,btype[10];
	long int recsize;
	struct slprice slp;

	FILE *fp;
	fp=fopen("slprice.dat","rb+");
	recsize=sizeof(slp);


 do
	{
	 clrscr();
	 fflush(stdin);

	 border(1,2,45,4,0x09);
	 c_box(3,3,29,4,0x0e);
	 gotoxy(3,3);  printf("Enter BRAND TYPE to modify :");


	 gotoxy(32,3);
	 gets(btype);
	 strupr(btype);
	 fflush(stdin);
	 rewind(fp);
	 while(fread(&slp,recsize,1,fp)==1)
		 {
		if(strcmp(slp.b_type,btype)==0)
			 {
			  border(1,7,30,10,0x09);
			  c_box(3,8,18,10,0x0e);

			  gotoxy(3,8);  printf("BRAND TYPE    : %s",slp.b_type);
			  gotoxy(3,9);  printf("PREVIOUS PRICE: %d",slp.sl_price);

			  border(1,13,36,15,0x09);
			  c_box(3,14,28,15,0x0e);
			  gotoxy(3,14);
			  printf("Input New Selling Price :");

			  gotoxy(29,14);
			  scanf("%d",&slp.sl_price);
			  fflush(stdin);

			   gotoxy(3,23);
			   printf("þ SAVE THE RECORD(y/n):[ ] ?   ");
			   gotoxy(27,23);
			   ch=getche();
			   getch();


			   if(ch=='y'||ch=='Y')
					 {
						fseek(fp,-recsize,SEEK_CUR);
						fwrite(&slp,recsize,1,fp);
						break;

					  }
				else
					break;





			  }


		  }

	   gotoxy(3,24);
	   printf("þ Modify another record(Y/N): ");
	   fflush(stdin);
	   gotoxy(33,24);
	   ch=getche();
	   getch();
	   fflush(stdin);
	   c_box(1,1,79,25,0x0b);
	 }while(ch=='y'||ch=='Y');

fclose(fp);

}









/*********************** SALES & RECORDING SWITCH **************************/


void sl_switch()
{

 char ch;
 int n;

 do
   {

	 clrscr();
	 ch=sl_menu();

	 switch(ch)
		{
		case'A':
		case'a':
			 outp_rec();
			 break;

		case'B':
		case'b':
			 outp_slp();
			 break;

		case'C':
		case'c':
			 inp_ord();
			 break;

		case'D':
		case'd':
			 inp_pay();
			 break;

		case'E':
		case'e':
			 deliverN();
			 break;

	default:
	  if(ch!='q'&& ch!='Q')
			{
			c_box(40,22,57,23,0x4);
			gotoxy(40,22); printf("  Wrong Input !!  ");
			getch();
			}

		}

	}while(ch!='q'&&ch!='Q');     /* back to function[4] */

 }





/**********************   SALES & RECORDING MENU   ***********************/


char sl_menu()
{

	char ch;
	clrscr();
	// textcolor(10);
	 c_box(1,1,81,26,0x60);
	 c_box(25,2,72,5,0xb0);
	 box(25,6,72,25,0x0c);
	 gotoxy(27,3);  printf("/********* SALES & RECORDING ***********/");
	 gotoxy(30,7);  printf("[a]  SHOW RECORDING CHARGES");
	 gotoxy(30,9);  printf("[b]  SHOW SELLING PRICE(Cassette/CD).");
	 gotoxy(30,11); printf("[c]  ORDER ENTRY & BILLING.");
	 gotoxy(30,13); printf("[d]  PAYMENT INQUIRY.");
	 gotoxy(30,15); printf("[e]  SHOW ORDERS (Not delivered yet).");
	 gotoxy(30,17); printf("[q]  EXIT TO MAIN MENU.");
	 gotoxy(30,19); printf("[ ]  Enter your choice_");
	 gotoxy(40,20); printf("_then press the enter key.");
	//scanf("%c",&ch);

	 gotoxy(31,19);
	 fflush(stdin);
	 ch=getchar();

	 return(ch);   /* Return to function [5]  */

}




/************************* SHOW RECORDING CHARGES *************************/




void outp_rec()
{


	int  y=12;//found=0;
	struct reccharge rc;
	FILE *fp;
	fp=fopen("recchrge.dat","rb");
	clrscr();


	   c_box(1,1,81,26,0x60); //screen coloring.
	   border(2,2,80,25,0x60); //main border.

	   c_box(14,3,73,6,0x02);  //shading.
	   c_box(12,2,71,5,0x24);  //heading.

	   gotoxy(15,3);  printf("****  LIST OF RECORDING CHARGES ( MIXED/ALBUM ) ****");

	   c_box(7,9,78,22,0x03);
	   c_box(5,8,76,21,0x20);

	   border(7,9,73,20,0x20);

	   x_line(7,11,73,11,'Ä',0x20);
	   y_line(40,10,40,20,'³',0x20);

	   joint(40,9,'Â',0x20);
	   joint(40,11,'Å',0x20);
	   joint(40,20,'Á',0x20);
	   joint(7,11,'Ã',0x20);
	   joint(73,11,'´',0x20);

	   c_box(13,10,38,11,0x21);

	   gotoxy(13,10);printf("RECORDING TYPES....");
	   gotoxy(22,13);printf(" (MIXED-90m).");
	   gotoxy(22,14);printf(" (MIXED-60m).");
	   gotoxy(22,15);printf(" (ALBUM-90m).");
	   gotoxy(22,16);printf(" (ALBUM-60m).");
	   gotoxy(22,17);printf(" (MIXED- CD). *");
	   gotoxy(22,18);printf(" (ALBUM- CD). *");


	   c_box(44,10,72,11,0x21);
	   gotoxy(44,10);printf("RECORDING CHARGES....");
	   gotoxy(50,13);printf(" TK/-");
	   gotoxy(50,14);printf(" TK/-");
	   gotoxy(50,15);printf(" TK/-");
	   gotoxy(50,16);printf(" TK/-");
	   gotoxy(50,17);printf(" TK/- *");
	   gotoxy(50,18);printf(" TK/- *");



	while(fread(&rc,sizeof(rc),1,fp)==1)
	   {

	   gotoxy(16,y+1);   printf("%s",rc.rec_type);
	   gotoxy(47,y+1);  printf("%d",rc.rec_chrg);

	   y++;

	  }



 fclose(fp);
 c_box(25,25,75,26,0x60);
 gotoxy(26,25);printf("è PRESS ANY KEY TO EXIT è");
 getch();


}



/**********************  SHOW SELLING PRICES  ***************************/



void outp_slp()
{


	int  y=9;
	struct slprice slp;
	struct brand b;
	FILE *fp,*ft;
	fp=fopen("slprice.dat","rb");
	ft=fopen("stock.dat","rb");

	clrscr();


	   c_box(1,1,81,26,0x60);
	   border(2,2,80,25,0x60);

	   c_box(14,3,73,6,0x06);   //Blake shade of heading box.
	   c_box(12,2,71,5,0x24);   //Green color for heading box.
	   gotoxy(15,3);  printf(" ******  LIST OF SELLING PRICE (Cassette/CD)  ******  ");

	   c_box(6,8,79,24,0x02);  //Blake shade of list box.
	   c_box(4,7,76,22,0x20);  //Green color for list box.
	   c_box(5,8,75,9,0x21);   //For the the blue colored heading.


	   border(4,7,76,22,0x20);
	   x_line(4,9,76,9,'Ä',0x20);
	   y_line(26,7,26,22,'³',0x20);
	   y_line(53,7,53,22,'³',0x20);

	   joint(26,7,'Â',0x20);
	   joint(53,7,'Â',0x20);

	   joint(26,9,'Å',0x20);
	   joint(53,9,'Å',0x20);

	   joint(26,22,'Á',0x20);
	   joint(53,22,'Á',0x20);

	   joint(4,9,'Ã',0x20);
	   joint(76,9,'´',0x20);

	   gotoxy(8,8);printf("BRAND NAME....");
	   gotoxy(31,8);printf("BRAND TYPE.....");
	   gotoxy(56,8);printf("SELLING PRICE.....");




	 while(fread(&slp,sizeof(slp),1,fp)==1)
	   {
		rewind(ft);
		  while (fread (&b,sizeof(b),1,ft)==1)
			   {

			   if(strcmp(b.b_type,slp.b_type)==0)
					 {

						gotoxy(10,y+1);  printf("%s",b.b_name);
						gotoxy(33,y+1);  printf("%s",slp.b_type);
						gotoxy(59,y+1);  printf("%d        TK/-",slp.sl_price);


						y++;
						break;

					  }

				}


	   }




 fclose(fp);
 fclose(ft);

 c_box(25,25,75,26,0x60);
 gotoxy(26,25);printf("è PRESS ANY KEY TO EXIT è");
 getch();

}




/**********************  ORDER ENTRY & BILLING  **************************/
/*~~~~~~~~~~~~~~~~~~~~~  ORDER ENTRY & BILLING  ~~~~~~~~~~~~~~~~~~~~~~~~~*/



void inp_ord()
{


 char ch,btype[10],targ[30];
 int i,f,y,w=0,s,temp,che,memo_no,dv=0;
 long int total, g_total;
 long int recsize;


 FILE *fp,*ft,*fg,*fr,*fb,*fc,*fm;
 struct date d;    //system date.
 struct cassale csl;
 struct brand b;
 struct slprice slp;
 static struct delivery dl;
 struct reccharge rc;
 struct payments pay;



 recsize=sizeof(b);

 fp=fopen("sales.dat","ab+");
 ft=fopen("stock.dat","rb+");
 fg=fopen("slprice.dat","rb");
 fr=fopen("recchrge.dat","rb");
 fb=fopen("payment.dat","ab");
 fc=fopen("delivery.dat","ab+");



//-----------------------------------------------------------------------//



do
{

 g_total=0;
 y=14;
 clrscr();
 c_box(1,1,80,25,0x0c);

 border(1,1,30,3,0x02);
 c_box(2,2,29,3,0x06);
 gotoxy(2,2);   printf(" IDENTITY INPUT FORM. ");

 gotoxy(2,4);   printf(" MEMO NO.      :");
 gotoxy(2,5);   printf(" ORDER DATE    :");
 gotoxy(2,6);   printf(" CUSTOMER NAME :");


 border(1,7,30,9,0x02);
 c_box(2,8,29,9,0x06);
 gotoxy(2,8);   printf(" ORDER INPUT FORM. ");


 border(1,12,79,23,0x02);
 c_box(2,13,78,14,0x06);
 x_line(1,14,79,14,'Ä',0x02);
 y_line(21,12,21,23,'³',0x02);
 y_line(36,12,36,23,'³',0x02);
 y_line(55,12,55,23,'³',0x02);
 joint(21,12,'Â',0x02);
 joint(36,12,'Â',0x02);
 joint(55,12,'Â',0x02);
 joint(21,14,'Å',0x02);
 joint(36,14,'Å',0x02);
 joint(55,14,'Å',0x02);
 joint(21,23,'Á',0x02);
 joint(36,23,'Á',0x02);
 joint(55,23,'Á',0x02);
 joint(1,14,'Ã',0x02);
 joint(79,14,'´',0x02);


 gotoxy(3,13);  printf("DESCRIPTION....");
 gotoxy(23,13); printf("QUANTITY.");
 gotoxy(40,13); printf("UNIT PRICE.");
 gotoxy(57,13); printf("TOTAL PRICE.");



 border(40,1,71,3,0x02);
 c_box(41,2,70,3,0x06);
 gotoxy(42,2);  printf(" PAYMENT INPUT FORM.");

 gotoxy(42,4);  printf(" AMOUNT RECIEVED :  ");
 gotoxy(42,5);  printf(" AMOUNT DUE : ");
 gotoxy(42,6);  printf(" MIXED REC. DELIVERY DATE : ");
 gotoxy(42,7);  printf(" ALBUM REC. DELIVERY DATE : ");
//------------------------------------------------------------------------


	   c_box(19,4,35,7,0x0b);   //to erase the -USER'S INPUT


	   fm=fopen("memo_no.dat","rb");  //Opening a file to auto generate the memo no.

	   if(fm==NULL)
		{
		fm=fopen("memo_no.dat","wb");
		memo_no=1;
		fprintf(fm,"%d",memo_no); // Writing the initial memo no. in the file.
		}
		else
		fscanf(fm,"%d",&memo_no); //Reading from the file.

		fclose(fm);

	   gotoxy(19,4); printf("%d",memo_no);
	   fflush(stdin);
	   csl.memo_no=memo_no;
	   dl.memo_no=memo_no;



	   getdate(&d);
	   gotoxy(19,5);
	   printf("%d. %d. %d",d.da_day,d.da_mon,d.da_year);

	   dl.od.day=d.da_day;   // System date copied to:- Struct dl (Order date).
	   dl.od.month=d.da_mon;
	   dl.od.year=d.da_year;

	   pay.rd.day=d.da_day;   // System date copied to:- Struct pay (Receive date).
	   pay.rd.month=d.da_mon;
	   pay.rd.year=d.da_year;


	   fflush(stdin);
	 //  c_box(19,6,35,7,0x0b);   //to erase the -USER'S INPUT
	   gotoxy(19,6);
	   gets(dl.cus_name);
	   strupr(dl.cus_name);

	   c_box(35,9,78,10,0x0d);
	   gotoxy(35,9);  printf("* WANT TO BUY CASSETTEs/CDs ??(y/n): [ ] *");
	   gotoxy(73,9);
	   ch=getche();
	   getch();


  if(ch=='y'||ch=='Y')
	{

	 c_box(35,9,78,10,0x0c);

	 gotoxy(2,10);  printf(" INPUT BRAND TYPE : ");
	 gotoxy(2,11);  printf(" INPUT QUANTITY   : ");




		  do //(do#2)
		   {



			 do //(do#3)
			   {
					f=0;
					s=0;

					c_box(41,10,70,12,0x0f);    //to erase the dialog- SAVE THE RECORD
					c_box(21,10,40,12,0x0b);   //to erase the -USER'S INPUT

					gotoxy(22,10);
					gets(btype);
					strupr(btype);


					rewind(ft);
					while(fread(&b,recsize,1,ft)==1)
					   {
						 if(strcmp(b.b_type,btype)==0) //&&b.qty>0 &&
							{
							 gotoxy(22,11);
							 scanf("%d", &csl.qty);
							 fflush(stdin);
							  if(b.qty>=csl.qty)
								  {
									f=1;
									break;
								   }
								else
								   {
								   c_box(21,10,40,11,0xf1);
								   gotoxy(23,10); printf("é WRONG INPUT é ");
								   c_box(21,11,40,12,0xf0);
								   gotoxy(22,11); printf("CURRENT STOCK: %d",b.qty);
								   textattr(0x03);
								   s=1;
								   break;

								   }

							 }

						}

					if(f==1)
					   break;

					if(s==1)
					   break;


				if(s==0)
				  {
				   if(f==0)
					  {
					   c_box(21,10,40,12,0x0e);
					   gotoxy(22,10);printf("NOT IN STOCK!!");
					   gotoxy(22,11);  printf("ÄÄÄÄÄ * ÄÄÄÄÄ ");
					   break;
					  }
					 break;
				   }

				}while(1); //(do#3)


			  if(f==1)  //IF(1)
				{
				   strcpy(csl.type,btype);

				   gotoxy(42,10);
				   printf("þ SAVE THE RECORD(y/n):[ ] ?");
				   gotoxy(66,10);
				   ch=getche();

				   if(ch=='y'||ch=='Y')  //IF(2)
						 {
						  fwrite(&csl,sizeof(csl),1,fp);

						  rewind(ft);
						  while(fread(&b,recsize,1,ft)==1)
							   {
								if(strcmp(csl.type,b.b_type)==0)
									 {
									  strcpy(targ,b.b_name);
									  strcat(targ," ");
									  strcat(targ,csl.type);

									  b.qty =b.qty-csl.qty;
									  fseek(ft,-recsize,SEEK_CUR);
									  fwrite(&b,recsize,1,ft);

									  c_box(35,9,79,10,0x0d);
									  if(b.qty<=b.reorder)
										 {
										   c_box(34,9,58,10,0xf5);
										   gotoxy(35,9);printf("é BELOW REORDER LEVEL é");
										   c_box(60,9,79,10,0xf1);
										   gotoxy(61,9);printf("!! NOW STOCK: %d",b.qty);
										   textattr(0x03);
										 }
									  break;

									 }



							   }

						   gotoxy(6,y+1); printf("%s",targ);
						   gotoxy(26,y+1); printf("%d",csl.qty);

						   rewind(fg);
						   while (fread (&slp,sizeof(slp),1,fg)==1)
								{
								 if(strcmp(csl.type,slp.b_type)==0)
									  {
									   csl.price= slp.sl_price;
									   gotoxy(41,y+1);  printf("%d  TK/-",csl.price);

									   total=(csl.price*csl.qty);
									   gotoxy(59,y+1);  printf("%d   TK/-",total);
									   g_total+=total;
									   break;
									  }

								}


						 y++;
						 }  //IF(2)


				 } //IF(1)



			gotoxy(42,11);
			printf("þ CONTINUE(y/n):[ ] ??");
			gotoxy(59,11);
			ch=getche();
			getch();

		   }while(ch=='y'||ch=='Y');   //end of (do#2)
		   c_box(35,9,79,10,0x0d);  // to erase the dialog- WANT TO BUY...

	} //end if.
//----------------------------------------------------------------------//


	   //	 c_box(35,9,78,10,0x0c);    // to erase the dialog- WANT TO BUY...
		 c_box(21,10,40,12,0x0b);  //to erase the dialog i.e, NOT IN STOCK
		 c_box(41,10,70,12,0x0e);  //to erase the dialog- SAVE THE RECORD

		 c_box(34,9,78,10,0x0e);
		 gotoxy(35,9);  printf("* LIKE TO ORDER FOR RECORDING ?(y/n):[ ] *");
		 gotoxy(73,9);
		 ch=getche();
		 getch();

	  //	 c_box(42,10,70,12,0x0e);

		 if(ch=='y'||ch=='Y')
			{

				do
				 {

					gotoxy(2,10);  printf(" RECORDING.. TYPE : ");
					gotoxy(2,11);  printf(" INPUT QUANTITY   : ");

					c_box(34,9,78,10,0x0d); //to erase the dialog- LIKE TO.....RECORDING?
					c_box(41,10,70,12,0x0e);    //to erase the dialog- SAVE THE RECORD

					c_box(22,10,37,12,0x0b);   //to erase the -USER'S INPUT_for recording


				 do
				   {
					f=0;
					c_box(21,10,41,11,0x0b);
					gotoxy(22,10);
					gets(btype);
					strupr(btype);

					 rewind(fr);
					 while(fread(&rc,sizeof(rc),1,fr)==1)
					   {
						 if(strcmp(rc.rec_type,btype)==0)
							{
							 f=1;
							  break;
							 }

						 }

					 if(f==1)
						break;
					 else
					  {
						c_box(21,10,40,11,0xf1);
						gotoxy(23,10); printf("é WRONG INPUT é ");
						textattr(0x03);
						getch();
					   }

					}while(1);

		   strcpy(csl.type,btype);

					gotoxy(22,11);
					scanf("%d", &csl.qty);
					fflush(stdin);

					gotoxy(42,10);
					printf("þ SAVE THE RECORD(y/n):[ ] ?");
					gotoxy(66,10);
					ch=getche();


					if(ch=='y'||ch=='Y')
						 {
						  w=1;
						  fwrite(&csl,sizeof(csl),1,fp);

						  rewind(fr);
						  while (fread (&rc,sizeof(rc),1,fr)==1)
								{
								 if(strcmp(csl.type,rc.rec_type)==0)
									  {
									   csl.price=rc.rec_chrg;

									   gotoxy(6,y+1);  printf("%s",csl.type);
									   gotoxy(26,y+1); printf("%d",csl.qty);
									   gotoxy(41,y+1);  printf("%d  TK/-",csl.price);

									   total=(csl.price*csl.qty);
									   gotoxy(59,y+1);  printf("%d   TK/-",total);
									   g_total+=total;
									   break;
									  }

								}


						 y++;

						 }

					gotoxy(42,11);
					printf("þ CONTINUE(y/n):[ ] ??");
					gotoxy(59,11);
					ch=getche();
					getch();


				 }while(ch=='y'||ch=='Y');





			} //END IF    */

 //---------------------------------------------------------------------//




	  border(55,23,79,25,0x02);
	  joint(79,23,'´',0x02);
	  joint(55,23,'Å',0x02);
	  c_box(56,24,69,25,0x06);
	  gotoxy(56,24);printf("GRAND TOTAL :");
	  c_box(70,24,78,25,0x0e);
	  gotoxy(70,24);printf("%d",g_total);


 if(g_total>0)
  {
  c_box(41,10,70,12,0x0e);    //to erase the dialog- SAVE THE RECORD
  pay.memo_no=memo_no;

	do
	 {
	  c_box(60,4,70,5,0x0b);   //to erase the -USER'S INPUT_for payment
	  c_box(55,5,70,6,0x0b);   //to erase the -USER'S INPUT_for payment
	  c_box(70,6,80,7,0x0b);   //to erase the -USER'S INPUT_for payment
	  c_box(70,7,80,8,0x0b);   //to erase the -USER'S INPUT_for payment

   if(w==1)
	 {
	   do
		{
		 gotoxy(61,4); printf("        ");
		 gotoxy(61,4);
		 scanf("%d", &temp);
		 fflush(stdin);

		 }while (temp>g_total);

	   }

	  if(w==0)
	  {
	   do
		{
		 gotoxy(61,4); printf("        ");
		 gotoxy(61,4);
		 scanf("%d", &temp);
		 fflush(stdin);

		 }while (temp!=g_total);

	   }


		pay.receive=temp;

		pay.due= g_total- pay.receive;
		gotoxy(61,5);
		printf("%d",pay.due);

		c_box(34,9,79,10,0x94);
		gotoxy(35,9); printf("**** PRESS [TAB] KEY TO INPUT DATE ****");
		textattr(0x03);

		gotoxy(70,6);ch=getch();
		if(ch=='\t')
		{
		 dv=1;
		 c_box(70,6,80,7,0x20);
		 gotoxy(70,6);
		 scanf("%d.%d.%d",&dl.md.day,&dl.md.month,&dl.md.year);
		 textattr(0x03);
		 fflush(stdin);
		 }

		gotoxy(70,7);ch=getch();
		if(ch=='\t')
		{
		 dv=1;
		 c_box(70,7,80,8,0x30);
		 gotoxy(70,7);
		 scanf("%d.%d.%d",&dl.ad.day,&dl.ad.month,&dl.ad.year);
		 textattr(0x03);
		 fflush(stdin);
		 }


		gotoxy(42,10);
		printf("þ SAVE THE RECORD(y/n):[ ] ?");
		gotoxy(66,10);
		ch=getche();
		getch();

	 }while(ch=='n'||ch=='N');
	 c_box(34,9,79,10,0x0d); //to erase the dialog- PRESS TAB KEY.........

 memo_no+=1;    //Increasing the memo number by +1.
 fm=fopen("memo_no.dat","w"); //By opening the file in 'w' mode ,previous memo no is deleted.
 fprintf(fm,"%d",memo_no);
 fclose(fm);

 dl.deliver='Y';
 if(dv==1)
 dl.deliver='N';

 fwrite(&pay,sizeof(pay),1,fb);
 fwrite(&dl,sizeof(dl),1,fc);


 }

 fflush(stdin);
 gotoxy(12,24); printf("Continue (y/n):[ ]");
 gotoxy(28,24);
 ch=getche();
 getch();


  }while(ch=='y'||ch=='Y'); //(do#1)



fclose(fp);
fclose(ft);
fclose(fg);
fclose(fr);
fclose(fb);
fclose(fc);
}




/***************************  DUES PAYMENT  **************************/




void inp_pay()
{


  int found,x,c;
  long int recsize;
  char ch;

  struct date d;    //system date.
  struct payments pay;
  struct delivery dl;
  FILE *fp,*ft;
  fp=fopen("payment.dat","rb+");
  ft=fopen("delivery.dat","rb+");

  recsize=sizeof(dl);
  do
   {

	 clrscr();
	 c=0;

	 c_box(1,1,80,26,0x0e);
	 c_box(19,2,60,3,0x0a);  //heading.
	 border(17,1,61,3,0x06);//border.

	 gotoxy(23,2); printf("***** PAYMENT INPUT FORM *****");

	 c_box(8,5,16,6,0x0c); //b.name high lighting.
	 gotoxy(2,5); printf("ENTER MEMO NO.FOR SEARCHING:  ");
	 gotoxy(35,5); scanf(" %d",&x);
	 fflush(stdin);

	 found=0;


	while(fread(&pay,sizeof(pay),1,fp)==1)
	  {
		 if(x==pay.memo_no)
		  {
			clrscr();
			border(18,1,59,3,0x06);    //heading border.
			c_box(21,2,58,3,0x0e);     //  ,,    color.

			gotoxy(22,2);   printf("******  PAYMENT INPUT FORM  ******");
			c_box(2,5,78,6,0x0a);
			border(1,4,79,24,0x06);  //main border.

			c_box(22,6,35,13,0x0a); //amount color.

			if(c==0)
				  {
					 gotoxy(8,6);  printf("CURRENT DATE :");
					 getdate(&d);
					 gotoxy(23,6);
					 printf("%d. %d. %d",d.da_day,d.da_mon,d.da_year);

					 c=1;
					}

		   while (fread (&dl,sizeof(dl),1,ft)==1)
			  {
			 if(pay.memo_no==dl.memo_no)
				{
				 if(dl.deliver=='N')
				  {
				   gotoxy(8,8);   printf("MEMO NO......:");
				   gotoxy(8,9);   printf("CUSTOMER NAME:");
				   gotoxy(8,10);  printf("ORDER DATE...:");
				   gotoxy(8,11);  printf("RECEIVED.....:");
				   gotoxy(8,12);  printf("DUES.........:");

				   gotoxy(23,8);  printf("%d",dl.memo_no);
				   gotoxy(23,9);  printf("%s",dl.cus_name);
				   gotoxy(23,10); printf("%d. %d. %d",pay.rd.day,pay.rd.month,pay.rd.year);
				   gotoxy(23,11); printf("%d",pay.receive);
				   gotoxy(23,12); printf("%d",pay.due);


					 c_box(7,15,47,16,0x0a); //amount color.
					 gotoxy(8,15);  printf("þ DO YOU WANT TO DELIVER IT. (y/n):[ ]");
					 gotoxy(44,15);
					 ch=getche();
					 getch();
					 fflush(stdin);
					 if(ch=='y'||ch=='Y')
						   {
							c_box(22,17,35,19,0x0a); //amount color.
							pay.receive=pay.due;
							gotoxy(8,17);  printf("þ NOW RECEIVED :");
							gotoxy(25,17);  printf("%d",pay.receive);

							pay.due=0;
							gotoxy(8,18);  printf("þ NOW DUE..... :");
							gotoxy(25,18);  printf("%d",pay.due);

							pay.rd.day=d.da_day;   // System date copied to:- Struct pay (Receive date).
							pay.rd.month=d.da_mon;
							pay.rd.year=d.da_year;

							dl.deliver='Y';
							fseek(ft,-recsize,SEEK_CUR);
							fwrite(&dl,recsize,1,ft);
							 }

						}
					 else
						{
						gotoxy(23,14);printf("Order had been deliveried");
						}

				 rewind(ft);
				 found=1;
				 break;

				 }

			  }


		   break;

		  }

	  }

	rewind(fp);
	rewind(ft);


	if(!found)
	 { gotoxy(32,23);
	   printf("ITEM NOT FOUND !!!");
	  }



	 c_box(12,25,45,26,0x0f);
	 gotoxy(12,25);
		   printf("Do you want to continue(y/n):[ ]");
	 gotoxy(42,25);
		  ch=getche();
		  getch();

   }while(ch=='y'||ch=='Y');

fclose(fp);
fclose(ft);

}


/*****************  TO VIEW THE ORDERS NOT DELIVERED YET ******************/


void deliverN()
{


	int  y=7;
	struct delivery dl;
	struct payments pay;

	FILE *fp,*ft;
	fp=fopen("delivery.dat","rb");
	ft=fopen("payment.dat","rb");

	clrscr();
	border(13,1,63,3,0x06); //heading border.
	c_box(14,2,62,3,0x0e); //heading color.

	gotoxy(16,2);   printf("******  LIST OF ORDERS NOT DELIVERED  ******");

	c_box(2,5,78,6,0x0a); //List heading color.
	border(1,4,79,24,0x06);  //2nd border_(list)
	x_line(1,6,79,6,'Ä',0x06);
	joint(1,6,'Ã',0x06);
	joint(79,6,'´',0x06);

	c_box(3,7,79,23,0x0c);
	gotoxy(3,5);   printf("MEMOno.");
	gotoxy(11,5);  printf("NAME.");
	gotoxy(21,5);  printf("ORDER DATE."); //Order date==Received date.
	gotoxy(35,5);  printf("RECEIVED.");
 //	c_box(45,5,50,6,0x0c);
	gotoxy(45,5);  printf("DUES.");
	gotoxy(54,5);  printf("MIX_D_DATE /");
	gotoxy(67,5);  printf("ALB_D_DATE.");



   while(fread(&dl,sizeof(dl),1,fp)==1)
	   {
	   if(dl.deliver=='N')
		  {

			rewind(ft);
			while (fread (&pay,sizeof(pay),1,ft)==1)
			   {
			   if(strcmp(pay.memo_no,dl.memo_no)==0)
					 {

						gotoxy(5,y+1);  printf("%d",pay.memo_no);
						gotoxy(11,y+1); printf("%s",dl.cus_name);
						gotoxy(21,y+1); printf("%d. %d. %d",pay.rd.day,pay.rd.month,pay.rd.year);
						gotoxy(35,y+1); printf("%d TK/-",pay.receive);
						gotoxy(45,y+1); printf("%d TK/-",pay.due);
						gotoxy(54,y+1); printf("%d.%d.%d",dl.md.day,dl.md.month,dl.md.year);
						gotoxy(67,y+1); printf(" %d.%d.%d",dl.ad.day,dl.ad.month,dl.ad.year);

						y++;
						break;

					  }

				 }

		   }


	  }



 fclose(fp);
 fclose(ft);

 c_box(25,25,75,26,0x0f);
 gotoxy(26,25);printf("è PRESS ANY KEY TO EXIT è");
 getch();


}




/***********************  SONG COLLECTION SWITCH ***********************/



void col_switch()
{

  char ch;
  int n;
	  do
	  {
	  clrscr();
	  ch=col_menu();

		switch(ch)
		{
		case'A':
		case'a':
			 inp_song();
			 break;

		case'B':
		case'b':
			 outp_col();
			 break;
		case'C':
		case'c':
			 del_col();
			 break;
		 case'D':
		 case'd':
			 //del_stk();
			 break;
		case'e':
			 //stk_filedel();
			 break;

	default:
	  if(ch!='q'&& ch!='Q')
			{
			c_box(40,22,57,23,0x4);
			gotoxy(40,22); printf("  Wrong Input !!  ");
			getch();
			}

		}

	}while(ch!='q'&&ch!='Q');

 }


/***********************  FOR SONG COLLECTION MENU **********************/


char col_menu()
{

	char ch;
	clrscr();

	 c_box(1,1,81,26,0xe0);
	 c_box(25,2,72,5,0xa0);
	 box(25,6,72,25,0x0c);

	 gotoxy(27,3);  printf("/******* SONG COLLECTION MENU *******/");

	 gotoxy(30,7);  printf("[a]  INPUT FORM FOR COLLECTION.");
	 gotoxy(30,9);  printf("[b]  SHOW SONG COLLECTION.");
	 gotoxy(30,11); printf("[c]  DELETE SPECIFIC SONG.");
	 gotoxy(30,13); printf("[d]  ..............");
	 gotoxy(30,15); printf("[e]  ...............");
	 gotoxy(30,17); printf("[q]  EXIT TO MAIN MENU.");
	 gotoxy(30,19); printf("[ ]  Enter your choice_");
	 gotoxy(40,20); printf("_then press the enter key.");

	 gotoxy(31,19);
	 fflush(stdin);
	 ch=getchar();

	 return(ch);

}




/**********************  SONG COLLECTION INPUT FORM  **********************/



void inp_song()
{
	char ch;
	int i,t,found,f;
	static struct collection col;


	FILE *fp;
	fp=fopen("songlist.dat","ab+");


  do

	 {
	  clrscr();

	  border(17,1,68,3,0x09);
	  c_box(18,2,66,3,0x0e);
	  gotoxy(19,2);	printf(" *** INPUT FORM FOR BANGLA & ENGLISH SONGS ***");
	  fflush(stdin);

	  c_box(3,4,23,9,0x0a);
	  gotoxy(4,4);  printf("INPUT CATAGORY NO: [   ]   ");
	  gotoxy(4,5);  printf("CATAGORY NAME    :             ");
	  gotoxy(4,6);  printf("INPUT ARTISTE NAME:                         ");
	  gotoxy(4,7);  printf("INPUT ALBUM NAME :                            ");
	  gotoxy(4,8);  printf("INPUT DURATION   :           (min:sec) ");



border(4,10,30,12,0x0d);
border(4,13,30,15,0x0d);
c_box(19,11,27,12,0x0e);
c_box(19,14,27,15,0x0e);
gotoxy(6,11);  printf("CATAGORY #1:  BANGLA ");
gotoxy(6,14);  printf("CATAGORY #2:  ENGLISH ");

	   do
		 {

		  found=0;
		  gotoxy(25,4);  printf("  ");
		  gotoxy(25,4);
		  scanf("%d",& col.t_no);

		  for(i=0;i<2;i++)
			 if(col.t_no==st[i].t_no)
			   {

				 fflush(stdin);
				 gotoxy(24,5);
				 puts( st[i].t_name);

				 gotoxy(24,6);
				 gets(col.artiste);
				 strupr(col.artiste);

				 gotoxy(24,7);
				 gets(col.album);
				 strupr(col.album);

				 gotoxy(24,8);
				 scanf("%d:%d",&col.t.min,&col.t.sec);
				 fflush(stdin);

				 found=1;

				gotoxy(4,24);
				printf("DO YOU WANT TO SAVE THE RECORD(y/n):[ ] ?   ");
				gotoxy(41,24);
				ch=getche();
				getch();
				  if(ch=='y'|| ch=='Y')
					 {
					  fwrite(&col,sizeof(col),1,fp);
					   }

			   break;

			   }


		if(found)
		  {
		   break;
		   }

	   }while(1);

	  gotoxy(4,25);
	  printf("Do you want to continue(y)\\Back to menu(m):[ ] ??");
	  gotoxy(48,25);
	  ch=getche();
	  getch();

	  c_box(1,1,79,25,0x0b);


	}while(ch=='y'||ch=='Y');

fclose(fp);

}



/******************* TO VIEW THE SONG COLLECTION  **********************/


void outp_col()
{


	int x,f=0,c=0, y=6,found=0,i=0,n=0,item;
	char ch;
	struct collection col[200],temp;

	FILE *fp;
	fp=fopen("songlist.dat","rb");
	clrscr();


	border(1,1,30,4,0x0a);
	c_box(2,2,18,4,0x0e);
	c_box(19,2,29,4,0x0c);

	gotoxy(2,2); printf("þ Catagory # 1 =  BANGLA.");
	gotoxy(2,3); printf("þ Catagory # 2 =  ENGLISH.");
	gotoxy(2,8); printf("Type '1' or '2' to view the list of Collection.");
	printf("\n INPUT CATAGORY NO:   ");
	scanf("%d",&x);
	clrscr();

//Sort program for sorting the song list.

 while(fread(&col[i],sizeof(col[i]),1,fp)==1)
  { i++ ;n++;
  }
 for(item=0;item<n-1;++item)
		 for(i=item+1;i<n;++i)
			if(strcmp(col[item].artiste,col[i].artiste)>0)
			{
			temp= col[item];
			col[item]=col[i];
			col[i]=temp;

			}
 /*-------------------------------------------------------------*/

 for(i=0;i<n;i++)
 {
	if(x==col[i].t_no) //(main IF block).
	   {
		if(c==0)     //to print the heading only once.
			{
			 if(x==1)
				  {

					border(18,1,59,3,0x06);
					c_box(20,2,58,3,0x0e);

					gotoxy(20,2);   printf("****  LIST OF BANGLA collection  ****");
					c_box(2,5,79,6,0x0a);
					border(1,4,79,24,0x06);
					x_line(1,6,79,6,'Ä',0x06);
					joint(1,6,'Ã',0x06);
					joint(79,6,'´',0x06);

					gotoxy(3,5);   printf("NO.");
					gotoxy(8,5);   printf("ARTISTE NAME ...");
					gotoxy(29,5);  printf("ALBUM NAME .......");
					gotoxy(55,5);  printf("ALBUM DURATION (min:sec)");

				   }

			   else
				   {

					border(18,1,59,3,0x06);
					c_box(20,2,58,3,0x0e);

					gotoxy(20,2);   printf("****  LIST OF ENGLISH collection  ****");
					c_box(2,5,79,6,0x0a);
					border(1,4,79,24,0x06);
					x_line(1,6,79,6,'Ä',0x06);
					joint(1,6,'Ã',0x06);
					joint(79,6,'´',0x06);

					gotoxy(3,5);   printf("NO.");
					gotoxy(8,5);   printf("ARTISTE NAME ....");
					gotoxy(29,5);  printf("ALBUM NAME ......");
					gotoxy(55,5);  printf("ALBUM DURATION (min:sec)");

					}

			  c=1;

			}

		 gotoxy(8,y+1);   printf("%s",col[i].artiste);
		 gotoxy(30,y+1);  printf("%s",col[i].album);
		 gotoxy(65,y+1);  printf("%d:%d",col[i].t.min,col[i].t.sec);

// a program to view the list page by page.

		if(y==22)
		   {
			 c_box(15,25,78,26,0x0f);
			 gotoxy(18,25); printf("PRESS *[TAB]* KEY TO SEE THE NEXT PAGE.");
			 ch=getch();
			   if(ch=='\t')
				 {
				  y=5;
				  c_box(5,7,76,24,0x0c);
				  c_box(15,25,78,26,0x0f);
				  gotoxy(19,25); printf("è PRESS ANY KEY TO EXIT è.");
				  }
				 else
				   f=1;

			   }

		  else
			  {
			   c_box(15,25,70,26,0x0f);
			   gotoxy(19,25); printf("è PRESS ANY KEY TO EXIT è.");
			   }




	   if(f==1)
		 break;

	   y++;
	   found=1;

	   } // (main IF block).

  } //(end WHILE).

if(fp==NULL)
  {
	gotoxy(26,10);
	puts("File Not Found.[ Press any key to exit.]");
   }
else if(!found)
   {
	gotoxy(26,10);
	puts(" There is no data in this file.");
	}

fclose(fp);
getch();
}



/************************  SONG COLLECTION DELETE  *************************/



void del_col()
{
	char ch='y',c,d_type[10];
	struct collection col;
	FILE *fp,*ft ;


	while(ch=='y'||ch=='Y')
	  {

		 clrscr();
		 c_box(1,1,80,25,0x0e);

		 c_box(15,2,69,3,0x0a);
		 border(13,1,70,3,0x06);
		 gotoxy(15,2); printf("* FOR DELETING ANY SPECIFIC SONG FROM THE COLLECTION *");

		 c_box(21,6,31,7,0x0c);
		 gotoxy(2,6); printf("Enter Specific.... ALBUM NAME to delete :   ");
		 gotoxy(44,6); scanf("%s",d_type);
		 strupr(d_type);


		 c_box(2,9,55,10,0x0d);
		 gotoxy(2,9); printf("Are you sure you want to DELETE that record !!(Y/N):  ");
		 gotoxy(56,9);
	   //	 scanf("%c",&c);
		 fflush(stdin);
		 c=getche();
		 getch();


		   if(c=='y'||c=='Y')
			  {
			   fp=fopen("songlist.dat","rb+");
			   ft=fopen("temp.dat","wb");
			   rewind(fp);

				 while(fread(&col,sizeof(col),1,fp)==1)
					{
					if(strcmp(col.album,d_type)!=0)
						 {
						  fwrite(&col,sizeof(col),1,ft);
						  }


					   }


				fclose(fp);
				fclose(ft);
				remove("songlist.dat");
				rename("temp.dat","songlist.dat");


			   }
	   c_box(2,12,35,13,0x0a);
	   gotoxy(2,12); printf("Do you want to continue ???(Y/N):");
	   fflush(stdin);
	   ch=getche();
	   getch();

	 }


}                       /*-----------`------ back to function (19)


/************************  USER HELP GUIDE  *********************************/

void hlp_guide()
{

	int y=1;
	char ch;
	FILE *fp;
	clrscr();

	fp=fopen("help.txt","r");
	c_box(0,0,81,26,0x4f);
	gotoxy(1,1);
	if(fp==NULL)
		 {
		  border(23,11,56,13,0x4f);
		  gotoxy(25,12);printf("*** CAN NOT OPEN THE FILE ***");
		  }

	while((ch=fgetc(fp))!=EOF)
		{

		 if(y==715)
		   {
			border(47,23,78,25,0x4e);
			c_box(48,24,77,25,0x4e);
			gotoxy(48,24);  printf(" Press any key to continoue...");
			getch();
			clrscr();
			c_box(0,0,81,26,0x4f);
			gotoxy(1,1);

		  //	gotoxy(48,25);  printf("                                  ");
			y=1;
			}

		  printf("%c",ch);
		  y++;
		}

fclose(fp);
getch();

}



/*------------------- (END OF THE WHOLE PROGRAM)--------------------------*/






