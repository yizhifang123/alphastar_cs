#include <iostream>
#include <vector>
using namespace std;

vector<int> cows;

void reverse(int start, int end) {
    for (int i = 0; i < (end - start) / 2; i++) {
        int temp = cows[start - 1 + i];
        cows[start - 1 + i] = cows[end - 1 - i];
        cows[end - 1 - i] = temp;
    }
}

int main() {
    int N, K, A1, A2, B1, B2;
    cin >> N >> K >> A1 >> A2 >> B1 >> B2;

    for (int i = 0; i < N; i++) {
        cows.push_back(i + 1);
    }

    vector<int> copy = cows;
    int cycle_length = 0;
    while (true) {
        cycle_length += 1;
        reverse(A1, A2);
        reverse(B1, B2);
        if (cows == copy) {
            break;
        }
    }

    for (int i = 0; i < (K % cycle_length); i++) {
        reverse(A1, A2);
        reverse(B1, B2);
    }

    for (int i = 0; i < N; i++) {
        cout << cows[i] << endl;
    }

    return 0;
}
