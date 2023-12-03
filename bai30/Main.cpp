#include <iostream>
#include <vector>
#include "PrimAlgorithm.h"

using namespace std;

int main() {
    int n; // Số thành phố
    int m; // Số tuyến đường
    cout << "Nhap so thanh pho: ";
    cin >> n;
    cout << "Nhap so tuyen duong: ";
    cin >> m;

    vector<vector<Edge>> graph(n); // Đồ thị lưu trữ thông tin về tuyến đường và trọng số

    // Nhập thông tin về các tuyến đường và trọng số
    for (int i = 0; i < m; ++i) {
        int src, dest, weight;
        cout << "Nhap tuyen duong thu " << i + 1 << ": ";
        cin >> src >> dest >> weight;

        // Thêm cạnh nối từ thành phố nguồn đến thành phố đích và ngược lại
        graph[src - 1].push_back(Edge(dest - 1, weight));
        graph[dest - 1].push_back(Edge(src - 1, weight));
    }

    // Tính toán cây khung nhỏ nhất bằng thuật toán Prim
    long long minCost = PrimAlgorithm::PrimMST(graph, n);

    cout << "Chi phi nho nhat: " << minCost << endl;

    return 0;
}