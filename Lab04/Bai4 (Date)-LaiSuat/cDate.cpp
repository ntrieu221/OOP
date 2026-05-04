#include "cDate.h"
#include <iostream>
#include <cmath>

using namespace std;
  

cDate::cDate(int d, int m, int y) {
    ngay = d; thang = m; nam = y;
}
cDate::~cDate() {}
//Kiểm tra năm nhuận
bool cDate::isNhuan(int n) {
    return ((n % 400 == 0) || (n % 4 == 0 && n % 100 != 0));
}
//Thực hiện tính toán số ngày có trong tháng
int cDate::NgayTrongThang() {
    switch(thang) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11: 
            return 30;
        case 2:
            return isNhuan(nam) ? 29: 28;
        default:
            return 0;
    }
}

int cDate::TongSoNgay() {
    long total = ngay;
    //Tính tổng số ngày bắt đầu từ 01/01/0001
    //Cộng tất cả các ngày của từng năm
    for (int y = 1; y < nam; y++) {
        if (isNhuan(y))
            total+= 366;
        else
            total+=365;
    }
    for (int m = 1; m < thang; m++) {
        total += NgayTrongThang();
    }
    return total;

}

//Cộng thêm một số ngày
cDate cDate::operator+(int day) {
    cDate tmp = *this;
    for (int i = 0; i < day; i++) tmp++;
    return tmp;
}

//Trừ đi một số ngày
cDate cDate::operator-(int day) {
     cDate tmp = *this;
    for (int i = 0; i < day; i++) tmp--;
    return tmp;
}
//Dùng một biến tạm để lưu giá trị và dùng vòng lặp để thực hiện phép tính
//Tiền tố
cDate& cDate::operator++() {
    ngay++;
    //Nếu số ngày hiện tại lớn hơn số ngày trong tháng
    if (ngay > NgayTrongThang()) {
        //=> Qua tháng mới
        ngay = 1;
        thang++;
        //nếu tháng lớn hơn 12
        if (thang > 12) {
        //Qua năm mới
            thang = 1;
            nam++;
        }
    }
    return *this;
}
cDate& cDate::operator--() {
    ngay--;
    //nếu ngày bé hơn 1
    if (ngay < 1) {
        //Trở về tháng trước
        thang--;
        //Nếu tháng bé hơn 1
        if (thang < 1) {
            //Trở về năm trước
            thang = 12;
            nam--;
        }
        //Số ngày sau khi tính toán sẽ bằng số ngày trong tháng
        ngay = NgayTrongThang();
    }
    return *this;
//Thực hiện các phép tính rồi mới trả về kết quả
}
//Hậu tố
cDate cDate::operator++(int) {
    cDate tmp = *this;
    ++(*this);
    return tmp;
}
cDate cDate::operator--(int) {
     cDate tmp = *this;
    --(*this);
    return tmp;
}
//Trả về giá trị trước rồi mới thực hiện phép tính

//Thực hiện tính tổng số ngày
long long cDate::operator-(cDate& khac) {
    return abs(this->TongSoNgay() - khac.TongSoNgay());
}

//Operator nhập xuất
istream& operator>>(istream& in, cDate& d) {
    in >> d.ngay >> d.thang >> d.nam;
    return in;
}
ostream& operator<<(ostream& out, cDate& d) {
    out << d.ngay << "/" << d.thang << "/" << d.nam;
    return out;
}


