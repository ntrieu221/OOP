#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>
#include <vector>

using namespace std;

class CVector {
private:
    vector<double> data; // Dùng vector để tự động quản lý mảng

public:
    // Khởi tạo vector n chiều (mặc định bằng 0)
    CVector(int n = 0) : data(n, 0) {}

    // Các toán tử nhập xuất 
    friend istream& operator>>(istream& in, CVector& v);
    friend ostream& operator<<(ostream& out, const CVector& v);

    // Các phép toán
    CVector operator+(const CVector& khac) const; // Cộng
    CVector operator-(const CVector& khac) const; // Trừ
    double operator*(const CVector& khac) const;  // Tích vô hướng
};

#endif