#include "cDaThuc.h"
#include <iostream>
#include <cmath>

using namespace std;

cDaThuc::cDaThuc() {
    n = 0; hs = NULL;
}


void cDaThuc::Nhap() {
    cout << "\nNhap bac cua da thuc: ";
    cin >> n;

    hs = new double[n + 1];

    for ( int i = n ; i >= 0; i--) {
        cout << "Nhap he so x^" << i << ": ";
        cin >> hs[i];
    }
}

void cDaThuc::Xuat() {
    //Biến flag dùng để kiểm tra xem đã in ra hệ số nào hay chưa
    bool flag = true;

    for ( int i = n; i >= 0; i--) {
        //Nếu hệ số bằng 0 thì bỏ qua không in gì cả
        if (hs[i] == 0) continue;

        //Nếu không phải số đầu tiên và hệ số lớn hơn 0 thì in ra hệ số dương
        if (!flag && hs[i] > 0) cout << " + ";
        //Nếu hệ số âm thì:
        if (hs[i] < 0) {
            //Nếu là số đầu tiên thì in ra dấu trừ dính liền vào hệ số
            if (flag) cout << "-";
            //Nếu không phải thì in ra dấu trừ có khoảng cách
            else cout << " - ";
            }
        
        double trituyetdoi = abs(hs[i]);
        //Nếu hệ số khác 1 hoặc bậc bằng 0 thì chỉ in ra hệ số
        if (trituyetdoi != 1 || i == 0)
            cout << trituyetdoi;
        
        //Nếu bậc lớn hơn 0
        if ( i > 0) {
            //Chỉ in ra x
            cout << "x";
            //Nếu bậc lớn hơn cả 1 thì in ra dấu mũ
            if ( i > 1) cout << "^" << i;    
            }
        //Gắn giá trị false cho flag vì đã in ra được số đầu tiên
        flag = false;  
        }
    //Nếu chạy hết vòng lặp nhưng flag vẫn giữ giá trị true có nghĩa là chưa in được gì => Đa thức bằng 0
    if (flag) cout << "0";
    cout << endl;
}

void cDaThuc::TinhDaThuc() {
    double x;
    cout << "Nhap gia tri x: ";
    cin >> x;

    //Khởi tạo biến kết quả để lưu giá trị0
    double kq = 0;
    for ( int i = 0; i <= n; i++) {
        //Cộng dồn vào kq
        kq += hs[i] * pow(x,i);
    }
    cout << "Gia tri cua da thuc khi x = " << x << ": " << kq;
}

cDaThuc cDaThuc::CongHaiDaThuc(cDaThuc &dt) {
    //Khởi tạo biến bậc cao nhất để tìm bậc cao nhất giữa hai đa thức
    int bacmax = (n > dt.n) ? n : dt.n;

    //Tạo một đa thức tạm để lưu kết quả của phép toán
    cDaThuc kq;
    kq.n = bacmax;
    kq.hs = new double[bacmax + 1];
    for (int i = 0; i <= bacmax; i++) {
        //Khởi tạo giá trị ban đầu là 0
        double s1 = 0;
        double s2 = 0;

        //Nếu bậc i tồn tại ở dt1 thì cập nhật lại s1
        if (i <= n) s1 = hs[i];
        //Nếu bậc i tồn tại ở dt2 thì cập nhật lại s2
        if (i <= dt.n) s2 = dt.hs[i];

        //Cộng hai hệ số lại vào vị trí bậc tương ứng
        kq.hs[i] = s1 + s2;
    }
    // Trả về đa thức kết quả
    return kq; 
}

cDaThuc cDaThuc::TruHaiDaThuc(cDaThuc &dt) {
    //Khởi tạo biến bậc cao nhất để tìm bậc cao nhất giữa hai đa thức
    int bacmax = (n > dt.n) ? n : dt.n;

    //Tạo một đa thức tạm để lưu kết quả của phép toán
    cDaThuc kq;
    kq.n = bacmax;
    kq.hs = new double[bacmax + 1];
    for (int i = 0; i <= bacmax; i++) {
        //Khởi tạo giá trị ban đầu là 0
        double s1 = 0;
        double s2 = 0;

        //Nếu bậc i tồn tại ở dt1 thì cập nhật lại s1
        if (i <= n) s1 = hs[i];
        //Nếu bậc i tồn tại ở dt2 thì cập nhật lại s2
        if (i <= dt.n) s2 = dt.hs[i];

        //Trừ hai hệ số lại vào vị trí bậc tương ứng
        kq.hs[i] = s1 - s2;
    }
    // Trả về đa thức kết quả
    return kq; 
}