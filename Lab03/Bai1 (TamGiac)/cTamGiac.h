#ifndef CTAMGIAC_H
#define CTAMGIAC_H
#include <iostream>
#include "Diem.h"

class cTamGiac
{
    private:
    Diem A, B, C;
    double AB, BC, CA;
    public:
    void Nhap();
    void Xuat();
    void KiemTra();
    void DoDaiCanh();
    void TinhChuVi();
    void TinhDienTich();
    void TinhTien();
    void Quay();
    void PhongTo();
    void ThuNho();
};

#endif