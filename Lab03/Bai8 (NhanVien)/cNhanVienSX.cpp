#include "cNhanVienSX.h"
#include <iostream>
#include <string>

using namespace std;

    cNhanVienSX::cNhanVienSX() {
    MaSoNV = ""; HoTen = ""; NgaySinh = "";
    SLSanPham = 0; DonGia = 0;
    }

    //Các hàm Set
    void cNhanVienSX::SetHoTen(string ten) { HoTen = ten; }
    void cNhanVienSX::SetMaSoNV(string maso) { MaSoNV = maso; }
    void cNhanVienSX::SetNgaySinh(string dob) { NgaySinh = dob; }
    void cNhanVienSX::SetSLSanPham(int soluong) { SLSanPham = (soluong > 0) ? soluong : 0; }
    void cNhanVienSX::SetDonGia(double gia) { DonGia = (gia > 0) ? gia : 0; }

    //Các hàm Get
    string cNhanVienSX::GetHoTen() { return HoTen; }
    string cNhanVienSX::GetMaSoNV() { return MaSoNV; }
    string cNhanVienSX::GetNgaySinh() { return NgaySinh; }
    int cNhanVienSX::GetSLSanPham() { return SLSanPham; }
    double cNhanVienSX::GetDonGia() { return DonGia; }

    //Các hàm chức năng khác
    void cNhanVienSX::Nhap() {
        cout << "\nNhap ho ten cua nhan vien: "; getline(cin, HoTen);
        cout << "Nhap ma so cua nhan vien: "; getline(cin, MaSoNV);
        cout << "Nhap ngay sinh cua nhan vien (dd/mm/yyyy): "; getline(cin,NgaySinh);
        cout << "Nhap so luong san pham: "; cin >> SLSanPham;
        cout << "Nhap don gia (VND): "; cin >> DonGia;
        cin.ignore();
    }
    void cNhanVienSX::Xuat() {
    cout << "MSNV: " << MaSoNV << " | Ten: " << HoTen << " | Ngay sinh: " << NgaySinh << " | Luong: " << (size_t)TinhLuong() << "VND" << endl;
    }
    double cNhanVienSX::TinhLuong() {
        return SLSanPham * DonGia;
    }
    int cNhanVienSX::GetNamSinh() {
        int ns;
        if (NgaySinh.length() >= 4) {
            string namsinh = NgaySinh.substr(NgaySinh.length() - 4);
            ns =stoi(namsinh);
        }
        return ns;
    }


 