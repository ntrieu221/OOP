#include <iostream>
#include "CVector.h"

using namespace std;

int main() {
    int n;
    cout << "Nhap so chieu cua Vector: ";
    cin >> n;

    CVector v1(n), v2(n);

    cout << "Nhap Vector 1:\n"; cin >> v1;
    cout << "Nhap Vector 2:\n"; cin >> v2;

    cout << "\nV1: " << v1 << endl;
    cout << "V2: " << v2 << endl;
    
    cout << "V1 + V2 = " << v1 + v2 << endl;
    cout << "V1 - V2 = " << v1 - v2 << endl;
    cout << "Tich vo huong: " << v1 * v2 << endl;

    return 0;
}