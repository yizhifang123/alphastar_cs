#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    string A;
    string B;
    cin >> N >> A >> B;
    int count = 0;
    bool bad_interval = false;
    for(int i=0; i<N-1; i++){
        if (A[i] == B[i]){
            if(bad_interval){
                count+=1;
                bad_interval = false;
            }
        }
        else{
            bad_interval = true;
        }
    }
    if (bad_interval){
        count+=1;
    }
    cout << count;
}
