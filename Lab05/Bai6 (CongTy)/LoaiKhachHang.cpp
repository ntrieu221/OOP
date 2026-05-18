#include "LoaiKhachHang.h"
#include "KhachHang.h"
#include <fstream>
#include <string>

using namespace std;

double loaiA::TinhTien()
{
    // Số lượng hàng * đơn giá hàng + Thuế VAT (10%)
    return (SoLuong * DonGia) * 1.1;
}

void loaiB::docFile(ifstream &in)
{
    KhachHang::docFile(in);
    in >> SoNamThanThiet;
}
double loaiB::TinhTien()
{
    // Phần trăm khuyến mãi = MAX (Số năm thân thiết * 5%, 50%)
    //(Số lượng hàng * đơn giá hàng) * (100% - Phần trăm khuyến mãi) + Thuế VAT (10%)
    double PhanTramKM = (SoNamThanThiet * 0.05 > 0.5) ? 0.5 : SoNamThanThiet * 0.05;
    return ((SoLuong * DonGia) * (1.0 - PhanTramKM)) * 1.1;
}

double loaiC::TinhTien()
{
    //(Số lượng hàng*đơn giá hàng)*50%+Thuế VAT (10%)
    return (((SoLuong * DonGia) * 0.5) * 1.1);
}
