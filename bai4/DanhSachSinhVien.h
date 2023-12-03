#ifndef SOURCEOCODE_DANHSACHSINHVIEN_H
#define SOURCEOCODE_DANHSACHSINHVIEN_H

#include "Node.h"
#include "SinhVien.h"
#include <fstream>

class DanhSachSinhVien {
private:
    Node* head; // Con trỏ đến đầu danh sách
    Node* tail; // Con trỏ đến cuối danh sách
public:
    // Đây là constructor của lớp DanhSachSinhVien để khởi tạo danh sách rỗng ban đầu
    DanhSachSinhVien() {
        head = nullptr;
        tail = nullptr;
    }
    // Đây là destructor của lớp DanhSachSinhVien để giải phóng bộ nhớ
    ~DanhSachSinhVien() {
        Node* current = head;
        // Duyệt danh sách và giải phóng bộ nhớ cho từng node
        while (current != nullptr) {
            Node* next = current->getNext();
            delete current;
            current = next;
        }
    }
    // Hàm này dùng để đọc danh sách sinh viên từ file
    void docDanhSachSinhVienTuFile(const string& tenFile) {
        ifstream input(tenFile);
        // Nếu mở file thành công thì đọc danh sách sinh viên từ file
        if (input.is_open()) {
            string maSV, hoTen, ngaySinh, gioiTinh, lop;
            while (!input.eof()) {
                getline(input, maSV, ',');
                if(maSV.empty()) break;
                getline(input, hoTen, ',');
                getline(input, ngaySinh, ',');
                getline(input, gioiTinh, ',');
                getline(input, lop);
                SinhVien sv(maSV, hoTen, ngaySinh, gioiTinh, lop);
                themSinhVien(sv);
            }
            input.close();
        }
        else {
            cout << "Khong mo duoc file!" << endl;
        }
        cout << "Doc file thanh cong!" << endl;
    }
    // Hàm này dùng để ghi danh sách sinh viên vào file
    void ghiDanhSachSinhVienVaoFile(string tenFile) {
        ofstream file(tenFile);
        // Nếu mở file thành công thì ghi danh sách sinh viên vào file
        if (file.is_open()) {
            Node* current = head;
            while (current != nullptr) {
                SinhVien sv = current->getData();
                file << sv.getMaSV() << ",";
                file << sv.getHoTen() << ",";
                file << sv.getNgaySinh() << ",";
                file << sv.getGioiTinh() << ",";
                file << sv.getLop() << endl;
                current = current->getNext();
            }
            file.close();
        }
        else {
            cout << "Khong mo duoc file!" << endl;
        }
        cout << "Ghi file thanh cong!" << endl;
    }
    // Hàm này dùng để thêm sinh viên vào danh sách
    void themSinhVien(SinhVien sv) {
        // Tạo một node mới với dữ liệu là sinh viên
        Node* newNode = new Node(sv);
        // Nếu danh sách rỗng thì node mới là node đầu và node cuối
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            // nếu danh sách không rỗng thì thêm node mới vào cuối danh sách
            newNode->setPrev(tail);
            tail->setNext(newNode);
            tail = newNode;
        }
    }
    // Hàm này dùng để xóa sinh viên theo mã sinh viên
    void xoaSinhVien(string maSV) {
        // Lấy node đầu tiên trong danh sách
        Node* current = head;
        // Duyệt danh sách và xóa node có mã sinh viên trùng với mã sinh viên cần xóa
        while (current != nullptr) {
            if (current->getData().getMaSV() == maSV) {
                // Nếu sinh viên cần xóa là sinh viên đầu tiên trong danh sách thì cập nhật lại head
                Node* prevNode = current->getPrev();
                Node* nextNode = current->getNext();
                if (prevNode != nullptr) {
                    // Nếu sinh viên cần xóa không phải là sinh viên đầu tiên thì cập nhật lại liên kết giữa các node
                    prevNode->setNext(nextNode);
                }
                else {
                    // Nếu sinh viên cần xóa là sinh viên đầu tiên thì cập nhật lại head
                    head = nextNode;
                }
                if (nextNode != nullptr) {
                    // Nếu sinh viên cần xóa không phải là sinh viên cuối cùng thì cập nhật lại liên kết giữa các node
                    nextNode->setPrev(prevNode);
                }
                else {
                    tail = prevNode;
                }
                delete current;
                break;
            }
            // Lấy node tiếp theo trong danh sách
            current = current->getNext();
        }
    }
    // Hàm này dùng để hiển thị danh sách sinh viên
    void hienThiDanhSachSinhVien() {
        // Lấy node đầu tiên trong danh sách
        Node* current = head;
        // Duyệt danh sách và hiển thị thông tin sinh viên
        while (current != nullptr) {
            SinhVien sv = current->getData();
            cout << "Ma SV: " << sv.getMaSV() << endl;
            cout << "Ho ten: " << sv.getHoTen() << endl;
            cout << "Ngay sinh: " << sv.getNgaySinh() << endl;
            cout << "Gioi tinh: " << sv.getGioiTinh() << endl;
            cout << "Lop: " << sv.getLop() << endl;
            current = current->getNext();
        }
        cout << endl;
    }
    // Hàm này dùng để cập nhật thông tin sinh viên theo mã sinh viên
    void capNhatSinhVien(string maSV, SinhVien sv) {
        Node* current = head;
        while (current != nullptr) {
            // Nếu mã sinh viên trùng với mã sinh viên cần cập nhật thì cập nhật lại thông tin sinh viên
            if (current->getData().getMaSV() == maSV) {
                current->setData(sv);
                break;
            }
            // Lấy node tiếp theo trong danh sách
            current = current->getNext();
        }
    }
    // Hàm này dùng để tìm kiếm sinh viên theo họ tên
    void timKiemSinhVien(string hoTen) {
        // Biến check dùng để kiểm tra xem có sinh viên nào trùng với họ tên cần tìm hay không
        bool check = false;
        // Lấy node đầu tiên trong danh sách
        Node* current = head;
        // Duyệt danh sách và hiển thị thông tin sinh viên
        while (current != nullptr) {
            // Nếu họ tên trùng với họ tên cần tìm thì hiển thị thông tin sinh viên
            if (current->getData().getHoTen() == hoTen) {
                // Đặt biến check là true để thông báo tìm thấy sinh viên
                check = true;
                SinhVien sv = current->getData();
                cout << "Ma SV: " << sv.getMaSV() << endl;
                cout << "Ho ten: " << sv.getHoTen() << endl;
                cout << "Ngay sinh: " << sv.getNgaySinh() << endl;
                cout << "Gioi tinh: " << sv.getGioiTinh() << endl;
                cout << "Lop: " << sv.getLop() << endl;
                cout << endl;
            }
            // Lấy node tiếp theo trong danh sách
            current = current->getNext();
        }
        if (!check) {
            // Nếu không tìm thấy sinh viên thì thông báo không tìm thấy sinh viên
            cout << "Khong tim thay sinh vien!" << endl;
        }
    }
};
#endif //SOURCEOCODE_DANHSACHSINHVIEN_H
