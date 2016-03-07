/****************************************************************************
** This is a unit to demonstrate how to access the mouse using Turbo       **
** C. I've decided to call the mouse using assembler statements.           **
** Using the standard C method would require a lot of extra work and       **
** doesn't improve readability.                                            **
****************************************************************************/

 //Global variables, storing the coordinates and the button press information
  unsigned int MouseX, MouseY, MouseB;

char IfMouse ();
void ShowMouse ();
void HideMouse ();
void ReadMouse ();
void SetMouseXY (unsigned int X, unsigned int Y);
void SetMinMaxX (unsigned int Min, unsigned int Max);
void SetMinMaxY (unsigned int Min, unsigned int Max);

//This procedure checks where a mouse is available
char IfMouse ()
{
  unsigned int Result;
  asm mov ax, 0
  asm int 0x33
  asm mov Result, ax
  return Result;
}

//This procedure makes the mouse cursor visible
void ShowMouse ()
{
	asm mov ax, 0x1
	asm int 0x33
}

//This procedure makes the mouse cursor invisible
void HideMouse ()
{
	asm mov ax, 0x2
  asm int 0x33
}

//This procedure reads the location of the mouse cursor and the button press
//information
void ReadMouse ()
{
  asm mov ax, 0x3
  asm int 0x33
  asm mov MouseB, bx
	asm mov MouseX, cx
  asm mov MouseY, dx
}

//This procedure sets the mouse cursor to another location
void SetMouseXY (unsigned int X, unsigned int Y)
{
  asm mov ax, 0x4
  asm mov cx, X
  asm mov dx, Y
  asm int 0x33
}

//This procedure sets the minimum and maximum values that the mouse cursor
//may reach in horizontal range
void SetMinMaxX (unsigned int Min, unsigned int Max)
{
	asm mov ax, 0x7
	asm mov cx, Min
	asm mov dx, Max
	asm int 0x33
}

//This procedure sets the minimum and maximum values that the mouse cursor
//may reach in vertical range
void SetMinMaxY (unsigned int Min, unsigned int Max)
{
	asm mov ax, 0x8
	asm mov cx, Min
	asm mov dx, Max
	asm int 0x33
}