#include "Diem.h"
#include <iostream>
#include <cmath>
using namespace std;

void Diem::Nhap() {
    cin >> x >> y;
}

void Diem::Xuat() {
    cout << "(" << x << ", " << y << ")";
}

//Do dai` canh: sqrt((x2 - x1)^2 + (y2 - y1)^2)
double Diem::TinhDoDai(Diem diem) {
return sqrt(pow(diem.x - x, 2) + (diem.y - y, 2));
}