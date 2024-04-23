#include "CSach.h"
#include<iomanip>
using namespace std;
CSach::CSach(string TenSach, int TongSoQuyenSach, int SoSachDangMuon)
{
    this->TenSach=TenSach;
    this->TongSoQuyenSach=TongSoQuyenSach;
    this->SoSachDangMuon=SoSachDangMuon;
    this->next=NULL;
}

int CSach:: GetSoSachConLai()
{
    return this->TongSoQuyenSach-this->SoSachDangMuon;
}

string  CSach::GetTenSach()
{
    return this->TenSach;
}

int CSach::GetTongSoQuyenSach()
{
    return this->TongSoQuyenSach;
}
int CSach::GetSoSachDangMuon()
{
    return this->SoSachDangMuon;
}
CSach* CSach::GetNext()
{
    return this->next;
}

void CSach::SetTongSoQuyenSach(int soluongthem)
{
    this->TongSoQuyenSach+=soluongthem;
}
void CSach::SetSoSachDangMuon(int soluongthem)
{
    this->SoSachDangMuon+=soluongthem;
}
void CSach::SetNext(CSach *next)

{
    this->next=next;
}