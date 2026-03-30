#ifndef SOPHUC_H
#define SOPHUC_H

//Khai báo class
class SoPhuc
{
   private:
   //Gồm số thực và số ảo
   double iThuc, iAo;
   public:
   void Nhap();
   void Xuat();
    SoPhuc TinhTong(SoPhuc &sp);
    SoPhuc TinhHieu(SoPhuc &sp);
    SoPhuc TinhTich(SoPhuc &sp);
    SoPhuc TinhThuong(SoPhuc &sp);

};

#endif