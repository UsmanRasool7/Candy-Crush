#include <windows.h>



void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void myLine(int x1, int y1, int x2, int y2, int  a, int x, int y, int z) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, a, RGB(x, y, z)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}


// This function checks if any of the 4 cursor keys are pressed. 
// If any cursor key is pressed, then the function returns true, and whichKey identifies which of the 4 cursor keys is pressed.
// whichkey is assigned following values if any cursor key is pressed. 1 for left, 2 for up, 3 for right and 4 for left.
bool isCursorKeyPressed(int& whichKey)   //whichKey passed as reference.... 
{
	char key;
	key = GetAsyncKeyState(VK_LEFT);
	if (key == 1)
	{
		whichKey = 1;		// 1 if left key is pressed 
		return true;
	}
	key = GetAsyncKeyState(VK_UP);
	if (key == 1)
	{

		whichKey = 2;		// 2 if up key is pressed
		return true;
	}

	key = GetAsyncKeyState(VK_RIGHT);
	if (key == 1)
	{

		whichKey = 3; // 3 if right key is pressed
		return true;
	}
	key = GetAsyncKeyState(VK_DOWN);
	if (key == 1)
	{

		whichKey = 4;   // 4 if down key is pressed
		return true;
	}
	key = GetAsyncKeyState(VK_RETURN);
	if (key == 1)
	{

		whichKey = 5;   // 5 if enter key is pressed
		return true;
	}
	return false;
}


bool isCursorKeyPressed2(int& whichKey)   //whichKey passed as reference.... 
{
	char key;
	key = GetAsyncKeyState(VK_LEFT);
	if (key == 1)
	{
		whichKey = 1;		// 1 if left key is pressed 
		return true;
	}
	key = GetAsyncKeyState(VK_UP);
	if (key == 1)
	{

		whichKey = 2;		// 2 if up key is pressed
		return true;
	}

	key = GetAsyncKeyState(VK_RIGHT);
	if (key == 1)
	{

		whichKey = 3; // 3 if right key is pressed
		return true;
	}
	key = GetAsyncKeyState(VK_DOWN);
	if (key == 1)
	{

		whichKey = 4;   // 4 if down key is pressed
		return true;
	}
	key = GetAsyncKeyState(VK_RETURN);
	if (key == 1)
	{

		whichKey = 5;   // 5 if enter key is pressed
		return true;
	}
	return false;
}

void myRectangle(int x1, int y1, int x2, int y2, int R, int G, int B, int x, int y, int z, int a)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(x, y, z, a)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}

void myRectangle2(int x1, int y1, int x2, int y2, int R, int G, int B, int x, int y, int z, int a)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 4, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = (HBRUSH)::GetStockObject(NULL_BRUSH); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}

void myRectangle3(int x1, int y1, int x2, int y2, int R, int G, int B, int x, int y, int z, int a)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 3, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = (HBRUSH)::GetStockObject(NULL_BRUSH); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}

void myEllipse(int x1, int y1, int x2, int y2, int R, int G, int B, int x, int y, int z)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 3, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(x, y, z));  //Fill color is black
	SelectObject(device_context, brush);
	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);


}

void triangle(int x, int y, int R, int G, int B)
{
	myLine(x, y + 35, x + 40, y + 35, 3, R, G, B);
	myLine(x, y + 35, x + 20, y, 3, R, G, B);
	myLine(x + 40, y + 35, x + 20, y, 3, R, G, B);
}

void mystar(int x, int y, int R, int G, int B)
{
	myLine(x, y + 30, x + 40, y + 30, 3, R, G, B);
	myLine(x, y + 30, x + 20, y, 3, R, G, B);
	myLine(x + 40, y + 30, x + 20, y, 3, R, G, B);

	myLine(x, y + 10, x + 40, y + 10, 3, R, G, B);
	myLine(x, y + 10, x + 20, y + 40, 3, R, G, B);
	myLine(x + 40, y + 10, x + 20, y + 40, 3, R, G, B);
}

void myEllipse3(int x1, int y1, int x2, int y2, int R, int G, int B, int x, int y, int z)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 5, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = (HBRUSH)::GetStockObject(NULL_BRUSH);  //Fill color is black
	SelectObject(device_context, brush);
	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);


}


//**********************************************************my own funtion ******************************************************************
//232, 225, 23, 10, 10, 31
