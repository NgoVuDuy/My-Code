package buoi3;

import java.util.Scanner;

import Buoi2.Diem;

public class SDDoanThang {
    public static void main(String[] args) {
        
        Diem A = new Diem(2, 5);
        
        Diem B = new Diem(20, 35);
        
        DoanThang AB = new DoanThang(A, B);
        System.out.println("diem A: " + A);
        System.out.println("diem B: " + B);
        System.out.println("do dai doan thang AB " + AB.tinhDoDai());

        
        AB.tinhTien(5, 3);
        System.out.println("diem A sau khi tinh tien " + AB.getX());
        System.out.println("diem B sau khi tinh tien " + AB.getY());

        
        Scanner scanner = new Scanner(System.in);
        System.out.print("nhap toa do diem C (x, y): ");
        int x1 = scanner.nextInt();
        int y1 = scanner.nextInt();
        Diem C = new Diem(x1, y1);
        System.out.print("nhap toa do diem D (x, y): ");
        int x2 = scanner.nextInt();
        int y2 = scanner.nextInt();
        Diem D = new Diem(x2, y2);
        DoanThang CD = new DoanThang(C, D);
        System.out.println("do dai doan thang CD: " + CD.tinhDoDai());
    }
}
