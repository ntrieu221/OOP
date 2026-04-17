#ifndef DIEM_H
#define DIEM_H
#pragma once
#include <iostream>

class Diem
{
    private:
    double x, y;
    public:
    friend class cTamGiac;
    void Nhap();
    void Xuat();
    double TinhDoDai(Diem diem);
};

#endif