#ifndef LOAINHANVIEN_H
#define LOAINHANVIEN_H
#include "NhanVien.h"
#include <string>
#include <iostream>

using namespace std;

class LapTrinhVien: public NhanVien
{
    private:
        int Overtime;
    public:
    LapTrinhVien();
        void Nhap() override;
        void Xuat() override;
        int GetType() override;
        double TinhLuong() override;
        ~LapTrinhVien();
};

class KiemChungVien: public NhanVien
{
    private:
        int Error_count;
    public:
    KiemChungVien();
        void Nhap() override;
        void Xuat() override;
        int GetType() override;
        double TinhLuong() override;
        ~KiemChungVien();
};
#endif