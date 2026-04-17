#ifndef CARRAY_H
#define CARRAY_H

class cArray
{
    private:
    int* a;
    int n;
    public:
    cArray();
    void MangNgauNhien();
    void Xuat();
    void DemXTrongMang();
    void KiemTraTangDan();
    void TimLeMin();
    bool TimSNT(int x);
    void TimSNTMax();
    void SapXepTangDan();
    ~cArray();
};

#endif