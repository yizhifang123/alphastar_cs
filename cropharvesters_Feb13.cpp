#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    if((x3<=x1 & x4>=x2) & (y3<=y1 & y4>=y2)){
        cout << 0;
    }
    else if((x3<=x1 & y3<=y1)&(x2>x4 & y2<y4)){
        //POINT 1 is swallowed by p3 p4 , but p2 is outside     
        cout << abs((y2-y1) * (x4-x2)); 
    }
    else if((x2<=x4 & y2<=y4) & (x3<x2 & y2>y3) & (y1 < y3 || y1>y4) & (x1>x3 & x1<x4)){
        //point 2 is swallowed by p3 p4, but p1 is available(Up and down)
        cout << abs((x2-x1) * (y3-y1));
    }
    else{
        cout << (x2 - x1)*(y2-y1);
    }
    return 0;
}
