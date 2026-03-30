#include "PhanSo.h"
#include <iostream>
using namespace std;

int main() {
    //Khai báo biến
    PhanSo ps1, ps2, kq;
    
    //Lần lượt nhập các input 
    cout << "Nhap phan so 1: ";
    ps1.Nhap();
    cout << endl;
    cout << "Nhap phan so 2: ";
    ps2.Nhap();
    
    //Xuất ra giá trị của hai phân số đã nhập
    ps1.Xuat(); cout << endl;
    ps2.Xuat(); cout << endl;

    //Lần lượt gán giá trị và xuất ra các phép tính
    kq = ps1.TinhTong(ps2);
    cout << "Phep cong: "; kq.Xuat(); cout << endl;
    kq = ps1.TinhHieu(ps2);
    cout << "Phep tru: "; kq.Xuat(); cout << endl;
    kq = ps1.TinhTich(ps2);
    cout << "Phep nhan: "; kq.Xuat(); cout << endl;
    kq = ps1.TinhThuong(ps2);
    cout << "Phep chia: "; kq.Xuat(); cout << endl;
    cout << "So sanh hai phan so: ";
    ps1.SoSanh(ps2);

    return 0;
}