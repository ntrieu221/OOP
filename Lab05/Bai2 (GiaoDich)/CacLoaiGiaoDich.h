#ifndef CACLOAIGIAODICH_H
#define CACLOAIGIAODICH_H
#include "GiaoDich.h"
#include <string>
#include <iostream>

using namespace std;

class GiaoDichDat : public GiaoDich
{
private:
    char loaiDat; // loại A, B hoặc C
public:
    GiaoDichDat();
    ~GiaoDichDat();
    void Nhap() override;
    void Xuat() override;
    double TinhTien() override;
    int GetType() override;
};

class GiaoDichNhaPho : public GiaoDich
{
private:
    int loaiNha;   // Cao cấp hoặc thường
    string DiaChi; // Địa chỉ nhà
public:
    GiaoDichNhaPho();
    ~GiaoDichNhaPho();
    void Nhap() override;
    void Xuat() override;
    double TinhTien() override;
    int GetType() override;
};

class GiaoDichCanHo : public GiaoDich
{
private:
    string MaCan;  // mã căn hộ
    int VitriTang; // Vị trí tầng
public:
    GiaoDichCanHo();
    ~GiaoDichCanHo();
    void Nhap() override;
    void Xuat() override;
    double TinhTien() override;
    int GetType() override;
};

#endif