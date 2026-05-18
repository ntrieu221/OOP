
#include "GiaoDich.h"
#include "CacLoaiGiaoDich.h"
#include <string>
#include <iostream>

using namespace std;

//Giao dịch Dất
GiaoDichDat::GiaoDichDat(){
    loaiDat = 'x';
}
GiaoDichDat::~GiaoDichDat(){}
void GiaoDichDat::Nhap(){
    GiaoDich::Nhap();
    cout << "Nhap loai dat(A - B - C): ";
    cin >> loaiDat;
}
void GiaoDichDat::Xuat(){
    GiaoDich::Xuat();
    cout << " | " << "Loai dat' giao dich: " << loaiDat;
}
double GiaoDichDat::TinhTien(){
    if (loaiDat == 'A')
        return DienTich * DonGia * 1.5; //Tính tiền đất loại A
    else
        return DienTich * DonGia; //Tính tiền đất loại B hoặc loại C
    return 0;
}

int GiaoDichDat::GetType() { return 1;} //Trả về 1 nếu là giao dịch Đất

//Giao dịch Nhà phố
GiaoDichNhaPho::GiaoDichNhaPho() {
    loaiNha = 0;
}
GiaoDichNhaPho::~GiaoDichNhaPho() {}
void GiaoDichNhaPho::Nhap(){
    GiaoDich::Nhap();
    //Quy định
    //Nếu nhập 1 thì là loại nhà "thường"
    //Nếu nhập 2 thì là loại nhà "cao cấp"
    cout << "Nhap loai nha`:`\n"
         << "1. Thuong`" << endl
         << "2. Cao cap'" << endl;
    cin >> loaiNha; //1 hoặc 2 
    cin.ignore();
    cout << "Nhap dia chi: ";
    getline(cin,DiaChi);
}
void GiaoDichNhaPho::Xuat(){
    GiaoDich::Xuat();
    cout << " | " << "Loai nha` giao dich: " << loaiNha;
    cout << " | " << "Dia chi nha`: " << DiaChi;
}
double GiaoDichNhaPho::TinhTien(){
    if (loaiNha == 1)
        return DienTich * DonGia * 0.9; //Nếu là nhà loại thường
    else
        return DienTich * DonGia; //nếu là nhà loại cao cấp
    return 0;
}

int GiaoDichNhaPho::GetType() { return 2;} //Trả về 2 nếu là giao dịch Nhà phố


//Giao dịch Căn hộ
GiaoDichCanHo::GiaoDichCanHo(){
    MaCan = "";
    VitriTang = 0;
}
GiaoDichCanHo::~GiaoDichCanHo(){}
void GiaoDichCanHo::Nhap(){
    GiaoDich::Nhap();
    cin.ignore();
    cout << "Nhap ma~ can ho: "; 
    getline(cin, MaCan);
    cout << "Nhap vi tri tang`: ";
    cin >> VitriTang;
}
void GiaoDichCanHo::Xuat(){
    GiaoDich::Xuat();
    cout << " | Ma~ can ho: " << MaCan;
    cout << " | Vi tri tang`: " << VitriTang;
}
double GiaoDichCanHo::TinhTien(){
    if (VitriTang == 1) //Nếu là tầng 1
        return DienTich * DonGia * 2;
    else if (VitriTang >= 15) //Nếu là tầng 15 trở lên
        return DienTich * DonGia * 1.2;
    else
        return DienTich * DonGia; //Các vị trí còn lại
    return 0;
}

int GiaoDichCanHo::GetType() { return 3;} //Trả về 3 nếu là giao dịch Căn hộ


