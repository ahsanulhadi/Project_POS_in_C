#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "mouse.c"

int main(void)
{
   int x,y;
   int    MaxX, MaxY;		/* The maximum resolution of the screen */
   int    MaxColors;		/* The maximum # of colors available	*/
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

   /* initialize graphics mode */
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

   /* read result of initialization */
   errorcode = graphresult();

   if (errorcode != grOk)  /* an error occurred */
   {
	 printf("Graphics error: %s\n", grapherrormsg(errorcode));
	 printf("Press any key to halt:");
	 getch();
	 exit(1);             /* return with error code */
   }
   MaxColors = getmaxcolor() + 1;	/* Read maximum number of colors*/
   MaxX = getmaxx();
   MaxY = getmaxy();			     /* Read size of screen*/
   SetMouseXY(200,430);
   ShowMouse();


	 setcolor(WHITE);
	 /* Main Box */
	 rectangle(370,180,500,300);
	 line(370,220,500,220);
	 line(370,260,500,260);

	 setcolor(LIGHTGRAY);
	 rectangle(380,270,420,290);
	 circle(390,280,3);
	 circle(410,280,3);
	 rectangle(430,280,490,290);
	 line(440,280,440,290);
	 line(450,280,450,290);
	 line(460,280,460,290);
	 line(470,280,470,290);
	 line(480,280,480,290);

	 line(380,230,380,250);
	 line(390,230,390,250);
	 line(400,230,400,250);
	 line(410,230,410,250);
	 line(420,230,420,250);
	 line(430,230,430,250);
	 line(440,230,440,250);

	 line(378,234,382,234);
	 line(388,238,392,238);
	 line(398,241,402,241);
	 line(408,246,412,246);
	 line(418,243,422,243);
	 line(428,239,432,239);
	 line(438,234,442,234);

	 circle(457,232,4);
	 circle(457,248,4);

	 circle(480,240,9);
	 line(480,240,485,245);

	 rectangle(380,190,450,200);
	 line(380,205,450,205);
	 //rectangle(380,190,450,210);



	 /* Sound Box */
	 setcolor(WHITE);

	 rectangle(270,100,360,300);
//	 setfillstyle(1, LIGHTGRAY);
//	 floodfill(317,142, LIGHTGRAY);

	 rectangle(510,100,600,300);
//	 setfillstyle(1, LIGHTGRAY);
//	 floodfill(517,142, LIGHTGRAY);


	 setcolor(LIGHTGRAY);
	 circle(315,140,10);
	 setfillstyle(8, LIGHTGRAY);
	 floodfill(315,140, LIGHTGRAY);

	 circle(315,190,15);
	 setfillstyle(8, LIGHTGRAY);
	 floodfill(315,190, LIGHTGRAY);

	 circle(315,255,25);
	 setfillstyle(8, LIGHTGRAY);
	 floodfill(315,255, LIGHTGRAY);

	 circle(555,140,10);
	 setfillstyle(8, LIGHTGRAY);
	 floodfill(555,140, LIGHTGRAY);

	 circle(555,190,15);
	 setfillstyle(8, LIGHTGRAY);
	 floodfill(555,190, LIGHTGRAY);

	 circle(555,255,25);
	 setfillstyle(8, LIGHTGRAY);
	 floodfill(555,255, LIGHTGRAY);

	 /*????*/
	 setcolor(WHITE);
	 line(40,330, 600, 330);
	 line(40,390, 600, 390);

	 setcolor(RED);
	 settextstyle(4,0,4);
	 outtextxy(70,340,"AUDIO");
	 outtextxy(220,340,"RECORDING");
	 outtextxy(440,340,"CENTRE");


	 settextstyle(1,0,1);

	 setfillstyle(1,8);
	 bar(450,425,595,450);
	 bar(346,425,425,450);

	 setfillstyle(1,9);
	 bar(340,420,420,445);
	 bar(440,420,590,445);


	 setcolor(7);
	 rectangle(340,420,420,445);
	 rectangle(440,420,590,445);

	 setcolor(15);
	 outtextxy(350,420,"ABOUT");
	 outtextxy(448,420,"MAIN PROGRAM");

	 while(!kbhit())
	 {
		 ShowMouse();
		 ReadMouse();
		 if((MouseX >= 440 && MouseY >= 420 && MouseX <= 590 && MouseY <= 445) & MouseB==1)
		 {
		   cleardevice();
		   SetMouseXY(200,430);
		   closegraph();
		   exit(0);
		 }
	   if((MouseX >= 340 && MouseY >= 420 && MouseX <= 420 && MouseY <= 445) & MouseB==1)
		 {
		   setfillstyle(1,8);
		   bar(17,72,190,103);

		   setfillstyle(1,9);
		   bar(12,68,184,97);
		   rectangle(12,68,184,97);

		   setcolor(15);
		   settextstyle(1,0,2);
		   outtextxy(25,70,"PROGRAMMER");

		   settextstyle(1,0,1);
		   setcolor(5);
		   delay(300);
		   outtextxy(14,130,"AHSAN UL HADI ADIL.");

		   setcolor(6);
		   settextstyle(7,0,2);
		   delay(300);
		   outtextxy(14,155,"<NCC-18th batch>");
		/*   delay(300);
		   outtextxy(14,180,"RISVI (Add...)");*/

	 /*	   settextstyle(1,0,1);
		   //setcolor(5);
		   delay(300);
		   setcolor(9);
		   outtextxy(10,230,"COURSE INSTRUCTOR :");  */

		   setfillstyle(1,8);
		   bar(9,230,225,260);

		   setfillstyle(1,9);
		   bar(5,226,220,255);
		   rectangle(5,226,220,255);

		   setcolor(15);
		   settextstyle(1,0,2);
		   outtextxy(10,230,"COURSE INSTRUCTOR");

		   delay(300);
		   setcolor(5);
		   outtextxy(30,265,"IMRANUL QUADER IMU.");


	  }
		 putpixel(random(MaxX), random(300), random( MaxColors-1 )+1);
		 x = MaxX / 2;
		 y = MaxY / 2;
		 delay(56);
	 }
	 getch();
	/* clean screen */
	 cleardevice();
	 closegraph();
	// clrscr();
	 return 0;
}

