#ifndef PHANSO_H
#define PHANSO_H
#include <iostream>
#include <cmath>
using namespace std;

class PhanSo
{
private:
    int tu;
    int mau;
public:
    PhanSo(int t = 1, int m = 1);
    int UCLN(int a, int b);
    void RutGon();
    friend istream& operator>>(istream& in, PhanSo& ps);
    friend ostream& operator<<(ostream& out, const PhanSo& ps);
    PhanSo operator+(PhanSo khac);
    PhanSo operator-(PhanSo khac);
    PhanSo operator*(PhanSo khac);
    PhanSo operator/(PhanSo khac);
    bool operator==(PhanSo khac);
    bool operator>(PhanSo khac);
    ~PhanSo(); 
};

#endif