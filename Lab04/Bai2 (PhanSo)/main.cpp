#include <iostream>
#include "PhanSo.h"
#include <cmath>
using namespace std;

int main() {
    PhanSo ps1, ps2;
    cout << "Nhap phan so 1:\n";
    cin >> ps1;
    cout << "Nhap phan so 2:\n";
    cin >> ps2;
    cout << "\nHai phan so vua` nhap la`:" << endl;
    cout << ps1 << endl << ps2 << endl;

    //Các phép tính
    cout << "---CAC PHEP TINH---\n";
    cout << "Phep cong: " << ps1 + ps2 << endl;
    cout << "Phep tru: " << ps1 - ps2 << endl;
    cout << "Phep nhan: " << ps1 * ps2 << endl;
    cout << "Phep chia: " << ps1 / ps2 << endl;

    if (ps1 == ps2) cout << "Hai phan so bang` nhau.";
    else if (ps1 > ps2)
        cout << "Phan so 1 > Phan so 2";
    else 
        cout << "Phan so 1 < Phan so 2";
    return 0;

}