#include "ThuVien.h"

using namespace std;
int ThuVien::count = 0;
CSach *head;
ThuVien::ThuVien()
{
    head = NULL;
}
void ThuVien::ThemSach(CSach *Sach)
{
    count++;
    if (head == NULL)
    {
        head = Sach;
    }
    else
    {
        CSach *current = head;
        while (current->GetNext() != NULL)
        {
            current = current->GetNext();
        }
        current->SetNext(Sach);
    }
}

void ThuVien::NhapDanhSach()
{
    int n;
    int x = 50, y = 7;
    Console::gotoxy(x, y);
    cout << "Nhap so luong sach: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string TenSach;
        int TongSoQuyen, SoSachDangMuon;
        Console::gotoxy(x, y + 1);
        cout << "Nhap ten sach thu " << i + 1 << ": ";
        getline(cin, TenSach);

        Console::gotoxy(x, y + 2);
        cout << "Nhap tong so quyen cua sach thu " << i + 1 << ": ";
        cin >> TongSoQuyen;

        Console::gotoxy(x, y + 3);
        cout << "Nhap so sach dang muon cua sach thu " << i + 1 << ": ";
        cin >> SoSachDangMuon;

        while (SoSachDangMuon > TongSoQuyen&&SoSachDangMuon>=0)
        {
            Console::gotoxy(x, y + 6);
            cout << "So sach dang muon khong hop le! Vui long nhap lai";
            getch();
            Console::gotoxy(x, y + 6);
            for (int i = 0; i < 50; i++)
                cout << " ";
            Console::gotoxy(x + 39, y + 3);
            for (int i = 0; i < 10; i++)
                cout << " ";
            Console::gotoxy(x + 39, y + 3);
            cin >> SoSachDangMuon;
        }

        Console::gotoxy(x, y + 1);
        for (int i = 0; i <= 50; i++)
            cout << " ";
        Console::gotoxy(x, y + 2);
        for (int i = 0; i <= 50; i++)
            cout << " ";
        Console::gotoxy(x, y + 3);
        for (int i = 0; i <= 50; i++)
            cout << " ";

        cin.ignore();
        CSach *current = head;
        while (current != NULL)
        {
            if (current->GetTenSach() == TenSach)
            {
                current->SetTongSoQuyenSach(TongSoQuyen);
                current->SetSoSachDangMuon(SoSachDangMuon);
                break;
            }
            current = current->GetNext();
        }
        if (current == NULL)
        {
            CSach *sach = new CSach(TenSach, TongSoQuyen, SoSachDangMuon);
            ThemSach(sach);
        }
    }

    Console::gotoxy(x, y);
    cout << "CAP NHAT SACH THANH CONG";
    getch();
    Console::gotoxy(x, y);
    for (int i = 0; i <= 30; i++)
        cout << " ";
}

void ThuVien::InDanhSachSach(int x, int y, int z = -1)
{

    Console::manhinhdanhsach();
    Console::khungtrong(0);
    if (z == 0)
    {
        Console::gotoxy(46, 5);
        cout << "DANH SACH SACH CON LAI TRONG THU VIEN";
    }
    else
    {
        Console::gotoxy(49, 5);
        cout << "DANH SACH SACH TRONG THU VIEN";
    }
    int k = 0;
    CSach *current = head;
    if (current == NULL)
    {
        Console::khungtrong(35);
        Console::gotoxy(x+27, y);
        cout << "Thu vien chua co sach." << endl;
    }
    else
    {
        Console::duongngang(x, ++y, 85);
        Console::gotoxy(x, ++y);
        cout << "| " << setw(20) << left << "Ten sach";
        cout << "| " << setw(17) << left << "Tong so sach";
        cout << "| " << setw(20) << left << "So sach dang muon";
        cout << "| " << setw(17) << left << "So sach con lai"
             << "  |" << endl;
        Console::duongngang(x, ++y, 85);
        while (current != NULL)
        {   
            k++;
            if (current->GetSoSachConLai() > z)
            {
                
                Console::gotoxy(x, min(++y, 35));
                cout << "| " << setw(20) << left << current->GetTenSach();
                cout << "| " << setw(17) << left << current->GetTongSoQuyenSach();
                cout << "| " << setw(20) << left << current->GetSoSachDangMuon();
                cout << "| " << setw(17) << left << current->GetSoSachConLai() << "  |";
                cout << endl;
                Console::duongngang(x, min(++y, 35), 85);                
                Console::khungtrong(-1);                
            }
            current = current->GetNext();
            if (k == count)   Console::khungtrong(35);
        }
    }
}

CSach *ThuVien::TimSach(string tenSach)
{
    CSach *current = head;
    while (current != NULL)
    { 
        if (current->GetTenSach() == tenSach)
        {   
            if(current->GetTongSoQuyenSach()<=0) return NULL;
            return current;
        }
        current = current->GetNext();
    }
    return NULL;
}
void ThuVien::XoaSach(CSach* Sach, int SoSachXoa)
{   
    Sach->SetTongSoQuyenSach(SoSachXoa*(-1));   
}
void ThuVien::MuonSach(CSach* Sach, int SoSachMuon)
{
    Sach->SetSoSachDangMuon(SoSachMuon);
}
void ThuVien::TraSach(CSach* Sach, int SoSachTra)
{
    Sach->SetSoSachDangMuon(SoSachTra*(-1));
}