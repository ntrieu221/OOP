#include <iostream>
#include "NgayThangNam.h"
using namespace std;

int main()
{
    NgayThangNam d;

    d.Nhap();

    cout << "Ngay vua nhap la:\n ";
    d.Xuat();

    d.TinhNgayKeTiep();
    cout << endl << "Ngay tiep theo la:\n ";
    d.Xuat();

    return 0;
}
