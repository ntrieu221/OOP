#ifndef CNHANVIENSX_H
#define CNHANVIENSX_H
#include <string>
#include <iostream>

using namespace std;
class cNhanVienSX
{
    private:
        string MaSoNV, HoTen, NgaySinh;
        int SLSanPham;
        double DonGia;
    public:
    //Constructor
    cNhanVienSX();

    //Các hàm Set
    void SetHoTen(string ten);
    void SetMaSoNV(string maso);
    void SetNgaySinh(string dob);
    void SetSLSanPham(int soluong);
    void SetDonGia(double gia);

    //Các hàm Get
    string GetHoTen();
    string GetMaSoNV();
    string GetNgaySinh();
    int GetSLSanPham();
    double GetDonGia();

    //Các hàm chức năng 
    void Nhap();
    void Xuat();
    int GetNamSinh();
    double TinhLuong();
    
};

#endif