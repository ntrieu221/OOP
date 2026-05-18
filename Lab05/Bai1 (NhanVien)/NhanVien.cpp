#include "NhanVien.h"
#include <iostream>
#include <string>

using namespace std;

//Constructor
NhanVien::NhanVien()
{
    HoTen = "";
    NgaySinh = "";
    Luong = 0;
}

//Nhập vào dữ liệu
void NhanVien::Nhap()
{
    cout << "Nhap ho ten: ";
    getline(cin, HoTen);
    cout << "Nhap ngay sinh (dd/mm/yy): ";
    getline(cin, NgaySinh);
}

//Xuất dữ liệu
void NhanVien::Xuat()
{
    cout << "\nHo ten: " << HoTen << " | ";
    cout << "Ngay sinh: " << NgaySinh << " | ";
    cout << "Luong: " << (long long)Luong << " | ";
}

//Hàm get lương
double NhanVien::GetLuong() { return Luong; }

//hàm get họ tên
string NhanVien::GetHoTen() { return HoTen; }

//Hàm get ngày sinh
string NhanVien::GetNgaySinh() { return NgaySinh; }
//Hàm get năm sinh (Dùng để so sánh tuổi)
int NhanVien::GetNamSinh()
{
    //Xét chuỗi ngày sinh
    if (NgaySinh.length() >= 4)
    {
        //Lấy ra 4 số cuối trong chuỗi tương ứng với năm sinh
        string namsinh = NgaySinh.substr(NgaySinh.length() - 4);
        return stoi(namsinh); // Chuyển đổi string thành int để so sánh
    }
    return 0;
}
//Destructor
NhanVien::~NhanVien() {}