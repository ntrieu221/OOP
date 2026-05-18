#include "CongTyXYZ.h"
#include "KhachHang.h"
#include "LoaiKhachHang.h"
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

CongTyXYZ::CongTyXYZ()
{
    tongsoKH = 0;
    x = y = z = 0;
}

bool CongTyXYZ::docDSKhachHang(string tenFile)
{   
    //Truyển thẳng tên file dạng string
    ifstream in(tenFile);
    if (!in) return false; //Trả về false nếu không mở file được

    in >> x >> y >> z;

    for (int i = 0; i < x; i++) {
        dsKH[tongsoKH] = new loaiA();
        dsKH[tongsoKH]->docFile(in);
        tongsoKH++;
    }

    for (int i = 0; i < y; i++) {
        dsKH[tongsoKH] = new loaiB();
        dsKH[tongsoKH]->docFile(in);
        tongsoKH++;
    }

    for (int i = 0; i < z; i++) {
        dsKH[tongsoKH] = new loaiC();
        dsKH[tongsoKH]->docFile(in);
        tongsoKH++;
    }

    in.close();
    return true;
}

bool CongTyXYZ::ghikq(string tenFile)
{
    ofstream out(tenFile);
    if (!out) return false;

    out << x << " " << y << " " << z << "\n";

    double Total_Doanhthu = 0;
    out << fixed << setprecision(0);

    for (int i = 0; i < tongsoKH; i++) {
        double have_to_pay = dsKH[i]->TinhTien();
        out << dsKH[i]->GetTen() << "\n" << have_to_pay << "\n";

        Total_Doanhthu += have_to_pay;

        delete dsKH[i];
    }
    out << Total_Doanhthu;
    out.close();
    return true;
}

CongTyXYZ::~CongTyXYZ() {}