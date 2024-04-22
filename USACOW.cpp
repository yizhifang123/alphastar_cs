#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> x_axis(n), y_axis(n);

	for (int &t : x_axis) { cin >> t; }
	for (int &t : y_axis) { cin >> t; }

	int max_squared = 0;  
	for (int i = 0; i < n; i++) { 
		for (int j = i + 1; j < n; j++) { 
			int dx = x_axis[i] - x_axis[j];
			int dy = y_axis[i] - y_axis[j];
			int square = dx * dx + dy * dy;
			max_squared = max(max_squared, square);
		}
	}

	cout << max_squared << endl;
}