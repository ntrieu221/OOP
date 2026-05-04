#ifndef CTIME_H
#define CTIME_H
#include <iostream>
#include <iomanip>

using namespace std;

class CTime {
    protected:
        int hour, minute, second;
    public: 
        CTime(int h = 0, int m = 0, int s = 0); //Construstor
        void ChuanHoa();
        friend istream& operator>>(istream& in, CTime& t);
        friend ostream& operator<<(ostream& out, const CTime& t);
        //Cộng hoặc trừ thêm một số nguyên giây
        CTime operator+(int sec);
        CTime operator-(int sec);
        //Thêm bớt một giây
        //Tiền tố
        CTime& operator++();
        CTime& operator--();
        //Hậu tố
        CTime operator++(int);
        CTime operator--(int);
        //kiểu dữ liệu int dùng để phân biệt 
        ~CTime();
};
#endif