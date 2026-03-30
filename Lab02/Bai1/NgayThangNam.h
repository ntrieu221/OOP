#ifndef NGAYTHANGNAM_H
#define NGAYTHANGNAM_H

class NgayThangNam
{
private:
    int iNgay, iThang, iNam;

public:
    void Nhap();
    void Xuat();
    void TinhNgayKeTiep();
    bool NamNhuan();
    int NgayTrongThang();
    bool KiemTraInput();
};

#endif // NGAYTHANGNAM_H
