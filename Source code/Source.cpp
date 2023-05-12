#include <windows.h>
#include <iostream>
#include <windows.h> 
#include <type_traits>
#include <type_traits>
#include < stdio.h >
#include <ctime>
#include "Header.h"
#include "game.h"
#include "console.h"
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
struct Base {};
struct Derived : Base {};
using namespace std;
int dodai=16;

//setColor
void Textcolor(int color)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, color);
}

//Dia chi
void gotoXY(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void PrintCaro()
{
	int a, b;
	for (int a = 0; a < 20; a++) {
		system("cls");
		int x = 28, y = 0;
		Textcolor(rand() % 4 + 9);
		gotoXY(x, y);				   cout << "ooooooooooooo";
		gotoXY(x - 3, y + 1);			cout << "oooooooooooooooo";
		gotoXY(x - 5, y + 2);    cout << "oooooooooooooooooo";
		gotoXY(x - 6, y + 3);   cout << "ooooooooooooooooooo";
		Textcolor(rand() % 15 + 1);
		gotoXY(x - 7, y + 4);  cout << "ooooooo";
		gotoXY(x - 8, y + 5); cout << "ooooooo";
		gotoXY(x - 8, y + 6); cout << "ooooooo";
		gotoXY(x - 8, y + 7); cout << "ooooooo";
		gotoXY(x - 8, y + 8); cout << "ooooooo";
		gotoXY(x - 8, y + 9); cout << "ooooooo";
		Textcolor(rand() % 15 + 1);
		gotoXY(x - 8, y + 10); cout << "ooooooo";
		gotoXY(x - 7, y + 11); cout << "ooooooo";
		gotoXY(x - 6, y + 12);  cout << "ooooooooooooooooooo";
		gotoXY(x - 5, y + 13);   cout << "oooooooooooooooooo";
		Textcolor(rand() % 15 + 1);
		gotoXY(x - 3, y + 14);		cout << "oooooooooooooooo";
		gotoXY(x, y + 15);			   cout << "ooooooooooooo";
		Textcolor(rand() % 15 + 1);
		gotoXY(x - 4 + 22, y + 4);				    cout << "ooooooooooo";
		gotoXY(x - 4 + 22 - 2, y + 5);		      cout << "ooooooooooooooo";
		gotoXY(x - 4 + 22 - 3, y + 6);		     cout << "ooooooooooooooooo";
		Textcolor(rand() % 15 + 1);
		gotoXY(x - 4 + 22 - 3, y + 7);			 cout << "ooooooooooooooooo";
		gotoXY(x - 4 + 22 - 3, y + 8);			 cout << "oooooo     oooooo";
		gotoXY(x - 4 + 22 - 3, y + 9);			 cout << "oooooo     oooooo";
		Textcolor(rand() % 15 + 1);
		gotoXY(x - 4 + 22 - 3, y + 10);		    cout << "oooooo     oooooo";
		gotoXY(x - 4 + 22 - 3, y + 11);		    cout << "ooooooooooooooooo";
		gotoXY(x - 4 + 22 - 3, y + 12);		    cout << "oooooo     oooooo";
		Textcolor(rand() % 15 + 1);
		gotoXY(x - 4 + 22 - 3, y + 13);		    cout << "oooooo     oooooo";
		gotoXY(x - 4 + 22 - 3, y + 14);		    cout << "oooooo     oooooo";
		gotoXY(x - 4 + 22 - 3, y + 15);		    cout << "oooooo     oooooo";

		Textcolor(rand() % 15 + 1);

		gotoXY(x + 33, y + 4);			cout << "ooooo   ooooooooo";
		gotoXY(x + 33, y + 5);			cout << "oooooooooooooooooo";
		gotoXY(x + 33, y + 6);		    cout << "ooooooooooooooooooo";
		Textcolor(rand() % 15 + 1);
		gotoXY(x + 33, y + 7);			cout << "oooooooooooooooooooo";
		gotoXY(x + 1 + 33, y + 8);		cout << "ooooooo     ooooooo";
		gotoXY(x + 1 + 33, y + 9);	    cout << "ooooooo     ooooooo";
		Textcolor(rand() % 15 + 1);
		gotoXY(x + 1 + 33, y + 10);		cout << "ooooooo";
		gotoXY(x + 1 + 33, y + 11);		cout << "ooooooo";
		gotoXY(x + 1 + 33, y + 12);		cout << "ooooooo";
		Textcolor(rand() % 15 + 1);
		gotoXY(x + 1 + 33, y + 13);		cout << "ooooooo";
		gotoXY(x + 1 + 33, y + 14);		cout << "ooooooo";
		gotoXY(x + 1 + 33, y + 15);		cout << "ooooooo";
		// Textcolor(Yellow);
		gotoXY(x + 57, y + 4);					cout << "ooooooooooo";
		gotoXY(x + 57 - 2, y + 5);			  cout << "ooooooooooooooo";
		Textcolor(rand() % 15 + 1);
		gotoXY(x + 57 - 3, y + 6);			 cout << "ooooooooooooooooo";
		gotoXY(x + 57 - 3, y + 7);			 cout << "ooooooooooooooooo";
		Textcolor(rand() % 15 + 1);
		gotoXY(x + 57 - 3, y + 8);			 cout << "oooooo     oooooo";
		gotoXY(x + 57 - 3, y + 9);			 cout << "oooooo     oooooo";
		gotoXY(x + 57 - 3, y + 10);          cout << "oooooo     oooooo";
		gotoXY(x + 57 - 3, y + 11);		     cout << "oooooo     oooooo";
		Textcolor(rand() % 15 + 1);
		gotoXY(x + 57 - 3, y + 12);		     cout << "ooooooooooooooooo";
		gotoXY(x + 57 - 3, y + 13);		     cout << "ooooooooooooooooo";
		Textcolor(rand() % 15 + 1);
		gotoXY(x + 57 - 2, y + 14);		     cout << "ooooooooooooooo";
		gotoXY(x + 57, y + 15);				   cout << "ooooooooooo";



		int i = 27, j = 20;

		gotoXY(i, j - 3);  cout << "                            ooo";
		gotoXY(i, j - 2);  cout << "                           oo";
		gotoXY(i, j - 1);  cout << "                          o";
		gotoXY(i, j);      cout << "oooo    ooo   ooo  ooo  ooooooo  oooo         ooo     ooooo  oooooo          ";
		gotoXY(i, j + 1);  cout << "ooooo   ooo   ooo  ooo  oo   oo  ooooo      ooooo         o  o              ";
		gotoXY(i, j + 2);  cout << "ooo  oo ooo   oooooooo  oo   oo  ooo  oo   oo ooo     ooooo  oooooo          ";
		gotoXY(i, j + 3);  cout << "ooo   ooooo   ooo  ooo  oo   oo  ooo   ooooo  ooo     o           o    ";
		gotoXY(i, j + 4);  cout << "ooo    oooo   ooo  ooo  ooooooo  ooo    ooo   ooo     ooooo  oooooo    ";

		Textcolor(5);
		int h = 10, k = 15;
		Textcolor(rand() % 15 + 1);
		gotoXY(h - 3, k);          cout << "ooooo     ooooo";
		gotoXY(h - 2, k + 1);    cout << "ooooo   ooooo";
		gotoXY(h + 2, k + 2);    cout << "ooooo";
		gotoXY(h + 2, k + 3);    cout << "ooooo";
		gotoXY(h - 2, k + 4);       cout << "ooooo   ooooo";
		gotoXY(h - 3, k + 5);         cout << "ooooo     ooooo";


		int m = 102, n = 15;
		Textcolor(rand() % 15 + 1);
		gotoXY(m - 1, n);          cout << "oooooooooooo";
		gotoXY(m - 1, n + 1);    cout << "oo	       oo";
		gotoXY(m - 1, n + 2);    cout << "oo	       oo";
		gotoXY(m - 1, n + 3);     cout << "oo	       oo";
		gotoXY(m - 1, n + 4);    cout << "oo	       oo";
		gotoXY(m - 1, n + 5);           cout << "oooooooooooo";

	}
	Sleep(5000);
}
void Begin()
{
	system("cls");
	gotoXY(47, 2);
	Textcolor(12);
	cout << "        CONNECTING";
	gotoXY(13, 4);
	Textcolor(12); //print("%c%c%c", 3, 3, 3); gotoxy(65, 4); cout("%c%c%c", 3, 3, 3);
	// gotoxy(18,6); textcolor(14); printf("____________________________________________");
	gotoXY(50, 6);
	Textcolor(13);
	cout << "  Loading......10%   ";
	gotoXY(35, 7);
	Textcolor(14);
	cout << "______________________________________________________";
}

//---------LOADING GAME---------
int Loading()
{
	Begin();
	gotoXY(40, 10);
	Textcolor(15);
	cout << "Nhom 25 ";
	Sleep(2000);
	gotoXY(50, 6);
	Textcolor(13);
	cout << "Loading......15%   ";
	gotoXY(40, 10);
	Textcolor(15);
	cout << "Le Cong Dat ";
	Sleep(1500);
	gotoXY(50, 6);
	Textcolor(13);
	cout << "Loading......27%   ";
	gotoXY(40, 10);
	Textcolor(15);
	cout << "Nguyen Lam Que Anh ";
	Sleep(1500);
	gotoXY(50, 6);
	Textcolor(13);
	cout << "Loading......30%   ";
	gotoXY(40, 10);
	Textcolor(15);
	cout << "Nguyen Lam Hung    ";
	Sleep(1500);
	gotoXY(50, 6);
	Textcolor(13);
	cout << "Loading......45%   ";
	gotoXY(40, 10);
	Textcolor(15);
	cout << "To Tran Son Ba     ";
	Sleep(1500);
	gotoXY(50, 6);
	Textcolor(13);
	cout << "Loading......60%   ";
	gotoXY(40, 10);
	Textcolor(15);
	cout << "Do Tan Tai         ";
	Sleep(1500);
	gotoXY(50, 6);
	Textcolor(13);
	cout << "Loading......70%   ";
	gotoXY(40, 10);
	Textcolor(15);
	cout << "Van Hoang Gia";
	Sleep(1500);
	gotoXY(50, 6);
	Textcolor(13);
	cout << "Loading......85%   ";
	gotoXY(40, 10);
	Textcolor(15);
	cout << "GVHD: Truong Toan Thinh";
	Sleep(2000);
	gotoXY(50, 6);
	Textcolor(13);
	cout << "Loading......99%   ";
	gotoXY(10, 10);
	Textcolor(15);
	Sleep(4000);
	gotoXY(50, 6);
	Textcolor(13);
	cout << "Loading......100%        ";
	gotoXY(40, 10);
	Textcolor(15);
	cout << "Loading game...            ";
	Sleep(3000);
	system("cls");
	return 0;
}

void Huongdan()
{
	while (1)
	{
		system("cls");
		ifstream FileIn;
		FileIn.open("Huongdan.txt", ios::in);
		while (!FileIn.eof())
		{
			char c;
			FileIn.get(c);
			Textcolor(14);
			cout << c;
		}
		FileIn.close();
		cout << endl << endl << endl << endl;
		Textcolor(15);
		cout << "Press ESC to back to the menu" << endl;
		if (_kbhit())
		{
			char key = _getch();
			if (key == 27) break;
		}
		Sleep(500);
	}
}

void SetCaro2()
{
	system("cls");
	int x = 22, y = 4;
	Textcolor(rand() % 15 + 1);
	gotoXY(x - 2, y - 1); cout << "oooooooooooo                  oooooooooooo";
	gotoXY(x, y);           cout << "oooooooooooo              oooooooooooo";
	gotoXY(x + 2, y + 1);     cout << "oooooooooooo          oooooooooooo";
	gotoXY(x + 4, y + 2);       cout << "oooooooooooo      oooooooooooo";
	gotoXY(x + 6, y + 3);         cout << "oooooooooooo  oooooooooooo";
	gotoXY(x + 8, y + 4);           cout << "oooooooooooooooooooooo";
	gotoXY(x + 6, y + 5);         cout << "oooooooooooo  oooooooooooo";
	gotoXY(x + 4, y + 6);       cout << "oooooooooooo      oooooooooooo";
	gotoXY(x + 2, y + 7);     cout << "oooooooooooo          oooooooooooo";
	gotoXY(x, y + 8);      cout << "oooooooooooo              oooooooooooo";
	gotoXY(x - 2, y + 9); cout << "oooooooooooo                  oooooooooooo";

	Textcolor(rand() % 15 + 1);
	gotoXY(x + 57, y - 1);					cout << "oooooooooooooooooo";
	gotoXY(x + 57 - 2, y);			      cout << "oooooooooooooooooooooo";
	gotoXY(x + 57 - 3, y + 1);			 cout << "oooooooooooooooooooooooo";
	gotoXY(x + 57 - 3, y + 2);			 cout << "ooooooo          ooooooo";
	gotoXY(x + 57 - 3, y + 3);			 cout << "oooooo            oooooo";
	gotoXY(x + 57 - 3, y + 4);			 cout << "oooooo            oooooo";
	gotoXY(x + 57 - 3, y + 5);		     cout << "oooooo            oooooo";
	gotoXY(x + 57 - 3, y + 6);		     cout << "ooooooo          ooooooo";
	gotoXY(x + 57 - 3, y + 7);		     cout << "oooooooooooooooooooooooo";
	gotoXY(x + 57 - 2, y + 8);		      cout << "oooooooooooooooooooooo";
	gotoXY(x + 57, y + 9);				    cout << "oooooooooooooooooo";
	cout << endl << endl << endl << endl;
}
void menu()
{
	resizeConsole(900, 450);
	PlaySound(TEXT("nentrong.wav"), NULL, SND_ASYNC);
	const char* menu[] = { "NEW GAME", "LOAD GAME", "HOW TO PLAY", "SETTINGS", "ABOUT", "EXIT" };
	int pointer = 0;
	while (1)
	{
		system("cls");
		SetCaro2();
		for (int i = 0; i < maxlist; i++)
			if (pointer == i)
			{
				Textcolor(206);
				cout << "\t\t\t\t\t\t\t" << menu[i] << endl;
				Textcolor(15);
			}
			else
			{
				Textcolor(15);
				cout << "\t\t\t\t\t\t\t" << menu[i] << endl;
			}
		while (1)
		{
			if (_kbhit())
			{
				char key = _getch();
				if (key == 72)
				{
					if (pointer > 0)
					{
						pointer--;
					}
					else
					{
						pointer = maxlist - 1;
					}
					break;
				}
				if (key == 80)
				{
					if (pointer < maxlist - 1)
					{
						pointer++;
					}
					else
					{
						pointer = 0;
					}
					break;
				}
				if (key == 13)
				{
					switch (pointer)
					{
					case 0:
						resetLuot();
						fxuli();
						break;
					case 1:
						    wrlistfile(true);
							fmenuseved();
							int n;
							cout << "Moi ban nhap STT file: ";
							cin >> n;
							loadgame(n);
							if (_kbhit())
							{
								char key = _getch();
								if (key == 27) break;
							}
						
						break;
					case 2: Huongdan(); break;
					case 3: set(dodai); break;
					case 4: about(); break;
					case 5: exit(); break;
					}
					break;
				}
			}
			Sleep(1);
		}
	}
}
void about()
{
	while (1)
	{
		system("cls");
		Textcolor(15);
		cout << "=============== ABOUT ===============" << endl;
		Textcolor(14);
		cout << "TRUONG DAI HOC KHOA HOC TU NHIEN TPHCM - HCMUS" << endl;
		cout << "DO AN CARO" << endl;
		Textcolor(11);
		cout << "Nhom 25 lop 20CTT3 nam hoc 2020-2021" << endl;
		cout << "20120408 Do Tan Tai" << endl;
		cout << "20120428 Nguyen Lam Que Anh" << endl;
		cout << "20120431 To Tran Son Ba" << endl;
		cout << "20120454 Le Cong Dat" << endl;
		cout << "20120464 Van Hoang Gia" << endl;
		cout << "20120487 Nguyen Lam Hung" << endl;
		cout << "GVHD: TRUONG TOAN THINH" << endl;
		Textcolor(15);
		cout << "=====================================" << endl;
		cout << endl << endl << endl << endl;
		cout << "Press ESC to back to the menu" << endl;
		if (_kbhit())
		{
			char key = _getch();
			if (key == 27) break;
		}
		Sleep(500);
	}
	
}
void exit()
{
	system("cls");
	exit(0);
}
void set(int& n)
{
	system("cls");
		cout << "===============SETTINGS===========" << endl;
		cout << "Moi ban nhap kich thuoc ban co" << endl;
		cout << "Tu 5x5 den 16x16" << endl;
		cout << "Kich thuoc ban co NxN" << endl;
		cout << "Moi ban nhap N: ";
		cin >> n;
}
int kichthuoc()
{
	return dodai;
}

