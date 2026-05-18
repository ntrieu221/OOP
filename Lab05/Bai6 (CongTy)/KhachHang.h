#ifndef KHACHHANG_H
#define KHACHHANG_H
#include <string>
#include <fstream>

using namespace std;
class KhachHang
{
protected:
    string Hoten;
    int SoLuong;
    double DonGia;
public:
    KhachHang();
    virtual void docFile(ifstream &in);
    virtual double TinhTien() = 0;
    virtual ~KhachHang();
    string GetTen();
};

#endif