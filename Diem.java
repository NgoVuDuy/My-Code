package Buoi2;

import java.util.Scanner;

public class Diem {
    private int x;
    private int y;

    public Diem() {
        this.x = 0;
        this.y = 0;
    }

    public Diem(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public Diem(Diem d) {
        this.x = d.x;
        this.y = d.y;
    }

    public void nhap() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap toa do x: ");
        this.x = sc.nextInt();
        System.out.print("Nhap toa do y: ");
        this.y = sc.nextInt();
    }

    public void hienThi() {
        System.out.println("(" + this.x + ", " + this.y + ")");
    }
    public String toString() {
        return "(" + x + ", " + y + ")";
    }

    public void tinhTien(int dx, int dy) {
        this.x += dx;
        this.y += dy;
    }

    public double tinhKhoangCach(Diem d) {
        int dx = this.x - d.x;
        int dy = this.y - d.y;
        return Math.sqrt(dx*dx + dy*dy);
    }

    public int getX() {
        return this.x;
    }

    public int getY() {
        return this.y;
    }
}
