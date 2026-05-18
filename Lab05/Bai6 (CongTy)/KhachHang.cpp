#include "KhachHang.h"
#include <fstream>

using namespace std;

KhachHang::KhachHang()
{
    Hoten = "";
    DonGia = 0.0;
    SoLuong = 0;
}

void KhachHang::docFile(ifstream &in) {
    in.ignore();
    getline(in, Hoten);
    in >> SoLuong >> DonGia;
}

string KhachHang::GetTen() { return Hoten; }

KhachHang::~KhachHang() {}