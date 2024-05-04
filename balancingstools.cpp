#include <iostream>
#include <vector>

using namespace std;

void reverse(int until, vector<char>& line){
    vector<char> reversed(until);
    for(int i = 0; i < until; i++){
        reversed[until - i - 1] = line[i];
    }
    for(int i = 0; i < until; i++){
        line[i] = reversed[i];
    }
}

int main(){
    int N;
    int steps = 0;
    cin >> N;
    vector<char> line(N);
    for(int i = 0; i < N; i++){
        cin >> line[i];
    }
    for(int i = 0; i < N - 1; i += 2){
        if(line[i] == 'G') {
            steps++;
            reverse(N - i, line); 
        }
    }
    cout << steps;
    return 0;
}
