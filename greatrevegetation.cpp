#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int N;
    int M;
    cin >> N;
    cin >> M;
    bool good = true;
    int pairs[N][2];
    for(int i=0; i<M; i++){
        for(int l=0; l<2; l++){
            cin >> pairs[i][l];
        }
    }
    for(int i=0; i<N-1; i++){
        sort(pairs[i], pairs[i] + 2);
    }
    int output[N];
    for(int i=0; i<N; i++){
        output[i] = 0;
    }
    for(int i=0; i<N-1; i++){
        for(int g = 1; g<4; g++){
            for(int j=0; j<M-1; j++){
                if(i+1 == pairs[j][1]){
                    if(output[pairs[j][0]-1] == g){
                        good = false;
                        break;
                    }
                }
            }
            if(good){
                output[i] = g;
                break;
            }
        }
    }
    for(int i=0; i<N; i++){
        cout << output[i];
    }
}
