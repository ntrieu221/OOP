#include <iostream>
#include "cTamGiac.h"

using namespace std;

int main() {
    cTamGiac tg;

    //Nhập dữ liệu tam giác
    tg.Nhap();

    //Xuất tọa độ vừa nhập
    cout << "\nToa do 3 dinh vua nhap la: ";
    tg.Xuat();

    //Kiểm tra loại tam giác
    tg.KiemTra();
    cout << endl;

    //Tính chu vi và diện tích
    tg.TinhChuVi();
    cout << endl;
    tg.TinhDienTich();
    cout << endl;

    //Tịnh tiến
    cout << "\n--- Phep tinh tien ---" << endl;
    tg.TinhTien();

    //Quay
    cout << "\n--- Phep quay ---" << endl;
    tg.Quay();

    //Phóng to
    cout << "\n--- Phep phong to ---" << endl;
    tg.PhongTo();

    //Thu nhỏ
    cout << "\n--- Phep thu nho ---" << endl;
    tg.ThuNho();

    return 0;
}