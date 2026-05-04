#include "CVector.h"

// Nhập từng phần tử
istream& operator>>(istream& in, CVector& v) {
    for (int i = 0; i < v.data.size(); i++) {
        cout << "  Phan tu [" << i << "]: ";
        in >> v.data[i];
    }
    return in;
}

// Xuất dạng (x1, x2, ...)
ostream& operator<<(ostream& out, const CVector& v) {
    out << "(";
    for (int i = 0; i < v.data.size(); i++) {
        out << v.data[i] << (i == v.data.size() - 1 ? "" : ", ");
    }
    out << ")";
    return out;
}

// Logic cộng: cộng từng vị trí tương ứng
CVector CVector::operator+(const CVector& khac) const {
    CVector res(data.size());
    for (int i = 0; i < data.size(); i++) {
        res.data[i] = data[i] + khac.data[i];
    }
    return res;
}

//Tương tự
CVector CVector::operator-(const CVector& khac) const {
    CVector res(data.size());
    for (int i = 0; i < data.size(); i++) {
        res.data[i] = data[i] - khac.data[i];
    }
    return res;
}

// Tích vô hướng: nhân từng cặp rồi cộng dồn
double CVector::operator*(const CVector& khac) const {
    double sum = 0;
    for (int i = 0; i < data.size(); i++) {
        sum = sum + data[i] * khac.data[i];
    }
    return sum;
}