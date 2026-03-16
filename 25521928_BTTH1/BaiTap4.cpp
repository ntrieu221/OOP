#include <iostream>
using namespace std;

//Khai báo struct.
struct Date {
  int ngay;
  int thang;
  int nam;
};

//Hàm xét năm nhuận.
bool XetNamNhuan(int nam) {
//Cách để tính năm nhuận hoặc không nhuận.
    return ( (nam % 4 == 0) && (nam % 100 != 0) || ( nam % 400 == 0) );
//Trả về True (Nhuận) hoặc False (Không nhuận).
}
//Hàm tính số ngày trong tháng
int NgaytrongThang(int ngay, int thang, int nam) {
    //Dùng switch để xét dễ hơn
    switch(thang) {
    //Các case tương đương với các tháng sẽ có 31 ngày.
    case 1: case 3: case 5: case 7: case 8:case 10: case 12:
        return 31;
    //Các case tương đương với các tháng sẽ có 30 ngày.
    case 4: case 6: case 9: case 11:
        return 30;
    //Riêng tháng 2 phải xét riêng
    case 2:
    //Nếu là năm nhuận => Trả về 29 ngày.
        if (XetNamNhuan(nam))
            return 29;
    //Còn không nhuận thì là 28 ngày.
        else
            return 28;
    default:
        return 0;
    }
}

//Hàm tìm ngày kế tiếp.
void TimNgayKeTiep( int &ngay, int &thang, int &nam) {
    //Khai báo biến maxDay là ngày cuối cùng trong tháng.
    int maxDay = NgaytrongThang(ngay, thang, nam);
    //Nếu như ngày trong tháng lớn hơn ngày cuối cùng trong tháng
    if ( ngay >= maxDay) {
       // Qua tháng mới.
        ngay = 1;
        thang++;
    }
    //Còn không thì chỉ cần tăng ngày lên 1 đơn vị.
    else {
        ngay++;
    }
    //Nếu tháng lớn hơn 12
    if ( thang > 12) {
    //Qua năm mới
        thang = 1;
        ngay = 1;
        nam++;
    }
}

int main()
{
//Khai báo biến có kiểu dữ liệu Date.
   Date d;
//Nhập vào ngày tháng năm.
   cin >> d.ngay >> d.thang >> d.nam;
//Gọi hàm để thực hiện Tìm ngày kế tiếp
   TimNgayKeTiep(d.ngay, d.thang, d.nam);
//Trả về kết quả
   cout << d.ngay << "/" << d.thang << "/" << d.nam;
   return 0;
}
