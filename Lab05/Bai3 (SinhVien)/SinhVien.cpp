#include "SinhVien.h"
#include <iostream>
#include <string>

using namespace std;

//Constructor
SinhVien::SinhVien() {
    mssv = ""; hoten = ""; diachi = "";
    tc = 0; dtb = 0;
}

void SinhVien::Nhap() {
    cout << "Nhap ho va ten: "; getline (cin, hoten);
    cout << "Nhap ma so sinh vien: "; getline(cin, mssv);
    cout << "Nhap dia chi: "; getline(cin, diachi);
    cout << "Nhap so tin chi: "; cin >> tc;
    cout << "Nhap diem trung binh: "; cin >> dtb;
}

void SinhVien::Xuat() {
    cout << "Ten: " << hoten << " | "
         << "MSSV: " << mssv << " | "
         << " D/c: " << diachi << " | "
         << "Tong so tin chi: " << tc << " | "
         << "DTB: " << dtb << endl;
}

//Destructor
SinhVien::~SinhVien() {}

int SinhVien::getTC() { return tc; } //Trả về số tín chỉ
double SinhVien::getDTB() { return dtb; } //Trả về điểm trung bình

