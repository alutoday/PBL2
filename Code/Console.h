#pragma once
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
class Console
{
public:
    static void gotoxy(short x, short y);
    static void SetBGColor(WORD color);
    static void textcolor(WORD color);
    static void setColor(int maunen, int mauchu);
    static void ThanhNgang(int x, int y, int dodai, int maunen, int mauchu, int makitu);
    static void ThanhTru(int x, int y, int dodai, int maunen, int mauchu, int makitu);
    static void BangGioiThieuTacGia();
    static void khungtrong(int y);
    static void duongngang(int x, int y, int dodai);
    static void manhinhdanhsach();
    static void manhinhchinh();
};