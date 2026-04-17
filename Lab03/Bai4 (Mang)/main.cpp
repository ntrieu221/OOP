#include "cArray.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    cArray arr;

    arr.MangNgauNhien();
    arr.Xuat(); cout << endl;
    arr.DemXTrongMang(); cout << endl;
    arr.KiemTraTangDan(); cout << endl;
    arr.TimLeMin(); cout << endl; 
    arr.TimSNTMax(); cout << endl;
    arr.SapXepTangDan();
}

