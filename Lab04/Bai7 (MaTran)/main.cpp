#include "cMatrix.h"

int main() {
    int d1, c1, d2, c2;

    // Nhập ma trận A
    cout << "---NHAP MA TRAN A---" << endl;
    cout << "Nhap so dong va so cot: "; cin >> d1 >> c1;
    cMatrix A(d1, c1);
    cin >> A; 

    //Tính tích với vector
    cout << "\n---Nhan A voi Vector---" << endl;
    cout << "Nhap " << c1 << " phan tu cho Vector: " << endl;
    double v_vao[100], v_ra[100];
    for (int i = 0; i < c1; i++) {
        cout << "  v[" << i << "] = "; cin >> v_vao[i];
    }
    
    A.nhanVector(v_vao, v_ra);
    cout << "=> Ket qua A * Vector: ";
    for (int i = 0; i < d1; i++) cout << v_ra[i] << " ";
    cout << endl;

    //Nhập ma trận B và tính tích A * B
    cout << "\n---Nhap ma tran B---" << endl;
    cout << "So dong` B phai bang` " << c1 << ". Nhap dong` va` cot B: "; 
    cin >> d2 >> c2;
    
    if (c1 != d2) {
        cout << "Error! Khong the nhan do khong cung` kich' thuoc'!" << endl;
    } else {
        cMatrix B(d2, c2);
        cin >> B;
        cMatrix C = A * B; 

        cout << "\nMa tran A:\n" << A;
        cout << "Ma tran B:\n" << B;
        cout << "A * B:\n" << C;
    }

    return 0;
}