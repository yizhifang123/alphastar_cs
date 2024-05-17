#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> rooms(N);
	int total_cows = 0;
	for (int r = 0; r < N; r++) {
		cin >> rooms[r];
		total_cows += rooms[r];
	}

	int min_dist = INT32_MAX;
	for (int unlock = 0; unlock < N; unlock++) {
		int dist = 0;
		int cows_left = total_cows;
		for (int r = 0; r < N; r++) {
			cows_left -= rooms[(unlock + r) % N];
			dist += cows_left;
		}
		min_dist = min(min_dist, dist);
	}

	cout << min_dist << endl;
}
