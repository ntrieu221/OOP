#include "GiaoDich.h"
#include <string>
#include <iostream>

using namespace std;

GiaoDich::GiaoDich(){
    MaGD = " ";
    NgayGD = " ";
    DonGia = 0;
    DienTich = 0;
}

GiaoDich::~GiaoDich(){}

void GiaoDich::Nhap(){
    cout << "Nhap ma giao dich: "; getline(cin, MaGD);
    cout << "Nhap ngay` giao dich (dd/mm/yyyy): "; getline(cin, NgayGD);
    cout << "Nhap don gia': "; cin >> DonGia;
    cout << "Nhap dien tich': "; cin >> DienTich;
}
void GiaoDich::Xuat(){
    cout << "Ma GD: " << MaGD << " | Ngay: " << NgayGD 
         << " | Don gia: " << (long long) DonGia;
}

//Lấy ngày tháng năm giao dịch
string GiaoDich::GetNgayThangNam() { return NgayGD; }
//Lấy tháng và năm của giao dịch
string GiaoDich::GetThangNam() {
    return NgayGD.substr(3);
}