#include "cMatrix.h"
#include <iostream>

using namespace std;
//Constructor
cMatrix::cMatrix(int d, int c) : soDong(d), soCot(c) {
    //Duyệt qua từng phần tử và gán giá trị 0
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            data[i][j] = 0;
}

//Operator nhập xuất
istream& operator>>(istream& in, cMatrix& mt) {
    for (int i = 0; i < mt.soDong; i++) {
        for (int j = 0; j < mt.soCot; j++) {
            cout << "  Phan tu [" << i << "][" << j << "]: ";
            in >> mt.data[i][j];
        }
    }
    return in;
}

ostream& operator<<(ostream& out, const cMatrix& mt) {
    for (int i = 0; i < mt.soDong; i++) {
        for (int j = 0; j < mt.soCot; j++) {
            out << mt.data[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

// Logic nhân 2 ma trận
cMatrix cMatrix::operator*(const cMatrix& khac) {
    //Tạo một ma trận có số dòng của ma trận này và số cột của ma trận kia
    cMatrix kq(this->soDong, khac.soCot);
    //Duyệt qua từng dòng của ma trận này
    for (int i = 0; i < this->soDong; i++) {
        //Duyệt qua từng cột của ma trận kia
        for (int j = 0; j < khac.soCot; j++) {
            //Chạy dọc theo cột của a và dòng của B để nhân
            for (int k = 0; k < this->soCot; k++) {
                // Công thức tính tổng tích dòng i của A với cột j của B
                kq.data[i][j] += this->data[i][k] * khac.data[k][j];
            }
        }
    }
    return kq;
}

// Nhân ma trận với vector (mảng 1 chiều)
void cMatrix::nhanVector(double InArr[], double OutArr[]) {
    //Duyệt qua từng dòng của ma trận
    for (int i = 0; i < soDong; i++) {
        //Khởi tạo giá trị tại vị trí i
        OutArr[i] = 0; // Đặt giá trị ban đầu là 0
        for (int j = 0; j < soCot; j++) {
            //Duyệt qua các phần tử để nhân
            OutArr[i] += data[i][j] * InArr[j];
        }
    }
}