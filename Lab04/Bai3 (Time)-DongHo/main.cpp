#include <iostream>
#include <windows.h> // Chứa Sleep() và các hàm Console
#include "CTime.h"

using namespace std;

// Hàm di chuyển con trỏ đến tọa độ (x, y) trên màn hình Console
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    CTime t;

    cout << "Nhap gio, phut, giay (cach nhau khoang trang): ";
    cin >> t;

    system("cls"); // Xóa sạch màn hình
    cout << "Dong` ho` dang chay o ben canh ==> " << endl;

    while (true) {
        // Vẽ đồng hồ ở góc trên bên phải (cột 70, dòng 0)
        gotoxy(60, 0);
        cout << "[" << t << "]";

        // Nghỉ 1 giây rồi tăng thêm 1 giây
        Sleep(1000);
        ++t;
    }
    return 0;
}