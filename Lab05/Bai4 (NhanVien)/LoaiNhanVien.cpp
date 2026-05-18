#include "LoaiNhanVien.h"
#include "NhanVien.h"
#include <string>
#include <iostream>

using namespace std;

//Constructor
LapTrinhVien::LapTrinhVien() {
    Overtime = 0;
}

//Nhập thêm dữ liệu
void LapTrinhVien::Nhap() {
    NhanVien::Nhap();
    cout << "Nhap so gio overtime: ";
    cin >> Overtime;
}

//Xuất thêm dữ liệu
void LapTrinhVien::Xuat() {
    NhanVien::Xuat();
    cout << " | " << "So gio Overtime: " << Overtime;
}

//Trả về 1 nếu là lập trình viên
int LapTrinhVien::GetType() { return 1; }

//Tính tiền lương
double LapTrinhVien::TinhLuong() {
    //(Lương cơ bản + Số giờ Overtime) * 20000
    return (luongcoban + Overtime) * 200000;
}

//Destructor
LapTrinhVien::~LapTrinhVien() {}

//Constructor
KiemChungVien::KiemChungVien() {
    Error_count = 0;
}

//Nhập thêm dữ liệu
void KiemChungVien::Nhap() {
    NhanVien::Nhap();
    cout << "Nhap so loi phat hien: ";
    cin >> Error_count;
}

//Xuất thêm dữ liệu
void KiemChungVien::Xuat() {
    NhanVien::Xuat();
    cout << " | So loi phat hien: " << Error_count;
}


//Trả về 2 nếu là Kiểm chứng viên
int KiemChungVien::GetType() { return 2; }

//Tính tiền lương
double KiemChungVien::TinhLuong() { 
    //Lương cơ bản + (số lỗi đếm được * 50000)
    return luongcoban + (Error_count * 50000);
}

//Destructor
KiemChungVien::~KiemChungVien() {}