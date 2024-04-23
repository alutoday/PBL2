#include "Console.h"
#include "CSach.h"
#include <iostream>
#include <string>
#include <windows.h>
#include<iomanip>
#include<conio.h>
using namespace std;
class ThuVien
{  
   
   public:
   CSach *head;
   static int count;
   ThuVien();
   void ThemSach(CSach*);
   void NhapDanhSach();
   void InDanhSachSach(int,int,int);   
   CSach* TimSach(string);
   void XoaSach(CSach*, int);
   void MuonSach(CSach*, int );
   void TraSach(CSach*, int);
};

