#ifndef NHANVIENSX_H
#define NHANVIENSX_H
#include "NhanVien.h"
#include <string>
#include <iostream>

using namespace std;

class NhanVienSX : public NhanVien
{
private:
    double LuongCanban;
    double SoLuongSP;

public:
    NhanVienSX();
    double TinhLuong() override;
    void Nhap() override;
    void Xuat() override;
    int GetType() override;
    ~NhanVienSX();
};

#endif