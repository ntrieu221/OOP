#include "cTamGiac.h"
#include "Diem.h"
#include <iostream>
#include <cmath>
#define PI 3.14159265358979323846

using namespace std;

//Nhập vào giá trị các đỉnh (x, y)
void cTamGiac::Nhap() {
    cout << "Nhap dinh A: "; A.Nhap();
    cout << "Nhap dinh B: "; B.Nhap();
    cout << "Nhap dinh C: "; C.Nhap();
}

//Xuất ra màn hình các cặp x y
void cTamGiac::Xuat() {
    A.Xuat(); cout << " ";
    B.Xuat(); cout << " ";
    C.Xuat(); cout << " ";
    cout << endl;
}

//Gán giá trị độ dài cho các cạnh của tam giác
void cTamGiac::DoDaiCanh() {
AB = A.TinhDoDai(B);
BC = B.TinhDoDai(C);
CA = C.TinhDoDai(A);

}

void cTamGiac::KiemTra() {
DoDaiCanh();
    //Kiểm tra các loại tam giác
    if  (AB + BC > CA && AB + CA > BC && BC + CA > AB) {
        double a = AB*AB;
        double b = BC*BC;
        double c = CA*CA;

        //Các tính chất của các loại tam giác
        bool Vuong = (a + b == c || a + c == b || b + c == a);
        bool Can = (AB == BC || BC || CA || CA == AB);
        bool Deu = (AB == BC && BC == CA);

        //Xét điều kiện để hiển thị ra màn hình loại tam giác.
        if (Deu) cout << "Tam giac vua` nhap la` tam giac deu`.";
        else if (Vuong && Can) cout << "Tam giac vua` nhap la` tam giac vuong can.";
        else if (Vuong) cout << "Tam giac vua` nhap la` tam giac vuong.";
        else if (Can) cout << "Tam giac vua` nhap la` tam giac can.";
        else cout << "Tam giac vua` nhap la` tam giac thuong`.";
    }
else cout << "Khong phai tam giac.";
}
void cTamGiac::TinhChuVi() {
DoDaiCanh();
    double cv;
    //Công thức tính chu vi tam giác
    cv = AB + BC + CA;
    cout << "Chu vi tam giac la`: " << cv;
}

void cTamGiac::TinhDienTich() {
    DoDaiCanh();
    double cv, p, S;
    //Dùng hê-rông để tính diện tích khi biết nửa chu vi
    cv = AB + BC + CA;
    p = cv / 2;
    S = sqrt(p * (p - AB) * (p - BC) * (p - CA));
    cout << "Dien tich tam giac la`: " << S;
}

void cTamGiac::TinhTien() {
    DoDaiCanh();    
    Diem vec;
    cout << "nhap Vecto tinh tien(x, y): ";
    vec.Nhap();

    A.x += vec.x; A.y += vec.y;
    B.x += vec.x; B.y += vec.y;
    C.x += vec.x; C.y += vec.y;

    cout << "Tam giac sau khi tinh tien co toa do:\n";
    A.Xuat(); cout << " "; 
    B.Xuat(); cout << " "; 
    C.Xuat(); cout << " "; 
}

void cTamGiac::Quay() {
    DoDaiCanh();
    int a;
    cout << "Nhap he so goc quay alpha: ";
    cin >> a;
    double rad = a * PI / 180.0;
    
    //Công thức quay
    double xA = A.x * cos(rad) - A.y * sin(rad);
    double yA = A.x * sin(rad) + A.y * cos(rad);
    A.x = xA;
    A.y = yA;

    double xB = B.x * cos(rad) - B.y * sin(rad);
    double yB = B.x * sin(rad) + B.y * cos(rad);
    B.x = xB;
    B.y = yB;
    
    double xC = C.x * cos(rad) - C.y * sin(rad);
    double yC = C.x * sin(rad) + C.y * cos(rad);
    C.x = xC;
    C.y = yC;
    
    cout << "Toa do cua tam giac sau khi quay:\n ";
    Xuat();
}

void cTamGiac::PhongTo() {
    DoDaiCanh();
    double k;
    cout << "Nhap he so phong to K: ";
    cin >> k;

    //Nhân các tọa độ với hệ số
    A.x *= k; A.y *= k;
    B.x *= k; B.y *= k;
    C.x *= k; C.y *= k;

    cout << "Tam giac sau khi phong to co toa do:\n";
    A.Xuat(); cout << " "; 
    B.Xuat(); cout << " "; 
    C.Xuat(); cout << " "; 
}
void cTamGiac::ThuNho() {
    DoDaiCanh();
    double q;
    //Chương trình sẽ không chạy nếu như input là 0
    do {
        cout << "Nhap he so thu nho Q (khac 0): ";
        cin >> q;
        if (q == 0) {
            cout << "He so khong hop le! Vui long` nhap lai." << endl;
        }
    } while (q == 0);

    //Chia các tọa độ cho hệ số
    A.x /= q; A.y /= q;
    B.x /= q; B.y /= q;
    C.x /= q; C.y /= q;

    cout << "Tam giac sau khi thu nho co toa do:\n";
    A.Xuat(); cout << " "; 
    B.Xuat(); cout << " "; 
    C.Xuat(); cout << " "; 
}