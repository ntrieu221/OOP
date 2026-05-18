#ifndef NHANVIEN_H
#define NHANVIEN_H
#include <string>
#include <iostream>

using namespace std;

#pragma once

class NhanVien
{
protected:
    string maso;       // Mã số nhân viên
    string Hoten;      // Họ tên nhân iên
    int tuoi;          // Tuổi của họ
    string sdt;        // Số điện thoại
    string email;      // Email
    double luongcoban; // Lương cơ bản
public:
    // Các hàm chức năng
    NhanVien();
    virtual void Nhap();
    virtual void Xuat();
    virtual int GetType() = 0;      // Hàm xét loại nhân viên
    virtual double TinhLuong() = 0; // Tính tiền lương
    ~NhanVien();
};

#endif