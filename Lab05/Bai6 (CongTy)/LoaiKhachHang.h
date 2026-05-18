#ifndef LOAIKHACHHANG_H
#define LOAIKHACHHANG_H
#include "KhachHang.h"
#include <fstream>
#include <string>

using namespace std;

// Khách hàng bình thường A
class loaiA : public KhachHang
{
public:
    double TinhTien() override;
};

// Khách hàng thân thiết B
class loaiB : public KhachHang
{
private:
    int SoNamThanThiet;

public:
    void docFile(ifstream &in) override;
    double TinhTien() override;
};

// Khách hàng đặc biệt C
class loaiC : public KhachHang
{
public:
    double TinhTien() override;
};

#endif