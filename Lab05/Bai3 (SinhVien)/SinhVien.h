#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <string>
#include <iostream>

using namespace std;

class SinhVien
{
    protected:
        string mssv; //Mã số sinh viên
        string hoten; //Họ và tên
        string diachi; //Địa chỉ
        int tc; //Số tín chỉ
        double dtb; //Điểm trung bình
    
    //Các hàm chức năng
    public:
    SinhVien();
    virtual void Nhap();
    virtual void Xuat();
    virtual ~SinhVien();
    virtual int GetType() = 0; //Hàm thuần ảo Get loại sinh viên
    int getTC(); //Get tín chỉ
    double getDTN(); //Get điểm tốt nghiệp
    double getDTB(); //Get điểm trung bình
    virtual bool XetTotNghiep() = 0; //Xét điều kiện tốt nghiệp
};

#endif