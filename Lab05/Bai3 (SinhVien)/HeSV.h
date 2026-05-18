#ifndef HESV_H
#define HESV_H
#include "SinhVien.h"
#include <string>
#include <iostream>

#pragma once

using namespace std;

class SVDaiHoc: public SinhVien 
{
    private:
        string tenLV; //Tên luận văn
        double diemLV; //Điểm luận văn 
    public:
        SVDaiHoc();
         ~SVDaiHoc();
        void Nhap() override;
        void Xuat() override;
        int GetType() override;
        bool XetTotNghiep() override; 
};

class SVCaoDang: public SinhVien
{
    private:
        double diemthitotnghiep;
    public:
        SVCaoDang();
        ~SVCaoDang();
        void Nhap() override;
        void Xuat() override;
        int GetType() override;
        double getDTN();
        bool XetTotNghiep() override; 
};

#endif