#ifndef CONGTYXYZ_H
#define CONGTYXYZ_H
#include "KhachHang.h"
#include "LoaiKhachHang.h"
#include <fstream>
#include <string>

using namespace std;

class CongTyXYZ
{
private:
    KhachHang *dsKH[3000]; // Mảng chứa con trỏ quản lí đối tượng khách hàng
    int tongsoKH;          // Đóng vai trò như là chỉ số cho phần tử trong mảng
    int x, y, z;           // Số lượng khách hàng của mỗi loại
public:
    CongTyXYZ();
    bool docDSKhachHang(string tenFile);
    bool ghikq(string tenFile);
    ~CongTyXYZ();
};

#endif