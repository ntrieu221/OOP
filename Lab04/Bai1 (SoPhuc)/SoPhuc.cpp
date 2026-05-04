#include "SoPhuc.h"
#include <iostream>
#include <cmath>
using namespace std;

//Constructor
SoPhuc::SoPhuc(double th, double a) {
    thuc = th;
    ao = a;
}

//Operator nhập giá trị
istream& operator>>(istream& in, SoPhuc& sp) {
    cout << "Nhap so thuc: "; in >> sp.thuc;
    cout << "Nhap so ao: "; in >> sp.ao;
    return in;
}

//Operator xuất giá trị 
ostream& operator<<(ostream& out, const SoPhuc& sp) {
    //Nếu cả phần thực và phần ảo bằng 0 thì in ra 0
    if (sp.thuc == 0 && sp.ao == 0) {
        out << "0";
        return out;
   }

   //Nếu phần thực khác 0 thì in phần thực trước
    if (sp.thuc != 0) {
        out << sp.thuc;
    }
    //Nếu như phần ảo khác 0
    if (sp.ao != 0) {
        //và dương
        if (sp.ao > 0) {
            //và nếu phần thực khác 0 thì in dấu cộng rời
            if (sp.thuc != 0) out << " + " << sp.ao << "i";
            //Nếu không thì chỉ in phần ảo
            else out << sp.ao << "i";
        }
        //Xét tương tự khi phần ảo âm
        else {
            if (sp.thuc != 0) out << " - " << abs(sp.ao) << "i";
            else out << "-" << abs(sp.ao) << "i";       
        }
    }
    return out;
}

//Các phép toán
// (a + bi) + (c + di) = (a + c) + (b + d)i
SoPhuc SoPhuc::operator+(SoPhuc khac) {
    SoPhuc kq;
    kq.thuc = thuc + khac.thuc;
    kq.ao = ao + khac.ao;
    return kq;
}

// (a + bi) + (c + di) = (a - c) + (b - d)i
SoPhuc SoPhuc::operator-(SoPhuc khac) {
    SoPhuc kq;
    kq.thuc = thuc - khac.thuc;
    kq.ao = ao - khac.ao;
    return kq;
}

// (a + bi)(c + di) = (ac - bd) + (ad + bc)i
SoPhuc SoPhuc::operator*(SoPhuc khac) {
    SoPhuc kq;
    kq.thuc = (thuc * khac.thuc - ao * khac.ao);
    kq.ao = (thuc * khac.ao + ao * khac.thuc);
    return kq;
}

// (a + bi)/(c + di) = (ac + bd) + (bc = ad)i / c^2 + d^2
SoPhuc SoPhuc::operator/(SoPhuc khac) {
    SoPhuc kq;
    //Gán trước giá trị mẫu chung để gọn chương trình
    double mau = khac.thuc * khac.thuc + khac.ao * khac.ao;
    if (mau == 0) {
        cout << "Loi chuong trinh!";
        return SoPhuc(0, 0);
    //Nếu mẫu bằng 0 thì dừng ngay
    }
    kq.thuc = (thuc * khac.thuc + ao * khac.ao) / mau;
    kq.ao = (ao * khac.thuc - thuc * khac.ao) / mau;
    return kq;
}
//Phép so sánh hai số phức
bool SoPhuc::operator==(SoPhuc khac) {
    return (thuc == khac.thuc && ao == khac.ao);
}
bool SoPhuc::operator!=(SoPhuc khac) {
    return (thuc != khac.thuc || ao != khac.ao);
}

//Destructor
SoPhuc::~SoPhuc() {}