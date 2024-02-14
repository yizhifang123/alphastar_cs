#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    
    int smallest_x = min(min(x1, x2), min(x3, x4));
    int biggest_x = max(max(x1, x2), max(x3, x4));
    
    int smallest_y = min(min(y1, y2), min(y3, y4));
    int biggest_y = max(max(y1, y2), max(y3, y4));

    cout << (biggest_y-smallest_y)*(biggest_x - smallest_x);
    return 0;
}
