#include "cDate.h"
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cDate ngayGui, ngayRut;
    double tienGoc, LaiSuatNam;

    cout << "-----TINH LAI SUAT-----\n";
    cout << "Nhap vao` ngay` gui tien`:\n";
    cin >> ngayGui;
    cout << "Nhap vao` ngay` rut tien`:\n";
    cin >> ngayRut;

    cout << "Nhap so tien` ban dau` gui(VND):\n";
    cin >> tienGoc;
    cout << "Nhap lai suat theo nam:\n";
    cin >> LaiSuatNam;

    long SoNgayGuiTien = ngayRut - ngayGui;
    if (SoNgayGuiTien < 0) cout << "Khong the thuc hien!";
    else {
        double LaiSuatNgay = LaiSuatNam / 365;
        double tienLai = tienGoc * LaiSuatNgay * SoNgayGuiTien;

        cout << "-----KET QUA GUI TIEN-----\n";
        cout << "Gui tien tu` ngay` " << ngayGui << " den' ngay` "  
             << ngayRut << ".\n";
        cout << "=> Tong so' ngay` da~ gui: " << SoNgayGuiTien << " ngay.\n";
        cout << "Tong so tien` lai~: " << (long long)tienLai << "VND" << endl;
        cout << "Tong so tien` nhan duoc: " << (long long)(tienGoc + tienLai) << "VND";
    }

    return 0;
}