#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findlowmaxforcoord(const vector<int>& xcords, const vector<int>& ycords, int x, int y, int cows) {
    int currlow = 0;
    int temp = 0;
    for (int i = 0; i < cows; i++) {
        if (xcords[i] < x && ycords[i] > y) {
            temp++;
        }
    }
    currlow = max(currlow, temp);
    temp = 0;
    for (int i = 0; i < cows; i++) {
        if (xcords[i] < x && ycords[i] < y) {
            temp++;
        }
    }
    currlow = max(currlow, temp);
    temp = 0;
    for (int i = 0; i < cows; i++) {
        if (xcords[i] > x && ycords[i] > y) {
            temp++;
        }
    }
    currlow = max(currlow, temp);
    temp = 0;
    for (int i = 0; i < cows; i++) {
        if (xcords[i] > x && ycords[i] < y) {
            temp++;
        }
    }
    currlow = max(currlow, temp);
    return currlow;
}

int main() {
    int N, B;
    cin >> N >> B;
    vector<int> xcords(N);
    vector<int> ycords(N);
    for (int i = 0; i < N; i++) {
        cin >> xcords[i] >> ycords[i];
    }

    int lowestmax = N;
    for (int x = 1; x <= B; x += 2) {
        for (int y = 1; y <= B; y += 2) {
            int maxInQuadrant = 0;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    maxInQuadrant = max(maxInQuadrant, findlowmaxforcoord(xcords, ycords, x + i, y + j, N));
                }
            }
            lowestmax = min(lowestmax, maxInQuadrant);
        }
    }
    cout << lowestmax;
    return 0;
}
