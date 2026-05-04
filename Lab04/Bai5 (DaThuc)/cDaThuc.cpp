#include "cDaThuc.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Constructor mặc định tất cả hệ số bằng 0
cDaThuc::cDaThuc(int b)
{
    bac = b;
    heso = new double[bac + 1];
    for (int i = 0; i <= bac; i++)
        heso[i] = 0;
}

//COnstructor sao chép để tránh lỗi dùng chung vùng nhớ
cDaThuc::cDaThuc(const cDaThuc &dt)
{
    bac = dt.bac;
    heso = new double[bac + 1];
    for (int i = 0; i <= bac; i++)
        heso[i] = dt.heso[i];
}

//Destructor để giải phóng bộ nhớ động đã cấp phát cho mảng hệ số
cDaThuc::~cDaThuc()
{
    delete[] heso;
}

//Operator nhập xuất
istream &operator>>(istream &in, cDaThuc &dt)
{
    cout << "Nhap bac: ";
    in >> dt.bac;
    // Cấp phát lại mảng dựa trên bậc mới
    dt.heso = new double[dt.bac + 1];
    for (int i = 0; i <= dt.bac; i++)
    {
        cout << "He so x^" << i << ": ";
        in >> dt.heso[i];
    }
    return in;
}

// Toán tử xuất: Hiển thị đa thức đẹp mắt theo định dạng toán học
ostream &operator<<(ostream &out, const cDaThuc &dt)
{
    bool first = true; // Biến đánh dấu số hạng đầu tiên để xử lý dấu
    for (int i = dt.bac; i >= 0; i--)
    {
        if (dt.heso[i] == 0)
            continue; // Bỏ qua nếu hệ số bằng 0

        // Xử lý in dấu giữa các số hạng
        if (!first)
        {
            //Nếu không phải đứng đầu và hệ số dương
            if (dt.heso[i] > 0)
                out << " + ";
            //Nếu hệ số âm
            else
                out << " - ";
        }
        else
        {
            //Nếu hệ số âm thì in dấu trừ
            if (dt.heso[i] < 0)
                out << "-";
        }

        double value = abs(dt.heso[i]);
        // Chỉ in hệ số nếu giá trị khác 1 hoặc là số hạng tự do (bậc 0)
        if (value != 1 || i == 0)
        {
            out << value;
        }
        // In phần biến x
        if (i > 0)
        {
            out << "x";
        }
        // In số mũ nếu bậc lớn hơn 1
        if (i > 1)
        {
            out << "^" << i;
        }
        first = false;
    }
    // Nếu tất cả hệ số bằng 0 thì in số 0
    if (first)
        out << "0"; 
    return out;
}

//Operator cộng hai đa thức
cDaThuc cDaThuc::operator+(cDaThuc &dt)
{
    int maxBac = (bac > dt.bac) ? bac : dt.bac;
    cDaThuc kq(maxBac); // Tạo đa thức kết quả với bậc lớn nhất
    //Xét từng đơn thức
    for (int i = 0; i <= maxBac; i++)
    {
        //Nếu như phần tử nằm ngoài mảng thì sẽ bằng 0
        double a = (i <= bac) ? heso[i] : 0;
        double b = (i <= dt.bac) ? dt.heso[i] : 0;
        // Cộng hệ số tương ứng của từng bậc
        kq.heso[i] = a + b; 
    }
    return kq;
}

// Tương tự với Operator trừ hai đa thức
cDaThuc cDaThuc::operator-(cDaThuc &dt)
{
    int maxBac = (bac > dt.bac) ? bac : dt.bac;
    cDaThuc kq(maxBac);

    for (int i = 0; i <= maxBac; i++)
    {
        double a = (i <= bac) ? heso[i] : 0;
        double b = (i <= dt.bac) ? dt.heso[i] : 0;
        kq.heso[i] = a - b;
    }
    return kq;
}

// Toán tử gán: Sao chép giá trị từ đa thức này sang đa thức khác
cDaThuc cDaThuc::operator=(cDaThuc &dt)
{
    // Tránh trường hợp tự gán (A = A)
    if (this != &dt)
    {          
        // Xóa mảng hiện tại trước khi nhận mảng mới
        delete[] heso; // Xóa mảng hiện tại trước khi nhận mảng mới
        bac = dt.bac;
        heso = new double[bac + 1];
        for (int i = 0; i <= bac; i++)
            heso[i] = dt.heso[i];
    }
    return *this;
}

//Operator tính x dùng để tính giá trị đa thức
double cDaThuc::operator()(double x)
{
    double tmp = heso[bac];
    for (int i = bac - 1; i >= 0; i--)
    {
        tmp = tmp * x + heso[i];
    }
    return tmp;
}