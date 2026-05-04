#ifndef CDATHUC_H
#define CDATHUC_H
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class cDaThuc
{
private:
    int bac;
    double* heso;
public:
    //Constructor
    cDaThuc(int b = 0);
    cDaThuc(const cDaThuc& dt);
    //Destructor
    ~cDaThuc();

    //Các operator chức năng
    friend istream& operator>>(istream& in, cDaThuc& dt);
    friend ostream& operator<<(ostream& out, const cDaThuc& dt);

    cDaThuc operator+(cDaThuc& dt);
    cDaThuc operator-(cDaThuc& dt);
    cDaThuc operator=(cDaThuc& dt);
    //Hàm tính giá trị x
    double operator()(double x);
};

#endif