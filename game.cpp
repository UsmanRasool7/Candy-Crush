#include <iostream>
#include "help.h"
#include <time.h>
#include <ctime>
using namespace std;

//A Funtion to fill the board by value starts

void BoardFiller(int arr[][8])
{
	int num;
	srand(time(0));
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			num = rand() % 5 + 1;
			arr[i][j] = num;
		}
	}
}

//A Funtion to fill the board by value ends

// funtion to fill the board by icons begin along with its rectangles of grid and main boarder 

void BoardConstructor(int arr[][8])
{

	int x = 0, y = 0;
	int xx = 410, yy = 230, aa1 = 0, an = 1;
	for (int i = 0; i < 75; i++)
	{
		if (i % 2 == 0)
			myRectangle(0, aa1, 1350, aa1 + 10, 12, 12, 66, 12, 12, 66, 255);
		else
			myRectangle(0, aa1, 1350, aa1 + 10, 70, 70, 184, 70, 70, 184, 255);
		aa1 = aa1 + 10;
	}

	myRectangle(340, 160, 940, 760, 232, 225, 23, 232, 225, 23, 255);
	myRectangle(340, 160, 400, 760, 232, 225, 23, 232, 225, 23, 255);
	myRectangle(880, 160, 940, 760, 232, 225, 23, 232, 225, 23, 255);
	myRectangle(340, 160, 940, 220, 232, 225, 23, 232, 225, 23, 255);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			myRectangle(400 + x, 220 + y, 460 + x, 280 + y, 232, 225, 23, 10, 10, 31, 255);
			x = x + 60;
		}
		y = y + 60;
		x = 0;
	}// grid again construction
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == 1)
			{
				myRectangle3(xx, yy, xx + 38, yy + 38, 44, 245, 198, 34, 37, 73, 255);
				myRectangle3(xx + 28, yy + 28, xx + 10, yy + 10, 44, 245, 198, 45, 40, 79, 255);
				xx = xx + 60;
			}
			if (arr[i][j] == 2)
			{
				myEllipse(xx, yy, xx + 35, yy + 35, 255, 0, 0, 10, 10, 31);
				xx = xx + 60;
			}
			if (arr[i][j] == 3)
			{
				myEllipse(xx, yy, xx + 38, yy + 38, 226, 88, 34, 10, 10, 31);
				myEllipse(xx + 7, yy + 7, xx + 30, yy + 30, 226, 88, 34, 10, 10, 31);
				myEllipse(xx + 15, yy + 15, xx + 23, yy + 23, 226, 88, 34, 10, 10, 31);
				xx = xx + 60;
			}
			if (arr[i][j] == 4)
			{
				triangle(xx, yy, 207, 202, 202);
				xx = xx + 60;
			}
			if (arr[i][j] == 5)
			{
				mystar(xx, yy, 252, 138, 43);
				xx = xx + 60;
			}


		}
		yy = yy + 60;
		xx = 410;
	}
	xx = 410, yy = 230;
}

// funtion to fill the board by icons begin along with its rectangles of grid and main boarder ends

// funtion to fill a single icons in the table at a particular point starts

void singleicon(int num, int arr[][8], int i, int j)
{
	int  xx1 = 400 + i * 60, yy1 = 220 + j * 60;

	myRectangle(340, 160, 400, 760, 232, 225, 23, 232, 225, 23, 255);
	myRectangle(880, 160, 940, 760, 232, 225, 23, 232, 225, 23, 255);
	myRectangle(340, 160, 940, 220, 232, 225, 23, 232, 225, 23, 255);
	// loop to remove the swaped icons 
	if (num == 8)
	{
		num = rand() % 5 + 1;//random number generator on empty space
		arr[j][i] = num;
	}
	for (int i = 0; i < 6; i++)
	{
		if (i == 0)
			myRectangle(xx1, yy1, xx1 + 60, yy1 + 60, 232, 225, 23, 10, 10, 31, 255);
		/*Sleep(5);*/
	}
	int xx = 410 + i * 60, yy = 230 + j * 60;

	if (num == 1)
	{
		myRectangle3(xx, yy, xx + 38, yy + 38, 44, 245, 198, 34, 37, 73, 255);
		myRectangle3(xx + 28, yy + 28, xx + 10, yy + 10, 44, 245, 198, 45, 40, 79, 255);
		//xx = xx + 60;
	}
	if (num == 2)
	{
		myEllipse(xx, yy, xx + 35, yy + 35, 252, 15, 3, 10, 10, 31);
	}
	if (num == 3)
	{
		myEllipse(xx, yy, xx + 38, yy + 38, 226, 88, 34, 10, 10, 31);
		myEllipse(xx + 7, yy + 7, xx + 30, yy + 30, 226, 88, 34, 10, 10, 31);
		myEllipse(xx + 15, yy + 15, xx + 23, yy + 23, 226, 88, 34, 10, 10, 31);
	}
	if (num == 4)
	{
		triangle(xx, yy, 207, 202, 202);
	}
	if (num == 5)
	{
		mystar(xx, yy, 252, 138, 43);
	}
	if (num == 10)
	{
		myRectangle3(xx, yy, xx + 38, yy + 38, 255, 0, 255, 34, 37, 73, 255);
		myRectangle3(xx + 28, yy + 28, xx + 10, yy + 10, 255, 0, 255, 45, 40, 79, 255);
	}
	if (num == 11)
	{
		myEllipse(xx, yy, xx + 35, yy + 35, 255, 0, 255, 10, 10, 31);
	}
	if (num == 12)
	{
		myEllipse(xx, yy, xx + 38, yy + 38, 255, 0, 255, 10, 10, 31);
		myEllipse(xx + 7, yy + 7, xx + 30, yy + 30, 255, 0, 255, 10, 10, 31);
		myEllipse(xx + 15, yy + 15, xx + 23, yy + 23, 255, 0, 255, 10, 10, 31);

	}
	if (num == 13)
	{
		triangle(xx, yy, 255, 0, 255);
	}
	if (num == 14)
	{
		mystar(xx, yy, 255, 0, 255);
	}
	if (num == 15)
	{
		myRectangle3(xx, yy, xx + 38, yy + 38, 255, 255, 255, 34, 37, 73, 255);
		myRectangle3(xx + 28, yy + 28, xx + 10, yy + 10, 255, 255, 255, 45, 40, 79, 255);
	}
	if (num == 16)
	{
		myEllipse(xx, yy, xx + 35, yy + 35, 255, 255, 255, 10, 10, 31);
	}
	if (num == 17)
	{
		myEllipse(xx, yy, xx + 38, yy + 38, 255, 255, 255, 10, 10, 31);
		myEllipse(xx + 7, yy + 7, xx + 30, yy + 30, 255, 255, 255, 10, 10, 31);
		myEllipse(xx + 15, yy + 15, xx + 23, yy + 23, 255, 255, 255, 10, 10, 31);
	}
	if (num == 18)
	{
		triangle(xx, yy, 255, 255, 255);
	}
	if (num == 19)
	{
		mystar(xx, yy, 255, 255, 255);
	}
}

// funtion to fill a single icons in the table at a particular point ends

// Funtion to swap right 
void rightswap(int arr[][8], int p, int q)
{
	int xx2 = 400 + q * 60, yy2 = 220 + p * 60;
	swap(arr[p][q], arr[p][q + 1]);
	singleicon(arr[p][q], arr, q, p);
	singleicon(arr[p][q + 1], arr, q + 1, p);
	myRectangle2(xx2, yy2, xx2 + 60, yy2 + 60, 0, 0, 0, 0, 0, 0, 255);
}

// Funtion to swap left
void leftswap(int arr[][8], int p, int q)
{
	int xx2 = 400 + q * 60, yy2 = 220 + p * 60;
	swap(arr[p][q], arr[p][q - 1]);
	singleicon(arr[p][q], arr, q, p);
	singleicon(arr[p][q - 1], arr, q - 1, p);
	myRectangle2(xx2, yy2, xx2 + 60, yy2 + 60, 0, 0, 0, 0, 0, 0, 255);
}

// Funtion to swap up
void upswap(int arr[][8], int p, int q)
{
	int xx2 = 400 + q * 60, yy2 = 220 + p * 60;
	swap(arr[p][q], arr[p - 1][q]);
	singleicon(arr[p][q], arr, q, p);
	singleicon(arr[p - 1][q], arr, q, p - 1);
	myRectangle2(xx2, yy2, xx2 + 60, yy2 + 60, 0, 0, 0, 0, 0, 0, 255);
}

// Funtion to swap down
void downswap(int arr[][8], int p, int q)
{
	int xx2 = 400 + q * 60, yy2 = 220 + p * 60;
	swap(arr[p][q], arr[p + 1][q]);
	singleicon(arr[p][q], arr, q, p);
	singleicon(arr[p + 1][q], arr, q, p + 1);
	myRectangle2(xx2, yy2, xx2 + 60, yy2 + 60, 0, 0, 0, 0, 0, 0, 255);
}

// function to blsat 3 consecutive jewels in row
void Blast_3_row(int arr[][8], int& score)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])
			{
				score = score + 10;
				/*arr[i][j] = 8;
				arr[i][j + 1] = 8;
				arr[i][j + 2] = 8;*/
				for (int k = 0; k < 3; k++)
				{
					j = j + k;
					if (k == 2)
						j--;
					int xx3 = 400 + j * 60, yy3 = 220 + i * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
					arr[i][j] = 8;
				}
			}
		}
	}
}


// function to blast 4 jewewls in a row
void Blast_4_row(int arr[][8], int& score)
{
	int a = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3])
			{
				score = score + 20;
				for (int k = 0; k < 3; k++)
				{
					j = j + k;
					if (k == 3)
						j--;
					int xx3 = 400 + j * 60, yy3 = 220 + i * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
					arr[i][j] = 8;
					if (a == 0)
					{
						if (arr[i][j + 2] == 1)
						{
							arr[i][j] = 10;
							singleicon(arr[i][j], arr, j, i);
						}
						else if (arr[i][j + 2] == 2)
						{
							arr[i][j] = 11;
							singleicon(arr[i][j], arr, j, i);
						}
						else if (arr[i][j + 2] == 3)
						{
							arr[i][j] = 12;
							singleicon(arr[i][j], arr, j, i);
						}
						else if (arr[i][j + 2] == 4)
						{
							arr[i][j] = 13;
							singleicon(arr[i][j], arr, j, i);
						}
						else if (arr[i][j + 2] == 5)
						{
							arr[i][j] = 14;
							singleicon(arr[i][j], arr, j, i);
						}
						/*singleicon(arr[i][j], arr, j, i);*/
					}
					a++;
				}
			}
		}
	}
}

// function to destroy 3 consecutive jewels in column
void Blast_3_column(int arr[][8], int& score)
{
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j])
			{
				score = score + 10;
				for (int k = 0; k < 3; k++)
				{
					i = i + k;
					if (k == 2)
						i--;
					int xx3 = 400 + j * 60, yy3 = 220 + i * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
					arr[i][j] = 8;
				}
			}
		}
	}
}

// function to blast 4 jewels consecutive in a column
void Blast_4_column(int arr[][8], int& score)
{
	int a = 0;
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 3][j])
			{
				score = score + 20;
				for (int k = 0; k < 3; k++)
				{
					i = i + k;
					if (k == 3)
						i--;
					int xx3 = 400 + j * 60, yy3 = 220 + i * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
					arr[i][j] = 8;
					if (a == 0)
					{
						if (arr[i + 2][j] == 1)
						{
							arr[i][j] = 10;
							singleicon(arr[i][j], arr, j, i);
						}
						else if (arr[i + 2][j] == 2)
						{
							arr[i][j] = 11;
							singleicon(arr[i][j], arr, j, i);
						}
						else if (arr[i + 2][j] == 3)
						{
							arr[i][j] = 12;
							singleicon(arr[i][j], arr, j, i);
						}
						else if (arr[i + 2][j] == 4)
						{
							arr[i][j] = 13;
							singleicon(arr[i][j], arr, j, i);
						}
						else if (arr[i + 2][j] == 5)
						{
							arr[i][j] = 14;
							singleicon(arr[i][j], arr, j, i);
						}
						/*singleicon(arr[i][j], arr, j, i);*/
					}
					a++;
				}
			}
		}
	}
}

//function to make destroyer gem
void Blast_elbow(int arr[][8], int& score)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i + 1][j + 2] && arr[i][j] == arr[i + 2][j + 2])
			{
				score = score + 50;
				/*arr[i][j] = 8;
				arr[i][j + 1] = 8;
				arr[i][j + 2] = 8;*/
				int l = j;
				int m = i;
				int num2 = arr[m][l + 2];
				int num = arr[i][j];
				for (int k = 0; k < 3; k++)
				{
					j = j + k;
					if (k == 2)
						j--;
					int xx3 = 400 + j * 60, yy3 = 220 + i * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
					arr[i][j] = 8;
				}
				for (int k = 0; k < 3; k++)
				{
					i = i + k;
					if (k == 2)
						i--;
					int xx3 = 400 + j * 60, yy3 = 220 + i * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
					arr[i][j] = 8;
				}
				if (num2 == 1)
				{
					arr[m][l + 2] = 15;
					singleicon(arr[m][l + 2], arr, l + 2, m);
				}
				else if (num2 == 2)
				{
					arr[m][l + 2] = 16;
					singleicon(arr[m][l + 2], arr, l + 2, m);
				}
				else if (num2 == 3)
				{
					arr[m][l + 2] = 17;
					singleicon(arr[m][l + 2], arr, l + 2, m);
				}
				else if (num2 == 4)
				{
					arr[m][l + 2] = 18;
					singleicon(arr[m][l + 2], arr, l + 2, m);
				}
				else if (num2 == 5)
				{
					arr[m][l + 2] = 19;
					singleicon(arr[m][l + 2], arr, l + 2, m);
				}
			}
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 2][j + 1] && arr[i][j] == arr[i + 2][j + 2])
			{
				score = score + 50;
				int l = j;
				int m = i;
				int num2 = arr[m + 2][l];
				int num = arr[i][j];
				for (int k = 0; k < 3; k++)
				{
					i = i + k;
					if (k == 2)
						i--;
					int xx3 = 400 + j * 60, yy3 = 220 + i * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 2232, 225, 23, 10, 10, 31, 255);
					arr[i][j] = 8;
				}

				for (int k = 0; k < 3; k++)
				{
					j = j + k;
					if (k == 2)
						j--;
					int xx3 = 400 + j * 60, yy3 = 220 + i * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
					arr[i][j] = 8;
				}
				if (num2 == 1)
				{
					arr[m + 2][l] = 15;
					singleicon(arr[m + 2][l], arr, l, m + 2);
				}
				else if (num2 == 2)
				{
					arr[m + 2][l] = 16;
					singleicon(arr[m + 2][l], arr, l, m + 2);
				}
				else if (num2 == 3)
				{
					arr[m + 2][l] = 17;
					singleicon(arr[m + 2][l], arr, l, m + 2);
				}
				else if (num2 == 4)
				{
					arr[m + 2][l] = 18;
					singleicon(arr[m + 2][l], arr, l, m + 2);
				}
				else if (num2 == 5)
				{
					arr[m + 2][l] = 19;
					singleicon(arr[m + 2][l], arr, l, m + 2);
				}
			}
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 2][j - 1] && arr[i][j] == arr[i + 2][j - 2])
			{
				score = score + 50;
				int l = j;
				int m = i;
				int num2 = arr[m + 2][l];
				int num = arr[i][j];
				for (int k = 0; k < 3; k++)
				{
					i = i + k;
					if (k == 2)
						i--;
					int xx3 = 400 + j * 60, yy3 = 220 + i * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
					arr[i][j] = 8;
				}

				for (int k = 0; k < 3; k++)
				{
					j = j - k;
					if (k == 2)
						j++;
					int xx3 = 400 + j * 60, yy3 = 220 + i * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
					arr[i][j] = 8;
				}
				if (num2 == 1)
				{
					arr[m + 2][l] = 15;
					singleicon(arr[m + 2][l], arr, l, m + 2);
				}
				else if (num2 == 2)
				{
					arr[m + 2][l] = 16;
					singleicon(arr[m + 2][l], arr, l, m + 2);
				}
				else if (num2 == 3)
				{
					arr[m + 2][l] = 17;
					singleicon(arr[m + 2][l], arr, l, m + 2);
				}
				else if (num2 == 4)
				{
					arr[m + 2][l] = 18;
					singleicon(arr[m + 2][l], arr, l, m + 2);
				}
				else if (num2 == 5)
				{
					arr[m + 2][l] = 19;
					singleicon(arr[m + 2][l], arr, l, m + 2);
				}
			}
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j])
			{
				score = score + 50;
				/*arr[i][j] = 8;
				arr[i][j + 1] = 8;
				arr[i][j + 2] = 8;*/
				int l = j;
				int m = i;
				int num2 = arr[m][l];
				int num = arr[i][j];
				for (int k = 0; k < 3; k++)
				{
					j = j + k;
					if (k == 2)
						j--;
					int xx3 = 400 + j * 60, yy3 = 220 + i * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
					arr[i][j] = 8;
				}
				for (int k = 0; k < 3; k++)
				{
					i = i + k;
					if (k == 2)
						i--;
					int xx3 = 400 + l * 60, yy3 = 220 + i * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
					arr[i][l] = 8;
				}
				if (num2 == 1)
				{
					arr[m][l] = 15;
					singleicon(arr[m][l], arr, l, m);
				}
				else if (num2 == 2)
				{
					arr[m][l] = 16;
					singleicon(arr[m][l], arr, l, m);
				}
				else if (num2 == 3)
				{
					arr[m][l] = 17;
					singleicon(arr[m][l], arr, l, m);
				}
				else if (num2 == 4)
				{
					arr[m][l] = 18;
					singleicon(arr[m][l], arr, l, m);
				}
				else if (num2 == 5)
				{
					arr[m][l] = 19;
					singleicon(arr[m + 2][l], arr, l, m);
				}
			}
		}
	}
}

//function for blasting bomb for row
void blast_bomb_row3(int arr[][8], int& score)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == 10 || arr[i][j] == 11 || arr[i][j] == 12 || arr[i][j] == 13 || arr[i][j] == 14)
			{
				int num = arr[i][j];
				num = num - 9;
				if (arr[i][j + 1] == num && arr[i][j + 2] == num && j < 7)
				{
					score = score + 30;
					if (i == 0 && j == 0)
					{
						int xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);


						arr[i][j + 1] = 8;
						arr[i][j] = 8;
						arr[i][j] = 8;
						arr[i + 1][j] = 8;
						arr[i + 1][j + 1] = 8;
					}
					else if (i == 7 && j == 0)
					{
						int xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);


						arr[i][j + 1] = 8;
						arr[i][j] = 8;
						arr[i][j] = 8;
						arr[i - 1][j] = 8;
						arr[i - 1][j + 1] = 8;
					}
					else if (i == 0)
					{
						int xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j + 1] = 8;
						arr[i][j] = 8;
						arr[i][j - 1] = 8;
						arr[i][j] = 8;
						arr[i + 1][j] = 8;
						arr[i + 1][j + 1] = 8;
						arr[i + 1][j - 1] = 8;
					}
					else if (j == 0)
					{
						int xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j + 1] = 8;
						arr[i][j] = 8;
						arr[i][j] = 8;
						arr[i - 1][j] = 8;
						arr[i + 1][j] = 8;
						arr[i + 1][j + 1] = 8;
						arr[i - 1][j + 1] = 8;
					}
					else if (i == 7)
					{
						int xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j + 1] = 8;
						arr[i][j] = 8;
						arr[i][j - 1] = 8;
						arr[i][j] = 8;
						arr[i - 1][j] = 8;
						arr[i - 1][j - 1] = 8;
						arr[i - 1][j + 1] = 8;
					}
					else
					{
						int xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j + 1] = 8;
						arr[i][j] = 8;
						arr[i][j - 1] = 8;
						arr[i][j] = 8;
						arr[i - 1][j] = 8;
						arr[i + 1][j] = 8;
						arr[i - 1][j - 1] = 8;
						arr[i + 1][j + 1] = 8;
						arr[i - 1][j + 1] = 8;
						arr[i + 1][j - 1] = 8;
					}

				}
				else if (arr[i][j - 1] == num && arr[i][j + 1] == num && j > 0)
				{
					score = score + 30;
					int xx3 = 400 + (j - 1) * 60, yy3 = 220 + i * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
					xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
					xx3 = 400 + j * 60, yy3 = 220 + i * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
					xx3 = 400 + j * 60, yy3 = 220 + (i + 1) * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
					xx3 = 400 + j * 60, yy3 = 220 + (i - 1) * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
					xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i - 1) * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
					xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i - 1) * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
					xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i + 1) * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
					xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i + 1) * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
					xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
					xx3 = 400 + j * 60, yy3 = 220 + i * 60;
					myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

					arr[i][j - 1] = 8;
					arr[i][j + 1] = 8;
					arr[i][j] = 8;
					arr[i][j + 1] = 8;
					arr[i - 1][j] = 8;
					arr[i + 1][j] = 8;
					arr[i - 1][j - 1] = 8;
					arr[i + 1][j + 1] = 8;
					arr[i - 1][j + 1] = 8;
					arr[i + 1][j - 1] = 8;
				}
				else if (arr[i][j - 1] == num && arr[i][j - 2] == num && j > 1)
				{
					score = score + 30;
					if (i == 0 && j == 7)
					{
						int xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j] = 8;
						arr[i][j - 1] = 8;
						arr[i][j] = 8;
						arr[i + 1][j] = 8;
						arr[i + 1][j - 1] = 8;
					}
					else if (i == 7 && j == 7)
					{
						int xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j] = 8;
						arr[i][j - 1] = 8;
						arr[i][j] = 8;
						arr[i - 1][j] = 8;
						arr[i - 1][j - 1] = 8;
					}
					else if (i == 0)
					{
						int xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j + 1] = 8;
						arr[i][j] = 8;
						arr[i][j] = 8;
						arr[i + 1][j] = 8;
						arr[i + 1][j + 1] = 8;
					}
					else if (i == 7)
					{
						int xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j] = 8;
						arr[i][j - 1] = 8;
						arr[i][j] = 8;
						arr[i - 1][j] = 8;
						arr[i - 1][j - 1] = 8;
					}
					else if (j == 7)
					{
						int xx3 = 400 + (j - 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j - 1] = 8;
						arr[i][j] = 8;
						arr[i - 1][j] = 8;
						arr[i + 1][j] = 8;
						arr[i - 1][j] = 8;
						arr[i - 1][j - 1] = 8;
						arr[i + 1][j - 1] = 8;
					}
					else
					{
						int xx3 = 400 + (j - 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j - 1] = 8;
						arr[i][j] = 8;
						arr[i][j + 1] = 8;
						arr[i - 1][j] = 8;
						arr[i + 1][j] = 8;
						arr[i - 1][j] = 8;
						arr[i - 1][j - 1] = 8;
						arr[i + 1][j + 1] = 8;
						arr[i - 1][j + 1] = 8;
						arr[i + 1][j - 1] = 8;
					}
				}
			}
		}
	}
}

//function for blasting bomb for column
void blast_bomb_column3(int arr[][8], int& score)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == 10 || arr[i][j] == 11 || arr[i][j] == 12 || arr[i][j] == 13 || arr[i][j] == 14)
			{
				int num = arr[i][j];
				num = num - 9;
				if (arr[i + 1][j] == num && arr[i + 2][j] == num && i < 7)
				{
					score = score + 30;
					if (i == 0 && j == 0)
					{
						int xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);


						arr[i][j + 1] = 8;
						arr[i][j] = 8;
						arr[i][j] = 8;
						arr[i + 1][j] = 8;
						arr[i + 1][j + 1] = 8;
					}
					else if (i == 7 && j == 0)
					{
						int xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);


						arr[i][j + 1] = 8;
						arr[i][j] = 8;
						arr[i][j] = 8;
						arr[i - 1][j] = 8;
						arr[i - 1][j + 1] = 8;
					}
					else if (i == 0)
					{
						int xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j + 1] = 8;
						arr[i][j] = 8;
						arr[i][j - 1] = 8;
						arr[i][j] = 8;
						arr[i + 1][j] = 8;
						arr[i + 1][j + 1] = 8;
						arr[i + 1][j - 1] = 8;
					}
					else if (j == 0)
					{
						int xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j + 1] = 8;
						arr[i][j] = 8;
						arr[i][j] = 8;
						arr[i - 1][j] = 8;
						arr[i + 1][j] = 8;
						arr[i + 1][j + 1] = 8;
						arr[i - 1][j + 1] = 8;
					}
					else if (i == 7)
					{
						int xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j + 1] = 8;
						arr[i][j] = 8;
						arr[i][j - 1] = 8;
						arr[i][j] = 8;
						arr[i - 1][j] = 8;
						arr[i - 1][j - 1] = 8;
						arr[i - 1][j + 1] = 8;
					}
					else if (j == 7)
					{
						score = score + 30;
						int		xx3 = 400 + (j - 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j - 1] = 8;
						arr[i][j] = 8;
						arr[i - 1][j] = 8;
						arr[i + 1][j] = 8;
						arr[i - 1][j - 1] = 8;
						arr[i + 1][j - 1] = 8;
					}
					else
					{
						int xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j + 1] = 8;
						arr[i][j] = 8;
						arr[i][j - 1] = 8;
						arr[i][j] = 8;
						arr[i - 1][j] = 8;
						arr[i + 1][j] = 8;
						arr[i - 1][j - 1] = 8;
						arr[i + 1][j + 1] = 8;
						arr[i - 1][j + 1] = 8;
						arr[i + 1][j - 1] = 8;
					}

				}
				else if (arr[i - 1][j] == num && arr[i + 1][j] == num && j >= 0)
				{
					if (j == 7)
					{
						score = score + 30;
						int xx3 = 400 + (j - 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j - 1] = 8;
						arr[i][j] = 8;
						arr[i - 1][j] = 8;
						arr[i + 1][j] = 8;
						arr[i - 1][j - 1] = 8;
						arr[i + 1][j - 1] = 8;
					}
					else
					{
						score = score + 30;
						int xx3 = 400 + (j - 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j - 1] = 8;
						arr[i][j + 1] = 8;
						arr[i][j] = 8;
						arr[i][j + 1] = 8;
						arr[i - 1][j] = 8;
						arr[i + 1][j] = 8;
						arr[i - 1][j - 1] = 8;
						arr[i + 1][j + 1] = 8;
						arr[i - 1][j + 1] = 8;
						arr[i + 1][j - 1] = 8;
					}

				}
				else if (arr[i - 1][j] == num && arr[i - 2][j] == num && j > 1)
				{
					score = score + 30;
					if (i == 0 && j == 7)
					{
						int xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j] = 8;
						arr[i][j - 1] = 8;
						arr[i][j] = 8;
						arr[i + 1][j] = 8;
						arr[i + 1][j - 1] = 8;
					}
					else if (i == 7 && j == 7)
					{
						int xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j] = 8;
						arr[i][j - 1] = 8;
						arr[i][j] = 8;
						arr[i - 1][j] = 8;
						arr[i - 1][j - 1] = 8;
					}
					else if (i == 0)
					{
						int xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j + 1] = 8;
						arr[i][j] = 8;
						arr[i][j] = 8;
						arr[i + 1][j] = 8;
						arr[i + 1][j + 1] = 8;
					}
					else if (i == 7)
					{
						int xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j] = 8;
						arr[i][j - 1] = 8;
						arr[i][j] = 8;
						arr[i - 1][j] = 8;
						arr[i - 1][j - 1] = 8;
					}
					else if (j == 7)
					{
						int xx3 = 400 + (j - 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j - 1] = 8;
						arr[i][j] = 8;
						arr[i - 1][j] = 8;
						arr[i + 1][j] = 8;
						arr[i - 1][j] = 8;
						arr[i - 1][j - 1] = 8;
						arr[i + 1][j - 1] = 8;
					}
					else
					{
						int xx3 = 400 + (j - 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i - 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j - 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + (i + 1) * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + (j + 1) * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						xx3 = 400 + j * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);

						arr[i][j - 1] = 8;
						arr[i][j] = 8;
						arr[i][j + 1] = 8;
						arr[i - 1][j] = 8;
						arr[i + 1][j] = 8;
						arr[i - 1][j] = 8;
						arr[i - 1][j - 1] = 8;
						arr[i + 1][j + 1] = 8;
						arr[i - 1][j + 1] = 8;
						arr[i + 1][j - 1] = 8;
					}
				}
			}
		}
	}
}

//function to blast destroyer gem if consecutive in row
void destroyer_blast_row(int arr[][8], int& score)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == 15 || arr[i][j] == 16 || arr[i][j] == 17 || arr[i][j] == 18 || arr[i][j] == 19)
			{
				int num = arr[i][j];
				num = num - 14;
				if ((arr[i][j + 1] == num && arr[i][j + 2] == num) || (arr[i][j - 1] == num && arr[i][j - 2] == num) || (arr[i][j - 1] == num && arr[i][j + 1] == num))
				{
					score = score + 40;
					for (int k = j; k <= 7; k++)
					{
						int xx3 = 400 + k * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						arr[i][k] = 8;
					}
					for (int k = j; k >= 0; k--)
					{
						int xx3 = 400 + k * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						arr[i][k] = 8;
					}
					for (int l = i; l <= 7; l++)
					{
						int xx3 = 400 + j * 60, yy3 = 220 + l * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						arr[l][j] = 8;
					}
					for (int l = i; l >= 0; l--)
					{
						int xx3 = 400 + j * 60, yy3 = 220 + l * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						arr[l][j] = 8;
					}
				}
			}
		}
	}
}

void destroyer_blast_column(int arr[][8], int& score)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == 15 || arr[i][j] == 16 || arr[i][j] == 17 || arr[i][j] == 18 || arr[i][j] == 19)
			{
				int num = arr[i][j];
				num = num - 14;
				if ((arr[i + 1][j] == num && arr[i + 2][j] == num) || (arr[i - 1][j] == num && arr[i - 2][j] == num) || (arr[i - 1][j] == num && arr[i + 1][j] == num))
				{
					score = score + 40;
					for (int k = j; k <= 7; k++)
					{
						int xx3 = 400 + k * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						arr[i][k] = 8;
					}
					for (int k = j; k >= 0; k--)
					{
						int xx3 = 400 + k * 60, yy3 = 220 + i * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						arr[i][k] = 8;
					}
					for (int l = i; l <= 7; l++)
					{
						int xx3 = 400 + j * 60, yy3 = 220 + l * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						arr[l][j] = 8;
					}
					for (int l = i; l >= 0; l--)
					{
						int xx3 = 400 + j * 60, yy3 = 220 + l * 60;
						myRectangle(xx3, yy3, xx3 + 60, yy3 + 60, 232, 225, 23, 10, 10, 31, 255);
						arr[l][j] = 8;
					}
				}
			}
		}
	}
}

//function to get the gems down on empty spaces
void gemsdown(int arr[][8])
{

	myRectangle(340, 160, 400, 760, 232, 225, 23, 232, 225, 23, 255);
	myRectangle(880, 160, 940, 760, 232, 225, 23, 232, 225, 23, 255);
	myRectangle(340, 160, 940, 220, 232, 225, 23, 232, 225, 23, 255);
	Sleep(20);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == 8)
			{
				if (i == 0)
				{
					arr[i][j] == rand() % 5 + 1;
					singleicon(arr[i][j], arr, j, i);
				}
				while (i > 0)
				{
					swap(arr[i][j], arr[i - 1][j]);
					singleicon(arr[i][j], arr, j, i);
					i--;
					if (i == 0)
					{
						/*arr[i ][j] == rand() % 5 + 1;*/
						singleicon(arr[i][j], arr, j, i);
					}
				}

			}
		}
	}
}

int row_check_3(int arr[][8])
{
	int check = 0;
	for (int i = 0; i < 8 && check == 0; i++)
	{
		for (int j = 0; j < 6 && check == 0; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])
			{
				check = 1;
			}
		}
	}
	return check;
}

int col_check_3(int arr[][8])
{
	int check = 0;
	for (int i = 0; i < 6 && check == 0; i++)
	{
		for (int j = 0; j < 8 && check == 0; j++)
		{
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j])
			{
				check = 1;
			}
		}
	}
	return check;
}

int bomb_check_row(int arr[][8])
{
	int check = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == 10 || arr[i][j] == 11 || arr[i][j] == 12 || arr[i][j] == 13 || arr[i][j] == 14)
			{
				int num = arr[i][j];
				num = num - 9;
				if (arr[i][j + 1] == num && arr[i][j + 2] == num && j < 7)
				{
					check = 1;

				}
				else if (arr[i][j - 1] == num && arr[i][j + 1] == num && j > 0)
				{
					check = 1;
				}
				else if (arr[i][j - 1] == num && arr[i][j - 2] == num && j > 1)
				{
					check = 1;
				}
			}
		}
	}
	return check;
}

int bomb_check_column(int arr[][8])
{
	int check = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == 10 || arr[i][j] == 11 || arr[i][j] == 12 || arr[i][j] == 13 || arr[i][j] == 14)
			{
				int num = arr[i][j];
				num = num - 9;
				if (arr[i + 1][j] == num && arr[i + 2][j] == num && i < 7)
				{
					check = 1;
				}
				else if (arr[i - 1][j] == num && arr[i + 1][j] == num && j > 0)
				{
					check = 1;
				}
				else if (arr[i - 1][j] == num && arr[i - 2][j] == num && j > 1)
				{
					check = 1;
				}
			}
		}
	}
	return check;
}

int destroyer_check_row(int arr[][8])
{
	int check = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == 15 || arr[i][j] == 16 || arr[i][j] == 17 || arr[i][j] == 18 || arr[i][j] == 19)
			{
				int num = arr[i][j];
				num = num - 14;
				if ((arr[i][j + 1] == num && arr[i][j + 2] == num) || (arr[i][j - 1] == num && arr[i][j - 2] == num) || (arr[i][j - 1] == num && arr[i][j + 1] == num))
				{
					check = 1;
				}
			}
		}
	}
	return check;
}

int destroyer_check_column(int arr[][8])
{
	int check = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == 15 || arr[i][j] == 16 || arr[i][j] == 17 || arr[i][j] == 18 || arr[i][j] == 19)
			{
				int num = arr[i][j];
				num = num - 14;
				if ((arr[i + 1][j] == num && arr[i + 2][j] == num) || (arr[i - 1][j] == num && arr[i - 2][j] == num) || (arr[i - 1][j] == num && arr[i + 1][j] == num))
				{
					check = 1;
				}
			}
		}
	}
	return check;
}



void scoreprinter(int score)
{
	int aa2 = 540, aa1 = 1250;
	int rem;
	myRectangle(1020, 520, 1320, 660, 232, 225, 23, 232, 225, 23, 255);
	for (int i = 0; score > 0; i++)
	{
		rem = score % 10;
		if (rem == 0)
		{
			myEllipse3(aa1, aa2, aa1 + 50, aa2 + 100, 255, 0, 0, 255, 0, 0);
		}
		else if (rem == 1)
		{
			myLine(aa1 + 25, aa2, aa1 + 25, aa2 + 100, 5, 255, 0, 0);
			myLine(aa1 + 25, aa2, aa1, aa2 + 20, 5, 255, 0, 0);
		}
		else if (rem == 2)
		{
			myLine(aa1, aa2, aa1 + 50, aa2, 5, 255, 0, 0);
			myLine(aa1 + 50, aa2, aa1 + 50, aa2 + 50, 5, 255, 0, 0);
			myLine(aa1, aa2 + 50, aa1 + 50, aa2 + 50, 5, 255, 0, 0);
			myLine(aa1, aa2 + 50, aa1, aa2 + 100, 5, 255, 0, 0);
			myLine(aa1, aa2 + 100, aa1 + 50, aa2 + 100, 5, 255, 0, 0);
		}
		else if (rem == 3)
		{
			myLine(aa1, aa2, aa1 + 50, aa2, 5, 255, 0, 0);
			myLine(aa1 + 50, aa2, aa1 + 50, aa2 + 50, 5, 255, 0, 0);
			myLine(aa1, aa2 + 50, aa1 + 50, aa2 + 50, 5, 255, 0, 0);
			myLine(aa1 + 50, aa2 + 50, aa1 + 50, aa2 + 100, 5, 255, 0, 0);
			myLine(aa1, aa2 + 100, aa1 + 50, aa2 + 100, 5, 255, 0, 0);
		}
		else if (rem == 4)
		{
			myLine(aa1, aa2 + 70, aa1 + 50, aa2, 5, 255, 0, 0);
			myLine(aa1 + 50, aa2, aa1 + 50, aa2 + 50, 5, 255, 0, 0);
			myLine(aa1, aa2 + 70, aa1 + 55, aa2 + 70, 5, 255, 0, 0);
			myLine(aa1 + 50, aa2 + 50, aa1 + 50, aa2 + 100, 5, 255, 0, 0);
		}
		else if (rem == 5)
		{
			myLine(aa1, aa2, aa1 + 50, aa2, 5, 255, 0, 0);
			myLine(aa1, aa2, aa1, aa2 + 50, 5, 255, 0, 0);
			myLine(aa1, aa2 + 50, aa1 + 50, aa2 + 50, 5, 255, 0, 0);
			myLine(aa1 + 50, aa2 + 50, aa1 + 50, aa2 + 100, 5, 255, 0, 0);
			myLine(aa1, aa2 + 100, aa1 + 50, aa2 + 100, 5, 255, 0, 0);
		}
		else if (rem == 6)
		{
			myLine(aa1, aa2, aa1 + 50, aa2, 5, 255, 0, 0);
			myLine(aa1, aa2, aa1, aa2 + 50, 5, 255, 0, 0);
			myLine(aa1, aa2 + 50, aa1 + 50, aa2 + 50, 5, 255, 0, 0);
			myLine(aa1 + 50, aa2 + 50, aa1 + 50, aa2 + 100, 5, 255, 0, 0);
			myLine(aa1, aa2 + 50, aa1, aa2 + 100, 5, 255, 0, 0);
			myLine(aa1, aa2 + 100, aa1 + 50, aa2 + 100, 5, 255, 0, 0);
		}
		else if (rem == 7)
		{
			aa1 = aa1 - 10;
			myLine(aa1, aa2, aa1 + 60, aa2, 5, 255, 0, 0);
			myLine(aa1 + 60, aa2, aa1 + 40, aa2 + 100, 5, 255, 0, 0);
			aa1 = aa1 + 10;
		}

		else if (rem == 8)
		{
			myLine(aa1, aa2, aa1 + 50, aa2, 5, 255, 0, 0);
			myLine(aa1, aa2, aa1, aa2 + 50, 5, 255, 0, 0);
			myLine(aa1, aa2 + 50, aa1 + 50, aa2 + 50, 5, 255, 0, 0);
			myLine(aa1 + 50, aa2, aa1 + 50, aa2 + 50, 5, 255, 0, 0);
			myLine(aa1 + 50, aa2 + 50, aa1 + 50, aa2 + 100, 5, 255, 0, 0);
			myLine(aa1, aa2 + 50, aa1, aa2 + 100, 5, 255, 0, 0);
			myLine(aa1, aa2 + 100, aa1 + 50, aa2 + 100, 5, 255, 0, 0);
		}
		else if (rem == 9)
		{
			myLine(aa1, aa2, aa1 + 50, aa2, 5, 255, 0, 0);
			myLine(aa1, aa2, aa1, aa2 + 50, 5, 255, 0, 0);
			myLine(aa1, aa2 + 50, aa1 + 50, aa2 + 50, 5, 255, 0, 0);
			myLine(aa1 + 50, aa2, aa1 + 50, aa2 + 50, 5, 255, 0, 0);
			myLine(aa1 + 50, aa2 + 50, aa1 + 50, aa2 + 100, 5, 255, 0, 0);
			myLine(aa1, aa2 + 100, aa1 + 50, aa2 + 100, 5, 255, 0, 0);
		}
		aa1 = aa1 - 70;
		score = score / 10;
	}
}



int main()
{
	auto startingTime = std::time(NULL);
	int BoardValue[8][8];
	int num, score = 0;
	// filling the board by value in 2D array 
	BoardFiller(BoardValue);
	for (int i = 0; i < 6; i++)
	{
		Sleep(100);
	}
	{
		// key for keyPressed and countX and CountY counting index i and J
		int key, countX = 1, countY = 1;
		int  x1 = 400, y1 = 220;

		// filling the board by icons in the grid

		BoardConstructor(BoardValue);

		//scoreboard + designing
		myRectangle(100, 650, 300, 720, 232, 225, 23, 10, 10, 31, 255);
		myRectangle(150, 600, 250, 650, 232, 225, 23, 10, 10, 31, 255);
		myRectangle(175, 70, 225, 600, 10, 10, 31, 232, 225, 23, 255);
		myRectangle(175, 70, 1330, 100, 10, 10, 31, 232, 225, 23, 255);
		myRectangle(400, 100, 450, 200, 232, 225, 23, 10, 10, 31, 255);
		myRectangle(800, 100, 850, 200, 232, 225, 23, 10, 10, 31, 255);
		myRectangle(1070, 100, 1090, 302, 232, 225, 23, 10, 10, 31, 255);
		myRectangle(1250, 100, 1270, 302, 232, 225, 23, 10, 10, 31, 255);
		int aa2 = 180, aa3 = 100;
		for (int i = 0; i < 58; i++)
		{
			myRectangle(aa2, 70, aa2 + 10, 100, 10, 10, 31, 10, 10, 31, 255);
			aa2 = aa2 + 20;
		}
		for (int i = 0; i < 25; i++)
		{
			myRectangle(175, aa3, 225, aa3 + 10, 10, 10, 31, 10, 10, 31, 255);
			aa3 = aa3 + 20;
		}

		myLine(20, 10, 50, 10, 4, 232, 225, 23);
		myLine(35, 10, 35, 50, 4, 232, 225, 23);
		myLine(60, 10, 90, 10, 4, 232, 225, 23);
		myLine(75, 10, 75, 50, 4, 232, 225, 23);
		myLine(60, 50, 90, 50, 4, 232, 225, 23);
		myLine(100, 10, 100, 50, 4, 232, 225, 23);
		myLine(100, 10, 120, 30, 4, 232, 225, 23);
		myLine(120, 30, 140, 10, 4, 232, 225, 23);
		myLine(140, 10, 140, 50, 4, 232, 225, 23);
		myLine(150, 10, 150, 50, 4, 232, 225, 23);
		myLine(150, 50, 180, 50, 4, 232, 225, 23);
		myLine(150, 10, 180, 10, 4, 232, 225, 23);
		myLine(150, 30, 180, 30, 4, 232, 225, 23);

		//scoreboard
		myRectangle(1020, 300, 1320, 540, 232, 225, 23, 10, 10, 31, 255);

		// Main cursor rectangle of Gaming Area
		myRectangle2(400, 220, 460, 280, 255, 255, 255, 0, 0, 0, 255);


		// Mian Loop starts for the GamePlay 
		float x5 = 250;
		int x4 = 250;
		int z = 1;
		//232, 225, 23
		myRectangle2(250, 20, 1100, 40, 232, 225, 23, 232, 225, 23, 255);
		while (z != 0)
		{
			if (std::time(0) - startingTime > 60)
			{
				cout << "time hogaya";
				z = 0;
			}
			if (startingTime % 10 == 0)
			{
				myRectangle(x4, 20, 50 + x5, 40, 232, 225, 23, 232, 225, 23, 255);
				x5 = x5 + 0.5;
			}
			myRectangle(x4, 20, 50 + x5, 40, 232, 225, 23, 232, 225, 23, 255);
			x5 = x5 + 0.5;

			Blast_elbow(BoardValue, score);
			destroyer_blast_column(BoardValue, score);
			destroyer_blast_row(BoardValue, score);
			blast_bomb_row3(BoardValue, score);
			blast_bomb_column3(BoardValue, score);
			Blast_4_column(BoardValue, score);
			Blast_4_row(BoardValue, score);
			Blast_3_row(BoardValue, score);
			Blast_3_column(BoardValue, score);
			gemsdown(BoardValue);

			scoreprinter(score);
			num = 0;
			if (isCursorKeyPressed(key))
			{
				if (key == 3 && x1 <= 760)
				{
					myRectangle2(x1, y1, x1 + 60, y1 + 60, 232, 225, 23, 0, 0, 0, 0);
					x1 = x1 + 60;
					myRectangle2(x1, y1, 60 + x1, y1 + 60, 255, 255, 255, 0, 0, 0, 0);
					countY++;
				}
				else if (key == 1 && x1 >= 460)
				{
					myRectangle2(x1, y1, x1 + 60, y1 + 60, 232, 225, 23, 0, 0, 0, 0);
					x1 = x1 - 60;
					myRectangle2(x1, y1, 60 + x1, y1 + 60, 255, 255, 255, 0, 0, 0, 0);
					countY--;
				}
				else if (key == 2 && y1 >= 280)
				{
					myRectangle2(x1, y1, x1 + 60, y1 + 60, 232, 225, 23, 0, 0, 0, 0);
					y1 = y1 - 60;
					myRectangle2(x1, y1, 60 + x1, y1 + 60, 255, 255, 255, 0, 0, 0, 0);
					countX--;
				}
				else if (key == 4 && y1 <= 580)
				{
					myRectangle2(x1, y1, x1 + 60, y1 + 60, 232, 225, 23, 0, 0, 0, 0);
					y1 = y1 + 60;
					myRectangle2(x1, y1, 60 + x1, y1 + 60, 255, 255, 255, 0, 0, 0, 0);
					countX++;
				}
				else if (key == 5)
				{
					while (num == 0)
					{
						if (isCursorKeyPressed2(key))
						{
							int p = countX - 1;
							int q = countY - 1;
							if (key == 3 && q < 7)
							{
								rightswap(BoardValue, p, q);
								if (row_check_3(BoardValue) == 0 && col_check_3(BoardValue) == 0)
								{
									if (bomb_check_column(BoardValue) == 0 && bomb_check_row(BoardValue) == 0)
									{
										if (destroyer_check_column(BoardValue) == 0 && destroyer_check_row(BoardValue) == 0)
										{
											for (int i = 0; i < 6; i++)
											{
												Sleep(25);
											}
											rightswap(BoardValue, p, q);
										}
									}
								}
							}
							else if (key == 1 && q > 0)
							{
								leftswap(BoardValue, p, q);
								if (row_check_3(BoardValue) == 0 && col_check_3(BoardValue) == 0)
								{
									if (bomb_check_column(BoardValue) == 0 && bomb_check_row(BoardValue) == 0)
									{
										if (destroyer_check_column(BoardValue) == 0 && destroyer_check_row(BoardValue) == 0)
										{
											for (int i = 0; i < 6; i++)
											{
												Sleep(25);
											}
											leftswap(BoardValue, p, q);
										}
									}
								}
							}
							else if (key == 2 && p > 0)
							{
								upswap(BoardValue, p, q);
								if (row_check_3(BoardValue) == 0 && col_check_3(BoardValue) == 0)
								{
									if (bomb_check_column(BoardValue) == 0 && bomb_check_row(BoardValue) == 0)
									{
										if (destroyer_check_column(BoardValue) == 0 && destroyer_check_row(BoardValue) == 0)
										{
											for (int i = 0; i < 6; i++)
											{
												Sleep(25);
											}
											upswap(BoardValue, p, q);
										}
									}
								}
							}
							else if (key == 4 && p < 7)
							{
								downswap(BoardValue, p, q);
								if (row_check_3(BoardValue) == 0 && col_check_3(BoardValue) == 0)
								{
									if (bomb_check_column(BoardValue) == 0 && bomb_check_row(BoardValue) == 0)
									{
										if (destroyer_check_column(BoardValue) == 0 && destroyer_check_row(BoardValue) == 0)
										{
											for (int i = 0; i < 6; i++)
											{
												Sleep(25);
											}
											downswap(BoardValue, p, q);
										}
									}
								}
							}
							num = 1;
							destroyer_blast_column(BoardValue, score);
							destroyer_blast_row(BoardValue, score);
							Blast_elbow(BoardValue, score);
							blast_bomb_row3(BoardValue, score);
							blast_bomb_column3(BoardValue, score);
							Blast_4_row(BoardValue, score);
							gemsdown(BoardValue);
							blast_bomb_row3(BoardValue, score);
							Blast_3_row(BoardValue, score);
							gemsdown(BoardValue);
							blast_bomb_row3(BoardValue, score);
							Blast_4_column(BoardValue, score);
							gemsdown(BoardValue);
							blast_bomb_row3(BoardValue, score);
							Blast_3_column(BoardValue, score);
							gemsdown(BoardValue);
							blast_bomb_row3(BoardValue, score);

							scoreprinter(score);

						}

					}
				}
			}
		}

	}
	system("CLS");
	cout << "GAME OVER!!";
	return 0;
}