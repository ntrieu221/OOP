#ifndef CDATHUC_H
#define CDATHUC_H

class cDaThuc
{
    private:
        int n;
        double* hs;
    public:
    cDaThuc();
    void Nhap();
    void Xuat();
    void TinhDaThuc();
    cDaThuc CongHaiDaThuc(cDaThuc &dt);
    cDaThuc TruHaiDaThuc(cDaThuc &dt);
};

#endif