#include "NhanVien.h"
#include <string>
#include <iostream>

using namespace std;

//Constructor
NhanVien::NhanVien()
{
    maso = "";
    Hoten = "";
    tuoi = 0;
    sdt = "";
    email = "";
    luongcoban = 0;
}

void NhanVien::Nhap()
{
    cout << "Nhap ma so nhan vien: ";
    getline(cin, maso);
    cout << "Nhap ho va ten: ";
    getline(cin, Hoten);
    cout << "Nhap tuoi: ";
    cin >> tuoi;
    cin.ignore();
    cout << "Nhap email: ";
    getline(cin, email);
    cout << "Nhap so dien thoai: ";
    getline(cin, sdt);
    cout << "Nhap luong co ban: ";
    cin >> luongcoban;
}
void NhanVien::Xuat()
{
    cout << "Ma so: " << maso << " | "
         << "Ten:  " << Hoten << " | "
         << "Tuoi: " << tuoi << " | "
         << "SDT: " << sdt << " | "
         << "Email: " << email << " | "
         << "Luong: " << (long long) TinhLuong();
}

//Destructor
NhanVien::~NhanVien() {}