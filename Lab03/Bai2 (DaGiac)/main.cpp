#include <iostream>
#include <cmath>
#include "Diem.h"
#include "cDaGiac.h"

using namespace std;

int main() {
    cDaGiac dg;
    dg.Nhap();

    cout << "Toa do cua cac dinh vua` nhap la`: " << endl;
    dg.Xuat();

    cout << "\n--- Phep tinh tien ---" << endl;
    dg.TinhTien();

    //Quay
    cout << "\n--- Phep quay ---" << endl;
    dg.Quay();

    //Phóng to
    cout << "\n--- Phep phong to ---" << endl;
    dg.PhongTo();

    //Thu nhỏ
    cout << "\n--- Phep thu nho ---" << endl;
    dg.ThuNho();

}