#include "ThuVien.h"
#include <fstream>
using namespace std;
void docfile(ThuVien &thuVien)
{
    ifstream fin1("tensach.txt");
    if (fin1.is_open())
    {
        string line;
        while (getline(fin1, line))
        {
            CSach *sach = new CSach(line, 0, 0);
            thuVien.ThemSach(sach);
        }
        fin1.close();
    }

    ifstream fin2("soluong.txt");
    if (fin2.is_open())
    {
        CSach *current = thuVien.head;
        int tongsosach, tongdangmuon;
        for (int i = 1; i <= thuVien.count; i++)
        {
            fin2 >> tongsosach >> tongdangmuon;
            current->SetTongSoQuyenSach(tongsosach);
            current->SetSoSachDangMuon(tongdangmuon);
            current = current->GetNext();
        }
        fin2.close();
    }
}
void luufile(ThuVien &thuVien)
{

    ifstream fin3("theend.txt");
    if (fin3.is_open())
    {
        string line;

        while (getline(fin3, line))
        {
            cout << line << endl;
        }
        fin3.close();
    }
    ofstream fout1("tensach.txt", std::ios::out | std::ios::trunc);
    if (fout1.is_open())
    {
        CSach *current = thuVien.head;
        while (current != NULL)
        {
            if (current->GetTongSoQuyenSach() > 0)
            {
                fout1 << current->GetTenSach() << endl;
            }
            current = current->GetNext();
        }
    }
    fout1.close();
    ofstream fout2("soluong.txt", std::ios::out | std::ios::trunc);

    if (fout2.is_open())
    {
        CSach *current = thuVien.head;
        while (current != NULL)
        {
            if (current->GetTongSoQuyenSach() > 0)
            {
                fout2 << current->GetTongSoQuyenSach() << " " << current->GetSoSachDangMuon() << endl;
            }
            current = current->GetNext();
        }
    }
    fout2.close();
}

int main()
{
    system("cls");
    ThuVien thuVien;
    docfile(thuVien);
    Console::BangGioiThieuTacGia();
    Console::manhinhdanhsach();
    thuVien.InDanhSachSach(26, 7, -1);
    getch();
    system("cls");
    Console::manhinhchinh();
    int choice;
    while (1)
    {
        Console::gotoxy(24, 15);
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            thuVien.NhapDanhSach();
            break;
        }
        case 2:
        {
            string s;
            cin.ignore();
            Console::gotoxy(50, 7);
            cout << "Nhap ten sach can tim : ";
            getline(cin, s);

            CSach *current = thuVien.TimSach(s);
            if (current != NULL)
            {
                Console::gotoxy(50, 8);
                cout << "Ten sach :" << current->GetTenSach() << endl;
                Console::gotoxy(50, 9);
                cout << "Tong so quyen sach :" << current->GetTongSoQuyenSach() << endl;
                Console::gotoxy(50, 10);
                cout << "So sach dang muon :" << current->GetSoSachDangMuon() << endl;
                cout << endl;
            }
            else
            {
                Console::gotoxy(50, 8);
                cout << "Sach khong co trong thu vien\n";
            }
            getch();
            for (int i = 7; i <= 10; i++)
            {
                Console::gotoxy(50, i);
                for (int j = 0; j <= 30; j++)
                    cout <<" ";
            }
            break;
        }
        case 3:
        {
            thuVien.InDanhSachSach(27, 7, 0);
            _getch();
            system("cls");
            Console::manhinhchinh();
            break;
        }
        case 4:
        {
            string s;
            int SoSachXoa;
            cin.ignore();
            Console::gotoxy(50, 7);
            cout << "Nhap ten sach can xoa : ";
            getline(cin, s);

            CSach *current = thuVien.TimSach(s);
            if (current != NULL)
            {
                Console::gotoxy(50, 8);
                cout << "Ten sach :" << current->GetTenSach() << endl;
                Console::gotoxy(50, 9);
                cout << "Tong so quyen sach :" << current->GetTongSoQuyenSach() << endl;
                Console::gotoxy(50, 10);
                cout << "So sach con lai :" << current->GetSoSachConLai() << endl;
                cout << endl;
                Console::gotoxy(50, 11);
                cout << "Nhap so sach can xoa (yeu cau <= So sach con lai) : ";
                cin >> SoSachXoa;
                while(SoSachXoa>current->GetSoSachConLai()||SoSachXoa<0)
                {
                    Console::gotoxy(50, 12);
                    cout<<"So sach can xoa khong hop le! Vui long nhap lai";
                    getch();
                    Console::gotoxy(50,12);
                    for(int i=0;i<=48;i++) cout<<" ";
                    Console::gotoxy(103,11); cout<<"                ";
                    Console::gotoxy(103,11);
                    cin>>SoSachXoa;
                }
                thuVien.XoaSach(current, SoSachXoa);
            }
            else
            {
                Console::gotoxy(50, 8);
                cout << "Sach khong co trong thu vien\n";
            }
            getch();            
            for (int i = 7; i <= 12; i++)
            {
                Console::gotoxy(50, i);
                for (int j = 0; j <= 60; j++)
                    cout << " ";
            }
            break;
        }
        case 5:
        {
            string s;
            int SoSachMuon;
            cin.ignore();
            Console::gotoxy(50, 7);
            cout << "Nhap ten sach can muon: ";
            getline(cin, s);

            CSach *current = thuVien.TimSach(s);
            if (current != NULL)
            {
                Console::gotoxy(50, 8);
                cout << "Ten sach :" << current->GetTenSach() << endl;
                Console::gotoxy(50, 9);
                cout << "Tong so quyen sach :" << current->GetTongSoQuyenSach() << endl;
                Console::gotoxy(50, 10);
                cout << "So sach con lai :" << current->GetSoSachConLai() << endl;
                cout << endl;
                Console::gotoxy(50, 11);
                cout << "Nhap so sach can muon (yeu cau <= So sach con lai) : ";

                cin >> SoSachMuon;
                 while(SoSachMuon>current->GetSoSachConLai()||SoSachMuon<0)
                {
                    Console::gotoxy(50, 12);
                    cout<<"So sach can xoa khong hop le! Vui long nhap lai";
                    getch();
                    Console::gotoxy(50,12);
                    for(int i=0;i<=48;i++) cout<<" ";
                    Console::gotoxy(103,11); cout<<"                ";
                    Console::gotoxy(103,11);
                    cin>>SoSachMuon;
                }
                thuVien.MuonSach(current, SoSachMuon);
            }
            else
            {
                Console::gotoxy(50, 8);
                cout << "Sach khong co trong thu vien\n";
            }
            getch();
            for (int i = 7; i <= 12; i++)
            {
                Console::gotoxy(50, i);
                for (int j = 0; j <= 60; j++)
                    cout << " ";
            }
            break;
        }
        case 6:
        {
            string s;
            int SoSachTra;
            cin.ignore();
            Console::gotoxy(50, 7);
            cout << "Nhap ten sach can tra : ";
            getline(cin, s);

            CSach *current = thuVien.TimSach(s);
            if (current != NULL)
            {
                Console::gotoxy(50, 8);
                cout << "Ten sach :" << current->GetTenSach() << endl;
                Console::gotoxy(50, 9);
                cout << "Tong so quyen sach :" << current->GetTongSoQuyenSach() << endl;
                Console::gotoxy(50, 10);
                cout << "So sach dang muon :" << current->GetSoSachDangMuon() << endl;
                cout << endl;
                Console::gotoxy(50, 11);
                cout << "Nhap so sach can tra (yeu cau <= So sach dang muon) : ";
                cin >> SoSachTra;
                 while(SoSachTra>current->GetSoSachDangMuon()||SoSachTra<0)
                {
                    Console::gotoxy(50, 12);
                    cout<<"So sach can xoa khong hop le! Vui long nhap lai";
                    getch();
                    Console::gotoxy(50,12);
                    for(int i=0;i<=48;i++) cout<<" ";
                    Console::gotoxy(103,11); cout<<"                ";
                    Console::gotoxy(103,11);
                    cin>>SoSachTra;
                }
                thuVien.TraSach(current, SoSachTra);
            }
            else
            {
                Console::gotoxy(50, 8);
                cout << "Sach khong co trong thu vien\n";
            }
            getch();
            for (int i = 7; i <= 12; i++)
            {
                Console::gotoxy(50, i);
                for (int j = 0; j <= 60; j++)
                    cout << " ";
            }
            break;
        }
        case 7:
        {

            system("cls");
            luufile(thuVien);
            exit(0);
        }
        default:
        {
            Console::gotoxy(50, 7);
            cout << "Lua chon khong hop le. Hay chon lai!";
            getch();
            Console::gotoxy(50, 7);
            for (int i = 0; i < 40; i++)
                cout <<"  ";
        }
        }
        Console::gotoxy(24, 15);
        cout << "   ";
    }
    return 0;
}