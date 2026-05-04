#include "PhanSo.h"
#include <iostream>
#include <cmath>

using namespace std;

//Constructor
PhanSo::PhanSo(int t, int m) {
    tu = t;
    mau = m;
    RutGon();
}

//Hàm tìm ước chung lớn nhất
int PhanSo::UCLN(int a, int b) {
    //Thuật toán Euclid
    a = abs(a); b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

//Hàm rút gọn phân số
void PhanSo::RutGon() {
    int uc = UCLN(tu, mau);
    tu /= uc;
    mau /= uc;

    //Nếu mẫu âm thì phải đưa dấu trừ lên tử để mẫu luôn dương
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
}

//Operator nhập giá trị
istream& operator>>(istream& in, PhanSo& ps) {
    cout << "Nhap tu: "; in >> ps.tu;
    //Thực hiện nhập mẫu số bắt buộc phải khác 0
    do {
        cout << "Nhap mau(phai khac 0): "; 
        in >> ps.mau;
    } while (ps.mau == 0);
    ps.RutGon();
    return in;
}

//Operator xuất giá trị
ostream& operator<<(ostream& out, const PhanSo& ps) {
    //Xử lí dấu
    //In phần tử số
    //nếu tử bằng 0 thì in phân số ra 0 luôn
    if (ps.tu == 0)
        out << "0";
    //Nếu mẫu số bằng 0 thì chỉ in tử số
    else if (ps.mau == 1) 
            out << ps.tu;
     //In phần mẫu số
     //nếu như mẫu bé hơn 0
    else if (ps.mau < 0) {
        //Đưa dấu trừ lên tử
        out << -ps.tu << "/" << -ps.mau;
    } else 
        //Còn không thì in ra như bình thường
        out << ps.tu << "/" << ps.mau;
    return out;
}

//Các phép tính
//a/b + c/d = a*d + b*c / b*d
PhanSo PhanSo::operator+(PhanSo khac) {
    PhanSo kq;
    kq.tu = (tu * khac.mau) + (mau * khac.tu);
    kq.mau = mau * khac.mau;
    kq.RutGon();
    return kq;
}

//a/b + c/d = a*d - b*c / b*d
PhanSo PhanSo::operator-(PhanSo khac){
    PhanSo kq;
    kq.tu = (tu * khac.mau) - (mau * khac.tu);
    kq.mau = mau * khac.mau;
    kq.RutGon();
    return kq;
}

//a/b * c/d = a*c/b*d
PhanSo PhanSo::operator*(PhanSo khac){
    PhanSo kq;
    kq.tu = tu * khac.tu;
    kq.mau = mau * khac.mau;
    kq.RutGon();
    return kq;
}

//a/b : c/d = a/b * d/c = a*d/b*c
PhanSo PhanSo::operator/(PhanSo khac){
    PhanSo kq;
    kq.tu = tu * khac.mau;
    kq.mau = mau * khac.tu;
    kq.RutGon();
    return kq;
}

//So sánh hai phân số
bool PhanSo::operator==(PhanSo khac){
    return (tu == khac.tu && mau == khac.mau);
}

bool PhanSo::operator>(PhanSo khac){
    //Đổi phân số ra số thập phân để so sánh
    double Phanso1 = tu / mau;
    double Phanso2 = khac.tu / khac.mau;

    if ( Phanso1 > Phanso2) return true;
    return false;
}

//Destructor
PhanSo::~PhanSo() {}