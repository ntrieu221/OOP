#ifndef NHANVIENVP_H
#define NHANVIENVP_H
#include "NhanVien.h"
#include <string>
#include <iostream>

using namespace std;

class NhanVienVP : public NhanVien
{
private:
    long SoNgay;

public:
    NhanVienVP();
    double TinhLuong() override;
    void Nhap() override;
    void Xuat() override;
    int GetType() override;
    ~NhanVienVP();
};

#endif