#ifndef CDATE_H
#define CDATE_H
#include <iostream>
using namespace std;

class cDate
{
private:
    int ngay, thang, nam;
public:
    cDate(int d = 0, int m = 0, int y = 0); //COnstructor
    ~cDate(); //Destructor
    //Các hàm chức năng
    bool isNhuan(int n); //Kiểm tra năm nhuận
    int NgayTrongThang(); //Kiểm tra số ngày có trong tháng
    int TongSoNgay(); //Dùng để tính tổng số ngày

    //Cộng trừ thêm một số ngày
    cDate operator+(int day);
    cDate operator-(int day);

    //Thêm bớt một ngày
    //Tiền tố
    cDate& operator++();
    cDate& operator--();

    //Hậu tố
    cDate operator++(int);
    cDate operator--(int);

    //Khoảng cách giữa hai ngày cDate tính bằng ngày
    long long operator-(cDate& khac);

    //Operator Nhập xuất
    friend istream& operator>>(istream& in, cDate& d);
    friend ostream& operator<<(ostream& out, cDate& d);
};

#endif