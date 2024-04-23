#include <string>
using namespace std;
class CSach
{
private:
    string TenSach;
    int TongSoQuyenSach;
    int SoSachDangMuon;
    CSach *next;
public:
    CSach(string , int, int);
    string GetTenSach();
    int GetTongSoQuyenSach();
    int GetSoSachDangMuon();
    int GetSoSachConLai();
    CSach *GetNext();
    void SetNext(CSach *next);
    void SetTongSoQuyenSach(int);
    void SetSoSachDangMuon(int);
};