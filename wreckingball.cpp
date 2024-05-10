#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T;
    cin >> T;
    vector<int> ideal(T);
    vector<int> start(T);
    vector<int> diff(T+2);
    int count = 0;
    for(int i=0; i<T; i++){
        cin >> ideal[i];
    }
    for(int i=0; i<T; i++){
        cin >> start[i];
    }
    for(int i=0; i<T; i++){
        diff[i+1] = ideal[i] - start[i];
    }
    for(int i=0; i<T; i++){
        if(diff[i+1] > diff[i]){
            count+=diff[i+1]-diff[i];
        }
    }
}
