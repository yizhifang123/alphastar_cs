#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> x_cords(n);  
	vector<int> y_cords(n);  
	for (int i = 0; i < n; i++) { cin >> x_cords[i] >> y_cords[i]; }

	int max_a = 0;
	for (int i = 0; i < n; i++) {
		for (int l = 0; l < n; l++) {
			for (int j = 0; j < n; j++) {
				if (y_cords[i]==y_cords[l] && x_cords[i]==x_cords[j]) {
					int area = abs((x_cords[l] - x_cords[i]) * (y_cords[j] - y_cords[i]));
					max_a = max(max_a, area);
				}
			}
		}
	}

	cout << max_a << endl;
}