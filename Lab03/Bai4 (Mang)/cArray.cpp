#include "cArray.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

cArray::cArray() {
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    //Cấp phát động một mảng mới
    a = new int[n];
}

cArray::~cArray() { delete[] a; }

void cArray::MangNgauNhien() {
    //Có sẵn trong thư viện, dùng để các lần random lấy số khác nhau
    srand(time(0));
    for ( int i = 0; i < n; i++) {
         //Có sẵn trong thư viện, dùng để lấy một số ngẫu nhiên 
        a[i] = rand() % 100 + 1;
    }

}
void cArray::Xuat() {
    for ( int i = 0; i < n ; i++) {
        cout << a[i] << "  ";
    }
}

void cArray::DemXTrongMang() {
    int x, count = 0;
    cout << "\nNhap phan tu can dem so lan xuat hien: ";
    cin >> x;
    //Nếu tìm được x thì tăng count lên
    for ( int i = 0; i < n ; i++) {
        if ( a[i] == x) count++;
    }
    cout << "Phan tu " << x << " xuat hien " << count << " lan`!\n";
}
void cArray::KiemTraTangDan() {
    //Đặt cờ
    bool flag = true;
    //Nếu như tìm thấy một số mà lớn hơn số ngay sau nó trong mảng
    //=> Gán false
    for ( int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) flag = false;
    }
    if (flag) cout << "Day la` mang tang dan`.";
    else cout << "Day khong phai la` mang tang dan`.";
}
void cArray::TimLeMin() {
    //Tạo một mảng b
    int* b = new int[n];
    int k = 0;
    //Tìm các số lẻ và gán vào mảng b
    for ( int i = 0; i < n; i++) {
        if ( a[i] % 2 == 1) {
            b[k] = a[i];
            k++;
        }
    }
    //Nếu như k bằng 0 có nghĩa là mảng không có phần tử lẻ
    if (k == 0) cout << "\nMang khong co phan tu le!";
    //Giả sử phần tử lẻ đầu tiên trong mảng b là nhỏ nhất
    else {
        int lc = b[0];
        for ( int i = 0; i < k ; i++) {
        //Nếu tìm được giá trị nào trong mảng b nhỏ hơn lc thì nó sẽ trở thành lc
            if (b[i] < lc ) 
                lc = b[i];  
        }
        cout << "\nPhan tu le nho nhat la`: " << lc;
    }
    delete[] b;
}

bool cArray::TimSNT(int x) {
    //Nếu như nhỏ hơn 2 thì không phải số nguyên tố
    if ( x < 2) return false;
    //Thuật toán tìm số nguyên tố
    for ( int i = 2; i*i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void cArray::TimSNTMax() {
    //Tạo một mảng c
    int* c = new int[n];
    int j = 0;
    //Mảng c sẽ chứa các số nguyên tố
    for ( int i = 0 ; i < n; i++) {
        if (TimSNT(a[i])) {
            c[j] = a[i];
            j++;
        }
    }
    //Nếu j bằng 0 thì mảng không có số nguyên tố
    if (j == 0) cout << "\nMang khong co so nguyen to!";
    else {
        //Giả sử phần tử index 0 là số nguyên tố nhỏ nhất
        int lc = c[0];
        for ( int i = 0 ; i < j; i++) {
            //Nếu tìm được số nguyên tố lớn hơn thì nó trở thành lc
            if (c[i] > lc)
                lc = c[i];
        }
        cout << "\nSo nguyen to lon nhat trong mang la`: " << lc;
    }
    delete[] c;
}
void cArray::SapXepTangDan() {
    //Thuật toán Bubble Sort sắp xếp tăng dần
    for ( int i = 0; i < n - 1; i++) {
        for ( int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << "\nMang sau khi sap xep tang dan`: ";
    Xuat();
}
