#ifndef SOURCEOCODE_SINHVIEN_H
#define SOURCEOCODE_SINHVIEN_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class SinhVien {
private:
    string maSV;
    string hoTen;
    string ngaySinh;
    string gioiTinh;
    string lop;
public:
    // Constructor, khởi tạo sinh viên với các thông tin cụ thể
    SinhVien(string maSV, string hoTen, string ngaySinh, string gioiTinh, string lop) {
        this->maSV = maSV;
        this->hoTen = hoTen;
        this->ngaySinh = ngaySinh;
        this->gioiTinh = gioiTinh;
        this->lop = lop;
    }
    SinhVien() {}
    string getMaSV() {
        return maSV;
    }
    string getHoTen() {
        return hoTen;
    }
    string getNgaySinh() {
        return ngaySinh;
    }
    string getGioiTinh() {
        return gioiTinh;
    }
    string getLop() {
        return lop;
    }
    void setMaSV(string maSV) {
        this->maSV = maSV;
    }
    void setHoTen(string hoTen) {
        this->hoTen = hoTen;
    }
    void setNgaySinh(string ngaySinh) {
        this->ngaySinh = ngaySinh;
    }
    void setGioiTinh(string gioiTinh) {
        this->gioiTinh = gioiTinh;
    }
    void setLop(string lop) {
        this->lop = lop;
    }
};
#endif //SOURCEOCODE_SINHVIEN_H
