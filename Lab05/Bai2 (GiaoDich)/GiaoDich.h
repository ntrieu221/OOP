#ifndef GIAODICH_H
#define GIAODICH_H
#include <string>
#include <iostream>

using namespace std;

class GiaoDich
{
protected:
    string MaGD;
    string NgayGD;
    double DonGia;
    double DienTich;

public:
    GiaoDich();
    virtual ~GiaoDich();
    virtual double TinhTien() = 0;
    virtual void Nhap();
    virtual void Xuat();
    virtual int GetType() = 0;
    
    string GetNgayThangNam();
    string GetThangNam();

};

#endif