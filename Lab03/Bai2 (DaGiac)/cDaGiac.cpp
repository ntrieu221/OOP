#include "cDaGiac.h"
#include <iostream>
#include <cmath>
#define PI 3.14159265358979323846

using namespace std;

cDaGiac::~cDaGiac() { delete[] ds; }

void cDaGiac::Nhap() {
    cout << "Nhap so luong dinh cua da giac: ";
    cin >> n;
    //Cấp phát động một mảng mới
    ds = new Diem[n];
    for ( int i = 0; i < n; i++) {
        cout << "Nhap dinh thu " << i + 1 << " : "; 
        ds[i].Nhap();
    }
}

void cDaGiac::Xuat() {
    for ( int i = 0 ; i < n; i++) {
        ds[i].Xuat();
        cout << endl;
    }
}

void cDaGiac::TinhTien() {
    Diem vec;
    cout << "Nhap Vecto tinh tien(x , y): ";
    vec.Nhap();

    //Logic tương tự lớp Tam giác
    for (int i = 0;i < n; i++) {
        ds[i].x += vec.x;
        ds[i].y += vec.y;
    }

    cout << "Toa do cua da giac sau khi tinh tien:\n";
    Xuat();
}

void cDaGiac::Quay() {
    int a;
    cout << "Nhap he so goc quay alpha: ";
    cin >> a;
    double rad = a * PI / 180.0;

    for (int i = 0; i < n; i++) {
        //Đặt biến temp để lưu giá trị
        double tmp_x = ds[i].x;
        double tmp_y = ds[i].y;

        ds[i].x = tmp_x * cos(rad) - tmp_y * sin(rad);
        ds[i].y = tmp_x * sin(rad) + tmp_y * cos(rad);
    }

    cout << "Toa do cua da giac sau khi quay:\n ";
    Xuat();

}
void cDaGiac::PhongTo() {
    double k;
    cout << "Nhap he so phong to K: ";
    cin >> k;
    
    for (int i = 0; i < n; i++) {
        ds[i].x *= k; ds[i].y *= k;
    }

    cout << "Da giac sau khi phong to co toa do:\n ";
    Xuat();
}

void cDaGiac::ThuNho() {
    double q;
    //Chương trình chỉ chạy khi nhập một số khác 0
    do {
        cout << "Nhap he so thu nho Q (khac 0): ";
        cin >> q;
        if (q == 0) {
            cout << "He so khong hop le! Vui long` nhap lai." << endl;
        }
    } while (q == 0);
    for ( int i = 0 ; i < n ; i++) {
        ds[i].x /= q; ds[i].y /= q;
    }

    cout << "Toa do cua da giac sau khi thu nho:\n ";
    Xuat();
}