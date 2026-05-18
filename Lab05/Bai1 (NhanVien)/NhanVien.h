#ifndef NHANVIEN_H
#define NHANVIEN_H
#include <string>
#include <iostream>

using namespace std;

class NhanVien
{
protected:
    string HoTen;
    string NgaySinh;
    double Luong;

public:
    NhanVien();
    virtual void Nhap();
    virtual void Xuat();
    virtual double TinhLuong() = 0;
    virtual int GetType() = 0; // Lấy loại nhân viên
    double GetLuong();
    string GetHoTen();
    string GetNgaySinh();
    int GetNamSinh();
    virtual ~NhanVien();
};
#endif