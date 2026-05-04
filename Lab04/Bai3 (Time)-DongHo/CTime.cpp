#include "CTime.h"
#include <iomanip>
#include <iostream>

using namespace std;

CTime::CTime(int h, int m, int s) {
    hour = h; minute = m; second = s;
}

istream& operator>>(istream& in, CTime& t) {
    in >> t.hour >> t.minute >> t.second;
    t.ChuanHoa();
    return in;
}
ostream& operator<<(ostream& out, const CTime& t) {
    out << setfill('0') << setw(2) << t.hour << ":"
        << setw(2) << t.minute << ":"
        << setw(2) << t.second;
    return out;
}

void CTime::ChuanHoa() {
    //Xử lí giây
        //Số giây bằng số giây dư và cộng phần nguyên vào phút
        minute += second / 60;
        second %= 60;
        //Xử lí phép trừ
        if (second < 0) {
            second += 60;
            minute--;
        }
    
    //Xử lí phút
        //Số phút bằng số phút dư và cộng phần nguyên vào giờ
        hour += minute / 60;
        minute %= 60;
        //Xử lí phép trừ
        if ( minute < 0) {
            minute += 60;
            hour--;
        }
    
    //Xử lí giờ
        //Qua ngày mới
        hour %= 24;
        //Xử lí phép trừ
        if (hour < 0) 
            hour += 24;
}
//Cộng hoặc trừ thêm một số nguyên giây
CTime CTime::operator+(int sec) {
    return CTime(hour, minute, second + sec);
}

CTime CTime::operator-(int sec) {
    return CTime(hour, minute, second - sec);
}
//return CTime(...) trả về một đối tượng mới

//Thêm bớt một giây
//Tiền tố
CTime& CTime::operator++() {
    second++;
    ChuanHoa();
    return *this;
}
CTime& CTime::operator--() {
    second--;
    ChuanHoa();
    return *this;
}

//Hậu tố
CTime CTime::operator++(int) {
   CTime tmp(hour, minute, second);
   second++;
   ChuanHoa();
   return tmp;
}
CTime CTime::operator--(int) {
    CTime tmp(hour, minute, second);
    second--;
    ChuanHoa();
    return tmp;
}

CTime::~CTime() {}
   