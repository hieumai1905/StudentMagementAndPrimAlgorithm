#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
private:
    vector<int> heap; // Mảng heap để lưu trữ các phần tử
    int size; // Kích thước hiện tại của hàng đợi ưu tiên
    int capacity; // Số lượng phần tử tối đa mà hàng đợi ưu tiên có thể chứa

public:
    // Constructor, khởi tạo hàng đợi ưu tiên với một dung lượng cụ thể
    PriorityQueue(int capacity) {
        this->heap.resize(capacity + 1); // Tạo mảng heap với kích thước là capacity + 1 (vì ta bỏ qua phần tử ở vị trí 0)
        this->size = 0; // Ban đầu hàng đợi ưu tiên rỗng
        this->capacity = capacity; // Lưu trữ dung lượng tối đa của hàng đợi ưu tiên
    }

    // Kiểm tra hàng đợi ưu tiên có rỗng không
    bool isEmpty() {
        return size == 0;
    }

    // Kiểm tra hàng đợi ưu tiên đã đầy chưa
    bool isFull() {
        return size == capacity;
    }

    // Thêm một phần tử vào hàng đợi ưu tiên
    void insert(int element) {
        if (isFull()) {
            cout << "Hang doi uu tien da day." << endl;
            return;
        }
        // Tăng kích thước của hàng đợi ưu tiên lên 1
        size++;
        int index = size;
        // Thêm phần tử vào cuối hàng đợi ưu tiên
        heap[index] = element;

        // Điều chỉnh heap để đảm bảo tính chất heap
        while (index > 1 && heap[index] < heap[index / 2]) {
            swap(heap[index], heap[index / 2]);
            index = index / 2;
        }
    }

    // Xóa và trả về phần tử có độ ưu tiên cao nhất
    int remove() {
        if (isEmpty()) {
            cout << "Hang doi uu tien rong." << endl;
            return -1;
        }

        int minElement = heap[1]; // Phần tử có độ ưu tiên cao nhất là phần tử ở vị trí đầu tiên trong heap
        heap[1] = heap[size]; // Ghi đè phần tử đầu tiên bằng phần tử cuối cùng trong heap
        size--;

        heapify(1); // Điều chỉnh heap để đảm bảo tính chất heap
        return minElement;
    }

    // Điều chỉnh heap bắt đầu từ vị trí index
    void heapify(int index) {
        int smallest = index;
        int left = 2 * index;
        int right = 2 * index + 1;

        // Tìm ra phần tử nhỏ nhất trong 3 phần tử: phần tử hiện tại, con trái và con phải
        if (left <= size && heap[left] < heap[smallest])
            smallest = left;
        if (right <= size && heap[right] < heap[smallest])
            smallest = right;

        // Nếu phần tử nhỏ nhất không phải là phần tử hiện tại, hoán đổi phần tử hiện tại với phần tử nhỏ nhất
        // và tiếp tục điều chỉnh heap từ vị trí phần tử nhỏ nhất
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapify(smallest);
        }
    }

    // Trả về phần tử có độ ưu tiên cao nhất trong hàng đợi ưu tiên
    int getMinimum() {
        if (isEmpty()) {
            cout << "Hang doi uu tien rong." << endl;
            return -1;
        }

        return heap[1];
    }

    // Xóa phần tử có độ ưu tiên cao nhất trong hàng đợi ưtiên
    void deleteMinimum() {
        remove();
    }

    // Trả về kích thước hiện tại của hàng đợi ưu tiên
    int getSize() {
        return size;
    }
};

#endif // PRIORITYQUEUE_H