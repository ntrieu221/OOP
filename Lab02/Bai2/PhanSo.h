#ifndef PHANSO_H
#define PHANSO_H

//Khai báo class
class PhanSo
{
    private:
    int iTu, iMau;

    public:

    void Nhap();
    void Xuat();
    void RutGon(); 

    //Các phép tính
    PhanSo TinhTong(PhanSo &ps);
    PhanSo TinhHieu(PhanSo &ps);
    PhanSo TinhTich(PhanSo &ps);
    PhanSo TinhThuong(PhanSo &ps);
    
    //Hàm để hỗ trợ tính toán
    void SoSanh(PhanSo &ps);
    int UCLN(int a,int b);
};

#endif