#include "NhanVienSX.h"
#include "NhanVien.h"
#include <iostream>
#include <string>

using namespace std;

NhanVienSX::NhanVienSX()
{
    LuongCanban = 0;
    SoLuongSP = 0;
}

double NhanVienSX::TinhLuong()
{
    Luong = LuongCanban + SoLuongSP * 5000;
    return Luong;
}

void NhanVienSX::Nhap()
{
    NhanVien::Nhap();
    cout << "Nhap luong can ban: ";
    cin >> LuongCanban;
    cout << "Nhap so luong san pham: ";
    cin >> SoLuongSP;
    cin.ignore();
}

void NhanVienSX::Xuat()
{
    NhanVien::Xuat();
    cout << "Nhan vien San xuat" << endl;
}

int NhanVienSX::GetType() { return 1; }

NhanVienSX::~NhanVienSX() {}