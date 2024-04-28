#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }
    
    int count = 0;
    for(int i = 0; i < N; i++) {
        if(B[i] != A[i]) {
            int pos = find(A.begin(), A.end(), B[i]) - A.begin();
            A.erase(A.begin() + pos);
            A.insert(A.begin() + i, B[i]);
            count++;
        }
    }
    
    cout << count;
    return 0;
}
