package buoi3;

import Buoi2.Diem;

public class DoanThang {
    private Diem d1;
    private Diem d2;

    public DoanThang() {
        this.d1 = new Diem();
        this.d2 = new Diem();
    }

    public DoanThang(Diem d1, Diem d2) {
        this.d1 = new Diem(d1);
        this.d2 = new Diem(d2);
    }

    public DoanThang(int ax, int ay, int bx, int by) {
        this.d1 = new Diem(ax, ay);
        this.d2 = new Diem(bx, by);
    }

    public void nhap() {
        System.out.println("Nhap toa do diem dau:");
        this.d1.nhap();
        System.out.println("Nhap toa do diem cuoi:");
        this.d2.nhap();
    }

    public void hienThi() {
        System.out.print("Doan thang co diem dau la: ");
        this.d1.hienThi();
        System.out.print("Doan thang co diem cuoi la: ");
        this.d2.hienThi();
    }

    public void tinhTien(int dx, int dy) {
        this.d1.tinhTien(dx, dy);
        this.d2.tinhTien(dx, dy);
    }

    public double tinhDoDai() {
        return this.d1.tinhKhoangCach(this.d2);
    }
    public Diem getX() {
    	return d1;
    }
    public Diem getY() {
    	return d2;
    }
}
