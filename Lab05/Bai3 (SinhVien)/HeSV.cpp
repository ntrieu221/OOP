#include "HeSV.h"
#include "SinhVien.h"
#include <string>
#include <iostream>

using namespace std;

// Constructor
SVDaiHoc::SVDaiHoc()
{
    tenLV = "";
    diemLV = 0;
}

// Destructor
SVDaiHoc::~SVDaiHoc() {}

// Nhập thêm dữ liệu
void SVDaiHoc::Nhap()
{
    SinhVien::Nhap();
    cin.ignore();
    cout << "Nhap ten luan van: ";
    getline(cin, tenLV);
    cout << "Nhap diem luan van: ";
    cin >> diemLV;
}
// Xuất thêm dữ liệu
void SVDaiHoc::Xuat()
{
    SinhVien::Xuat();
    cout << "Ten luan van: " << tenLV << " | "
         << "Diem luan van: " << diemLV << endl;
}

// Nếu là sinh viên đại học thì trả về 1
int SVDaiHoc::GetType() { return 1; }

// Xét điều kiện tốt nghiệp của sinh viên đại học
bool SVDaiHoc::XetTotNghiep()
{
    // Nếu số tín chỉ >= 170 và điểm trung bình > 5 và điểm Luận văn > 5)
    return (tc >= 170 && dtb >= 5.0 && diemLV >= 5.0);
}

// Constructor
SVCaoDang::SVCaoDang()
{
    diemthitotnghiep = 0;
}

// Destructor
SVCaoDang::~SVCaoDang() {}

// Nhập thêm dữ liệu
void SVCaoDang::Nhap()
{
    SinhVien::Nhap();
    cout << "Diem thi tot nghiep: ";
    cin >> diemthitotnghiep;
}
// Xuất thêm dữ liệu
void SVCaoDang::Xuat()
{
    SinhVien::Xuat();
    cout << "Diem thi tot nghiep: " << diemthitotnghiep;
}

// Nếu là sinh viên cao đẳng thì trả về 2
int SVCaoDang::GetType() { return 2; }

// Trả về điểm thi tốt nghiệp
double SVCaoDang::getDTN() { return diemthitotnghiep; }

// Xét điều kiện tốt nghiệp của sinh viên cao đẳng
bool SVCaoDang::XetTotNghiep()
{
    // Nếu số tín chỉ > 120 và điểm trung bình > 5 và điểm thi tốt nghiệp > 5)
    return (tc >= 120 && dtb >= 5.0 && diemthitotnghiep >= 5.0);
}
