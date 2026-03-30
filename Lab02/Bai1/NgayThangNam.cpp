#include "NgayThangNam.h"
#include <iostream>
using namespace std;

// Tính năm nhuận
bool NgayThangNam::NamNhuan() {
    return ((iNam % 4 == 0) && (iNam % 100 != 0) || (iNam % 400 == 0));
}

// Nhập input
void NgayThangNam::Nhap() {
    do {
        cout << "Nhap ngay thang nam: ";
        cin >> iNgay >> iThang >> iNam;
        if (!KiemTraInput())
            cout << "Khong hop le! Vui long nhap lai.\n";
    } while (!KiemTraInput());
}

// Output xuất ra
void NgayThangNam::Xuat() {
    cout << iNgay << "/" << iThang << "/" << iNam;
}

// Tính số ngày trong tháng
int NgayThangNam::NgayTrongThang() {
    switch (iThang) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if (NamNhuan())
                return 29;
            else
                return 28;
    }
}

//Kiểm tra input
bool NgayThangNam::KiemTraInput() {
    //Giá trị của ngày tháng năm được nhập vào phải đúng logic
    if (iNam < 1 || iThang < 1 || iThang > 12) return false;
    if (iNgay < 1 || iNgay > NgayTrongThang()) return false;
    return true;
}
// Tìm ngày kế tiếp
void NgayThangNam::TinhNgayKeTiep() {
    // Gán Max là số ngày tối đa trong tháng
    int Max = NgayTrongThang();

    // Tăng ngày lên 1 đơn vị để xét điều kiện
    iNgay++;

    // Nếu input ngày lớn hơn ngày trong tháng
    if (iNgay > Max) {
        // Qua tháng mới
        iThang++;
        iNgay = 1;
    }

    // Nếu input tháng lớn hơn tháng 12
    if (iThang > 12) {
        // Qua năm mới
        iThang = 1;
        iNgay = 1;
        iNam++;
    }
}
