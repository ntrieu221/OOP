#include "PhanSo.h"
#include <iostream>
#include <cmath>
using namespace std;
//Hàm nhập input
void PhanSo::Nhap() {
    cout << "Nhap Tu: ";
    cin >> iTu;
    //Mẫu phải khác 0
    cout << "Nhap mau(khac 0): ";
    do {
        cin >> iMau;
        if (iMau == 0) cout << "Gia tri khong hop le! Nhap lai: ";
    }
    //Nếu như mẫu bằng 0 thì chạy ngược lên thực hiện "do"
    while (iMau == 0);
}

//Hàm xuất output
void PhanSo::Xuat() {
    //Nếu mẫu bằng 1 thì chỉ in ra tử 
    if ( iMau == 1) cout << iTu;
    //Còn không thì in cả tử và mẫu
    else cout << iTu << "/" << iMau;
}

//Tìm ước chung lớn nhất của mẫu
int PhanSo::UCLN(int a, int b) {
    //Lấy giá trị dương
    a = abs(a);
    b  = abs(b);
    
    //Thuật toán tìm UCLN
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    //Trả về UCLN
    return a;
}

//Rút gọn phân số
void PhanSo::RutGon() {
    int ucln = UCLN(iTu, iMau);
    iTu /= ucln;
    iMau /= ucln;
//Nếu như mẫu âm thì đưa dấu trừ lên tử
    if (iMau < 0) {
    iTu*=-1;
    iMau*=-1;
    }
}
// a/b + c/d = a*d + c*b/ b*d; 
PhanSo PhanSo::TinhTong(PhanSo &ps) {
    PhanSo kq;
    kq.iTu = iTu * ps.iMau + ps.iTu * iMau;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}

// a/b + c/d = a*d - c*b/ b*d; 
PhanSo PhanSo::TinhHieu(PhanSo &ps) {
    PhanSo kq;
    kq.iTu = iTu * ps.iMau - ps.iTu * iMau;
    kq.iMau = iMau * ps.iMau;
     kq.RutGon();
    return kq;
}
// a/b * c/d = a*c/b*d;
PhanSo PhanSo::TinhTich(PhanSo &ps) {
    PhanSo kq;
    kq.iTu = iTu * ps.iTu;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}

// a/b : c/d = a/b*d/c = a*d/b*c;
PhanSo PhanSo::TinhThuong(PhanSo &ps) {
    PhanSo kq;
    kq.iTu = iTu * ps.iMau;
    kq.iMau = iMau * ps.iTu;
    kq.RutGon();
    return kq;
}

//So sánh hai phân số 
void PhanSo::SoSanh(PhanSo &ps) {
    
    int tich1 = iTu * ps.iMau;
    int tich2 = iMau * ps.iTu;

    if ( tich1 > tich2) cout << "Phan so 1 > Phan so 2.";
    else if ( tich1 < tich2) cout << "Phan so 1 < Phan so 2.";
    else cout << "Hai phan so bang nhau.";
}