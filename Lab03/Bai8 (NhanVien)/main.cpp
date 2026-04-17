#include <iostream>
#include <cmath>
#include "cNhanVienSX.h"

using namespace std;

int main() {
    int n;
    cout << "Nhap so luong nhan vien trong cong ty: ";
    cin >> n;
    cin.ignore();

    cNhanVienSX* ds = new cNhanVienSX[n];

    //Nhập thông tin của các nhân viên trong công ty
    for ( int i = 0; i < n ; i++) {
        cout << "\nNhap thong tin cua nhan vien thu " << i + 1 << " : ";
        ds[i].Nhap();
    }

    //Xuất danh sách nhân viên
    cout << "=======DANH SACH CAC NHAN VIEN TRONG CONG TY=======" << endl;
    for ( int i = 0; i < n; i++) {
        ds[i].Xuat();
    } 
    
    //Tính nhân viên có lương thấp nhất
   if (n > 0) {
        cNhanVienSX NVLuongMin = ds[0];
        for ( int i = 0 ; i < n; i++) {
            if (ds[i].TinhLuong() < NVLuongMin.TinhLuong()) {
                NVLuongMin = ds[i];
            }
        }
        cout << "\nNhan vien co luong thap nhat la`: " << NVLuongMin.GetHoTen() << endl;
    }

    //Tính tổng lương phải trả cho các nhân viên sản xuất
    double sum = 0;
    for ( int i = 0; i < n; i++) {
        sum += ds[i].TinhLuong();
    }

    cout << "Tong so tien phai tra cho cac nhan vien trong cong ty: " << (size_t)sum << "VND" << endl;

    //Tìm nhân viên có tuổi cao nhất
    if (n > 0) {
        //Giả sử người đầu tiên là người già nhất
        cNhanVienSX TheOldest = ds[0];
        for ( int i = 0; i < n; i++) {
            //Nếu tìm được người già hơn thì thay thế giá trị
            if (ds[i].GetNamSinh() < TheOldest.GetNamSinh()) {
                TheOldest = ds[i];
            }
        }
        cout << "Nhan vien co tuoi lon nhat trong cong ty la`: " << TheOldest.GetHoTen() << endl;
    }

    //Sắp xếp danh sách nhân viên tăng dần theo lương
    for ( int i = 0; i < n - 1; i++) {
        for ( int j = 0; j < n - 1 - i; j++) {
            if (ds[j].TinhLuong() > ds[j + 1].TinhLuong()) {
                cNhanVienSX temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
    cout << "\n=======DANH SACH NHAN VIEN SAP XEP THEO LUONG TANG DAN`======= " << endl;
    for ( int i = 0; i < n; i++) {
        ds[i].Xuat();
    }
    
    delete[] ds;
    return 0;
}