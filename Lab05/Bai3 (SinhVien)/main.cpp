#include "SinhVien.h"
#include "HeSV.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    SinhVien *ds[100]; // Mảng tĩnh quản lí danh sách các sinh viên
    int n, loaiSV;     // Khai báo số lượng sinh viên và loại sinh viên
    // Nhập vào danh sách sinh viên
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    { // Dùng vòng lặp để xét
        cout << "\nNhap loai sinh vien:\n"
             << "1. Dai hoc" << endl
             << "2. Cao dang" << endl;
        cin >> loaiSV;
         cin.ignore();
        if (loaiSV == 1) // Nếu là 1
            ds[i] = new SVDaiHoc();
        else // Nếu là 2
            ds[i] = new SVCaoDang();
        ds[i]->Nhap(); // Nhập vào dữ liệu
    }

    // Xuất ra danh sách các sinh viên
    cout << "\n-------DANH SACH SINH VIEN-------" << endl;
    for (int i = 0; i < n; i++)
    {
        ds[i]->Xuat();
    }

    // Xuất ra danh sách sinh viên đủ điều kiện tốt nghiệp
    cout << "\n-------DANH SACH SINH VIEN TOT NGHIEP------\n";
    bool flag1 = false;
    for (int i = 0; i < n; i++)
    {
        if (ds[i]->XetTotNghiep()) {
            ds[i]->Xuat();
            flag1 = true;
        }
    }
    if (!flag1)
        cout << "Khong co sinh vien nao` tot' nghiep! TT";
    // Xuất ra danh sách sinh viên không đủ điều kiện tốt nghiệp
    cout << "\n---DANH SACH SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP---\n";
    bool flag2 = false;
    for (int i = 0; i < n; i++)
    {
        if (!ds[i]->XetTotNghiep())
         {
            ds[i]->Xuat();
            flag2 = true;
        }
    }
    if (!flag2) 
        cout << "Tat ca deu` tot nghiep!" << endl;
    // Tìm sinh viên đại học có điểm trung bình cao nhất
    SinhVien *SVDH_DTB_Max = 0; // Khai báo con trỏ với giá trị ban đầu là 0
    for (int i = 0; i < n; i++)
    {
        if (ds[i]->GetType() == 1)
        { // Xét sinh viên đại học
            if (SVDH_DTB_Max == 0 || SVDH_DTB_Max->getDTB() < ds[i]->getDTB())
                SVDH_DTB_Max = ds[i]; // Gán giá trị khi tìm thấy biến thỏa điều kiện
        }
    }
    if (SVDH_DTB_Max != 0)
    { // Nếu tìm thấy
        cout << "\nSinh vien dai hoc co diem trung binh cao nhat la`:" << endl;
        SVDH_DTB_Max->Xuat();
    }
    else
        cout << "\nKhong co sinh vien dai hoc nao trong danh sach!" << endl;

    // Tìm sinh viên cao đẳng có điểm trung bình cao nhất
    SinhVien *SVCD_DTB_Max = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds[i]->GetType() == 2)
        { // Xét sinh viên cao đẳng
            if (SVCD_DTB_Max == 0 || SVCD_DTB_Max->getDTB() < ds[i]->getDTB())
                SVCD_DTB_Max = ds[i];
        }
    }

    if (SVCD_DTB_Max != 0)
    { // Nếu tìm thấy
        cout << "\nSinh vien cao dang co diem trung binh cao nhat la`:" << endl;
        SVCD_DTB_Max->Xuat();
    }
    else
        cout << "\nKhong co sinh vien cao dang nao trong danh sach!" << endl;

    // Tìm số lượng sinh viên không đủ điều kiện tốt nghiệp của mỗi loại
    int SL_DH = 0, SL_CD = 0;
    for (int i = 0; i < n; i++)
    {
        if (!ds[i]->XetTotNghiep())
        {                              // Xét những người không đủ điều kiện tốt nghiệp
            if (ds[i]->GetType() == 1) // Nếu người đó là sinh viên đại học
                SL_DH++;
            else if (ds[i]->GetType() == 2) // Hoặc nếu người đó là sinh viên cao đẳng
                SL_CD++;
        }
    }

    cout << "\nTrong do:" << endl;
    cout << "- Co " << SL_DH << " sinh vien dai hoc khong du dieu` kien tot' nghiep." << endl;
    cout << "- Co " << SL_CD << " sinh vien cao dang khong du dieu` kien tot' nghiep.";

    return 0;
}
