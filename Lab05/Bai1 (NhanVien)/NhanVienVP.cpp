#include "NhanVienVP.h"
#include <string>
#include <iostream>

using namespace std;

NhanVienVP::NhanVienVP() { SoNgay = 0; }
double NhanVienVP::TinhLuong()
{
    // lương = số ngày làm việc * 100.000
    Luong = SoNgay * 100000;
    return Luong;
}
// Nhập thêm dữ liệu
void NhanVienVP::Nhap()
{
    NhanVien::Nhap();
    cout << "Nhap so ngay` lam` viec: ";
    cin >> SoNgay;
    cin.ignore();
}
// Xuất dữ liệu
void NhanVienVP::Xuat()
{
    NhanVien::Xuat();
    cout << "Nhan vien Van phong`" << endl;
}

// Trả về 2 nếu là nhân viên văn phòng
int NhanVienVP::GetType() { return 2; }

NhanVienVP::~NhanVienVP() {}