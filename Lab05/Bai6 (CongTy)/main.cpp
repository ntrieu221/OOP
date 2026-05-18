#include <iostream>
#include "CongTyXYZ.h"

using namespace std;

int main() {
    CongTyXYZ congTy;
    
    // Đảm bảo chạy Terminal trong thư mục Bai6 để nhận diện trực tiếp file text
    if (congTy.docDSKhachHang("XYZ.INP")) {
        congTy.ghikq("XYZ.OUT");
    }
    
    return 0;
}