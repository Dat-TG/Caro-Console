#include "game.h"
#include "Board.h"
#include "console.h"
#include "Header.h"
#include <string>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>

using namespace std;

//cac bien toan cuc
int BOARD_SIZE = kichthuoc();
#define LEFT 2
#define TOP 1
#define size 16
struct _POINT { int x, y, c; }; //x,y: toa do; c: 0 la chua danh, 1 la x, -1 la 0

_POINT _A[16][16];

int _COMMAND; // bien nhan thao tac ng dung
bool _TURN; //true la luoc x - false la luoc o
int _X, _Y, _N = 0;
int _POS[1000];
int _COUNDX = 0, _COUNDO = 0; //dem so lan di cua x va o
int dem = 1, soquanP1 = 0, soquanP2 = 0, win1 = 0, win2 = 0;//so luot, so tran thang
string _LINKFILE = "F:/Filegame/Filegame";
string _LISTFILE = "F:/Filegame/list_game.txt";
string _FILE = ""; //danh sach game da luu
string _SAVED; //neu tiep tuc game tung save thi luu filename


void gotoxy(int x, int y) {
       COORD coord;
       coord.X = x;
       coord.Y = y;
       SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void drawboard()
{
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            gotoxy(_A[i][j].x, _A[i][j].y);
            if (_A[i][j].c == 0) cout << ' ';
            else if (_A[i][j].c == -1)
            {
                setColor(11);
                cout << 'x';
            }
            else
            {
                setColor(12);
                cout << 'o';
            }
        }
    gotoxy(_A[_X][_Y].x, _A[_X][_Y].y);
}

void processfinish(int whowin)
{
    switch (whowin)
    {
    case -1: // hien giao dien x thang
        PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);
        win1++;
        gotoxy(16 * 4 + 25 + 3+29, 6);
        cout << win1;
        while (1)
        {
            for (int a = 0; a < 20; a++) {
                Textcolor(rand() % 14 + 1);
                int m = 10, n = 15;
                gotoxy(m, n - 1);
                cout << "                                                ";
                gotoxy(m, n);
                cout << " @@     @@    @       @       @   @   @       @ ";
                gotoxy(m, n + 1);
                cout << "   @@  @@      @     @ @     @    @   @ @     @ ";
                gotoxy(m, n + 2);
                cout << "     @@         @   @   @   @     @   @   @   @ ";
                gotoxy(m, n + 3);
                cout << "   @@  @@        @ @     @ @      @   @     @ @ ";
                gotoxy(m, n + 4);
                cout << " @@      @@       @       @       @   @       @ ";
                gotoxy(m, n + 5);
                cout << "                                                ";
                gotoxy(m, n + 6);
                setColor(226);
                cout << "Press ESC to back to menu or SPACE to continue";
                if (_kbhit())
                {
                    char key = _getch();
                    if (key == 27)
                    {
                        setColor(15);
                        exitgame();
                    }
                    if (key == 32)
                    {
                        _TURN = !_TURN;
                        fxuli();
                    }
                }
                Sleep(10);
            }
        }
    case 1: // hien giao dien o thang
        resetLuot();
        PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);
        gotoxy(16* 4 + 25 + 3 + 29, 18);
        win2++;
        cout << win2;
        while (1)
        {
            for (int a = 0; a < 20; a++) {
                Textcolor(rand() % 14 + 1);
                int m = 10, n = 15;
                gotoxy(m, n - 1);
                cout << "                                                ";
                gotoxy(m, n);
                cout << " @@@@@@@@@    @       @       @   @   @       @ ";
                gotoxy(m, n + 1);
                cout << " @       @     @     @ @     @    @   @ @     @ ";
                gotoxy(m, n + 2);
                cout << " @       @      @   @   @   @     @   @   @   @ ";
                gotoxy(m, n + 3);
                cout << " @       @       @ @     @ @      @   @     @ @ ";
                gotoxy(m, n + 4);
                cout << " @@@@@@@@@        @       @       @   @       @ ";
                gotoxy(m, n + 5);
                cout << "                                                ";
                gotoxy(m, n + 6);
                setColor(226);
                cout << "Press ESC to back to menu or SPACE to continue";
                if (_kbhit())
                {
                    char key = _getch();
                    if (key == 27)
                    {
                        setColor(15);
                        exitgame();
                    }
                    if (key == 32) fxuli();
                }
                Sleep(10);
            }
        }
    case 0: // hien giao dien hoa
        PlaySound(TEXT("hoa.wav"), NULL, SND_ASYNC);
        while (1)
        {
            for (int a = 0; a < 20; a++) {
                Textcolor(rand() % 14 + 1);
                int m = 10, n = 15;
                gotoxy(m, n - 1);
                cout << "                                     ";
                gotoxy(m, n);
                cout << " @       @     @@@@@@@@@        @    ";
                gotoxy(m, n + 1);
                cout << " @       @     @       @      @   @  ";
                gotoxy(m, n + 2);
                cout << " @@@@@@@@@     @       @     @@@@@@@ ";
                gotoxy(m, n + 3);
                cout << " @       @     @       @     @     @ ";
                gotoxy(m, n + 4);
                cout << " @       @     @@@@@@@@@     @     @ ";
                gotoxy(m, n + 5);
                cout << "                                     ";
                gotoxy(m, n + 6);
                setColor(226);
                cout << "Press ESC to back to menu or SPACE to continue";
                if (_kbhit())
                {
                    char key = _getch();
                    if (key == 27)
                    {
                        setColor(15);
                        exitgame();
                    }
                    if (key == 32) fxuli();
                }
                Sleep(10);
            }
        }
        break;
    default: _TURN = !_TURN;
    }
}

int fnhap(int dau, int cuoi)
{
    return 1;
}

int fmenuchinh(int x)
{
    //cout << "1. Start new game\n";
    //cout << "2. Seved games\n";
    return x;
}

void fxuli()
{
    system("cls");
    int cuoi = fmenuchinh(1);
    int lenh = fnhap(1, cuoi);
    switch (lenh)
    {
    case 1:
        newgame();
        dem = 1;
        soquanP1 = 0;
        soquanP2 = 0;
        console_go(dem, soquanP1, soquanP2);
        break;
    case 2:
        cuoi = fmenuseved();
        fxuli_seved();
        break;
    }

}

int fmenuseved()
{
    system("cls");
    while (_N == 0)
    {
        system("cls");
        cout << "Chua co file nao duoc luu" << endl;
        cout << "Press ESC to back to menu";
        Sleep(500);
        if (_kbhit())
        {
            char key = _getch();
            if (key == 27) menu();
        }
    }
    cout << "\tLIST GAME\n";
    for (int i = 0; i < _N; i++)
    {
        cout << i + 1 << ". " << _FILE.substr(_POS[i], _POS[i + 1] - 2) << endl;
    }
    return _N;
}

void fxuli_seved()
{
    int cuoi = fmenuseved();
    int lenh = fnhap(0, cuoi);
    if (lenh == 0) fxuli();
    else loadgame(lenh);
}

// (*) model function
void resetdata()
{
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            _A[i][j].x = 4 * i + LEFT;
            _A[i][j].y = 2 * j + TOP;
            _A[i][j].c = 0;
        }
    _SAVED = " ";
    _X = 0;  _Y = 0;
}

// (*) control function
void newgame()
{
    system("cls");
    resetdata();
    resizeConsole(1000, 650);
    f_DrawBoard(kichthuoc());
    drawboard();
}

void exitgame()
{
    setColor(226);
    gotoxy(10, 14);
    cout << "                                  ";
    gotoxy(10, 15);
    cout << "  Do you want to save this game?  ";
    gotoxy(10, 16);
    cout << "  1.YES       2.NO      3.CANCEL  ";
    gotoxy(10, 17);
    cout << "                                  ";
    char lenh = _getch();
    if (lenh == '1')
    {
        if (_SAVED == " ")
        {
            gotoxy(10, 18);
            cout << " File name:                             ";
            gotoxy(10, 19);
            cout << "                                         ";
            gotoxy(21, 18);
            string filename;
            cin >> filename;
            int pos = _FILE.find(' ' + filename, 0);
            if (pos == -1 || _FILE[pos + 1 + filename.length()] != ' ')
            {
                _POS[_N] = _FILE.length() + 1;
                _N++;
                _FILE += ' ' + filename;
            }
            savegame(_LINKFILE + filename + ".txt");
            wrlistfile(false);
            menu();
        }
        else {
            savegame(_SAVED);
            menu();//
        }
    }
    else if (lenh == '2')
    {
        menu();
    }
    else if (lenh == '3')
    {
        gotoxy(10, 15);
        cout << "                                            \n";
        gotoxy(11, 15);
        cout << "                                                ";
        f_DrawBoard(kichthuoc());
        drawboard();
    }
    else exitgame();
}

void savegame(string filename)
{
    fstream datafile;
    datafile.open(filename, ios::out);
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            datafile << _A[i][j].x << ' ' << _A[i][j].y << ' ' << _A[i][j].c << ' ';
        }
        datafile << endl;
    }
    datafile << _TURN << ' ' << _X << ' ' << _Y << endl;
    datafile << dem<<' '<<soquanP1 << ' ' << soquanP2 << endl;
    datafile.close();
}

void loaddata(string filename)
{
    fstream datafile;
    datafile.open(filename, ios::in);
    resizeConsole(1000, 650);
    f_DrawBoard(kichthuoc());
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            datafile >> _A[i][j].x>> _A[i][j].y>> _A[i][j].c;
        }
    }
    datafile >> _TURN >> _X >> _Y;
    datafile >> dem>> soquanP1 >> soquanP2;
    datafile.close();
}

void loadgame(int stt)
{
    while (stt<1 || stt>_N)
    {
        cout << "File khong ton tai!" << endl;
        cout << "Moi ban nhap lai: ";
        cin >> stt;
    }
    system("cls");
    _SAVED = _LINKFILE + _FILE.substr(_POS[stt - 1], _POS[stt] - 2) + ".txt";
    loaddata(_SAVED);
    drawboard();
    console_go(dem, soquanP1, soquanP2);
}

void wrlistfile(bool flag) //true: lay du lieu  false: ghi du lieu
{
    fstream datafile;
    if (flag)
    {
        _N = 0;
        datafile.open(_LISTFILE, ios::in);
        getline(datafile, _FILE);
        for (int i = 0; i < _FILE.length(); i++)
        {
            if (_FILE[i] == ' ')
            {
                _POS[_N] = i + 1;
               _N++;
            }
        }
    }
    else {
        datafile.open(_LISTFILE, ios::out);
        datafile << _FILE << endl;
    }
    datafile.close();
}

void resetLuot()
{
    _TURN = true;
}

void console_go(int&dem, int&soquanP1, int&soquanP2) 
{
    setColor(10);
    gotoxy(16 * 4 + 25 + 3 + 29, 6);
    cout << win1;
    gotoxy(16 * 4 + 25 + 3 + 29, 18);
    cout << win2;
    if (_TURN)
    {
        gotoxy(9, size * 2 + 2);
        cout << "PLAYER 1";
        gotoxy(_A[_X][_Y].x, _A[_X][_Y].y);
    }
    else
    {
        gotoxy(9, size * 2 + 2);
        cout << "PLAYER 2";
        gotoxy(_A[_X][_Y].x, _A[_X][_Y].y);
    }
    _COMMAND = toupper(_getch());
    {
        switch (_COMMAND)
        {
        case 'W':
            if (_Y > 0)
            {
                _Y--;
                PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);
                gotoxy(_A[_X][_Y].x, _A[_X][_Y].y);
            }
            break;
        case 'S':
            if (_Y < kichthuoc() - 1)
            {
                _Y++;
                PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);
                gotoxy(_A[_X][_Y].x, _A[_X][_Y].y);
            }
            break;
        case 'A':
            if (_X > 0)
            {
                _X--;
                PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);
                gotoxy(_A[_X][_Y].x, _A[_X][_Y].y);
            }
            break;
        case 'D':
            if (_X < kichthuoc() - 1)
            {
                _X++;
                PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);
                gotoxy(_A[_X][_Y].x, _A[_X][_Y].y);
            }
            break;
        case 13:
            setColor(10);
            if (_A[_X][_Y].c == 0)
            {
                if (_TURN)
                {
                    gotoxy(9, size * 2 + 2);
                    cout << "PLAYER 2";
                    soquanP1++;
                    gotoxy(_A[_X][_Y].x, _A[_X][_Y].y);
                    setColor(11);
                    cout << 'x';
                    setColor(10);
                    _A[_X][_Y].c = -1;
                    gotoxy(size * 4 + 25 + 3 + 18 + 1, 5);
                    cout << soquanP1;
                    gotoxy(_A[_X][_Y].x, _A[_X][_Y].y);
                }
                else
                {
                    gotoxy(9, size * 2 + 2);
                    cout << "PLAYER 1";
                    soquanP2++;
                    gotoxy(_A[_X][_Y].x, _A[_X][_Y].y);
                    setColor(12);
                    cout << 'o';
                    setColor(10);
                    _A[_X][_Y].c = 1;
                    gotoxy(size * 4 + 25 + 2 + 18 + 2, 17);
                    cout << soquanP2;
                    gotoxy(_A[_X][_Y].x, _A[_X][_Y].y);
                }
                PlaySound(TEXT("tick.wav"), NULL, SND_SYNC);
                gotoxy(_A[_X][_Y].x, _A[_X][_Y].y);
            }
            processfinish(testboard());
            break;
        case 27:
            exitgame();
            break;
        }
    }
    console_go(dem, soquanP1, soquanP2);
}

bool check_cot(int x, int y)
{
    char temp = 1;
    for (int i = 1; i <= 4; i++)
    {
        if (_A[x][y].c != _A[x][y + i].c || y + i >= BOARD_SIZE)
        {
            temp += i - 1;
            break;
        }
        else if (i == 4) return true;
    }
    for (int i = 1; i <= 4; i++)
    {
        if (_A[x][y].c != _A[x][y - i].c || y - i < 0)
        {
            temp += i - 1;
            break;
        }
        else if (i == 4) return true;
    }
    if (temp >= 5) return true;
    else return false;
}

bool check_hang(int x, int y)
{
    char temp = 1;
    for (int i = 1; i <= 4; i++)
    {
        if (_A[x][y].c != _A[x + i][y].c || x + i >= BOARD_SIZE)
        {
            temp += i - 1;
            break;
        }
        else if (i == 4) return true;
    }
    for (int i = 1; i <= 4; i++)
    {
        if (_A[x][y].c != _A[x - i][y].c || x - i < 0)
        {
            temp += i - 1;
            break;
        }
        else if (i == 4) return true;
    }
    if (temp >= 5) return true;
    else return false;
}

bool check_xeochinh(int x, int y)
{
    char temp = 1;
    for (int i = 1; i <= 4; i++)
    {
        if (_A[x][y].c != _A[x + i][y + i].c || x + i >= BOARD_SIZE || y + i >= BOARD_SIZE)
        {
            temp += i - 1;
            break;
        }
        else if (i == 4) return true;
    }
    for (int i = 1; i <= 4; i++)
    {
        if (_A[x][y].c != _A[x - i][y - i].c || x - i < 0 || y - i < 0)
        {
            temp += i - 1;
            break;
        }
        else if (i == 4) return true;
    }
    if (temp >= 5) return true;
    else return false;
}

bool check_xeophu(int x, int y)
{
    char temp = 1;
    for (int i = 1; i <= 4; i++)
    {
        if (_A[x][y].c != _A[x - i][y + i].c || x - i < 0 || y + i >= BOARD_SIZE)
        {
            temp += i - 1;
            break;
        }
        else if (i == 4) return true;
    }
    for (int i = 1; i <= 4; i++)
    {
        if (_A[x][y].c != _A[x + i][y - i].c || x + i >= BOARD_SIZE || y - i < 0)
        {
            temp += i - 1;
            break;
        }
        else if (i == 4) return true;
    }
    if (temp >= 5) return true;
    else return false;
}

short testboard()
{
    //ma tran day => hoa
    if (soquanP1+soquanP2 >= kichthuoc()*kichthuoc()) return 0;
    else
    {
        if (check_cot(_X, _Y) || check_hang(_X, _Y) || check_xeochinh(_X, _Y) || check_xeophu(_X, _Y))
        {
            return (_TURN == true ? -1 : 1);
        }
        else return 2;
    }
}
