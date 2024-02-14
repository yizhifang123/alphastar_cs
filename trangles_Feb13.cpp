#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int> x(n);  
	vector<int> y(n);  
	for (int i = 0; i < n; i++) { cin >> x[i] >> y[i]; }

	int max_area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (y[i] == y[j] && x[i] == x[k]) {
					int area = abs((x[j] - x[i]) * (y[k] - y[i]));
					max_area = max(max_area, area);
				}
			}
		}
	}

	cout << max_area << endl;
}