#ifndef BAI30_PRIMALGORITHM_H
#define BAI30_PRIMALGORITHM_H

#include <vector>
#include "PriorityQueue.h"

using namespace std;

struct Edge {
    int dest; // Đỉnh đích của cạnh
    int weight; // Trọng số của cạnh

    // Constructor, khởi tạo cạnh với đỉnh đích và trọng số
    Edge(int d, int w) : dest(d), weight(w) {}
};

class PrimAlgorithm {
public:
    // Phương thức tĩnh để thực hiện thuật toán Prim và trả về tổng trọng số của cây khung nhỏ nhất
    static long long PrimMST(vector<vector<Edge>>& graph, int V) {
        PriorityQueue pq(V); // Tạo một hàng đợi ưu tiên với dung lượng V
        vector<bool> visited(V, false); // Mảng visited để kiểm tra xem một đỉnh đã được thăm hay chưa
        long long minCost = 0; // Tổng trọng số của cây khung nhỏ nhất

        int startVertex = 0; // Chọn đỉnh xuất phát là đỉnh 0

        visited[startVertex] = true; // Đánh dấu đỉnh xuất phát là đã thăm
        for (const auto& edge : graph[startVertex]) {
            pq.insert(edge.weight); // Thêm trọng số của các cạnh nối với đỉnh xuất phát vào hàng đợi ưu tiên
        }
        while (!pq.isEmpty()) {
            int currentWeight = pq.remove(); // Lấy ra trọng số nhỏ nhất từ hàng đợi ưu tiên
            int currentVertex = -1; // Đỉnh hiện tại

            // Tìm đỉnh đích của cạnh có trọng số hiện tại và chưa được thăm
            for (int i = 0; i < V; ++i) {
                if (visited[i]) {
                    // Duyệt qua các cạnh nối với đỉnh hiện tại
                    for (const auto& edge : graph[i]) {
                        // Nếu đỉnh đích của cạnh chưa được thăm và trọng số của cạnh bằng trọng số hiện tại
                        if (!visited[edge.dest] && edge.weight == currentWeight) {
                            currentVertex = edge.dest;
                            break;
                        }
                    }
                }
                if (currentVertex != -1)
                    break;
            }

            if (currentVertex != -1) {
                minCost += currentWeight; // Cộng trọng số của cạnh vào tổng trọng số của cây khung nhỏ nhất
                visited[currentVertex] = true; // Đánh dấu đỉnh hiện tại là đã thăm

                // Thêm các cạnh nối với đỉnh hiện tại vào hàng đợi ưu tiên, nếu đỉnh đó chưa được thăm
                for (const auto& edge : graph[currentVertex]) {
                    if (!visited[edge.dest]) {
                        pq.insert(edge.weight);
                    }
                }
            }
        }

        return minCost; // Trả về tổng trọng số của cây khung nhỏ nhất
    }
};

#endif // BAI30_PRIMALGORITHM_H