#include <graphics.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <alloc.h>
#include<process.h>
#include<fcntl.h>
#include<sys\stat.h>
#include<stdio.h>
#include <stdio.h>

void clos_scr(void);


main()
{
	int driver, mode,errorcode;
	void *buf;
	unsigned size;
	int i,w,j,hi_menu=0;
	driver=DETECT;
	initgraph(&driver, &mode, "c:\\tc\\bgi");
		/* read result of initialization */
	errorcode = graphresult();
		/* an error occurred */
	if (errorcode != grOk)
	{
	 printf("Graphics error: %s\n", grapherrormsg(errorcode));
	 printf("Press any key to halt.......");
	 getch();
	 /* terminate with an error code */
	 exit(1);
	}
	clos_scr();

}

void clos_scr(void)
{
	setbkcolor(0);
	setcolor(9);
	settextstyle(7,0,2);
	delay(200);
	outtextxy(150,50,"THANK   YOU   FOR   USING . . . . . ");
	delay(100);

	setcolor(RED);
	settextstyle(0,0,4);
	outtextxy(90,150,"THIS");
	delay(300);
	outtextxy(140,210,"CUSTOMISED");
	delay(300);
	outtextxy(315,275,"SOFTWARE");
	delay(500);

	setcolor(5);
	settextstyle(6,0,3);   //FORMAT: (fonts, vertcal/horizontal, font size);
	delay(200);
	outtextxy(13,379,"DESIGNED & DEVELOPED BY :");
	outtextxy(13,390,"컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴");

	setcolor(2);
	settextstyle(10,0,2);
	delay(200);
	outtextxy(50,420,"AHSAN UL HADI ADIL");

	setcolor(6);
	settextstyle(7,0,2);
	outtextxy(427,436,"<NCC-18th batch>");


	delay(11000);

	cleardevice();
	closegraph();
	clrscr();
}

