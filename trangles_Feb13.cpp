#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double calculate_area(int x1, int y1, int x2, int y2, int x3, int y3) {
    return abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0;
}

double max_triangle_area(int N, vector<pair<int, int>>& fence_posts) {
    double max_area = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            for (int k = j+1; k < N; ++k) {
                int x1 = fence_posts[i].first;
                int y1 = fence_posts[i].second;
                int x2 = fence_posts[j].first;
                int y2 = fence_posts[j].second;
                int x3 = fence_posts[k].first;
                int y3 = fence_posts[k].second;
                if (x1 == x2 || x1 == x3 || x2 == x3) {
                    double area = calculate_area(x1, y1, x2, y2, x3, y3);
                    max_area = max(max_area, area);
                }
            }
        }
    }
    return max_area;
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> fence_posts(N);
    for (int i = 0; i < N; ++i) {
        cin >> fence_posts[i].first >> fence_posts[i].second;
    }
    double result = max_triangle_area(N, fence_posts);
    cout << 2 * result << endl;
    return 0;
}
