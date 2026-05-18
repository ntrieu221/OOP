#include "NhanVien.h"
#include "NhanVienSX.h"
#include "NhanVienVP.h"
#include <string>
#include <iostream>

using namespace std;

// Hàm để thực hiện tính toán trong main
// Tìm nhân viên sản xuất lương thấp nhất
void MinLuongSX(NhanVien *ds[], int n)
{
    // Khởi tạo con trỏ ban đầu bằng 0
    NhanVien *minSX = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds[i]->GetType() == 1) // Chỉ xét nhân viên sản xuất
        {
            // Nếu như không tìm thấy hoặc tìm thấy một giá trị thỏa điều kiện
            if (minSX == 0 || ds[i]->GetLuong() < minSX->GetLuong())
                minSX = ds[i]; // Gán giá trị
        }
    }
    if (minSX != 0) // Nếu khác 0 (Tìm thấy)
    {
        cout << "\nNhan vien san xuat co' luong thap' nhat' la`: ";
        cout << minSX->GetHoTen();
    }
    else
        cout << "\nKhong co nhan vien san xuat' trong danh sach'.";
}

// Tìm nhân viên văn phòng lớn tuổi nhất
void MaxTuoiVP(NhanVien *ds[], int n)
{
    NhanVien *maxVP = 0; // Cách thức thực hiện tương tự như MinLuongSX
    for (int i = 0; i < n; i++)
    {
        if (ds[i]->GetType() == 2)
        {
            if (maxVP == 0 || ds[i]->GetNamSinh() < maxVP->GetNamSinh())
                maxVP = ds[i];
        }
    }

    if (maxVP != 0)
    {
        cout << "\nNhan vien van phong` co' tuoi cao nhat' la`: ";
        cout << maxVP->GetHoTen();
    }
    else
        cout << "\nKhong co nhan vien van phong` trong danh sach'.";
}

int main()
{
    int n; // Biến đại diện cho số lượng nhân viên trong công ty
    cout << "Nhap so luong nhan vien trong cong ty: ";
    cin >> n;
    cin.ignore();
    NhanVien *ds[100]; // Mảng tĩnh chứa con trỏ để quản lí các đối tượng nhân viên

    for (int i = 0; i < n; i++)
    {
        int type;
        cout << "\n1. San xuat" << "\n2. Van phong`" << "\nLoai nhan vien: ";
        cin >> type; // Nhập vào loại nhân viên
        cin.ignore();
        if (type == 1)
            ds[i] = new NhanVienSX();
        else
            ds[i] = new NhanVienVP();

        ds[i]->Nhap();
        ds[i]->TinhLuong();
    }

    // Xuất ra danh sách các nhân viên
    cout << "\n-----DANH SACH NHAN VIEN-----";
    for (int i = 0; i < n; i++)
    {
        ds[i]->Xuat();
    }

    // Tính tổng số tiền mà công ty phải trả
    cout << "\n-----CAC THONG TIN KHAC-----";
    long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += ds[i]->GetLuong();
    }
    cout << "\nTong so luong ma` cong ty phai tra la`: " << sum;
    // Các hàm chức năng
    MinLuongSX(ds, n);
    MaxTuoiVP(ds, n);
}
