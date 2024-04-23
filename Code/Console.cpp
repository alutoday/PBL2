#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include "Console.h"
using namespace std;
void Console::gotoxy(short x, short y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x, y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void Console::SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void Console::textcolor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void Console::setColor(int maunen, int mauchu)
{
    SetBGColor(maunen);
    textcolor(mauchu);
}
void Console::ThanhNgang(int x, int y, int dodai, int maunen, int mauchu, int makitu)
{
    setColor(maunen, mauchu);
    for (int i = x; i < x + dodai; i++)
    {
        gotoxy(i, y);
        cout << char(makitu);
    }
}
void Console::ThanhTru(int x, int y, int dodai, int maunen, int mauchu, int makitu)
{
    setColor(maunen, mauchu);
    for (int j = y; j < y + dodai; j++)
    {
        gotoxy(x, j);
        cout << char(makitu) << char(makitu);
    }
}
void Console::BangGioiThieuTacGia()
{
    ThanhNgang(1, 8, 132, 7, 14, 177);
    setColor(0, 14);
    gotoxy(50, 10);
    cout << "PBL2- DU AN CO SO LAP TRINH" << endl;
    gotoxy(48, 11);
    cout << "XAY DUNG HE THONG QUAN LY THU VIEN" << endl;
    gotoxy(10, 15);
    cout << "* GVHD : Nguyen Van Nguyen";
    gotoxy(65, 15);
    cout << "*  SV : Ly Hoang Quyen(22T_DT5)";
    gotoxy(65, 17);
    cout << "        Nguyen Thi Ngoc Anh(22T_Nhat2)";
    ThanhNgang(1, 19, 132, 7, 14, 177);
    _getch();
    system("cls");
}
void Console::khungtrong(int y)
{
    if (y > 0)
    {
        ThanhNgang(0, y, 133, 2, 9, 177);
        ThanhTru(0, 0, 36, 2, 9, 177);
        ThanhTru(131, 0, 36, 2, 9, 177);
    }
    else
    {
        ThanhTru(0, 0, 2, 2, 9, 177);
        ThanhTru(131, 0, 2, 2, 9, 177);
    }
    setColor(0, 14);
}
void Console::duongngang(int x, int y, int dodai)
{
    gotoxy(x, y);
    for (int i = 0; i < dodai; i++)
        cout << "-";
    cout << endl;
}

void Console::manhinhdanhsach()
{   
    setColor(0,14);
    system("cls");
    ThanhNgang(0, 0, 132, 2, 9, 177);
    setColor(0,14);
    char date[10];
    gotoxy(120, 1);
    cout << _strdate(date) << endl;
    gotoxy(50, 3);
    cout << "** QUAN LY SACH THU VIEN **";
    
}
void Console::manhinhchinh()
{
    system("cls");
    ThanhNgang(0, 0, 131, 2, 9, 177);
    ThanhTru(0, 0, 35, 2, 9, 177);
    ThanhTru(131, 0, 35, 2, 9, 177);
    ThanhTru(45, 5, 35, 2, 9, 177);
    ThanhNgang(0, 5, 133, 2, 9, 177);
    ThanhNgang(0, 35, 133, 2, 9, 177);
    setColor(0, 14);
    char date[10];
    gotoxy(120, 1);
    cout << _strdate(date) << endl;
    gotoxy(50, 2);
    cout << "TRUONG DAI HOC BACH KHOA";
    gotoxy(49, 3);
    cout << "** QUAN LY SACH THU VIEN **";
    gotoxy(3, 7);
    cout << "BANG LUA CHON";
    gotoxy(3, 8);
    cout << "1. Cap nhat them sach";
    gotoxy(3, 9);
    cout << "2. Tim sach theo ten";
    gotoxy(3, 10);
    cout << "3. Liet ke sach hien co trong thu vien";
    gotoxy(3, 11);
    cout << "4. Xoa sach";    
    gotoxy(3, 12);
    cout << "5. Muon sach";
    gotoxy(3, 13);
    cout << "6. Tra sach";
    gotoxy(3, 14);
    cout<< "7.Thoat chuong trinh";
    gotoxy(3,15);
    cout << "Nhan lua chon (1-7) : ";
}