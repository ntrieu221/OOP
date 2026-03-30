#include "SoPhuc.h"
#include <iostream>
using namespace std;

int main() {
    //Khai báo giá trị
    SoPhuc sp1, sp2, kq;
    cout << "Nhap so phuc 1:\n";
    sp1.Nhap();
    cout << "Nhap so phuc 2:\n";
    sp2.Nhap();
    cout << "Hai so phuc vua nhap la`: " << endl;
    sp1.Xuat();
    cout << endl;
    sp2.Xuat();
    
    //Các phép tính toán
    kq = sp1.TinhTong(sp2);
    cout << endl << "Phep cong: "; kq.Xuat();
    kq = sp1.TinhHieu(sp2);
    cout << endl << "Phep tru: "; kq.Xuat();
    kq = sp1.TinhTich(sp2);
    cout << endl << "Phep nhan: "; kq.Xuat();
    kq = sp1.TinhThuong(sp2); 
    cout << endl << "Phep chia: "; kq.Xuat();

    return 0;
}