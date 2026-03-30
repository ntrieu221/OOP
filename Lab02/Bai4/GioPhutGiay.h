#ifndef GIOPHUTGIAY_H
#define GIOPHUTGIAY_H

//Tạo class
class GioPhutGiay
{
private:
    int iGio, iPhut, iGiay;
public:
    void Nhap();
    void Xuat();
    void TinhCongThemMotGiay();
    //Hàm hỗ trợ
    bool KiemTraInput();
};

#endif