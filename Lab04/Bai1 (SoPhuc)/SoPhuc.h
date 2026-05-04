#ifndef SOPHUC_H
#define SOPHUC_H
#include <iostream>
#include <cmath>
using namespace std;

class SoPhuc
{
    private:
        double thuc;
        double ao;
    public:
        SoPhuc(double th = 0, double a = 0);
        friend istream& operator>>(istream& in, SoPhuc& sp);
        friend ostream& operator<<(ostream& out, const SoPhuc& sp);
        SoPhuc operator+(SoPhuc khac);
        SoPhuc operator-(SoPhuc khac);
        SoPhuc operator*(SoPhuc khac);
        SoPhuc operator/(SoPhuc khac);
        bool operator==(SoPhuc khac);
        bool operator!=(SoPhuc khac);
        ~SoPhuc();
};
#endif