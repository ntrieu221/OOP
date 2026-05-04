#ifndef cMatrix_H
#define cMatrix_H

#include <iostream>
#include <iomanip>

using namespace std;

class cMatrix {
private:
    int soDong, soCot;
    double data[100][100]; // Mảng cố định tối đa 100x100
public:
    // Hàm khởi tạo mặc định
    cMatrix(int d = 0, int c = 0);

    friend istream& operator>>(istream& is, cMatrix& mt);
    friend ostream& operator<<(ostream& os, const cMatrix& mt);

    // Nạp chồng toán tử nhân hai ma trận: A * B
    cMatrix operator*(const cMatrix& khac);

    // Hàm nhân ma trận với một mảng (biểu diễn vector)
    void nhanVector(double InArr[], double OutArr[]);
};

#endif