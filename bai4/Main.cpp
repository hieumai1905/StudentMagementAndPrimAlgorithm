#include <iostream>
#include "SinhVien.h"
#include "DanhSachSinhVien.h"

using namespace std;

int main() {
    // Khởi tạo danh sách sinh viên
    DanhSachSinhVien danhSach;
    // Đọc danh sách sinh viên từ file
    danhSach.docDanhSachSinhVienTuFile("/Users/Documents/outsource/ctdl/sourceocode/bai4/DanhSachSinhVien.txt");

    // Hiển thị danh sách sinh viên sau khi đọc file
    cout << "Danh sach sinh vien sau khi doc file: " << endl;
    danhSach.hienThiDanhSachSinhVien();

    // Thêm sinh viên
    string maSV, hoTen, ngaySinh, gioiTinh, lop;
    cout << "\nThem sinh vien:" << endl;
    cout << "Nhap thong tin sinh vien: " << endl;
    cout << "Ma SV: ";
    getline(cin, maSV);
    cout << "Ho ten: ";
    getline(cin, hoTen);
    cout << "Ngay sinh: ";
    getline(cin, ngaySinh);
    cout << "Gioi tinh: ";
    getline(cin, gioiTinh);
    cout << "Lop: ";
    getline(cin, lop);

    // Tạo đối tượng sinh viên mới với thông tin vừa nhập
    SinhVien sv(maSV, hoTen, ngaySinh, gioiTinh, lop);
    danhSach.themSinhVien(sv);

    // Hiển thị danh sách sinh viên sau khi thêm sinh viên
    cout << "\nDanh sach sinh vien sau khi them sinh vien: " << endl;
    danhSach.hienThiDanhSachSinhVien();

    string maSVXoa;
    cout << "Xoa sinh vien:" << endl;
    cout << "Nhap ma SV can xoa: ";
    getline(cin, maSVXoa);
    danhSach.xoaSinhVien(maSVXoa);

    // Hiển thị danh sách sinh viên sau khi xóa sinh viên
    cout << "Danh sach sinh vien sau khi xoa sinh vien: " << endl;
    danhSach.hienThiDanhSachSinhVien();

    // Cập nhật sinh viên
    cout << "Cap nhat thong tin sinh vien: " << endl;
    string maSVCapNhat;
    cout << "Nhap ma SV can cap nhat: ";
    getline(cin, maSVCapNhat);
    cout << "Nhap thong tin sinh vien moi: " << endl;
    cout << "Ho ten: ";
    getline(cin, hoTen);
    cout << "Ngay sinh: ";
    getline(cin, ngaySinh);
    cout << "Gioi tinh: ";
    getline(cin, gioiTinh);
    cout << "Lop: ";
    getline(cin, lop);

    // Tạo đối tượng sinh viên mới với thông tin mới
    SinhVien svCapNhat(maSVCapNhat, hoTen, ngaySinh, gioiTinh, lop);
    // Cập nhật sinh viên
    danhSach.capNhatSinhVien(maSVCapNhat, svCapNhat);

    // Hiển thị danh sách sinh viên sau khi cập nhật sinh viên
    cout << "Danh sach sinh vien sau khi cap nhat sinh vien: " << endl;
    danhSach.hienThiDanhSachSinhVien();

    // Tìm kiếm sinh viên theo họ tên
    string hoTenTimKiem;
    cout << "Nhap ho ten sinh vien can tim: ";
    getline(cin, hoTenTimKiem);
    danhSach.timKiemSinhVien(hoTenTimKiem);

    danhSach.ghiDanhSachSinhVienVaoFile("/Users/Documents/outsource/ctdl/sourceocode/bai4/DanhSachSinhVien.txt");

    return 0;
}