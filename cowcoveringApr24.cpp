#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> x_cord(N);
    vector<int> y_cord(N);
    vector<int> x_sorted(N);
    vector<int> y_sorted(N);
    for(int i=0; i<N; i++){
        int tempx, tempy;
        cin >> tempx >> tempy;
        x_cord[i] = tempx;
        y_cord[i] = tempy;
        x_sorted[i] = tempx;
        y_sorted[i] = tempy;
    }
    sort(x_sorted.begin(), x_sorted.end());
    sort(y_sorted.begin(), y_sorted.end());
    int result;
    for(int i=0; i<N-1; i++){
        int minX = x_sorted[0];
        int maxX = x_sorted[N-1];
        int minY = y_sorted[0];
        int maxY = y_sorted[N-1];
        if(x_cord[i] == minX){
            minX = x_sorted[1];
        }
        if(x_cord[i] == maxX){
            maxX = x_sorted[N-2];
        }
        if(y_cord[i] == minY){
            minY = y_sorted[1];
        }
        if(y_cord[i] == maxY){
            maxY = y_sorted[N-2];
        }
        int area = (maxX-minX)*(maxY-minY);
        result = min(result, area);
    }
    cout << result;
}
