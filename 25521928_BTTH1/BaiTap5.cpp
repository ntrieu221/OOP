#include <iostream>
using namespace std;
//Khai báo struct
struct Hocsinh {
    char HovaTen[20];
    float diemToan;
    float diemVan;
};

int main()
{
//Khởi tạo biến có kiểu dữ liệu là Hocsinh.
 Hocsinh a;
 //Thực hiện nhập các Input
 cout << "Nhap Ho va Ten: " << endl;
 cin.getline(a.HovaTen, 20);
 cout << "Nhap diem Toan:" << endl;
 cin >> a.diemToan;
 cout << "Nhap diem Van: " << endl;
 cin >> a.diemVan;
 //Khai báo biến dtb để tính điểm trung bình
 float dtb = ( a.diemToan + a.diemVan ) / 2;
 //Xuất ra các thông tin đã điền
 cout << "Ho va Ten cua Hoc sinh la: " << a.HovaTen << endl;
 cout << "Diem mon Toan: " << a.diemToan << endl;
 cout << "Diem mon Van: " << a.diemVan << endl;
 cout << "Diem Trung Binh: " << dtb;
 return 0;
}
