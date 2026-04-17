#include "cDaThuc.h"
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cDaThuc a, b, tong, hieu;
    cout << "\nNhap da thuc A: ";
    a.Nhap();
    cout << "\nNhap da thuc B: ";
    b.Nhap();
    cout << "\n=====DA THUC VUA NHAP=====" << endl;
    cout << "Da thuc A: "; a.Xuat(); 
    cout << "Da thuc B: "; b.Xuat();
    cout << "=====TINH GIA TRI KHI BIET X=====\n";
    cout << "Da thuc A:\n";
    a.TinhDaThuc();
    cout << "\nDa thuc B:\n";
    b.TinhDaThuc();
    cout << "\n=====CONG HAI DA THUC=====\n";
    tong = a.CongHaiDaThuc(b);
    cout << "A + B = ";
    tong.Xuat();
    cout << "\n=====TRU HAI DA THUC=====\n";
    hieu = a.TruHaiDaThuc(b);
    cout << "A - B = ";
    hieu.Xuat();

    return 0;
}