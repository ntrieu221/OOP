#include "NhanVien.h"
#include "LoaiNhanVien.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    NhanVien *nv[100]; // mảng tĩnh quản lí danh sách nhân viên
    int loaiNV, n;
    // Nhập vào số lượng nhân viên
    cout << "Nhap vao so luong nhan vien: ";
    cin >> n;
    cin.ignore();
    // Nhập vào danh sách các nhân viên
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap loai nhan vien:\n"
             << "1. Lap trinh vien" << endl
             << "2. Kiem chung vien" << endl;
        cin >> loaiNV;
        cin.ignore();
        if (loaiNV == 1)
            nv[i] = new LapTrinhVien();
        else if (loaiNV == 2)
            nv[i] = new KiemChungVien();

        cin.ignore();
        nv[i]->Nhap(); //Nhập dữ liệu từng nhân viên
    }

    cout << "-------DANH CACH NHAN VIEN TRONG CONG TY-------" << endl;
    // Xuất ra danh sách các nhân viên
    for (int i = 0; i < n; i++)
    {
        nv[i]->Xuat();
        cout << endl;
    }

    // Xuất ra danh sách các nhân viên có lương thấp hơn mức trung bình
    // của các nhân viên trong công ty
    double Total_Luong = 0; //Tổng lương
    for (int i = 0; i < n; i++)
        Total_Luong += nv[i]->TinhLuong(); //Cộng dồn vào
    double Aver_Luong = Total_Luong / n; //Chia cho số lượng để lấy trung bình

    cout << "----DANH SACH NHAN VIEN CO LUONG THAP HON MUC TRUNG BINH----" << endl;
    bool flag1 = false;
    for (int i = 0; i < n; i++)
    {
        if (nv[i]->TinhLuong() < Aver_Luong) { //Nếu có nhân viên thỏa điều kiện
            nv[i]->Xuat(); //In ra
            flag1 = true;
        }
    }
    if (!flag1) 
    cout << "Khong co nhan vien nao` co luong thap' hon muc' trung binh`!" << endl;

    // Xuất thông tin nhân viên có lương thấp nhất
    NhanVien *Min_Luong = 0; //Khai báo biến con trỏ với giá trị 0
    for (int i = 0; i < n; i++)
    {
        if (Min_Luong == 0 || Min_Luong->TinhLuong() > nv[i]->TinhLuong()) //nếu thỏa điều kiện
            Min_Luong = nv[i]; //Gán giá trị
    }
    if (Min_Luong != 0) //Nếu tìm thấy
    {
        cout << "\nNhan vien co luong thap nhat la`:" << endl;
        Min_Luong->Xuat();
    }

    // Xuất thông tin nhân viên có lương cao nhất
    NhanVien *Max_Luong = 0; //Thực hiện tương tự như Min_Luong
    for (int i = 0; i < n; i++)
    {
        if (Max_Luong == 0 || Max_Luong->TinhLuong() < nv[i]->TinhLuong())
            Max_Luong = nv[i];
    }
    if (Max_Luong != 0)
    {
        cout << "\nNhan vien co luong cao nhat la`:" << endl;
        Max_Luong->Xuat();
    }

    // Xuất thông tin lập trình viên có lương cao nhất
    NhanVien *LTV_Max = 0; //Thực hiện tương tự
    for (int i = 0; i < n; i++)
    {
        if (nv[i]->GetType() == 1) //Chỉ xét Lập trình viên
        {
            if (LTV_Max == 0 || LTV_Max->TinhLuong() < nv[i]->TinhLuong())
                LTV_Max = nv[i];
        }
    }
    if (LTV_Max != 0)
    {
        cout << endl
             << "\nLap trinh` vien co luong cao nhat' la`:" << endl;
        LTV_Max->Xuat();
    }
    else
        cout << endl
             << "\nKhong co' lap trinh` vien trong danh sach'!";

    // Xuất thông tin kiểm chứng viên có lương thấp nhất
    NhanVien *KCV_Min = 0; //Thực hiện tương tự
    for (int i = 0; i < n; i++)
    {
        if (nv[i]->GetType() == 2) //Chỉ xét Kiểm chứng viên
        {
            if (KCV_Min == 0 || KCV_Min->TinhLuong() > nv[i]->TinhLuong())
                KCV_Min = nv[i];
        }
    }
    if (KCV_Min != 0)
    {
        cout << endl
             << "\nKiem chung vien co luong thap' nhat' la`:" << endl;
        KCV_Min->Xuat();
    }
    else
        cout << endl
             << "\nKhong co' kiem chung vien trong danh sach'!";

    // Giải phóng bộ nhớ
    for (int i = 0; i < n; i++)
        delete nv[i];
    return 0;
}