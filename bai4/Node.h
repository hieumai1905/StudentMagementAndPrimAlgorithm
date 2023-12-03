#ifndef SOURCEOCODE_NODE_H
#define SOURCEOCODE_NODE_H
#include <iostream>
#include <fstream>
#include <string>
#include "SinhVien.h"

using namespace std;

class Node {
private:
    SinhVien data; // Dữ liệu của node
    Node *prev; // Con trỏ trỏ đến node trước
    Node *next; // Con trỏ trỏ đến node sau
public:
    // Constructor, khởi tạo node với dữ liệu là data
    Node(SinhVien data) {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
    // Hàm này dùng để lấy dữ liệu của node
    SinhVien getData() {
        return data;
    }
    // Hàm này dùng để lấy con trỏ trỏ đến node trước
    Node *getPrev() {
        return prev;
    }
    // Hàm này dùng để lấy con trỏ trỏ đến node sau
    Node *getNext() {
        return next;
    }
    // Hàm này dùng để gán dữ liệu cho node
    void setData(SinhVien data) {
        this->data = data;
    }
    // Hàm này dùng để gán con trỏ trỏ đến node trước
    void setPrev(Node *prev) {
        this->prev = prev;
    }
    // Hàm này dùng để gán con trỏ trỏ đến node sau
    void setNext(Node *next) {
        this->next = next;
    }
};
#endif //SOURCEOCODE_NODE_H
