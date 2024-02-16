#include <iostream>
#include <vector>
#include <utility>
using namespace std;
bool isEven(int num) {
    return num % 2 == 0;
}
int main() {
    int N;
    cin >> N;
    vector<vector<int>> input(100);
    for (int i = 0; i < N; ++i) {
        char l;
        cin >> l;
        int n;
        cin >> n;
        int val = 'S'-l;
        input[val].push_back(n);
    }
    int count = 0;
    for (int v0 : input[0]) {
        for (int v1 : input[4]) {
            for (int v2 : input[6]) {
                for (int v3 : input[14]) {
                    for (int v4 : input[17]) {
                        for (int v5 : input[10]) {
                            for (int v6 : input[12]) {
                                int expressionValue = (v1 + v2 + v1) * (v0 + v5 + v0 + v4 + v3 + v3) * (v3 + v6 + v1 + v0);//somebig
                                if (isEven(expressionValue)) {
                                    count++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << count;
    return 0;
}
