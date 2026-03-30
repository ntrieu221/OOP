#include "SoPhuc.h"
#include <iostream>
#include <cmath>
using namespace std;

//Hàm input nhập vào giá trị của số thực và số ảo
void SoPhuc::Nhap() {
    cin >> iThuc >> iAo;
}

//Hàm xuất ra Output
void SoPhuc::Xuat() {
//Nếu phần số ảo bằng 0 (Chỉ in phần số thực)
if (iAo == 0) {
    cout << iThuc;
    return;
}
//Nếu phần số thực bằng 0 (Chỉ in phần số ảo)
if (iThuc == 0) {
    if (iAo == 1) cout << "i";
    else if (iAo == -1) cout << "-i";
    else cout << iAo << "i";
    return;
}

//Trường hợp có cả phần số thực và phần số ảo
cout << iThuc;
if (iAo == 1) cout << " + i";
else if (iAo == -1) cout << " - i";
else if (iAo > 0) cout << " + " << iAo << "i";
else cout << " - " << abs(iAo) << "i";
}

//(a + bi) + (c + di) = (a + c) + (b + d)i
SoPhuc SoPhuc::TinhTong(SoPhuc &sp) {
SoPhuc kq;
kq.iThuc = iThuc + sp.iThuc;
kq.iAo = iAo + sp.iAo;
return kq;
}

//(a + bi) - (c + di) = (a - c) + (b - d)i
SoPhuc SoPhuc::TinhHieu(SoPhuc &sp) {
SoPhuc kq;
kq.iThuc = iThuc - sp.iThuc;
kq.iAo = iAo - sp.iAo;
return kq;
}

//(a + bi)(c + di) = (ac - bd) + (ad + bc)i
SoPhuc SoPhuc::TinhTich(SoPhuc &sp) {
SoPhuc kq;
kq.iThuc = (iThuc * sp.iThuc) - (iAo * sp.iAo);
kq.iAo = (iThuc * sp.iAo) + (iAo * sp.iThuc);
return kq;
}

// (a + bi)/(c + di) = (ac + bd) + (bc - ad)i/c^2 + d^2
SoPhuc SoPhuc::TinhThuong(SoPhuc &sp) {
SoPhuc kq;
//Khởi tạo biến mẫu số
double mauso;
mauso = (sp.iThuc * sp.iThuc) + (sp.iAo * sp.iAo);
//Nếu mẫu bằng
if (mauso == 0) {
    cout << "Loi chia cho 0";
    return kq;
}
kq.iThuc = (iThuc * sp.iThuc + iAo * sp.iAo) / mauso;
kq.iAo = (iAo * sp.iThuc - iThuc * sp.iAo) / mauso;
return kq;
}
