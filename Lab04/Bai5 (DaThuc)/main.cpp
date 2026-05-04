#include <iostream>
#include "cDaThuc.h"

using namespace std;

    int main() {
    cDaThuc a, b;
    //Nhập vào giá trị đa thức
    cout << "--- NHAP DA THUC A ---" << endl;
    cin >> a;
    
    cout << "--- NHAP DA THUC B ---" << endl;
    cin >> b;

    cout << "\nDa thuc A: " << a << endl;
    cout << "Da thuc B: " << b << endl;

    //Các phép toán
    cout << "A + B = " << a + b << endl;
    cout << "A - B = " << a - b << endl;

    double x;
    cout << "\nNhap x: ";
    cin >> x;
    // Dung operator() de tinh gia tri: tong(x)
    cout << "Gia tri Da thuc A tai " << x << " la: " << a(x) << endl;
    cout << "Gia tri Da thuc B tai " << x << " la: " << b(x) << endl;


    return 0;
}