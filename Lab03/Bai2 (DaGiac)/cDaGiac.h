#ifndef CDAGIAC_H
#define CDAGIAC_H
#include "Diem.h"

class cDaGiac
{
    private:
    int n;
    Diem *ds;
    public:
    ~cDaGiac();

    void Nhap();
    void Xuat();
    void TinhTien();
    void Quay();
    void PhongTo();
    void ThuNho();
};

#endif