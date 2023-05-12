#include <windows.h>
#include <iostream>
#include "Header.h"
#include "console.h"
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include"mmsystem.h"
#include <mciapi.h>
using namespace std;
int main()
{
	PlaySound(TEXT("nhacnen.wav"), NULL, SND_ASYNC);
	resizeConsole(900, 450);
	FixConsoleWindow();
	PrintCaro();
	Begin();
	Loading();
	menu();
}
