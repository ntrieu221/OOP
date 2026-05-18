// Công ty Bất động sản VAKALAND
#include "GiaoDich.h"
#include "CacLoaiGiaoDich.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    GiaoDich *ds[100]; //Mảng tĩnh quản lí danh sách các loại giao dịch
    int loaiGD; //Loại giao dịch
    int n; //Số lượng giao dịch
    cout << "Nhap so luong giao dich: ";
    cin >> n;
    for (int i = 0; i < n; i++) //Dùng vòng lặp để xét từng loại giao dịch
    {
        cout << "Nhap loai giao dich:\n"
             << "1. Dat' " << endl
             << "2. Nha` pho'" << endl
             << "3. Can ho " << endl;
        cin >> loaiGD;
        cin.ignore();
        //Chỉ nhập 1, 2 hoặc 3
        if (loaiGD == 1) //Nếu là loại 1 
            ds[i] = new GiaoDichDat();
        else if (loaiGD == 2)
            ds[i] = new GiaoDichNhaPho(); //Nếu là loại 2
        else
            ds[i] = new GiaoDichCanHo(); //Còn không thì là loại 3

        ds[i]->Nhap(); //Nhập vào theo từng loại giao dịch
    }

    // Tính tổng số lượng Giao dịch cho từng loại
    int SLD = 0, SLNP = 0, SLCH = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds[i]->GetType() == 1) //Nếu là giao dịch Đất
            SLD++;
        else if (ds[i]->GetType() == 2) //Nếu là giao dịch Nhà phố
            SLNP++;
        else //Còn lại thì là giao dịch căn hộ
            SLCH++;
    }

    cout << "\nSo luong cac loai giao dich:\n"
         << "Giao dich dat': " << SLD << endl
         << "Giao dich nha` pho: " << SLNP << endl
         << "Giao dich can ho: " << SLCH << endl;

    // Tính trung bình thành tiền của giao dịch Căn hộ chung cư
    double Total = 0; //Tổng
    for (int i = 0; i < n; i++)
    {
        if (ds[i]->GetType() == 3)
        {
            Total += ds[i]->TinhTien();
        }
    }

    if (SLCH > 0) //Nếu có giao dịch căn hộ
        cout << "\nSo tien` trung binh` cua giao dich can ho: " <<  (long long) (Total / SLCH);
    else
        cout << "\nKhong co giao dich can ho!";

    // Tìm Giao dịch nhà phố có giá trị cao nhất
    GiaoDich *MaxDeal = 0; //Biến con trỏ có giá trị 0
    for (int i = 0; i < n; i++)
    {
        if (ds[i]->GetType() == 2) //Chỉ xét giao dịch Nhà phố
        { 
            //Nếu không tìm thấy hoặc tìm thấy được giá trị thỏa điều kiện
            if (MaxDeal == 0 || MaxDeal->TinhTien() < ds[i]->TinhTien())
                MaxDeal = ds[i]; //Gán giá trị
        }
    }
        if (MaxDeal != 0) //Nếu tìm được 
        {
            cout << "\nGiao dich nha` pho' co gia tri cao nhat' la`: " << endl;
            MaxDeal->Xuat();
        }
        else
        {
            cout << "\nKhong co giao dich nha` pho!";
        }


        cout << "\nGiao dich trong thang 12 nam 2024:\n";
    bool flag = false; //Đặt biến để kiểm tra xem có giao dịch trogn tháng 12 năm 2024 không

    // Xuất ra danh sách các giao dịch của tháng 12 năm 2024
    for (int i = 0; i < n; i++)
    {
        if (ds[i]->GetThangNam() == "12/2024")
        {
            ds[i]->Xuat();
            cout << endl;
            flag = true; // Đánh dấu là đã tìm thấy giao dịch
        }
    }

    // Nếu chạy hết vòng lặp mà vẫn là false thì thông báo cho người dùng biết
    if (!flag)
    {
        cout << "Khong co giao dich nao trong thang 12/2024!" << endl;
    }
    return 0;
}