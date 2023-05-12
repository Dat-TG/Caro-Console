#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "console.h"
#include "Board.h"
#include "Header.h"
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
using namespace std;
// tien khai bao
void f_DrawBoardplayer2(int width, int hight, int size);
void f_DrawBoardplayer1(int width, int hight, int size);
void f_printCARO(int size);
void f_DrawBoardMenu(int width, int hight, int size);
int f_winPlayer1() { return 1; }
int f_winPlayer2() { return 1; }
//
//
void f_DrawBoard(int size)
{
	if (size == 0) return;
	setColor(9);
	// ##########################
	//vẽ bàn cờ
	for (int i = 0; i < size * 2 - 1; i++)
	{
		// Ve cot phai
		gotoxy(size * 4, i + 1);
		if ((i + 1) % 2 == 1)
			cout << char(179);
		else cout << char(180);
	}
	// ve cot trai
	for (int i = 0; i < size * 2 - 1; i++)
	{
		gotoxy(0, i + 1);
		if ((i + 1) % 2 == 1)
			cout << char(179);
		else cout << char(195);
	}
	// ve hang tren
	gotoxy(1, 0);
	for (int i = 0; i < size * 4 - 1; i++)
	{
		if ((i + 1) % 4 == 0)
			cout << char(194);
		else cout << char(196);
	}
	//
	// ve hang duoi
	gotoxy(1, size * 2);
	for (int i = 0; i < size * 4 - 1; i++)
	{
		if ((i + 1) % 4 == 0)
			cout << char(193);
		else cout << char(196);
	}
	//
	//goc trai tren
	gotoxy(0, 0);
	cout << char(218);
	//goc phai tren
	gotoxy(size * 4, 0);
	cout << char(191);
	// goc trai duoi
	gotoxy(0, size * 2);
	cout << char(192);
	//goc phai duoi
	gotoxy(size * 4, size * 2);
	cout << char(217);
	// dong thuong
	for (int i = 1; i < size * 2 - 2; i = i + 2)
	{
		gotoxy(1, i + 1);
		for (int j = 1; j < size * 4; j++)
		{
			if (j % 4 == 0)
				cout << char(197);
			else
				cout << char(196);
		}
	}
	// ve cot thuong
	for (int i = 0; i < size * 4; i = 4 + i)
	{
		for (int j = 1; j < size * 2; j++)
		{
			gotoxy(i, j);
			cout << char(179);
		}
	}
	// khung player
	f_DrawBoardplayer1(40, 8, 16);
	f_DrawBoardplayer2(40, 8, 16);
	f_DrawBoardMenu(40, 8, 16);
	gotoxy(0, 16 * 2 + 1);
	for (int i = 0; i <= 16 * 4 + 25 + 40; i++)
		cout << char(205);
	gotoxy(2, 16 * 2 + 2);
	cout << "Luot: ";
	f_printCARO(16);
	setColor(14);
}

void f_DrawBoardplayer1(int width, int hight, int size)
{
	setColor(8);
	// ve khung player
	// ve hang tren player 1
	gotoxy(size * 4 + 25, 0);
	for (int i = 0; i < width; i++)
	{
		cout << char(178);
	}
	// ve hang duoi player 1
	gotoxy(size * 4 + 25, hight);
	for (int i = 0; i < width; i++)
	{
		cout << char(178);
	}
	// ve hang doc trai Player 1
	for (int i = 0; i < hight; i++)
	{
		gotoxy(size * 4 + 25, i);
		cout << char(178);
	}
	// ve hang doc phai player 1

	for (int i = 0; i < hight + 1; i++)
	{
		gotoxy(size * 4 + 25 + width, i);
		cout << char(178);
	}
	//nội dung bên trong khung player
	gotoxy(size * 4 + 25 + (width - 8) / 2, 2);
	setColor(14);
	cout << " PLAYER 1 ";
	setColor(15); cout << "X";
	setColor(14);
	gotoxy(size * 4 + 25 + 3, 5);
	cout << " So quan Player 1: "; //<< f_soquanPlayer1();
	gotoxy(size * 4 + 25 + 3, 6);
	cout << " So tran thang cua Player 1: ";// << f_winPlayer1();
}
void f_DrawBoardplayer2(int width, int hight, int size)
{
	setColor(8);
	// ve khung player
	// ve hang tren player 1
	gotoxy(size * 4 + 25, hight + 4);
	for (int i = 0; i < width; i++)
	{
		cout << char(178);
	}
	// ve hang duoi player 1
	gotoxy(size * 4 + 25, hight + hight + 4);
	for (int i = 0; i < width; i++)
	{
		cout << char(178);
	}
	// ve hang doc trai Player 1
	for (int i = 0; i < hight; i++)
	{
		gotoxy(size * 4 + 25, i + hight + 4);
		cout << char(178);
	}
	// ve hang doc phai player 1

	for (int i = 0; i < hight + 1; i++)
	{
		gotoxy(size * 4 + 25 + width, i + hight + 4);
		cout << char(178);
	}
	// noi dung trong khung player
	gotoxy(size * 4 + 25 + (width - 8) / 2, hight + 4 + 2);
	setColor(14);
	cout << "PLAYER 2 ";
	setColor(4); cout << "O";
	setColor(14);
	gotoxy(size * 4 + 25 + 2, hight + 4 + 5);
	cout << " So quan Player 2: ";// << f_soquanPlayer1();
	gotoxy(size * 4 + 25 + 2, hight + 4 + 6);
	cout << " So tran thang cua Player 2: ";// << f_winPlayer1();
		// in chu VS
	gotoxy(size * 4 + 25 + width / 2 - 1, hight + 2);
	cout << "VS";
}
void f_printCARO(int size)
{
	//tạo màu ngẫu nhiên
	srand(time(NULL));
	setColor(rand() % 16);
	// in chữ CARO
	gotoxy(size * 4 + 8, 0);     cout << "  cccccc";
	gotoxy(size * 4 + 8, 1);   cout << " cc    ";
	gotoxy(size * 4 + 8, 2);   cout << "c";
	gotoxy(size * 4 + 8, 3);   cout << " cc    ";
	gotoxy(size * 4 + 8, 4);   cout << "  cccccc";
	//
	gotoxy(size * 4 + 8, (size * 2 - 20) / 4 + 5);      cout << "    a";
	gotoxy(size * 4 + 8, (size * 2 - 20) / 4 + 6);    cout << "   a  a";
	gotoxy(size * 4 + 8, (size * 2 - 20) / 4 + 7);    cout << "  aaaaaa";
	gotoxy(size * 4 + 8, (size * 2 - 20) / 4 + 8);     cout << " a      a";
	gotoxy(size * 4 + 8, (size * 2 - 20) / 4 + 9);   cout << "a        a";
	//
	gotoxy(size * 4 + 8 + 2, 2 * (size * 2 - 20) / 4 + 10);      cout << "aaaaa";
	gotoxy(size * 4 + 8 + 2, 2 * (size * 2 - 20) / 4 + 11);      cout << "a    a";
	gotoxy(size * 4 + 8 + 2, 2 * (size * 2 - 20) / 4 + 12);      cout << "aaaaa";
	gotoxy(size * 4 + 8 + 2, 2 * (size * 2 - 20) / 4 + 13);      cout << "a    a";
	gotoxy(size * 4 + 8 + 2, 2 * (size * 2 - 20) / 4 + 14);      cout << "a     a";
	//
	gotoxy(size * 4 + 8 + 1, 3 * (size * 2 - 20) / 4 + 15);  cout << "   oo";
	gotoxy(size * 4 + 8 + 1, 3 * (size * 2 - 20) / 4 + 16);  cout << " o    o";
	gotoxy(size * 4 + 8 + 1, 3 * (size * 2 - 20) / 4 + 17);  cout << "o      o";
	gotoxy(size * 4 + 8 + 1, 3 * (size * 2 - 20) / 4 + 18);  cout << " o    o";
	gotoxy(size * 4 + 8 + 1, 3 * (size * 2 - 20) / 4 + 19);  cout << "   oo";
	//
	for (int i = 0; i < size * 2; i++)
	{
		gotoxy(size * 4 + 5, i);
		cout << char(4);
	}
	for (int i = 0; i < size * 2; i++)
	{
		gotoxy(size * 4 + 5 + 15, i);
		cout << char(4);
	}
}
void f_DrawBoardMenu(int width, int hight, int size)
{
	setColor(8);
	// ve khung player
	// ve hang tren player 1
	gotoxy(size * 4 + 25, 2 * (hight + 4));
	for (int i = 0; i < width; i++)
	{
		cout << char(178);
	}
	// ve hang duoi player 1
	gotoxy(size * 4 + 25, hight + 2 * (hight + 4));
	for (int i = 0; i < width; i++)
	{
		cout << char(178);
	}
	// ve hang doc trai Player 1
	for (int i = 0; i < hight; i++)
	{
		gotoxy(size * 4 + 25, i + 2 * (hight + 4));
		cout << char(178);
	}
	// ve hang doc phai player 1

	for (int i = 0; i < hight + 1; i++)
	{
		gotoxy(size * 4 + 25 + width, i + 2 * (hight + 4));
		cout << char(178);
	}
	// noi dung trong khung player
	string tenmenu = " Selection ";
	gotoxy(size * 4 + 25 + (width - tenmenu.length()) / 2, 2 * (hight + 4));
	setColor(10);
	cout << tenmenu;
	gotoxy(size * 4 + 25 + (width - tenmenu.length()) / 2-1, 2 * (hight + 4)+4);
	cout << "Press ESC to exit";
	gotoxy(size * 4 + 25 + (width - tenmenu.length()) / 2-1, 2 * (hight + 4) + 3);
	cout << "Move by W, A, S, D";
	gotoxy(size * 4 + 25 + (width - tenmenu.length()) / 2 - 1, 2 * (hight + 4) +5);
	cout << "Let's start!!!";
	setColor(4);
	setColor(14);
	gotoxy(size * 4 + 25 + 2, 2 * (hight + 4) + 2);
	cout << " ";
	gotoxy(size * 4 + 25 + 2, hight + 4 + 6);
	cout << " ";
}