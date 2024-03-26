#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> stars(N);
    for (int i = 0; i < N; ++i) {
        cin >> stars[i];
    }
    
    int moves = 0;
    for (int i = 0; i < N; ++i) {
        if (stars[i] != i + 1) {
            moves++;
            swap(stars[i], stars[stars[i] - 1]);
            i--;
        }
    }
    
    cout << moves;
    return 0;
}
