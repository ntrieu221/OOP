#include "GioPhutGiay.h"
#include <iostream>
#include <iomanip>

using namespace std;

//Kiểm tra tính hợp lệ của input
bool GioPhutGiay::KiemTraInput() {
    if (iGio < 0 || iPhut < 0 || iGiay < 0 || iPhut >= 60 || iGiay >= 60 || iGio >= 24) return false;
    return true;
}

//Hàm nhập Input
void GioPhutGiay::Nhap() {
    //Dùng vòng lặp do-while để kiểm tra Input
    do {
        cout << "Nhap gio phut giay:"; 
        cin >> iGio >> iPhut >> iGiay;
        if (!KiemTraInput()) 
            cout << "Khong hop le! Vui long nhap lai.\n";
    } while (!KiemTraInput());
}

//Hàm xuất Output
void GioPhutGiay::Xuat() {
    //Để xuất output ra định dạng 00
    cout << setfill('0'); 
    cout << setw(2) << iGio << ":" 
         << setw(2) << iPhut << ":" 
         << setw(2) << iGiay << endl;
}

//Hàm tính cộng thêm một giây
void GioPhutGiay::TinhCongThemMotGiay() {
    iGiay++;
    //Nếu giây bị tràn
    if (iGiay >= 60) {
        //Phút tăng lên 1, giây là 00
        iGiay = 0;
        iPhut++;
        // Nếu phút bị tràn
        if (iPhut >= 60) {
        //Giờ tăng lên 1, phút là 00
            iPhut = 0;
            iGio++;
        //Nếu giờ bị tràn
            if (iGio >= 24) {
            //Giờ là 00 (Qua ngày mới)
                iGio = 0;
            }
        }
    }
}