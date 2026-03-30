#include "GioPhutGiay.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    //Tạo giá trị
    GioPhutGiay time;
    time.Nhap();
    cout << "Gio phut giay vua` nhap la`: \n ";
    time.Xuat();

    time.TinhCongThemMotGiay();
    cout << endl << "Gio phut giay sau khi +1 giay la`: \n ";
    time.Xuat();
}
