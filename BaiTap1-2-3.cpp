#include <iostream>
#include <cmath>

// Bài tập 1: Viết chương trình nhập vào một phân số, rút gọn phân số và xuất kết quả //
using namespace std;
// Dùng struct để khai báo phân số
struct phanso {
    int tu;
    int mau;
};

// Hàm tìm Ước chung lớn nhất
int UCLN( int a, int b) {
    a = abs(a);
    b = abs(b);
    while( b != 0 )
    {
      int temp = b;
      b = a % b;
      a = temp;
    }
    return a;
// Trả về ước chung lớn nhất của a và b
}

// Hàm rút gọn phân số
void RutGon( int &a, int &b) {
    int uc = UCLN(a, b);
    a /= uc;
    b /= uc;

// Nếu như mẫu số âm, đổi dấu
    if ( b < 0) {
        a = -a;
        b = -b;
    }
}

// Hàm quy đồng hai phân số
void QuyDong( int &tu2, int &mau2, int &tu3, int &mau3) {
 //Rút gọn trước khi quy đồng
  RutGon(tu2, mau2);
  RutGon(tu3, mau3);
  //Tìm ước chung lớn nhất của hai phân số
  int uc = UCLN(mau2, mau3);
  //Tìm bội chung nhỏ nhất của hai phân số
  int bcnn = (mau2 * mau3) / uc;
  tu2 *= (bcnn / mau2);
  mau2 = bcnn;
  tu3 *= ( bcnn / mau3);
  mau3 = bcnn;
  //Quy đồng cả hai với mẫu số chung
}
//Tính toán cộng trừ nhân chia giữa các phân số
void TinhToan(int a, int b, int c, int d) {
    //Thực hiện quy đồng với phép cộng và phép trừ
    QuyDong(a,b,c,d);
    //Phép cộng
    int congtu = a + c;
    int congmau = b;
    //Rút gọn sau khi đã tính toán
    RutGon(congtu, congmau);
    cout << "Phep cong: " << congtu << "/" << congmau << endl;
    //Phép trừ
    int trutu = a - c;
    int trumau = d;
    //Rút gọn sau khi đã tính toán
    RutGon(trutu, trumau);
    cout << "Phep tru: " << trutu << "/" << trumau << endl;
    //Phép nhân
    int nhantu = a * c;
    int nhanmau = b * d;
    //Rút gọn sau khi đã tính toán
    RutGon(nhantu, nhanmau);
    cout << "Phep nhan: " << nhantu << "/" << nhanmau << endl;
    //Phép chia
    int chiatu = a * d;
    int chiamau = b * c;
    //Rút gọn sau khi đã tính toán
    RutGon(chiatu, chiamau);
    cout << "Phep chia: " << chiatu << "/" << chiamau << endl;

}
int main()
{
  phanso ps1;
  cout << "------------ RUT GON PHAN SO ------------" << endl;
  //Nhập input
  cout << "Nhap ps1:" << endl;

  cin >> ps1.tu >> ps1.mau;
  //Thực hiện gọi đến hàm Rút gọn
  RutGon(ps1.tu, ps1.mau);
  cout << "Ket qua cua ps1 sau khi rut gon: " ;
  //Nếu như mẫu số bằng 0 => Ngay lập tức trả về 0.
  if ( ps1.mau == 0)
    return 0;
//Nếu như mẫu số bằng 1, thì chỉ hiển thị tử số.
  else if ( ps1.mau == 1)
    cout << ps1.tu;
//Nếu không phải hai trường hợp trên thì hiển thị phân số có đầy đủ tử và mẫu
  else
    cout << ps1.tu << "/" << ps1.mau;
  cout << endl << "------------ PHAN SO LON NHAT ------------" << endl;

  //Bài tập 2: Viết chương trình nhập vào hai phân số, tìm phân số lớn nhất và xuất kết quả//
  phanso ps2;
  phanso ps3;
  cout << endl;
  cout << "Nhap ps2: " << endl;
  cin >> ps2.tu >> ps2.mau;
  cout << "Nhap ps3: " << endl;
  cin >> ps3.tu >> ps3.mau;
  //Gọi đến hàm Quy đồng
  QuyDong(ps2.tu, ps2.mau, ps3.tu, ps3.mau);
  if ( ps2.tu > ps3.tu)
    cout << "ps2 lon hon ps3";
  else
    cout << "ps3 lon hon ps2";
  cout << endl;
  //Bài tập 3: Viết chương trình nhập vào hai phân số. Tính tổng, hiệu, tích, thương giữa chúng và xuất kết quả//
  cout << "------------ CONG TRU NHAN CHIA ------------" << endl;
  phanso ps4;
  phanso ps5;
  cout << "Nhap ps4: " << endl;
  cin >> ps4.tu >> ps4.mau;
  cout << "Nhap ps5: " << endl;
  cin >> ps5.tu >> ps5.mau;
  //Gọi đến hàm TÍnh toán để thực hiện chức năng
  TinhToan(ps4.tu, ps4.mau, ps5.tu, ps5.mau);
}
