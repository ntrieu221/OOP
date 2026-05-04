#include "SoPhuc.h"
#include <iostream>

using namespace std;

int main() {
    //Khai báo và nhập vào Input
    SoPhuc sp1, sp2;
    cout << "-------So Phuc 1-------\n";
    cin >> sp1;
    cout << "-------So Phuc 2-------\n";
    cin >> sp2;

    //In ra màn hình
    cout << "\nHai so phuc vua` nhap la`:" << endl;
    cout << sp1 << endl << sp2 << endl;

    //Các phép toán
    cout << "Phep cong: " << sp1 + sp2 << endl;
    cout << "Phep tru: " << sp1 - sp2 << endl;
    cout << "Phep nhan: " << sp1 * sp2 << endl;
    cout << "Phep chia: " << sp1 / sp2 << endl;
    
    //So sánh hai số phức
    if (sp1 == sp2) cout << "Hai so phuc bang nhau.";
    else cout << "Hai so phuc khac nhau.";

    return 0;
}